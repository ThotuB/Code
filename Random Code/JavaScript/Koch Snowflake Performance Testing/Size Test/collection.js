class Collection {
    constructor() {
        this.items = [];
    }

    add(item) {
        this.items.push(item);
    }

    toString() {
        let output = "";
        for (let item of this.items) {
            output += item.toString() + "\n";
        }
        return output;
    }
}