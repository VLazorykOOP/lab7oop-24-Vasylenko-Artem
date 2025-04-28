#include <iostream>

#include "console.h"
#include "taskManager.h"

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node *left;
	Node *right;

	Node(const T &value);
};

template <typename T>
Node<T>::Node(const T &value) : data(value), left(nullptr), right(nullptr) {}

template <typename T>
class BinaryTree
{
private:
	Node<T> *root;
	void destroyTree(Node<T> *node);
	Node<T> *insertTree(Node<T> *node, const T &value);

public:
	BinaryTree();
	~BinaryTree();
	void insert(const T &value);

	class Iterator
	{
	private:
		static const int MAX_STACK_SIZE = 100;
		Node<T> *stack[MAX_STACK_SIZE];
		int stackSize;
		Node<T> *current;

	public:
		Iterator(Node<T> *root);
		bool hasNext();
		T next();
	};

	Iterator getIterator() { return Iterator(root); }
};

template <typename T>
void BinaryTree<T>::destroyTree(Node<T> *node)
{
	if (node != nullptr)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

template <typename T>
Node<T> *BinaryTree<T>::insertTree(Node<T> *node, const T &value)
{
	if (node == nullptr)
		return new Node<T>(value);

	if (value < node->data)
		node->left = insertTree(node->left, value);
	else if (value > node->data)
		node->right = insertTree(node->right, value);

	return node;
}

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
BinaryTree<T>::~BinaryTree() { destroyTree(root); }

template <typename T>
void BinaryTree<T>::insert(const T &value) { root = insertTree(root, value); }

template <typename T>
BinaryTree<T>::Iterator::Iterator(Node<T> *root) : stackSize(0), current(root)
{
	while (current != nullptr)
	{
		stack[stackSize++] = current;
		current = current->left;
	}
}

template <typename T>
bool BinaryTree<T>::Iterator::hasNext() { return stackSize > 0; }

template <typename T>
T BinaryTree<T>::Iterator::next()
{
	if (!hasNext())
		throw "No more elements";

	Node<T> *node = stack[--stackSize];
	T result = node->data;

	if (node->right != nullptr)
	{
		current = node->right;
		while (current != nullptr)
		{
			stack[stackSize++] = current;
			current = current->left;
		}
	}
	return result;
}

void task_04()
{
	BinaryTree<int> tree;

	tree.insert(4);
	tree.insert(2);
	tree.insert(6);
	tree.insert(1);
	tree.insert(3);
	tree.insert(5);
	tree.insert(7);

	// 	        4
	//       /   \
	//     2       6
	//    / \     / \
	//   1   3   5   7

	BinaryTree<int>::Iterator it = tree.getIterator();

	while (it.hasNext())
		std::cout << it.next() << " ";
	std::cout << std::endl;
}
