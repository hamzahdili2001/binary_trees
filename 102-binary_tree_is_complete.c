#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The size of the tree starting at @node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}


/**
 * is_complete - Helper function to recursively check
 *               if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node
 * @size: Number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
					is_complete(tree->right, 2 * index + 2, size));
}

/**
* binary_tree_is_complete - checks if a binary tree is complete.
* @tree:  is a pointer to the root node of the tree to check.
* Return: If tree is NULL, your function must return 0.
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete(tree, 0, binary_tree_size(tree)));
}

