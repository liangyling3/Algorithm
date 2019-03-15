#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ostream & operator << (ostream & out, vector<pair<string,string> > & vec) {
	int size = vec.size();
	for (int i = 0; i < size; ++i) {
		out << vec[i].second << " is the MaJia of " << vec[i].first << '\n';
	}
	return out;
}

// 按主id的字典序比较
bool cmp(pair<string,string> & line1, pair<string,string> & line2) {
	return line1.first < line2.first;
}

int main() {
	int n;
	while (cin >> n && n) {
		vector<string> id(n);
		vector<string> address(n);
		vector<pair<string,string> > result;
		for (int i = 0; i < n; ++i) {
			cin >> id[i] >> address[i];

			auto it = find(address.begin(), address.end(), address[i]);
			if (it != address.end()) {
				int index = distance(address.begin(), it);
				if (index != i) {
					pair<string,string> temp;
					temp.first = id[index];
					temp.second = id[i];
					result.push_back(temp);
				}
			}
		}

		sort(result.begin(),result.end(),cmp);
		cout << result << '\n';
	}
}