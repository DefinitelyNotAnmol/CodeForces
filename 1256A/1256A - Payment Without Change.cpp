#include <iostream>
#include <string>

#define DEBUG 0
#if DEBUG
	#define PRINT(x, y) std::cout << x << y << std::endl
#else
	#define PRINT(x, y)
#endif

std::string isPossibleExactChange(long long a, long long b, long long n, long long s);

int main() {
	long long testCases;
	std::cin >> testCases;

	long long a, b, n, s;

	for (int test = 0; test < testCases; test++) {
		std::cin >> a >> b >> n >> s;
		std::cout << isPossibleExactChange(a, b, n, s) << std::endl;
	}
}

std::string isPossibleExactChange(long long a, long long b, long long n, long long s) {
	long long currentTotal = 0;

	for (long long i = 1; i <= a; i++) {
		PRINT("i x n = ", i*n);

		currentTotal = i * n;
		if (currentTotal > s) {
			long long remaining = s - ((i - 1) * n);
			if (remaining <= b)
				return "YES";
			else
				return "NO";
		} 
	}

	if (a == 0 or currentTotal <= s) {
		if (b + currentTotal >= s)
			return "YES";
		else
			return "NO";
	}

	return "NO";
}