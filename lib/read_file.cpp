//
// Created by Alexander Allis on 1/24/23.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "read_file.h"


/*
 * Converts a string alphabetical message as a String to a numeric message as a vector.
 * Args:
 *  message: the alphabetical message passed by reference
 * Returns:
 *  A pointer to a vector of type <int>, which is the converted numeric message
 */

std::vector<char> * convert_message_to_vector_char(std::string * message) {
    // Initialize vector
    auto * numericMessage = new std::vector<char>();
    std::string:: iterator it;

    for (it = message->begin(); it != message->end(); it++) {
        // Add character to vector of character integers
        numericMessage->emplace_back(*it);
    }
    numericMessage->pop_back();  // remove last character because it's a return character in this use case.
    return numericMessage;
}

/*
 * Reads a file and returns the contents as a String.
 * Args:
 *  filePath(string): The filepath
 * Returns:
 *  String: the contents of the file.
 */

std::string * fileToString(std::string& fileName) {

//    auto returnString = std::string();
    auto * returnString = new std::string();
    // Check if file exists
    std::ifstream inFile(fileName.c_str());  // Check to make sure file exists
    if (!inFile) {
        std::cout << "File not found." << std::endl;
        return returnString;
    }

    // Open file
    std::ifstream fileStream(fileName);
    if (!fileStream.is_open()) {
        std::cout << "Can't read file." << std::endl;
        return returnString;
    }

    std::stringstream sStream;  // stream to parse each line
    std::string line;  // each line (string)
//    std::string returnLine;
    auto * returnLine = new std::string();

    while(!fileStream.eof()) {  // Loop through lines
        getline(fileStream, line);  // Consume first line
        returnLine->append(line);
        line.clear();
    }

    fileStream.close();
    return returnLine;
};
