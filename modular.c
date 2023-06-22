#include "monty.h"
/**
 * f_mod - computes the remaining division of the second block
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line number
 * Return: no return needed
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *he;
	int len = 0, aux;

	he = *head;
	while (he)
	{
		he = he->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	he = *head;
	if (he->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = he->next->n % he->n;
	he->next->n = aux;
	*head = he->next;
	free(he);
}
