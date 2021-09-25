﻿namespace Data_Structures.List
{
    public class DoublyLinkedList<T>{
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
        public DoublyLinkedList(){}

        public DoublyLinkedList(params T[] data){
            InsertBack(data);
        }

        /// Empty
        public bool IsEmpty() {
            return Size == 0;
        }

        /// Insertion
        private void InsertIfEmpty(T data){
            var node = new Node(data, null, null);

            _head = node;
            _tail = node;

            Size++;
        }

        private void InsertAtTail(T data){
            var node = new Node(data, _tail, null);

            _tail.Next = node;
            _tail = node;
            
            Size++;
        }

        private void InsertAtHead(T data){
            var node = new Node(data, null, _head);

            _head.Prev = node;
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

        public T RemoveFront(){
            if( IsEmpty() ) throw new System.Exception("List is empty");
            T data = _head.Data;
            _head = _head.Next;

            if ( Size == 1 ){
                _tail = null;
            }
            else {
                _head.Prev = null;
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
            string output = "null <- ";
            for (Node curr = _head; curr != null; curr = curr.Next){
                output += curr + " <-> ";
            }
            output = output.Substring(0, output.Length - 4) + "-> null"
                                                            + "\nhead: " + (_head == null ? "null" : _head.Data)
                                                            + "\ntail: " + (_tail == null ? "null" : _tail.Data);
            return output;
        }
    }
}