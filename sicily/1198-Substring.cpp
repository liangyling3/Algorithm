#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 判断s是否为t的子串（且必须从第一个字符开始）
bool isSubstring(string s, string t) {
	int len1 = s.size(), len2 = t.size();
	for (int i = 0; i < len1; ++i) {
		if (s[i] != t[i])	return false;
	}
	return true;
}

bool cmp(string & str1, string & str2) {
	int len1 = str1.size();
	int len2 = str2.size();

	if(len1 == len2) {
		return str1 < str2;
	}
	if (len1 < len2) {
		if (isSubstring(str1, str2) && str2[len1-1] > str2[len1]) 
			return false;
	}
	if (len1 > len2) {
		if (isSubstring(str2, str1) && str1[len2-1] > str1[len2]) 
			return true;
	}
	return str1 < str2;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		string str[n];
		for (int i = 0; i < n; ++i) {
			cin >> str[i];
		} 
		sort(str, str+n, cmp);

		for (int i = 0; i < n; ++i) {
			cout << str[i];
		} 
		cout << endl;
	}
}