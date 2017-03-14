#include <stdio.h>
#include <string.h>

/**
* 格式：puts(字符数组名)
* 功能：把字符数组中的字符串输出到显示器。即在屏幕上显示该字符串。
*/
void puts_function()
{
    char str[] = "DO MORE \nSAY LESS";
    puts(str);
}

/**
* 格式：gets（字符数组名）
* 功能：从标准输入设备上输入一个字符串
* 本函数得到一个函数值， 即为该字符数组的首地址
*/
void gets_function()
{
    char str[22];
    printf("input string's length less than 21:\n");
    gets(str);
    puts(str);
}


/**
* 格式：strcat(dest数组名, src数组名)
* 功能：把src字符数组中的字符串连接到dest字符数组字符串的后面， 并删去dest字符串后的串标志"\0".
* 本函数返回值是dest字符串的首地址。
*/
void strcat_function()
{
    static char str[50] = "Always tell a good story.";
    char str2[10];    // WC, here is int
    printf("Input your name:\n");
    gets(str2);
    strcat(str, str2);
    puts(str);
}

/**
* 格式：strcpy(dest, src)
* 功能：把src字符数组中的字符串拷贝到dest字符数组中。 串结束标志'\0'也一同拷贝。src字符串也可以是一个"字符串"
* 这时相当于把一个字符串赋予一个字符数组
*/
void strcpy_function()
{
    char str[20], str2[] = "Learn C Language again!";
    strcpy(str, str2);
    puts(str);
    printf("\n");
}

/**
* 格式：strncpy(dest, src, n)
* 功能: 将 src 内最多 n 个字符复制进 dest 字符数组
*
*/
/**
* 格式：strlen(字符数组名)
* 功能：测字符串的实际长度（不含字符串结束标志 '\0'）并作为函数返回值。
*/
void strncpy_function()
{
    char str[20];
    char str2[] = "I made a fault!";
    strncpy(str, str2, 15);
    puts(str);
}

void strlen_function()
{
    static char str[] = "Learn C language again!";
    int len = strlen(str);
    printf("the str length: %d\n", len);
}



int main()
{
    puts_function();
    gets_function();
    strcat_function();
    strcpy_function();
    strlen_function();
    strncpy_function();
    return 0;
}
