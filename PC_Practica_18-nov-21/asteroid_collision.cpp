#include <bits/stdc++.h>

int sign(int n) {
	return (n >> 31) | (!!n);
}

std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
	std::vector<int> surviving_asteroids;

	for (auto& asteroid : asteroids) {
		while (!surviving_asteroids.empty() && sign(asteroid) < sign(surviving_asteroids.back()) && abs(asteroid) > abs(surviving_asteroids.back()))
			surviving_asteroids.pop_back();
		
		if (surviving_asteroids.empty() || sign(asteroid) >= sign(surviving_asteroids.back()))
			surviving_asteroids.push_back(asteroid);
		else if (abs(asteroid) == abs(surviving_asteroids.back()))
			surviving_asteroids.pop_back();
	}

	return surviving_asteroids;
}

void print_vector(const std::vector<int>& vec) {
	for (auto& i : vec)
		std::cout << i << " ";
	std::cout << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> asteroids;

	// Caso de prueba 1:
	// Entrada:
	// 5 10 -5
	// Salida:
	// 5 10
	//
	asteroids = { 5, 10, -5 };
	print_vector(asteroidCollision(asteroids));

	// Caso de prueba 2:
	// Entrada:
	// 8 -8
	// Salida:
	// 
	//
	asteroids = { 8, -8 };
	print_vector(asteroidCollision(asteroids));

	// Caso de prueba 3:
	// Entrada:
	// 10 2 -5
	// Salida:
	// 10
	//
	asteroids = { 10, 2, -5 };
	print_vector(asteroidCollision(asteroids));

	// Caso de prueba 4:
	// Entrada:
	// -2 -1 1 2
	// Salida:
	// -2 -1 1 2
	//
	asteroids = { -2, -1, 1, 2 };
	print_vector(asteroidCollision(asteroids));

	return 0;
}
