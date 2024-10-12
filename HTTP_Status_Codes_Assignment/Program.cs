// Prompt user for input
Console.Write("Enter a Response Code: ");

// Read user input
string errorCode_Input = Console.ReadLine();

// Convert input to an int
int errorCode = int.Parse(errorCode_Input);

// Determine if code is valid, if valid then print resonse type
if (errorCode < 100 || errorCode > 599)
{
        Console.WriteLine(errorCode + " is not a valid Response.");
}
else if (errorCode >= 100 && errorCode <= 199)
{
        Console.WriteLine(errorCode + " is a Informational Response.");
}
else if (errorCode >= 200 && errorCode <= 299)
{
        Console.WriteLine(errorCode + " is a Successful Response.");
}
else if (errorCode >= 300 && errorCode <= 399)
{
        Console.WriteLine(errorCode + " is a Redirection Response.");
}
else if (errorCode >= 400 && errorCode <= 499)
{
        Console.WriteLine(errorCode + " is a Client Error Response.");
}
else if (errorCode >= 500 && errorCode <= 599)
{
        Console.WriteLine(errorCode + " is a Error Response.");
}