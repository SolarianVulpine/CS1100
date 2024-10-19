// Establishes Random value based on default random seed
Random rand = new Random();

// Declares an array to hold the dice rolls
int[] diceRolls = new int[5];

// Assigns a random value 1-6 for five dice
// int diceOne = rand.Next(1, 6);
// int diceTwo = rand.Next(1, 6);
// int diceThree = rand.Next(1, 6);
// int diceFour = rand.Next(1, 6);
// int diceFive = rand.Next(1, 6);

// Assigns index locations to the random dice rolls
// diceRolls[0] = diceOne;
// diceRolls[1] = diceTwo;
// diceRolls[2] = diceThree;
// diceRolls[3] = diceFour;
// diceRolls[4] = diceFive;



// // Prints the rolls and the index placement
// for(int i = 0; i < 5; i++)
// {
//         Console.WriteLine($"i = {i}\t random roll was {diceRolls[i]}");
// }




// Declare variable to count roll attempts
int numRolls = 1;
int rollAttempts = 2;

// While loop should keep the program running until user has reached maximum roll attempts
while (numRolls < 4)
{
        // on the first roll should print Initial instead of Updated
        if (numRolls == 1)
        {
                Console.WriteLine("Initial Roll: ");
                int index = 1;
                for (int i = 0; i < diceRolls.Length; i++)
                {
                        diceRolls[i] = rand.Next(1, 6);
                        Console.Write($"Die {index}: ");
                        Console.WriteLine(diceRolls[i]);
                        index++;
                }
                numRolls++;
                // Console.WriteLine("Enter the dice numbers to reroll (comma-separated, ex: 2,3,5) or leave blank to keep current dice.");
        }
        else
        {
                // prompts user for whether they want to reroll or hold dice results
                Console.WriteLine("Enter the dice numbers to reroll (comma-separated, ex: 2,3,5) or leave blank to keep current dice.");
                string reroll_Input = Console.ReadLine();

                // checks if input is null, empty, or contains value
                switch (reroll_Input)
                {
                        case null:
                                Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                                rollAttempts--;

                                numRolls++;
                                break;
                        case "":
                                Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                                rollAttempts--;

                                numRolls++;
                                break;
                        case string s when !string.IsNullOrEmpty(s):
                                if (reroll_Input.Length > 1)
                                {
                                        string[] parsed_dice = reroll_Input.Split(','); // Splits string into array of values when a comma occurs
                                        int[] dice_to_reroll = new int[parsed_dice.Length]; // Stores CSVs into new array

                                        for (int i = 0; i < parsed_dice.Length; i++) // typecasts CSVs into ints
                                        {
                                                dice_to_reroll[i] = int.Parse(parsed_dice[i]);
                                                // Console.WriteLine(dice_to_reroll[i]);
                                        }

                                        int j = 1;
                                        int k = 0;

                                        Console.WriteLine("Updated Rolls: "); // Should print the updated set of values
                                        int index = 1;

                                        for (k = 0; k < diceRolls.Length; k++)
                                        {
                                                if (diceRolls[k] == dice_to_reroll[j])
                                                {
                                                        diceRolls[k] = rand.Next(1, 6);
                                                        Console.Write($"Die {index}: ");
                                                        Console.WriteLine(diceRolls[k]);
                                                        index++;
                                                        j++;
                                                }
                                                else
                                                {
                                                        Console.Write($"Die {index}: ");
                                                        Console.WriteLine(diceRolls[k]);
                                                        index++;
                                                }
                                                k++;
                                        }

                                        Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                                        rollAttempts--;

                                        numRolls++;
                                }
                                else if (reroll_Input.Length == 1)
                                {
                                        int input = int.Parse(reroll_Input);
                                        Console.WriteLine("Updated Rolls: "); // Should print the updated set of values
                                        int index = 1;
                                        int k = 0;

                                        for (k = 0; k <= diceRolls.Length; k++)
                                        {
                                               if (diceRolls[k] != (input - 1))
                                                {
                                                        Console.Write($"Die {index}: ");
                                                        Console.WriteLine(diceRolls[k]);
                                                        index++;
                                                }
                                                 if (diceRolls[k] == (input - 1))
                                                {
                                                        diceRolls[k] = rand.Next(1, 6);
                                                        Console.Write($"Die {index}: ");
                                                        Console.WriteLine(diceRolls[k]);
                                                        index++;
                                                }
                                                k++;
                                        }

                                        Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                                        rollAttempts--;

                                        numRolls++;
                                }
                                break;
                        default:
                                break;


                }
                // Console.WriteLine("made it!\nbreaking out of loop");
                // break;
        }
}

// Console.WriteLine("\nmade it here!");
//Console.WriteLine("Breaking~");
//break;