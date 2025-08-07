using System;
using System.Collections.Generic;
using System.Linq;

namespace KnapsackGA
{
    public class GeneticKnapsack
    {
        private static Random rand = new Random();
        private List<Item> items;
        private int capacity;
        private int populationSize = 100;
        private int generations = 100;
        private double mutationRate = 0.05;

        public GeneticKnapsack(List<Item> items, int capacity)
        {
            this.items = items;
            this.capacity = capacity;
        }

        public Individual Run()
        {
            List<Individual> population = InitializePopulation();

            for (int gen = 0; gen < generations; gen++)
            {
                foreach (var individual in population)
                    EvaluateFitness(individual);

                List<Individual> newPopulation = new List<Individual>();

                var best = population.OrderByDescending(i => i.Fitness).First().Clone();
                newPopulation.Add(best);

                while (newPopulation.Count < populationSize)
                {
                    var parent1 = TournamentSelection(population);
                    var parent2 = TournamentSelection(population);
                    var child = Crossover(parent1, parent2);
                    Mutate(child);
                    EvaluateFitness(child);
                    newPopulation.Add(child);
                }

                population = newPopulation;
            }

            return population.OrderByDescending(i => i.Fitness).First();
        }

        private List<Individual> InitializePopulation()
        {
            var population = new List<Individual>();
            for (int i = 0; i < populationSize; i++)
            {
                var ind = new Individual(items.Count);
                for (int j = 0; j < items.Count; j++)
                    ind.Chromosome[j] = rand.NextDouble() < 0.5;
                population.Add(ind);
            }
            return population;
        }

        private void EvaluateFitness(Individual individual)
        {
            int totalWeight = 0, totalValue = 0;

            for (int i = 0; i < items.Count; i++)
            {
                if (individual.Chromosome[i])
                {
                    totalWeight += items[i].Weight;
                    totalValue += items[i].Value;
                }
            }

            individual.Fitness = (totalWeight <= capacity) ? totalValue : 0;
        }

        private Individual TournamentSelection(List<Individual> population)
        {
            int tournamentSize = 5;
            var selected = new List<Individual>();
            for (int i = 0; i < tournamentSize; i++)
                selected.Add(population[rand.Next(population.Count)]);

            return selected.OrderByDescending(i => i.Fitness).First().Clone();
        }

        private Individual Crossover(Individual p1, Individual p2)
        {
            var child = new Individual(p1.Chromosome.Length);
            int point = rand.Next(p1.Chromosome.Length);

            for (int i = 0; i < p
