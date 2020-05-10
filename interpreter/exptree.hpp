#include <vector>
#include <string>
#include <cstdint>

using namespace std;

class ExpTree {

    class Node {
    private:
        /* says if the node is operator or operand */
        bool is_operand;

        /* value of the operand if this is an operand node */
        int operand;

        /* '+', '-', '*' (and we can add more) */
        string optr;

        /* left subtree */
        Node *left;

        /* right subtree */
        Node *right;

    public:
        Node(const int operand) {
            this->is_operand = true;
            this->operand = operand;
            this->optr = '0';
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(string optr, Node* left, Node *right) {
            this->is_operand = false;
            this->operand = 0;
            this->optr = optr;
            this->left = left;
            this->right = right;
        }

        int32_t eval() const {
            if (is_operand) {
                return operand;
            } else {
                int32_t lv = left->eval();
                int32_t rv = right->eval();
                if (optr == "+") {
                    return lv + rv;
                } else if (optr == "*") {
                    return lv * rv;
                } else if (optr == "-") {
                    return lv - rv;
                } else if (optr == "/")
                    return lv/rv;
                else if (optr == "%")
                    return lv%rv;
                else if (optr == "&&")
                    return lv&&rv;
                else if (optr == "||")
                    return lv||rv;
                else if (optr == "<")
                    return lv<rv;
                else if (optr == ">")
                    return lv>rv;
                else if (optr == "==")
                    return lv==rv;
                else if (optr == "!=")
                    return lv!=rv;
                else if (optr == "<=")
                    return lv<=rv;
                else if (optr == ">=")
                    return lv>=rv;
                else if (optr == "!")
                    return !lv;
                else if (optr == "~")
                    return -1 * lv;
            }
            return 0;
        }

        /* TODO: Copy constructor */
        // Node(const Node &other);

        /* TODO: Destructor */
        // ~Node();

        /* TODO: Assignment operator */
        // Node& operator=(const Node &other);

        void printInfix() const {
            if (is_operand) {
                cout << operand << ' ';
            } else {
                if (left != nullptr) {
                    left->printInfix();
                }
                cout << optr << ' ';
                if (right != nullptr) {
                    right->printInfix();
                }
            }
        }

        void printPrefix() const {
            if (is_operand) {
                cout << operand << ' ';
            } else {
                cout << optr << ' ';
                if (left != nullptr) {
                    left->printPrefix();
                } 
                if (right != nullptr) {
                    right->printPrefix();
                }
            }
        }
    };

    /* root of the expression tree */
    Node *root;

    Node* parse(vector<string> &expr);

    void printInfix(const Node *n) const;

    void printPrefix(const Node *n) const;

public:

    ExpTree(vector<string> expr);

    // ExpTree(const ExpTree &other);
    // ~ExpTree();
    // ExpTree& operator=(const ExpTree &other);

    /* Print the tree by doing in-order traversal */
    void printInfix() const;

    /* Print the tree by doing pre-order traversal */
    void printPrefix() const;

    /* Evaluate the tree and return the value */
    int32_t eval() const;
};
