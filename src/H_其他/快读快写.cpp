#include <bits/stdc++.h>
using namespace std;


char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}




// 快读函数
inline void fastRead(int &x) {
    x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
    x *= f;
}

// 快写函数
inline void fastWrite(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    char buf[10];
    int len = 0;
    do {
        buf[len++] = '0' + x % 10;
        x /= 10;
    } while (x);
    for (int i = len - 1; i >= 0; --i) {
        putchar(buf[i]);
    }
    putchar('\n'); // 输出换行
}

int main() {
    int n;
    fastRead(n); // 使用快读读取整数
    for (int i = 0; i < n; ++i) {
        fastWrite(i); // 使用快写输出整数
    }
    return 0;
}