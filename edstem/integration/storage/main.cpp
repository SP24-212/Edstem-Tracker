#include <iostream>
#include <fstream>
#include <sstream>

#include "node.cpp"
#include "st.cpp"

int main(int argc, char* argv[]) {

    std::ifstream file("edstem/integration/edstem-data/data.txt");

    // Later we will implement the rest of the code hre

    std::string line;

    // stores the data for the current course
    std::vector<std::string> st_course_data;

    // create course key for splay tree
    int st_course_key;

    int test_count;

    // Declare a splay tree
    SplayTree* st = new SplayTree();

    while (std::getline(file, line)) {

        std::istringstream iss(line);

        std::string word;

        // check line to see if the first characters are st or bhavl
        if (line.substr(0, 2) == "st") {

            
            // check if there is new course id
            if (line.substr(0, 12) == "st_course_id") {

                // if vector is empty
                if (!st_course_data.empty()) {
                    // create a new node
                    EATNode* node = new EATNode(st_course_key, st_course_data);
                    // insert the data into the splay tree
                    st->insert(node);
                    st_course_data.clear();
                }

                // create the new course key
                st_course_key = std::stoi(line.substr(15, line.length() - 2));

                
            }
        
            std::stringstream streamline(line);
            std::string word;
            std::string phrase;
            bool in_quotes = false;

            // iterate through the line - we iterate through the line to get the data in the quotes
            for (char c : line) {
                if (c == '\'') {
                    in_quotes = !in_quotes;
                    if (!in_quotes && !phrase.empty()) {
                        
                        st_course_data.push_back(phrase);

                        phrase.clear();
                    }
                } 
                // if we are not in quotes we add the character to the phrase
                else if (in_quotes) {
                    phrase += c;
                }
            }
            
        
        } 
        
        else if (line.substr(0, 5) == "bhavl") {
            // Since we can't technically determine the next line we create the remaining splay tree node here
                if (!st_course_data.empty()) {
                    // create a new node
                    EATNode* node = new EATNode(st_course_key, st_course_data);
                    // insert the data into the splay tree
                    st->insert(node);
                    st_course_data.clear();
                }


            // implement code to sort the data for bhavl
            // std::cout << "Binary Heap / AVL tree" << std::endl;
        }
        
    }
    
    // print the splay tree
    st->printSplayTree();

    // FOR TESTING - delete later
    SplayTree* test = new SplayTree();

    st->add_bh_pointer(53506, test);

    
    
    //search function test
    // st->add_bh_pointer(53506);

    // We will ask the user to decide if they want to get the data for a specific course
    

    return 0;
}

