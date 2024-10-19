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




// Declare variable to count roll attempts
int numRolls = 1;

while (numRolls < 4)
{
        if (numRolls == 1)
        {
                Console.WriteLine("Initial Roll: ");
                int index = 1;
                foreach (int Roll in diceRolls)
                {
                        Console.Write($"Die {index}: ");
                        Console.WriteLine(Roll);
                        index++;
                }
                numRolls++;
                // Console.WriteLine("Enter the dice numbers to reroll (comma-separated, ex: 2,3,5) or leave blank to keep current dice.");
        }
        else
        {
                Console.WriteLine("Enter the dice numbers to reroll (comma-separated, ex: 2,3,5) or leave blank to keep current dice.");
                string reroll_Input = Console.ReadLine();

                switch (reroll_Input)
                {
                        case null:
                                break;
                        case "":
                                break;
                        case string s when !string.IsNullOrEmpty(s):
                                string[] dice_to_reroll = reroll_Input.Split(',');
                                int index = 1;
                                foreach (string dice in dice_to_reroll)
                                {
                                        int index_dice_to_reroll = int.Parse(dice);
                                        Console.WriteLine(index_dice_to_reroll);
                                        
                                }

                                // foreach (int Roll in diceRolls)
                                // {
                                //         Console.Write($"Die {index}: ");
                                //         Console.WriteLine(Roll);
                                //         index++;
                                // }
                                break;
                                default:
                                break;


                }
                Console.WriteLine("made it here\nbreaking");
                break;
        }
}

// Console.WriteLine("\nmade it here!");
//Console.WriteLine("Breaking~");
//break;