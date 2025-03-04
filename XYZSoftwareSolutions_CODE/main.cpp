#include <iostream>
#include <vector>
using namespace std;

struct Employee {
  private:
    string Name;
    string EmployeeID;
    double Salary;
  public:
    // Constructor
    Employee(string name, string id, double salary)
        : Name(name), EmployeeID(id), Salary(salary) {}

    // virtual destructor for cleanup in polymorphism
    virtual ~Employee(){}

    // Getter methods
    string getName(){
        return Name;
    }

    string getID(){
        return EmployeeID;
    }

    double getSalary(){
        return Salary;
    }

    // Setter methods
    void setName(string n){
        Name = n;
    }

    void setID(string eID){
        EmployeeID = eID;
    }

    void setSalary(double s){
        if(s >= 0){
            Salary = s;
        } else{
            cout << "Invalid Salary Amount" << endl;
        }
    }

    // Input Details
    virtual void inputEmployeeDetails(string n, string eID, double s){
        Name = n;
        EmployeeID = eID;
        Salary = s;
    }

    // Display method
    virtual void displayEmployeeDetails(){
        cout << "Employee Name: " << Name << endl;
        cout << "Employee ID: " << EmployeeID << endl;
        cout << "Salary: " << Salary << endl;
    }
};

class Manager : public Employee {
private:
    string Department;
    double Bonus;
public:
    // Constructor
    Manager(string name, string id, double salary, string department, double bonus)
        : Employee(name, id, salary), Department(department), Bonus(bonus) {}

    // getter methods
    string getDepartment(){
        return Department;
    }

    double getBonus(){
        return Bonus;
    }

    // setter methods
    void setDepartment(string d){
        Department = d;
    }

    void setBonus(double b){
        if(b >= 0){
            Bonus = b;
        } else{
            cout << "Invalid Bonus amount" << endl;
        }
    }

    // Input employee Details
    void inputEmployeeDetails(string n, string eID, double s) override {
        Employee::inputEmployeeDetails(n, eID, s);
    }

    // Input manager details
    void inputManagerDetails(string d, double b){
        Department = d;
        Bonus = b;
    }

    // Display Details
    void displayEmployeeDetails() override {
        Employee::displayEmployeeDetails();
        cout << "Manager Department: " << Department << endl;
        cout << "Manager Bonus: " << Bonus << endl;
    }
};

class Engineer : public Employee {
private:
    string Specialization;
    string ProjectAssigned;
public:
    // Constructor
    Engineer(string n, string id, double s, string special, string project)
        : Employee(n, id, s), Specialization(special), ProjectAssigned(project) {}

    // getter methods
    string getSpecialization(){
        return Specialization;
    }

    string getProjectAssigned(){
        return ProjectAssigned;
    }

    // setter methods
    void setSpecialization(string s){
        Specialization = s;
    }

    void setProjectAssigned(string p){
        ProjectAssigned = p;
    }

    // Input Employee Details
    void inputEmployeeDetails(string n, string eID, double s) override {
      Employee::inputEmployeeDetails(n,eID,s);
    }

    // Input Engineer Details
    void inputEngineerDetails(string s, string p){
        Specialization = s;
        ProjectAssigned = p;
    }

    // Display Manager details
    void displayEmployeeDetails() override {
        Employee::displayEmployeeDetails();
        cout << "Engineer Specialization: " << Specialization << endl;
        cout << "Engineer Project Assigned: " << ProjectAssigned << endl;
    }
};

class EmployeeManagementSystem {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* emp){
        employees.push_back(emp);
    }

    void displayAllEmployees(){
        if(employees.empty()){
            cout << "No employees in the system." << endl;
            return;
        }
        cout << "----- Employee List -----" << endl;
        for(Employee* emp : employees){
            emp->displayEmployeeDetails();
            cout << "-----------------" << endl;
        }
    }

    void searchEmployeeByID(string id){
        for(Employee* emp : employees){
            if(emp->getID()==id){
                cout << "Employee Found:" << endl;
                emp->displayEmployeeDetails();
                return;
            }
        }
        cout << "Employee with ID" << id << " not found." << endl;
    }

    // Destructor
    ~EmployeeManagementSystem(){
         cout << "Destroying Employee Management System..." << endl;
        for (Employee* emp : employees) {
            delete emp; // Free allocated memory
        }
        employees.clear();
        cout << "All Employees Deleted." << endl;

    }

};

int main()
{
    EmployeeManagementSystem ems;

    // Adding Employees
    ems.addEmployee(new Manager("Keith Kipruto", "MGR101", 90000, "IT", 15000));
    ems.addEmployee(new Engineer("Bob Wafula", "ENG202", 75000, "Software Engineering", "AI Project"));
    ems.addEmployee(new Employee("Charlie Kioko", "EMP303", 50000));

    // Display all employees
    cout << "\nDisplaying All Employees:\n";
    ems.displayAllEmployees();

    // Search for an employee
    cout << "\nSearching for Employee ID 'ENG202':\n";
    ems.searchEmployeeByID("ENG202");
    delete &ems;
    return 0;
}
