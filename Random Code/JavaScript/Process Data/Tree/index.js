import fs from 'fs';

let data = fs.readFileSync('data.csv', 'utf8');

let objs = data
    .trim()
    .split('\r\n')
    .map(line => line.split(', '))
    .map(entries => {
        let [name, parent] = entries;
        return {
            name,
            parent
        };
    });

function makeTree(objs) {
    let map = {};
    
    return objs.reduce((tree, obj) => {
        if (!obj.parent) {
            tree[obj.name] = {};
            map[obj.name] = tree[obj.name];

            return tree;
        }

        let parent = map[obj.parent];
        parent[obj.name] = {};
        map[obj.name] = parent[obj.name];

        return tree
    }, {});
}

let tree = makeTree(objs);
console.log(JSON.stringify(tree, null, 2));