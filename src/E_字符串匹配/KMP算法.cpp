#include <bits/stdc++.h>
using namespace std;

//在关键字中记录与前缀匹配的组合,记录在next数组
void make_next(string pattern, int *next)
{
    int q, k;               //q是匹配的位置,k是前缀开始的地方
    int m = pattern.size(); //关键字的长度

    next[0] = 0; //用于记录关键字中与前缀匹配的组合的位置
    for (q = 1, k = 0; q < m; q++)
    { //q是后面的数,k是前缀开始的地方
        while (k > 0 && pattern[q] != pattern[k])
        { //当后面的组合与前缀不同时,前缀数-1继续匹配
            k = next[k - 1];
        }

        if (pattern[q] == pattern[k])
        { // 如果前缀与后面有相同字符
            k++;
        }
        next[q] = k; //用于记录关键字中与前缀匹配的组合的位置
    }
}

//kmp算法
int kmp(string text, string pattern, int *next)
{
    int n = text.size();    //文本串的长度
    int m = pattern.size(); //关键字的长度

    make_next(pattern, next); //在关键字中记录与前缀匹配的组合,记录在next数组

    int i, q;
    for (i = 0, q = 0; i < n; i++)
    { //i --> text, q --> pattern
        while (q > 0 && pattern[q] != text[i])
        {                    //如果匹配失败,往前找与前缀相同组合的位置
            q = next[q - 1]; //只要next[q-1]不大于0,那么就是还没找到与前缀相同的组合
        }                    //继续在循环中找到与前缀相同的组合,直到next[q-1]等于0

        if (pattern[q] == text[i])
        { //如果匹配正确,关键字位置+1
            q++;
        }

        if (q == m)
        {                     //如果q的位置是关键字的长度,那么就是找到字符串了
            return i - q + 1; //返回字符串的位置
        }
    }
    return -1; //整个文本串找完都没有找到字符串,返回-1
}

int main()
{
    string text = "ABAABAABBABAAABAABBABAAB";
    string temp = "ABAABBABAAB";
    int len = temp.size();
    int arr[len+1];
    make_next(temp, arr);
    
    cout << kmp(text, temp, arr);

    return 0;
}
