using System;
using System.Collections.Generic;
using System.Net.Http.Headers;
using System.Security.Cryptography;
using System.Xml.XPath;
using firstCsharp;

// SeungHun Yim
// 101325908

namespace firstCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int qualified = 0, unqualified = 0;
            double max = 0, best_contestant = 0;
            
            // input
            while (true)
            {
                int competitor_num = 0;
                float[] scores = new float[3];
                double total = 0, average = 0, standard = 1.5;
                string qualify_or_not;
                
                Console.Write("Please enter a competitor number (0 to quit): ");
                competitor_num = int.Parse(Console.ReadLine());
                if (competitor_num == 0) break;

                Console.Write("Please enter 3 jump heights: ");
                string[] tokens = Console.ReadLine().Split();
                for (int i = 0; i < 3; ++i)
                {
                    scores[i] = float.Parse(tokens[i]);
                    // Processing
                    total += scores[i];
                }

                // Processing
                average = Math.Round((total / 3), 2);
                // getting the highest average and the best contestant
                if (max < average)
                {
                    max = average;
                    best_contestant = competitor_num;
                }
                // defining qualifying or not
                if (average >= standard)
                {
                    qualify_or_not = "qualify";
                    qualified++;
                }
                else
                {
                    qualify_or_not = "does not qualify";
                    unqualified++;
                }
                // Output
                Console.WriteLine(competitor_num + "\t\t" + average + "\t\t" + qualify_or_not);
            }
            Console.WriteLine("\n");
            // Output
            Console.WriteLine(qualified + " jumpers qualified");
            Console.WriteLine(unqualified + " jumpers did not qualify");
            Console.WriteLine("The highest jumper was " + best_contestant + "with an average height of " + max + " metres.");
        }
    }
}