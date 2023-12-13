#include <stdio.h>
#include "contact.h"


int main() {
	FILE* file;

	Contact example_contact_1 = {"SATUA", "15", "zz"};
	Contact example_contact_2 = {"DUA", "15", "zz"};
	Contact example_contact_3 = {"TIGA", "15", "zz"};
	Contact example_new_contact = {"NEW!", "16", "xx"};

	add_contact(example_contact_1, file);
	add_contact(example_contact_2, file);
	add_contact(example_contact_3, file);
	get_contacts(file);
	delete_contact(3, file);
	printf("\n");
	get_contacts(file);

	printf("\n");
	int* searched_positions = search_contacts("UA", file);
	printf("searched \"UA\"\n");
	if (searched_positions[0] > 0) {
		printf("found %d match(es)\n", searched_positions[0]);
		for (int i = 1; i <= searched_positions[0]; i++) {
			printf("at index %d\n", searched_positions[i]);
		}
	}

	free(searched_positions);

	printf("\n");

	get_contacts(file);
	modify_contact(2, example_new_contact, file);
	printf("\n");
	get_contacts(file);

	return 0;
}