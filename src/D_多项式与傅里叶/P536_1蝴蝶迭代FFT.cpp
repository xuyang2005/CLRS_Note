#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 快速傅里叶变换(FFT)
 * @Input 输入：一个多项式系数向量a(a0,a1,...,an)
 * @Output 输出：结果值向量y(a0,a1,...,yn)
 */
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;
void ffft(vector<complex<double>>& x) {
    // 填充设置为2^n长度
    int N = x.size();
    int N2 = 1;
    bool ngood = false;
    for(int i = 0; i <= 12 && N2 <= N; i++){
        N2 = pow(2,i);
        if(N==N2){
            ngood = true;
            break;
        }
    }
    int Ncha = N2 - N;
    for(int i = 0; i < Ncha; i++){
        x.push_back({0.0,0.0});
    }
    N = N2;
    // 位反转排序
    int logN = log2(N);
    vector<complex<double>> temp(N);
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (int bit = 0; bit < logN; bit++) {
            if (i & (1 << bit)) {
                j |= (1 << (logN - 1 - bit));
            }
        }
        temp[j] = x[i];
    }
    x = temp;

    // 蝴蝶操作
    for (int len = 2; len <= N; len *= 2) {
        double angle = -2 * PI / len;
        complex<double> wlen(cos(angle), sin(angle));

        for (int i = 0; i < N; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; j++) {
                complex<double> u = x[i + j];
                complex<double> v = x[i + j + len / 2] * w;

                x[i + j] = u + v;   // 蝴蝶操作
                x[i + j + len / 2] = u - v; // 蝴蝶操作
                w *= wlen; // 更新旋转因子
            }
        }
    }
}

int main() {
    // 示例：计算8个点的FFT
    vector<complex<double>> data = {
        {1.0, 0.0},
        {0.0, 0.0},
        {0.0, 0.0},
        {0.0, 0.0},
        {0.0, 0.0},
        {0.0, 0.0},
        {0.0, 0.0},
        {0.0, 0.0}
    };

    cout << "Input Data:\n";
    for (const auto& c : data) {
        cout << c << "\n";
    }

    ffft(data);

    cout << "\nFFT Result:\n";
    for (const auto& c : data) {
        cout << c << "\n";
    }

    return 0;
}