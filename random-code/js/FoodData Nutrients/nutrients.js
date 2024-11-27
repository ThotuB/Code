const axios = require('axios').default;
const fs = require('fs');
const path = require('path');


async function getFoodPage(page) {
    const url = `https://api.nal.usda.gov/fdc/v1/search`
    const query = {
        params: {
            api_key: 'U90ctjxNwICMOKnJnyqB2kDuKgpqL2dG7vBB03lZ',
            generalSearchInput: '',
            dataType: 'Branded',
            pageNumber: page,
            pageSize: 1000
        }
    }
    const response = await axios.get(url, query)
    return response.data.foods
}

async function getNutrients(){
    const nutrients = {}
    for (let page = 1; page < 10; page++) {
        console.log(`Page ${page}`)
        let foods = await getFoodPage(page)
        
        for (let food of foods) {
            for (let nutrient of food.foodNutrients) {
                if (!nutrients[nutrient.nutrientId]) {
                    nutrients[nutrient.nutrientId] = {
                        name: nutrient.nutrientName,
                        number: nutrient.nutrientNumber,
                    }
                }
            }
        }
    }
    
    return nutrients
}

getNutrients().then(res => {
    const filePath = path.join(__dirname, 'nutrients.json')
    fs.writeFileSync(filePath, JSON.stringify(res, null, 4))
})

