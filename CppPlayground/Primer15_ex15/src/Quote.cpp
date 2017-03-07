#include "Quote.h"

void Quote::debug() const
{
    std::cout << "bookNo= " << this->bookNo << " "
                << "price= " << this->price << std::endl;
}
