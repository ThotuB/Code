import {Node} from './tree.js'

function makeTreeFromTraversals(preorder, inorder) {
    let root = new Node(preorder[0]);
    function makeTree(root, preorder, inorder) {
        let index = inorder.indexOf(root.data)

        let leftPreorder = preorder.slice(1, index + 1)
        let rightPreorder = preorder.slice(index + 1)
        let leftInorder = inorder.slice(0, index)
        let rightInorder = inorder.slice(index + 1)

        if (leftPreorder.length > 0) {
            root.left = new Node(leftPreorder[0])
            makeTree(root.left, leftPreorder, leftInorder)
        }
        if (rightPreorder.length > 0) {
            root.right = new Node(rightPreorder[0])
            makeTree(root.right, rightPreorder, rightInorder)
        }
    }

    makeTree(root, preorder, inorder)
    return root
}

let preorder = [1, 2, 4, 8, 9, 'd', 5, 'a', 3, 6, 'b', 'c', 'e', 7]
let inorder =  [8, 4, 9, 'd', 2, 5, 'a', 1, 'b', 6, 'e', 'c', 3, 7]

let root = makeTreeFromTraversals(preorder, inorder)
console.log(JSON.stringify(root, null, 4))

console.log(root.preorder())
console.log(root.inorder())