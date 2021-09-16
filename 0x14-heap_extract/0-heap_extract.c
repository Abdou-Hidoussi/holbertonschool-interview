#include "binary_trees.h"

/**
 * binary_tree_height - Holberton
 *
 * @tree: Pointer to the tree
 * Return: Length  of tree
 */
int binary_tree_height(const heap_t *tree)
{
	int r, l;

	if (!tree)
		return (0);
	l = 0;
	r = 0;
	if (tree->left)
		l += 1;
	if (tree->right)
		r += 1;
	r += binary_tree_height(tree->right);
	l += binary_tree_height(tree->left);
	if (r > l)
		return (r);
	return (l);
}
/**
 * switchrue - switch values
 * @o: Pointer to element of the tree
 * @n: Pointer to element of the tree
 */
void switchrue(heap_t **o, heap_t **n)
{
	heap_t *old = *o, *new = *n;
	int tmp;

	tmp = old->n;
	old->n = new->n;
	new->n = tmp;
}
/**
 * heap_extract - extract value
 * @root: Pointer to the tree
 * Return: the extracted node or 0
 */
int heap_extract(heap_t **root)
{
	heap_t *new, *old;
	int r = 0, l = 0, ret;

	if (!root)
		return (0);
	old = *root;
	new = *root;
	ret = old->n;
	while (new->right || new->left)
	{
		r = binary_tree_height(new->right);
		l = binary_tree_height(new->left);
		if (r < l || new->right == NULL)
			new = new->left;
		else
			new = new->right;
	}
	switchrue(&old, &new);
	if (new->parent->right && new->parent->right == new)
		new->parent->right = NULL;
	else
		new->parent->left = NULL;
	new->parent = NULL;
	free(new);
	old = *root;
	while (old->right || old->left)
	{
		if (old->right->n < old->left->n)
		{
			switchrue(&old, &old->left);
			old = old->left;
		}
		else
		{
			switchrue(&old, &old->right);
			old = old->right;
		}
	}
	return (ret);
}
