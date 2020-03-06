using NUnit.Framework;
using System;
using TernaryLogic;

namespace TernaryLogic.Test
{
    public class TBitTest
    {
        [Test]
        public void WrongCreation()
        {
            Assert.That(() => { TBit bit = 5; }, Throws.TypeOf<ArgumentOutOfRangeException>());
        }

        [Test]
        public void TBitCreation()
        {
            TBit bit = 0;
            Assert.AreEqual(TBit.MAIBY, bit);
            bit = new TBit();
            Assert.AreEqual(TBit.MAIBY, bit);
        }

        [Test]
        public void NotEqual()
        {
            Assert.AreNotEqual(TBit.MAIBY, new object());

            Assert.IsTrue(TBit.FALSE != TBit.MAIBY);
        }

        [Test]
        public void Compare()
        {
            TBit bit = TBit.FALSE;
            Assert.AreEqual(TBit.TRUE, bit.Compare(TBit.FALSE));
            bit = TBit.MAIBY;
            Assert.AreEqual(TBit.TRUE, bit.Compare(TBit.FALSE));
            bit = TBit.TRUE;
            Assert.AreEqual(TBit.MAIBY, bit.Compare(TBit.MAIBY));
            bit = TBit.FALSE;
            Assert.AreEqual(TBit.FALSE, bit.Compare(TBit.TRUE));
        }

        [Test]
        public void ParseTest()
        {
            Assert.AreEqual(TBit.TRUE, TBit.Parse("true"));
            Assert.AreEqual(TBit.MAIBY, TBit.Parse("maiby"));
            Assert.AreEqual(TBit.FALSE, TBit.Parse("false"));
            Assert.AreEqual(TBit.TRUE, TBit.Parse("1"));
            Assert.AreEqual(TBit.MAIBY, TBit.Parse("0"));
            Assert.AreEqual(TBit.FALSE, TBit.Parse("-1"));
            
            Assert.That(() => TBit.Parse(null), Throws.TypeOf<ArgumentException>());
            Assert.That(() => TBit.Parse("aaa"), Throws.TypeOf<FormatException>());
        }

        [Test]
        public void ToStringTest()
        {
            Assert.AreEqual("TRUE", TBit.TRUE.ToString());
            Assert.AreEqual("MAIBY", TBit.MAIBY.ToString());
            Assert.AreEqual("FALSE", TBit.FALSE.ToString());
        }
    }
}
