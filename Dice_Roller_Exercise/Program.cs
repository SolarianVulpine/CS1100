﻿// Establishes Random value based on default random seed
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
        // Console.WriteLine(numRolls);
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
                Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                string reroll_Input = Console.ReadLine();

                // checks if input is null, empty, or contains value
                switch (reroll_Input)
                {
                        case string s when !string.IsNullOrEmpty(s):
                                Console.WriteLine("Updated Rolls: ");
                                int indexer = 1;
                                for (int k = 0; k < diceRolls.Length; k++)
                                {
                                        bool shouldReroll = false;

                                        // Check if this die should be re-rolled
                                        if (reroll_Input == "")
                                        {
                                                // No re-roll requested, just print
                                        }
                                        else if (reroll_Input.Length == 1)
                                        {
                                                int inputDie = int.Parse(reroll_Input);
                                                shouldReroll = (k + 1 == inputDie); // Note: Dice are numbered 1-5, but array indices are 0-4
                                        }
                                        else
                                        {
                                                string[] parsed_dice = reroll_Input.Split(',');
                                                foreach (string dieStr in parsed_dice)
                                                {
                                                        int dieNum = int.Parse(dieStr);
                                                        if (dieNum == k + 1) // Again, adjusting for 1-based vs 0-based indexing
                                                        {
                                                                shouldReroll = true;
                                                                break;
                                                        }
                                                }
                                        }

                                        Console.Write($"Die {indexer}: ");
                                        if (shouldReroll)
                                        {
                                                diceRolls[k] = rand.Next(1, 6);
                                        }
                                        Console.WriteLine(diceRolls[k]);
                                        indexer++;
                                }
                                numRolls++;

                                rollAttempts--;
                                break;
                        case null:
                                Console.WriteLine("Updated Rolls: ");
                                int index = 1;
                                for (int i = 0; i < diceRolls.Length; i++)
                                {
                                        Console.Write($"Die {index}: ");
                                        Console.WriteLine(diceRolls[i]);
                                        index++;
                                }
                                numRolls++;
                                // Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                                rollAttempts--;
                                break;
                        case "":
                                Console.WriteLine("Updated Rolls: ");
                                index = 1;
                                for (int i = 0; i < diceRolls.Length; i++)
                                {
                                        Console.Write($"Die {index}: ");
                                        Console.WriteLine(diceRolls[i]);
                                        index++;
                                }
                                numRolls++;
                                // Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                                rollAttempts--;
                                break;

                        default:
                                Console.WriteLine("Invalid");
                                numRolls++;
                                // Console.WriteLine($"You have {rollAttempts} rerolls remaining):");
                                rollAttempts--;
                                break;


                }
                // Console.WriteLine("made it!\nbreaking out of loop");
                // break;
        }
}

// Console.WriteLine("\nmade it here!");
//Console.WriteLine("Breaking~");
//break;