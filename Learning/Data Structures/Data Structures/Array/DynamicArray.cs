namespace Data_Structures.Array
{
    public class DynamicArray<T>{
        private T[] _array;
        public uint Length { get; private set; }
        public uint Capacity { get; private set; }

        public DynamicArray() : this(16) {}

        public DynamicArray(uint capacity) {
            _array = new T[capacity];
            Length = 0;
            Capacity = capacity;
        }

        // capacity
        public bool IsEmpty() {
            return Length == 0;
        }

        // element modification
        private void Resize() {
            Capacity = ( Capacity == 0 ) ? 1 : Capacity * 2;
            T[] newArray = new T[Capacity];
            for(uint i = 0; i < Length; i++) {
                newArray[i] = _array[i];
            }
            _array = newArray;
        }

        public void Add(T item) {
            if (Length == Capacity) { // resize
                Resize();
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
                Resize();
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

        public bool Remove(T item) {
            for (uint i = 0; i < Length; i++) {
                if (_array[i].Equals(item)) {
                    RemoveAt(i);
                    return true;
                }
            }
            return false;
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
            output = output.TrimEnd(',', ' ');
            output += "]";
            
            return output;
        }
    }
}