
#include <iostream>
#include "bst.hpp"
#include <cassert>

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

int BST::sumRec() {
    if (root == nullptr)
        return 0;
    return root->sumRec();
}

int BST::Node::sumRec() {
    if (this->left == nullptr && this->right == nullptr) {
        return this->val;
    }
    if (this->left == nullptr && this->right != nullptr) {
        return this->val + this->right->sumRec();
    }
    if (this->left != nullptr && this->right == nullptr) {
        return this->val + this->left->sumRec();
    }
    return this->left->sumRec() + this->val + this->right->sumRec();
}

void testEmptyTree() {
    BST bst;
    assert(0 == bst.sumRec());
}

void testSingleNodeTree() {
    BST bst;
    bst.insert(777);
    assert(777 == bst.sumRec());
}

void testMoreNodes() {
    BST bst;
    bst.insert(50);
    bst.insert(60);
    bst.insert(40);
    assert(150 == bst.sumRec());
}

void testEvenMoreNodes() {
    BST bst;
    bst.insert(50);
    bst.insert(60);
    bst.insert(40);
    bst.insert(55);
    bst.insert(30);
    bst.insert(58);
    assert(293 == bst.sumRec());
}

int main(void) {
    cout << "Starting Empty Tree" << endl;
    testEmptyTree();
    cout << "Finished Empty Tree" << endl;
    cout << "Starting Single Node Tree" << endl;
    testSingleNodeTree();
    cout << "Finished Single Node Tree" << endl;
    cout << "Starting Test More Nodes" << endl;
    testMoreNodes();
    cout << "Finished Test More Nodes" << endl;
    cout << "Starting Test Even More Nodes" << endl;
    testEvenMoreNodes();
    cout << "Finished Test Even More Nodes" << endl;
}
