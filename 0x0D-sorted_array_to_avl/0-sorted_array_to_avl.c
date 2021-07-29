#include "binary_trees.h"

/**
 * new_node - create a node
 * @n: value of node
 * @parent:parent node
 * Return: newly created node or null
 */
avl_t *new_node(int n, avl_t *parent)
{
	avl_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->n = n;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/**
 * loop - search where to add in tree
 * @parent: parent node
 * @array: array of values
 * @left: left index
 * @right: right index
 * Return: null or last node
 */
avl_t *loop(avl_t *parent, int *array, int left, int right)
{
	avl_t *new;
	int i;

	if (left > right)
		return (NULL);
	i = (left + right) / 2;
	new = new_node(array[i], parent);
	if (!new)
		return (NULL);
	new->left = loop(new, array, left, i - 1);
	new->right = loop(new, array, i + 1, right);
	return (new);
}

/**
 * sorted_array_to_avl - build AVL tree from array
 * @array: pointer to first element of array
 * @size: size of array
 *
 * Return:  root or null
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (loop(NULL, array, 0, size - 1));
}
