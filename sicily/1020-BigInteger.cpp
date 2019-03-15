#include <iostream>
#include <string>
using namespace std;

int getRem(const string & x, int num) {
	int size = x.size();
	int temp = 0;
	int rem = 0;
	for (int i = 0; i < size; ++i) {
		temp = rem*10 + (x[i] -'0');
		rem = temp % num;
	}
	return rem;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int nums[n];
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}

		string x;
		cin >> x;

		cout << "(";
		for (int i = 0; i < n; ++i) {
			if (i!=0)	cout << ",";
			cout << getRem(x, nums[i]);
		}
		cout << ")\n";
	}
}

