using System.Globalization;
using System.Security.Cryptography.X509Certificates;

/*
This is Torin's Character Battle simulator. Their partner was Cin/Thawn.
New submits may occur as Torin continues to nitpick and refine the program.
Torin - I'd like to alter the attack vs defend to act more like a rock/paper/scissors type combat
where the choice to atk or def would be up agaianst the other character's own decision to atk or def
*/

// allows for random value generation
Random rand = new Random();

// Runs the Battle program - The is the program's "main" function
battle();

void battle()
{
    Console.Clear(); // Clears console at runtime

    Console.Write("\nWelcome Hero, what is your name: "); // Prompt user for the Hero's name
    string heroName = Console.ReadLine();

    Console.WriteLine($"\nWelcome {heroName}!"); // Greets Hero by new name

    int heroAtk = rand.Next(15, 30); // random value to determine how strong your weapon is
    // int heroDef = rand.Next(3, 5); // Unused Player defense modifier
    if (heroAtk > 25)
    {
        Console.WriteLine("You've found a mystical sword. It's Rare and very strong!");
    }
    else if (heroAtk > 20)
    {
        Console.WriteLine("You've found a mystical sword. It's Uncommon and very strong!");

    }
    else if (heroAtk >= 15)
    {
        Console.WriteLine("You've found a sword. You feel strong.");
    }

    // creates new objects based on the Player and Enemy classes
    Player Hero = new Player(heroAtk, 5, heroName);
    Enemy Bandit = new Enemy(15, 5, "Joe");

    // Alerts player to beginning of Battle
    Console.WriteLine($"{Hero.CharName} has encountered the dangerous Bandit {Bandit.CharName}!\nPrepare for Battle!");

    // Initializes HP to Default starting value before loop
    Hero.Current_Player_HP = Hero.StartingHP;
    Bandit.Current_Enemy_HP = Bandit.StartingHP;


    while (Hero.Current_Player_HP > 0 && Bandit.Current_Enemy_HP > 0) // Continues battle game while the characters are alive
    {
        int enemyAction = rand.Next(1, 3); // This variable decides what the enemy does by flipping a coin

        // int playerCrit = rand.Next(1, 11); // This variable is an unused crit attack (scrapped for time, may be added later)


        Console.Write("\nWill you Attack or Defend: "); // Prompts user for action
        string playerInput = Console.ReadLine();
        string playerAction = playerInput.ToLower(); // allows input to be case agnostic

        switch (playerAction) // calls different methods based on both user chosen action
        {
            case "attack":

                Console.Clear(); // Empties screen before printing actions and results

                Bandit.Current_Enemy_HP = Hero.Attack(Bandit); // In the case that player attacks, bandit's HP is acted on by Hero attack

                if (enemyAction == 1)
                {
                    Hero.Current_Player_HP = Bandit.Attack(Hero); // In the case that enemy attacks, Hero's HP is acted on by Bandit's attack
                }
                else
                {
                    Bandit.Current_Enemy_HP = Bandit.Defend(Hero); // In the case that Bandit Defends, bandit's HP is acted on by Hero attack
                }
                break;
            case "defend":
                Console.Clear();

                Hero.Current_Player_HP = Hero.Defend(Bandit); // In the case that player defends, Hero's HP is acted on by Bandit's attack

                if (enemyAction == 1)
                {
                    Hero.Current_Player_HP = Bandit.Attack(Hero); // In the case that Bandit attacks, Hero's HP is acted on by Bandit attack
                }
                else
                {
                    Bandit.Current_Enemy_HP = Bandit.Defend(Hero); // In the case that Bandit defends, bandit's HP is acted on by Hero attack
                }
                break;
            default:
                Console.WriteLine("\nI don't understand that command.");
                break;
        }
        if (Hero.Current_Player_HP <= 0)
        {
            Hero.DeathMessage();
            break;
        }
        else if (Bandit.Current_Enemy_HP <= 0)
        {
            Bandit.DeathMessage();
            break;
        }

    }
}


public class Player // This creates a class called Player that holds the Player's abilities and stats
{
    public int Current_Player_HP { get; set; }
    public int StartingHP { get; set; }
    public int Atk { get; set; }
    public int Def { get; set; }
    public string CharName { get; set; }

    public Player(int atk, int def, string charName) // This is a constructor for the Player class
    {
        Atk = atk;
        Def = def;
        CharName = charName;
        StartingHP = 100;

    }

    public int Attack(Enemy enemy) // This is a method for the Player's attack action
    {

        int damageValue = Atk - enemy.Def;
        int newHP = enemy.Current_Enemy_HP - damageValue;

        Console.WriteLine($"\n{CharName} attacks!\nThey hit {enemy.CharName} for {damageValue} points of damage!");
        if (newHP > 0)
        {
            Console.WriteLine($"{enemy.CharName} now has {newHP} Health Points.");
        }
        else
        {
            Console.WriteLine($"{enemy.CharName} is fading fast!");
        }

        return newHP;
    }

    public int Defend(Enemy enemy) // This is a method for the Player's defense action
    {
        int damageValue = enemy.Atk - (Def + 5);
        int newHP = Current_Player_HP - damageValue;

        Console.WriteLine($"\n{CharName} defends!\nThe {enemy.CharName} has hit {CharName} for {damageValue} points of damage!");
        if (newHP > 0)
        {
            Console.WriteLine($"{CharName} now has {newHP} Health Points.");
        }
        else
        {
            Console.WriteLine($"{CharName} is fading fast!");
        }


        return newHP;
    }

    public void DeathMessage() // Prints character death message
    {
        Console.WriteLine($"\n{CharName} has perished in combat.");
    }


}

public class Enemy // This creates a class called Player that holds the Enemy's abilities and stats
{
    public int Current_Enemy_HP { get; set; }
    public int StartingHP { get; set; }
    public int Atk { get; set; }
    public int Def { get; set; }
    public string CharName { get; set; }

    public Enemy(int atk, int def, string charName) // This is a constructor for the Enemy class
    {
        Atk = atk;
        Def = def;
        CharName = charName;
        StartingHP = 100;

    }

    public int Attack(Player player) // This is a method for the Enemy's attack action
    {
        int damageValue = Atk - player.Def;
        int newHP = player.Current_Player_HP - damageValue;

        Console.WriteLine($"\n{CharName} attacks!\nThey hit {player.CharName} for {damageValue} points of damage!");
        if (newHP > 0)
        {
            Console.WriteLine($"{player.CharName} now has {newHP} Health Points.");
        }
        else
        {
            Console.WriteLine($"{player.CharName} is fading fast!");
        }

        return newHP;
    }
    public int Defend(Player player) // This is a method for the Enemy's defend action
    {
        int damageValue = player.Atk - (Def + 5);
        int newHP = Current_Enemy_HP - damageValue;

        Console.WriteLine($"\n{CharName} defends!\n{player.CharName} has hit {CharName} for {damageValue} points of damage!");
        if (newHP > 0)
        {
            Console.WriteLine($"{CharName} now has {newHP} Health Points.");
        }
        else
        {
            Console.WriteLine($"{CharName} is fading fast!");
        }

        return newHP;
    }

    public void DeathMessage() // Prints character death message
    {
        Console.WriteLine($"\n{CharName} has perished in combat.");
    }

}
