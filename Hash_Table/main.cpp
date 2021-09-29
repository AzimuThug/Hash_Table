#include "hash_map.h"
int main()
{
	HashMap<10> a1;
	std::cin >> a1;
	std::cin >> a1;
	std::cin >> a1;
	std::cin >> a1;
	std::cout << a1;
	HashMap<10> a2 = a1;
	std::cout << std::endl;
	std::cin >> a2;
	std::cout << a2;
	HashMap<10> a3(a1);
	std::cout << std::endl;
	std::cin >> a3;
	std::cout << a3;
	std::cout << std::endl;
	HashMap<10> a4(std::move(a3));
	std::cout << a4;
	return 0;
}