// Prompt User
Console.Write("What type of shape (R)ectangle, (T)riangle, or (C)ircle?");
string Letter = Console.ReadLine();

// Convert to Uppercase to make program !case sensitive
string upperLetter = Letter.ToUpperInvariant();

switch(upperLetter)
{
        case "R":
        {       
        Console.Write("Enter the length: ");
        string R_length = Console.ReadLine();
        decimal Rlen = decimal.Parse(R_length);

        Console.Write("Enter the width: ");
        string R_width = Console.ReadLine();
        decimal Rwidth = decimal.Parse(R_width);

        decimal rectangle_Area = Rlen * Rwidth;

        Console.WriteLine($"The area of this rectangle is {rectangle_Area:N2}.");

        }
        break;
        case "T":
        {
        Console.Write("Enter the base: ");
        string T_base = Console.ReadLine();
        decimal tBase = decimal.Parse(T_base);

        Console.Write("Enter the height: ");
        string T_height = Console.ReadLine();
        decimal tHeight = decimal.Parse(T_height);

        decimal triangle_base_times_height = tBase * tHeight;

        decimal triangle_Area = triangle_base_times_height / 2;

        Console.WriteLine($"The area of this triangle is {triangle_Area:N2}.");
        }
        break;
        case "C":
        {
        Console.Write("Enter the radius: ");
        string radius = Console.ReadLine();
        decimal C_rad = decimal.Parse(radius);

        decimal rad_squared = C_rad * C_rad;

        decimal circle_area = (decimal)Math.PI * rad_squared;

        Console.WriteLine($"The area of this circle is {circle_area:N2}.");
        }
        break;
        default:
        {
        Console.WriteLine("Invalid shape type!");
        }
        break;
}