namespace Data_Structures.List
{
    public class SimplyLinkedList<T>{
        public uint Size { get; private set; }
        private Node _head;
        private Node _tail;

        private class Node{
            public T Data { get; set; }
            public Node Next { get; set; }

            public Node(T data, Node next){
                Data = data;
                Next = next;
            }

            /// To String
            public override string ToString(){
                return Data.ToString();
            }
        }

        /// Constructor
        public SimplyLinkedList(){}

        public SimplyLinkedList(params T[] data){
            InsertBack(data);
        }

        /// Empty
        public bool IsEmpty() {
            return Size == 0;
        }

        /// Insertion
        private void InsertIfEmpty(T data){
            var node = new Node(data, null);

            _head = node;
            _tail = node;

            Size++;
        }

        private void InsertAtTail(T data){
            var node = new Node(data, null);

            _tail.Next = node;
            _tail = node;
            
            Size++;
        }

        private void InsertAtHead(T data){
            var node = new Node(data, _head);

            _head = node;

            Size++;
        }

        public void InsertBack(T data){
            if( IsEmpty() ){
                InsertIfEmpty(data);
                return;
            }

            InsertAtTail(data);
        }

        public void InsertBack(params T[] data){
            InsertBack(data[0]);

            for(int i = 1; i < data.Length; i++){
                InsertAtTail(data[i]);
            }
        }

        public void InsertFront(T data){
            if( IsEmpty() ) {
                InsertIfEmpty(data);
                return;
            }
            
            InsertAtHead(data);
        }

        public void InsertFront(params T[] data){
            InsertFront(data[0]);

            for(int i = 1; i < data.Length; i++){
                InsertAtHead(data[i]);
            }
        }

        /// Deletion
        public T RemoveBack(){
            if( IsEmpty() ) throw new System.Exception("List is empty");

            T data = _tail.Data;

            if ( Size == 1 ){
                _head = null;
                _tail = null;
            }
            else{
                Node curr = _head;
                while ( curr.Next != _tail ){
                    curr = curr.Next;
                }

                curr.Next = null;
                _tail = curr;
            }


            Size--;

            return data;
        }

        public T RemoveFront(){
            if( IsEmpty() ){
                throw new System.Exception("List is empty");
            }
            T data = _head.Data;
            _head = _head.Next;

            if ( Size == 1 ){
                _tail = null;
            }

            Size--;
            
            return data;
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
                output += curr + " -> ";
            }
            output += "null"
                      + "\nhead: " + (_head == null ? "null" : _head.Data)
                      + "\ntail: " + (_tail == null ? "null" : _tail.Data);
            return output;
        }
    }
}