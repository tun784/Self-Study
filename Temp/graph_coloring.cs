using System;
using System.Collections.Generic;
using System.Linq;

namespace GC
{
    public class GraphColoring
    {
        private Dictionary<string, List<string>> graph;

        public GraphColoring(Dictionary<string, List<string>> graph)
        {
            this.graph = graph;
        }

        public Dictionary<string, int> ColorGraph()
        {
            Dictionary<string, int> colors = new Dictionary<string, int>();

            foreach (string vertex in graph.Keys)
            {
                colors[vertex] = -1; // Initialize to -1 (unassigned)
            }

            return ColorGraphRecursive(colors);
        }

        private Dictionary<string, int> ColorGraphRecursive(Dictionary<string, int> colors)
        {
            foreach (string vertex in graph.Keys)
            {
                if (colors[vertex] == -1)
                {
                    for (int color = 1; color <= graph.Keys.Count; color++)
                    {
                        if (IsSafe(vertex, color, colors))
                        {
                            colors[vertex] = color;

                            if (ColorGraphRecursive(colors) != null)
                            {
                                return colors;
                            }

                            colors[vertex] = -1; // Backtrack
                        }
                    }

                    return null; // No valid color found
                }
            }

            return colors;
        }

        private bool IsSafe(string vertex, int color, Dictionary<string, int> colors)
        {
            foreach (string adjacentVertex in graph[vertex])
            {
                if (colors[adjacentVertex] == color)
                {
                    return false;
                }
            }

            return true;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            // Create the graph based on the provided map
            Dictionary<string, List<string>> graph = new Dictionary<string, List<string>>()
            {
                {"Lisbon", new List<string> { "Madrid", "Paris" }},
                {"Madrid", new List<string> { "Lisbon", "Paris" }},
                {"Paris", new List<string> { "Lisbon", "Madrid", "Brussels", "Luxembourg", "The Hague", "Rome", "Berne" }},
                {"Brussels", new List<string> { "Paris", "Luxembourg", "The Hague", "Berne" }},
                {"Luxembourg", new List<string> { "Paris", "Brussels", "The Hague", "Berne" }},
                {"The Hague", new List<string> { "Paris", "Brussels", "Luxembourg", "Berne" }},
                {"Rome", new List<string> { "Paris", "Berne", "Vienna" }},
                {"Berne", new List<string> { "Paris", "Brussels", "Luxembourg", "The Hague", "Rome", "Vienna", "Berlin" }},
                {"Vienna", new List<string> { "Rome", "Berne", "Berlin" }},
                {"Berlin", new List<string> { "Berne", "Vienna" }}
            };
            GraphColoring graphColoring = new GraphColoring(graph);
            Dictionary<string, int> colors = graphColoring.ColorGraph();

            if (colors != null)
            {
                Console.WriteLine("Graph coloring successful:");
                foreach (var vertexColor in colors)
                {
                    Console.WriteLine($"{vertexColor.Key}: {vertexColor.Value}");
                }
            }
            else
            {
                Console.WriteLine("Graph coloring failed.");
            }
        }
    }
}