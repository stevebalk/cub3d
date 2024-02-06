#include <stdlib.h>
#include <stdio.h>

void show_iarr(int **arr)
{
	int i = -1;
	printf("show\n");
	while(arr[++i])
		printf("i: %i   = %i\n", i, arr[i][0]);
}

int main(void)
{
	int count = 10;
	int i = 0;
	int **iarr;

	iarr = (int **)malloc(sizeof(int *)*count);
	iarr[9] = NULL;
	while (i < 9)
	{
		iarr[i] = malloc(sizeof(int));
		iarr[i][0] = i;
		i++;
	}
	show_iarr(iarr);
	return 0;
}