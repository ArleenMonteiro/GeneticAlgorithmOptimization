using System;

namespace KnapsackGA
{
    public class Individual
    {
        public bool[] Chromosome;
        public int Fitness;

        public Individual(int length)
        {
            Chromosome = new bool[length];
        }

        public Individual Clone()
        {
            var clone = new Individual(Chromosome.Length);
            Chromosome.CopyTo(clone.Chromosome, 0);
            clone.Fitness = Fitness;
            return clone;
        }
    }
}
