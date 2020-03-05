using System.Collections;
using System.Collections.Generic;
using System.Json;

namespace TernaryLogic.Manager
{

    public interface ILayer : ICollection<int>, IRemember
    {
        public int Id { get; }

        public int this[int i] { get; }

        Pebble Fire();
        Pebble Teach(Pebble better);

    }

    public interface ILayer<T> : ILayer
    {
        T Input { get; set; }
    }

    public abstract class LayerBase<T> : ILayer<T>
    {
        readonly List<int> _outputIds = new List<int>();
        protected T input;

        protected LayerBase(int id)
        {
            Id = id;
            Orcestrator.Instance.Register(this);
        }

        public int this[int i] => _outputIds[i];

        public int Id { get; protected set; }

        public int Count => _outputIds.Count;

        bool ICollection<int>.IsReadOnly => false;

        public T Input { get; set; }

        public void Add(int item)
        {
            _outputIds.Add(item);
        }

        public void Clear()
        {
            _outputIds.Clear();
        }

        public bool Contains(int item)
        {
            return _outputIds.Contains(item);
        }

        public void CopyTo(int[] array, int arrayIndex)
        {
            _outputIds.CopyTo(array, arrayIndex);
        }

        abstract public Pebble Fire();

        public IEnumerator<int> GetEnumerator()
        {
            return _outputIds.GetEnumerator();
        }

        protected virtual JsonObject LoadLocal(JsonObject json)
        {
            JsonArray array = json["Outputs"] as JsonArray;
            _outputIds.Clear();
            foreach (var item in array)
            {
                _outputIds.Add(item);
            }
            return json;
        }

        public void Load(string state)
        {
            JsonObject json = JsonObject.Parse(state) as JsonObject;
            LoadLocal(json);
        }

        public bool Remove(int item)
        {
            return _outputIds.Remove(item);
        }

        protected virtual JsonObject SaveLocal()
        {
            JsonObject result = new JsonObject();
            JsonArray array = new JsonArray();
            foreach (var item in _outputIds)
            {
                array.Add(item);
            }
            result.Add("Outputs", array);
            return result;
        }

        public string Save()
        {
            return SaveLocal().ToString();
        }

        abstract public Pebble Teach(Pebble better);

        IEnumerator IEnumerable.GetEnumerator() => null;

    }
}
