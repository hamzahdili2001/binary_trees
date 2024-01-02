#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size
 *                     of a node in a binary tree.
 * @tree: is a pointer to the node to measure the size
 * Return: 0 if tree is NULL, otherwise its size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;
	binary_tree_t *left_node;
	binary_tree_t *right_node;

	if (tree == NULL)
		return (0);

	left_node = tree->left;
	right_node = tree->right;

	while (left_node != NULL)
	{
		left_node = left_node->left != NULL ? left_node->left
											: left_node->right;
		left_size++;
	}

	while (right_node != NULL)
	{
		right_node = right_node->right != NULL ? right_node->right
											   : right_node->left;
		right_size++;
	}

	return ((left_size + right_size) + 1);
}
