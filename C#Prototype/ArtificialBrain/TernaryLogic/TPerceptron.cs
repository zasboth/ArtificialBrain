using System;
using System.Json;
using TernaryLogic.Manager;

namespace TernaryLogic
{
    public class TPerceptron : IRemember
    {
        private const double ACTIVATED_MULTIPLIER = 1.5;
        private const double TRESHOLD_VALUE = 2;

        double[] _weights;
        double[] _inputs;
        TBit lastResult;

        public TPerceptron(int inputNumber)
        {
            InputNumber = inputNumber;
            _weights = new double[InputNumber];
            Random rnd = new Random();
            for (int i = 0; i < _weights.Length; i++)
            {
                _weights[i] = rnd.NextDouble() - 0.5d;
            }
        }

        public double Bias { get; set; } = 0.0d;
        //public double Treshold { get; set; } = 0.2;
        public int InputNumber { get; private set; }
        public double LearnRate { get; set; } = 0.1d;

        public TBit Percept(double[] input)
        {
            if (input == null) throw new ArgumentNullException();
            if (input.Length != InputNumber) throw new ArgumentOutOfRangeException("Invalid array length");
            _inputs = input;

            double sum = Summarize();
            double activation = Activation(sum);
            TBit result = (sbyte)(activation * ACTIVATED_MULTIPLIER);
            lastResult = result;
            return result;
        }

        private double Summarize()
        {
            double sum = Bias;
            for (int i = 0; i < _weights.Length; i++)
            {
                sum += _weights[i] * _inputs[i];
            }
            return sum;
        }

        private double Activation(double x)
        {
            double result;
            //Tthe activation function range must be betveen -1..1
            //Sigmoid not approporiate
            //result = 1.0d /(1.0d + Math.Pow(Math.E, -x));
            //SoftSign 
            result = x / (1 + Math.Abs(x));
            //Console.WriteLine(result);
            return result;
        }

        public void Teach(TBit wouldBeGood)
        {
            if (wouldBeGood == lastResult) return;
            double expectedValue = TRESHOLD_VALUE * wouldBeGood.Value;
            double perceptionError = expectedValue - Summarize();
            perceptionError *= perceptionError;
            for (int i = 0; i < _weights.Length; i++)
            {
                _weights[i] -= (LearnRate * perceptionError * _weights[i] * _inputs[i]);
            }
        }

        public string Save()
        {
            JsonObject json = new JsonObject();
            JsonArray array = new JsonArray();
            for (int i = 0; i < _weights.Length; i++)
            {
                array.Add(_weights[i]);
            }
            json.Add("Bias", Bias);
            //json.Add("Treshold", Treshold);
            json.Add("LearnRate", LearnRate);
            json.Add("Weights", array);
            return json.ToString();
        }

        public void Load(string state)
        {
            JsonObject json = (JsonObject)JsonObject.Parse(state);
            Bias = json["Bias"];
            //Treshold = json["Treshold"];
            LearnRate = json["LearnRate"];
            JsonArray array = json["Weights"] as JsonArray;
            InputNumber = array.Count;
            _weights = new double[InputNumber];
            for (int i = 0; i < InputNumber; i++)
            {
                _weights[i] = array[i];
            }
        }
    }
}
