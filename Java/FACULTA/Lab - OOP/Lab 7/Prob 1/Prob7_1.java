import java.util.ArrayList;

class Company {
    private ArrayList<Employee> employees = new ArrayList<Employee>();

    public boolean add(Employee newEmployee){
        for (int i = 0 ; i < employees.size() ; i++){
            if ( employees.contains(newEmployee) ){
                return false;
            }
        }

        employees.add(newEmployee);
        return true;
    }

    public String toString(){
        String printString = "";

        for (int i = 0 ; i < employees.size() ; i++){
            printString += employees.toString();
        }

        return printString;
    }
}

abstract class Employee {
    private String name;
    private int personalID;

    protected Employee(String name, int personalID){
        this.name = name;
        this.personalID = personalID;
    }
    
    abstract double getSalary();

    public boolean equals(Object o){
        if ( o instanceof Employee ){
            if ( ((Employee)o).name.equals(this.name) && ((Employee)o).personalID == (this.personalID) ) {
                return true;
            }
        }
        return false;
    }

    public String toString(){
        String printString = "";

        printString += "Name: " + this.name + "\n";
        printString += "Personal ID: " + this.personalID + "\n";
        printString += "Salary: " + this.getSalary() + "\n\n";

        return printString;
    }
}

class PermanentEmployee extends Employee {
    private double salary;

    public PermanentEmployee(String name, int personalID, double salary){
        super(name, personalID);

        this.salary = salary;
    }

    public double getSalary(){
        return salary;
    }
}

class HourlyPaidEmployee extends Employee {
    private int workedHours;
    private double hourlyRate;

    public HourlyPaidEmployee(String name, int personalID, double hourlyRate){
        super(name, personalID);

        this.hourlyRate = hourlyRate;
    }

    public void setWorkedHours(int workedHours){
        this.workedHours = workedHours;
    }

    public double getSalary(){
        return workedHours * hourlyRate;
    }
}

public class Prob7_1 {
    public static void main(String[] args){
        PermanentEmployee e1 = new PermanentEmployee("Gion", 5255432, 3000);
        HourlyPaidEmployee e2 = new HourlyPaidEmployee("Dani", 5436543, 50);
        e2.setWorkedHours(120);

        Company c = new Company();

        c.add(e1);
        c.add(e2);

        System.out.println(c.toString());
    }
}
