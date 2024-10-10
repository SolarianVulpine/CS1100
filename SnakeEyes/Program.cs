Random rand = new Random();

int randomNum_A = rand.Next(1, 6);
int randomNum_B = rand.Next(1, 6);
Console.WriteLine($"You Rolled {randomNum_A},{randomNum_B}");

int total_Roll = (randomNum_A+randomNum_B);
if(total_Roll == 2)
{
        Console.WriteLine("Snake Eyes!");
}
else if(total_Roll == 12)
{
        Console.WriteLine("Box Cars!");
}
else
{
        Console.WriteLine($"{total_Roll}");
}