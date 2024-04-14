#include "st.h"

// Constructor
SplayTree::SplayTree() {
    this->root = nullptr;
}

// Destructor
SplayTree::~SplayTree() {
    // Recursively delete all nodes in the splay tree
    deleteSplayTree(this->root);
}

// Splay function
void SplayTree::splay(EATNode* node) {
    
    while (node != root) {
        if (node->parent == root) {
            // Zig case
            if (node == node->parent->left) {
                rotateRight(node->parent);
            } else {
                rotateLeft(node->parent);
            }
        } else {
            // Either Zig-Zig or Zig-Zag case
            EATNode* parent = node->parent;
            EATNode* grandparent = parent->parent;

            if (node == parent->left && parent == grandparent->left) {
                // Zig-Zig case (left child of left child)
                rotateRight(grandparent);
                rotateRight(parent);
            } else if (node == parent->right && parent == grandparent->right) {
                // Zig-Zig case (right child of right child)
                rotateLeft(grandparent);
                rotateLeft(parent);
            } else {
                // Zig-Zag case
                if (node == parent->left) {
                    rotateRight(parent);
                    rotateLeft(grandparent);
                } else {
                    rotateLeft(parent);
                    rotateRight(grandparent);
                }
            }
        }
    }
    // After splay, the given node becomes the root
    root = node;
}


// Find node function
EATNode* SplayTree::findNode(int key) {
    // Implement findNode function
    return nullptr;
}

// Rotate right function
void SplayTree::rotateRight(EATNode* node) {
    // Make sure node and its left child are not nullptr
    if (node == nullptr || node->left == nullptr) {
        return;
    }

    EATNode* pivot = node->left;
    node->left = pivot->right;
    if (pivot->right != nullptr) {
        pivot->right->parent = node;
    }

    pivot->parent = node->parent;
    if (node->parent == nullptr) {
        root = pivot;
    } else if (node == node->parent->right) {
        node->parent->right = pivot;
    } else {
        node->parent->left = pivot;
    }

    pivot->right = node;
    node->parent = pivot;
}

// Rotate left function
void SplayTree::rotateLeft(EATNode* node) {
    // Make sure node and its right child are not nullptr
    if (node == nullptr || node->right == nullptr) {
        return;
    }

    EATNode* pivot = node->right;
    node->right = pivot->left;
    if (pivot->left != nullptr) {
        pivot->left->parent = node;
    }

    pivot->parent = node->parent;
    if (node->parent == nullptr) {
        root = pivot;
    } else if (node == node->parent->left) {
        node->parent->left = pivot;
    } else {
        node->parent->right = pivot;
    }

    pivot->left = node;
    node->parent = pivot;
}

// Insert function
void SplayTree::insert(EATNode* node) {
    /*
    We will create a node with the given key and contents an insert it into the splay tree.
    */

    // we need to check if the root is null - if it is we will set the root to the node
    if (root == nullptr) {
        root = node;
        return;
    }
    
    // Otherwise, find the appropriate position to insert the node
    EATNode* current = root; // Start from the root
    EATNode* parent = nullptr; // Parent of the current node
    while (current != nullptr) { // Traverse the tree to find the appropriate position
        parent = current;
        if (node->data.first < current->data.first) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Insert the node as a child of the appropriate parent
    if (node->data.first < parent->data.first) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->parent = parent;
    // After insertion, splay the newly inserted node to the root
    splay(node);
}

// Remove function
void SplayTree::remove(int key) {
    // Implement remove function
}

// Search function
EATNode* SplayTree::search(int key) {
    // Implement search function
    return nullptr;
}

// Helper function for inorder traversal
void SplayTree::inorderTraversal(EATNode* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    std::cout << "Key: " << node->data.first << ", Contents: ";
    for (size_t i = 0; i < node->data.second.size(); ++i) {
        std::cout << node->data.second[i];
        if (i != node->data.second.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    inorderTraversal(node->right);
}

// Print splay tree function
void SplayTree::printSplayTree() {
    // Perform an inorder traversal starting from the root
    inorderTraversal(root);
}

// Implement the deleteSplayTree function
void SplayTree::deleteSplayTree(EATNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteSplayTree(node->left);
    deleteSplayTree(node->right);
    delete node;
}

