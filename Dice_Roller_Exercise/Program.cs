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

// While loop should keep the program running until user has reached maximum roll attempts
while (numRolls < 4)
{
        // on the first roll should print Initial instead of Updated
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
                // prompts user for whether they want to reroll or hold dice results
                Console.WriteLine("Enter the dice numbers to reroll (comma-separated, ex: 2,3,5) or leave blank to keep current dice.");
                string reroll_Input = Console.ReadLine();

                // checks if input is null, empty, or contains value
                switch (reroll_Input)
                {
                        case null:
                                break;
                        case "":
                                break;
                        case string s when !string.IsNullOrEmpty(s):
                                string[] parsed_dice = reroll_Input.Split(','); // Splits string into array of values when a comma occurs
                                int[] dice_to_reroll = new int[parsed_dice.Length]; // Stores CSVs into new array

                                for (int i = 0; i < parsed_dice.Length; i++) // typecasts CSVs into ints
                                {
                                        dice_to_reroll[i] = int.Parse(parsed_dice[i]);
                                        Console.WriteLine(dice_to_reroll[i]);
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
                Console.WriteLine("made it!\nbreaking out of loop");
                break;
        }
}

// Console.WriteLine("\nmade it here!");
//Console.WriteLine("Breaking~");
//break;