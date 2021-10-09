import {Node} from './tree.js'

function makeTreeFromTraversals(level, inorder) {
    let intervals = [{interval: inorder, root: null, child: null}];
    let actualRoot = null
    
    for (let nodeVal of level) {
        let node = new Node(nodeVal)

        let nodeIndex;
        let intervIndex = intervals.findIndex(interval => {
            nodeIndex = interval.interval.indexOf(node.data)
            return nodeIndex !== -1
        })

        let root = intervals[intervIndex].root
        let child = intervals[intervIndex].child
        
        if ( !root ) {
            actualRoot = node
        }
        else {
            root[child] = node
        }

        let leftInorder = {interval: intervals[intervIndex].interval.slice(0, nodeIndex), root: node, child: 'left'}
        let rightInorder = {interval: intervals[intervIndex].interval.slice(nodeIndex + 1), root: node, child: 'right'}

        intervals.splice(intervIndex, 1)
        if (leftInorder.interval.length) {
            intervals.push(leftInorder)
        }
        if (rightInorder.interval.length) {
            intervals.push(rightInorder)
        }
    }

    return actualRoot
}

let level   = [1, 2, 3, 4, 5, 6, 7, 8, 9, 'a', 'b', 'c', 'd', 'e']
let inorder = [8, 4, 9, 'd', 2, 5, 'a', 1, 'b', 6, 'e', 'c', 3, 7]

let root = makeTreeFromTraversals(level, inorder)
console.log(root.inorder())
console.log(root.levelorder())