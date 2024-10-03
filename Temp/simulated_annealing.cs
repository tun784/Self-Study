using System;
using System.Collections.Generic;

namespace SA
{
    class Program
    {
        static void Main(string[] args)
        {
            int numCities = 10;
            double[,] distances = GenerateRandomDistances(numCities);
            int[] bestRoute = SimulatedAnnealing(distances, numCities, 10000.0, 0.99, 1000);

            Console.WriteLine("Best route found:");
            foreach (var city in bestRoute)
            {
                Console.Write(city + " ");
            }
            Console.WriteLine();
        }
        static double[,] GenerateRandomDistances(int numCities)
        {
            Random rand = new Random();
            double[,] distances = new double[numCities, numCities];
            for (int i = 0; i < numCities; i++)
            {
                for (int j = 0; j < numCities; j++)
                {
                    if (i == j)
                        distances[i, j] = 0;
                    else
                        distances[i, j] = rand.Next(1, 100);
                }
            }
            return distances;
        }
        static int[] SimulatedAnnealing(double[,] distances, int numCities, double startTemp, double alpha, int maxIter)
        {
            Random rand = new Random();
            int[] currentRoute = GenerateInitialRoute(numCities);
            int[] bestRoute = (int[])currentRoute.Clone();
            double bestDistance = CalculateTotalDistance(bestRoute, distances);
            double currentTemp = startTemp;

            for (int iter = 0; iter < maxIter; iter++)
            {
                int[] newRoute = (int[])currentRoute.Clone();
                SwapCities(newRoute, rand.Next(numCities), rand.Next(numCities));
                double newDistance = CalculateTotalDistance(newRoute, distances);

                if (AcceptanceProbability(bestDistance, newDistance, currentTemp) > rand.NextDouble())
                {
                    currentRoute = newRoute;
                    bestDistance = newDistance;
                    bestRoute = (int[])currentRoute.Clone();
                }
                currentTemp *= alpha;
            }

            return bestRoute;
        }
        static int[] GenerateInitialRoute(int numCities)
        {
            int[] route = new int[numCities];
            for (int i = 0; i < numCities; i++)
            {
                route[i] = i;
            }
            return route;
        }
        static void SwapCities(int[] route, int i, int j)
        {
            int temp = route[i];
            route[i] = route[j];
            route[j] = temp;
        }

        static double CalculateTotalDistance(int[] route, double[,] distances)
        {
            double totalDistance = 0;
            for (int i = 0; i < route.Length - 1; i++)
            {
                totalDistance += distances[route[i], route[i + 1]];
            }
            totalDistance += distances[route[route.Length - 1], route[0]];
            return totalDistance;
        }

        static double AcceptanceProbability(double currentDistance, double newDistance, double temperature)
        {
            if (newDistance < currentDistance)
            {
                return 1.0;
            }
            return Math.Exp((currentDistance - newDistance) / temperature);
        }
    }
}
