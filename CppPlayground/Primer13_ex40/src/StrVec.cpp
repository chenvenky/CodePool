#include "StrVec.h"

void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();      // 确保有空间容纳新元素
    // 在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    // 分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个 pair， 该 pair 由 data 和 uninitialized_copy 的返回值构成
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    // 不能传递给 deallocate 一个空指针， 如果 elements 为 0， 函数什么也不做
    if (elements)
    {
        // 逆序销毁旧元素
        for (auto p = first_free; p != elements; /* 空 */)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);     // 释放内存空间
    }
}

/*
StrVec::StrVec(const StrVec &s)
{
    // 调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
*/

StrVec::~StrVec()
{
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
    // 调用 alloc_n_copy 分配内存，大小与 rhs 中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());   // 先复制，后释放，解决自赋值问题。
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

// reallocate 成员
void StrVec::reallocate()
{
    // 我们将分配当前大小两倍的内存空间
    auto newcapacity = size() ? 2 * size() : 1;     // 注意：当size()为 0 时的情况
    // 分配新内存
    alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap)
{
    if (new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s)
{
    if (count > size())
    {
        if (count > capacity()) reserve(count * 2);
        for (size_t i = size(); i != count; i++)
            alloc.construct(first_free++, s);
    }
    else if (count < size())
    {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

void StrVec::range_initialize(const std::string *first, const std::string *last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &rhs)
{
    range_initialize(rhs.begin(), rhs.end());
}

// 列表初始化构造函数
StrVec::StrVec(std::initializer_list<std::string> il)
{
    range_initialize(il.begin(), il.end());
}
