#include"contact.h"

//Print the mnue of the contact management system
void PrintMenu() {
	printf("1. Add Contact\n");
	printf("2. Show Contacts\n");
	printf("3. Search Contact\n");
	printf("4. Delete Contact\n");
	printf("5. Modify Contact\n");
	printf("6. Sort Contacts\n");
	printf("7. Clear Contacts\n");
	printf("0. Exit\n");
}

// Initialize the contact list
void InitContact(Contact* con) {
	assert(con != NULL);
	con->data[0] = (PeoInf){ "","",0,"","" };
	con->size = 0;
}

// Add a new contact
void AddContact(Contact* con) {
	assert(con != NULL);
	if (con->size >= 1000) {
		printf("Contact list is full, cannot add more contacts.\n");// Check if the contact list is full
	}
	else {
		printf("Enter name: ");	
		scanf("%s", con->data[con->size].name);
		printf("Enter gender:");
		scanf("%s", con->data[con->size].gender);
		printf("Enter age: ");
		scanf("%d", &con->data[con->size].age);
		printf("Enter phone: ");
		scanf("%s", con->data[con->size].phone);
		printf("Enter address: ");
		scanf("%s", con->data[con->size].address);
		con->size++;
		printf("Contact added successfully!\n");	
	}
}

// Show all contacts
void ShowContact(Contact* con) {
	assert(con != NULL);
	if (con->size <= 0) {
		printf("No contacts available.\n");
	}
	else {
		printf("Name\tGender\tAge\tPhone\t\tAddress\n");
		for (int i = 0; i < con->size; i++) {
			printf("%s\t%s\t%d\t%s\t\t%s\n", con->data[i].name, con->data[i].gender,
				con->data[i].age, con->data[i].phone, con->data[i].address);
		}
	}
	
}

//Find a contact by name
void SearchContact(const Contact* con) {
	assert(con != NULL);
	if (con->size <= 0) {
		printf("No contacts available to search.\n");
		return;
	}
	char name[20];
	printf("Enter the name of the contact to search: ");
	scanf("%s", name);
	int found = 0;
	for (int i = 0; i < con->size; i++) {
		if (strcmp(con->data[i].name, name) == 0) {
			printf("Found contact: %s\t%s\t%d\t%s\t\t%s\n", con->data[i].name,
				con->data[i].gender, con->data[i].age, con->data[i].phone, con->data[i].address);
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("Contact with name '%s' not found.\n", name);
	}
}

// Delete a contact by name
void DelContact(Contact* con) {
	assert(con != NULL);
	if (con->size <= 0) {
		printf("No contacts available to delete.\n");
		return;
	}
	char name[20];
	printf("Enter the name of the contact to delete ");
	scanf("%s", name);
	for (int i = 0; i < con->size; i++) {
		if (strcmp(con->data[i].name, name) == 0) {
			for (int j = i; j < con->size - 1; j++) {
				con->data[j] = con->data[j + 1]; // Shift contacts left
			}
			con->size--;
			printf("Contact '%s' deleted successfully.\n", name);
		}
	}
}

//modify a contact by name
void ModifyContact(Contact* con) {
	assert(con != NULL);
	if (con->size <= 0) {
		printf("No contacts available to modify.\n");
		return;
	}
	char name[20];
	printf("Enter the name of the contact to modify: ");
	scanf("%s", name);
	for (int i = 0; i < con->size; i++) {
		if (strcmp(con->data[i].name, name) == 0) {
			printf("Enter new name: ");
			scanf("%s", con->data[i].name);
			printf("Enter new gender:");
			scanf("%s", con->data[i].gender);
			printf("Enter new age: ");
			scanf("%d", &con->data[con->size].age);
			printf("Enter new phone: ");
			scanf("%s", con->data[con->size].phone);
			printf("Enter new address: ");
			scanf("%s", con->data[con->size].address);
			con->size++;
			printf("Contact modify successfully!\n");
		}
	}
}

// Sort contacts by name
void SortContact(Contact* con) {
	assert(con != NULL);
	if (con->size <= 0) {
		printf("No contacts available to sort.\n");
		return;
	}
	for (int i = 0; i < con->size - 1; i++) {
		for (int j = i + 1; j < con->size; j++) {
			if (strcmp(con->data[i].name, con->data[j].name) > 0) {
				PeoInf temp = con->data[i];
				con->data[i] = con->data[j];
				con->data[j] = temp;
			}
		}
	}
	printf("Contacts sorted successfully!\n");
}

// Clear all contacts
void ClearContact(Contact* con) {
	assert(con != NULL);
	if (con->size <= 0) {
		printf("No contacts available to clear.\n");
		return;
	}
	con->size = 0; // Reset size to 0
	for (int i = 0; i < 1000; i++) {
		con->data[i] = (PeoInf){"", "", 0, "", ""}; // Reset each contact
	}
	printf("All contacts cleared successfully!\n");
}
