#include <iostream>
using namespace std;

template <typename T> class BST {
    private:
        struct BSTNode {
            T value;
            BST right;
            BST left;
            BSTNode(const T&x): value(x) {};
            BSTNode(const BSTNode&) = default;
            ~BSTNode() {};
        };
        BSTNode* root = nullptr;
    public:
        BST() = default;
        ~BST() { delete root;}
        bool is_empty() {return root == nullptr;}
        bool contains(const T& x) const;
        const T& find_min() const;
        const T& find_max() const;   

        void insert(const T& x);     
};

template <typename T>
bool BST<T>::contains(const T& x) const {
    if (is_empty())
        return false;

    if (root->value == x)
        return true;
    else if (x < root->value) 
        return root->left.contains(x);
    else 
        return root->right.contains(x);
}

template <typename T>
const T& BST<T>::find_min() const {
    const BSTNode* node = root;

    while(!node->left.is_empty())
        node = node->left.root;
    return node->value;
}

template <typename T>
const T& BST<T>::find_max() const {
    const BSTNode* node = root;

    while(!node->right.is_empty())
        node = node->right.root;
    return node->value;
}

template <typename T>
void BST<T>::insert(const T& x) {
    if (is_empty())
        root = new BSTNode(x);

    if (x < root->value) 
        root->left.insert(x);
    else 
        root->right.insert(x);    
}


int main() {

};