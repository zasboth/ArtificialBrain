using System;
using System.Collections.Generic;
using System.Json;

namespace TernaryLogic.Manager
{
    class TrinaryLayer : LayerBase<Pebble>
    {
        readonly List<Pile> piles = new List<Pile>();

        public TrinaryLayer(int id) : base(id) { }


        public override Pebble Fire()
        {
            Pebble result = new Pebble(piles.Count);
            for (int i = 0; i < piles.Count; i++)
            {
                result[i] = piles[i].Answer(Input);
            }
            return result;
        }

        public void InitPiles(int outputLength, int inputLength)
        {
            piles.Clear();
            for (int i = 0; i < outputLength; i++)
            {
                piles.Add(new Pile(inputLength));
            }
        }

        protected override JsonObject LoadLocal(JsonObject json)
        {
            piles.Clear();
            JsonArray array = json["Piles"] as JsonArray;
            foreach (var item in array)
            {
                var p = new Pile(0);
                p.Load(item);
                piles.Add(p);
            }
            return base.LoadLocal(json);
        }

        protected override JsonObject SaveLocal()
        {
            JsonObject json = base.SaveLocal();
            JsonArray array = new JsonArray();
            foreach (var item in piles)
            {
                array.Add(item.Save());
            }
            json.Add("Piles", array);
            return json;
        }

        public override Pebble Teach(Pebble better)
        {
            throw new NotImplementedException();
        }

    }
}
