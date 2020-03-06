using System;
using System.Collections.Generic;
using System.Json;

namespace TernaryLogic.Manager
{
    class Orcestrator : IRemember
    {
        public static Orcestrator Instance { get; } = new Orcestrator();

        readonly Dictionary<int, ILayer> _layers = new Dictionary<int, ILayer>();

        private Orcestrator() { }

        public void Register(ILayer remark)
        {
            if (!_layers.ContainsKey(remark.Id))
            {
                _layers.Add(remark.Id, remark);
            }
        }

        public string Save()
        {
            JsonObject json = new JsonObject();
            JsonArray array = new JsonArray();
            foreach (var item in _layers)
            {
                array.Add(item.Value.Save());
            }
            json.Add("Layers", array);
            return json.ToString();
        }

        public void Load(string state)
        {
            throw new NotImplementedException();
        }
    }
}
