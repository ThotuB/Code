class Node {
    constructor(value, left=null, right=null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

let root =  new Node(1,
                new Node(2,
                    new Node(4,
                        new Node(8),
                        new Node(9)),
                    new Node(5)
                    ),
                new Node(3,
                    new Node(6,
                        null,
                        new Node(10)
                    ),
                    new Node(7)
                )
            );

console.log(JSON.stringify(root, null, 2));