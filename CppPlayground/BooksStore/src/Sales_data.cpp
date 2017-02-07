#include "Sales_data.h"

// 在类的外部定义成员函数
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}

// 与 Sales_data 的合成的拷贝构造函数等价
Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),        // 使用 string 的拷贝构造函数
    units_sold(orig.units_sold),    // 拷贝 orig.units_sold
    revenue(orig.revenue)          // 拷贝 orig.revenue
    { }                             // 空函数体

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 在类的外部定义 类 Sales_data 的非成员接口函数
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;       // 把 lhs 的数据成员拷贝给 sum
    sum.combine(rhs);           // 把 rhs 的数据成员加到 sum 当中
    return sum;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}



