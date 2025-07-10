#include<iostream>
using namespace std;

class Book {
private:
    int qty;
    string title, author, code;

public:
    void inputData() {
        cin.ignore();  
        cout << "Enter Book's code: ";
        getline(cin, code);
        cout << "Enter Book's title: ";
        getline(cin, title);
        cout << "Enter Book's author: ";
        getline(cin, author);
        cout << "Enter quantity: ";
        cin >> qty;
    }

    void displayData() {
        cout << "----------------------------\n";
        cout << "Code    : " << code << endl;
        cout << "Title   : " << title << endl;
        cout << "Author  : " << author << endl;
        cout << "Quantity: " << qty << endl;
    }

    bool searchData(string query) {
        return (query == title || query == code || query == author);
    }

    bool searchData(int q) {
        return (q == qty);
    }

    void updateQuantity(int change) {
        if (qty + change < 0) {
            cout << "Error: Quantity cannot go negative.\n";
        } else {
            qty += change;
            cout << "Quantity updated. New quantity: " << qty << endl;
        }
    }
};

int main() {
    int n, choice, change, temp;
    string query, c;
    bool found, update;

    cout << "Enter number of Books you want to add initially: ";
    cin >> n;
    Book* b = new Book[n];

    do {
        cout << "\n---- Library Menu ----" << endl;
        cout << "1. Enter book data" << endl;
        cout << "2. Display all books" << endl;
        cout << "3. Search by title / author / code" << endl;
        cout << "4. Search by quantity" << endl;
        cout << "5. Update book quantity" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < n; i++) {
                cout << "\nBook #" << i + 1 << ":" << endl;
                b[i].inputData();
            }
        }

        else if (choice == 2) {
            for (int i = 0; i < n; i++) {
                b[i].displayData();
            }
        }

        else if (choice == 3) {
            cin.ignore();
            cout << "Enter title / author / code to search: ";
            getline(cin, query);

            found = false;
            for (int i = 0; i < n; i++) {
                if (b[i].searchData(query)) {
                    b[i].displayData();
                    found = true;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }

        else if (choice == 4) {
            int q;
            cout << "Enter quantity to search: ";
            cin >> q;

            found = false;
            for (int i = 0; i < n; i++) {
                if (b[i].searchData(q)) {
                    b[i].displayData();
                    found = true;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }

        else if (choice == 5) {
            cin.ignore();
            cout << "Enter book code to update quantity: ";
            getline(cin, c);

            update = false;
            for (int i = 0; i < n; i++) {
                if (b[i].searchData(c)) {
                    cout << "1. Add books\n2. Remove books\nEnter your choice: ";
                    cin >> temp;
                    if (temp == 1) {
                        cout << "Enter quantity to add: ";
                        cin >> change;
                        b[i].updateQuantity(change);
                        update = true;
                    } else if (temp == 2) {
                        cout << "Enter quantity to remove: ";
                        cin >> change;
                        b[i].updateQuantity(-change);
                    } else {
                        cout << "Invalid option.\n";
                    }
                    break;
                }
            }
            if (!update)
                cout << "Book not found. No update performed.\n";
        }

        else if (choice != 6) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    delete[] b;  
    cout << "Library system closed.\n";
    return 0;
}
