#include "PaperBook.h"
#include <iostream>
using namespace std;



PaperBook::PaperBook(string i, string t, string a, int y, double p, int q)
        : Book(i, t, a, y, p) {
    quantity = q;
}

void PaperBook::ship(string address) {
    cout << "Quantum book store: Shipping paper book '" << title << "' to " << address << endl;
}
