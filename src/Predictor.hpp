//
//  Predictor.hpp
//  FinalProject
//
//  Created by Siddhant Rao on 23/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#ifndef Predictor_hpp
#define Predictor_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#include "Training.hpp"
#include <boost/math/distributions/poisson.hpp>


using namespace std;
using namespace boost::math;

// Confusion matrix dimension:
const int kMatrixRow = 10;
const int kMatirxColumn = 10;

// Model Specific Rows:
const int kTeamNameRow = 0;
const int kHomeASRow = 1;
const int kHomeDSRow = 2;
const int kAwayASRow = 3;
const int kAwayDSRow = 4;

// FindTeamGoalExpectancy calculates the HomeTeamGoalExpectancy and AwayTeamGoalExpectancy which are basically
// the probabilities that the home team or away team are going to score.
pair<double, double> FindTeamGoalExpectancy(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team_name, string away_team_name, double league_avg_home_goals_for, double league_avg_away_goals_for);

// ModelPrediction takes the two models built for the home and away team respectively, their team names
// and their respective league averages for goals scored at home or away depending on which are the home and away teams.
// Using this data a prediction matrix is created by this function as a 2d vector of strings
// which contains all the probabilities of each possible scoreline of upto 9 goals.
vector<vector<string>> ModelPrediction(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team, string away_team, double league_avg_home_goals_for, double league_avg_away_goals_for);

// This function takes in the calculated probabilties and the home and away team names and stores the draw, home win, away win probabilties and the expected scoreline in a vector of strings.
vector<string> StatisticsCreator(vector<vector<string>> resultant_matrix, string home_team_name, string away_team_name);

#endif /* Predictor_hpp */
