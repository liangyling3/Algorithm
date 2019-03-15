#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

#define INF 100000000

struct node {
	double x;
	double y;
};

int main() {
	int n, k;
	while (cin >> n >> k) {
		node points[n];
		double edges[n][n] = {0};

		for (int i = 0; i < n; ++i) {
			cin >> points[i].x >> points[i].y;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				edges[i][j]=sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x)
                                +(points[i].y-points[j].y)*(points[i].y-points[j].y));
				edges[j][i] = edges[i][j];
			}
		}

		// Prim算法
		bool visited[n] = {0};
		double dis[n] = {0};		// 最短距离

		for (int i = 0; i < n; ++i) {
			dis[i] = edges[0][i];	// 此题中所有边都存在所以不用初始化为Inf
		}

		visited[0] = 1;		// 以第一个点作为起点
		vector<double> result;
		for (int i = 1; i < n; ++i) {
			double min = INF;
			int index = 0;		// 当前点
			for (int j = 1; j < n; ++j) {
				if (!visited[j] and dis[j] < min) {
					min = dis[j];
					index = j;
				}
			}

			visited[index] = true;
			result.push_back(dis[index]);

			// 检查这个点到邻点的距离有没有比之前更小的
			for (int j = 1; j < n; ++j) {
				if (!visited[j] && edges[index][j] < dis[j]) {
					dis[j] = edges[index][j];
				}
			}	
		}

		sort(result.begin(), result.end(), greater<double>());
		cout << fixed << setprecision(2) << result[k-2] << endl;
	}
}