/*
 * Copyright 2024 Jim Haslett
 *
 * This file is part of the 11c.dev AVL Balanced Binary Search Tree implementation.
 *
 * AVL Balanced Binary Search Tree is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * AVL Balanced Binary Search Tree is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * the AVL Balanced Binary Search Tree. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef SRC_AVLTREENODE_H_
#define SRC_AVLTREENODE_H_

#include "MapEntry.h"


namespace _11c_dev_collections {

/**
 * Node used in an AVLTree.
 *
 * @param <TKey>	Generic type representing the key used for sorting.  Must implement <, =, and >.
 * @param <TValue>	Generic type representing the data being stored.
 */
template <typename TKey, typename TValue>
class AVLTreeNode{
 private:
    TKey key_;
    TValue value_;
    AVLTreeNode<TKey, TValue> *left_;
    AVLTreeNode<TKey, TValue> *right_;
    int height_;

 public:
	/**
	 * Creates a leaf node with no left or right children.
	 * 
	 * @param Key		Key used for sorting.  Must be Comparable.
	 * @param Value		Data being stored in the Tree.
	 */
    AVLTreeNode(TKey key, TValue value) {
        key_ = key;
        value_ = value;
        left_ = nullptr;
        right_ = nullptr;
        CalculateHeight();
    }

	/**
	 * Get the value of the TreeNode.
	 * 
	 * @return Value (TValue).
	 */
    TValue GetValue() { return value_; }

    /**
	 * Set the value of the TreeNode.
	 * 
	 * @param value Set the nodes value.
	 */
    void SetValue(TValue value) { value_ = value; }

	/**
	 * Get the key of the TreeNode.
	 * 
	 * @return Key.
	 */    
    TKey GetKey() { return key_; }

    /**
	 * Get the Left child TreeNode.  The Left child is the "smaller" key.
	 * 
	 * @return Left child node.
	 */
    AVLTreeNode<TKey, TValue>* GetLeft() { return left_; }

	/**
	 * Get the Right child TreeNode.  The Right child is the "larger" key.
	 * 
	 * @return Right child node.
	 */      
    AVLTreeNode<TKey, TValue>* GetRight() { return right_; }

	/**
	 * Set the Left child TreeNode.  The Left child is the "smaller" key.
	 * 
	 * @param node	Set the left child node.
	 */    
    void SetLeft(AVLTreeNode<TKey, TValue> *node) { left_ = node; }

  	/**
	 * Set the Right child TreeNode.  The Right child is the "larger" key.

	 * @param node	Set the right child node.
	 */
    void SetRight(AVLTreeNode<TKey, TValue> *node) { right_ = node; }

	/**
	 * @return Height of the node.
	 */
    int GetHeight() { return height_; }

	/**
	 * Get the balance factor of the current node.  Compares height if right and left child nodes.  Used to determine how balanced this node is.
	 * 
	 * @return	Balance factor of the node.  
	 */    
    int GetBalanceFactor() {
        int r, l;
        r = (right_ == nullptr) ? -1 : right_->GetHeight();
        l = (left_ == nullptr) ? -1 : left_->GetHeight();
        return l - r;
    }

	/**
	 * Get a MapEntry representing teh key / value pair of this TreeNode.
	 * 
	 * @return	MapEntry representing the Key and Value of the node.
	 */
    MapEntry<TKey, TValue> GetMapEntry() {
        return MapEntry<TKey, TValue>(key_, value_);
    }

	/**
	 * Recalcualtes the height of the node.
	 */
    void CalculateHeight() {
        int r, l;
        r = (right_ == nullptr) ? -1 : right_->GetHeight();
        l = (left_ == nullptr) ? -1 : left_->GetHeight();
        height_ = (r > l) ? r + 1 : l + 1;
    }
};
}  // namespace _11c_dev_collections

#endif  // SRC_AVLTREENODE_H_
