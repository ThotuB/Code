class Node {
    constructor(data, left = null, right = null) {
        this.data = data
        this.left = left
        this.right = right
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

    levelorder() {
        function levelorder(root) {
            let output = ''

            let queue = [root]
            while (queue.length > 0) {
                let node = queue.shift()
                output += node.data + ' '

                if (node.left) {
                    queue.push(node.left)
                }
                if (node.right) {
                    queue.push(node.right)
                }
            }
            return output
        }
        return levelorder(this)
    }
}

export { Node }