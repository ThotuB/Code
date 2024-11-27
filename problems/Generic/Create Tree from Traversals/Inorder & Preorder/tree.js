class Node {
    constructor(data, left = null, right = null) {
        this.data = data
        this.left = left
        this.right = right
    }

    preorder() {
        function preorder(node) {
            if (node == null) {
                return ''
            }

            return node.data + ' '
                + preorder(node.left)
                + preorder(node.right)
        }
        return preorder(this)
    }

    inorder() {
        function inorder(node) {
            if (node == null) {
                return ''
            }

            return inorder(node.left)
                + node.data + ' '
                + inorder(node.right)
        }
        return inorder(this)
    }
}

export { Node }