#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height
 *                     of a node in a binary tree
 * @tree: is a pointer to the node to measure the height
 *
 * Return: 0 if tree is null, otherwise its height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (height);

	while (tree != NULL && (tree->left != NULL || tree->right != NULL))
	{
		height++;
		tree = tree->left != NULL ? tree->left : tree->right;
	}

	return (height);
}
