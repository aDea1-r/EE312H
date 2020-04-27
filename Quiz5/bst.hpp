using namespace std;

class BST {

    class Node {
    public:
        int val;
        Node *left;
        Node *right;
        Node *parent;

        Node(int el) {
            this->val = el;
            this->left = nullptr; // NULL
            this->right = nullptr;
            this->parent = nullptr;
        }

        Node(const Node &other);

        ~Node() {
            delete left;
            delete right;
        }
    };

    Node *root;

    void copy(const BST &other);

    void destroy() {
        delete root;
    }

 public:

    Node* findMin(void);

    Node* successor(Node *n);

    void print(void);

    BST(void);
    // BST(BST &other)
    // BST& operator=(BST &other)

    ~BST() {
        destroy();
    }

    void insert(int el);
    bool find(int el);
    // void remove(int el);
};
