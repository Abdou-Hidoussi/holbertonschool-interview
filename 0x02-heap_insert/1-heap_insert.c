#include "binary_trees.h"

int smol(heap_t *parent)
{
    if (!parent->right || !parent->left)
        return (0);

    if (parent->left)
        return smol(parent->left) + 1;

    if (parent->right)
        return smol(parent->right) + 1;

    return (0);
}


void switchrue(heap_t **root)
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
		{
			break;
		}
		
	}
	
}


heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent;
	parent = *root;

	if (!parent)
	{
		*root =  binary_tree_node(parent, value);
		return *root;
	}

	if (!parent->left)
	{
		parent->left = binary_tree_node(parent, value);
		switchrue(&parent->left);
		return parent;
	}
	if (!parent->right)
	{
		parent->right = binary_tree_node(parent, value);
		switchrue(&parent->right);
		return parent;
	}

	if (smol(parent->left) <= smol(parent->right))
		return (heap_insert(&parent->left, value));
	else
		return (heap_insert(&parent->right, value));
	
}
