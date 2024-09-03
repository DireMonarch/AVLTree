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


#include "AVLTreeNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <memory>

/**
 * Used for testing only, not part of the actual package
 */
int main(int argc, char *argv[]) {
    _11c_dev_collections::AVLTree<int, std::string> tree =
        _11c_dev_collections::AVLTree<int, std::string>();

    for (int i = 0; i < 255; i++) {
        tree.Add(i, std::to_string(i));
    }


    std::cout << std::endl << std::endl << std::endl;

    tree.SetTraversalMethod(
        _11c_dev_collections::AVLTreeTraversalMethod::TopDown);

    for ( auto me : tree ) {
        std::cout << "Main, printing: " << me.GetValue() << std::endl;
    }

    std::cout << "Tree Height: " << tree.GetTreeHieight()
        << "  Balance Factor: "<< tree.GetTreeBalanceFactor()
        << "  Tree Size: " << tree.GetCount() << std::endl;
}
