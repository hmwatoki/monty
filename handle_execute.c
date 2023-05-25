#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * execute_instruction - execute an instruction
 * @instruction: the instruction
 * @line_no: line number
 * Return: void
*/
void execute_instruction(char *instruction, int line_no)
{
if (!instruction || instruction[0] == '#')
{
return;
}
else if (strcmp(instruction, "push") == 0)
{
int value;
if (sscanf(strtok(NULL, " \n\t"), "%d", &value) == 1)
{
push(value);
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_no);
exit(EXIT_FAILURE);
}
}
else if (strcmp(instruction, "pop") == 0)
{
pop(line_no);
}
else if (strcmp(instruction, "pall") == 0)
{
pall();
}
else if (strcmp(instruction, "pint") == 0)
{
pint(line_no);
}
else if (strcmp(instruction, "swap") == 0)
{
swap(line_no);
}
else if (strcmp(instruction, "add") == 0)
{
add(line_no);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_no, instruction);
exit(EXIT_FAILURE);
}
}
