using NUnit.Framework;
using TernaryLogic;
using System;
using System.Collections.Generic;
using System.Text;

namespace TernaryLogic.Test
{
    [TestFixture()]
    public class TPerceptronTests
    {
        [Test()]
        public void TPerceptronTest()
        {
            Assert.IsNotNull(new TPerceptron(3));
        }

        [Test()]
        public void PerceptTest()
        {
            TPerceptron perceptron = new TPerceptron(3);
            TBit result = perceptron.Percept(new double[] {1.0, 1.0, 1.0});
            Assert.IsTrue(TBit.FALSE.Value <= result.Value);

            Assert.That(() => perceptron.Percept(null), Throws.TypeOf<ArgumentNullException>());
            Assert.That(() => perceptron.Percept(new double[] { 1.0, 1.0 }), Throws.TypeOf<ArgumentOutOfRangeException>());
        }

        [Test()]
        public void TeachTest()
        {
            var input = new double[] { 10.0, 1.0, 100.0 };
            TPerceptron perceptron = new TPerceptron(3);
            int counter = 0;
            TBit result = perceptron.Percept(input);
            TBit teach = !result;
            do
            {
                perceptron.Teach(teach);
                result = perceptron.Percept(input);
                counter++;
                if (counter > 100)
                {
                    Assert.Fail("Counter = " + counter);
                }
            } while (result != teach);
        }

        [Test()]
        public void LoadTest()
        {
            var input = new double[] { 10.0, 1.0, 100.0 };
            TPerceptron perceptron = new TPerceptron(3);
            int counter = 0;
            TBit result = perceptron.Percept(input);
            TBit teach = !result;
            do
            {
                perceptron.Teach(teach);
                result = perceptron.Percept(input);
                counter++;
                if (counter > 100)
                {
                    Assert.Fail("Counter = " + counter);
                }
            } while (result != teach);

            string sav = perceptron.Save();
            Console.WriteLine(sav);
            TPerceptron perceptron1 = new TPerceptron(0);
            perceptron1.Load(sav);
            result = perceptron1.Percept(new double[] { 1.0, 1.0, 1.0 });
            Assert.AreEqual(teach, result);
        }
    }
}