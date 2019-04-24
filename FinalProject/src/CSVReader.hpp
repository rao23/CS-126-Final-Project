//
//  CSVReader.hpp
//  FinalProject
//
//  Created by Siddhant Rao on 21/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#ifndef CSVReader_hpp
#define CSVReader_hpp

#include <stdio.h>
#include <iostream>

/*
 * A class to read data from a csv file.
 */
class CSVReader
{
    std::string fileName;
    std::string delimeter;
    
public:
    CSVReader(std::string filename, std::string delm = ",") :
    fileName(filename), delimeter(delm)
    { }
    
    // Function to fetch data from a CSV File
    std::vector<std::vector<std::string>> getData();
};

#endif /* CSVReader_hpp */

