#include "so_long.h"

void	print_map (t_img *img)
{
	int j = 0;

	while(j < img->y && img->map[j])
	{
		printf("line %d : %s\n",j ,img->map[j]);
		j++;
	}
}