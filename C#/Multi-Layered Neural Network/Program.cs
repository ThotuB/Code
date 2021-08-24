using System;

namespace Multi_Layered_Neural_Network
{
    class Node {
        public float[] weights;
        public float bias;
        public float output;

        public Node(int numInputs) {
            weights = new float[numInputs];
            bias = 0;
        }

        public override string ToString() {
            string output = "Node [";
            for (int i = 0; i < weights.Length; i++) {
                output += String.Format("{0:0.00}", weights[i]) + " ";
            }
            output += "| " + String.Format("{0:0.00}", bias) + "]";
            
            return output;
        }
    }

    class Layer {
        public Node[] nodes;
        public int numNodes;

        public Layer(int numNodes, int numInputs) {
            this.numNodes = numNodes;
            nodes = new Node[numNodes];

            for (int i = 0; i < numNodes; i++) {
                nodes[i] = new Node(numInputs);
            }
        }

        public override string ToString() {
            string output = "";
            for (int i = 0; i < numNodes; i++) {
                output += nodes[i].ToString() + "\n";
            }
            return output;
        }
    }

    class NeuralNetwork {
        public float[] inputLayer;
        public Layer hiddenLayer;
        public Layer outputLayer;

        public NeuralNetwork(int numInputs, int numHidden, int numOutputs) {
            inputLayer = new float[numInputs];
            hiddenLayer = new Layer(numHidden, numInputs);
            outputLayer = new Layer(numOutputs, numHidden);
        }

        public override string ToString() {
            return "Input Layer:\n" + inputLayer.ToString() + "\n" +
                "Hidden Layer:\n" + hiddenLayer.ToString() + "\n" +
                "Output Layer:\n" + outputLayer.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            NeuralNetwork nn = new NeuralNetwork(25, 5, 2);

            Console.WriteLine(nn);
        }
    }
}
