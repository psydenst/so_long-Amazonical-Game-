#include "../inc/so_long.h"

typedef struct 	s_vars
{
	void *mlx;
	void *win;
}	t_vars;

int keyhook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World");
	mlx_key_hook(vars.win, keyhook, &vars);
	mlx_loop(vars.mlx);
}
