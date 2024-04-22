#include "st.h"
#include <fstream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"


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
    if (root == nullptr) {
        root = node;
        return;
    }
    
    EATNode* current = root;
    EATNode* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (node->data.first < current->data.first) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (node->data.first < parent->data.first) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->parent = parent;
    splay(node);
}

// Search function
EATNode* SplayTree::search(int key) { 
    return searchRecursive(root, key);
}

//Recursive private method search function
EATNode* SplayTree::searchRecursive(EATNode* node, int key){
    if (node == nullptr || node->data.first == key) {
        return node; // Return the node if found
    }

    if (key < node->data.first) {  
        return searchRecursive(node->left, key);
    } else {
        return searchRecursive(node->right, key);
    }
}

void SplayTree::add_bh_pointer(int key, void* ptr) {
    EATNode* node = search(key); // Assuming `search` function is correctly implemented

    if (node != nullptr) {
        node->data.second.second = ptr; // Assign the pointer to the second part of the data pair
    }
}

// Helper function for inorder traversal
void SplayTree::inorderTraversal(EATNode* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
    std::cout << "Key: " << node->data.first << ", Contents: ";
    for (size_t i = 0; i < node->data.second.first.size(); ++i) {
        std::cout << node->data.second.first[i];
        if (i != node->data.second.first.size() - 1) {
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

// Function to get the pointer of the binary heap
void* SplayTree::get_bh_pointer(int key) {
    EATNode* node = search(key); // Assuming `search` function is correctly implemented

    if (node != nullptr) {
        return node->data.second.second; // Return the pointer
    }
    return nullptr;
}

// This function is for conceptual understanding only and not used for actual balancing
bool SplayTree::isBalanced(EATNode* node) {
  // In a splay tree, balance is not explicitly maintained like in AVL trees.
  // However, for understanding, we can define a height difference check here.
  // This is not a strict requirement, and splaying ensures amortized efficiency.
  if (node == nullptr) {
    return true;
  }

  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);

  // Here, we define a threshold for the maximum allowed height difference.
  // You can adjust this value based on your specific needs.
  int threshold = 1;

  return abs(leftHeight - rightHeight) <= threshold;
}

// Helper function to get the height of a subtree (can be modified for other definitions)
int SplayTree::getHeight(EATNode* node) {
  if (node == nullptr) {
    return 0;
  }

  int leftHeight = getHeight(node->left);
  int rightHeight = getHeight(node->right);

  return 1 + std::max(leftHeight, rightHeight);
}

bool SplayTree::isBalanced(){
    return isBalanced(root);
}

void SplayTree::visualize() {
  std::string folderPath = "edstem/integration/edstem-data/";

  std::ofstream file;
  file.open(folderPath + "splay.dot");
  file << "digraph SplayTree {" << std::endl;
  visualizeHelper(root, file);
  file << "}" << std::endl;
  file.close();
  system(("dot -Tpng " + folderPath + "splay.dot -o " + folderPath + "splay.png").c_str());
  system(("open " + folderPath + "splay.png").c_str());
}

void SplayTree::visualizeHelper(EATNode* node, std::ofstream& file) {
  if (node == nullptr) {
    return;
  }
  // Create an edge for the left child (even if null)
  file << node->data.first << " -> ";
  if (node->left != nullptr) {
    file << node->left->data.first;
  } else {
    file << "null";  // Indicate null child
  }
  file << ";" << std::endl;

  // Create an edge for the right child (even if null)
  file << node->data.first << " -> ";
  if (node->right != nullptr) {
    file << node->right->data.first;
  } else {
    file << "null";  // Indicate null child
  }
  file << ";" << std::endl;

  visualizeHelper(node->left, file);
  visualizeHelper(node->right, file);
}