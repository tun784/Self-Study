using System;
// using System.Drawing;
// using System.Globalization;

namespace Yooo
{
    internal class program
    {
        static void Main(string[] args)
        {
            int year = 0;
            Console.Write("Please enter a year: ");
            //year = int.Parse(Console.ReadLine());
            if (int.TryParse(Console.ReadLine(), out year))
            {
                if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) //Chia hết cho 4 nhưng không chia hết cho 100 hoặc chia hết cho 400
                {
                    Console.WriteLine("{0} isn't a leap year.", year);
                }
                else
                {
                    Console.WriteLine("{0} is a leap year.", year);
                }
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a valid year.");
            }

            double point=0;
            Console.Write("Enter your point: ");
            //point = double.Parse(Console.ReadLine());
            //if (double.TryParse(Console.ReadLine(), NumberStyles.Any, CultureInfo.InvariantCulture, out point)
            if (double.TryParse(Console.ReadLine(), out point))
            {
                if (point >= 5)
                {
                    Console.WriteLine("Point: {0} ==> 'Pass the exam'.", point);
                }
                else
                {
                    Console.WriteLine("Point: {0} ==> 'Failed the exam'.", point);
                }
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a valid numeric value.");
            }
        }
    }
}