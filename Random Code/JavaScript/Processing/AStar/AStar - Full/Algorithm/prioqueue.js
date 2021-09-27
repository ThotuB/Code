class PriorityQueue {
    constructor() {
        this.heap = [];
        this.capacity = 16;
        this.size = 0;
    }

    /// Size
    isEmpty() {
        return this.size === 0;
    }

    /// Swap
    swap(i, j) {
        let temp = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = temp;
    }

    /// Add
    enqueue(data) {
        if ( this.size === this.capacity ) {
            this.capacity *= 2;
        }

        const heapifyUp = () => {
            let i = this.size;
            while (i > 0) {
                let parent = Math.floor((i - 1) / 2);
                if ( this.heap[parent].compareTo(this.heap[i]) > 0 ) {
                    this.swap(i, parent);
                    i = parent;
                    continue;
                }
                break;
            }
        }

        this.heap.push(data);
        heapifyUp();
        this.size++;
    }

    /// Pop
    dequeue() {
        if ( this.isEmpty() ) throw "PrioQueue is empty";

        const heapifyDown = () => {
            let i = 0;
            while (i * 2 + 1 < this.size) {
                let childL = i * 2 + 1;
                let childR = i * 2 + 2;
                let smallest = i;
                if (childL < this.size && this.heap[childL].compareTo(this.heap[smallest]) < 0) {
                    smallest = childL;
                }
                if (childR < this.size && this.heap[childR].compareTo(this.heap[smallest]) < 0) {
                    smallest = childR;
                }

                if (smallest !== i) {
                    this.swap(i, smallest);
                    i = smallest;
                    continue;
                }
                break;
            }
        }
        
        let data = this.heap[0];
        this.heap[0] = this.heap[this.size - 1];
        this.heap.pop();
        this.size--;

        heapifyDown();

        return data;
    }

    /// Peek
    peek() {
        if ( this.isEmpty() ) throw "PrioQueue is empty";

        return this.heap[0];
    }

    /// Contains
    contains(data) {
        return this.heap.includes(data);
    }
}