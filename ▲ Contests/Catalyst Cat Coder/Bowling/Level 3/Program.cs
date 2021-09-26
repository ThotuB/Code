using System;
using System.IO;
using System.Collections.Generic;

namespace Level_1
{
    class Throw {
        public uint[] pins = new uint[2];
        public uint score;

        public Boolean isSpare = false;
        public Boolean isStrike = false;

        public Throw(uint pins1, uint pins2) {
            pins[0] = pins1;
            pins[1] = pins2;

            if (pins1 == 10) {
                isStrike = true;
            } else if (pins1 + pins2 == 10) {
                isSpare = true;
            }
        }
    }

    class BowlingGame {
        public uint score = 0;

        private uint rolls = 0;
        public Throw[] throws = new Throw[10];
        public uint[] scores = new uint[10];

        public BowlingGame() {
        }

        public void Add(Throw t) {
            throws[rolls++] = t;
        }

        public void CalculateScores(){
            for (int i = 0; i < rolls; i++) {
                if (throws[i].isStrike) {
                    scores[i] = 10 + throws[i + 1].pins[0] + throws[i + 1].pins[1];
                } 
                else if (throws[i].isSpare) {
                    scores[i] = 10 + throws[i + 1].pins[0];
                } 
                else {
                    scores[i] = throws[i].pins[0] + throws[i].pins[1];
                }
                if ( i != 0 ){
                    scores[i] += scores[i - 1];
                }
                throws[i].score = scores[i];
                score += scores[i];
            }
        }
    }

    class Program
    {
        public static string PATH = "level3-";
        public static uint START = 0;
        public static uint COUNT = 2;

        static void Main(string[] args){
            for (uint cnt = START ; cnt < START + COUNT ; cnt++) {
                using FileStream fsIn = File.OpenRead("Input/" + PATH + cnt + ".in");
                using FileStream fsOut = File.OpenWrite("Output/" + PATH + cnt + ".out");

                StreamWriter swOut = new StreamWriter(fsOut);

                string text = new StreamReader(fsIn).ReadToEnd();
                string[] words = text.Split(':', ',');

                uint throws = uint.Parse(words[0]);

                BowlingGame game = new BowlingGame();

                uint[] pins = new uint[20];
                for (uint i = 1; i < words.Length ; i++) {
                    pins[i - 1] = uint.Parse(words[i]);
                }
                for (uint i = 1 ; i < words.Length ; ) {
                    if ( pins[i-1] == 10 ) {
                        game.Add(new Throw(10, 0));
                        i++;
                    }
                    else {
                        game.Add(new Throw(pins[i-1], pins[i]));
                        i += 2;
                    }
                }

                game.CalculateScores();

                for (uint i = 0 ; i < throws ; i++) {
                    swOut.Write(game.scores[i] + ",");
                    Console.Write(game.scores[i] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
