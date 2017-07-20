## 用两个栈实现队列

### 题目描述
用两个栈来实现一个队列， 完场队列的Push和Pop操作。 队列中的元素为 int 类型。 

### 解题思路：
1. 当 Push 的时候， 把元素 Push 进 stack2. 
2. 当 Pop 的时候， 如果 stack1 不为空， stack1 pop 即可。 否则， 把stack2中的元素全部Push进 stack1, 然后从 stack1 中 pop出一个元素。如果 两个栈都为空，出错。
