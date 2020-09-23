


// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function prototypes below...             |
// +-------------------------------------------------+
void clearKeyboard(void);
void clearKeyboard(void);
void pause(void);
int getInt(void);
int getIntInRange(int, int);
int yes(void);
int menu(void);
void ContactManagerSystem(void);
void getTenDigitPhone(char[]);
// findContactIndex 
int findContactIndex(const struct Contact[], int, const char[]);
// displayContactHeader
void displayContactHeader(void);
// displayContactFooter:
void displayContactFooter(int);
// displayContact:
// put function prototype here:
void displayContact(const struct Contact*);
// displayContacts:
void displayContacts(const struct Contact[], int);
// searchContacts:
void searchContacts(const struct Contact[], int);
// addContact:
void addContact(struct Contact[], int);
// updateContact:
void updateContact(struct Contact[], int);
// deleteContact:
void deleteContact(struct Contact[], int);
// sortContacts:
void sortContacts(struct Contact[], int);




