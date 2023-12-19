#include <stdio.h>
#include "contact.h"


int main() {
	printf("\033[44m");
	printf("\033[1;36m");
	FILE* file;
	bool quit = false;
	int choice = -1;
	char ch;

	while (!quit)
	{
		clear_screen();
		printf("\n\t\t\t\t\t\t  CONTACT\n\n");
		printf("\t\t\t\t\t\t MAIN MENU\n\n\n");
		printf("\t\t\t 1. Add Contact");
		printf("\t\t\t\t 4. Search Contact\n\n");
		printf("\t\t\t 2. Show Contact");
		printf("\t\t\t 5. Delete Contact\n\n");
		printf("\t\t\t 3. Modify Contact");
		printf("\t\t\t 6. Reset Contact\n\n\n");
		printf("\t\t\t\t\t\t 7. Exit\n\n");
		printf("\t\t\t\t\t\t Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			clear_screen();

			printf("\n\t\t\t\t\t\t    CONTACT\n\n");
			printf("\t\t\t\t\t\t ADDING CONTACT\n\n\n");

			Contact addContact;

			printf("\t\t\t Enter the name of the person\t\t: ");
			while ((ch = getchar()) != '\n' && ch != EOF);
			fgets(addContact.name, 20, stdin);
			rmv_newline(addContact.name);

			printf("\t\t\t Enter the phone number of the person\t: ");
			scanf("%s", addContact.phone_number);

			printf("\t\t\t Enter the email of the person\t\t: ");
			scanf("%s", addContact.email);

			clear_screen();

			printf("\n\t\t\t\t\t\t    CONTACT\n\n");
			printf("\t\t\t\t\t\t ADDING CONTACT\n\n\n");

			printf("\t\t\t\tAdding: %s, %s, %s\n", addContact.name, addContact.phone_number, addContact.email);
			printf("\n\n\t\t\t\t\t ");
			system("pause");

			add_contact(addContact, file);
			break;
		
		case 2:
			clear_screen();

			printf("\n\t\t\t\t\t\t     CONTACT\n\n");
			printf("\t\t\t\t\t\t SHOWING CONTACT\n\n\n");

			printf("\t\t Index   Name \t\t\t\t Phone Number \t\t Email\n");
			get_contacts(file);
			
			printf("\n\n\t\t ");
			system("pause");
			
			break;
		
		case 3:
			clear_screen();

			printf("\n\t\t\t\t\t\t      CONTACT\n\n");
			printf("\t\t\t\t\t\t MODIFYING CONTACT\n\n\n");

			printf("\t\t Index   Name \t\t\t\t Phone Number \t\t Email\n");
			get_contacts(file);
			int contactIndex;
			Contact modifyContact;
			
			printf("\n\n\t\t Which contact you wish to modify?: ");
			scanf("%d", &contactIndex);

			clear_screen();

			printf("\n\t\t\t\t\t\t      CONTACT\n\n");
			printf("\t\t\t\t\t\t MODIFYING CONTACT\n\n\n");

			printf("\t\t\t Enter the new name of the contact\t\t: ");
			while ((ch = getchar()) != '\n' && ch != EOF);
			fgets(modifyContact.name, 20, stdin);
			rmv_newline(modifyContact.name);

			printf("\t\t\t Enter the new phone number of the contact\t: ");
			scanf("%s", modifyContact.phone_number);

			printf("\t\t\t Enter the new email of the contact\t\t: ");
			scanf("%s", modifyContact.email);

			modify_contact(contactIndex, modifyContact, file);

			clear_screen();

			printf("\n\t\t\t\t\t\t      CONTACT\n\n");
			printf("\t\t\t\t\t\t MODIFYING CONTACT\n\n\n");

			printf("\t\t Index   Name \t\t\t\t Phone Number \t\t Email\n");
			get_contacts(file);

			printf("\n\n\t\t ");
			system("pause");

			break;

		case 4:
			clear_screen();

			printf("\n\t\t\t\t\t\t      CONTACT\n\n");
			printf("\t\t\t\t\t\t SEARCHING CONTACT\n\n\n");

			char searchContact[50];

			printf("\t\t Search: ");
			scanf("%s", searchContact);

			clear_screen();

			printf("\n\t\t\t\t\t\t      CONTACT\n\n");
			printf("\t\t\t\t\t\t SEARCHING CONTACT\n\n\n");


			int* searched_positions = search_contacts(searchContact, file);
			printf("\t\t searched \"%s\"\n", searchContact);
			printf("\t\t found %d match(es)\n", searched_positions[0]);
			if (searched_positions[0] > 0) {	
				printf("\t\t at index:");
			}
			display_search(searched_positions, file);

			printf("\n\n\t\t ");
			system("pause");

			free(searched_positions);

			break;

		case 5:
			clear_screen();

			printf("\n\t\t\t\t\t\t     CONTACT\n\n");
			printf("\t\t\t\t\t\t DELETING CONTACT\n\n\n");

			printf("\t\t Index   Name \t\t\t\t Phone Number \t\t Email\n");
			get_contacts(file);
			int contactDelete;
			
			printf("\n\n\t\t Which contact you wish to delete?: ");
			scanf("%d", &contactDelete);

			delete_contact(contactDelete, file);

			clear_screen();

			printf("\n\t\t\t\t\t\t     CONTACT\n\n");
			printf("\t\t\t\t\t\t DELETING CONTACT\n\n\n");

			printf("\t\t Index   Name \t\t\t\t Phone Number \t\t Email\n");
			get_contacts(file);

			printf("\n\n\t\t ");
			system("pause");

			break;

		case 6:
			clear_screen();

			printf("\n\t\t\t\t\t\t     CONTACT\n\n");
			printf("\t\t\t\t\t\t RESETING CONTACT\n\n\n");

			char seriously;

			printf("\t\t     WARNING: This process will delete every single data stored in this file.\n");
			printf("\n\t\t\t\t\t      Do you wish to continue? \n\n\t\t\t\t\t\t    [Y] / [N]: ");
			
			scanf("%s", &seriously);

			seriously = tolower(seriously);

			if (seriously == 'y')
			{
				reset_contact(file);
			}
			else
			{
				printf("\n\n\t\t\t\t\t ");
				system("pause");
			}

			break;

		case 7:
			clear_screen();

			printf("\n\t\t\t\t\t\t     CONTACT\n\n");
			printf("\t\t\t\t\t\t EXITING CONTACT\n\n\n");

			char isSure;
			
			printf("\t\t\t\t\t\t  Are you sure? \n\n\t\t\t\t\t\t   [Y] / [N]: ");
			scanf("%s", &isSure);

			isSure = tolower(isSure);

			if (isSure == 'y')
			{
				printf("\n\n\t\t\t\t\t\t   Good Bye! :< \n\n");
				quit = true;
			}
			else
			{
				printf("\n\n\t\t\t\t\t ");
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