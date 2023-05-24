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
char *arg;
if (!instruction || instruction[0] == '#')
{
return;
}
else if (strcmp(instruction, "push") == 0)
{
arg = strtok(NULL, " \n\t");
if (!arg || !isdigit(arg[0]))
{
fprintf(stderr, "L%d: usage: push integer\n", line_no);
exit(EXIT_FAILURE);
}
push(atoi(arg));
}
else if (strcmp(instruction, "pop") == 0)
{
pop();
}
else if (strcmp(instruction, "pall") == 0)
{
pall();
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_no, instruction);
exit(EXIT_FAILURE);
}
}
