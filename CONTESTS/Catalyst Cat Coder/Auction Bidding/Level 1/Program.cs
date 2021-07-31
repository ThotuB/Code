using System;
using System.IO;
using System.Collections.Generic;

namespace Level_1
{
    class Data {
        public string bidder;
        public uint bid;
        public uint currentPrice;
        public string highestBidder;

        public Data(string bidder, uint bid, uint currentPrice, string highestBidder) {
            this.bidder = bidder;
            this.bid = bid;
            this.currentPrice = currentPrice;
            this.highestBidder = highestBidder;
        }

        public override string ToString() {
            return bidder + "\t" + bid + "\t" + currentPrice + "\t" + highestBidder;
        }
    }

    class Log {
        public int size = 0;
        public List<Data> data = new List<Data>();

        public Log() {
        }

        public void Add(Data data) {
            this.size++;
            this.data.Add(data);
        }

        public override string ToString() {
            string result = "";
            foreach (Data d in data) {
                result += d.ToString() + "\n";
            }
            return result;
        }
    }

    class Program
    {
        public static string PATH = "level1-";
        public static uint START = 5;
        public static uint COUNT = 1;

        static void Main(string[] args){
            for (uint cnt = START ; cnt < START + COUNT ; cnt++) {
                using FileStream fsIn = File.OpenRead("Input/" + PATH + cnt + ".in");
                using FileStream fsOut = File.Create("Output/" + PATH + cnt + ".out");

                StreamWriter swOut = new StreamWriter(fsOut);

                string text = new StreamReader(fsIn).ReadToEnd();
                string[] words = text.Split(',');

                uint initialPrice = uint.Parse(words[0]);

                uint currentPrice = initialPrice;
                string highestBidder = "";

                Log log = new Log();
                Data data = new Data("Start", initialPrice, currentPrice, "-");
                log.Add(data);

                for (uint i = 1 ; i < words.Length ; i+=2) {
                    string name = words[i];
                    uint bid = uint.Parse(words[i+1]);

                    if ( bid > currentPrice ) {
                        highestBidder = name;
                        currentPrice = bid + initialPrice;
                    }

                    data = new Data(name, bid, currentPrice, highestBidder);
                    log.Add(data);
                }

                Console.WriteLine(log);
                Console.WriteLine(log.data[log.size-1].highestBidder + "," + (log.data[log.size-1].currentPrice-initialPrice));
            }
        }
    }
}
