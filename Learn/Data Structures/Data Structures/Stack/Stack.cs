namespace Data_Structures.Stack
{
    public class Stack<T>{
        public uint Size { get; private set; }
        private Node _head;

        private class Node {
            public T Data { get; set; }
            public Node Next { get; set; }

            public Node(T data, Node next) {
                Data = data;
                Next = next;
            }

            /// To String
            public override string ToString(){
                return Data.ToString();
            }
        }

        public Stack(){}

        public Stack(params T[] data){
            Push(data);
        }

        /// Capacity
        public bool IsEmpty() {
            return Size == 0;
        }

        /// Push
        public void Push(T data){
            _head = new Node(data, _head);
            Size++;
        }

        public void Push(params T[] data){
            foreach (T item in data){
                Push(item);
            }
        }

        /// Pop
        public T Pop(){
            if (IsEmpty()) throw new System.Exception("Stack is empty");

            T data = _head.Data;
            _head = _head.Next;
            Size--;

            return data;
        }

        /// Peek
        public T Peek(){
            if (IsEmpty()) throw new System.Exception("Stack is empty");

            return _head.Data;
        }

        /// Search
        public uint Find(T data){
            uint index = 0;
            for (Node curr = _head; curr != null; curr = curr.Next){
                if (curr.Data.Equals(data)) {
                    return index;
                }
            }
            return Size;
        }

        public bool Contains(T data){
            return Find(data) != Size;
        }

        /// To String
        public override string ToString(){
            string output = "Stack:\n";
            for (Node current = _head; current != null; current = current.Next){
                output += current + " < ";
            }
            output = output.Substring(0, output.Length - 3);
            return output;
        }
    }
}