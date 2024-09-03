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

#include <iostream>

#include "MapEntry.h"

/**
 * Node used in an AVLTree.
 *
 * @param <TKey>	Generic type representing the key used for sorting.  Must implement <, =, and >.
 * @param <TValue>	Generic type representing the data being stored.
 */
namespace _11c_dev_collections {
/**
 * Node used in an AVLTree.
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
    AVLTreeNode(TKey key, TValue value) {
        key_ = key;
        value_ = value;
        left_ = nullptr;
        right_ = nullptr;
        CalculateHeight();
    }


    TValue GetValue() { return value_; }
    void SetValue(TValue value) { value_ = value; }
    TKey GetKey() { return key_; }

    AVLTreeNode<TKey, TValue>* GetLeft() { return left_; }
    AVLTreeNode<TKey, TValue>* GetRight() { return right_; }
    void SetLeft(AVLTreeNode<TKey, TValue> *node) { left_ = node; }
    void SetRight(AVLTreeNode<TKey, TValue> *node) { right_ = node; }

    int GetHeight() { return height_; }
    int GetBalanceFactor() {
        int r, l;
        r = (right_ == nullptr) ? -1 : right_->GetHeight();
        l = (left_ == nullptr) ? -1 : left_->GetHeight();
        return l - r;
    }

    MapEntry<TKey, TValue> GetMapEntry() {
        return MapEntry<TKey, TValue>(key_, value_);
    }

    void CalculateHeight() {
        int r, l;
        r = (right_ == nullptr) ? -1 : right_->GetHeight();
        l = (left_ == nullptr) ? -1 : left_->GetHeight();
        height_ = (r > l) ? r + 1 : l + 1;
    }



    void Debug() {
        std::cout << "<DEBUG (" << key_ << ")> ME: " << this << "  HEIGHT: "
            << height_ << "  LEFT: " << left_ << "  RIGHT: " << right_
            << std::endl;
    }
};
}  // namespace _11c_dev_collections

#endif  // SRC_AVLTREENODE_H_
