//
//  Predictor.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 23/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Predictor.hpp"
#include <stdio.h>

// Function to calculate the probability of each scoreline and returns it as a 2d vector of strings.
vector<vector<string>> ModelPrediction(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team, string away_team, double league_avg_home_goals_for, double league_avg_away_goals_for) {
    
    vector<vector<string>> distribution;
    
    // Home Goal Expectancy and Away Goal Expectancy calculated with the help of the FindTeamGoalExpectancy helper method.
    double home_goal_expectancy = get<0>(FindTeamGoalExpectancy(model_home, model_away, home_team, away_team, league_avg_home_goals_for, league_avg_away_goals_for));
    double away_goal_expectancy = get<1>(FindTeamGoalExpectancy(model_home, model_away, home_team, away_team, league_avg_home_goals_for, league_avg_away_goals_for));;
    
    // declaration of two poisson variables - one for the home team and for the away team goal probabilities
    poisson_distribution<> p_home(home_goal_expectancy);
    poisson_distribution<> p_away(away_goal_expectancy);
    
    // temporary string vector
    vector<string> tmp;
    
    for (int i = 0; i < kMatrixRow; i++) {
        for (int j = 0; j < kMatirxColumn; j++) {
            
            // probability of the home team scoring j goals x probability of the away team scoring i goals x 100
            // this data is added to the tmp string
            tmp.push_back(to_string(pdf(p_home, j) * pdf(p_away, i) * 100));
            
        }
        
        // this temp string is then added to the 2d vector to be returned and is then cleared.
        distribution.push_back(tmp);
        tmp.clear();
        
    }
    
    return distribution;
}

// Helper function to calculate both teams' goal expectancies.
pair<double, double> FindTeamGoalExpectancy(vector<vector<string>> model_home, vector<vector<string>> model_away, string home_team_name, string away_team_name, double league_avg_home_goals_for, double league_avg_away_goals_for) {
    
    double home_goal_expectancy;
    double away_goal_expectancy;
    
    double home_attacking_strength = 0.0;
    double away_defensive_strength = 0.0;
    double home_defensive_strength = 0.0;
    double away_attacking_strength = 0.0;
    
    // loop through the model created for the home team - which is basically the attacking and defensive strengths
    // of all teams in the home team's league.
    for (int i = 0; i < model_home.size(); i++) {
        
        // if the home team is found add the data from the model to the home team's stats
        if (home_team_name == model_home[i][kTeamNameRow]) {
            home_attacking_strength = stod(model_home[i][kHomeASRow]);
            home_defensive_strength = stod(model_home[i][kHomeDSRow]);
        }
    }
    
    // loop through the model created for the away team - which is basically the attacking and defensive strengths
    // of all teams in the away team's league.
    for (int i = 0; i < model_away.size(); i++) {
        
        // if the away team is found add the data from the model to the away team's stats
        if (away_team_name == model_away[i][kTeamNameRow]) {
            away_attacking_strength = stod(model_away[i][kAwayASRow]);
            away_defensive_strength = stod(model_away[i][kAwayDSRow]);
        }
    }
    
    // Home Goal Expectancy = home attacking strength x away defensive strength x average goals for at home
    home_goal_expectancy = home_attacking_strength * away_defensive_strength * league_avg_home_goals_for;
    
    // Away Goal Expectancy = away attacking strength x home defensive strength x average goals for at away
    away_goal_expectancy = away_attacking_strength * home_defensive_strength * league_avg_away_goals_for;
    
    return make_pair(home_goal_expectancy, away_goal_expectancy);
}


// Helper function to print the overall win probability for both teams,
// the draw probability and the most expected scoreline.
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
    
    // In this loop whenever i > j means away team won the game,
    // if i < j home team wins the game, else when i = j then its a draw.
    // These stats are stored in the variables above.
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
    
    // using stringstream these print lines are stored as strings which are then printed on the display window.
    home_win << home_team_name <<" Win Probability = " << loss << " %" << endl;
    away_win << away_team_name << " Win Probability = " << win << " %" << endl;
    even << "Draw Probability = " << 100.0 - (loss + win) << " %" << endl;
    score << "Expected Score: " << home_team_name << " " << home << " - " << away << " " << away_team_name << endl;
    
    // the print lines are stored in a vector as strings.
    stats.push_back(home_win.str());
    stats.push_back(away_win.str());
    stats.push_back(even.str());
    stats.push_back(score.str());
    
    return stats;
}
