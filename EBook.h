#ifndef EBOOK_H
#define EBOOK_H
#include "Book.h"

class EBook : public Book {
public:
    string filetype;
    EBook(string i, string t, string a, int y, double p, string f);

    void send_email(string email) override;
};

#endif
