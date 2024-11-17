#include <iostream>
using namespace std;

class Employee {
    int emp_id;
    string name;
    int contact;

public:
    int index;
    Employee() {
        emp_id = -1;
        name = "";
        contact = -1;
        index = -1;
    }
    void setID(int id) { emp_id = id; }
    void setName(string n) { name = n; }
    void setContact(int c) { contact = c; }
    void setIndex(int i) { index = i; }

    int getID() { return emp_id; }
    void setEmployee(int id, string empName, int empContact, int empIndex) {
        emp_id = id;
        name = empName;
        contact = empContact;
        index = empIndex;
    }
    void printEmployee() {
        if (index != -1) {
            cout << "Details: " << emp_id << " - " << name << " - " << contact << endl;
        }
    }
};

class HashTable {
    int tableSize;
    Employee* ht;

public:
    HashTable(int size) {
        tableSize = size;
        ht = new Employee[tableSize];
    }
    int hash(int value) {
        return (value % tableSize);
    }
    void insertIntoHT(int emp_id, string N, int contact) {
        int ToBeInsertedAt = hash(emp_id);
        if (ht[ToBeInsertedAt].index == -1) { // position is empty, can insert here
            ht[ToBeInsertedAt].setEmployee(emp_id, N, contact, ToBeInsertedAt);
        }
        else {
            for (int i = 0; i < tableSize; i++) {
                ToBeInsertedAt = (ToBeInsertedAt + 1) % tableSize;

                if (ht[ToBeInsertedAt].index == -1) {
                    ht[ToBeInsertedAt].setEmployee(emp_id, N, contact, ToBeInsertedAt);
                    return;
                }
            }
            cout << "HashTable is full" << endl;
        }
    }
    void searchInHT(int emp_id) {
        int ToBeInsertedAt = hash(emp_id);
        if (ht[ToBeInsertedAt].getID() == emp_id) { // data found
            ht[ToBeInsertedAt].printEmployee();
        }
        else {
            for (int i = 0; i < tableSize; i++) {
                ToBeInsertedAt = (ToBeInsertedAt + 1) % tableSize;

                if (ht[ToBeInsertedAt].getID() == emp_id) {
                    ht[ToBeInsertedAt].printEmployee();
                    return;
                }
            }
            cout << emp_id << ": Details not found" << endl;
        }
    }
    void displayHT() {
        for (int i = 0; i < tableSize; i++)
            ht[i].printEmployee();
    }
};

int main() {
    int tableSize, choice, emp_id, contact;
    string name;

    cout << "Enter hash table size: ";
    cin >> tableSize;
    HashTable ht1(tableSize);

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> emp_id;
                cout << "Enter Employee Name: ";
                cin >> name;
                cout << "Enter Employee Contact: ";
                cin >> contact;
                ht1.insertIntoHT(emp_id, name, contact);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> emp_id;
                ht1.searchInHT(emp_id);
                break;

            case 3:
                cout << "Hash Table contents:\n";
                ht1.displayHT();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
