#include "basic_datastructures/stacks.h"
#include "basic_datastructures/queues.h"

int main()
{
	int menu_choice, continueMenu = 1;

	int menu_choices_indices[] = {1, 2};
	char menu_choices[][20] = {"Stack", "Queue"};

	int number_of_choices = sizeof(menu_choices_indices) / sizeof(int);

	do
	{
		printf("\n\tMAIN MENU\n\t=========\n");

		printf("\t0) Exit\n");
		for(int i = 0; i < number_of_choices; i++)
			printf("\t%d) %s operations\n", menu_choices_indices[i], menu_choices[i]);

		printf("\tEnter : ");
		scanf("%d", &menu_choice);
		printf("\n");

		switch(menu_choice)
		{
			case 0:
				continueMenu = 0;
				printf("Exiting...");
				break;
			case 1:
				stacks();
				break;
			case 2:
				queues();
				break;
		}

	} while (continueMenu);

	return 0;
}