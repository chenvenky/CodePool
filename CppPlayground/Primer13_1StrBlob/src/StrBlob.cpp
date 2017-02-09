#include "StrBlob.h"
#include <iostream>
// 类 StrBlob 的实现
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string & StrBlob::front()
{
    // 如果 vector 为空， check 会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    // 如果 vector 为空， check 会抛出一个异常
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i >= data->size());
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// 类 StrBlobPtr 的实现
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "derefernmce past end");
    return (*p)[curr];
}

StrBlobPtr & StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();         // 检查 vector 是否存在
    if (!ret)
        ; //throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        ; //throw std::out_of_range(msg);

    return ret;
}
