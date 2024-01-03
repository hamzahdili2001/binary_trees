#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 *
 * @node: pointer to the node to find the uncle
 *
 * Return:
 * - NULL, If node is NULL or the parent is NULL
 * - NULL, If node has no uncle
 * - Otherwise, pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grand_parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grand_parent = parent->parent;

	if (grand_parent->left == NULL || grand_parent->right == NULL)
		return (NULL);

	if (grand_parent->left == parent)
		return (grand_parent->right);
	else
		return (grand_parent->left);
}
