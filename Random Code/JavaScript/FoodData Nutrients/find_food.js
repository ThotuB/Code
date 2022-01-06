const axios = require('axios').default;

async function getFood() {
    const url = `https://api.nal.usda.gov/fdc/v1/foods`
    const query = {
        params: {
            api_key: 'U90ctjxNwICMOKnJnyqB2kDuKgpqL2dG7vBB03lZ',
            fdcIds: 534358
            
        }
    }
    const response = await axios.get(url, query)
    return response.data[0]
}

async function getNutrients(){
    console.log(await getFood())
}

getNutrients().then(() => console.log('done'))