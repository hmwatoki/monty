#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * main - start the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
*/
int main(int argc, char **argv)
{
FILE *file;
int line_no;
char *filename;
char *instruction;
char line[MAX_LINE_LENGTH];
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
filename = argv[1];
file = fopen(filename, "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
line_no = 0;
while (fgets(line, MAX_LINE_LENGTH, file))
{
line_no++;
instruction = strtok(line, " \n\t");
execute_instruction(instruction, line_no);
}
fclose(file);
exit(EXIT_SUCCESS);
}
