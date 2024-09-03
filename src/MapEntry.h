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

#ifndef SRC_MAPENTRY_H_
#define SRC_MAPENTRY_H_

namespace _11c_dev_collections {

/**
 * Map of a Key / Value pair.  This class holds a key / value pair as a single object.
 * It is used as a return value for collections that use a separate key and value.
 */
template <typename TKey, typename TValue>
struct MapEntry{
    TKey key;
    TValue value;

    MapEntry(TKey k, TValue v){
        key = k;
        value = v;
    }
};

}  // namespace _11c_dev_collections

#endif  // SRC_MAPENTRY_H_
