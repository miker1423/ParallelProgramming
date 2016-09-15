using System;
using System.Diagnostics;
using System.Threading.Tasks;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch stp = new Stopwatch();
            Random rnd = new Random();
            int m = 15000, n = 2;
            int[,] a = new int[m, n];
            int[,] b = new int[m, n];

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    a[i, j] = rnd.Next();
                    b[i, j] = rnd.Next();
                }
            }


            Console.WriteLine("Matrix Multiplication is :");
            int[,] c = new int[m, n];
            stp.Start();
            Parallel.For(0, m, i =>
            {
                Parallel.For(0, n, j =>
                {
                    for (int k = 0; k < 2; k++)
                    {
                        c[i, j] += a[i, k] * b[k, j];
                    }
                });
            });
            stp.Stop();

            //for (int i = 0; i < m; i++)
            //{
            //    for (int j = 0; j < n; j++)
            //    {
            //        Console.Write(c[i, j] + "\t");
            //    }
            //    Console.WriteLine();
            //}

            Console.WriteLine(stp.ElapsedMilliseconds);

            Console.ReadKey();
        }
    }
}
