using System.Globalization;
using System.Security.Cryptography.X509Certificates;

Random rand = new Random();

battle();

void battle()
{
        int heroAtk = rand.Next(10, 25);
        int heroDef = rand.Next(3, 5);
        Console.Write("\nWelcome Hero, what is your name: ");
        string heroName = Console.ReadLine();

        Console.WriteLine($"Welcome {heroName}!");
        if (heroAtk > 20)
        {
                Console.WriteLine($"You've found a mystical sword. It's very strong!");
        }
        else if (heroAtk > 15)
        {
                Console.WriteLine($"You've found a mystical sword. It's very strong!");

        }


        Player Moira = new Player(20, 5, "Moira");
        Enemy Esper = new Enemy(15, 5, "Esper");

        Console.WriteLine($"{Moira.CharName} has encountered {Esper.CharName}!\nPrepare for Battle!");

        Moira.Current_Player_HP = Moira.StartingHP;
        Esper.Current_Enemy_HP = Esper.StartingHP;


        // int x = 0;
        while (Moira.Current_Player_HP > 0 && Esper.Current_Enemy_HP > 0)
        {
                int enemyAction = rand.Next(1, 3);
                Console.Write("\nWill Moira Attack or Defend: ");
                string playerInput = Console.ReadLine();
                string playerAction = playerInput.ToLower();

                switch (playerAction)
                {
                        case "attack":

                                Console.Clear();

                                Moira.Current_Player_HP = Moira.Attack(Esper);
                                // Console.WriteLine(Moira.Current_Player_HP);
                                // Console.WriteLine(Moira.Attack(Esper));

                                if (enemyAction == 1)
                                {
                                        Esper.Current_Enemy_HP = Esper.Attack(Moira);
                                        // Console.WriteLine(Esper.Current_Enemy_HP);
                                }
                                else
                                {
                                        Esper.Current_Enemy_HP = Esper.Defend(Moira);
                                }

                                break;
                        case "defend":
                                Console.Clear();

                                Moira.Current_Player_HP = Moira.Defend(Esper);

                                if (enemyAction == 1)
                                {
                                        Esper.Current_Enemy_HP = Esper.Attack(Moira);
                                        // Console.WriteLine(Esper.Current_Enemy_HP);
                                }
                                else
                                {
                                        Esper.Current_Enemy_HP = Esper.Defend(Moira);
                                }

                                break;
                }
                if (Moira.Current_Player_HP <= 0)
                {
                        Moira.DeathMessage();
                        break;
                }
                else if (Esper.Current_Enemy_HP <= 0)
                {
                        Esper.DeathMessage();
                        break;
                }

        }
}


public class Player
{
        public int Current_Player_HP { get; set; }
        public int StartingHP { get; set; }
        public int Atk { get; set; }
        public int Def { get; set; }
        public string CharName { get; set; }

        public Player(int atk, int def, string charName)
        {
                Atk = atk;
                Def = def;
                CharName = charName;
                StartingHP = 100;

        }

        public int Attack(Enemy enemy)
        {

                int damageValue = Atk - enemy.Def;
                int newHP = enemy.Current_Enemy_HP - damageValue;

                Console.WriteLine($"\n{CharName} attacks!\nThey hit {enemy.CharName} for {damageValue} points of damage!");
                Console.WriteLine($"{enemy.CharName} now has {newHP} Health Points.");


                return newHP;
        }

        public int Defend(Enemy enemy)
        {
                int damageValue = enemy.Atk - (Def + 5);
                int newHP = Current_Player_HP - damageValue;

                Console.WriteLine($"\n{CharName} defends!\n{enemy.CharName} has hit {CharName} for {damageValue} points of damage!");
                Console.WriteLine($"{CharName} now has {newHP} Health Points.");


                return newHP;
        }

        public void DeathMessage()
        {
                Console.WriteLine($"\n{CharName} has perished in combat.");
        }


}

public class Enemy
{
        public int Current_Enemy_HP { get; set; }
        public int StartingHP { get; set; }
        public int Atk { get; set; }
        public int Def { get; set; }
        public string CharName { get; set; }

        public Enemy(int atk, int def, string charName)
        {
                Atk = atk;
                Def = def;
                CharName = charName;
                StartingHP = 100;

        }

        public int Attack(Player player)
        {
                int damageValue = Atk - player.Def;
                int newHP = player.Current_Player_HP - damageValue;

                Console.WriteLine($"\n{CharName} attacks!\nThey hit {player.CharName} for {damageValue} points of damage!");
                Console.WriteLine($"{player.CharName} now has {newHP} Health Points.");

                return newHP;
        }
        public int Defend(Player player)
        {
                int damageValue = player.Atk - (Def + 5);
                int newHP = Current_Enemy_HP - damageValue;

                Console.WriteLine($"\n{CharName} defends!\n{player.CharName} has hit {CharName} for {damageValue} points of damage!");
                Console.WriteLine($"{CharName} now has {newHP} Health Points.");


                return newHP;
        }

        public void DeathMessage()
        {
                Console.WriteLine($"\n{CharName} has perished in combat.");
        }

}



