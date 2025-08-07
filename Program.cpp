using System;
using System.Collections.Generic;

namespace KnapsackGA
{
    class Program
    {
        static void Main(string[] args)
        {
            var items = new List<Item>
            {
                new Item { Weight = 10, Value = 60 },
                new Item { Weight = 20, Value = 100 },
                new Item { Weight = 30, Value = 120 },
                new Item { Weight = 25, Value = 75 },
                new Item { Weight = 15, Value = 40 }
            };

            int capacity = 50;

            var ga = new GeneticKnapsack(items, capacity);
            var best = ga.Run();

            Console.WriteLine("Best solution found:");
            for (int i = 0; i < items.Count; i++)
            {
                if (best.Chromosome[i])
                    Console.WriteLine($"- Item {i + 1}: Weight = {items[i].Weight}, Value = {items[i].Value}");
            }

            Console.WriteLine($"Total Value = {best.Fitness}");
        }
    }
}
