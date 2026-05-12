#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int bId, string bTitle, string bAuthor) {
        id = bId;
        title = bTitle;
        author = bAuthor;
        issued = false;
    }
};

// Member Class
class Member {
public:
    int memberId;
    string memberName;

    Member(int mId, string mName) {
        memberId = mId;
        memberName = mName;
    }
};

// Library Management System
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    // Add Book
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));

        cout << "Book Added Successfully!\n";
    }

    // Add Member
    void addMember() {
        int id;
        string name;

        cout << "\nEnter Member ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Member Name: ";
        getline(cin, name);

        members.push_back(Member(id, name));

        cout << "Member Added Successfully!\n";
    }

    // Display Books
    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo Books Available!\n";
            return;
        }

        cout << "\n----- Book List -----\n";

        for (auto &b : books) {
            cout << "ID: " << b.id << endl;
            cout << "Title: " << b.title << endl;
            cout << "Author: " << b.author << endl;
            cout << "Status: " << (b.issued ? "Issued" : "Available") << endl;
            cout << "----------------------\n";
        }
    }

    // Issue Book
    void issueBook() {
        int id;

        cout << "\nEnter Book ID to Issue: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id) {
                if (!b.issued) {
                    b.issued = true;
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book Already Issued!\n";
                }
                return;
            }
        }

        cout << "Book Not Found!\n";
    }

    // Return Book
    void returnBook() {
        int id;

        cout << "\nEnter Book ID to Return: ";
        cin >> id;

        for (auto &b : books) {
            if (b.id == id) {
                if (b.issued) {
                    b.issued = false;
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "This Book Was Not Issued!\n";
                }
                return;
            }
        }

        cout << "Book Not Found!\n";
    }

    // Search by Title
    void searchByTitle() {
        string title;

        cin.ignore();
        cout << "\nEnter Book Title to Search: ";
        getline(cin, title);

        bool found = false;

        for (auto &b : books) {
            if (b.title == title) {
                cout << "\nBook Found!\n";
                cout << "ID: " << b.id << endl;
                cout << "Author: " << b.author << endl;
                cout << "Status: " << (b.issued ? "Issued" : "Available") << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Book Not Found!\n";
        }
    }

    // Search by Author
    void searchByAuthor() {
        string author;

        cin.ignore();
        cout << "\nEnter Author Name to Search: ";
        getline(cin, author);

        bool found = false;

        for (auto &b : books) {
            if (b.author == author) {
                cout << "\nBook Found!\n";
                cout << "ID: " << b.id << endl;
                cout << "Title: " << b.title << endl;
                cout << "Status: " << (b.issued ? "Issued" : "Available") << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No Books Found By This Author!\n";
        }
    }
};

// Main Function
int main() {
    Library lib;
    int choice;

    do {
        cout << "\n========== Library Management System ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display Books\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Search Book by Title\n";
        cout << "7. Search Book by Author\n";
        cout << "8. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;

            case 2:
                lib.addMember();
                break;

            case 3:
                lib.displayBooks();
                break;

            case 4:
                lib.issueBook();
                break;

            case 5:
                lib.returnBook();
                break;

            case 6:
                lib.searchByTitle();
                break;

            case 7:
                lib.searchByAuthor();
                break;

            case 8:
                cout << "\nThank You for Using Library Management System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 8);

    return 0;
}