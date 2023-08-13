using System;

namespace MyApp // Note: actual namespace depends on the project name.
{
    class MyProgram
    {
        static void Main(string[] args)
        {
            const double PI = 3.14;

            int soluong = 3214;
            double ketqua = soluong * PI;

            double diemso = 8.5;
            int sobichia = 7;
            int sochia = 2;
            double diemtrungbinh = diemso / sochia;
            double thuong = (double)sobichia / sochia;
            string name = "Tuan";
            string nation = "Vietnam";
            var number = 113;
            var series = "31/12/2023";
            var date = new DateTime(2023, 12, 31);

            Console.Write("Enter any number: ");
            number = int.Parse(Console.ReadLine());
            Console.WriteLine("number= {0}", number);
            Console.WriteLine($"Ket qua = {soluong} x {PI} = {ketqua}");
            Console.WriteLine("Thuong = {0}/{1} = {2} ", sobichia, sochia, thuong);
            Console.WriteLine($"Diem so = {diemso}, diem trung binh = {diemtrungbinh}");
            Console.WriteLine($"Ten cua toi la {name} va toi den tu {nation}");
            Console.WriteLine("String: '{0}' and data: {1}", series, date);
            //Console.ReadLine();
        }
    }
}