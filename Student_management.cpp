#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
    int id;
    string name;
    int age;
    string course;

public:
    void input() {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);
    }

    void display() const {
        cout << left << setw(10) << id
             << setw(20) << name
             << setw(10) << age
             << setw(20) << course << endl;
    }

    int getID() const { return id; }

    void writeToFile(ofstream &out) const {
        out << id << "|" << name << "|" << age << "|" << course << endl;
    }

    bool readFromFile(ifstream &in) {
        string line;
        if (!getline(in, line)) return false;

        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        id = stoi(line.substr(0, pos1));
        name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        course = line.substr(pos3 + 1);

        return true;
    }
};

void addStudent() {
    Student s;
    s.input();
    ofstream out("students.txt", ios::app);
    s.writeToFile(out);
    out.close();
    cout << "Student added successfully!\n";
}

void displayStudents() {
    ifstream in("students.txt");
    Student s;
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Age"
         << setw(20) << "Course" << endl;
    cout << string(60, '-') << endl;
    while (s.readFromFile(in)) {
        s.display();
    }
    in.close();
}

void deleteStudent() {
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    ifstream in("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;

    while (s.readFromFile(in)) {
        if (s.getID() != id) {
            s.writeToFile(temp);
        } else {
            found = true;
        }
    }

    in.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) cout << "Student deleted successfully!\n";
    else cout << "Student not found!\n";
}

void updateStudent() {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    ifstream in("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;

    while (s.readFromFile(in)) {
        if (s.getID() == id) {
            cout << "Enter new details:\n";
            s.input();
            found = true;
        }
        s.writeToFile(temp);
    }

    in.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) cout << "Student updated successfully!\n";
    else cout << "Student not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
