#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

#pragma region Classes
class Employee { // base class
private:
    int id;
protected:
    string name;
    float salary;
public:
    // Constructor
    Employee(int id, string name, float salary) {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }
    // Destructor
    ~Employee() { cout << "Destructor : on" << endl; }
    // set methods
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setSalary(float salary) { this->salary = salary; }
    // get methods
    int getId() { return this->id; }
    string getName() { return this->name; }
    float getSalary() { return this->salary; }
    // virtual method for displaying info
    virtual void showInfo() {
        cout << "\n == Basic Information ==" << endl;
        cout << "ID: " << this->id << " | Name: " << this->name << " | Salary: " << this->salary << " RSD ";
    }
    virtual void increaseSalary(float amount) { this->salary += amount; }
};

class Worker : public Employee { // Inheritance
private:
    string position;
public:
    // constructor
    Worker(string position, int id, string name, float salary) : Employee(id, name, salary) {
        this->position = position;
    }
    // setters
    void setPosition(string position) { this->position = position; }
    // getters
    string getPosition() { return this->position; }
    void showInfo() override {
        Employee::showInfo();
        cout << " | Position: " << this->position;
    }
    void increaseSalary(float amount) override {
        float tax = amount * 0.15f;
        salary += (amount - tax);
    }
};

class Manager : public Employee { // derived class
private:
    float bonus;
public:
    // constructor
    Manager(float bonus, int id, string name, float salary) : Employee(id, name, salary) {
        this->bonus = bonus;
    }
    // setters
    void setBonus(float bonus) { this->bonus = bonus; }
    // getters
    float getBonus() { return this->bonus; }
    // polymorphism
    void showInfo() override {
        Employee::showInfo();
        cout << " | Bonus: " << this->bonus;
    }
    void increaseSalary(float amount) override {
        salary += (amount + this->bonus);
    }
};

//Const MAX = 100 -> 100 slots for employees
#define MAX 100

class Project {
private:
    string name;
    string deadline;
    Employee* employeesOnProject[MAX];
    int employeeCount;
public:
    // constructor
    Project(string name, string deadline) {
        this->name = name;
        this->deadline = deadline;
        this->employeeCount = 0;
    }
    // methods
    void addEmployee(Employee* e) {
        if (employeeCount >= MAX) {
            cout << "!= No space for more employees =!" << endl;
            return;
        }
        // check if employee with that ID already exists in project
        for (int i = 0; i < employeeCount; i++) {
            if (employeesOnProject[i]->getId() == e->getId()) {
                cout << "Employee with ID " << e->getId() << " already exists in project!" << endl;
                return;
            }
        }
        employeesOnProject[employeeCount++] = e;
        cout << "Employee with ID " << e->getId() << " added to project." << endl;
    }
    bool removeEmployee(int id) {
        for (int i = 0; i < employeeCount; i++) {
            if (employeesOnProject[i]->getId() == id) {
                // shift all after i one place back
                for (int j = i; j < employeeCount - 1; j++) {
                    employeesOnProject[j] = employeesOnProject[j + 1];
                }
                employeesOnProject[employeeCount - 1] = nullptr;
                employeeCount--;
                return true;
            }
        }
        return false; // employee with that id not found
    }
    void showProject() const {
        cout << "Project: " << this->name << ", deadline: " << this->deadline << endl;
        cout << "Employees on project: " << employeeCount << endl;
        for (int i = 0; i < employeeCount; i++) {
            employeesOnProject[i]->showInfo();
        }
    }
    string getName() {
        return this->name;
    }
};
#pragma endregion

void printCentered(string text) { 
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); 
    int consoleWidth = csbi.dwSize.X; int padding = (consoleWidth - text.length()) / 2; 
    if (padding < 0) padding = 0; cout << string(padding, ' ') << text << endl; 
}

void setColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }

