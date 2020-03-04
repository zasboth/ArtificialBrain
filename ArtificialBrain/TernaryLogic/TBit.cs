using System;

namespace TernaryLogic
{
    public struct TBit
    {
        public static readonly TBit TRUE = 1;
        public static readonly TBit MAIBY = 0;
        public static readonly TBit FALSE = -1;

        private sbyte _value;

        public sbyte Value { get => _value; }

        public static TBit Parse(string s)
        {
            if (string.IsNullOrEmpty(s)) throw new ArgumentException();
            if (sbyte.TryParse(s, out sbyte val)) return val;
            return (s.ToUpper()) switch
            {
                "TRUE" => TRUE,
                "MAIBY" => MAIBY,
                "FALSE" => FALSE,
                _ => throw new FormatException("Not valid TBit value!"),
            };
        }

        public TBit Compare(TBit operand)
        {
            if (operand == null) throw new ArgumentNullException();
            if (this == operand || this == MAIBY) return TRUE;
            if (operand == MAIBY) return MAIBY;
            else return FALSE;
        }

        public override bool Equals(object obj)
        {
            if (!(obj is TBit)) return base.Equals(obj);
            else
            {
                return _value == ((TBit)obj)._value;
            }
        }

        public static implicit operator TBit(sbyte v)
        {
            if (v > 1 || v < -1) throw new ArgumentOutOfRangeException();
            return new TBit() { _value = v };
        }

        public override int GetHashCode()
        {
            return _value;
        }

        public static bool operator ==(TBit left, TBit right)
        {
            return left.Equals(right);
        }

        public static bool operator !=(TBit left, TBit right)
        {
            return !(left == right);
        }

        public static TBit operator !(TBit bit)
        {
            return (TBit)(bit.Value * -1);
        }

        static readonly string[] STRING_VALUES = { "FALSE", "MAIBY", "TRUE" };
        public override string ToString()
        {
            return STRING_VALUES[_value + 1];

        }
    }
}
