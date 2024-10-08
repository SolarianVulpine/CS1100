int count;
count = 1;

while (count <= 100)
{
        if (count % 15 == 0)
        {
                Console.WriteLine("FizzBuzz");
        }
        else if (count % 5 == 0)
        {
                Console.WriteLine("Buzz");
        }
        else if (count % 3 == 0)
        {
                Console.WriteLine("Fizz");
        }
        else
        {
                Console.WriteLine(count);
        }
        count++;
}