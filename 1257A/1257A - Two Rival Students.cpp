#include <iostream>
#include <cmath>

int maxDistance(int n, int x, int a, int b);

int main() {
	int testCases;
	std::cin >> testCases;

	int n, x, a, b;

	for (int test = 0; test < testCases; test++) {
		std::cin >> n >> x >> a >> b;
		std::cout << maxDistance(n, x, a, b) << std::endl;
	}
}

int maxDistance(int n, int x, int a, int b) {
	int startDistance = std::abs(a - b); //1

	if (startDistance < n-1) {
		if (startDistance+x < n-1)
			return startDistance+x;
		else 
			return n-1;
	} 
	else
		return startDistance;
}