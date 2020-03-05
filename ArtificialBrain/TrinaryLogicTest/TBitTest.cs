using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using TernaryLogic;

namespace TrinaryLogicTest
{
    [TestClass]
    public class TBitTest
    {
        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void WrongCreation()
        {
            TBit bit = 5;
            Assert.IsNotNull(bit);
        }

        [TestMethod]
        public void TBitCreation()
        {
            TBit bit = 0;
            Assert.AreEqual(TBit.MAIBY, bit);
            bit = new TBit();
            Assert.AreEqual(TBit.MAIBY, bit);
        }

        [TestMethod]
        public void NotEqual()
        {
            Assert.AreNotEqual(TBit.MAIBY, new object());
        }

        [TestMethod]
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
    }
}
