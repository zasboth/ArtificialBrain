using NUnit.Framework;
using TernaryLogic;
using System;
using System.Collections.Generic;
using System.Text;

namespace TernaryLogic.Test
{
    [TestFixture()]
    public class PileTests
    {
        [Test()]
        public void PileTest()
        {
            var pile = new Pile(3);
            Assert.AreEqual(3, pile.InputLength);
        }

        [Test()]
        public void AnswerTest()
        {
            var pile = new Pile(3);
            var answ = pile.Answer(PebbleTests.CreatePebble());
            Assert.AreEqual(TBit.TRUE, answ);
        }

        [Test()]
        public void FeedbackTest()
        {
            var pile = new Pile(3);
            var question = PebbleTests.CreatePebble();
            var answ = pile.Answer(question);
            Assert.AreEqual(TBit.TRUE, answ);
                        
            pile.Feedback(TBit.TRUE);
            answ = pile.Answer(question);
            Assert.AreEqual(TBit.TRUE, answ);

            pile.Feedback(TBit.TRUE);
            pile.Feedback(TBit.TRUE);
            pile.Answer(question);
            pile.Feedback(TBit.MAIBY);
            pile.Answer(question);
            pile.Feedback(TBit.FALSE);
        }

        [Test()]
        public void SaveTest()
        {
            var pile = new Pile(3);
            var question = PebbleTests.CreatePebble();
            var answ = pile.Answer(question);
            Assert.AreEqual(TBit.TRUE, answ);

            pile.Feedback(TBit.TRUE);
            answ = pile.Answer(question);
            Assert.AreEqual(TBit.TRUE, answ);

            String saved = pile.Save();
            Console.WriteLine(saved);
            Assert.IsFalse(String.IsNullOrEmpty(saved));
        }

        [Test()]
        public void LoadTest()
        {
            var pile = new Pile(3);
            var question = PebbleTests.CreatePebble();
            var answ = pile.Answer(question);
            Assert.AreEqual(TBit.TRUE, answ);

            pile.Feedback(TBit.TRUE);
            answ = pile.Answer(question);
            Assert.AreEqual(TBit.TRUE, answ);

            String saved = pile.Save();
            Assert.IsFalse(String.IsNullOrEmpty(saved));
            var loaded = new Pile(0);
            loaded.Load(saved);
            Assert.IsTrue(loaded.InputLength == pile.InputLength);
            Assert.AreEqual(loaded.Save(), saved);
        }
    }
}