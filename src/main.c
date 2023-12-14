#include <stdio.h>
#include "contact.h"


int main() {
	printf("\033[1;36m");
	FILE* file;
	bool quit = false;
	int choice = -1;

	while (!quit)
	{
		clear_screen();
		printf("\t\t\t\t\t\t MAIN MENU\n");
		printf("\n\t\t 1. Add Contact");
		printf("\t\t\t 4. Search Contact");
		printf("\t\t 7. Exit\n");
		printf("\t\t 2. Show Contact");
		printf("\t\t 5. Delete Contact\n");
		printf("\t\t 3. Modify Contact");
		printf("\t\t 6. Reset Contact\n");
		
		printf("\n\t\t Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			clear_screen();

			Contact addContact;

			printf("\t\t Enter the name of the person: ");
			scanf("%s", addContact.name);

			printf("\t\t Enter the phone number of the person: ");
			scanf("%s", addContact.phone_number);

			printf("\t\t Enter the email of the person: ");
			scanf("%s", addContact.email);

			clear_screen();

			printf("\t\t Adding: %s, %s, %s\n", addContact.name, addContact.phone_number, addContact.email);
			printf("\n\t\t ");
			system("pause");

			add_contact(addContact, file);
			break;
		
		case 2:
			clear_screen();

			get_contacts(file);
			
			printf("\n\t\t ");
			system("pause");
			
			break;
		
		case 3:
			clear_screen();

			get_contacts(file);
			int contactIndex;
			Contact modifyContact;
			
			printf("\n\t\t Which contact you wish to modify?: ");
			scanf("%d", &contactIndex);

			clear_screen();


			printf("Enter the new name of the contact: ");
			scanf("%s", modifyContact.name);

			printf("Enter the new number of the contact: ");
			scanf("%s", modifyContact.phone_number);

			printf("Enter the new email of the contact: ");
			scanf("%s", modifyContact.email);

			modify_contact(contactIndex, modifyContact, file);

			clear_screen();


			get_contacts(file);

			printf("\n\t\t ");
			system("pause");

			break;

		case 4:
			clear_screen();

			char searchContact[50];

			printf("\t\t Search: ");
			scanf("%s", searchContact);

			clear_screen();


			int* searched_positions = search_contacts(searchContact, file);
			printf("\t\t searched \"%s\"\n", searchContact);
			printf("\t\t found %d match(es)\n", searched_positions[0]);
			if (searched_positions[0] > 0) {	
				printf("\t\t at index:");
			}
			display_search(searched_positions, file);

			printf("\n\t\t ");
			system("pause");

			free(searched_positions);

			break;

		case 5:
			clear_screen();

			get_contacts(file);
			int contactDelete;
			
			printf("\n\t\t Which contact you wish to delete?: ");
			scanf("%d", &contactDelete);

			delete_contact(contactDelete, file);

			clear_screen();


			get_contacts(file);

			printf("\n\t\t ");
			system("pause");

			break;

		case 6:
			clear_screen();

			char seriously;

			printf("\t\t WARNING: You will delete every single data stored in this file\n");
			printf("\n\t\t Do you want to continue? \n\n\t\t [Y] / [N]: ");
			
			scanf("%s", &seriously);

			seriously = tolower(seriously);

			if (seriously == 'y')
			{
				reset_contact(file);
			}
			else
			{
				printf("\n\t\t ");
				system("pause");
			}

			break;

		case 7:
			clear_screen();

			char isSure;
			
			printf("\t\t Are you sure? \n\n\t\t [Y] / [N]: ");
			scanf("%s", &isSure);

			isSure = tolower(isSure);

			if (isSure == 'y')
			{
				printf("\n\t\t Good Bye! :< \n\n");
				quit = true;
			}
			else
			{
				printf("\n\t\t ");
				system("pause");
			}
			
			break;

		default:
			break;
		}
	}	
	
	printf("\033[0m");
	return 0;
}