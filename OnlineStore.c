/**
 * File: Online Store Simulator
 * 
 * Edited Version of the CLothing Store Simulator
 * Edited to handle international shipping and tax between USA, MEXICO, and CANADA
 */

// Include necessary header files
#include <stdio.h>   // Provides input/output functions
#include <string.h>  // Provides string manipulation functions
#include <ctype.h>

// Define constants for clothing item prices using macros
#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

// Define constants for shipping costs
#define USA_standard 5.99
#define USA_expedited 9.99
#define MEX_standard 7.99
#define MEX_expedited 12.99
#define CAN_standard 6.99
#define CAN_expedited 11.99

//Define constants for tax rates
#define USA_tax 0.08
#define MEX_tax 0.16
#define CAN_tax 0.12

int main(void) {
    // Declare variables
    char item_Input[20];  // Array to store user input for clothing type
    char country_Input[20];
    char shipping_Input[20];
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;  // Variables to store quantities of each clothing item
    float totalcost = 0.0, shippingcost = 0.0, taxrate = 0.0, taxamount = 0.0;

    //item and quantity
    do {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and calculate the total cost.\n");
        // Read user input for clothing type
        scanf("%s", item_Input);

        for(int i = 0; item_Input[i]; i++)
        {
            item_Input[i] = tolower(item_Input[i]);
        }

        // Check user input and prompt for quantity based on clothing type
        if (strcmp(item_Input, "exit") == 0) 
        {
            break;
        }

        int quantity = 0;

        //rewriting clothing stores if statements as switch cases to handle item types
        switch (item_Input[0])
        {
        case 's':
            if (strcmp(item_Input, "shirt") == 0)
            {
                printf("Enter the quantity of %ss needed: ", item_Input);
                scanf("%d", &quantity);
                shirtQuantity += quantity;
                printf("Clothing item '%s' successfully added to your cart.\n", item_Input);
            }
            else if (strcmp(item_Input, "shoes") == 0) 
            {
                printf("Enter the quantity of %s needed: ", item_Input);
                scanf("%d", &quantity);
                shoeQuantity += quantity;
                printf("Clothing item '%s' successfully added to your cart.\n", item_Input);
            }
            else
            {
                printf("Invalid item. Please enter 'shirt', 'shoes', or 'pants'.\n");
            }
            break;
        case 'p':
            if (strcmp(item_Input, "pants") == 0) 
            {
                printf("Enter the quantity of %s needed: ", item_Input);
                scanf("%d", &quantity);
                pantsQuantity += quantity;
                printf("Clothing item '%s' successfully added to your cart.\n", item_Input);
            }
            else
            {
                printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
            }
            break;
        default:
                printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
        }
    } while (1);
    
    //Calculate total item cost
    totalcost = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);

    //Shipping selection
    printf("\nEnter the shipping destination (USA, Mexico, Canada):");
    scanf("%s", country_Input);
    for(int i = 0; country_Input[i]; i++) country_Input[i] = tolower(country_Input[i]);  // Convert to lowercase

    //Determine tax rate based on country
    switch (country_Input[0])
    {
        case 'u':
            if (strcmp(country_Input, "usa") == 0)
            {
                taxrate = USA_tax;
            }
            else
            {
                printf("Invalid country. Defaulting to USA standard shipping.\n");
                taxrate = USA_tax;
            }
            break;
        case 'm':
            if (strcmp(country_Input, "mexico") == 0)
            {
                taxrate = MEX_tax;
            }
            else
            {
                printf("Invalid country. Defaulting to USA standard shipping.\n");
                taxrate = USA_tax;
            }
            break;
        case 'c':
            if (strcmp(country_Input, "canada") == 0)
            {
                taxrate = CAN_tax;
            }
            else
            {
                printf("Invalid country. Defaulting to USA standard shipping.\n");
                taxrate = USA_tax;
            }
            break;
        default:
            printf("Invalid country. Defaulting to USA standard shipping.\n");
            taxrate = USA_tax;
    }

    //Shipping method selection
    printf("Enter the shipping method (standard, expedited):\n");
    scanf("%s", shipping_Input);
    for(int i = 0; shipping_Input[i]; i++) shipping_Input[i] = tolower(shipping_Input[i]);

    //Calculate shipping cost based on country and shipping method
    switch (country_Input[0])
    {
        case 'u':
            if (strcmp(shipping_Input, "standard") == 0)
            {
                shippingcost = USA_standard;
            }
            else if (strcmp(shipping_Input, "expedited") == 0)
            {
                shippingcost = USA_expedited;
            }
            break;
        case 'm':
            if (strcmp(shipping_Input, "standard") == 0)
            {
                shippingcost = MEX_expedited;
            }
            else if (strcmp(shipping_Input, "expedited") == 0)
            {
                shippingcost = MEX_expedited;
            }
            break;
        case 'c':
            if (strcmp(shipping_Input, "standard") == 0)
            {
                shippingcost = CAN_expedited;
            }
            else if (strcmp(shipping_Input, "expedited") == 0)
            {
                shippingcost = CAN_expedited;
            }
            break;
        default:
            printf("Invalid shipping method. Defaulting to standard.\n");
            shippingcost = USA_standard;
    }
       

    //Calculate tax amount
    taxamount = totalcost * taxrate;

    //Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Total Cost:\t\t\t\t\t$%.2f\n", totalcost);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shippingcost);
    printf("Tax Amount:\t\t\t\t\t$%.2f\n", taxamount);
    printf("-------------------------------------------------------\n");
    printf("Grand Total:\t\t\t\t\t$%.2f\n", totalcost + shippingcost + taxamount);

    return 0;
}