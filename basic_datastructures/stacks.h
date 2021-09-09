#include <stdio.h>

int stacks()
{
	int menuChoice, size, stack[100], top = -1, continueMenu = 1;

	printf("Enter the size of the stack (max 100) : ");
	scanf("%d", &size);

	void push_stack(int stack[], int *top, int size);
	void pop_stack(int stack[], int *top);
	void display_stack(int stack[], int top);

	do
	{
		printf("\n\tSTACK IMPLEMENTATION MENU\n");
		printf("\t0. Exit\n");
		printf("\t1. Push\n");
		printf("\t2. Pop\n");
		printf("\t3. Display\n");
		printf("\tEnter : ");

		scanf("%d", &menuChoice);
		printf("\n");

		switch(menuChoice)
		{
			case 0:
				continueMenu = 0;
				printf("\nExiting");
				break;
			case 1:
				push_stack(stack, &top, size);
				break;
			case 2:
				pop_stack(stack, &top);
				break;
			case 3:
				display_stack(stack, top);
				break;
			default:
				printf("Please enter valid choice\n");
				break;
		}

	} while (continueMenu);

	return 0;
}

void push_stack(int stack[], int *top, int size)
{
	if( (*top) == size-1 )
	{
		printf("Stack Overflow.. can't push more values\n");
	}
	else
	{
		int data;
		printf("Enter value to push : ");
		scanf("%d", &data);
		(*top)++;
		stack[(*top)] = data;
		printf("Pushed %d into the stack\n", data);
	}
}

void pop_stack(int stack[], int *top)
{
	if( (*top) == -1 )
	{
		printf("Stack Underflow.. can't pop more values\n");
	}
	else
	{
		printf("Element Popped - %d\n", stack[(*top)]);
		(*top)--;
	}
}

void display_stack(int stack[], int top)
{
	if(top >= 0)
	{
		printf("Elements in the stack-\n");
		for(int i=top; i>=0; i--)
		{
			printf("%d\n", stack[i]);
		}
	}
	else printf("No elements to display\n");
}