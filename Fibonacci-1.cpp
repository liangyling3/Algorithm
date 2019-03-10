#include <iostream>
#include <cmath>
using namespace std;

int fib(int n) {
	return (n < 3 ? 1 : fib(n-1) + fib(n-2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		cout << fib(n) % (int)(pow(10,9) + 7) << '\n';
	}
}