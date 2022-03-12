const promise1 = Promise.resolve(1);
const promise2 = Promise.reject(2);
const promise3 = 3

Promise.allSettled([promise1, promise2, promise3])
    .then(values => {
        console.log(`resolved: ${values}`);
    })
    .catch(err => {
        console.log(`rejected: ${err}`);
    })