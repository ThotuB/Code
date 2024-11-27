const axios = require('axios');

axios
    .get('https://api.nal.usda.gov/fdc/v1/search', {
        params: {
            api_key: 'g8hkV8fS6A17dTaS0DEk464LisJCu8AdN2gKIU2C',
            generalSearchInput: "McChicken",
            dataType: 'Branded',
            pageNumber: 1,
            pageSize: 10,
        },
    })
    .then((res) => {
        const data = res.data;

        for (let field in data) {
            console.log(field);
        }
        console.log(data.totalHits);
        for (let field in data.foods[0]) {
            console.log(field);
        }

        const alteredData = data.foods.map((food) => {
            return {
                name: food.description,
                brand: food.brandOwner,
                brandName: food.brandName,
                servingSize: food.servingSize,
                servingSizeUnit: food.servingSizeUnit,
                score: food.score,
            };
        }
        );

        console.log(alteredData);
    })
    .catch((err) => {
        console.log(err.code);
        console.log(err.message);
        console.log(err.response.statusText);
    });