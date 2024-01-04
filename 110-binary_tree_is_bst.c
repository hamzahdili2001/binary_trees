#include "binary_trees.h"

/**
 * binary_tree_is_bst - function that checks if a binary tree
 * is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return:
 * - 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (binary_tree_is_bst_util(tree, NULL, NULL));
}

/**
 * binary_tree_is_bst_util - function that checks if a binary tree
 * is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 * @min: min node
 * @max: max node
 *
 * Return:
 * - 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst_util(
	const binary_tree_t *tree,
	const binary_tree_t *min,
	const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if (
		(min != NULL && tree->n <= min->n) ||
		(max != NULL && tree->n >= max->n))
		return (0);

	return (
		binary_tree_is_bst_util(tree->left, min, tree) &&
		binary_tree_is_bst_util(tree->right, tree, max));
}
