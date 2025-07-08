#ifndef SHOWCASEBOOK_H
#define SHOWCASEBOOK_H
#include "Book.h"

class ShowcaseBook : public Book {
public:
    ShowcaseBook(string i, string t, string a, int y);
    bool is_for_sale() override;
};

#endif
