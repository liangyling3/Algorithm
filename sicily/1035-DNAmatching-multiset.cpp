#include <iostream>
#include <set>
#include <string>
using namespace std;

bool match(multiset<string> & dna, string line) {
	string matchLine = "";
	int size = line.size();
	for(int i = 0; i < size; ++i) {
		if (line[i] == 'A')	matchLine += "T";
		if (line[i] == 'T')	matchLine += "A";
		if (line[i] == 'C')	matchLine += "G";
		if (line[i] == 'G')	matchLine += "C";
	}

	auto it = dna.find(matchLine);
	if (it == dna.end()) {
		return false;
	} else {
		dna.erase(it);	// dna.erase(matchLine)会删除所有值=matchLine的元素
		return true;
	} 
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		multiset<string> dna;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			string line;
			cin >> line;

			if (match(dna, line)) {
				count++;
			} else {
				dna.insert(line);
			}
		} 
		cout << count << endl;
	}
}