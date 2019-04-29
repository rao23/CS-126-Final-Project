//
//  Predictor.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 23/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Predictor.hpp"
#include <stdio.h>


vector<vector<string>> ModelPrediction(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team, string away_team, double league_avg_home_goals_for, double league_avg_away_goals_for) {
    
    vector<vector<string>> distribution;
    
    double home_goal_expectancy = get<0>(FindTeamGoalExpectancy(model_home, model_away, home_team, away_team, league_avg_home_goals_for, league_avg_away_goals_for));
    double away_goal_expectancy = get<1>(FindTeamGoalExpectancy(model_home, model_away, home_team, away_team, league_avg_home_goals_for, league_avg_away_goals_for));;
    
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
    
    return distribution;
}

pair<double, double> FindTeamGoalExpectancy(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team_name, string away_team_name, double league_avg_home_goals_for, double league_avg_away_goals_for) {
    
    double home_goal_expectancy;
    double away_goal_expectancy;
    
    double home_attacking_strength = 0.0;
    double away_defensive_strength = 0.0;
    double home_defensive_strength = 0.0;
    double away_attacking_strength = 0.0;
    
    for (int i = 0; i < model_home.size(); i++) {
        
        if (home_team_name == model_home[i][0]) {
            home_attacking_strength = stod(model_home[i][1]);
            home_defensive_strength = stod(model_home[i][2]);
        }
    }
    
    for (int i = 0; i < model_away.size(); i++) {
        
        if (away_team_name == model_away[i][0]) {
            away_attacking_strength = stod(model_away[i][3]);
            away_defensive_strength = stod(model_away[i][4]);
        }
    }
    
    home_goal_expectancy = home_attacking_strength * away_defensive_strength * league_avg_home_goals_for;
    away_goal_expectancy = away_attacking_strength * home_defensive_strength * league_avg_away_goals_for;
    
    return make_pair(home_goal_expectancy, away_goal_expectancy);
}

vector<string> StatisticsCreator(vector<vector<string>> resultant_matrix, string home_team_name, string away_team_name) {
    
    double win;
    double loss;
    double draw;
    
    stringstream home_win;
    stringstream away_win;
    stringstream even;
    stringstream score;
    vector<string> stats;
    
    double max = 0.0;
    int home = 0;
    int away = 0;
    
    for (int i = 0; i < resultant_matrix.size(); i++) {
        for (int j = 0; j < resultant_matrix[i].size(); j++) {
            if (max < stod(resultant_matrix[i][j])) {
                max = stod(resultant_matrix[i][j]);
                home = j;
                away = i;
            }
            if (i > j) {
                win += stod(resultant_matrix[i][j]);
            } else if (i < j) {
                loss += stod(resultant_matrix[i][j]);
            } else if (i == j) {
                draw += stod(resultant_matrix[i][j]);
            }
        }
    }
    
    home_win << home_team_name <<" Win Probability = " << loss << " %" << endl;
    away_win << away_team_name << " Win Probability = " << win << " %" << endl;
    even << "Draw Probability = " << 100.0 - (loss + win) << " %" << endl;
    score << "Expected Score: " << home_team_name << " " << home << " - " << away << " " << away_team_name << endl;
    
    stats.push_back(home_win.str());
    stats.push_back(away_win.str());
    stats.push_back(even.str());
    stats.push_back(score.str());
    
    return stats;
}
