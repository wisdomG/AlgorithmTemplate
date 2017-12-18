#include <iostream>
#include <queue>
using namespace std;

template<typename Key, typename Value>
class BinarySearchTree {

private :
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    int count; // #Nodes

    Node* __insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count ++;
            return new Node(key, value);
        }
        if (key == node->key) node->value = value;
        else if (key > node->key)
            node->right = __insert(node->right, key, value);
        else
            node->left = __insert(node->left, key, value);
        return node;
    }
    //.non recurrence
    Node* __insert2(Node *node, Key key, Value value) {

    }

    bool __contain(Node *node, Key key) {
        if (node == NULL) return false;
        if (key == node->key) return true;
        else if (key > node->key)
            return __contain(node->right, key);
        else
            return __contain(node->left, key);
    }

    Value* __search(Node *node, Key key) {
        if (node == NULL) return NULL;
        if (key == node->key) return &(node->value);
        else if (key > node->key)
            return __search(node->right, key);
        else
            return __search(node->left, key);
    }

    void __preOrder(Node *node) {
        cout << node->key << endl;
        __preOrder(node->left);
        __preOrder(node->right);
    }

    void __inOrder(Node *node) {
        __inOrder(node->left);
        cout << node->key << endl;
        __inOrder(node->right);
    }

    void __postOrder(Node *node) {
        __postOrder(node->left);
        __postOrder(node->right);
        cout << node->key << endl;
    }

    void __destroy(Node *node) {
        if (node != NULL) {
            __destroy(node->left);
            __destroy(node->right);
            delete node;
            count--;
        }
    }

    void __levelOrder() {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            cout << node->key << endl;
            if (node->left) q.push(node->left);
            if (node->rigth) q.push(node->right);
        }
    }

public:
    BinarySearchTree() {
        root = NULL;
        count = 0;
    }
    ~BinarySearchTree() {
        __destroy(root);
    }
    int size() { return count; }
    bool empty() { return count == 0; } // return root == NULL}

    void insert(Key key, Value value) {
        root = __insert(root, key, value);
    }

    bool contain(Key key) {
        return __contain(root, key);
    }

    Value* search(Key key) {
        return __search(root, key);
    }

    void preOrder() {
        __preOrder(root);
    }

    void inOrder() {
        __inOrder(root);
    }

    void postOrder() {
        __postOrder(root);
    }

    void levelOrder() {
        __levelOrder();
    }

};
