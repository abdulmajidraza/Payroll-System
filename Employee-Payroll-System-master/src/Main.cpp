#include <bits/stdc++.h>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string name, int id) {
        this->name = name;
        this->id = id;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    virtual double calculateSalary() = 0;

    virtual void display() {
        cout << "Name: " << name 
             << " | ID: " << id 
             << " | Salary: " << calculateSalary() << endl;
    }

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double monthlySalary;

public:
    FullTimeEmployee(string name, int id, double salary)
        : Employee(name, id) {
        monthlySalary = salary;
    }

    double calculateSalary() {
        return monthlySalary;
    }
};

class PartTimeEmployee : public Employee {
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(string name, int id, int hours, double rate)
        : Employee(name, id) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }
};

class PayrollSystem {
    vector<Employee*> employees;

public:

    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void removeEmployee(int id) {
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->getId() == id) {
                delete employees[i];
                employees.erase(employees.begin() + i);
                cout << "Employee removed successfully\n";
                return;
            }
        }
        cout << "Employee not found\n";
    }

    void displayEmployees() {
        if (employees.empty()) {
            cout << "No employees found\n";
            return;
        }

        for (auto emp : employees) {
            emp->display();
        }
    }

    ~PayrollSystem() {
        for (auto emp : employees)
            delete emp;
    }
};

int main() {

    PayrollSystem payroll;
    int choice;

    while (true) {

        cout << "\n---- Payroll System ----\n";
        cout << "1. Add Full Time Employee\n";
        cout << "2. Add Part Time Employee\n";
        cout << "3. Remove Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            string name;
            int id;
            double salary;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Monthly Salary: ";
            cin >> salary;

            payroll.addEmployee(new FullTimeEmployee(name, id, salary));
        }
        else if (choice == 2) {

            string name;
            int id, hours;
            double rate;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Hours Worked: ";
            cin >> hours;

            cout << "Enter Hourly Rate: ";
            cin >> rate;

            payroll.addEmployee(new PartTimeEmployee(name, id, hours, rate));
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Employee ID to remove: ";
            cin >> id;
            payroll.removeEmployee(id);
        }
        else if (choice == 4) {
            payroll.displayEmployees();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}