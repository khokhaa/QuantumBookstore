#ifndef PAPERBOOK_H
#define PAPERBOOK_H
#include "Book.h"

class PaperBook : public Book {
public:
    int quantity;
    bool buy(int q) {
        if (quantity >= q) {
            quantity -= q;
            return true;
        }
        return false;
    }
    PaperBook(string i, string t, string a, int y, double p, int q);
    void ship(string address) override;
};

#endif
