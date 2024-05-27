// 文件路径：MyString.h

#ifndef MYSTRING_H
#define MYSTRING_H

// 函数：统计输入字符串中的英文字母个数
int myStat(const char *input);

// 函数：将输入的两个字符串连接起来
char *myConcat(const char *left, const char *right);

// 函数：将输入字符串中的每个字母都改为大写
void myUpper(char *input);

// 函数：将输入字符串中的每个字母都改为小写
void myLower(char *input);

// 函数：将输入的字符串进行加密
void myEncode(char *input);

// 函数：将输入的字符串进行解密
void myDecode(char *input);

#endif // MYSTRING_H
