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


pair<double, double> FindTeamGoalExpectancy(vector<vector<string>> model, string home_team_name, string away_team_name, double league_avg_home_goals_for, double league_avg_away_goals_for);

vector<vector<string>> ModelPrediction(vector<vector<string>> model, string home_team, string away_team, double league_avg_home_goals_for, double league_avg_away_goals_for);
//class Predictor {
//    
//public:
//    
//    float AttackingStrength(float goals_scored, float goals_conceded);
//    
//private:
//    float home_team_avg_goals_for;
//    float home_team_avg_goals_against;
//    float away_team_avg_goals_for;
//    float away_team_avg_goals_against;
//    
//};

#endif /* Predictor_hpp */
