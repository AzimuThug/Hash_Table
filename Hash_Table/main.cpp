#include "Hash_Table.h"
// обработка исключений

int main()
{
	int N = 10;
	Hash_Table a(N);
	a.Push("ABC");
	a.Push("VVV");
	a << "BCA";
	a.Push("XVV");
	a.Push("BCA");
	a.Push("HJ");
	a.Push("JH");
	a.PrintList();
	std::cout << std::endl;
	a.Pop("ABC");
	a.Pop("VVV");
	a.Pop("XVV");
	a.PrintList();
	std::cout << std::endl;
	Hash_Table a2(N);
	a2 = a;
	a2.PrintList();
	return 0;
}