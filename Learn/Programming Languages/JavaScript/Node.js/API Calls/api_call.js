const axios = require("axios").default;
const fs = require("fs");

id = 1965765
api_key = 'U90ctjxNwICMOKnJnyqB2kDuKgpqL2dG7vBB03lZ'
url = `https://api.nal.usda.gov/fdc/v1/food/${id}?api_key=${api_key}`

axios.get(url)
    .then(response => {
        const food = response.data;
        
        fs.writeFileSync('./food.json', JSON.stringify(food, null, 2));
    })