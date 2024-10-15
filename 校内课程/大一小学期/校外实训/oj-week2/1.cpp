//补全下列两个函数即可
int lowbit(int n)
{
    //write your code here
    return n & -n;

}
int NumberOf1(int n) {
    int res = 0;
    //write your code here
    for (int i = n; i; i -= lowbit(i))
    {
        res++;
    }
    return res;
}