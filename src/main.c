/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalk <sbalk@student.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:55 by sbalk             #+#    #+#             */
/*   Updated: 2024/01/24 21:39:13 by sbalk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[TEST_MAP_SIZE_X][TEST_MAP_SIZE_Y]= {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

int		celling_color = 0x000000FF;
int		floor_color = 0x00333333;

void	transfers_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < TEST_MAP_SIZE_X)
	{
		j = 0;
		while (j < TEST_MAP_SIZE_Y)
		{
			cub->map[i][j] = worldMap[i][j];
			j++;
		}
		i++;
	}
}

void	draw_player(t_cub *cub)
{
	t_vec2i	pos;
	t_vec2i	size;
	int		color;
	t_vec2i	target;

	pos.x = cub->player.pos.x * TILE_SIZE / 2 + 400;
	pos.y = cub->player.pos.y * TILE_SIZE / 2;
	size.x = TILE_SIZE / 2;
	size.y = TILE_SIZE / 2;
	color = 0x00FFFFFF;

	target = add_vec2i(pos, v2_to_v2i(scale_vec2(cub->player.dir, 30)));
	draw_line(cub->img, pos, target, 0x00FFFF00);
	draw_circle(cub->img, pos, size.x / 2, color);
}

int	render_loop(t_cub *cub)
{
	input_handler(cub);
	draw_ceilling(cub);
	draw_floor(cub);
	move(cub);
	raycast(cub);
	// draw_minimap(cub, (t_vec2i){400, 0});
	// draw_player(cub);

	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	if (DEBUG)
		draw_debug_overlay(cub, (t_vec2i){0, 0});

	return (0);
}

void process_texture(t_texture *texture)
{
	int x;
	int y;

	for (y = 0; y < texture->height; ++y)
	{
		for (x = 0; x < texture->width; ++x)
		{
			// Calculate the offset to access the color of the current pixel
			int offset = (y * texture->line_length) + (x * (texture->bpp / 8));

			// Access the color values of the current pixel
			unsigned char blue = texture->addr[offset];
			unsigned char green = texture->addr[offset + 1];
			unsigned char red = texture->addr[offset + 2];

			// You can use the color values (red, green, blue) as needed
			// For example, you can print them
			printf("Pixel at (%d, %d): R=%u, G=%u, B=%u\n", x, y, red, green, blue);
		}
	}
	printf("Pixel_count: %d\n", x * y);
}

void copy_texture_pixels_to_position(t_texture *src_texture, t_data *dst_texture, int target_x, int target_y)
{
	for (int y = 0; y < src_texture->height; ++y)
	{
		for (int x = 0; x < src_texture->width; ++x)
		{
			// Calculate the offset for the current pixel in both source and destination textures
			int src_offset = (y * src_texture->line_length) + (x * (src_texture->bpp / 8));
			int dst_offset = ((y + target_y) * dst_texture->line_length) + ((x + target_x) * (dst_texture->bpp / 8));

			// Copy the pixel values from source to destination
			for (int byte = 0; byte < (src_texture->bpp / 8); ++byte)
			{
				dst_texture->addr[dst_offset + byte] = src_texture->addr[src_offset + byte];
			}
		}
	}
}

int get_pixel_color_int(t_texture *texture, int x, int y)
{
	int color = 0;

	// Ensure the coordinates are within the bounds of the texture
	if (x >= 0 && x < texture->width && y >= 0 && y < texture->height)
	{
		// Calculate the offset for the current pixel
		int offset = (y * texture->line_length) + (x * (texture->bpp / 8));

		// Read the color as a 32-bit integer
		color |= ((unsigned char)texture->addr[offset + 2]) << 16; // Red
		color |= ((unsigned char)texture->addr[offset + 1]) << 8;  // Green
		color |= ((unsigned char)texture->addr[offset]);           // Blue
	}

	return color;
}

int	main(void)
{
	t_cub cub;

	ft_bzero(&cub, sizeof(t_cub));
	// cub.wall_texture_paths[0] = "textures/wall_1.xpm";
	// cub.wall_texture_paths[1] = "textures/wall_2.xpm";
	// cub.wall_texture_paths[2] = "textures/wall_3.xpm";
	// cub.wall_texture_paths[3] = "textures/wall_4.xpm";
	cub.wall_texture_paths[0] = "textures/east.xpm";
	cub.wall_texture_paths[1] = "textures/south.xpm";
	cub.wall_texture_paths[2] = "textures/west.xpm";
	cub.wall_texture_paths[3] = "textures/north.xpm";

	
	init_cub(&cub);
	cub.ceilling_color = celling_color;
	cub.floor_color = floor_color;
	transfers_map(&cub);
	init_mouse(&cub);
	move_mouse_to_center(&cub);
	mlx_loop_hook(cub.mlx, render_loop, &cub);
	// int	img_width;
	// int	img_height;
	// copy_texture_pixels_to_position(&cub.wall_textures[0], cub.img, 0, 0);
	// copy_texture_pixels_to_position(&cub.wall_textures[1], cub.img, 64, 0);
	// copy_texture_pixels_to_position(&cub.wall_textures[2], cub.img, 128, 0);
	// copy_texture_pixels_to_position(&cub.wall_textures[3], cub.img, 192, 0);
	// mlx_put_image_to_window(cub.mlx, cub.win, cub.img->img, 0, 0);
	mlx_loop(cub.mlx);
	return (0);
}