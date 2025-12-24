#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int roll;
    char name[50];
    char branch[30];

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Branch: ";
        cin.getline(branch, 30);
    }

    void display() {
        cout << "\nRoll Number: " << roll;
        cout << "\nName: " << name;
        cout << "\nBranch: " << branch << endl;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();

    cout << "\nStudent added successfully!\n";
}

void viewStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
        cout << "----------------------";
    }
    file.close();
}

void searchStudent() {
    int r;
    bool found = false;
    Student s;
    ifstream file("students.dat", ios::binary);

    cout << "Enter roll number to search: ";
    cin >> r;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.roll == r) {
            s.display();
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
        cout << "\nStudent not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "\nExiting...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
