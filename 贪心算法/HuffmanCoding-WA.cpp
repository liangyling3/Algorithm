// 邪门歪道的做法
// 2019.3.10 为啥错了？？？

/*
In computer science and information theory, a Huffman code is an optimal prefix code algorithm.

In this exercise, please use Huffman coding to encode a given data.

You should output the number of bits, denoted as B(T), to encode the data:

B(T)=∑f(c)dT(c),

where f(c) is the frequency of character c, and dT(c) is be the depth of character c's leaf in the tree T.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
	int num;
	int frequency;
};

bool cmp(node & n1, node & n2) {
	return n1.frequency < n2.frequency;
}

// 找到的规律：n=同深度满二叉树结点数(2^k)-n+2^m
int calculate(vector<node> arr, int n) {
	sort(arr.begin(), arr.end(), cmp);
	int depth = log(n-1) / log(2) + 1;
	int bottom = n - (pow(2, depth)-n);
	int result = 0;

	for (int i = 0; i < bottom; ++i) {
		result += arr[i].frequency * depth;
	}

	for (int i = bottom; i < n; ++i) {
		result += arr[i].frequency * (depth-1);
	}

	return result;
}

int main() {
	int n;
	
	while (cin >> n) {
		vector<node> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].num >> arr[i].frequency;
		}

		cout << calculate(arr, n) << endl;
	}
}