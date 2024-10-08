int count = 1;

while (count <= 100)
{
        if(count % 15 = 0)
        {
                Console.Writeline("FizzBuzz\n");
        }
        else if(count % 5 = 0)
        {
                Console.Writeline("Buzz\n");
        }
        else if(count % 3 = 0)
        {
                Console.Writeline("Fizz\n");
        }
        else
        {
                Console.Writeline(count);
        }
        count++;
}