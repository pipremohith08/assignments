#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    string department;
    double baseSalary;

public:
    Employee()
    {
        id = 0;
        name = "Unknown";
        department = "Not Assigned";
        baseSalary = 0;
    }
    Employee(int i, string n)
    {
        id = i;
        name = n;
        department = "Not Assigned";
        baseSalary = 0;
    }
    Employee(int i, string n, string d, double salary)
    {
        id = i;
        name = n;
        department = d;
        baseSalary = salary;
    }
    Employee(const Employee &e)
    {
        id = e.id;
        name = e.name;
        department = e.department;
        baseSalary = e.baseSalary;
    }
    double calculatePay()
    {
        return baseSalary;
    }
    double calculatePay(double bonus)
    {
        return baseSalary + bonus;
    }
    double calculatePay(int hours, double rate)
    {
        return baseSalary + (hours * rate);
    }
    double calculatePay(double bonus, double taxPercentage)
    {
        double total = baseSalary + bonus;
        double tax = total * taxPercentage / 100;

        return total - tax;
    }
    void updateProfile(string d)
    {
        department = d;
    }

    // updateProfile() - Update Salary
    void updateProfile(double salary)
    {
        baseSalary = salary;
    }
    void updateProfile(string d, double salary)
    {
        department = d;
        baseSalary = salary;
    }
    void display()
    {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Base Salary: " << baseSalary << endl;
    }
};

int main()
{
    Employee e1;
    Employee e2(101, "Mohith");
    Employee e3(102, "vishal", "CSE", 50000);
    Employee e4(e3);

    cout << "Employee 3 Details:" << endl;
    e3.display();

    cout << "\n Calculate Pay->  " << endl;

    cout << "Base Salary: "
         << e3.calculatePay() << endl;

    cout << "Salary + Bonus: "
         << e3.calculatePay(5000.0) << endl;

    cout << "Salary + Overtime: "
         << e3.calculatePay(10, 500.0) << endl;

    cout << "Salary + Bonus - Tax: "
         << e3.calculatePay(5000.0, 10.0) << endl;

    cout << "\n Updating Profile -> " << endl;
    e3.updateProfile("BSE-Nursing");
    e3.updateProfile(60000.0);
    e3.updateProfile("Data Science", 70000.0);

    e3.display();

    return 0;
}

