#ifndef MONTY_H
#define MONTY_H
#define MAX_LINE_LENGTH 1024
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(int n);
int pop(int line_number);
void pall(void);
void pint(int line_no);
void swap(int line_no);
void add(int line_no);
void sub(int line_number);
int stack_len(void);
void div_op(int line_no);
void execute_instruction(char *instruction, int line_no);
#endif
