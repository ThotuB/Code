import java.util.*;

abstract class Teacher {
    protected String name;
    protected double salary;

    public Teacher(String name){
        this.name=name;
        this.salary=getSalary();
    }

    public abstract double getSalary();

    public boolean equals(Object o){
        if(o instanceof Teacher){
            return((Teacher)o).name.equals(name);
        }
        return false;
    }
}

class HourlyTeacher extends Teacher{
    private static int workedHours = 20;

    public HourlyTeacher(String name){
        super(name);
    }
    public double getSalary(){
        return workedHours * 60;
    }
    public int getWorkedHours(){
        return workedHours;
    }
}

class PermanentTeacher extends Teacher{
    public PermanentTeacher(String name){
        super(name);
    }

    public double getSalary(){
        return 3200.5;
    }
}

class Test{
    public static void main(String[] args){
        Teacher t1= new PermanentTeacher("Mike");
        Teacher t2= new PermanentTeacher("Joe");
        Teacher t3= new HourlyTeacher("Raphael");
        Teacher t4= new HourlyTeacher("Johnny");
        Teacher t5= new HourlyTeacher("Mike");
        
        System.out.println( t1 );
    }
}