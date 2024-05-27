// 文件路径：MyString.cpp

#include "MyString.h"

#include <cstring>

// 函数：统计输入字符串中的英文字母个数
int myStat(const char *input)
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; ++i)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            ++count;
        }
    }
    return count;
}

// 函数：将输入的两个字符串连接起来
char *myConcat(const char *left, const char *right)
{
    int left_len = strlen(left);
    int right_len = strlen(right);
    char *result = new char[left_len + right_len + 1];
    strcpy(result, left);
    strcat(result, right);
    return result;
}

// 函数：将输入字符串中的每个字母都改为大写
void myUpper(char *input)
{
    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] -= 32; // 转换为大写
        }
    }
}

// 函数：将输入字符串中的每个字母都改为小写
void myLower(char *input)
{
    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] += 32; // 转换为小写
        }
    }
}

// 函数：将输入的字符串进行加密
void myEncode(char *input)
{
    for (int i = 0; input[i] != '\0'; ++i)
    {
        input[i] += 8; // 加密
    }
}

// 函数：将输入的字符串进行解密
void myDecode(char *input)
{
    for (int i = 0; input[i] != '\0'; ++i)
    {
        input[i] -= 8; // 解密
    }
}
