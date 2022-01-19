#include "binary_trees.h"

/**
* avl_check - checks if BST is a valid AVL tree
* @node: node of a tree
* @min: value of min node
* @max: value of max node
* @height: height of the tree
* Return: 1 if it is AVL tree, 0 otherwise
*/
int avl_check(const binary_tree_t *node, int min, int max, int *height)
{
	int height_l, height_r;

	height_r = 0;
	height_l = 0;

	if (!node)
		return (1);
	if (node->n <= min || node->n >= max)
		return (0);
	if (!avl_check(node->left, min, node->n, &height_l) ||
			!avl_check(node->right, node->n, max, &height_r))
		return (0);
	if (height_l > height_r)
		*height = height_l + 1;
	else
		*height = height_r + 1;
	return (abs(height_l - height_r) < 2);
}

/**
 * binary_tree_is_avl - function that checks if a
 * binary tree is a valid AVL Tree
 * @tree: binary tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (avl_check(tree, INT_MIN, INT_MAX, &height));
}
