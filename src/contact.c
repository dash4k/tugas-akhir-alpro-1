#include "contact.h"


int get_contacts(FILE* file) {
	Contact contact;
	int total_contacts = 1;

	file = fopen("contact_data.dat", "rb");

	if (file == NULL) {
		printf("no contact data found, try adding one!");
		fclose(file);
		return 1;
	}

	while (fread(&contact, sizeof(Contact), 1, file)) {
		printf("%d: %s, %s, %s\n", total_contacts, contact.name, contact.phone_number, contact.email);
		total_contacts++;
	}

	fclose(file);
	return 0;
}


void add_contact(Contact new_contact, FILE* file) {
	file = fopen("contact_data.dat", "ab");
	if (file == NULL) {
		fclose(file);
		file = fopen("contact_data.dat", "wb");
	}

	fwrite(&new_contact, sizeof(Contact), 1, file);

	fclose(file);
}

int modify_contact(int contact_index, Contact new_contact, FILE* file) {
	// IMPORTANT: contact_index starts from 1

	file = fopen("contact_data.dat", "rb");
	if (file == NULL) {
		printf("Nothing to delete");
		fclose(file);
		return 1;
	}

	int file_size;
	Contact* new_contacts;
	Contact contact_copy;
	contact_index *= sizeof(Contact);
	int i = 0;

	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	rewind(file);

	if (contact_index > file_size || contact_index < sizeof(Contact)) {
		printf("invalid index");
		fclose(file);
		return 1;
	}

	new_contacts =  malloc(file_size);

	while (fread(&contact_copy, sizeof(Contact), 1, file)) {
		if (ftell(file) == contact_index) {
			new_contacts[i] = new_contact;
			i++;
			continue;
		}

		new_contacts[i] = contact_copy;
		i++;
	}

	fclose(file);

	file = fopen("contact_data.dat", "wb");
	fwrite(new_contacts, file_size, 1, file);

	fclose(file);

	free(new_contacts);

	return 0;
}

int delete_contact(int contact_index, FILE* file) {
	// IMPORTANT: contact_index starts from 1

	file = fopen("contact_data.dat", "rb");
	if (file == NULL) {
		printf("Nothing to delete");
		fclose(file);
		return 1;
	}

	int file_size;
	Contact* new_contacts;
	Contact contact_copy;
	contact_index *= sizeof(Contact);
	int i = 0;

	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	rewind(file);

	if (contact_index > file_size || contact_index < sizeof(Contact)) {
		printf("invalid index");
		fclose(file);
		return 1;
	}

	new_contacts =  malloc(file_size - sizeof(Contact));

	while (fread(&contact_copy, sizeof(Contact), 1, file)) {
		if (ftell(file) == contact_index) {
			continue;
		}

		new_contacts[i] = contact_copy;
		i++;
	}

	fclose(file);

	file = fopen("contact_data.dat", "wb");
	fwrite(new_contacts, file_size - sizeof(Contact), 1, file);

	fclose(file);

	free(new_contacts);

	return 0;
}

int* search_contacts(const char* search_term, FILE* file) {
	file = fopen("contact_data.dat", "rb");
	Contact current_contact;
	char* lowercased_search_term = str_tolower(search_term);
	int* searched_positions = (int*) malloc(sizeof(int));
	int found_count = 0;
	searched_positions[0] = found_count;
	
	rewind(file);

	while (fread(&current_contact, sizeof(Contact), 1, file)) {
		char* lowercased_contact_name = str_tolower(current_contact.name);
		char* lowercased_contact_phone_number = str_tolower(current_contact.phone_number);
		char* lowercased_contact_email = str_tolower(current_contact.email);

		if (strstr(lowercased_contact_name, lowercased_search_term) != NULL || strstr(lowercased_contact_phone_number, lowercased_search_term) != NULL || strstr(lowercased_contact_email, lowercased_search_term) != NULL) {
			found_count++;
			searched_positions = realloc(searched_positions, (found_count + 1) * sizeof(int));
			searched_positions[found_count] = ftell(file) / sizeof(Contact) ;
			
			searched_positions[0] = found_count;
		}
		free(lowercased_contact_name);
		free(lowercased_contact_phone_number);
		free(lowercased_contact_email);

	}
	free(lowercased_search_term);

	fclose(file);
	return searched_positions;

}