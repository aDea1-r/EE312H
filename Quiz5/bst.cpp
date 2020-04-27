
#include <iostream>
#include "bst.hpp"

BST::BST(void) : root(nullptr) { }

void BST::print(void) {
    Node *current = findMin();
    cout << "Printing BST" << endl;
    while (current != nullptr) {
        cout << current->val << " ";
        current = successor(current);
    }
    cout << endl;
}

BST::Node* BST::findMin(void) {
    if (root == nullptr) {
        return nullptr;
    }

    Node *current = root; // current != nullptr
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

BST::Node* BST::successor(Node *n) {
    if (n == nullptr) {
        return nullptr;
    }

    if (n->right != nullptr) {
        Node *current = n->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    } else {
        Node *parent = n->parent;
        while (parent != nullptr && (parent->left != n)) {
            n = parent;
            parent = n->parent;
        }
        return parent;
    }
}

bool BST::find(int el) {
    Node *current = root;
    while (current != nullptr) {
        if (current->val == el) {
            return true;
        }
        if (el < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

void BST::insert(int el) {
    Node *node = new Node(el);
    if (root == nullptr) {
        root = node;
    } else {
        Node *parent = nullptr;
        Node *current = root;
        while (current != nullptr) {
            parent = current;
            if (node->val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        // parent != nullptr && current == nullptr
        if (node->val < parent->val) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        node->parent = parent;
    }
}



int main(void) {
    BST bst;
    bst.insert(55);
    bst.insert(66);

    cout << bst.find(77) << endl;
    cout << bst.find(55) << endl;

    cout << (bst.findMin())->val << endl;

    bst.print();
}
