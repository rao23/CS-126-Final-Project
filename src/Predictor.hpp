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


pair<double, double> FindTeamGoalExpectancy(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team_name, string away_team_name, double league_avg_home_goals_for, double league_avg_away_goals_for);

vector<vector<string>> ModelPrediction(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team, string away_team, double league_avg_home_goals_for, double league_avg_away_goals_for);

vector<string> StatisticsCreator(vector<vector<string>> resultant_matrix, string home_team_name, string away_team_name);

#endif /* Predictor_hpp */
