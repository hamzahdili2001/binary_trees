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
	binary_tree_t *temp = NULL;

	return (binary_tree_is_bst_util(tree, temp));
}

/**
 * binary_tree_is_bst_util - function that checks if a binary tree
 * is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
 * @node: pointer to temporary node
 *
 * Return:
 * - 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst_util(const binary_tree_t *tree, binary_tree_t *node)
{
	if (tree)
	{
		if (!binary_tree_is_bst_util(tree->left, node))
			return (0);

		if (node != NULL && tree->n <= node->n)
			return (0);

		node = (binary_tree_t *)tree;

		return (binary_tree_is_bst_util(tree->right, node));
	}

	return (1);
}
