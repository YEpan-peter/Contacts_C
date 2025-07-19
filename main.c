#include"contact.h"

enum OPtions {
	EXIT,
	ADD,
	SHOW,
	SEARCH,
	DEL,
	MODIFY,
	SORT,
	CLEAR
};

int main() {
	int input;
	Contact con;
	InitContact(&con);
	while (1) {
		PrintMenu();
		printf("Enter your choice: ");
		scanf("%d", &input);
		switch (input) {
			case ADD:
				AddContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case DEL:
				DelContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case CLEAR:
				ClearContact(&con);
				break;
			case EXIT:
				printf("Exiting the contact management system.\n");
				return 0;
			default:
				printf("Invalid choice, please try again.\n");
		}
	}

	return 0;
}