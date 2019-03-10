#include <iostream>
#include <vector>
using namespace std;

// 递归算法
void selectByRecursion(vector<int> & result, int * s, int * f, int k, int n) {
	int m = k + 1;
	// m是k的后一个活动，若m的开始时间小于k的结束时间，则冲突
	while (m <= n && s[m] < f[k]) {
		m++;
	}

	if (m <= n) {
		result.push_back(m);
		selectByRecursion(result, s, f, m, n);
	}
}


// 迭代算法
void selectByIteration(vector<int> & result, int * s, int * f, int n) {
	int k = 1;
	result.push_back(k);

	for (int m = 2; m <= n; ++m) {
		if (s[m] >= f[k]) {
			result.push_back(m);
			k = m;
		}
	}
}

int main() {
	// 活动需要先按照fi的升序排列好
}