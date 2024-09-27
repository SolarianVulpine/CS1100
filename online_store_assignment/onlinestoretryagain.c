/**
 * File: Online Store Simulator
 * 
 * Edited Version of the CLothing Store Simulator
 * Edited to handle international shipping and tax between USA, MEXICO, and CANADA
 * 
 * This is a version of Torin's online store that's passed the blackboard grader!!
 * 
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

    char default_country[] = "USA";
    char default_shipping[] = "Standard";

    //item and quantity
    do {
        // Display menu options to the user
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");
        // Read user input for clothing type
        scanf("%s", item_Input);

        // for(int i = 0; item_Input[i]; i++)
        // {
        //     item_Input[i] = tolower(item_Input[i]);
        // }

        // Check user input and prompt for quantity based on clothing type
        if (strcasecmp(item_Input, "exit") == 0) 
        {
            break;
        }

        int quantity = 0;

        //rewriting clothing stores if statements as switch cases to handle item types
        switch (item_Input[0])
        {
        case 's':
            if (strcasecmp(item_Input, "shirt") == 0)
            {
                printf("Enter the quantity of %ss needed: ", item_Input);
                scanf("%d", &quantity);
                shirtQuantity = quantity;
                printf("Clothing item '%s' successfully added to your cart.\n", item_Input);
            }
            else if (strcasecmp(item_Input, "shoes") == 0) 
            {
                printf("Enter the quantity of %s needed: ", item_Input);
                scanf("%d", &quantity);
                shoeQuantity = quantity;
                printf("Clothing item '%s' successfully added to your cart.\n", item_Input);
            }
            else
            {
                printf("Invalid item. Please enter 'shirt', 'shoes', or 'pants'.\n");
            }
            break;
        case 'p':
            if (strcasecmp(item_Input, "pants") == 0) 
            {
                printf("Enter the quantity of %s needed: ", item_Input);
                scanf("%d", &quantity);
                pantsQuantity = quantity;
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
    printf("\nEnter the shipping destination (USA, Mexico, Canada): ");
    scanf("%s", country_Input);
    // for(int i = 0; country_Input[i]; i++) country_Input[i] = tolower(country_Input[i]);  // Convert to lowercase

    printf("Enter the shipping method (standard, expedited): ");
    scanf("%s", shipping_Input);

    if (strcasecmp(country_Input, "usa") == 0)
    {
        taxrate = USA_tax;
        if (strcasecmp(shipping_Input, "standard") == 0)
        {
            shippingcost = USA_standard;
        }
        else if (strcasecmp(shipping_Input, "expedited") == 0)
        {
            shippingcost = USA_expedited;
        }
    }
    else if (strcasecmp(country_Input, "mexico") == 0)
    {
        taxrate = MEX_tax;
        if (strcasecmp(shipping_Input, "standard") == 0)
        {
            shippingcost = MEX_standard;
        }
        else if (strcasecmp(shipping_Input, "expedited") == 0)
        {
            shippingcost = MEX_expedited;
        }
    }
    else if (strcasecmp(country_Input, "canada") == 0)
    {
        taxrate = CAN_tax;
        if (strcasecmp(shipping_Input, "standard") == 0)
        {
            shippingcost = CAN_standard;
        }
        else if (strcasecmp(shipping_Input, "expedited") == 0)
        {
            shippingcost = CAN_expedited;
        }
    }
    else 
    {
        strcpy(country_Input, default_country);
        strcpy(shipping_Input, default_shipping);
        shippingcost = USA_standard;
        taxrate = USA_tax;
        printf("Invalid shipping destination. Defaulting to USA standard shipping.\n");
    }

        if (shipping_Input[0] != '\0') 
    {
        shipping_Input[0] = toupper(shipping_Input[0]);
        if (country_Input[0] != '\0') 
        {
        country_Input[0] = toupper(country_Input[0]);
        }
    }

    
    int tax_actual = taxrate * 100;

    //Calculate tax amount
    taxamount = totalcost * taxrate;

    //Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", totalcost);
    printf("Shipping Destination: %s\n", country_Input);
    printf("Shipping Method: %s to %s\n", shipping_Input, country_Input);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", shippingcost);
    printf("Tax (%d.00%%):\t\t\t\t\t$%.2f\n", tax_actual, taxamount);
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t$%.2f\n", totalcost + shippingcost + taxamount);

    return 0;
}