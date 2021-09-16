using System;
using System.Collections.Generic;

namespace Algorithms.StringMatching {
    public class BoyerMoore {
        public static Dictionary<char, int> BuildDisplacement(string text) {
            Dictionary<char, int> displacement = new Dictionary<char, int>();
            for (int i = text.Length - 2; i >= 0 ; i--) {
                if (!displacement.ContainsKey(text[i])) {
                    displacement[text[i]] = text.Length - i - 1;
                }
            }
            return displacement;
        }

        public static List<int> Search(string text, string pattern) {
            var indicies = new List<int>();

            int tlen = text.Length;
            int plen = pattern.Length;

            Dictionary<char, int> displacement = BuildDisplacement(pattern);

            for (int i = 0; i <= tlen - plen; ) {
                string sub = text.Substring(i, plen);

                if (sub == pattern) {
                    indicies.Add(i);
                    i++;
                    continue;
                }

                if ( !displacement.ContainsKey(text[i + plen - 1]) ) {
                    i += plen;
                }
                else {
                    i += displacement[text[i + plen - 1]];
                }
            }

            PrintIndicies(indicies);

            return indicies;
        }

        /// Helper Functions
        // Print Displacements
        public static void PrintDisplacement(Dictionary<char, int> displacement) {
            Console.WriteLine("Displacements: ");
            foreach (var item in displacement) {
                Console.WriteLine($" {item.Key} : {item.Value}");
            }
        }

        // Print Indicies
        public static void PrintIndicies(List<int> indicies) {
            Console.Write("Indicies: ");
            foreach (var item in indicies) {
                Console.WriteLine(item + " ");
            }
        }
    }
}