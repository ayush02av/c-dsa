#include <stdio.h>
#include <stdlib.h>

struct Linked_List_Node
{
	int data;
	struct Linked_List_Node *next;
};

int linkedlists()
{
	int menuChoice, continueMenu = 1;

	struct Linked_List_Node *head = (struct Linked_List_Node*)malloc(sizeof(struct Linked_List_Node));
	head->next = NULL;

	printf("Enter the value for head node : ");
	scanf("%d", &head->data);

	void Insert_New_Linked_List_Node_At_Head(struct Linked_List_Node **head);
	void Insert_New_Linked_List_Node_At_Tail(struct Linked_List_Node *head);
	void Display_Linked_List_Nodes(struct Linked_List_Node *head);

	do
	{
		printf("\n\tLINKED LIST IMPLEMENTATION MENU\n");
		printf("\t0. Exit\n");
		printf("\t1. Insert New at Head\n");
		printf("\t2. Insert New at Tail\n");
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
				Insert_New_Linked_List_Node_At_Head(&head);
				break;
			case 2:
				Insert_New_Linked_List_Node_At_Tail(head);
				break;
			case 3:
				Display_Linked_List_Nodes(head);
				break;
			default:
				printf("Please enter valid choice\n");
				break;
		}

	} while (continueMenu);

	return 0;
}

void Display_Linked_List_Nodes(struct Linked_List_Node *head)
{
	struct Linked_List_Node *current = NULL;
	current = (struct Linked_List_Node*)malloc(sizeof(struct Linked_List_Node));
	current = head;

	int index=1;
	while(current != NULL)
	{
		printf("%d) %d\n", index, current->data);
		current = current->next;
		index++;
	}
}

void Insert_New_Linked_List_Node_At_Tail(struct Linked_List_Node *head)
{	
	int data;
	printf("Enter value to be added : ");
	scanf("%d", &data);

	struct Linked_List_Node *tail = NULL;
	tail = (struct Linked_List_Node*)malloc(sizeof(struct Linked_List_Node));
	tail = head;

	while(tail->next != NULL)
	{
		tail = tail->next;
	}

	struct Linked_List_Node *new = NULL;
	new = (struct Linked_List_Node*)malloc(sizeof(struct Linked_List_Node));
	new->next = NULL;
	new->data = data;

	tail->next = new;

	printf("%d added at tail.\n", data);
}

void Insert_New_Linked_List_Node_At_Head(struct Linked_List_Node **head)
{	
	int data;
	printf("Enter value to be added : ");
	scanf("%d", &data);

	struct Linked_List_Node *new = NULL;
	new = (struct Linked_List_Node*)malloc(sizeof(struct Linked_List_Node));

	new->data = data;
	new->next = (*head);
	(*head) = new;
	
	printf("%d added at head.\n", data);
}