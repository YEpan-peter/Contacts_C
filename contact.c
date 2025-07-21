//#include"contact.h"
//
////Print the mnue of the contact management system
//void PrintMenu() {
//	printf("1. Add Contact\n");
//	printf("2. Show Contacts\n");
//	printf("3. Search Contact\n");
//	printf("4. Delete Contact\n");
//	printf("5. Modify Contact\n");
//	printf("6. Sort Contacts\n");
//	printf("7. Clear Contacts\n");
//	printf("0. Exit\n");
//}
//
//// Initialize the contact list
//void InitContact(Contact* con) {
//	assert(con != NULL);
//	con->data[0] = (PeoInf){ "","",0,"","" };
//	con->size = 0;
//}
//
//// Add a new contact
//void AddContact(Contact* con) {
//	assert(con != NULL);
//	if (con->size >= 1000) {
//		printf("Contact list is full, cannot add more contacts.\n");// Check if the contact list is full
//	}
//	else {
//		printf("Enter name: ");	
//		scanf("%s", con->data[con->size].name);
//		printf("Enter gender:");
//		scanf("%s", con->data[con->size].gender);
//		printf("Enter age: ");
//		scanf("%d", &con->data[con->size].age);
//		printf("Enter phone: ");
//		scanf("%s", con->data[con->size].phone);
//		printf("Enter address: ");
//		scanf("%s", con->data[con->size].address);
//		con->size++;
//		printf("Contact added successfully!\n");	
//	}
//}
//
//// Show all contacts
//void ShowContact(const Contact* con) {
//	assert(con != NULL);
//	if (con->size <= 0) {
//		printf("No contacts available.\n");
//	}
//	else {
//		printf("Name\tGender\tAge\tPhone\t\tAddress\n");
//		for (int i = 0; i < con->size; i++) {
//			printf("%s\t%s\t%d\t%s\t\t%s\n", con->data[i].name, con->data[i].gender,
//				con->data[i].age, con->data[i].phone, con->data[i].address);
//		}
//	}
//	
//}
//
////Find a contact by name
//void SearchContact(const Contact* con) {
//	assert(con != NULL);
//	if (con->size <= 0) {
//		printf("No contacts available to search.\n");
//		return;
//	}
//	char name[20];
//	printf("Enter the name of the contact to search: ");
//	scanf("%s", name);
//	int found = 0;
//	for (int i = 0; i < con->size; i++) {
//		if (strcmp(con->data[i].name, name) == 0) {
//			printf("Found contact: %s\t%s\t%d\t%s\t\t%s\n", con->data[i].name,
//				con->data[i].gender, con->data[i].age, con->data[i].phone, con->data[i].address);
//			found = 1;
//			break;
//		}
//	}
//	if (!found) {
//		printf("Contact with name '%s' not found.\n", name);
//	}
//}
//
//// Delete a contact by name
//void DelContact(Contact* con) {
//	assert(con != NULL);
//	if (con->size <= 0) {
//		printf("No contacts available to delete.\n");
//		return;
//	}
//	char name[20];
//	printf("Enter the name of the contact to delete ");
//	scanf("%s", name);
//	for (int i = 0; i < con->size; i++) {
//		if (strcmp(con->data[i].name, name) == 0) {
//			for (int j = i; j < con->size - 1; j++) {
//				con->data[j] = con->data[j + 1]; // Shift contacts left
//			}
//			con->size--;
//			printf("Contact '%s' deleted successfully.\n", name);
//		}
//	}
//}
//
////modify a contact by name
//void ModifyContact(Contact* con) {
//	assert(con != NULL);
//	if (con->size <= 0) {
//		printf("No contacts available to modify.\n");
//		return;
//	}
//	char name[20];
//	printf("Enter the name of the contact to modify: ");
//	scanf("%s", name);
//	for (int i = 0; i < con->size; i++) {
//		if (strcmp(con->data[i].name, name) == 0) {
//			printf("Enter new name: ");
//			scanf("%s", con->data[i].name);
//			printf("Enter new gender:");
//			scanf("%s", con->data[i].gender);
//			printf("Enter new age: ");
//			scanf("%d", &con->data[i].age);
//			printf("Enter new phone: ");
//			scanf("%s", con->data[i].phone);
//			printf("Enter new address: ");
//			scanf("%s", con->data[i].address);
//			printf("Contact modify successfully!\n");
//		}
//	}
//}
//
//// Sort contacts by name
//void SortContact(Contact* con) {
//	assert(con != NULL);
//	if (con->size <= 0) {
//		printf("No contacts available to sort.\n");
//		return;
//	}
//	for (int i = 0; i < con->size - 1; i++) {
//		for (int j = i + 1; j < con->size; j++) {
//			if (strcmp(con->data[i].name, con->data[j].name) > 0) {
//				PeoInf temp = con->data[i];
//				con->data[i] = con->data[j];
//				con->data[j] = temp;
//			}
//		}
//	}
//	printf("Contacts sorted successfully!\n");
//}
//
//// Clear all contacts
//void ClearContact(Contact* con) {
//	assert(con != NULL);
//	if (con->size <= 0) {
//		printf("No contacts available to clear.\n");
//		return;
//	}
//	con->size = 0; // Reset size to 0
//	for (int i = 0; i < 1000; i++) {
//		con->data[i] = (PeoInf){"", "", 0, "", ""}; // Reset each contact
//	}
//	printf("All contacts cleared successfully!\n");
//}



