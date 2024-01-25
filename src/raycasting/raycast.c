/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:47:58 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/25 11:43:09 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_step_size(t_ray *ray)
{
		ray->step.x = 0;
		ray->step.y = 0;
		ray->map_check.x = (int)ray->pos.x;
		ray->map_check.y = (int)ray->pos.y;

		if (ray->dir.x == 0) // Prevents division by 0
			ray->step_size.x = 1e30;
		else
			ray->step_size.x = fabs(1 / ray->dir.x); 
		if (ray->dir.y == 0) // Prevents division by 0
			ray->step_size.y = 1e30;
		else
			ray->step_size.y = fabs(1 / ray->dir.y);

}

void	calculate_ray_length(t_ray *ray)
{
		if (ray->dir.x < 0.0)
		{
			ray->step.x = -1;
			ray->length.x = (ray->pos.x - ray->map_check.x) * ray->step_size.x;
		}
		else
		{
			ray->step.x = 1;	
			ray->length.x = (ray->map_check.x + 1.0f - ray->pos.x) * ray->step_size.x;
		}
		if (ray->dir.y < 0.0)
		{
			ray->step.y = -1;
			ray->length.y = (ray->pos.y - ray->map_check.y) * ray->step_size.y;
		}
		else
		{
			ray->step.y = 1;
			ray->length.y = (ray->map_check.y + 1.0f - ray->pos.y) * ray->step_size.y;
		}
}

void	calculate_ray_dir(t_ray *ray, t_cub *cub, int i)
{
	double	camera_x;

	camera_x = 2 * i / (double)cub->win_size.x - 1;
	ray->dir.x = cub->player.dir.x + cub->player.plane.x * camera_x;
	ray->dir.y = cub->player.dir.y + cub->player.plane.y * camera_x;
}

void	horizontal_step(t_ray *ray, double *dist)
{
	ray->map_check.x += ray->step.x;
	*dist = ray->length.x;
	ray->length.x += ray->step_size.x;
	ray->was_hit_vertical = 0;
}

void	vertical_step(t_ray *ray, double *dist)
{
	ray->map_check.y += ray->step.y;
	*dist = ray->length.y;
	ray->length.y += ray->step_size.y;
	ray->was_hit_vertical = 1;
}

// int	is_inside_map(t_ray *ray, t_cub *cub)
// {
// 	if (ray->map_check.x >= 0 && ray->map_check.x < cub->map_size.x
// 		&& ray->map_check.y >= 0 && ray->map_check.y < cub->map_size.y)
// 		return (1);
// 	return (0);
// }

int	is_cell_occopied(t_cub *cub, t_vec2i pos)
{
	if (cub->map[pos.x][pos.y] >= 1)
		return (1);
	return (0);
}

int	is_wall(t_ray *ray, t_cub *cub)
{
	if (cub->map[ray->map_check.y][ray->map_check.x] >= 1)
		return (1);
	return (0);
}

void	calculate_perpendicular_wall_dist(t_ray *ray)
{
	if (ray->was_hit_vertical == 0)
		ray->perp_wall_dist = (ray->length.x - ray->step_size.x);
	else
		ray->perp_wall_dist = (ray->length.y - ray->step_size.y);
}

