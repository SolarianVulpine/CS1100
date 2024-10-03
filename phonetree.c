#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

struct contactInfo {
    char name[MAX_CONTACT_NAME_LENGTH];
    char phone[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_ADDRESS_LENGTH];
};

void contacts_list(struct contactInfo contacts[], int num_contacts);
void contacts_selection(struct contactInfo contacts[]);

int main(void)
{
    struct contactInfo contacts[MAX_CONTACTS];
    int choice;
    int contactCount = 1;
    char line[256];

    FILE *filePtr;
    filePtr = fopen("phone_contacts.csv", "r");
    if (filePtr == NULL) 
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    while (contactCount < MAX_CONTACTS && fgets(line, sizeof(line), filePtr) != NULL) 
    {
        line[strcspn(line, "\n")] = '\0';
        
        sscanf(line, "%49[^,],%14[^,],%49[^\n]", contacts[contactCount].name, contacts[contactCount].phone, contacts[contactCount].email);

        contactCount++;

        if (contactCount >= MAX_CONTACTS) 
        {
            break;
        }
    }


    do {
        printf("Smartphone Contact Hub\n");
        printf("1. List Contacts\n");
        printf("2. Select Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
            {
                contacts_list(contacts, contactCount);
                break;
            }

        case 2:
        {
            contacts_selection(contacts);
            break;
        }

        case 3:
        {
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

void contacts_list(struct contactInfo contacts[], int contactCount)
{
    

    printf("Phone Contacts:\n");
    for (int i = 1; i < contactCount; i++)
    {
        printf("%d. Name: %s\n", i, contacts[i].name);
        printf("   Phone: %s\n", contacts[i].phone);
        printf("   Email: %s\n\n", contacts[i].email);
    }
    printf("\n");
}

void contacts_selection(struct contactInfo contacts[])
{

    int selection;
    printf("Enter the contact index: ");
    scanf("%d", &selection);

    if (selection < 1 || selection >= 5)
    {
        printf("Invalid contact index.\n\n");
        return;
    }


    printf("Selected Contact:\n");
    printf("Name: %s\n", contacts[selection].name);
    printf("Phone: %s\n", contacts[selection].phone);
    printf("Email: %s\n", contacts[selection].email);

    int option;
    printf("What would you like to do?\n");
    printf("1. Call\n2. Send Email\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) 
    {
        case 1:
            printf("Calling %s...\n", contacts[selection].name);
            printf("\n");
            break;

        case 2:
            printf("Sending email to %s...\n", contacts[selection].email);
            printf("\n");
            break;

        default:
            printf("Invalid choice please try again.");
            break;
    }
}