#include "contact.h"

// Print the menu of the contact management system
void PrintMenu() {
    printf("\n===== Contact Management System =====\n");
    printf("1. Add Contact\n");
    printf("2. Show Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Modify Contact\n");
    printf("6. Sort Contacts\n");
    printf("7. Clear Contacts\n");
    printf("8. Save Contacts to File\n");
    printf("9. Load Contacts from File\n");
    printf("0. Exit\n");
    printf("====================================\n");
}

// Initialize the contact list with dynamic memory
void InitContact(Contact* con) {
    assert(con != NULL);
    con->data = (PeoInf*)malloc(INIT_CAPACITY * sizeof(PeoInf));
    if (con->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    con->size = 0;
    con->capacity = INIT_CAPACITY;
}

// Free the dynamically allocated memory
void FreeContact(Contact* con) {
    assert(con != NULL);
    free(con->data);
    con->data = NULL;
    con->size = 0;
    con->capacity = 0;
}

// Save contacts to file
void SaveToFile(const Contact* con, const char* filename) {
    assert(con != NULL);
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Write the number of contacts first
    fwrite(&con->size, sizeof(int), 1, file);

    // Write all contacts
    fwrite(con->data, sizeof(PeoInf), con->size, file);

    fclose(file);
    printf("Contacts saved to %s successfully!\n", filename);
}

// Load contacts from file
void LoadFromFile(Contact* con, const char* filename) {
    assert(con != NULL);
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }

    // Read the number of contacts
    int size;
    fread(&size, sizeof(int), 1, file);

    // Check if we need to expand capacity
    if (size > con->capacity) {
        int new_capacity = con->capacity;
        while (new_capacity < size) {
            new_capacity *= GROWTH_FACTOR;
        }
        PeoInf* new_data = (PeoInf*)realloc(con->data, new_capacity * sizeof(PeoInf));
        if (new_data == NULL) {
            printf("Memory reallocation failed!\n");
            fclose(file);
            return;
        }
        con->data = new_data;
        con->capacity = new_capacity;
    }

    // Read the contacts
    fread(con->data, sizeof(PeoInf), size, file);
    con->size = size;

    fclose(file);
    printf("Contacts loaded from %s successfully!\n", filename);
}

// Add a new contact with dynamic capacity expansion
void AddContact(Contact* con) {
    assert(con != NULL);

    // Check if we need to expand capacity
    if (con->size >= con->capacity) {
        int new_capacity = con->capacity * GROWTH_FACTOR;
        PeoInf* new_data = (PeoInf*)realloc(con->data, new_capacity * sizeof(PeoInf));
        if (new_data == NULL) {
            printf("Memory reallocation failed! Cannot add more contacts.\n");
            return;
        }
        con->data = new_data;
        con->capacity = new_capacity;
        printf("Contact list capacity expanded to %d.\n", new_capacity);
    }

    printf("\n--- Add New Contact ---\n");
    printf("Enter name: ");
    scanf("%19s", con->data[con->size].name);
    printf("Enter gender: ");
    scanf("%6s", con->data[con->size].gender);
    printf("Enter age: ");
    scanf("%d", &con->data[con->size].age);
    printf("Enter phone: ");
    scanf("%11s", con->data[con->size].phone);
    printf("Enter address: ");
    scanf("%49s", con->data[con->size].address);

    con->size++;
    printf("\nContact added successfully!\n");
}

