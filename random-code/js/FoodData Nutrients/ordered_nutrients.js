const fs = require('fs');
const path = require('path');

const relativePath = path.relative(process.cwd(), __dirname);

const data = fs.readFileSync(`${relativePath}/nutrients.json`);
const nutrients = JSON.parse(data);

let orderedNutrients = [];
for (let id in nutrients) {
    orderedNutrients.push({
        id: id, 
        name: nutrients[id].name,
        number: nutrients[id].number 
    });
}
orderedNutrients = orderedNutrients.sort((a, b) => a.number - b.number);
console.log(orderedNutrients);