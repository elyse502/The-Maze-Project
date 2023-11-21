#include "maze.h"

/**
 * main - The main function to run the maze game
 * @argc: The number of arguments passed to the program
 * @argv: All the arguments passed to the program
 * Return: 1 if failure, 0 if successful exit
 **/
int main(int argc, char *argv[])
{
	SDL_Instance instance;
	level *levels;
	int lvl, win_value, num_of_levels;
	keys key_press = {0, 0, 0, 0};

	lvl = win_value = 0;
	num_of_levels = argc;
	if (num_of_levels < 2)
		return (1);
	levels = build_world_from_args(argc, argv);
	if (levels == NULL)
		return (1);
	if (init_instance(&instance) != 0)
		return (1);
	lvl = 0;
	while (1)
	{
		if (keyboard_events(&key_press))
		{
			free_memory(instance, levels[lvl].map, levels[lvl].height);
			break;
		}
		movement(key_press, &levels[lvl].plane, &levels[lvl].dir, &levels[lvl].play,
			 levels[lvl].map);
		if (check_win(levels[lvl].play, levels[lvl].win, &win_value))
		{
			free_map(levels[lvl].map, levels[lvl].height);
			lvl++;
			if (lvl == argc - 1)
				break;
			win_value = 0;
		}
		draw(instance, levels[lvl].map, levels[lvl].play, levels[lvl].dir,
		     levels[lvl].plane);
	}
	close_SDL(instance);
	if (win_value)
		print_win();
	return (0);
}
