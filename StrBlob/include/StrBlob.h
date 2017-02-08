#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <vector>
#include <string>

// 对于 StrBlob 中的友元声明来说， 这个前置声明是必要的
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob():data(std::make_shared<std::vector<std::string>>()) { }
        StrBlob(std::initializer_list<std::string>il):data(std::make_shared<std::vector<std::string>>(il)) { }
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        // 添加和删除元素
        void push_back(const std::string &t) { data->push_back(t); }
        void pop_back();

        std::string& front();
        std::string& back();
        const std::string& front() const;
        const std::string& back() const;

        // 返回指向首元素和尾元素的 StrBlobPtr
        StrBlobPtr begin();
        StrBlobPtr end();
    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i, const std::string &msg) const;
};

// 对于访问一个不存在元素的尝试， StrBlobPtr抛出一个异常
class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();     // 前缀递增
private:
    // 若检查成功， check返回一个指向 vector 的 shared_ptr
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t i, const std::string& msg) const;
    // 保存一个 waak_ptr， 意味着底层 vector 可能被销毁
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;       // 在数组中的当前位置
};
#endif // STRBLOB_H
