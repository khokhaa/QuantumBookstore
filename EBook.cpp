#include "EBook.h"
#include <iostream>
using namespace std;

EBook::EBook(string i, string t, string a, int y, double p, string f)
        : Book(i, t, a, y, p) {
    filetype = f;
}

void EBook::send_email(string email) {
    cout << "Quantum book store: Sending ebook '" << title << "' to " << email << endl;
}
