#include <stdio.h>

int arrays()
{
	int menuChoice, size, array[100], top = -1, continueMenu = 1;

	printf("Enter the size of the array (max 100) : ");
	scanf("%d", &size);

	void insert_array(int array[], int *top, int size);
	void replace_array(int array[], int top);
	void delete_array(int array[], int *top);
	void display_array(int array[], int top);

	do
	{
		printf("\n\tARRAY IMPLEMENTATION MENU\n");
		printf("\t0. Exit\n");
		printf("\t1. Insert\n");
		printf("\t2. Replace\n");
		printf("\t3. Delete\n");
		printf("\t4. Display\n");
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
				insert_array(array, &top, size);
				break;
			case 2:
				replace_array(array, top);
				break;
			case 3:
				delete_array(array, &top);
				break;
			case 4:
				display_array(array, top);
				break;
			default:
				printf("Please enter valid choice\n");
				break;
		}

	} while (continueMenu);

	return 0;
}

void insert_array(int array[], int *top, int size)
{
	if( (*top) == size-1 )
	{
		printf("array Overflow.. can't insert more values\n");
	}
	else
	{
		int data;
		printf("Enter value to insert : ");
		scanf("%d", &data);
		(*top)++;
		array[(*top)] = data;
		printf("Inserted %d into the array\n", data);
	}
}

void replace_array(int array[], int top)
{
	if(top >= 0)
	{
		int index;
		printf("Enter index to delete : ");
		scanf("%d", &index);

		if(index > top+1 || index <= 0)
		{
			printf("Index can't be greater than the number of elements present in the array, and can't be less than or equal to 0.\n");
			printf("Index you entered = %d & Number of elements in array = %d\n", index, top+1);
		}
		else
		{
			int data;
			printf("Enter new data : ");
			scanf("%d", &data);
			array[index-1] = data;
			printf("Element at index %d replaced with %d\n", index, data);
		}
	}
	else printf("No elements to replace\n");
}

void delete_array(int array[], int *top)
{
	if( (*top) == -1 )
	{
		printf("Array Underflow.. can't delete more values\n");
	}
	else
	{
		int index;
		printf("Enter index to delete : ");
		scanf("%d", &index);
		if(index > (*top)+1 || index <= 0)
		{
			printf("Index can't be greater than the number of elements present in the array, and can't be less than or equal to 0.\n");
			printf("Index you entered = %d & Number of elements in array = %d\n", index, (*top)+1);
		}

		else
		{
			for(int i = index-1; i < (*top); i++)
				array[i] = array[i+1];
			(*top)--;
			printf("Deleted element %d from the array\n", index);
		}
	}
}

void display_array(int array[], int top)
{
	if(top >= 0)
	{
		printf("Elements in the array-\n");
		for(int i=0; i<=top; i++)
		{
			printf("%d) %d\n", i+1, array[i]);
		}
	}
	else printf("No elements to display\n");
}
