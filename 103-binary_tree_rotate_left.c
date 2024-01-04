#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a
 * left-rotation on a binary tree
 *
 * @tree: is a pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	temp = pivot->left;
	pivot->left = tree;
	tree->right = temp;

	if (temp != NULL)
		temp->parent = tree;

	temp = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp;

	if (temp != NULL)
	{
		if (temp->right == tree)
		{
			temp->right = pivot;
		}
		else
		{
			temp->left = pivot;
		}
	}
	return (pivot);
}
