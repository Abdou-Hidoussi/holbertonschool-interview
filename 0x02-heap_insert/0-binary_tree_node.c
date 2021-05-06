#include "binary_trees.h"
/**
 * binary_tree_node - create new node
 * @parent: parent of the new node
 * @value: value to put in new node
 * Description: create a new node
 * Return: new node created
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
