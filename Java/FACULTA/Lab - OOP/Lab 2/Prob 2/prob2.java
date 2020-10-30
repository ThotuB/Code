class prob2 {
  public static void main(String[] args){
    Engine e1, e2;
    e1 = new Engine(5);
    e2 = e1;
    e2.setCapacity(10);
    e1.print();
  }
}

class Engine {
  private int capacity;

  public Engine(int c) {
    capacity = c;
  }

  public void setCapacity(int c) {
    capacity = c;
  }

  public void print() {
    System.out.println("My capacity is " + capacity);
 }
}
