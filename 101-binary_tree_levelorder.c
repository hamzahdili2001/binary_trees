#include "binary_trees.h"

/**
 * binary_tree_height - function that feasures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL the function must return 0, else return height.
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

/**
 * binary_tree_levelorder - function that goes through
 * a binary tree using level-order traversal
 *
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height;
	size_t i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
		binary_tree_print_level(tree, func, i);
}

/**
 * binary_tree_print_level - function that prints level
 *
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 * @level: level of the binary tree
 */
void binary_tree_print_level(
	const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else
	{
		binary_tree_print_level(tree->left, func, level - 1);
		binary_tree_print_level(tree->right, func, level - 1);
	}
}
