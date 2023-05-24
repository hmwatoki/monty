#include "monty.h"
/**
 * push - add an element to the top of the stack
 * @n: integer
 * Return: void
*/
stack_t *stack = NULL;
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
int pop(void)
{
int n;
stack_t *prev;
if (!stack)
{
fprintf(stderr, "Error: can't pop an empty stack\n");
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
