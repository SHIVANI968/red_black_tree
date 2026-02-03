# red_black_tree
Red-Black Tree Implementation in C++
📌 Overview

This project provides a C++ implementation of a Red-Black Tree, a self-balancing Binary Search Tree (BST).
The implementation supports insertion with automatic rebalancing using rotations and recoloring to maintain Red-Black Tree properties.

Red-Black Trees guarantee O(log n) time complexity for search, insertion, and deletion, making them widely used in real-world systems such as databases, operating systems, and language libraries.

🧠 Key Concepts

A Red-Black Tree follows these properties:

Every node is either RED or BLACK

The root node is always BLACK

All leaf nodes (null pointers) are considered BLACK

Red nodes cannot have red children

Every path from a node to its descendant leaves has the same number of black nodes

✨ Features

Binary Search Tree insertion

Automatic balancing using:

Left Rotation

Right Rotation

Fixing Red-Black Tree violations

Inorder traversal with color indication

Clean and modular object-oriented design

🏗️ Project Structure
RedBlackTree.cpp
├── Node structure
├── RedBlackTree class
│   ├── leftRotate()
│   ├── rightRotate()
│   ├── fixInsert()
│   ├── insert()
│   ├── inorder()
│   └── display()
└── main()

🚀 How It Works

Nodes are inserted following BST rules

Every new node is initially colored RED

If Red-Black properties are violated:

The tree is rebalanced using rotations

Nodes are recolored appropriately

The root node is enforced as BLACK

🧪 Sample Input
tree.insert(10);
tree.insert(20);
tree.insert(30);
tree.insert(40);
tree.insert(35);

📤 Sample Output
Inorder traversal (with colors):
10(B) 20(B) 30(R) 35(B) 40(R)


(Note: Colors may vary based on rotation order, but Red-Black properties are always maintained.)

⏱️ Time & Space Complexity
Operation	Time Complexity	Space Complexity
Insertion	O(log n)	O(1)
Traversal	O(n)	O(h)

where h = height of the tree

💻 Compilation & Execution
g++ RedBlackTree.cpp -o rbt
./rbt

📚 Applications

Database indexing

Memory management

Operating systems scheduling

STL map and set implementations

File systems
