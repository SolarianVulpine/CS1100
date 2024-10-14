// Prompt the user for price
using System.Globalization;

Console.Write("Enter the purchase price: ");

// Read user input
string purchaseTotal = Console.ReadLine();

// ask for tax rate
Console.Write("Enter the tax rate: ");

// Read user input
string taxRate = Console.ReadLine();

// Convert input to an int
decimal int_Purchase = decimal.Parse(purchaseTotal);

decimal int_Tax = decimal.Parse(taxRate);

// Perform math
decimal taxPercent = (int_Tax / 100);

decimal newTotal = int_Purchase + int_Purchase * taxPercent;

CultureInfo ci = new CultureInfo("en-US");
Thread.CurrentThread.CurrentCulture = ci;

Console.WriteLine($"For your {int_Purchase:C} purchase, a {taxRate}% tax is {int_Tax:C} for a total of {newTotal:C}.");