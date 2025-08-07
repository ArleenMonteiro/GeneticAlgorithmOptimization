# Genetic Algorithm Optimization Engine for the Knapsack Problem

This project implements a **Genetic Algorithm (GA)** to solve the classic **0/1 Knapsack Problem** — an NP-hard problem in combinatorial optimization. The engine evolves a population of candidate solutions using principles of natural selection, with the goal of maximizing total item value while staying within a weight limit.

---

## Problem Description

In the **0/1 Knapsack Problem**, given:
- A set of `n` items, each with a weight `w` and value `v`
- A knapsack with maximum weight capacity `W`

Find a combination of items to include in the knapsack such that:
- The **total weight** does not exceed `W`
- The **total value** is maximized

---

## Features

- Configurable **population size**, **mutation rate**, and **number of generations**
- Implements **selection**, **crossover**, **mutation**, and **elitism**
- Ensures all solutions stay within weight constraints
- Optional **visualization** of fitness over generations
- Simple and modular Python implementation

---

## How It Works

1. **Initialization**: Randomly generate a population of binary chromosomes representing item selections.
2. **Fitness Evaluation**: Compute the total value of selected items if the total weight is within the limit; otherwise, assign a low fitness.
3. **Selection**: Choose parents using tournament or roulette selection based on fitness.
4. **Crossover**: Combine pairs of parents to create offspring.
5. **Mutation**: Randomly flip bits in offspring to introduce variation.
6. **Elitism**: Carry the best individuals to the next generation unchanged.
7. **Repeat**: Iterate through generations to evolve better solutions.

---

## Configuration

Edit the parameters in `config.py` or main script:

```python
NUM_ITEMS = 50
MAX_WEIGHT = 50
POPULATION_SIZE = 100
NUM_GENERATIONS = 200
CROSSOVER_RATE = 0.8
MUTATION_RATE = 0.05
ELITISM_COUNT = 2
