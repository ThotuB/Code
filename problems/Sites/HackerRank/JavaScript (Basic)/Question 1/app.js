const https = require('https');

async function getCountryCode(code) {
    return new Promise((resolve, reject) => {
        for (let page = 1 ; page <= 25 ; page++) {
            https.get(`https://jsonmock.hackerrank.com/api/countries?page=${page}`, res => {
                res.on('data', data => {
                    let country = JSON.parse(data)
                        .data
                        .find(country => country.alpha2Code === code)
                        
                    if ( country ) {
                        resolve(country.name)
                    }
                })
            }).on('error', err => {
                reject(err)
            })
        }
    })
}

let countryCode = 'RO'
getCountryCode(countryCode)
    .then(country => {
        console.log(country)
    })

