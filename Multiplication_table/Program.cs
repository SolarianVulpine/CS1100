// prompt user
Console.Write("Enter starting value for rows: ");
string startRows_Input = Console.ReadLine();

Console.Write("Enter ending value for rows: ");
string endRows_Input = Console.ReadLine();

Console.Write("Enter starting value for columns: ");
string startColumns_Input = Console.ReadLine();

Console.Write("Enter ending value for columns: ");
string endColumns_Input = Console.ReadLine();

// parse value
int startRows = int.Parse(startRows_Input);
int endRows = int.Parse(endRows_Input);
int startColumns = int.Parse(startColumns_Input);
int endColumns = int.Parse(endColumns_Input);

// begin loops
for(int j = startColumns; j <= endColumns; j++)
{
        Console.Write($"\t{j}");
}

Console.WriteLine();

for(int j = startColumns; j <= endColumns; j++)
{
        Console.Write("==========");
}

Console.WriteLine();

for(int i = startRows; i <= endRows; i++)
{
        Console.Write($"{i}\t");
    for(int j = startColumns; j <= endColumns; j++)
    {
        Console.Write($"{j * i}\t");
    }
    Console.WriteLine();
}

// Console.WriteLine();

// for(int j = startColumns; j <= endColumns; j++)
// {
//         Console.Write("==========");
// }