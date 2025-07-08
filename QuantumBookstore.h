#ifndef UNTITLED18_QUANTUMBOOKSTORE_H
#define UNTITLED18_QUANTUMBOOKSTORE_H
#include "PaperBook.h"
#include "EBook.h"
#include "ShowcaseBook.h"
#include <vector>
#include <string>
using namespace std;


class QuantumBookstore {
private:
    vector<Book*> inventory;  // pointer to base class Book
    const int CURRENT_YEAR = 2025;

public:
    void add_book();
    void remove_out_dated_books();
    void buy_book();
    void run();
    void list_inventory();

};

