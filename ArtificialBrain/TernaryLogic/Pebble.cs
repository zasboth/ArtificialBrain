using System;
using System.Json;
using System.Text;
using TernaryLogic.Manager;

namespace TernaryLogic
{
    public class Pebble : IRemember
    {
        public static Pebble Parse(string val)
        {
            var pebble = new Pebble(1);
            pebble.Load(val);
            return pebble;
        }

        TBit[] bits;

        public Pebble(int inputNumber)
        {
            InputNumber = inputNumber;
            bits = new TBit[inputNumber];
            Trashold = InputNumber / 3;
        }

        public TBit this[int i] { get => bits[i]; set => bits[i] = value; }
        public int Trashold { get; set; }
        public int InputNumber { get; private set; }

        public TBit Compare(Pebble operand)
        {
            if (operand == null) throw new ArgumentNullException();
            if (InputNumber != operand.InputNumber) throw new ArgumentOutOfRangeException("The size is not equal");
            int _true = 0;
            int _false = 0;
            for (int i = 0; i < bits.Length; i++)
            {
                TBit cmp = bits[i].Compare(operand[i]);
                if (TBit.TRUE == cmp) _true++;
                if (TBit.FALSE == cmp) _false++;
            }
            if (_true > _false && Trashold <= _true) return TBit.TRUE;
            if (_false > _true && Trashold <= _false) return TBit.FALSE;
            return TBit.MAIBY;
        }

        public override bool Equals(object obj)
        {
            if (!(obj is Pebble)) return base.Equals(obj);
            else
            {
                for (int i = 0; i < InputNumber; i++)
                {
                    if (((Pebble)obj)[i] != bits[i]) return false;
                }
                return true;
            }
        }

        public override int GetHashCode()
        {
            int sum = 0;
            foreach (var item in bits)
            {
                sum += item.GetHashCode();
            }
            return sum;
        }

        public static Pebble operator !(Pebble pebble)
        {
            var result = new Pebble(pebble.InputNumber);
            for (int i = 0; i < pebble.bits.Length; i++)
            {
                result.bits[i] = !pebble.bits[i];
            }
            return result;
        }

        public void Load(string state)
        {
            JsonArray array = JsonArray.Parse(state) as JsonArray;
            InputNumber = array.Count;
            bits = new TBit[InputNumber];
            for (int i = 0; i < InputNumber; i++)
            {
                bits[i] = TBit.Parse(array[i].ToString());
            }
        }

        public string Save()
        {
            return ToString();
        }

        public override string ToString()
        {
            JsonArray array = new JsonArray();
            foreach (var item in bits)
            {
                array.Add(item.Value);
            }
            return array.ToString();
        }
    }
}
