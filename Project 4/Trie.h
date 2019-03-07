#ifndef TRIE_INCLUDED
#define TRIE_INCLUDED

#include <string>
#include <vector>


template<typename ValueType>
class Trie
{
public:
	Trie();
	~Trie();
	void reset();
	void insert(const std::string& key, const ValueType& value);
	std::vector<ValueType> find(const std::string& key, bool exactMatchOnly) const;

	// C++11 syntax for preventing copying and assignment
	Trie(const Trie&) = delete;
	Trie& operator=(const Trie&) = delete;
private:	
	struct Node;
	struct LabeledPtrToNext
	{
		char label;
		Node* next;
	};
	struct Node
	{
		std::vector<ValueType> values;
		std::vector<LabeledPtrToNext> children;
	};
	Node* root;

	//delete all the Nodes in the current trie
	void clearAll(Node* root);
};

template <typename ValueType>
Trie<ValueType>::Trie()
{
	root = new Node;
}

template <typename ValueType>
Trie<ValueType>::~Trie()
{
	clearAll(root);
}

template <typename ValueType>
void Trie<ValueType>::reset()
{
	clearAll(root);
	root = new Node;
}







//Helper: delete all the Nodes in the current trie
template <typename ValueType>
void Trie<ValueType>::clearAll(Node* root)
{
	if (root == nullptr)
		return;
	if (!root->children.empty())
	{
		for (unsigned int i = 0; i < root->children.size(); i++)
			clearAll(root->children[i].next);
	}
}


#endif // TRIE_INCLUDED
