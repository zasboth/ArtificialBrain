using Microsoft.VisualStudio.TestTools.UnitTesting;
using Moq;
using System;
using TernaryLogic;

namespace TrinaryLogicTest
{
    [TestClass]
    public class PebbleTests
    {
        private MockRepository mockRepository;



        [TestInitialize]
        public void TestInitialize()
        {
            this.mockRepository = new MockRepository(MockBehavior.Strict);
        }

        [TestCleanup]
        public void TestCleanup()
        {
            this.mockRepository.VerifyAll();
        }

        private Pebble CreatePebble()
        {
            var pebble = new Pebble(3);
            pebble[0] = TBit.TRUE;
            pebble[1] = TBit.MAIBY;
            pebble[2] = TBit.FALSE;
            return pebble;
        }

        [TestMethod]
        public void Compare_StateUnderTest_ExpectedBehavior()
        {
            var pebble = this.CreatePebble();
            Pebble operand = CreatePebble();

            var result = pebble.Compare(operand);
            Assert.AreEqual(TBit.TRUE, result);

            operand[0] = TBit.FALSE;
            result = pebble.Compare(operand);
            Assert.AreEqual(TBit.MAIBY, result);

            operand[1] = TBit.FALSE;
            operand[2] = TBit.TRUE;
            pebble[1] = TBit.TRUE;
            result = pebble.Compare(operand);
            Assert.AreEqual(TBit.FALSE, result);
        }

        [TestMethod]
        public void Equals_StateUnderTest_ExpectedBehavior()
        {
            var pebble = this.CreatePebble();
            object obj = null;

            var result = pebble.Equals(obj);
            Assert.IsFalse(result);

            obj = CreatePebble();
            result = pebble.Equals(obj);
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void GetHashCode_StateUnderTest_ExpectedBehavior()
        {
            // Arrange
            var pebble = this.CreatePebble();

            // Act
            var result = pebble.GetHashCode();

            // Assert
            Assert.AreEqual(0, result);
        }
    }
}
