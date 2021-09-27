#include "Hash_Table.h"

Hash_Table::Node::Node()
{
	hash_key = 0;
};

/*Struct Constructor*/
Hash_Table::Node::Node(int M)
{
	hash_key = (unsigned char)M;
};

/*Hash function*/
unsigned char Hash_Table::hash(std::string& Value, int N)
{
	unsigned char res = 0;
	for (int i = 0; i < (int)Value.length(); i++)
		res += (unsigned char)Value[i];
	return res % N;
}

/*Constructor with parameters*/
Hash_Table::Hash_Table(int N)
{
	this->N = N;
	for (int i = 0; i < N; i++)
		nodes.push_back(Node(i));
};

/*Destructor*/
Hash_Table::~Hash_Table() {};

/*Copy constructor*/
Hash_Table::Hash_Table(const Hash_Table& other)
{
	N = other.N;
	nodes = other.nodes;
};

/*Move-constructor*/
Hash_Table::Hash_Table(Hash_Table&& other)
	:N(0),
	nodes(0)
{
	N = other.N;
	nodes = other.nodes;

	other.N = 0;
	std::vector<Node>().swap(other.nodes);
};

/*Assignment operator*/
Hash_Table& Hash_Table::operator=(const Hash_Table& other)
{
	if (this != &other)
	{
		if (N > 0)
			std::vector<Node>().swap(nodes);

		N = other.N;

		for (int i = 0; i < N; i++)
		{
			nodes.push_back(Node(i));
			for (int j = 0; j < other.nodes[i].value.size(); j++)
			{
				nodes[i].value.push_back(other.nodes[i].value[j]);
			};
		};
	};
	return *this;
}

/*Move assignment operator*/
Hash_Table& Hash_Table::operator=(Hash_Table&& other)
{
	N = other.N;
	nodes = other.nodes;

	other.N = 0;
	std::vector<Node>().swap(other.nodes);

	return *this;
};

/*Insert operator*/
Hash_Table& Hash_Table::operator<<(std::string str)
{
	int tmp = (int)hash(str, N);
	nodes[tmp].value.push_back(str);
	return *this;
}

void Hash_Table::Push(std::string str)
{
	int tmp = (int)hash(str, N);
	nodes[tmp].value.push_back(str);
};

void Hash_Table::Pop(std::string str)
{
	int tmp = (int)hash(str, N);
	auto it = std::remove(nodes[tmp].value.begin(), nodes[tmp].value.end(), str);
	nodes[tmp].value.erase(it, nodes[tmp].value.end());
};

void Hash_Table::PrintList()
{
	for (int i = 0; i < N; i++)
	{
		if ((int)nodes[i].value.size() > 0) 
		{
			for (int j = 0; j < (int)nodes[i].value.size(); j++)
			{
				std::cout << nodes[i].value[j] << " ";
			};
			std::cout << std::endl;
		}
	};
};