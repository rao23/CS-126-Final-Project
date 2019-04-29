//
//  Training.hpp
//  FinalProject
//
//  Created by Siddhant Rao on 24/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#ifndef Training_hpp
#define Training_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

#include "CSVReader.hpp"

using namespace std;

vector<vector<string>> ModelCreator(vector<string> team_names, vector<vector<string>> data);
vector<string> TeamList(vector<vector<string>> data);
bool ContainsIn1D(vector<string> input, string to_search);
tuple<double,double,double,double> LeagueAverages(vector<string> team_names, vector<vector<string>> data);

const int kNumberOfTeams = 20;
const int kGamesPlayed = 19;

#endif /* Training_hpp */
