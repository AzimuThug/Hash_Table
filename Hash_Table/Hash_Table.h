#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hash_Table
{
private:
	int N;
	struct Node 
	{
		unsigned char hash_key;
		std::vector<std::string> value;
		Node();
		Node(int M);
	};
public:
	std::vector<Node> nodes;

	/*Hash function*/
	unsigned char hash(std::string&, int);

	/*Constructor with parameters*/
	Hash_Table(int N);

	/*Destructor*/
	~Hash_Table();

	/*Copy constructor*/
	Hash_Table(const Hash_Table&);

	/*Move-constructor*/
	Hash_Table(Hash_Table&& other);

	/*Assignment operator*/
	Hash_Table& operator=(const Hash_Table& HT);

	/*Move assignment operator*/
	Hash_Table& operator=(Hash_Table&& other);

	/*Insert operator*/
	Hash_Table& operator<<(std::string str);

	void Push(std::string);
	void Pop(std::string);
	void PrintList();
};