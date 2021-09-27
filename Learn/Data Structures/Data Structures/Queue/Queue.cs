namespace Data_Structures.Queue
{
    public class Queue<T>{
        public uint Size { get; private set; }
        private Node _head;
        private Node _tail;

        private class Node{
            public T Data { get; set; }
            public Node Next { get; set; }
            public Node Prev { get; set; }

            public Node(T data, Node prev, Node next){
                Data = data;
                Prev = prev;
                Next = next;
            }

            /// To String
            public override string ToString(){
                return Data.ToString();
            }
        }

        /// Constructor
        public Queue(){}

        public Queue(params T[] data){
            Push(data);
        }

        /// Empty
        public bool IsEmpty() {
            return Size == 0;
        }

        /// Insertion
        private void PushIfEmpty(T data){
            var node = new Node(data, null, null);

            _head = node;
            _tail = node;

            Size++;
        }

        private void PushAtHead(T data){
            var node = new Node(data, null, _head);

            _head.Prev = node;
            _head = node;

            Size++;
        }

        public void Push(T data){
            if( IsEmpty() ) {
                PushIfEmpty(data);
                return;
            }
            
            PushAtHead(data);
        }

        public void Push(params T[] data){
            Push(data[0]);

            for(int i = 1; i < data.Length; i++){
                PushAtHead(data[i]);
            }
        }

        /// Deletion
        public T Pop(){
            if( IsEmpty() ) throw new System.Exception("List is empty");
            
            T data = _tail.Data;
            _tail = _tail.Prev;

            if ( Size == 1 ){
                _head = null;
            }
            else {
                _tail.Next = null;
            }

            Size--;

            return data;
        }

        /// Peek
        public T PeekBack(){
            if( IsEmpty() ) throw new System.Exception("List is empty");
            return _tail.Data;
        }

        public T PeekFront(){
            if( IsEmpty() ) throw new System.Exception("List is empty");
            return _head.Data;
        }

        /// Search
        public uint Find(T data){
            uint index = 0;
            for (Node curr = _head; curr != null; curr = curr.Next){
                if ( curr.Data.Equals(data) ){
                    return index;
                }
                index++;
            }

            return Size;
        }

        public bool Contains(T data){
            return Find(data) != Size;
        }

        /// To String
        public override string ToString(){
            string output = "";
            for (Node curr = _head; curr != null; curr = curr.Next){
                output += curr + " > ";
            }
            output = output.Substring(0, output.Length - 3);
            return output;
        }
    }
}