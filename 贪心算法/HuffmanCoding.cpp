// 2019.3.10
// 根本就不用建树！！！！
/*
In computer science and information theory, a Huffman code is an optimal prefix code algorithm.

In this exercise, please use Huffman coding to encode a given data.

You should output the number of bits, denoted as B(T), to encode the data:

B(T)=∑f(c)dT(c),

where f(c) is the frequency of character c, and dT(c) is be the depth of character c's leaf in the tree T.

*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct node {
	bool operator < (const node & n2) const {
		return this->frequency > n2.frequency;
	}

	int frequency;
};

int calculate(priority_queue<node> pq, int n) {
	int result = 0;

	while (pq.size() > 1) {
		node n1;
		n1.frequency = pq.top().frequency;
		pq.pop();

		node n2; 
		n2.frequency = pq.top().frequency;
		pq.pop();

		node n3;
		n3.frequency = n1.frequency + n2.frequency;
	
		result += n3.frequency;
		pq.push(n3);
	}

	return result;
}

int main() {
	int n;
	priority_queue<node> pq;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			node temp;
			char c;
			cin >> c >> temp.frequency;
			pq.push(temp);
		}

		cout << calculate(pq, n) << '\n';
	}
}