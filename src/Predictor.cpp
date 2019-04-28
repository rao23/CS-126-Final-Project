//
//  Predictor.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 23/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Predictor.hpp"
#include <stdio.h>


vector<vector<string>> ModelPrediction(vector<vector<string>> model, string home_team, string away_team, double league_avg_home_goals_for, double league_avg_away_goals_for) {
    
    vector<vector<string>> distribution;
    
    double home_goal_expectancy = get<0>(FindTeamGoalExpectancy(model, home_team, away_team, league_avg_home_goals_for, league_avg_away_goals_for));
    double away_goal_expectancy = get<1>(FindTeamGoalExpectancy(model, home_team, away_team, league_avg_home_goals_for, league_avg_away_goals_for));;
    
    poisson_distribution<> p_home(home_goal_expectancy);
    poisson_distribution<> p_away(away_goal_expectancy);
    
    vector<string> tmp;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            
            tmp.push_back(to_string(pdf(p_home, j) * pdf(p_away, i) * 100));
            
        }
        
        distribution.push_back(tmp);
        tmp.clear();
        
    }
    
    //poisson_distribution<> p();
    
    //math::poisson_distribution::pdf(1,2);
    
    //boost::poisson_distribution(RealType mean = 1);
    
    return distribution;
}

pair<double, double> FindTeamGoalExpectancy(vector<vector<string>> model, string home_team_name, string away_team_name, double league_avg_home_goals_for, double league_avg_away_goals_for) {
    
    double home_goal_expectancy;
    double away_goal_expectancy;
    
    double home_attacking_strength = 0.0;
    double away_defensive_strength = 0.0;
    double home_defensive_strength = 0.0;
    double away_attacking_strength = 0.0;
    
    for (int i = 0; i < model.size(); i++) {
        
        if (home_team_name == model[i][0]) {
            home_attacking_strength = stod(model[i][1]);
            home_defensive_strength = stod(model[i][2]);
        }
        
        if (away_team_name == model[i][0]) {
            away_attacking_strength = stod(model[i][3]);
            away_defensive_strength = stod(model[i][4]);
        }
    }
    
    home_goal_expectancy = home_attacking_strength * away_defensive_strength * league_avg_home_goals_for;
    away_goal_expectancy = away_attacking_strength * home_defensive_strength * league_avg_away_goals_for;
    
    return make_pair(home_goal_expectancy, away_goal_expectancy);
}
