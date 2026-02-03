#include <iostream>
using namespace std;

// Color enumeration
enum Color { RED, BLACK };

// Node structure
struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        color = RED;              // New nodes are RED
        left = right = parent = nullptr;
    }
};

// Red-Black Tree class
class RedBlackTree {
private:
    Node* root;

    // LEFT ROTATION
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    // RIGHT ROTATION
    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;

        if (x->right != nullptr)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    // FIX VIOLATIONS AFTER INSERTION
    void fixInsert(Node* k) {
        while (k != root && k->parent->color == RED) {
            Node* parent = k->parent;
            Node* grandparent = parent->parent;

            // Parent is left child
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is RED
                if (uncle && uncle->color == RED) {
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    k = grandparent;
                }
                else {
                    // Case 2: Left-Right
                    if (k == parent->right) {
                        leftRotate(parent);
                        k = parent;
                        parent = k->parent;
                    }

                    // Case 3: Left-Left
                    parent->color = BLACK;
                    grandparent->color = RED;
                    rightRotate(grandparent);
                }
            }
            // Parent is right child (mirror case)
            else {
                Node* uncle = grandparent->left;

                if (uncle && uncle->color == RED) {
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    k = grandparent;
                }
                else {
                    // Case 2: Right-Left
                    if (k == parent->left) {
                        rightRotate(parent);
                        k = parent;
                        parent = k->parent;
                    }

                    // Case 3: Right-Right
                    parent->color = BLACK;
                    grandparent->color = RED;
                    leftRotate(grandparent);
                }
            }
        }
        root->color = BLACK; // Root must always be BLACK
    }

    // INORDER TRAVERSAL
    void inorder(Node* node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << (node->color == RED ? "(R) " : "(B) ");
        inorder(node->right);
    }

public:
    RedBlackTree() {
        root = nullptr;
    }

    // INSERT FUNCTION
    void insert(int data) {
        Node* node = new Node(data);
        Node* parent = nullptr;
        Node* curr = root;

        // Standard BST insertion
        while (curr != nullptr) {
            parent = curr;
            if (data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        node->parent = parent;

        if (parent == nullptr)
            root = node;
        else if (data < parent->data)
            parent->left = node;
        else
            parent->right = node;

        fixInsert(node);
    }

    // DISPLAY TREE
    void display() {
        inorder(root);
        cout << endl;
    }
};

// MAIN FUNCTION
int main() {
    RedBlackTree tree;

    // Insert sequence
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(35);

    cout << "Inorder traversal (with colors):\n";
    tree.display();

    return 0;
}