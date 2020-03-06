using System.Collections.Generic;
using System.Linq;
using System.Json;
using System.Text.Json;
using TernaryLogic.Manager;
using System;

namespace TernaryLogic
{
    public class Pile : IRemember
    {
        struct Statistic
        {
            public int TrueCount { get; set; }
            //public int MaibyCount { get; set; }
            public int FalseCount { get; set; }

            public override string ToString()
            {
                return JsonSerializer.Serialize(this);
            }

            public static Statistic Parse(string s) => (Statistic)JsonSerializer.Deserialize(s, typeof(Statistic));

        }

        readonly Pebble _decider;
        Statistic[] _statistics;
        Pebble _question;
        TBit _lastResult;
        readonly Dictionary<Pebble, TBit> _memory = new Dictionary<Pebble, TBit>();

        public Pile(int inputLength)
        {
            InputLength = inputLength;
            _decider = new Pebble(InputLength);
            _statistics = new Statistic[InputLength];
        }

        public int InputLength { get; private set; }
        //public bool HasNewMemory { get; private set; } = false;

        public TBit Answer(Pebble question)
        {
            _question = question;
            if (_memory.ContainsKey(question))
            {
                _lastResult = _memory[_question];
            }
            else
            {
                _lastResult = _decider.Compare(question);
            }
            return _lastResult;
        }

        public void Feedback(TBit woudBeGood)
        {
            try
            {
                if (_question == null) return;
                if (TBit.MAIBY == woudBeGood) return;
                if (!_memory.ContainsKey(_question) && _lastResult == woudBeGood && TBit.TRUE == _lastResult)
                {
                    _memory.Add(_question, woudBeGood);
                }
                Pebble pebble;
                if (TBit.TRUE == woudBeGood) pebble = _question;
                else pebble = !_question;

                for (int i = 0; i < pebble.InputNumber; i++)
                {
                    if (TBit.TRUE == pebble[i]) _statistics[i].TrueCount++;
                    if (TBit.FALSE == pebble[i]) _statistics[i].FalseCount++;
                    _decider[i] = TBit.FALSE;
                    if (Math.Abs(_statistics[i].TrueCount - _statistics[i].FalseCount) <= (_statistics[i].FalseCount + _statistics[i].TrueCount) / 5)
                    {
                        _decider[i] = TBit.MAIBY;
                    }
                    else if (_statistics[i].TrueCount > _statistics[i].FalseCount)
                    {
                        _decider[i] = TBit.TRUE;
                    }
                }
            }
            finally
            {
                _question = null;
            }
        }

        public string Save()
        {
            JsonObject json = new JsonObject();
            JsonArray array = new JsonArray();
            json.Add("Decider", _decider.Save());
            foreach (var item in _statistics)
            {
                array.Add(item.ToString());
            }
            json.Add("Statistic", array);
            JsonArray memory = new JsonArray();
            foreach (var item in _memory)
            {
                memory.Add(new JsonObject(new KeyValuePair<string, JsonValue>(item.Key.ToString(), item.Value.ToString())));
            }
            json.Add("Memory", memory);
            return json.ToString();
        }

        public void Load(string state)
        {
            JsonObject json = (JsonObject)JsonValue.Parse(state);
            _decider.Load(json["Decider"]);
            InputLength = _decider.InputNumber;
            _statistics = new Statistic[InputLength];
            JsonArray array = (JsonArray)json["Statistic"];
            for (int i = 0; i < InputLength; i++)
            {
                _statistics[i] = Statistic.Parse(array[i]);
            }
            _memory.Clear();
            JsonArray memory = (JsonArray)json["Memory"];
            foreach (JsonObject item in memory)
            {
                _memory.Add(Pebble.Parse(item.Keys.First()), TBit.Parse(item.Values.First()));
            }
        }
    }
}
