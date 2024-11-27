let collection1 = new Collection();

for (let i = 0; i < 1000000; i++) {
    collection1.add(new Item(i));
}

let collection = new Collection();

let item = new Item(0);

for (let i = 0; i < 1000000; i++) {
    collection.add(item);
}