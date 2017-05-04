#include <stdio.h>
#include <stdlib.h>

struct Stack_element{
	int value;
	struct Stack_element *next;
};
typedef struct Stack_element Stack_element;

typedef struct {
	Stack_element *sp;
} Stack;

void stack_init(Stack *stack){
	stack->sp = NULL;
}

int stack_push(int element, Stack *stack){
	Stack_element *new;
	if ((new = (Stack_element*) malloc(sizeof(Stack_element))) == NULL) return 0;
	new->value = element;
	new->next = stack->sp;
	stack->sp = new;
	return 1;
}

int stack_pop(int *element, Stack *stack){
	Stack_element *helper;
	if (stack->sp == NULL) return 0;
	*element = stack->sp->value;
	helper = stack->sp->next;
	free(stack->sp);
	stack->sp = helper;
	return 1;
}

void stack_print(Stack *stack){
	Stack_element *iterator = stack->sp;
	printf("Stack, from top to bottom:\n");
	while (1){
		printf("%d\n", iterator->value);
		if ((iterator->next)==NULL) break;
		iterator = iterator->next;
	}
}

int main(void){
	Stack a;
	int temp;
	stack_init(&a);
	stack_push(42,&a);
	stack_push(5,&a);


	stack_pop(&temp,&a);
	stack_pop(&temp,&a);

	printf("%d\n",temp); /* should print 42 */

	return 0;
}

