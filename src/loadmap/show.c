#include "j_header.h"

void show_arr(char **arr)
{
    int i = 0;
    printf("\nshow array \n");
    while(arr[i] != NULL)
    {
        printf("i: %i  >%s<\n", i, arr[i]);
        i++;
    }
    printf("--- End ---\n\n");
}

void show_color(t_color color)
{
    printf("show color\n");
    printf(" R: %i\n", color.r);
    printf(" G: %i\n", color.g);
    printf(" B: %i\n", color.b);
    printf(" A: %i\n\n", color.a);
}