#include <stdio.h>

int queues()
{
	int menuChoice, size, queue[100], top = -1, continueMenu = 1;

	printf("Enter the size of the queue (max 100) : ");
	scanf("%d", &size);

	void push_queue(int queue[], int *top, int size);
	void pop_queue(int queue[], int *top);
	void display_queue(int queue[], int top);

	do
	{
		printf("\n\tQUEUE IMPLEMENTATION MENU\n");
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
				push_queue(queue, &top, size);
				break;
			case 2:
				pop_queue(queue, &top);
				break;
			case 3:
				display_queue(queue, top);
				break;
			default:
				printf("Please enter valid choice\n");
				break;
		}

	} while (continueMenu);

	return 0;
}

void push_queue(int queue[], int *top, int size)
{
	if( (*top) == size-1 )
	{
		printf("Queue Overflow.. can't push more values\n");
	}
	else
	{
		int data;
		printf("Enter value to push : ");
		scanf("%d", &data);
		(*top)++;
		queue[(*top)] = data;
		printf("Pushed %d into the queue\n", data);
	}
}

void pop_queue(int queue[], int *top)
{
	if( (*top) == -1 )
	{
		printf("Queue Underflow.. can't pop more values\n");
	}
	else
	{
		printf("Element Popped - %d\n", queue[0]);
		for(int i=0; i<(*top); i++)
			queue[i] = queue[i+1];
		(*top)--;
	}
}

void display_queue(int queue[], int top)
{
	if(top >= 0)
	{
		printf("Elements in the queue-\n");
		for(int i=top; i>=0; i--)
		{
			printf("%d\n", queue[i]);
		}
	}
	else printf("No elements to display\n");
}