#include "Hash_Table.h"

int main()
{
	int N;
	std::cout << "Enter container size:" << std::endl;
	std::cin >> N;

	Hash_Table table1(N);
	table1.Push("ABC");
	table1.Push("DEF");
	table1 << "ABCDEF";
	table1 << "BAC";

	std::string value;
	std::cout << "Enter some string:" << std::endl;
	std::cin >> value;
	table1 << value;
	std::cout << std::endl;
	std::cout  << "Take this hash table, bro:" << std::endl;
	table1.PrintList();
	std::cout << std::endl;

	std::cout << "Enter some string to test input srteam:" << std::endl;
	std::cin >> table1;
	std::cout << "Look, it works!:" << std::endl;
	table1.PrintList();
	std::cout << std::endl;

	Hash_Table table2(N);
	table2 = table1;
	std::cout << "Enter value to delete from table:" << std::endl;
	std::cin >> value;
	std::cout << std::endl;
	table1.Pop(value);
	std::cout << "First hash table:" << std::endl;
	table1.PrintList();
	std::cout << std::endl;
	std::cout << "Second hash table:" << std::endl;
	table2.PrintList();

	return 0;
}