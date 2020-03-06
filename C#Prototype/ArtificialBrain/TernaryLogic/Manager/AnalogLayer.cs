using System;
using System.Json;

namespace TernaryLogic.Manager
{
    public class AnalogLayer : LayerBase<double[]>
    {
        public AnalogLayer(int id) : base(id)
        {
        }

        public override Pebble Fire()
        {
            throw new NotImplementedException();
        }

        public override Pebble Teach(Pebble better)
        {
            throw new NotImplementedException();
        }

        protected override JsonObject LoadLocal(JsonObject json)
        {
            return base.LoadLocal(json);
        }

        protected override JsonObject SaveLocal()
        {
            return base.SaveLocal();
        }
    }
}
