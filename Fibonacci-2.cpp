#include <iostream>
#include <cmath>
using namespace std;

struct Matrix {
    long long int num[2][2];
};

Matrix multiply(Matrix m1, Matrix m2) { // 矩阵乘积
    Matrix result;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            result.num[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                result.num[i][j] += m1.num[i][k] * m2.num[k][j];
                result.num[i][j] %= (long long int)(pow(10,9) + 7);
            }
        }
    }

    return result;
}

Matrix exp(Matrix m1, long long int n) { // 矩阵的n次幂
    Matrix result = {1, 0, 0, 1};   // 初始化为单位矩阵
    // 若为偶数，则两个两个相乘，再折半循环，直至得到结果（n=1时）
    // 若为奇数，则在结果基础上多乘一个矩阵
    while(n) {
        if (n % 2 != 0) result = multiply(result, m1);  
        m1 = multiply(m1, m1);
        n /= 2;
    }

    return result;
}


int main() {
    Matrix m = {1, 1, 1, 0};
    Matrix result;
    long long int n, fn;
    while(cin >> n) {
        result = exp(m, n);
        fn = result.num[0][1];
        cout << fn << endl;
    }
}