//#include"contact.h"
//
//enum OPtions {
//	EXIT,
//	ADD,
//	SHOW,
//	SEARCH,
//	DEL,
//	MODIFY,
//	SORT,
//	CLEAR
//};
//
//int main() {
//	int input;
//	Contact con;
//	InitContact(&con);
//	while (1) {
//		PrintMenu();
//		printf("Enter your choice: ");
//		scanf("%d", &input);
//		switch (input) {
//			case ADD:
//				AddContact(&con);
//				break;
//			case SHOW:
//				ShowContact(&con);
//				break;
//			case SEARCH:
//				SearchContact(&con);
//				break;
//			case DEL:
//				DelContact(&con);
//				break;
//			case MODIFY:
//				ModifyContact(&con);
//				break;
//			case SORT:
//				SortContact(&con);
//				break;
//			case CLEAR:
//				ClearContact(&con);
//				break;
//			case EXIT:
//				printf("Exiting the contact management system.\n");
//				return 0;
//			default:
//				printf("Invalid choice, please try again.\n");
//		}
//	}
//
//	return 0;
//}


#include "contact.h"

enum Options {
    EXIT,
    ADD,
    SHOW,
    SEARCH,
    DEL,
    MODIFY,
    SORT,
    CLEAR,
    SAVE,
    LOAD
};

int main() {
    int input;
    Contact con;
    InitContact(&con);

    // Try to load contacts from default file at startup
    LoadFromFile(&con, "contacts.dat");

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
        case SAVE:
            SaveToFile(&con, "contacts.dat");
            break;
        case LOAD:
            printf("Enter filename to load: ");
            char filename[100];
            scanf("%99s", filename);
            LoadFromFile(&con, filename);
            break;
        case EXIT:
            // Save to default file before exiting
            SaveToFile(&con, "contacts.dat");
            printf("\nExiting the contact management system.\n");
            FreeContact(&con);
            return 0;
        default:
            printf("\nInvalid choice, please try again.\n");
        }
    }

    FreeContact(&con);
    return 0;
}