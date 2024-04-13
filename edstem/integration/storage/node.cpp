#include "node.h"

// O(1) - Default Constructor 
EATNode::EATNode(int key, std::vector<std::string> contents) {
    data = std::make_pair(key, contents);
    left = nullptr;
    right = nullptr;
}

// O(1) - Destructor
EATNode::~EATNode() {
    // Nothing to do here
}

