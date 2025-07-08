#include "QuantumBookstore.h"
#include <iostream>

using namespace std;
const int CURRENT_YEAR = 2025;


void QuantumBookstore::add_book() {
    cout << "Quantum book store: Enter type (1=Paper,2=EBook,3=Showcase): ";
    int type;
    cin >> type;
    cin.ignore();

    cout << "Quantum book store: Enter ISBN: ";
    string isbn;
    getline(cin, isbn);

    cout << "Quantum book store: Enter title: ";
    string title;
    getline(cin, title);

    cout << "Quantum book store: Enter author: ";
    string author; getline(cin, author);

    cout << "Quantum book store: Enter year: ";
    int year; cin >> year;

    if (type == 3) {
        inventory.push_back(new ShowcaseBook(isbn, title, author, year));
        cout << "Quantum book store: Showcase book added.\n";
    } else {
        cout << "Quantum book store: Enter price: ";
        double price; cin >> price;

        if (type == 1) {
            cout << "Quantum book store: Enter quantity: ";
            int q; cin >> q;
            inventory.push_back(new PaperBook(isbn, title, author, year, price, q));
            cout << "Quantum book store: Paper book added.\n";
        } else if (type == 2) {
            cout << "Quantum book store: Enter filetype: ";
            string f; cin >> f;
            inventory.push_back(new EBook(isbn, title, author, year, price, f));
            cout << "Quantum book store: EBook added.\n";
        }
    }
}

void QuantumBookstore::remove_out_dated_books() {
    cout << "Quantum book store: Enter max age: ";
    int max_age;
    cin >> max_age;


    for (auto it = inventory.begin(); it != inventory.end();) {
        if (CURRENT_YEAR - (*it)->year > max_age) {
            cout << "Quantum book store: Removing " << (*it)->title << endl;
            delete *it;
            it = inventory.erase(it);
        } else ++it;
    }
}

void QuantumBookstore::buy_book() {
    cout << "Quantum book store: Enter ISBN: ";
    string isbn; cin >> isbn;

    cout << "Quantum book store: Enter quantity: ";
    int quan; cin >> quan;

    cout << "Quantum book store: Enter email: ";
    string email; cin >> email;

    cout << "Quantum book store: Enter address: ";
    cin.ignore(); string addr; getline(cin, addr);

    for (Book* b : inventory) {
        if (b->isbn == isbn) {
            if (!b->is_for_sale()) {
                cout << "Quantum book store: Not for sale.\n"; return;
            }
            if (PaperBook* pb = dynamic_cast<PaperBook*>(b)) {
                if (pb->quantity < quan) {
                    cout << "Quantum book store: Not enough stock.\n"; return;
                }
                pb->quantity -= quan;
                cout << "Quantum book store: Paid " << pb->price * quan << endl;
                pb->ship(addr);
                return;
            }
            if (EBook* ebook = dynamic_cast<EBook*>(b)) {
                cout << "Quantum book store: Paid " << ebook->price * quan << endl;
                ebook->send_email(email);
                return;
            }
        }
    }
    cout << "Quantum book store: Book not found.\n";
}

void QuantumBookstore::run() {
    while (true) {
        cout << "1. Add book"<<endl;
        cout << "2. Remove outdated books"<<endl;
        cout << "3. Buy book"<<endl;
        cout << "4. Exit"<<endl;

        int c;
        cin >> c;
        if (c == 1) add_book();
        else if (c == 2) remove_out_dated_books();
        else if (c == 3) buy_book();
        else if (c == 4) break;
        else cout << "Quantum book store: Invalid choice.\n";
    }
}

