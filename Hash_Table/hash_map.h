#include <iostream>
#include <string>
#include <utility>
#include <memory>
class LinkedList
{
public:
	class Node
	{
		std::string val_;
		std::unique_ptr<Node> next_;
	public:
		Node(const std::string& str) :
			val_(str),
			next_(nullptr)
		{}
		void set_next(Node* ptr)
		{
			next_ = std::unique_ptr<Node>(ptr);
		}
		Node* get_next()
		{
			return next_.get();
		}
		std::string get_val()
		{
			return val_;
		}
	};
private:
	size_t size_ = 0;
	std::unique_ptr<Node> head_;
public:
	void push(const std::string& str)
	{
		if (head_.get() == nullptr)
			head_ = std::unique_ptr<Node>(new Node(str));
		else
		{
			Node* cur = head_.get();
			while (cur->get_next() != nullptr)
				cur = cur->get_next();
			cur->set_next(new Node(str));
		}
		size_++;
	}
	Node* get_head() const
	{
		return head_.get();
	}
	bool empty() const
	{
		return size_ == 0;
	}
	size_t size() const
	{
		return size_;
	}
};

template <size_t size_>
class HashMap
{
	class Bucket
	{
	public:
		LinkedList values_;
		Bucket()
		{}
	};
	std::unique_ptr<Bucket[]> table_;
	unsigned char hash(const std::string& value) {
		unsigned char res = 0;
		for (const auto c : value)
			res += static_cast<unsigned char>(c);
		return res % size_;
	}
public:
	HashMap() :
		table_{ std::unique_ptr<Bucket[]>(new Bucket[size_]) }
	{}
	HashMap(std::initializer_list<std::string> list) :
		table_{ std::unique_ptr<Bucket[]>(new Bucket[size_]) }
	{
		for (const auto& s : list)
			*this << s;
	}
	HashMap(const HashMap& rhs) :
		table_{ std::unique_ptr<Bucket[]>(new Bucket[size_]) }
	{
		for (size_t i = 0; i < size_; ++i)
			table_[i] = rhs.table_[i];
	}
	HashMap(HashMap&& rhs) :
		table_{ std::exchange(rhs.table_,nullptr) }
	{}
	HashMap& operator=(const HashMap& rhs)
	{
		if (this != &rhs)
		{
			for (size_t i = 0; i < size_; ++i)
				table_[i] = rhs.table_[i];
		}
	}
	HashMap& operator=(HashMap&& rhs)
	{
		if (this != &rhs)
		{
			delete table_;
			std::exchange(rhs.table_, nullptr);
		}
	}
	LinkedList operator[](int index) const
	{
		return (table_.get())[index].values_;
	}
	template<size_t _size_>
	friend std::istream& operator>> (std::istream& is, HashMap<_size_>& rhs);
	template<size_t _size_>
	friend std::ostream& operator<<(std::ostream& os, HashMap<_size_>& rhs);
};

template<size_t size_>
std::istream& operator>>(std::istream& is, HashMap<size_>& rhs)
{
	std::string temp;
	is >> temp;
	rhs.table_[rhs.hash(temp)].values_.push(temp);
	return is;
}
template<size_t size_>
std::ostream& operator<<(std::ostream& os, HashMap<size_>& rhs)
{
	for (size_t i = 0; i < size_; i++)
	{
		if (rhs.table_[i].values_.empty())
			continue;
		LinkedList::Node* cur = rhs.table_[i].values_.get_head();
		while (cur != nullptr)
		{
			os << cur->get_val() << ' ';
			cur = cur->get_next();
		}
		os << '\n';
	}
	return os;
}