//
//  main.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 24/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

#include "CSVReader.hpp"
#include "Training.hpp"

using namespace std;


int main()
{
    // Creating an object of CSVWriter
    //CSVReader team_reader("/Users/sid/Downloads/Team.csv");
    CSVReader player_reader("/Users/sid/Downloads/E0.csv");
    
    // Get the data from CSV File
    std::vector<std::vector<std::string>> dataList = player_reader.getData();
    //std::vector<std::vector<std::string>> dataList = team_reader.getData();
    
    //cout << dataList.size() << endl;
    
    //cout << dataList[1][2] << endl;
    
    
//    std::vector<std::vector<std::string>> season_data;
//
//    season_data.push_back(dataList[0]);
//
//    for (int i = 1; i < dataList.size(); i++) {
//        for (int j = 0; j < dataList[i].size(); j++) {
//            if (j == 3) {
//                if (dataList[i][j] == "2015/2016") {
//                    season_data.push_back(dataList[i]);
//                }
//            }
//        }
//    }
    
    //cout << season_data.size() << endl;
    
//    for (int i = 0; i < season_data.size(); i++) {
//        cout << season_data[i][3] << endl;
//    }
    
    //    for (int i = 0; i < season_data.size(); i++) {
    //        for (int j = 0; j < season_data[i].size(); j++) {
    //            cout << season_data[i][j];
    //            cout << "   ";
    //            if (j % 114 == 0) {
    //                cout << endl;
    //            }
    //        }
    //    }
    
    // Print the content of row by row on screen
//        for(std::vector<std::string> vec : dataList)
//        {
//            for(std::string data : vec)
//            {
//                std::cout<<data << " , ";
//            }
//            std::cout<<std::endl;
//        }
    
    vector<string> x = TeamList(dataList);
    //vector<string> rand = {"pan", "bat", "kit", "tim", "fox", "ass"};
    
//    cout << get<0>(LeagueAverages(x, dataList)) << endl;
//    cout << get<1>(LeagueAverages(x, dataList)) << endl;
//    cout << get<2>(LeagueAverages(x, dataList)) << endl;
//    cout << get<3>(LeagueAverages(x, dataList)) << endl;
    
    
//    for (int i = 0; i < x.size(); i++) {
//        cout << x[i] << endl;
//    }
    //cout << x.size();
    
    return 0;
}
