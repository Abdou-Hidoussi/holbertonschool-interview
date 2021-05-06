#include "binary_trees.h"
/**
 * smol - return the smallest size of a tree
 * @parent: parent of the new node
 * Return: smallest size
 */
int smol(heap_t *parent)
{
	if (!parent->right || !parent->left)
		return (0);

	if (parent->left)
		return (smol(parent->left) + 1);

	if (parent->right)
		return (smol(parent->right) + 1);

	return (0);
}

/**
 * switchrue - switch the value of the leaf with the parent
 * @root: parent of the new node
 * Return: new node created
 */
heap_t *switchrue(heap_t **root)
{
	heap_t *parent;
	int tmp;

	parent = *root;
	while (parent->parent->n < parent->n)
	{
		tmp = parent->parent->n;
		parent->parent->n = parent->n;
		parent->n = tmp;
		parent = parent->parent;
		if (!parent->parent)
			break;
	}
	return (parent);
}

/**
 * heap_insert - create new node
 * @root: parent of the new node
 * @value: value to put in new node
 * Return: new node created
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;

	parent = *root;
	if (!parent)
	{
		*root =  binary_tree_node(parent, value);
		return (*root);
	}

	if (!parent->left)
	{
		parent->left = binary_tree_node(parent, value);
		return (switchrue(&parent->left));
	}
	if (!parent->right)
	{
		parent->right = binary_tree_node(parent, value);
		return (switchrue(&parent->right));
	}

	if (smol(parent->left) <= smol(parent->right))
		return (heap_insert(&parent->left, value));
	else
		return (heap_insert(&parent->right, value));
}
