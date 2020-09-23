

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include"contactHelpers.h"

void printSectionHeader(const char*);
int main(void)
{
	printSectionHeader("Final A#2-Milestone #4");
	ContactManagerSystem();
	return 0;
}
void printSectionHeader(const char* testName)
{
	printf("\n");
	printf("------------------------------------------\n");
	printf("Testing: %s\n", testName);
	printf("------------------------------------------\n");
}

