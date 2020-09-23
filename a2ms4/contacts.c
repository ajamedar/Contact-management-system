

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"contactHelpers.h"
#include "contacts.h"
void getName(struct Name *name)
{
	char yesOrno;
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	yesOrno = yes();
	if (yesOrno == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %7[^\n]", name->middleInitial);
		clearKeyboard();
	}
	printf("Please enter the contact's last name: ");
	scanf(" %36[^\n]", name->lastName);
	clearKeyboard();
}
// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *address)
{
	char yesOrno;
	do
	{
		printf("Please enter the contact's street number: ");
		address->streetNumber = getInt();

	} while (address->streetNumber <= 0);
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	yesOrno = yes();
	if (yesOrno == 1)
	{
		do
		{
			printf("Please enter the contact's apartment number: ");
			address->apartmentNumber = getInt();
		} while (address->apartmentNumber <= 0);
	}
	else
	{
		address->apartmentNumber = 0;
	}
	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]s", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearKeyboard();

}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *numbers)
{
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes() == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
	{
		numbers->home[0] = '\0';
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else {
		numbers->business[0] = '\0';
	}
}
// getContact
void getContact(struct Contact *contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}

