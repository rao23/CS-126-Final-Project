//
//  CSVReader.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 21/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "CSVReader.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

// Took help from here for this class - https://thispointer.com/how-to-read-data-from-a-csv-file-in-c/ 

using namespace std;

/*
 * Parses through csv file line by line and returns the data
 * in vector of vector of strings.
 */
std::vector<std::vector<std::string>> CSVReader::getData()
{
    std::ifstream file(fileName);
    
    std::vector<std::vector<std::string>> dataList;
    
    std::string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
        dataList.push_back(vec);
    }
    // Close the File
    file.close();
    
    return dataList;
}
