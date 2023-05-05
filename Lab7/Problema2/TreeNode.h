#include <iostream>

using namespace std;

template <class T>
using boolFtt = bool(*)(T, T);


template <class T>
class node
{
public:
	T value;
	node<T>** copii;
	node<T>* Parents;
	unsigned int nrCopii;
	unsigned int maxNrCopii;
};

template <class T>
#pragma once
class TreeNode
{
public:

	TreeNode(unsigned int increase);
	void add_node(T elem, node<T>* parent = nullptr);
	node<T>* get_node(unsigned int index = 0, node<T>* parent = nullptr)
	{
		if (parent == nullptr) return root;

		if (index < parent->nrCopii)
			return (parent->copii[index]);
		else
			return (parent->copii[0]);
	}
	void delete_node(node<T>* Deleted);
	node<T>* find(T element, boolFtt<T> comparison = nullptr)
	{
		return cautare(root, element, comparison);
	}
	void insert(node<T>* parent, unsigned int index, T element);
	void sort(node<T>* parent, boolFtt<T> comparison = nullptr);
	unsigned int count(node<T>* parent);
	void print();
	~TreeNode();
protected:
private:
	node<T>* root;
	unsigned int GrowSpace;

	node<T>* cautare(node<T>* present, T element, boolFtt<T> comparison)
	{
		int i;
		if (present != nullptr)
		{
			if (comparison != nullptr ? comparison(present->value, element) : present->value == element)
				return present;

			node<T>* aux = nullptr;
			for (i = 0; i < present->nrCopii; i++)
			{
				aux = cautare(present->copii[i], element, comparison);
				if (aux != nullptr)
					break;
			}

			return aux;
		}
		else
			return nullptr;
	}
	void NewNode(node<T>* parent, T element)
	{
		node<T>* generate;
		if (parent != nullptr)
		{
			++parent->nrCopii;
			generate = parent->copii[parent->nrCopii - 1] = new node<T>;
		}
		else
			generate = root = new node<T>;

		generate->value = element;
		generate->copii = nullptr;
		generate->Parents = parent;
		generate->maxNrCopii = 0;
		generate->nrCopii = 0;
	}
	void increasing(node<T>* parent)
	{
		int i;
		parent->maxNrCopii += GrowSpace;
		node<T>** aux = new node<T> *[parent->maxNrCopii];

		for (i = 0; i < parent->nrCopii; ++i)
			aux[i] = parent->copii[i];

		delete[] parent->copii;
		parent->copii = aux;
	}
	void addingLevel(int level, node<T>* present)
	{
		int i;
		if (present != nullptr)
		{
			if (present->nrCopii > 0)
			{
				cout << "Nivelul este: " << level << "->" << present->value << "-> ";
				for (i = 0; i < present->nrCopii; i++)
					cout << present->copii[i]->value << ' ';
				cout << endl;

				for (i = 0; i < present->nrCopii; i++)
					addingLevel(level + 1, present->copii[i]);
			}
		}
	}

	void mutare(node<T>* Deleted)
	{
		unsigned int index = 0;
		node<T>* parent = Deleted->Parents;

		for (unsigned int i = 0; i < parent->nrCopii; i++)
			if (parent->copii[i]->value == Deleted->value)
			{
				index = i;
				break;
			}

		for (unsigned int i = index; i < parent->nrCopii - 1; i++)
			parent->copii[i] = parent->copii[i + 1];
	}
};
template <class T>
bool smaller(T a, T b)
{
	return a < b;
}

template <class T>
TreeNode<T>::TreeNode(unsigned int increase)
{
	if (increase > 0)
		GrowSpace = increase;
	else
		GrowSpace = 20;
	root = new node<T>;
}

template <class T>
void TreeNode<T>::add_node(T element, node<T>* parent)
{
	if (parent != nullptr)
		if (parent->nrCopii == parent->maxNrCopii)
			increasing(parent);

	NewNode(parent, element);
}

template <class T>
void TreeNode<T>::delete_node(node<T>* Deleted)
{
	int i;
	if (Deleted->Parents != nullptr)
	{
		mutare(Deleted);
		--Deleted->Parents->nrCopii;
	}

	for (i = 0; i < Deleted->nrCopii; i++)
		delete_node(Deleted->copii[i]);

	delete Deleted;
}

template <class T>
void TreeNode<T>::insert(node<T>* parent, unsigned int index, T element)
{
	int i;
	if (index > parent->nrCopii)
		index = parent->nrCopii;

	if (parent->nrCopii == parent->maxNrCopii)
		increasing(parent);

	NewNode(parent, element);

	node<T>* aux = parent->copii[parent->nrCopii - 1];
	for (i = parent->nrCopii - 1; i > index; --i)
		parent->copii[i] = parent->copii[i - 1];
	parent->copii[index] = aux;
}

template <class T>
void TreeNode<T>::sort(node<T>* parent, boolFtt<T> comparison)
{
	int i, j;
	if (comparison == nullptr)
		comparison = &smaller;

	for (i = 0; i < parent->nrCopii - 1; i++)
		for (j = i + 1; j < parent->nrCopii; j++)
			if (!comparison(parent->copii[i]->value, parent->copii[j]->value))
			{
				node<T>* aux = parent->copii[i];
				parent->copii[i] = parent->copii[j];
				parent->copii[j] = aux;
			}
}

template <class T>
void TreeNode<T>::print()
{
	cout << "Nivelul este: 0 ->" << root->value << '\n';
	addingLevel(1, root);
}

template <class T>
unsigned int TreeNode<T>::count(node<T>* parent)
{
	return parent->nrCopii;
}

template <class T>
TreeNode<T>::~TreeNode()
{
	delete_node(root);
}