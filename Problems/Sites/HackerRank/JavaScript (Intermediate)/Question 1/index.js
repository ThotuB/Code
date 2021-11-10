class ParkingLot {
    constructor(slots) {
        this.slots = slots;
        this.taken = 0;
        this.cars = new Array(slots).fill(null);
    }

    park(carId) {
        if ( this.taken === this.slots ) {
            return false;
        }

        for ( let i = 0; i < this.slots; i++ ) {
            if ( this.cars[i] == null ) {
                this.cars[i] = carId;
                this.taken++;
                return true;
            }
        }
    }

    remove(carId) {
        for ( let i = 0; i < this.slots; i++ ) {
            if ( this.cars[i] == carId ) {
                this.cars[i] = null;
                this.taken--;
                return true;
            }
        }
        return false;
    }

    getSlots() {
        return this.cars;
    }
}


let parkingLot = new ParkingLot(5);
parkingLot.park('A1');
parkingLot.park('A2');
parkingLot.park('A3');
console.log(parkingLot.getSlots());
parkingLot.remove('A2');
console.log(parkingLot.getSlots());