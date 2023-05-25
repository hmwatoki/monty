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
 * @line_number: curr line number
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
stack_t *curr;
if (!stack)
{
return;
}
curr = stack;
while (curr != NULL)
{
printf("%d\n", curr->n);
curr = curr->prev;
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
}

/**
 * swap - swaps the top two elements of the stack
 * @line_no: line number
 * Return: void
 */
void swap(int line_no)
{
int temp;
if (!stack || !stack->prev)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
temp = stack->n;
stack->n = stack->prev->n;
stack->prev->n = temp;
}
/**
 * add - adds the top two elements of the stack
 * @line_no: line number
 * Return: void
 */
void add(int line_no)
{
int a, b;
if (!stack || !stack->prev)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
a = pop(line_no);
b = pop(line_no);
push(a + b);
}
/**
 * sub - subtracts the top element of the stack from the second top element of the stack
 * @line_no: line number
 * Return: void
 */
void sub(int line_no)
{
int a, b;
if (stack_len() < 3)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
a = pop(line_no), b = pop(line_no);
push(b - a);
}
/**
 * stack_len - returns the number of elements in the stack
 * Return: number of elements in the stack
 */
int stack_len(void)
{
int len = 0;
stack_t *current = stack;
while (current != NULL)
{
len++;
current = current->next;
}
return (len);
}
/**
 * div_op - divide the second top element of the stack by the top element
 * @line_no: line number
 * Return: void
*/
void div_op(int line_no)
{
int a,b;
if (stack_len() < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
exit(EXIT_FAILURE);
}
a = pop(line_no);
if (a == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_no);
exit(EXIT_FAILURE);
}
b = pop(line_no);
push(b / a);
}
