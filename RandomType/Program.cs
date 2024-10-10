Random rand = new Random();

int randomNumber = rand.Next();
Console.WriteLine(randomNumber);

randomNumber = rand.Next(1, 11);
Console.WriteLine(randomNumber);

if(randomNumber % 2 == 0)
{
        Console.WriteLine($"{randomNumber} is even.");
}
else
{
        Console.WriteLine($"{randomNumber} is odd.");
}