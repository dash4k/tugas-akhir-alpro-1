#include "contact.h"

void get_contacts(FILE* file) {
	Contact contact;
	int total_contacts = 1;


	file = fopen("contact_data.dat", "rb");
	if (file == NULL) {
		printf("ERROR!");
		exit(1);
	}

	while (fread(&contact, sizeof(Contact), 1, file)) {
		printf("%d: %s, %s, %s\n", total_contacts, contact.name, contact.phone_number, contact.email);
		total_contacts++;
	}

	fclose(file);
}


void add_contact(Contact new_contact, FILE* file) {
	file = fopen("contact_data.dat", "ab+");
	if (file == NULL) {
		printf("ERROR OPENING FILE (FILE NOT FOUND)");
		exit(1);
	}

	fwrite(&new_contact, sizeof(Contact), 1, file);

	fclose(file);
}


void delete_contact(long contact_index, FILE* file) {
	// IMPORTANT: contact_index starts from 1
	long file_size;
	Contact* new_contacts;
	Contact contact_copy;
	contact_index *= sizeof(Contact);
	int i = 0;

	file = fopen("contact_data.dat", "rb");

	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	rewind(file);

	new_contacts =  malloc(file_size - sizeof(Contact));

	while (fread(&contact_copy, sizeof(Contact), 1, file)) {
		if (ftell(file) == contact_index) {
			continue;
			i++;
		}

		new_contacts[i] = contact_copy;
		i++;
	}

	file = fopen("contact_data.dat", "wb");
	fwrite(new_contacts, file_size - sizeof(Contact), 1, file);

	fclose(file);

	free(new_contacts);
}