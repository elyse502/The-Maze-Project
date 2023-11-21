/*
 * File: win.c
 * Auth: Elysée NIYIBIZI
 *
 */

#include "maze.h"

/**
 * print_win - Print a win message win player finishes the game
 **/
void print_win(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("     \\  /  __   |     |\n");
	printf("      \\/  /  \\  |     |\n");
	printf("      /  |    | |     |\n");
	printf("     /    \\__/   \\___/\n\n");
	printf("\\      /\\      / ------- |\\   |\n");
	printf(" \\    /  \\    /     |    | \\  |\n");
	printf("  \\  /    \\  /      |    |  \\ |\n");
	printf("   \\/      \\/    ------- |   \\|\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
}

/**
 * check_win - Check if the player has found the win spot in the maze
 * @play: Player x/y coordinate
 * @win: The x/y coordinate of the win space
 * @win_value: If the player has found the win space or not
 * Return: 1 if player found win space, 0 if not
 **/
int check_win(double_s play, int_s win, int *win_value)
{
	if ((int) play.x == win.x && (int) play.y == win.y)
	{
		*win_value = 1;
		return (1);
	}
	return (0);
}
