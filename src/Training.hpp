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

// ModelCreator as the name suggests creates the trained model as a 2d vector of strings.
// It contains all the teams calculated attacking and defensive strengths at home and away from the chosen league.
vector<vector<string>> ModelCreator(vector<string> team_names, vector<vector<string>> data);

// TeamList reads the data from the file of all matches played in the specific league and
// returns a list of all the teams present in that league as a vector of strings.
// The vector returned contains the team list in alphabetical order.
vector<string> TeamList(vector<vector<string>> data);

// ContainsIn1D is a helper function used to check if a specific string is contained in a given vector of strings.
// Function returns true if the vector contains the given string.
bool ContainsIn1D(vector<string> input, string to_search);

// This tuple function returns the league average home goals scored, league average home goals conceded,
// league average away goals scored and league average away goals conceded.
// It takes in the CSV read data and the list of teams in that particular league as arguments.
tuple<double,double,double,double> LeagueAverages(vector<string> team_names, vector<vector<string>> data);

// Constant - number of teams in a league
const int kNumberOfTeams = 20;

// Constant - number of matches played at home or away in a league
const int kGamesPlayed = 19;

#endif /* Training_hpp */
