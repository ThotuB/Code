const axios = require("axios").default;

api_key = 'U90ctjxNwICMOKnJnyqB2kDuKgpqL2dG7vBB03lZ'
url = `https://api.nal.usda.gov/fdc/v1/search`

function get_foods() {
    return axios.get(url, {
        params: {
            api_key: api_key,
            generalSearchInput: 'chicken',
            pageNumber: 2,
            pageSize: 3
        }
    })
}

get_foods()
.then(response => {
    console.log(response.data.foods[0].foodNutrients);
})