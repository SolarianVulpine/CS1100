// Establishes Random value based on default random seed
Random rand = new Random();

// Declares an array to hold the dice rolls
int[] diceRolls = new int[5];

// Assigns a random value 1-6 for five dice
int diceOne = rand.Next(1, 6);
int diceTwo = rand.Next(1, 6);
int diceThree = rand.Next(1, 6);
int diceFour = rand.Next(1, 6);
int diceFive = rand.Next(1, 6);

// Assigns index locations to the random dice rolls
diceRolls[0] = diceOne;
diceRolls[1] = diceTwo;
diceRolls[2] = diceThree;
diceRolls[3] = diceFour;
diceRolls[4] = diceFive;

// // Prints the rolls and the index placement
// for(int i = 0; i < 5; i++)
// {
//         Console.WriteLine($"i = {i}\t random roll was {diceRolls[i]}");
// }

Console.WriteLine("Initial Roll: ");
int index = 1;
foreach (int Roll in diceRolls)
{
        Console.Write($"Die {index}: ");
        Console.WriteLine(Roll);
        index++;
}


// Declare variable to count roll attempts
// int numRolls = 1;

// while (numRolls < 3)
// {
//         if (numRolls == 1)
//         {
//                 Console.WriteLine("Initial Roll: ");
//                 int index = 1;
//                 foreach (int Roll in diceRolls)
//                 {
//                         Console.Write($"{index}: ");
//                         Console.WriteLine(Roll);
//                         index++;
//                 }
//         }
//         else
//         {
//                 Console.WriteLine("Updated Rolls: ");
//         }
// }