#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bh.h"
#include "bh.cpp"
#include "node.cpp"
#include "st.cpp"

int main(int argc, char* argv[]) {

    std::ifstream file("edstem/integration/edstem-data/data.txt");

    // Later we will implement the rest of the code hre

    std::string line;

    // stores the data for the current course
    std::vector<std::string> st_course_data;
    std::vector<std::string> bhavl_lesson_data;
    std::vector<int>course_ids;

    // create course key for splay tree
    int st_course_key;
    int bhavl_lesson_key;

    int test_count;

    // Declare a splay tree
    SplayTree* st = new SplayTree();
    BinaryHeap* bh = new BinaryHeap();

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
                course_ids.push_back(0); // Add a dummy value to the course_ids vector
            }

            
            // check if the line starts with bhavl_course_id
            if (line.substr(0, 15) == "bhavl_course_id") {
                // Extract the course id from the line
                size_t idStartIndex = line.find(":") + 3; // Find the position of ':' and add 2 to skip it and the space after it
                size_t idEndIndex = line.find('\n') - 2; // Find the position of newline character
                std::string courseIdStr = line.substr(idStartIndex, idEndIndex - idStartIndex); // Extract the substring containing the course id
                int courseId = std::stoi(courseIdStr); // Convert the substring to an integer


                // Check if the course id is not already in the vector
                if (std::find(course_ids.begin(), course_ids.end(), courseId) == course_ids.end()) {
                    // Add the new course id to the vector
                    course_ids.push_back(courseId);
                    // Create a new BinaryHeap for this course id
                    bh = new BinaryHeap();
                }
            }


            if (line.substr(0, 15) == "bhavl_lesson_id") {

                int idStartIndex = 18;
                int idLength = line.length() - idStartIndex - 1; // Adjusting to remove the trailing quote
                /* 
                    if vector is empty
                    create a new node
                    insert the data into the splay tree
                */
                if (!bhavl_lesson_data.empty()) {
                    EATNode* node = new EATNode(bhavl_lesson_key, bhavl_lesson_data);
                    bh->insert(node);
                    bhavl_lesson_data.clear();
                }

                // creates the new lesson key
                bhavl_lesson_key = std::stoi(line.substr(idStartIndex, idLength));
                
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
                            
                            bhavl_lesson_data.push_back(phrase);

                            phrase.clear();
                        }
                    } 
                    // if we are not in quotes we add the character to the phrase
                    else if (in_quotes) {
                        phrase += c;
                    }
                }

            // implement code to sort the data for bhavl
            // std::cout << "Binary Heap / AVL tree" << std::endl;
        }
        
    }
    // clear the vectors
    course_ids.clear();


    // print the splay tree
    st->printSplayTree();

    std::cout << "====================" << std::endl;

    // print the binary heap
    bh->printBinaryHeap();

  
  // FOR TESTING - delete later
    SplayTree* test = new SplayTree();

    st->add_bh_pointer(53506, test);

    
    
    //search function test
    // st->add_bh_pointer(53506);

    // We will ask the user to decide if they want to get the data for a specific course
    
    

    return 0;
}

