#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	while (cin >> N) {
		if (N == 0) break;

		stack<int> stack;
		int cp[N*2+1] = {0};
		for (int i = 0; i < N; ++i) {
			int x, y;
			cin >> x >> y;
			cp[x] = y;
			cp[y] = x;
		}

		for (int i = 1; i <= 2*N; ++i) {
			// 若栈不为空且栈顶与当前数字为cp，则移除
			if (!stack.empty() and cp[i]==stack.top()) {
				stack.pop();
			} else {	// 若不匹配则入栈
				stack.push(i);
			}
		}

		if (stack.empty()) 
			cout << "Yes\n";
		else 
			cout << "No\n";
	}
}