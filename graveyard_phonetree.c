#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

char contacts[MAX_CONTACTS][MAX_CONTACT_NAME_LENGTH + MAX_PHONE_NUMBER_LENGTH + MAX_EMAIL_ADDRESS_LENGTH + 3];
char names[MAX_CONTACTS][MAX_CONTACT_NAME_LENGTH];
char phones[MAX_CONTACTS][MAX_PHONE_NUMBER_LENGTH];
char emails[MAX_CONTACTS][MAX_EMAIL_ADDRESS_LENGTH];

void contacts_list(int contactCount);
void contacts_selection(int contactCount);

int main(void)
{
    
    int choice;
    int contactCount = 0;
    char line[256];
    // int i = 0;


    FILE *filePtr;
    filePtr = fopen("phone_contacts.csv", "r");
    if (filePtr == NULL)
    {
    printf("Failed to open the file.\n");
    return 1;
    }

    // while (fgets(contacts[contactCount], sizeof(contacts[contactCount]), filePtr) != NULL && contactCount < MAX_CONTACTS)
    // {
    // contacts[contactCount][strcspn(contacts[contactCount], "\n")] = '\0';
    // contactCount++;
    // }

    // while (fgets(line, sizeof(line), filePtr) != NULL && contactCount < MAX_CONTACTS)
    while (fgets(contacts[contactCount], sizeof(contacts[contactCount]), filePtr) != NULL && contactCount < MAX_CONTACTS)
    {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        
        sscanf(line, "%49[^,],%14[^,],%49[^\n]", 
               names[contactCount], phones[contactCount], emails[contactCount]);
        
        contactCount++;
    }

    fclose(filePtr);

do {
    printf("Smartphone Contact Hub\n");
    printf("1. List Contacts\n");
    printf("2. Select Contact\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      contacts_list(contactCount);
      break;
    }

    case 2: {
      contacts_selection(contactCount);
      break;
    }

    case 3: {
      printf("Exiting the Smartphone Contact Hub.\n");
      printf("\n");
      break;
    }

    default:
      printf("Invalid choice. Please try again.\n\n");
      break;
    }
  } while (choice != 3);

}

void contacts_list(int contactCount)
{
    printf("Phone Contacts:\n");

    for (int i = 0; i < contactCount; i++)
    {
        printf("%d. Name: %.*s\n", i + 1, MAX_CONTACT_NAME_LENGTH, names[contactCount]);
        printf("   Phone: %.*s\n", MAX_PHONE_NUMBER_LENGTH, phones[contactCount]);
        printf("   Email: %.*s\n\n", MAX_EMAIL_ADDRESS_LENGTH, emails[contactCount]);   
    }
    printf("\n");

}

void contacts_selection(char contacts[MAX_CONTACTS],int contactCount)
{
    int selection;
    printf("Enter the contact index: ");
    scanf("%d", &selection);

    if (selection < 1 || selection > contactCount)
    {
        printf("Invalid contact index.\n\n");
        return;
    }

    printf("Selected Contact:\n");
    printf("Name: %.*s\n", MAX_CONTACT_NAME_LENGTH, contacts[selection - 1]);
    printf("Phone: %.*s\n", MAX_PHONE_NUMBER_LENGTH, contacts[selection - 1] + MAX_CONTACT_NAME_LENGTH);
    printf("Email: %.*s\n", MAX_EMAIL_ADDRESS_LENGTH, contacts[selection - 1] + MAX_CONTACT_NAME_LENGTH + MAX_PHONE_NUMBER_LENGTH);

    int option;

    printf("What would you like to do?\n");
    printf("1. Call\n2. Send Email\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Calling %.*s...\n", MAX_CONTACT_NAME_LENGTH, contacts[selection - 1]);
            printf("\n");
            break;

        case 2:
            printf("Sending email to %.*s...\n", MAX_EMAIL_ADDRESS_LENGTH, contacts[selection - 1] + MAX_CONTACT_NAME_LENGTH + MAX_PHONE_NUMBER_LENGTH);
            printf("\n");
            break;

        default:
            printf("Invalid choice please try again.");
            break;
    }
}
