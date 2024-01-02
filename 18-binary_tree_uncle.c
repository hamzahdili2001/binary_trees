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
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->parent && node->parent->left == node)
		return (node->parent->parent->left);
	else if (node->parent->parent && node->parent->right == node)
		return (node->parent->parent->right);
	else
		return (NULL);
}
