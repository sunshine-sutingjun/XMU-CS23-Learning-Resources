// 文件路径：Test.cpp

#include "MyString.h"
#include <iostream>

// 使用using声明来访问std命名空间中的标识符
using std::cout;
using std::endl;

int main()
{
    // 定义函数指针
    int (*stat)(const char *);
    char *(*concat)(const char *, const char *);
    void (*upper)(char *);
    void (*lower)(char *);
    void (*encode)(char *);
    void (*decode)(char *);

    // 将函数指针指向相应的函数
    stat = myStat;
    concat = myConcat;
    upper = myUpper;
    lower = myLower;
    encode = myEncode;
    decode = myDecode;

    // 测试函数指针调用函数
    const char *input_str = "I'm studying C++";
    cout << "Input string: " << input_str << endl;
    cout << "Number of English letters: " << stat(input_str) << endl;

    char left[] = "Hello";
    char right[] = "World";
    char *concat_result = concat(left, right);
    cout << "Concatenated string: " << concat_result << endl;

    char test_str[] = "I'm studying C++";
    upper(test_str);
    cout << "Uppercase string: " << test_str << endl;

    lower(test_str);
    cout << "Lowercase string: " << test_str << endl;

    encode(test_str);
    cout << "Encoded string: " << test_str << endl;

    decode(test_str);
    cout << "Decoded string: " << test_str << endl;

    // 释放动态分配的内存
    delete[] concat_result;

    return 0;
}
