#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string i, string t, string a, int y, double p) {
    isbn = i;
    title = t;
    author = a;
    year = y;
    price = p;
}

bool Book::is_for_sale() { return true; }
void Book::ship(string address) {}
void Book::send_email(string email) {}
