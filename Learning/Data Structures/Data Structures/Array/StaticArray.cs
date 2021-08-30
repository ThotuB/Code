namespace Data_Structures.Array
{
    public class StaticArray<T> {
        private readonly T[] _array;
        public uint Length { get; private set; }
        public uint Capacity { get; }

        public StaticArray(uint capacity) {
            this._array = new T[capacity];
            this.Length = 0;
            this.Capacity = capacity;
        }

        // capacity
        public bool IsEmpty() {
            return this.Length == 0;
        }

        // element modification
        public void Add(T item) {
            if (Length == Capacity) {
                throw new System.Exception("Array is full");
            }
            _array[Length++] = item;
        }

        public void Add(params T[] items) {
            foreach (T item in items) {
                Add(item);
            }
        }

        public void Insert(T item, uint index) {
            if (Length == Capacity) {
                throw new System.Exception("Array is full");
            }
            if (index > Length) {
                throw new System.Exception("Index out of bounds");
            }

            InsertMove();
            _array[index] = item;
            Length++;

            void InsertMove() {
                for (var i = Length; i > index; i--) {
                    _array[i] = _array[i - 1];
                }
            }
        }

        public void RemoveAt(uint index) {
            if (index > Length) {
                throw new System.Exception("Index out of bounds");
            }
            
            RemoveMove();
            Length--;

            void RemoveMove() {
                for (var i = index; i < Length; i++) {
                    _array[i] = _array[i + 1];
                }
            }
        }

        public void Remove(T item) {
            for (uint i = 0; i < Length; i++) {
                if (_array[i].Equals(item)) {
                    RemoveAt(i);
                    return;
                }
            }
        }

        public void Clear() {
            Length = 0;
        }

        public T this[uint index] {
            get {
                if (index > Length) {
                    throw new System.Exception("Index out of bounds");
                }
                return _array[index];
            }
            set {
                if (index > Length) {
                    throw new System.Exception("Index out of bounds");
                }
                _array[index] = value;
            }
        }

        // element search
        public uint Find(T item) {
            for (uint i = 0; i < Length; i++) {
                if (_array[i].Equals(item)) {
                    return i;
                }
            }
            return Length;
        }

        public bool Contains(T item) {
            return Find(item) != Length;
        }

        // overrides
        public override string ToString() {
            var output = "[";
            for (uint i = 0; i < Length; i++) {
                output += $"{_array[i].ToString()}, ";
            }
            output = output.Substring(0, output.Length - 2);
            output += "]";
            return output;
        }
    }
}