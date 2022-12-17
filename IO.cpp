#include <iostream>
#include <cmath>
using namespace std;

char input;

int main() {
	cout << "Type an x ";
	cin >> input;
	int x = int(input);

	cout << 3 * pow(x, 6) - 6 * pow(x, 2) - 7 ;
}