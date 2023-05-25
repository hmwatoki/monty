#include "monty.h"
stack_t *stack;
/**
 * push - add an element to the top of the stack
 * @n: integer
 * Return: void
*/
void push(int n)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = n;
new_node->prev = stack;
stack = new_node;
}
/**
 * pop - remove the element from the top of the stack
 * Return: integer
*/
int pop(int line_number)
{
int n;
stack_t *prev;
if (!stack)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
prev = stack->prev;
n = stack->n;
free(stack);
stack = prev;
return (n);
}
/**
 * pall - print all the elements in the stack
 * Return: void
*/
void pall(void)
{
stack_t *current;
if (!stack)
{
return;
}
current = stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->prev;
}
}
/**
 * pint - prints the value at the top of the stack
 * @line_no: line number
 * Return: void
 */
void pint(int line_no)
{
if (!stack)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
exit(EXIT_FAILURE);
}
printf("%d\n", stack->n);
pop(line_no);
}
