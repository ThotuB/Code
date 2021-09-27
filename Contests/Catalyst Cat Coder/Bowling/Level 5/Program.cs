using System;
using System.IO;
using System.Collections.Generic;

namespace Level_1
{
    class BowlingGame {
        public enum Outcome {Normal, Spare, Strike};
        public uint score = 0;

        private uint rollCnt = 0;
        public uint[] rolls = new uint[21];

        public uint outcomeCnt = 0;
        public Outcome[] outcomes = new Outcome[10];

        public uint scoresCnt = 0;
        public uint[] scores = new uint[10];

        public BowlingGame() {
        }

        public void Add(uint pins) {
            rolls[rollCnt] = pins;
            rollCnt++;
        }

        public void CalculateOutcomes() {
            for (int i = 0; i < rollCnt; ) {
                if (rolls[i] == 10) {
                    outcomes[outcomeCnt] = Outcome.Strike;
                    i++;
                }
                else if (rolls[i] + rolls[i+1] == 10) {
                    outcomes[outcomeCnt] = Outcome.Spare;
                    i += 2;
                }
                else {
                    outcomes[outcomeCnt] = Outcome.Normal;
                    i += 2;
                }
                outcomeCnt++;
            }
        }

        public void CalculateScores(){
            uint j = 0;
            for (int i = 0; i < rollCnt; ) {
                if (outcomes[j] == Outcome.Strike) {
                    scores[scoresCnt] = rolls[i] + rolls[i + 1] + rolls[i + 2];
                    i++;
                }
                else if (outcomes[j] == Outcome.Spare) {
                    scores[scoresCnt] = rolls[i] + rolls[i + 1] + rolls[i + 2];
                    i+=2;
                }
                else {
                    scores[scoresCnt] = rolls[i] + rolls[i + 1];
                    i+=2;
                }
                scoresCnt++;
                j++;
            }
        }

        public override string ToString() {
            string result = "Rolls: ";
            for (int i = 0; i < rollCnt; i++) {
                result += rolls[i] + " ";
            }
            result += "\nOutcomes: ";
            for (int i = 0; i < outcomeCnt; i++) {
                result += outcomes[i] + " ";
            }
            result += "\nScores: ";
            for (int i = 0; i < scoresCnt; i++) {
                result += scores[i] + " ";
            }
            result += "\nTotal Scores: ";
            uint sum = 0;
            for (int i = 0; i < scoresCnt; i++) {
                sum += scores[i];
                result += sum + " ";
            }
            return result;
        }
    }

    class Program
    {
        public static string PATH = "level5-";
        public static uint START = 0;
        public static uint COUNT = 3;

        static void Main(string[] args){
            for (uint cnt = START ; cnt < START + COUNT ; cnt++) {
                using FileStream fsIn = File.OpenRead("Input/" + PATH + cnt + ".in");
                
                string text = new StreamReader(fsIn).ReadToEnd();
                string[] words = text.Split(':', ',');

                uint throws = uint.Parse(words[0]);

                BowlingGame game = new BowlingGame();

                for (uint i = 1; i < words.Length ; i++) {
                    uint pins = uint.Parse(words[i]);
                    game.Add(pins);
                }

                game.CalculateOutcomes();
                game.CalculateScores();

                Console.WriteLine(game + "\n");
            }
        }
    }
}
