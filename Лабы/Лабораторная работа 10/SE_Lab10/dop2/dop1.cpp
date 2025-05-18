#include <iostream>
using namespace std;

int main() {
	auto lamb = [](int a) -> bool {
		return a > 0;
	};
	cout << (lamb(-5) ? "true" : "false") << ' ' << (lamb(3) ? "true" : "false");
	return 0;
}