// Show all contacts
void ShowContact(const Contact* con) {
    assert(con != NULL);
    if (con->size <= 0) {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n--- All Contacts (%d) ---\n", con->size);
    printf("Name\t\tGender\tAge\tPhone\t\tAddress\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < con->size; i++) {
        printf("%-15s\t%-6s\t%-3d\t%-12s\t%-30s\n",
            con->data[i].name,
            con->data[i].gender,
            con->data[i].age,
            con->data[i].phone,
            con->data[i].address);
    }
}

// Search contact by name, phone or address
void SearchContact(const Contact* con) {
    assert(con != NULL);
    if (con->size <= 0) {
        printf("\nNo contacts available to search.\n");
        return;
    }

    printf("\n--- Search Contact ---\n");
    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Address\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    char search_term[50];
    printf("Enter search term: ");
    scanf("%49s", search_term);

    printf("\n--- Search Results ---\n");
    int found = 0;

    for (int i = 0; i < con->size; i++) {
        int match = 0;
        switch (choice) {
        case 1:
            match = (strcmp(con->data[i].name, search_term) == 0);
            break;
        case 2:
            match = (strcmp(con->data[i].phone, search_term) == 0);
            break;
        case 3:
            match = (strstr(con->data[i].address, search_term) != NULL);
            break;
        default:
            printf("Invalid search option.\n");
            return;
        }

        if (match) {
            printf("%-15s\t%-6s\t%-3d\t%-12s\t%-30s\n",
                con->data[i].name,
                con->data[i].gender,
                con->data[i].age,
                con->data[i].phone,
                con->data[i].address);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found matching your search.\n");
    }
}

// Delete a contact by name
void DelContact(Contact* con) {
    assert(con != NULL);
    if (con->size <= 0) {
        printf("\nNo contacts available to delete.\n");
        return;
    }

    printf("\n--- Delete Contact ---\n");
    char name[20];
    printf("Enter the name of the contact to delete: ");
    scanf("%19s", name);

    int found = 0;
    for (int i = 0; i < con->size; i++) {
        if (strcmp(con->data[i].name, name) == 0) {
            found = 1;
            // Shift all elements after i one position left
            for (int j = i; j < con->size - 1; j++) {
                con->data[j] = con->data[j + 1];
            }
            con->size--;
            printf("Contact '%s' deleted successfully.\n", name);
            break;
        }
    }

    if (!found) {
        printf("Contact with name '%s' not found.\n", name);
    }
}

// Modify a contact by name
void ModifyContact(Contact* con) {
    assert(con != NULL);
    if (con->size <= 0) {
        printf("\nNo contacts available to modify.\n");
        return;
    }

    printf("\n--- Modify Contact ---\n");
    char name[20];
    printf("Enter the name of the contact to modify: ");
    scanf("%19s", name);

    int found = 0;
    for (int i = 0; i < con->size; i++) {
        if (strcmp(con->data[i].name, name) == 0) {
            found = 1;
            printf("\nCurrent contact information:\n");
            printf("Name: %s\n", con->data[i].name);
            printf("Gender: %s\n", con->data[i].gender);
            printf("Age: %d\n", con->data[i].age);
            printf("Phone: %s\n", con->data[i].phone);
            printf("Address: %s\n", con->data[i].address);

            printf("\nEnter new information (leave blank to keep current value):\n");

            char input[50];

            printf("New name: ");
            scanf(" %49[^\n]", input);
            if (strlen(input) > 0) strcpy(con->data[i].name, input);

            printf("New gender: ");
            scanf(" %6[^\n]", input);
            if (strlen(input) > 0) strcpy(con->data[i].gender, input);

            printf("New age: ");
            scanf(" %49[^\n]", input);
            if (strlen(input) > 0) con->data[i].age = atoi(input);

            printf("New phone: ");
            scanf(" %11[^\n]", input);
            if (strlen(input) > 0) strcpy(con->data[i].phone, input);

            printf("New address: ");
            scanf(" %49[^\n]", input);
            if (strlen(input) > 0) strcpy(con->data[i].address, input);

            printf("\nContact modified successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Contact with name '%s' not found.\n", name);
    }
}

// Sort contacts by name
void SortContact(Contact* con) {
    assert(con != NULL);
    if (con->size <= 0) {
        printf("\nNo contacts available to sort.\n");
        return;
    }

    // Simple bubble sort
    for (int i = 0; i < con->size - 1; i++) {
        for (int j = 0; j < con->size - i - 1; j++) {
            if (strcmp(con->data[j].name, con->data[j + 1].name) > 0) {
                PeoInf temp = con->data[j];
                con->data[j] = con->data[j + 1];
                con->data[j + 1] = temp;
            }
        }
    }

    printf("\nContacts sorted by name successfully!\n");
}

// Clear all contacts
void ClearContact(Contact* con) {
    assert(con != NULL);
    if (con->size <= 0) {
        printf("\nNo contacts available to clear.\n");
        return;
    }

    printf("\nAre you sure you want to clear all contacts? (y/n): ");
    char confirm;
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        con->size = 0;
        printf("\nAll contacts cleared successfully!\n");
    }
    else {
        printf("\nOperation canceled.\n");
    }
}