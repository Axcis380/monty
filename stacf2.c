#include "monty.h"

/**
 * nop - it has no function.
 * @stack: Pntr to the pntr that points top nod of stak.
 * @line_number: Intgr that represnt the line number of opcod.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - it Swap stack's top two element .
 * @stack: Pntr to a pntr that points stack's top nod.
 * @line_number: Integr that represent line number of the opcod.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - it adds nods of the top elements of the stk.
 * @stack: Phtr to pntr that points to nods of the stak.
 * @line_number: Interger that represent the line number of the op.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - it adds top two elements of the stk.
 * @stack: Phtrto a pntr that points top node of stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - it Adds top stack's elemts.
 * @stack: Pntr to a pntr that points to stk top nod.
 * @line_number: Intgr that represents the line number ofthe opcd.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
