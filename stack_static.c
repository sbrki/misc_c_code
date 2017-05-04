#include <stdio.h>
#define MAXSTACK 5

typedef struct {
	int sp, values[MAXSTACK];
} Stack;


void stack_init(Stack *stack){
	stack->sp = -1;
}

int stack_push(int element, Stack *stack){
	/* Check if stack is full */
	if (stack->sp >= MAXSTACK - 1) return 0;
	/* If stack is not full, push the element */
	stack->sp++;
	stack->values[stack->sp] = element;
	return 1;
}

int stack_pop(int *element, Stack *stack){
	/* Check if stack is empty */
	if (stack->sp < 0) return 0;
	/* If stack is not empty, pop the latest element */
	*element = stack->values[stack->sp];
	stack->sp--;
	return 1;
}

int stack_print_full(Stack *stack){
	int i;
	printf("Stack top pointer: %d\n",stack->sp);
	for (i=0;i<MAXSTACK;i++){
		printf("stack[%d] = %d\n",i,stack->values[i]);
	}
}

int main(void){
	Stack a;
	stack_init(&a);
	int temp = 5;
	stack_push(42,&a);   /* push 42 to the stack*/
	stack_push(temp,&a); /* push temp (5) to the stack*/

	stack_pop(&temp,&a); /* pop 5 from the stack*/
	stack_pop(&temp,&a); /* pop 42 from the stack*/
	printf("%d\n", temp); /* should print out 42 */

}