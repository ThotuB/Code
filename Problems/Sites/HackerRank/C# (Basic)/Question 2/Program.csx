using System.Collections.Generic;
using System.Linq;

class Employee {
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Company { get; set; }
    public int Age { get; set; }

    public Employee(string firstName, string lastName, string company, int age) {
        FirstName = firstName;
        LastName = lastName;
        Company = company;
        Age = age;
    }

    public override string ToString(){
        return $"{FirstName} {LastName} works for {Company} and is {Age} years old.";
    }
}

class Test {
    public static Dictionary<string, int> AverageAgeForEachCompany(List<Employee> employees) {
        Dictionary<string, int> count = CountOfEmployeesForEachCompany(employees);
        Dictionary<string, int> result = new Dictionary<string, int>();

        foreach (Employee employee in employees) {
            if (!result.ContainsKey(employee.Company)) {
                result.Add(employee.Company, 0);
            }
            result[employee.Company] += employee.Age;
        }

        foreach (string key in result.Keys.ToList()) {
            result[key] = result[key] / count[key];
        }

        return result;
    }
    
    public static Dictionary<string, int> CountOfEmployeesForEachCompany(List<Employee> employees) {
        Dictionary<string, int> result = new Dictionary<string, int>();

        foreach (Employee employee in employees) {
            if (!result.ContainsKey(employee.Company)) {
                result.Add(employee.Company, 1);
                continue;
            }

            result[employee.Company]++;
        }

        return result;
    }
    
    public static Dictionary<string, Employee> OldestAgeForEachCompany(List<Employee> employees) {
        Dictionary<string, Employee> result = new Dictionary<string, Employee>();
        
        foreach (Employee employee in employees) {
            if (!result.ContainsKey(employee.Company)) {
                result.Add(employee.Company, employee);
                continue;
            } 
            
            if (result[employee.Company].Age < employee.Age) {
                result[employee.Company] = employee;
            }
        }

        return result;
    }
}

class Program {
    static void PrintDict<T>(Dictionary<string, T> dict) {
        foreach (KeyValuePair<string, T> entry in dict) {
            Console.WriteLine($"{entry.Key} : {entry.Value}");
        }
    }

    public static void Main(string[] args) {
        List<Employee> employees = new List<Employee>();
        employees.Add(new Employee("John", "Smith", "Google", 30));
        employees.Add(new Employee("Jane", "Smith", "Google", 25));
        employees.Add(new Employee("John", "Doe", "Microsoft", 20));
        employees.Add(new Employee("Jane", "Doe", "Microsoft", 30));
        employees.Add(new Employee("John", "Hatz", "Apple", 40));
        employees.Add(new Employee("Jane", "Hatz", "Apple", 35));
        employees.Add(new Employee("Mark", "Hatz", "Apple", 50));

        Dictionary<string, int> averageAgeForEachCompany = Test.AverageAgeForEachCompany(employees);
        Dictionary<string, int> countOfEmployeesForEachCompany = Test.CountOfEmployeesForEachCompany(employees);
        Dictionary<string, Employee> oldestAgeForEachCompany = Test.OldestAgeForEachCompany(employees);

        PrintDict(averageAgeForEachCompany);
        PrintDict(countOfEmployeesForEachCompany);
        PrintDict(oldestAgeForEachCompany);
    }
}

Program.Main(null);