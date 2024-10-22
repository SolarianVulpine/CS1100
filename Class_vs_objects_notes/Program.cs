

using System.Runtime.CompilerServices;

/** Conventionally Fields are at the top followed by methods.
* Public, Private, Protected, Internal - access modifier - determines what level access we have on a function
* Essentially sets where a function is allowed to be called
*/
class Create
{
        //         string color = "red"; // Field
        //         int speed = 200; // Field
        string color;
        int speed;
        string brand;
        string model;

        public Car() // Constructor{}
        {
                String model = "Mustang";
        }
        public void fullThrottle(String brand) // Method
        {
                this.brand = brand; // Accesses the passed brand to override the field brand 
                if (speed == 200)
                {
                        Console.WriteLine("The car is going as fast as it can!");
                }
        }

        static void Main(string[] args)
        {
                Car myObj = new Car();
                Car bmw = new Car();
                bmw.color = "blue";
                myObj.color = "purple";
                Console.WriteLine(myObj.color);
                Console.WriteLine(bmw.color);
        }
}