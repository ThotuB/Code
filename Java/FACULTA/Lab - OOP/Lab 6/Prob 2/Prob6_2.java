class Train {
    private Carriage[] carriages = new Carriage[15];
    private int carriagesSize;

    public Train(Carriage ... carriages){
        this.carriagesSize = carriages.length;

        for (int i = 0 ; i < 15 && i < this.carriagesSize ; i++){
            this.carriages[i] = carriages[i];
        }
    }

    private int getPackageCapacity(){
        int packageCapacityTotal = 0;

        for (int i = 0 ; i < this.carriagesSize ; i++){
            packageCapacityTotal += this.carriages[i].getPackageCapacity();
        }

        return packageCapacityTotal;
    }

    public boolean equals(Object o){
        if ( o instanceof Train ){
            if ( this.getPackageCapacity() == ((Train)o).getPackageCapacity() ){
                return true;
            }
        }
        return false;
    }
}

interface Carriage {
    int getPackageCapacity();
}

class PassengersCarA implements Carriage {
    private int passagerCapacity = 40;
    private int packageCapacity = 300;
    
    public int getPackageCapacity(){
        return this.packageCapacity;
    }

    public void openDoors(){
        System.out.println("Doors Open!");
    }
    
    public void closeDoors(){
        System.out.println("Doors Closed!");
    }
}

class PassengersCarB implements Carriage {
    private int passagerCapacity = 50;
    private int packageCapacity = 400;

    public int getPackageCapacity(){
        return this.packageCapacity;
    }

    public void openDoors(){
        System.out.println("Doors Open!");
    }
    
    public void closeDoors(){
        System.out.println("Doors Closed!");
    }

    public void blockWindows(){
        System.out.println("Windows Blocked!");
    }
}

class LoadsCar implements Carriage {
    private int packageCapacity = 400;
    
    public int getPackageCapacity(){
        return this.packageCapacity;
    }
}

public class Prob6_2 {
    public static void main(String[] args){
        Train t1 = new Train(new PassengersCarA(), new PassengersCarB());
        Train t2 = new Train(new LoadsCar(), new PassengersCarA());
        Train t3 = new Train(new PassengersCarA(), new PassengersCarB(), new LoadsCar());

        if ( t1.equals(t2) ){
            System.out.println("t1 == t2");
        }
        else {
            System.out.println("t1 != t2");
        }

        if ( t2.equals(t3) ){
            System.out.println("t2 == t3");
        }
        else {
            System.out.println("t2 != t3");
        }

        if ( t3.equals(t1) ){
            System.out.println("t3 == t1");
        }
        else {
            System.out.println("t3 != t1");
        }
    }
}
