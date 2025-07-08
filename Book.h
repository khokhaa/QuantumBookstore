#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book {
public:
    string isbn;
    string title;
    string author;
    int year;
    double price;

    Book(string i, string t, string a, int y, double p);
    virtual bool is_for_sale();
    virtual bool buy(int quantity) { return false; }
    virtual void ship(string address);
    virtual void send_email(string email);

};

#endif
