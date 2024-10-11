/*this in an incompatible type. Will not implicitly convert int to string*/
// int test = Console.ReadLine();

Console.Write("Enter an integer: ");
int num1 = int.Parse(Console.ReadLine());

Console.Write("Enter a decimal: ");
decimal num2 = decimal.Parse(Console.ReadLine());

Console.Write("Enter a boolean (true/false): ");
bool val = bool.Parse(Console.ReadLine());

Console.WriteLine("You entered " + num1 + ", " + num2 + ", and " + val);