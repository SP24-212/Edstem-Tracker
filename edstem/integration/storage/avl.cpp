#include "avl.h"

// Constructor
AVLTree::AVLTree() {
    root = nullptr;
}

// Destructor
AVLTree::~AVLTree() {
    // Call a helper function to delete all nodes in the AVL tree
    deleteAllNodes(root);
}


// Helper function to insert a node into the AVL tree
EATNode* AVLTree::insert(EATNode* node) {

    

    // perform a normal BST insertion
    if (node == nullptr) {
        return node;
    } else if (root == nullptr) {
        root = node;
        return root;
    }
    
    if (node->data.first < root->data.first) {
        root->left = insert(root->left);
    }
    
    else if (node->data.first > root->data.first) {
        root->right = insert(root->right);
    } 
    
    else {
        return root;
    }

    
    // update height of this ancestor node
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

    // get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(root);

    // if this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && node->data.first < root->left->data.first) {
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && node->data.first > root->right->data.first) {
        return rotateLeft(root);
    }

    // Left Right Case
    if (balance > 1 && node->data.first > root->left->data.first) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && node->data.first < root->right->data.first) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
    
}

// Helper function to search for a node in the AVL tree
EATNode* AVLTree::search(EATNode* node, int key) {
    // if the root is null or the key is found at the root
    if (node == nullptr || node->data.first == key) {
        return node;
    }

    // if the key is greater than the root's key
    if (node->data.first < key) {
        return search(node->right, key);
    }

    // if the key is less than the root's key
    return search(node->left, key);
}

// Helper function to perform a right rotation on a node
EATNode* AVLTree::rotateRight(EATNode* node) {
    EATNode* leftChild = node->left;
    EATNode* rightChild = leftChild->right;

    // perform rotation
    leftChild->right = node;
    node->left = rightChild;

    // update heights
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    leftChild->height = std::max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    // return new root
    return leftChild;
}

// Helper function to perform a left rotation on a node
EATNode* AVLTree::rotateLeft(EATNode* node) {
    EATNode* rightChild = node->right;
    EATNode* leftChild = rightChild->left;

    // perform rotation
    rightChild->left = node;
    node->right = leftChild;

    // update heights
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    rightChild->height = std::max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    // return new root
    return rightChild;
}

// Helper function to get the height of a node
int AVLTree::getHeight(EATNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Helper function to get the balance factor of a node
int AVLTree::getBalance(EATNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Helper function to perform an inorder traversal of the AVL tree
void AVLTree::inorderTraversal(EATNode* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    std::cout << node->data.first << " ";
    inorderTraversal(node->right);
}

// Public function to insert a node into the AVL tree
void AVLTree::insert(int key, std::vector<std::string> contents) {
    EATNode* node = new EATNode(key, contents);
    root = insert(node);
}

// Public function to search for a node in the AVL tree
EATNode* AVLTree::search(int key) {
    return search(root, key);
}

// Public function to print the contents of the AVL tree in order
void AVLTree::printAVLTree() {
    inorderTraversal(root);
    std::cout << std::endl;
}

// Helper function to delete all nodes in the AVL tree
void AVLTree::deleteAllNodes(EATNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteAllNodes(node->left);
    deleteAllNodes(node->right);
    delete node;
}
