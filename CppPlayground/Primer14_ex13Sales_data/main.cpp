#include "Sales_data.h"
using namespace std;

int main()
{
    Sales_data book1("Who Moved my Cheese?", 99, 15);
    Sales_data book2("Who Moved my Cheese?", 1, 25);
    Sales_data book3("Are Your Lights On?", 100, 20);

    cout << book1 << endl;

    // Assignment
    if (book1.isbn() == book2.isbn())
        book1 = book1 + book2;
    cout << book1 << endl;

    // Compound assignment
    if (book1.isbn() == book2.isbn())
        book1 += book2;
    cout << book1 << endl;

    // Subtraction
    if (book1.isbn() == book2.isbn())
        book1 = book1 - book2;
    cout << book1 << endl;

    // Compound subtraction
    if (book1.isbn() == book2.isbn())
        book1 -= book2;
    cout << book1 << endl;

    return 0;
}
