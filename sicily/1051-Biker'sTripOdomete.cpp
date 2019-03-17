#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.1415927

int main() {
	double diameter, revolutions, time;
	int count = 0;
	while (cin >> diameter >> revolutions >> time && revolutions) {
		count ++;
		cout << "Trip #" << count << ": ";

		double round = PI * diameter;	// 周长
		double distance = (round * revolutions) / 5280 / 12;
		double velocity = distance / (time/3600);

		cout << fixed << setprecision(2) << distance << " ";
		cout << fixed << setprecision(2) << velocity << endl;
	}
}