

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5
#include <stdio.h>
#include<string.h>
#include"contactHelpers.h"
#include "contacts.h"


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

void clearKeyboard(void)
{

	while (getchar() != '\n'); // empty execution code block on purpose
}
// pause: Empty function definition goes here:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}
// getInt: Empty function definition goes here:
int getInt(void) {
	int val;
	char NL = 'x';
	while (NL != '\n')
	{
		scanf("%d%c", &val, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return val;
}
// getIntInRange: Empty function definition goes here:
int getIntInRange(int low, int max) {
	int valrange = getInt();
	while ((valrange < low) || (valrange > max))
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", low, max);
		valrange = getInt();
	}
	return valrange;
}
// yes: Empty function definition goes here:
int yes(void) {
	int flag = 0;
	int retVal;
	char val;
	char NL;
	do
	{
		scanf("%c%c", &val, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		if ((val == 'Y' || val == 'y') && (NL == '\n')) {
			flag = 1;
			retVal = 1;
		}
		else if ((val == 'N' || val == 'n') && (NL == '\n'))
		{
			flag = 1;
			retVal = 0;
		}
	} while (flag == 0);
	return retVal;
}
// menu: Empty function definition goes here:
int menu(void) {
	int select;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	select = getIntInRange(0, 6);
	printf("\n");
	return select;
}
// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void) {
	struct Contact contacts[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
			{
				{ "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};
	int selection = 0;
	int end = 0;
	while (end == 0)
	{
		selection = menu();
		switch (selection)
		{
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();   
                        printf("\n");
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			end = yes();
			printf("\n");
			break;
		}
	}
	printf("Contact Management System: terminated\n");
}
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	int contact;
	int flag = 0;
	int value = -1;
	for (i = 0; i < size && flag == 0; i++) {
		contact = strcmp(contacts[i].numbers.cell, cellNum);
		if (contact == 0) {
			flag = 1;
			value = i;
		}

	}
	return value;
}
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


void displayContactFooter(int size) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", size);
        printf("\n");
}

void displayContact(const struct Contact* contact) {
	if (strlen(contact->name.middleInitial) == 0) {
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	else
	{
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

void displayContacts(const struct Contact contact[], int size) {
	int contactCount = 0;
	int i;
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(contact[i].numbers.cell) > 0) {
			displayContact(&contact[i]);
			contactCount++;
		}
	}
	displayContactFooter(contactCount);
}

void searchContacts(const struct Contact contact[], int size) {
	char searchCellPhone[11];
	int index;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(searchCellPhone);
	index = findContactIndex(contact, size, searchCellPhone);
	if (index > -1) {
		printf("\n");
		displayContact(&contact[index]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}

void addContact(struct Contact contact[], int size) {
	int addContact = -1;
	int i;
	int flag = 0;
	int max = 0;
	for (i = 0; i < size&& flag == 0; i++)
	{
		if (strlen(contact[i].numbers.cell) == 0)
		{
			addContact = i;
			flag = 1;
			max = 1;
			getContact(&contact[addContact]);
			printf("--- New contact added! ---\n");
		}
	}
	if (max == 0)
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
}
void updateContact(struct Contact contact[], int size) {
	char respond[11];
	int contactIndex;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(respond);
	contactIndex = findContactIndex(contact, size, respond);
	if (contactIndex > -1)
	{
		printf("\nContact found:\n");
		displayContact(&contact[contactIndex]);

		printf("\nDo you want to update the name? (y or n): ");
		if (yes() == 1)
			getName(&contact[contactIndex].name);

		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1)
			getAddress(&contact[contactIndex].address);

		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1)
			getNumbers(&contact[contactIndex].numbers);
		printf("--- Contact Updated! ---\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");
}
void deleteContact(struct Contact contact[], int size) {
	char response[11];
	int index;
	int input = 0;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(response);

	index = findContactIndex(contact, size, response);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[index]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		input = yes();
		if (input == 1) {
			contact[index].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

void sortContacts(struct Contact contacts[], int size) {
	int i, numbers;
	struct Contact Con;
	for (i = size - 1; i > 0;i--) {
		for (numbers = 0; numbers <i; numbers++) {
			if (strcmp(contacts[numbers].numbers.cell, contacts[numbers + 1].numbers.cell) > 0) {
				Con = contacts[numbers];
				contacts[numbers] = contacts[numbers + 1];
				contacts[numbers + 1] = Con;
			}
		}
	}
	printf("--- Contacts sorted! ---\n");
}
