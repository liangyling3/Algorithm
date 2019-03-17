#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct period {
	int quarters;
	double planePerQuarter;
	int start;
	int end;
	vector<int> planes;
};

double getSum(const vector<int> & nums) {
	int size = nums.size();
	double sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += nums[i];
	}
	return sum;
}

bool cmp(period & p1, period & p2) {
	if (p1.planePerQuarter != p2.planePerQuarter) {
		return p1.planePerQuarter > p2.planePerQuarter;
	} else {
		if (p1.quarters != p2.quarters) {
			return p1.quarters > p2.quarters;
		} else {
			return p1.end < p2.end;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	int testNum = T;
	while(T--) {
		int n, bestNum, min;
		cin >> n >> bestNum >> min;

		int planes[n];
		for (int i = 0; i < n; ++i) {
			cin >> planes[i];
		}

		vector<period> result;
		for(int i = min; i <= n; ++i) {
			for (int j = 0; j+i <= n; ++j) {
				period temp;
				for (int k = j; k < j+i; ++k) {
					temp.planes.push_back(planes[k]);
				}
				temp.planePerQuarter = getSum(temp.planes) / i;
				temp.start = j+1;
				temp.end = j+i;
				temp.quarters = i;
				result.push_back(temp);
			}
		}

		sort(result.begin(), result.end(), cmp);
		cout << "Result for run " << testNum-T << ":" << endl;
		if (bestNum > result.size()) {
			bestNum = result.size();
		}
		for (int i = 0; i < bestNum; ++i) {
			cout << result[i].start << '-' << result[i].end << endl;
		}
	}
}