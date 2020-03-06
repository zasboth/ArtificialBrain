using NUnit.Framework;
using System;
using TernaryLogic;


namespace TernaryLogic.Test
{
    public class PebbleTests
    {
        public static Pebble CreatePebble()
        {
            var pebble = new Pebble(3);
            pebble[0] = TBit.TRUE;
            pebble[1] = TBit.MAIBY;
            pebble[2] = TBit.FALSE;
            return pebble;
        }

        [Test]
        public void CompareTest()
        {
            var pebble = CreatePebble();
            Pebble operand = CreatePebble();

            var result = pebble.Compare(operand);
            Assert.AreEqual(TBit.TRUE, result);

            operand[1] = TBit.FALSE;
            operand[2] = TBit.TRUE;
            pebble[1] = TBit.TRUE;
            result = pebble.Compare(operand);
            Assert.AreEqual(TBit.FALSE, result);

            operand[2] = TBit.FALSE;
            pebble.Trashold = 3;
            result = pebble.Compare(operand);
            Assert.AreEqual(TBit.MAIBY, result);

            Assert.That(() =>  pebble.Compare(null), Throws.TypeOf<ArgumentNullException>());
            Assert.That(() => pebble.Compare(new Pebble(1)), Throws.TypeOf<ArgumentOutOfRangeException>());
        }

        [Test]
        public void EqualsTest()
        {
            var pebble = CreatePebble();
            object obj = null;

            var result = pebble.Equals(obj);
            Assert.IsFalse(result);

            result = pebble.Equals(new Pebble(3));
            Assert.IsFalse(result);

            obj = CreatePebble();
            result = pebble.Equals(obj);
            Assert.IsTrue(result);
        }

        [Test]
        public void GetHashCodeTest()
        {
            // Arrange
            var pebble = CreatePebble();

            // Act
            var result = pebble.GetHashCode();

            // Assert
            Assert.AreEqual(0, result);
        }

        [Test]
        public void SaveTest()
        {
            Pebble pebble = CreatePebble();
            string saved = pebble.Save();
            Assert.IsFalse(string.IsNullOrEmpty(saved));
            Assert.AreEqual("[1, 0, -1]", saved);
        }

        [Test]
        public void LoadTest()
        {
            Pebble pebble = CreatePebble();
            string saved = pebble.Save();
            Pebble loaded = new Pebble(1);
            loaded.Load(saved);
            Assert.AreEqual(pebble, loaded);
        } 

        [Test]
        public void ParseTest()
        {
            Pebble pebble = CreatePebble();
            Assert.AreEqual(pebble, Pebble.Parse(pebble.ToString()));
        }
    }
}
