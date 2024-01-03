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
	size_t left_height = 0, right_height = 0;

	if (tree)
	{
		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}
