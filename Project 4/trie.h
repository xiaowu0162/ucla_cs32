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
	struct LabeledPtrToNext
	{
		char label;
		Trie<ValueType>* next;
	};
	struct Node
	{
		vector<ValueType> m_values;
		vector<LabeledPtrToNext> m_children;
	};
	Node* m_root;
	
	//delete all the Nodes in the current trie
	void clearAll(Node* root);
};

template <typename ValueType>
Trie<ValueType>::Trie()
{
	m_root = new Node;
}

template <typename ValueType>
Trie<ValueType>::~Trie()
{
	clearAll(m_root);
}

template <typename ValueType>
void Trie<ValueType>::reset()
{
	clearAll(m_root);
	m_root = new Node;
}



template <typename ValueType>
void Trie<ValueType>::clearAll(Node* root)
{
	if (root == nullptr)
		return;
	if (!root->m_children.empty())
	{
		for (int i = 0; i < root->m_children.size(); i++)
			clearAll(root->m_children[i]);
	}
}


#endif // TRIE_INCLUDED
