#include "holberton.h"
/**
 * main - verify if all file exist
 * Desription: path to the file
 * Return: 0 if the file exist or -1 if not
 */
int exist(char **pathname)
{
	int exist_stats;

	exist_stast = (pathname, O_INORDER);
	if (exist_stat != -1)
	{
		close(exist_stat);
		return (0);
	}
	else
		return (-1);
}
