using System;
using System.Collections.Generic;

namespace Algorithms.StringMatching {
    public class KMP {
        public static Dictionary<string, int> BuildDisplacement(string text) {
            var displacement = new Dictionary<string, int>();
            
            for (int i = 0; i < text.Length; i++) {
                string match = text.Substring(0, i);
                char charAfterMatch = text[i];

                int displacementValue = match.Length + 1;

                for (int j = i; j >= 0; j--) {
                    string prefix = match.Substring(0, j);
                    string suffix = match.Substring(match.Length - j);

                    if ( prefix == suffix ) {
                        char charAfterPrefix = text[j];

                        if ( charAfterPrefix != charAfterMatch ) {
                            displacementValue = match.Length - j;
                            break;
                        }
                    }
                }

                displacement[match] = displacementValue;
            }

            return displacement;
        }

        public static List<int> Search(string text, string pattern) {
            var indicies = new List<int>();

            int tlen = text.Length;
            int plen = pattern.Length;

            Dictionary<string, int> displacement = BuildDisplacement(pattern);

            PrintDisplacement(displacement);

            for (int i = 0; i <= tlen - plen; ) {
                int index = -1;
                for (int j = 0; j < plen; j++) {
                    if ( text[i + j] != pattern[j] ) {
                        index = j;
                        break;
                    }
                }

                if ( index == -1 ) {
                    indicies.Add(i);
                    i++;
                    continue;
                }
                i += displacement[pattern.Substring(0, index)];
            }

            PrintInidices(indicies);

            return indicies;
        }

        /// Helper Functions
        // Print Displacements
        public static void PrintDisplacement(Dictionary<string, int> displacement) {
            Console.WriteLine("Displacements:");
            foreach (var item in displacement) {
                Console.WriteLine($" {item.Key} : {item.Value}");
            }
        }

        // Print Indicies
        public static void PrintInidices(List<int> indicies) {
            Console.Write("Indicies: ");
            foreach (var item in indicies) {
                Console.Write(item + " ");
            }
        }
    }
}