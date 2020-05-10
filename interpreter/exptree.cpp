
#include <vector>
#include <string>
#include <iostream>
#include "exptree.hpp"

ExpTree::Node* ExpTree::parse(vector<string> &expr) {
    if (expr.size() == 0) {
        return nullptr;
    }

    string token = expr[0];
    expr.erase(expr.begin());
    if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "&&" || token == "||" || token == "<" || token == ">" || token == "==" || token == "!=" || token == "<=" || token == ">=" || token == "!" || token == "~") {
        Node *left = parse(expr);
        Node* right;
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "&&" || token == "||" || token == "<" || token == ">" || token == "==" || token == "!=" || token == "<=" || token == ">=")
            right = parse(expr);
        else
            right = new Node(0);
        return new Node(token, left, right);
    } else {
        return new Node(stoi(token));
    }
}

ExpTree::ExpTree(vector<string> expr) {
    this->root = parse(expr);
}

void ExpTree::printInfix() const {
    // TODO
}

void ExpTree::printPrefix() const {
    // TODO
}

int32_t ExpTree::eval() const {
    if (root == nullptr) {
        return 0;
    } else {
        return root->eval();
    }
}

#ifdef fjsd
int main() {
    vector<string> expr; // { "+", "3", "*", "5", "2" };
    expr.push_back("+");
    expr.push_back("3");
    expr.push_back("*");

    ExpTree tree(expr);

    tree.printInfix();
    tree.printPrefix();

    return 0;
}
#endif