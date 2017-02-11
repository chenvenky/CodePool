## 动态内存管理类

某些类需要在运行时分配可变大小的内存空间。这种类通常可以（并且如果它们确实可以的话，一般应该）使用标准库容器来保护它们的数据。但是，这一策略并不是对每个类都适用：某些类需要自己进行内存分配。这些类一般来说必须定义自己的拷贝控制成员来管理所分配的内存。 

#### StrVec 类的设计

- allocator 按照 vector 的内存分配策略，构造新对象。 
- destory 释放过期的对象的内存。 

每个 StrVec 有三个指针成员指向其元素所使用的内存。 

- elements, 指向分配的内存中的首元素。 
- first_free, 指向最后一个实际元素之后的位置。 
- cap, 指向分配的内存末尾之后的位置。 

除了这些指针之外， StrVec 还有一个名为 alloc 的静态成员， 其类型为 allocator<string>. alloc 成员会分配 StrVec 使用的内存。 我们的类还有 4 个工具函数。 

- alloc_n_copy 会分配内存， 并拷贝一个给定范围中的元素。 
- free 会销毁构造的元素并释放内存。 
- chk_n_alloc 保证 StrVec 至少有容纳一个新元素的空间。如果没有空间添加新元素， chk_n_alloc 会调用 reallocate 来分配更多内存。 
- reallocate 在内存用完时为 StrVec 分配新内存。 

类体定义了多个成员：

- 默认构造函数(隐式地)默认初始化 alloc 并(显式地)将指针初始化为 nullptr, 表明没有元素。 
- size 成员返回当前真正在使用的元素的数目，等于 first_free - elements.
- capacity 成员返回 StrVec 可以保存的元素的数量， 等价于 cap - elements. 
- 当没有空间容纳新元素，即 cap == first_free 时， chk_n_alloc 会为 StrVec 重新分配内存。 
- begin 和 end 成员分别返回指向首元素（即elements）和最后一个构造的元素之后位置(即first_free)的指针。 
 
