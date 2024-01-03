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
* binary_tree_is_perfect - function that checks if a binary tree is perfect.
* @tree: is a pointer to the root node of the tree to check.
* Return: If tree is NULL, your function must return 0.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
		else if (tree->left != NULL && tree->right != NULL)
			return (binary_tree_is_perfect(tree->left) &&
							binary_tree_is_perfect(tree->right));
	}

	return (0);
}
