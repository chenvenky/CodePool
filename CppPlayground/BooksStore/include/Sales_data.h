#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>

class Sales_data
{
public:
// 新增的构造函数
//Sales_data() = default; // 默认构造函数
//    Sales_data(std::string &s = "") : bookNo(s) { }
//    Sales_data(const std::string &s, unsigned n, double p):
//            bookNo(s), units_sold(n), revenue(p*n) { }
//    Sales_data(std::istream&);

// 委托构造函数
// 非委托构造函数使用对应的实参初始化成员
Sales_data(std::string s, unsigned cnt, double price):
    bookNo(s), units_sold(cnt), revenue(price * cnt) { }
// 其余构造函数全都委托给另一个构造函数
Sales_data() : Sales_data("", 0, 0){ }
Sales_data(std::string s) : Sales_data(s, 0, 0) { }
Sales_data(std::istream &is);// 委托给第二个构造函数
// 和合成的拷贝构造函数等价的拷贝构造函数的声明
Sales_data(const Sales_data&);

    // 新成员：关于 Sales_data 对象的操作
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // 数据成员
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

// Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

#endif // SALES_DATA_H