int validateInput(string message) {
    int number;
    cout << message;
    while (!(cin >> number)) {
        setColor(12);
        cout << "Invalid input. Try again: ";
        setColor(7);
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return number;
}

void Menu() {
    cout << endl;
    printCentered("+-------------------------------+");
    printCentered("|   --- INTERACTIVE MENU ---    |");
    printCentered("|  0.Exit                       |");
    printCentered("|  1.Add worker                 |");
    printCentered("|  2.Add manager                |");
    printCentered("|  3.Add project                |");
    printCentered("|  4.Increase salary            |");
    printCentered("|  5.Show info                  |");
    printCentered("|  6.Remove employee            |");
    printCentered("|  7.Remove project             |");
    printCentered("|  8.Assign employee(project)   |");
    printCentered("|  9.Search employee(name)      |");
    printCentered("|  10.Search employee(id)       |");
    printCentered("|  11.Search worker position    |");
    printCentered("|  12.Average salary employees  |");
    printCentered("|  13.Average salary workers    |");
    printCentered("|  14.Average salary managers   |");
    printCentered("+-------------------------------+");
    cout << endl;
}

int main() {
    const int MAX_R = 100;
    Worker* workers[MAX_R];
    Manager* managers[MAX_R];
    Project* projects[MAX_R];
    int choice;
    int workerCount = 0, managerCount = 0, projectCount = 0;
    bool taken;
#pragma region Options
    setColor(2);
    printCentered("============= MADE BY MIHAJLO =============");
    setColor(7);
    do {
        Menu();
        choice = validateInput("Enter choice: "); 
        cout << "------------------------------" << endl;
        if (choice >= 0 && choice <= 14) {
            if (choice == 1) {
                int id;
                int numW; cout << "Enter number of workers: "; cin >> numW;
                for (int i = 0; i < numW; i++) {
                    string name, position;
                    float salary;
                    cout << "------------------------------" << endl;
                    cout << "Worker #" << i + 1 << endl;
                    do {
                        taken = false;
                        id = validateInput("ID: ");

                        for (int j = 0; j < workerCount; j++) {
                            if (workers[j]->getId() == id) {
                                setColor(14);
                                cout << "ID is already taken by a worker!" << endl;
                                setColor(7);
                                taken = true;
                                break;
                            }
                        }

                        for (int j = 0; j < managerCount && !taken; j++) {
                            if (managers[j]->getId() == id) {
                                setColor(14);
                                cout << "ID is already taken by a manager!" << endl;
                                setColor(7);
                                taken = true;
                                break;
                            }
                        }
                    } while (taken);
                    cout << "Name: "; cin.ignore(); getline(cin, name);
                    cout << "Salary (RSD): "; cin >> salary;
                    cout << "Position: "; cin.ignore(); getline(cin, position);
                    cout << "------------------------------" << endl;
                    setColor(10);
                    cout << "Worker " << name << " added..." << endl;
                    setColor(7);
                    workers[workerCount++] = new Worker(position, id, name, salary);

                }
            }
            else if (choice == 2) {
                float bonus;
                int id;
                string name;
                float salary;
                int numM;
                cout << "Enter number of managers: "; cin >> numM;
                for (int i = 0; i < numM; i++) {
                    cout << "------------------------------" << endl;
                    cout << "Manager #" << i + 1 << endl;
                    do {
                        taken = false;
                        id = validateInput("ID: ");

                        for (int j = 0; j < workerCount; j++) {
                            if (workers[j]->getId() == id) {
                                cout << "ID is already taken by a worker!" << endl;
                                taken = true;
                                break;
                            }
                        }

                        for (int j = 0; j < managerCount && !taken; j++) {
                            if (managers[j]->getId() == id) {
                                cout << "ID is already taken by a manager!" << endl;
                                taken = true;
                                break;
                            }
                        }
                    } while (taken);
                    cout << "Name: "; cin.ignore(); getline(cin, name);
                    cout << "Salary (RSD): "; cin >> salary;
                    cout << "Bonus (RSD): "; cin >> bonus;
                    cout << "------------------------------" << endl;
                    setColor(10);
                    cout << "Manager " << name << " added..." << endl;
                    setColor(7);
                    managers[managerCount++] = new Manager(bonus, id, name, salary);
                }
            }
            else if (choice == 3) {
                string name, deadline;
                int numP;
                cout << "Enter number of projects: "; cin >> numP;
                cin.ignore();
                for (int i = 0; i < numP; i++) {
                    cout << "------------------------------" << endl;
                    cout << "Project #" << i + 1 << endl;
                    cout << "Project name: "; getline(cin, name);
                    cout << "Project deadline: "; getline(cin, deadline);
                    setColor(10);
                    cout << "------------------------------" << endl;
                    cout << "Project /" << name << "/ added..." << endl;
                    cout << "------------------------------" << endl;
                    setColor(7);
                    projects[projectCount++] = new Project(name, deadline);
                }
            }
            else if (choice == 4) {
                int idIncrease;
                float amount;
                cout << "Enter employee ID: ";
                cin >> idIncrease;
                cout << "Enter amount to increase: ";
                cin >> amount;

                bool found = false;

                for (int i = 0; i < workerCount; i++) {
                    if (workers[i]->getId() == idIncrease) {
                        workers[i]->increaseSalary(amount);
                        cout << "Salary increased!" << endl;
                        found = true;
                        break;
                    }
                }
                for (int i = 0; i < managerCount; i++) {
                    if (managers[i]->getId() == idIncrease) {
                        managers[i]->increaseSalary(amount);
                        cout << "Salary increased!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << endl;
                    setColor(12);
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    cout << "EMPLOYEE WITH THAT ID NOT FOUND." << endl;
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    setColor(7);
                    cout << endl;
                }
            }
            else if (choice == 5) {
                cout << endl;
                cout << "=== WORKERS ===" << endl;
                for (int i = 0; i < workerCount; i++) {
                    workers[i]->showInfo();
                }
                cout << endl;
                cout << "=== MANAGERS ===" << endl;
                for (int i = 0; i < managerCount; i++) {
                    managers[i]->showInfo();
                }
                cout << endl;
                cout << "=== PROJECTS ===" << endl;
                for (int i = 0; i < projectCount; i++) {
                    projects[i]->showProject();
                }
                cout << endl;
            }
            else if (choice == 6) {
                int id; cout << "Enter ID of employee you want to remove: "; cin >> id;
                bool found = false;
                for (int i = 0; i < workerCount; i++) {
                    if (workers[i]->getId() == id) {
                        for (int k = 0; k < projectCount; k++) {
                            projects[k]->removeEmployee(id);
                        }
                        delete workers[i];
                        for (int j = i; j < workerCount - 1; j++) {
                            workers[j] = workers[j + 1];
                        }
                        workers[workerCount - 1] = nullptr;
                        workerCount--;
                        found = true;
                        setColor(10);
                        cout << "------------------------------" << endl;
                        cout << "Worker with ID " << id << " removed." << endl;
                        cout << "------------------------------" << endl;
                        setColor(7);
                        break;
                    }
                }
                if (!found) {
                    for (int i = 0; i < managerCount; i++) {
                        if (managers[i]->getId() == id) {
                            for (int k = 0; k < projectCount; k++) {
                                projects[k]->removeEmployee(id);
                            }
                            delete managers[i];
                            for (int j = i; j < managerCount - 1; j++) {
                                managers[j] = managers[j + 1];
                            }
                            managers[managerCount - 1] = nullptr;
                            managerCount--;
                            found = true;
                            setColor(10);
                            cout << "------------------------------" << endl;
                            cout << "Manager with ID " << id << " removed." << endl;
                            cout << "------------------------------" << endl;
                            setColor(7);
                        }
                    }
                }
                }
            else if (choice == 7) {
                string projectName; cout << "Enter name of project you want to remove: ";
                cin.ignore(); getline(cin, projectName);
                bool foundP = false;
                for (int i = 0; i < projectCount; i++) {
                    if (projects[i]->getName() == projectName) {
                        delete projects[i];
                        for (int j = i; j < projectCount - 1; j++) {
                            projects[j] = projects[j + 1];
                        }
                        projects[--projectCount] = nullptr;
                        cout << endl;
                        cout << "------------------------------" << endl;
                        setColor(10);
                        cout << "Project /" << projectName << "/ removed." << endl;
                        setColor(7);
                        foundP = true;
                        break;
                    }
            }
                if (!foundP) {
                    setColor(12);
                    cout << "Project with name /" << projectName << "/ not found." << endl;
                    setColor(7);
                }
            }
            else if (choice == 8) {
                int empId, projIndex;
                cout << "Enter employee ID: "; cin >> empId;
                cout << "Enter project index (0 - " << projectCount - 1 << "): "; cin >> projIndex;
                if (projIndex >= 0 && projIndex < projectCount) {
                     Employee* e = nullptr;
                     for (int i = 0; i < workerCount; i++) {
                          if (workers[i]->getId() == empId) e = workers[i];
                     }
                     for (int i = 0; i < managerCount; i++) {
                          if (managers[i]->getId() == empId) e = managers[i];
                     }
                     if (e != nullptr) {
                         projects[projIndex]->addEmployee(e);
                         cout << "------------------------------" << endl;
                     }
                     else {
                         setColor(12);
                         cout << "Employee not found." << endl;
                         setColor(7);
                     }
                }
                else {
                    cout << endl;
                    setColor(12);
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    cout << "NON-EXISTENT PROJECT" << endl;
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    setColor(7);
                    cout << endl;
                }
            }
            else if (choice == 9) {
                string searchName; cout << "Enter employee name: ";
                cin.ignore(); getline(cin, searchName);
                bool foundName = false;
                cout << "------------------------------" << endl;
                cout << "Search results:" << endl;
                setColor(1);
                for (int i = 0; i < workerCount; i++) {
                    if (workers[i]->getName() == searchName) {
                        workers[i]->showInfo();
                        foundName = true;
                    }
                }
                for (int i = 0; i < managerCount; i++) {
                    if (managers[i]->getName() == searchName) {
                        managers[i]->showInfo();
                        foundName = true;
                    }
                }
                setColor(7);
                if (!foundName) {
                    setColor(12);
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    cout << "EMPLOYEE WITH NAME " << searchName << " NOT FOUND." << endl;
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    setColor(7);
                }
            }
            else if (choice == 10) {
                int searchId; cout << "Enter employee ID: "; cin >> searchId;
                bool foundId = false;
                cout << "------------------------------" << endl;
                cout << "Search results:" << endl;
                for (int i = 0; i < workerCount; i++) {
                    if (workers[i]->getId() == searchId) {
                        workers[i]->showInfo();
                        foundId = true;
                    }
                }
                for (int i = 0; i < managerCount; i++) {
                    if (managers[i]->getId() == searchId) {
                        managers[i]->showInfo();
                        foundId = true;
                    }
                }
                if (!foundId) {
                    setColor(12);
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    cout << "EMPLOYEE WITH ID " << searchId << " NOT FOUND." << endl;
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    setColor(7);
                }
                }
            else if (choice == 11) {
                string position; cout << "Enter worker position: ";
                cin.ignore(); getline(cin, position);
                bool foundPos = false;
                cout << "------------------------------" << endl;
                cout << "Search results:" << endl;
                for (int i = 0; i < workerCount; i++) {
                    if (workers[i]->getPosition() == position) {
                        workers[i]->showInfo();
                        foundPos = true;
                    }
                }
                if (!foundPos) {
                    setColor(12);
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    cout << "WORKER WITH POSITION " << position << " NOT FOUND." << endl;
                    cout << "-!---!---!---!---!---!---!-" << endl;
                    setColor(7);
                }
                }
            else if (choice == 12) {
                float sum = 0;
                int totalEmployees = workerCount + managerCount;
                for (int i = 0; i < workerCount; i++) sum += workers[i]->getSalary();
                for (int i = 0; i < managerCount; i++) sum += managers[i]->getSalary();
                if (totalEmployees > 0) {
                    float avg = sum / totalEmployees;
                    cout << "Average salary of all employees: " << avg << " RSD." << endl;
                }
                else {
                    setColor(6);
                    cout << "No employees currently..." << endl;
                    setColor(7);
                }
                }
            else if (choice == 13) {
                float sumWorkers = 0;
                for (int i = 0; i < workerCount; i++) sumWorkers += workers[i]->getSalary();
                if (workerCount > 0) {
                    float avgWorkers = sumWorkers / workerCount;
                    cout << "Average salary of workers: " << avgWorkers << " RSD." << endl;
                }
                else {
                    setColor(6);
                    cout << "No workers currently..." << endl;
                    setColor(7);
                }
                }
            else if (choice == 14) {
                float sumManagers = 0;
                for (int i = 0; i < managerCount; i++) sumManagers += managers[i]->getSalary();
                if (managerCount > 0) {
                    float avgManagers = sumManagers / managerCount;
                    cout << "Average salary of managers: " << avgManagers << " RSD." << endl;
                }
                else {
                    setColor(6);
                    cout << "No managers currently..." << endl;
                    setColor(7);
                }
            }
        }
        else {
            cout << "Enter choice (number) in range 1 to 14" << endl;
            cout << "-------------------------------------" << endl;
        }
    } while (choice != 0);
    setColor(10);
    cout << "Exit..." << endl;
    setColor(7);
    cout << "------------------------------" << endl; 
#pragma endregion
    return 0;
}