void	calculate_line_height(t_ray *ray, t_cub *cub)
{;
	ray->line_height = (int)(cub->win_size.y / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + cub->win_size.y / 2;
	if(ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cub->win_size.y / 2;
	if(ray->draw_end >= cub->win_size.y)
		ray->draw_end = cub->win_size.y - 1;
}

// Calculate where the ray hit the wall
void	calculate_wall_x(t_ray *ray)
{
	double wallX;

	if (ray->was_hit_vertical == 0)
		wallX = ray->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		wallX = ray->pos.x + ray->perp_wall_dist * ray->dir.x;
	wallX -= floor(wallX);
	ray->wall_x = wallX;
}

void	calculate_texture_x(t_ray *ray, t_cub *cub)
{
	int texWidth;

	texWidth = cub->wall_textures[0].width;
	if (ray->was_hit_vertical == 0)
	{
		ray->tex.x = (int)(ray->wall_x * (double)(texWidth));
		if (ray->dir.x < 0)
			ray->tex.x = texWidth - ray->tex.x - 1;
	} else
	{
		ray->tex.x = (int)(ray->wall_x * (double)(texWidth));
		if (ray->dir.y > 0) ray->tex.x = texWidth - ray->tex.x - 1;
	}
}

// Returns the side of the wall that was hit
int	get_compass_hit_direction(t_ray *ray)
{
	if (ray->was_hit_vertical && ray->pos.y > ray->map_check.y)
		return (SOUTH);
	else if (ray->was_hit_vertical && ray->pos.y < ray->map_check.y)
		return (NORTH);
	else if (!ray->was_hit_vertical && ray->pos.x > ray->map_check.x)
		return (EAST);
	else if (!ray->was_hit_vertical && ray->pos.x < ray->map_check.x)
		return (WEST);
	return (-1);
}

void	draw_pixel_from_texture(t_ray *ray, t_cub *cub, int i, int j)
{
	int color;
	t_texture	*texture;

	texture = &(cub->wall_textures[ray->hit_direction]);
	color = get_pixel_color_int(texture, ray->tex.x, ray->tex.y);
	put_pixel(cub->img, (t_vec2i){i, j}, color);
}

void	draw_line_from_texture(t_ray *ray, t_cub *cub, int i)
{
	double	step_tex;
	double	tex_pos;
	int		tex_height;
	int		j;

	j = ray->draw_start;
	tex_height = cub->wall_textures[ray->hit_direction].height;
	step_tex = 1.0 * tex_height / ray->line_height;
	tex_pos = (ray->draw_start - cub->win_size.y / 2 + ray->line_height / 2)
					* step_tex;
	while (j < ray->draw_end)
	{
		ray->tex.y = (int)tex_pos & (tex_height - 1);
		tex_pos += step_tex;
		draw_pixel_from_texture(ray, cub, i, j);
		j++;
	}
}

int	is_ray_hitting(t_cub *cub, t_ray *ray)
{
	int		hit;
	double	dist;

	hit = 0;
	dist = 0;
	while (!hit && dist < MAX_RAY_LENGTH)
	{
		if (ray->length.x < ray->length.y)
			horizontal_step(ray, &dist);
		else
			vertical_step(ray, &dist);
		if (is_inside_map(cub, ray->map_check))
		{
			// if (is_wall(ray, cub))
			// 	return (1);
			if (is_cell_occopied(cub, 
					(t_vec2i){ray->map_check.y, ray->map_check.x}))
				return (1);
		}
	}
	return (0);
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	cub->ray.pos.x = cub->player.pos.x;
	cub->ray.pos.y = cub->player.pos.y;
	while(i < cub->win_size.x)
	{
		calculate_ray_dir(&cub->ray, cub, i);
		calculate_step_size(&cub->ray);
		calculate_ray_length(&cub->ray);
		if (is_ray_hitting(cub, &cub->ray))
		{
			cub->ray.hit_direction = get_compass_hit_direction(&cub->ray);
			calculate_perpendicular_wall_dist(&cub->ray);
			calculate_line_height(&cub->ray, cub);
			calculate_wall_x(&cub->ray);
			calculate_texture_x(&cub->ray, cub);
			// draw_line(cub->img, (t_vec2i){i, cub->ray.draw_start}, (t_vec2i){i, cub->ray.draw_end}, 0x00FF0000);
			draw_line_from_texture(&cub->ray, cub, i);
		}
		i++;
	}
}

// void	raycast(t_cub *cub)
// {
// 	int i;
// 	double	camera_x;
// 	t_ray	*ray;
	
// 	ray = &cub->ray;
// 	ray->pos.x = cub->player.pos.x;
// 	ray->pos.y = cub->player.pos.y;
// 	// ray->dir.x = cub->player.dir.x;
// 	// ray->dir.y = cub->player.dir.y;
// 	i = 0;
// 	while (i < cub->win_size.x) // For each x axis pixel on the screen
// 	{
// 		camera_x = 2 * i / (double)cub->win_size.x - 1; // x-coordinate in camera space, normalized device coordinates (NDC) [-1, 1] 
// 		ray->dir.x = cub->player.dir.x + cub->player.plane.x * camera_x;
// 		ray->dir.y = cub->player.dir.y + cub->player.plane.y * camera_x;
// 		ray->was_hit_vertical = 0;
// 		// printf("Raydir x: %f y: %f\n", ray->dir.x, ray->dir.y);

// 		// printf("camera_x: %f\n", camera_x);
// 		// printf("Raydirs x: %f y: %f\n", ray->dir.x, ray->dir.y);
// 		// int		side;

// 		ray->step.x = 0;
// 		ray->step.y = 0;
// 		// side = -1;
// 		ray->map_check.x = (int)ray->pos.x;
// 		ray->map_check.y = (int)ray->pos.y;

// 		if (ray->dir.x == 0) // Prevents division by 0
// 			ray->step_size.x = 1e30;
// 		else
// 			ray->step_size.x = fabs(1 / ray->dir.x); 
// 		if (ray->dir.y == 0) // Prevents division by 0
// 			ray->step_size.y = 1e30;
// 		else
// 			ray->step_size.y = fabs(1 / ray->dir.y);
// 		if (ray->dir.x < 0.0)
// 		{
// 			ray->step.x = -1;
// 			ray->length.x = (ray->pos.x - ray->map_check.x) * ray->step_size.x;
// 		}
// 		else
// 		{
// 			ray->step.x = 1;	
// 			ray->length.x = (ray->map_check.x + 1.0f - ray->pos.x) * ray->step_size.x;
// 		}
// 		if (ray->dir.y < 0.0)
// 		{
// 			ray->step.y = -1;
// 			ray->length.y = (ray->pos.y - ray->map_check.y) * ray->step_size.y;
// 		}
// 		else
// 		{
// 			ray->step.y = 1;
// 			ray->length.y = (ray->map_check.y + 1.0f - ray->pos.y) * ray->step_size.y;
// 		}
// 		// printf("Mapcheck x %d y %d\n", ray->map_check.x, ray->map_check.y);
// 		// printf("Step x %d y %d\n", ray->step.x, ray->step.y);
// 		// printf("Raylength x %f y %f\n", ray->length.x, ray->length.y);
// 		// printf("Stepsize x %f y %f\n", ray->step_size.x, ray->step_size.y);
// 		int		hit;
// 		double	max_dist;
// 		double	dist;

// 		hit = 0;
// 		max_dist = 100.0f;
// 		dist = 0;
// 		while (!hit && dist < max_dist)
// 		{
// 			if (ray->length.x < ray->length.y) // Horizontal 
// 			{
// 				ray->map_check.x += ray->step.x;
// 				dist = ray->length.x;
// 				ray->length.x += ray->step_size.x;
// 				ray->was_hit_vertical = 0;
// 			}
// 			else
// 			{
// 				ray->map_check.y += ray->step.y;
// 				dist = ray->length.y;
// 				ray->length.y += ray->step_size.y;
// 				ray->was_hit_vertical = 1;
// 			}
// 			if ( ray->map_check.x >= 0 && ray->map_check.x < cub->map_size.x && ray->map_check.y >= 0 && ray->map_check.y < cub->map_size.y)
// 			{
// 				if (cub->map[ray->map_check.y][ray->map_check.x] >= 1)
// 				{
// 					// t_vec2i	coord;
// 					// int		color;

// 					// if (ray->was_hit_vertical == 0)
// 					// 	color = 0x000000FF;
// 					// else
// 					// 	color = 0x0000FF00;
// 					// coord = scale_vec2i(ray->map_check, TILE_SIZE / 2);
// 					// coord.x += 400;
// 					// draw_square(cub->img, coord, TILE_SIZE / 2, color);
// 					// printf("Hit x: %d y: %d\n", ray->map_check.x, ray->map_check.y);
// 					hit = 1;
// 				}
// 			}
// 		}

// 		if (hit)
// 		{
// 			// t_vec2	intersection;

// 			// intersection.x = ray->pos.x + ray->dir.x * dist;
// 			// intersection.y = ray->pos.y + ray->dir.y * dist;
// 			// draw_circle(cub->img, v2_to_v2i(scale_vec2(intersection, TILE_SIZE)), TILE_SIZE / 4, 0x00FFFF00);

// 			if (ray->was_hit_vertical == 0)
// 				ray->perp_wall_dist = (ray->length.x - ray->step_size.x);
// 			else
// 				ray->perp_wall_dist = (ray->length.y - ray->step_size.y);
// 			int line_height = (int)(cub->win_size.y / ray->perp_wall_dist);

// 			int draw_start = -line_height / 2 + cub->win_size.y / 2;
// 			if(draw_start < 0)
// 				draw_start = 0;
// 			int draw_end = line_height / 2 + cub->win_size.y / 2;
// 			if(draw_end >= cub->win_size.y)
// 				draw_end = cub->win_size.y - 1;
// 			// int draw_color;
// 			// if (side == 0)
// 			// 	draw_color = 0x00FF0000; // Red for the North side
// 			// else if (side == 1)
// 			// 	draw_color = 0x0000FF00; // Green for the South side
// 			// draw_line(cub->img, (t_vec2i){i, draw_start}, (t_vec2i){i, draw_end}, draw_color);

// 				//texturing calculations
// 			// int texNum = cub->map[map_check.x][map_check.y] - 1; //1 subtracted from it so that texture 0 can be used!

// 			//calculate value of wallX
// 			double wallX; //where exactly the wall was hit
// 			if (ray->was_hit_vertical == 0) wallX = ray->pos.y + ray->perp_wall_dist * ray->dir.y;
// 			else           wallX = ray->pos.x + ray->perp_wall_dist * ray->dir.x;
// 			wallX -= floor(wallX);
// 			int texWidth = cub->wall_textures[0].width;

// 			//x coordinate on the texture
// 			// int texX = (int)(wallX * (double)(texWidth));
// 			// int texX;
// 			// if (side == 0) {
// 			// 	texX = (int)(wallX * (double)(texWidth));
// 			// 	if (ray->dir.x > 0) texX = texWidth - texX - 1;
// 			// } else {
// 			// 	texX = (int)(wallX * (double)(texWidth));
// 			// 	if (ray->step.y < 0) texX = texWidth - texX - 1;
// 			// }
// 			int texX;
// 			if (ray->was_hit_vertical == 0) {
// 				texX = (int)(wallX * (double)(texWidth));
// 				if (ray->dir.x < 0) texX = texWidth - texX - 1;
// 			} else {
// 				texX = (int)(wallX * (double)(texWidth));
// 				if (ray->dir.y > 0) texX = texWidth - texX - 1;
// 			}
			
// 			int texHeight = cub->wall_textures[0].height;
// 			// How much to increase the texture coordinate per screen pixel
// 			double stepTex = 1.0 * texHeight / line_height;
// 			// Starting texture coordinate
// 			double texPos = (draw_start - cub->win_size.y / 2 + line_height / 2) * stepTex;
// 			int color;
// 			color = 0x00FFFFFF;
// 			for(int y = draw_start; y<draw_end; y++)
// 			{
// 				// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
// 				int texY = (int)texPos & (texHeight - 1);
// 				texPos += stepTex;
// 				if (ray->was_hit_vertical && ray->pos.y > ray->map_check.y)
// 					color = get_pixel_color_int(&(cub->wall_textures[1]), texX, texY);
// 				else if (ray->was_hit_vertical && ray->pos.y < ray->map_check.y)
// 					color = get_pixel_color_int(&(cub->wall_textures[3]), texX, texY);
// 				else if (!ray->was_hit_vertical && ray->pos.x > ray->map_check.x)
// 					color = get_pixel_color_int(&(cub->wall_textures[0]), texX, texY);
// 				else if (!ray->was_hit_vertical && ray->pos.x < ray->map_check.x)
// 					color = get_pixel_color_int(&(cub->wall_textures[2]), texX, texY);
// 				// color = get_pixel_color_int(&(cub->wall_textures[0]), texX, texY);
// 				//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// 				// if(side == 1) color = (color >> 1) & 8355711;
// 				put_pixel(cub->img, (t_vec2i){i, y}, color);
// 				// cub->img->addr[y * cub->img->line_length / 4 + i] = color;
// 				// buffer[y][x] = color;
// 			}
// 		}
// 		i++;
// 	}
// 	ft_bzero(&cub->ray, sizeof(t_ray));
// 	// exit(0);
// }



// void	raycast(t_cub *cub, t_vec2 start_pos, t_vec2 dir)
// {
// 	(void)dir;
// 	t_vec2	step_size;
// 	t_vec2i	step;
// 	t_vec2i	map_check;
// 	t_vec2	ray_length;
// 	double	perp_wall_dist;
// 	int i;
// 	double	camera_x;
// 	double	ray_dir_x;
// 	double	ray_dir_y;
	
// 	i = 0;
// 	while (i < cub->win_size.x) // For each x axis pixel on the screen
// 	{
// 		camera_x = 2 * i / (double)cub->win_size.x - 1; // x-coordinate in camera space, normalized device coordinates (NDC) [-1, 1] 
// 		ray_dir_x = cub->player.dir.x + cub->player.plane.x * camera_x;
// 		ray_dir_y = cub->player.dir.y + cub->player.plane.y * camera_x;

// 		// printf("camera_x: %f\n", camera_x);
// 		// printf("Raydirs x: %f y: %f\n", ray_dir_x, ray_dir_y);
// 		int		side;

// 		step.x = 0;
// 		step.y = 0;
// 		side = -1;
// 		map_check.x = (int)start_pos.x;
// 		map_check.y = (int)start_pos.y;

// 		if (ray_dir_x == 0) // Prevents division by 0
// 			step_size.x = 1e30;
// 		else
// 			step_size.x = fabs(1 / ray_dir_x); 
// 		if (ray_dir_y == 0) // Prevents division by 0
// 			step_size.y = 1e30;
// 		else
// 			step_size.y = fabs(1 / ray_dir_y);
// 		if (ray_dir_x < 0.0)
// 		{
// 			step.x = -1;
// 			ray_length.x = (start_pos.x - map_check.x) * step_size.x;
// 		}
// 		else
// 		{
// 			step.x = 1;	
// 			ray_length.x = (map_check.x + 1.0f - start_pos.x) * step_size.x;
// 		}
// 		if (ray_dir_y < 0.0)
// 		{
// 			step.y = -1;
// 			ray_length.y = (start_pos.y - map_check.y) * step_size.y;
// 		}
// 		else
// 		{
// 			step.y = 1;
// 			ray_length.y = (map_check.y + 1.0f - start_pos.y) * step_size.y;
// 		}
// 		// printf("Mapcheck x %d y %d\n", map_check.x, map_check.y);
// 		// printf("Step x %d y %d\n", step.x, step.y);
// 		// printf("Raylength x %f y %f\n", ray_length.x, ray_length.y);
// 		// printf("Stepsize x %f y %f\n", step_size.x, step_size.y);
// 		int		hit;
// 		double	max_dist;
// 		double	dist;

// 		hit = 0;
// 		max_dist = 100.0f;
// 		dist = 0;
// 		while (!hit && dist < max_dist)
// 		{
// 			if (ray_length.x < ray_length.y) // Horizontal 
// 			{
// 				map_check.x += step.x;
// 				dist = ray_length.x;
// 				ray_length.x += step_size.x;
// 				side = 0;
// 			}
// 			else
// 			{
// 				map_check.y += step.y;
// 				dist = ray_length.y;
// 				ray_length.y += step_size.y;
// 				side = 1;
// 			}
// 			if ( map_check.x >= 0 && map_check.x < cub->map_size.x && map_check.y >= 0 && map_check.y < cub->map_size.y)
// 			{
// 				if (cub->map[map_check.y][map_check.x] >= 1)
// 				{
// 					t_vec2i	coord;
// 					int		color;

// 					if (side == 0)
// 						color = 0x000000FF;
// 					else
// 						color = 0x0000FF00;
// 					coord = scale_vec2i(map_check, TILE_SIZE / 2);
// 					coord.x += 400;
// 					draw_square(cub->img, coord, TILE_SIZE / 2, color);
// 					hit = 1;
// 				}
// 			}
// 		}
// 		// exit(0);

// 		if (hit)
// 		{
// 			// t_vec2	intersection;

// 			// intersection.x = start_pos.x + dir.x * dist;
// 			// intersection.y = start_pos.y + dir.y * dist;
// 			// draw_circle(cub->img, v2_to_v2i(scale_vec2(intersection, TILE_SIZE)), TILE_SIZE / 4, 0x00FFFF00);

// 			if (side == 0)
// 				perp_wall_dist = (ray_length.x - step_size.x);
// 			else
// 				perp_wall_dist = (ray_length.y - step_size.y);
// 			int line_height = (int)(cub->win_size.y / perp_wall_dist);

// 			int draw_start = -line_height / 2 + cub->win_size.y / 2;
// 			if(draw_start < 0)
// 				draw_start = 0;
// 			int draw_end = line_height / 2 + cub->win_size.y / 2;
// 			if(draw_end >= cub->win_size.y)
// 				draw_end = cub->win_size.y - 1;
// 			// int draw_color;
// 			// if (side == 0)
// 			// 	draw_color = 0x00FF0000; // Red for the North side
// 			// else if (side == 1)
// 			// 	draw_color = 0x0000FF00; // Green for the South side
// 			// draw_line(cub->img, (t_vec2i){i, draw_start}, (t_vec2i){i, draw_end}, draw_color);

// 				//texturing calculations
// 			// int texNum = cub->map[map_check.x][map_check.y] - 1; //1 subtracted from it so that texture 0 can be used!

// 			//calculate value of wallX
// 			double wallX; //where exactly the wall was hit
// 			if (side == 0) wallX = start_pos.y + perp_wall_dist * ray_dir_y;
// 			else           wallX = start_pos.x + perp_wall_dist * ray_dir_x;
// 			wallX -= floor(wallX);
// 			int texWidth = cub->wall_textures[0].width;

// 			//x coordinate on the texture
// 			// int texX = (int)(wallX * (double)(texWidth));
// 			// int texX;
// 			// if (side == 0) {
// 			// 	texX = (int)(wallX * (double)(texWidth));
// 			// 	if (ray_dir_x > 0) texX = texWidth - texX - 1;
// 			// } else {
// 			// 	texX = (int)(wallX * (double)(texWidth));
// 			// 	if (ray_dir_y < 0) texX = texWidth - texX - 1;
// 			// }
// 			int texX;
// 			if (side == 0) {
// 				texX = (int)(wallX * (double)(texWidth));
// 				if (ray_dir_x < 0) texX = texWidth - texX - 1;
// 			} else {
// 				texX = (int)(wallX * (double)(texWidth));
// 				if (ray_dir_y > 0) texX = texWidth - texX - 1;
// 			}
			
// 			int texHeight = cub->wall_textures[0].height;
// 			// How much to increase the texture coordinate per screen pixel
// 			double stepTex = 1.0 * texHeight / line_height;
// 			// Starting texture coordinate
// 			double texPos = (draw_start - cub->win_size.y / 2 + line_height / 2) * stepTex;
// 			int color;
// 			color = 0x00FFFFFF;
// 			for(int y = draw_start; y<draw_end; y++)
// 			{
// 				// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
// 				int texY = (int)texPos & (texHeight - 1);
// 				texPos += stepTex;
// 				if (side == 0 && start_pos.x > map_check.x)
// 					color = get_pixel_color_int(&(cub->wall_textures[0]), texX, texY);
// 				else if (side == 0 && start_pos.x < map_check.x)
// 					color = get_pixel_color_int(&(cub->wall_textures[2]), texX, texY);
// 				else if (side == 1 && start_pos.y > map_check.y)
// 					color = get_pixel_color_int(&(cub->wall_textures[1]), texX, texY);
// 				else if (side == 1 && start_pos.y < map_check.y)
// 					color = get_pixel_color_int(&(cub->wall_textures[3]), texX, texY);
// 				// color = get_pixel_color_int(&(cub->wall_textures[0]), texX, texY);
// 				//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
// 				// if(side == 1) color = (color >> 1) & 8355711;
// 				put_pixel(cub->img, (t_vec2i){i, y}, color);
// 				// cub->img->addr[y * cub->img->line_length / 4 + i] = color;
// 				// buffer[y][x] = color;
// 			}
// 		}
// 		i++;
// 	}
// 	// exit(0);
// }
