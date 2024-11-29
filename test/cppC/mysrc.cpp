#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 快速傅里叶变换(FFT)
 * @Input 输入：一个多项式系数向量a(a0,a1,...,an)
 * @Output 输出：结果值向量y(a0,a1,...,yn)
 */
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;
// FFT 实现
void notFFT(vector<complex<double>>& a) {
    // 长度过小直接返回
    int n = a.size();
    if (n <= 1) return;
    // 计算根Omiga
    complex<double> omiga_n(cos(2*PI/n), sin(2*PI/n));//omiga_n = e^{2PIi/n}
    complex<double> tem1 = (1.0,0.0);
    omiga_n = tem1 / omiga_n;
    complex<double> omiga(1.0,0.0);
    // 折半系数向量a，分出奇偶
    vector<complex<double>> a_even(n / 2);//A0=(a0,a2,...,an-2)
    vector<complex<double>> a_odd(n / 2);//A1=(a1,a3,...,an-1)
    for (int i = 0; i < n / 2; ++i) {
        a_even[i] = a[i * 2];
        a_odd[i] = a[i * 2 + 1];
    }
    // 递归计算
    notFFT(a_even);
    notFFT(a_odd);
    // 组合两个y
    for (int k = 0; k < n / 2; ++k) {
        complex<double> t = polar(1.0, -2 * PI * k / n) * a_odd[k];
        a[k] = a_even[k] + t;
        a[k + n / 2] = a_even[k] - t;
    }
}

int main() {
    // 示例输入
    vector<complex<double>> y;
    int n;
    cin >> n;
    int n2 = pow(2,n);
    for(int i = 0; i < n2; i++){
        double tem;
        cin >> tem;
        complex<double> t(tem,0);
        y.push_back(t);
    } 
    // 计算 FFT
    notFFT(y);
    //每个结果除以n
    int n1 = y.size();
    for(int i = 0; i < n1; i++){
        y[i] /= n1;
    }
    // 输出结果
    for (const auto& x : y) {
        cout << fixed << setprecision(2)<< x.real() << " ";
        cout << fixed << setprecision(2)<< x.imag() << endl;
    }
    return 0;
}