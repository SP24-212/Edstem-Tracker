#include "avl.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>


// Constructor
AVLTree::AVLTree() {
    root = nullptr;
}

// Destructor
AVLTree::~AVLTree() {
    // Call a helper function to delete all nodes in the AVL tree
    deleteAllNodes(root);
}


/// Helper function to insert a node into the AVL tree
EATNode* AVLTree::insert(EATNode* root, EATNode* node) {
    // perform a normal BST insertion
    if (root == nullptr) {
        return node;
    }
    
    if (node->data.first < root->data.first) {
        root->left = insert(root->left, node);
    } else if (node->data.first > root->data.first) {
        root->right = insert(root->right, node);
    } else {
        // Duplicate keys are not allowed in AVL tree
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

    // return the (unchanged) root pointer
    return root;
}

// Public function to insert a node into the AVL tree
void AVLTree::insert(EATNode* node) {
    root = insert(root, node);
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

    // update
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
// Helper function to perform an inorder traversal of the AVL tree
void AVLTree::inorderTraversal(EATNode* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    // Skip printing nodes with a key of 0
    if (node->data.first != 0) {
        std::cout << "Key: " << GREEN << node->data.first << RESET << " [";
        for (int i = 0; i < node->data.second.first.size(); i++) {
            // if i is 0 print Course ID in red and the data in white
            if (i == 0) {
            std::cout << RED << "Course ID: " << RESET << node->data.second.first[i] << " ";
            }
            // If i is 1: print Due Date: in RED
            else if (i == 1) {
            std::cout << RED << "Due Date: " << RESET << node->data.second.first[i] << " ";
            }
            // If i is 2: print Lesson Type: in RED
            else if (i == 2) {
            std::cout << RED << "Lesson Type: " << RESET << node->data.second.first[i] << " ";
            }
            // If i is 3: print Openable: in RED
            else if (i == 3) {
            std::cout << RED << "Openable: " << RESET << node->data.second.first[i] << " ";
            }
            // If i is 4: print Title: in RED
            else if (i == 4) {
            std::cout << RED << "Title: " << RESET << node->data.second.first[i] << " ";
            }
            // If i is 5: print Status: in RED
            else if (i == 5) {
            std::cout << RED << "Status: " << RESET << node->data.second.first[i] << " ";
            } 
            // If i is 6: print User Score: in RED
            else if (i == 6) {
            std::cout << RED << "User Score: " << RESET << node->data.second.first[i] << " ";
            }
            // If i is 7: print Potential Score: in RED
            else if (i == 7) {
            std::cout << RED << "Potential Score: " << RESET << node->data.second.first[i] << " ";
            }
        }
        std::cout << "]" << std::endl << std::endl;
    }
    inorderTraversal(node->right);
}

// Public function to insert a node into the AVL tree
// void AVLTree::insert(int key, std::vector<std::string> contents) {
//     EATNode* node = new EATNode(key, contents);
//     root = insert(node);
// }

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


// Balance check function
bool AVLTree::isBalanced(EATNode* node) {
    if (node == nullptr) {
        return true;
    }
    int balance = getBalance(node);
    if (balance > 1 || balance < -1) {
        return false;
    }
    return isBalanced(node->left) && isBalanced(node->right);
}

// Public function to check if the AVL tree is balanced
bool AVLTree::isBalanced() {
    return isBalanced(root);
}

// Visualize the AVL tree
void AVLTree::visualize() {
    std::string folderPath = "edstem/integration/edstem-data/";

    std::ofstream file;
    file.open(folderPath + "avl.dot");
    file << "digraph AVL {" << std::endl;
    visualizeHelper(root, file);
    file << "}" << std::endl;
    file.close();
    system(("dot -Tpng " + folderPath + "avl.dot -o " + folderPath + "avl.png").c_str());
    system(("open " + folderPath + "avl.png").c_str());
}

// Helper function to visualize the AVL tree
void AVLTree::visualizeHelper(EATNode* node, std::ofstream& file) {
    if (node == nullptr || node->data.first == 0) {
        return;
    }
    if (node->left != nullptr && node->left->data.first != 0) {
        file << node->data.first << " -> " << node->left->data.first << ";" << std::endl;
    }
    if (node->right != nullptr && node->right->data.first != 0) {
        file << node->data.first << " -> " << node->right->data.first << ";" << std::endl;
    }
    visualizeHelper(node->left, file);
    visualizeHelper(node->right, file);
}