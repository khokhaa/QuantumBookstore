#include "ShowcaseBook.h"

ShowcaseBook::ShowcaseBook(string i, string t, string a, int y)
        : Book(i, t, a, y, 0) {}

bool ShowcaseBook::is_for_sale() { return false; }
