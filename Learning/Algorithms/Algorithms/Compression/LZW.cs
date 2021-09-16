using System;
using System.Collections.Generic;

namespace Algorithms.Compression {
    public static class LZW {
        const int CHAR_MAX = 256;
        
        public static List<int> Compress(string input) {
            var output = new List<int>();
            var dict = new Dictionary<string, int>();

            for (int i = 0; i < CHAR_MAX; i++) {
                dict[Convert.ToChar(i).ToString()] = i;
            }
            
            int index = CHAR_MAX;
            int inputIndex = 1;

            string c = "";
            string s = "" + input[0];
            while (inputIndex < input.Length) {
                c = "" + input[inputIndex];
                string sc = s + c;
                if ( dict.ContainsKey(sc) ) {
                    s = sc;
                }
                else {
                    output.Add(dict[s]);
                    dict[sc] = index++;
                    s = c;
                }
                inputIndex++;
            }
            output.Add(dict[s]);

            return output;
        }

        public static string Decompress(List<int> input) {
            string output = "";
            var dict = new Dictionary<int, string>();

            for (int i = 0; i < CHAR_MAX; i++) {
                dict[i] = "" + (char)i;
            }

            int index = CHAR_MAX;
            int inputIndex = 1;
            
            int curr = input[0];
            int prev = curr;

            output += dict[curr];

            while ( inputIndex < input.Count ) {
                curr = input[inputIndex];
                if ( dict.ContainsKey(curr) ) {
                    string s = dict[curr];
                    string prevs = dict[prev] + s[0];
                    dict[index++] = prevs;

                    output += s;
                }
                else {
                    string s = dict[prev] + dict[prev][0];
                    dict[index++] = s;

                    output += s;
                }
                prev = curr;
                inputIndex++;
            }

            return output;
        }
    }
}