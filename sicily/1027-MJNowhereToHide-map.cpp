#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		// 使用map时前面一定要加std::
		std::map<string,string> map;		// 存储IP地址+id
		std::map<string,string> result; 	// 存储IP地址相同的主id + MJid
		for (int i = 0; i < n; ++i) {
			pair<string,string> info;
			cin >> info.second >> info.first;	// 以IP地址为主码
			auto it = map.find(info.first);
			if (it == map.end()) {
				map.insert(info);
			} else {
				pair<string,string> temp;
				temp.first = it->second;
				temp.second = info.second;
				result.insert(temp);
			}
		}

		for (auto it = result.begin(); it != result.end(); it++) {
			cout << it->second << " is the MaJia of " << it->first << '\n';
		}
		cout << '\n';
	}
}