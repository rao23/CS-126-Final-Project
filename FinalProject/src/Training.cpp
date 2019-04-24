//
//  Training.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 24/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Training.hpp"


int games_played = 19;
int goals_scored = 0;
int goals_conceded = 0;
int home_goals_scored = 0;
int home_goals_conceded = 0;
int away_goals_scored = 0;
int away_goals_conceded = 0;
int total_goals_scored = 0;
int total_goals_conceded = 0;
double home_avg_goals_for = 0.0;
double home_avg_goals_against = 0.0;
double away_avg_goals_for = 0.0;
double away_avg_goals_against = 0.0;



tuple<int,int,int,int> LeagueAverages(vector<string> team_names, vector<vector<string>> data) {
    
    vector<string>::iterator iter;
    
    for (int i = 1; i < data.size(); i++) {
        
        if (ContainsIn1D(team_names, data[i][2])) {
            
            for (int j = 1; j < data.size(); j++) {
                //cout << j;
                
                if (data[i][2] == data[j][2]) {
                    //cout << data[j][4];
                    home_goals_scored += stoi(data[j][4]);
                    home_goals_conceded += stoi(data[j][5]);
                } else if (data[i][2] == data[j][3]) {
                    away_goals_scored += stoi(data[i][5]);
                    away_goals_conceded += stoi(data[i][4]);
                }
            }
            
            home_avg_goals_for += (double) home_goals_scored / (double) games_played;
            home_avg_goals_against += (double) home_goals_conceded / (double) games_played;
            away_avg_goals_for += (double) away_goals_scored / (double) games_played;
            away_avg_goals_against += (double) away_goals_conceded / (double) games_played;
            
            team_names.erase(remove(team_names.begin(), team_names.end(), data[i][2]), team_names.end());
        }
    }
    
    int league_avg_home_goals_for = home_avg_goals_for / (double) games_played;
    int league_avg_home_goals_against = home_avg_goals_against / (double) games_played;
    int league_avg_away_goals_for = away_avg_goals_for / (double) games_played;
    int league_avg_away_goals_against = away_avg_goals_against / (double) games_played;
    
    return make_tuple(league_avg_home_goals_for, league_avg_home_goals_against, league_avg_away_goals_for, league_avg_away_goals_against);
}

vector<vector<string>> ModelCreator(vector<string> team_names, bool home_team, vector<vector<string>> data) {
    
    vector<vector<string>> result;
    vector<string>::iterator iter;
    
    vector<string> tmp;
    //vector<string> team_names;
    
    
    
    for (int i = 0; i < data.size(); i++) {
        
        if (ContainsIn1D(team_names, data[i][2])) {
            
            for (int j = 0; j < data.size(); j++) {
                
                if (data[i][2] == data[j][2]) {
                    home_goals_scored += stoi(data[j][4]);
                    home_goals_conceded += stoi(data[j][5]);
                } else if (data[i][2] == data[j][3]) {
                    away_goals_scored += stoi(data[i][5]);
                    away_goals_conceded += stoi(data[i][4]);
                }
            }
            
            home_avg_goals_for = (double) home_goals_scored / (double) games_played;
            home_avg_goals_against = (double) home_goals_conceded / (double) games_played;
            away_avg_goals_for = (double) away_goals_scored / (double) games_played;
            away_avg_goals_against = (double) away_goals_conceded / (double) games_played;
            
            
            
        }
        
        away_goals_scored += stoi(data[i][5]);
        away_goals_conceded += stoi(data[i][4]);
        
    }
//    if (home_team) {
//        for (int i = 0; i < data.size(); i++) {
//
//
//
//            if (data[i][2] == team_name) {
//
//                //                cout << stoi(data[i][4]);
//                //                cout << " - ";
//                //                cout << stoi(data[i][5]) << endl;
//                //cout << games_played << endl;
//
//                goals_scored += stoi(data[i][4]);
//                goals_conceded += stoi(data[i][5]);
//                games_played++;
//
//            }
//        }
//    } else if (!home_team) {
//
//        for (int i = 0; i < data.size(); i++) {
//
//            if (data[i][3] == team_name) {
//
//                //                cout << stoi(data[i][4]);
//                //                cout << " - ";
//                //                cout << stoi(data[i][5]) << endl;
//
//                goals_conceded += stoi(data[i][4]);
//                goals_scored += stoi(data[i][5]);
//                games_played++;
//
//            }
//        }
//    }
    
    double avg_goals_for = (double) goals_scored / (double) games_played;
    double avg_goals_against = (double) goals_conceded / (double) games_played;
    
    cout << avg_goals_for << endl;
    cout << avg_goals_against << endl;
    
    return result;
}

bool ContainsIn2D(vector<vector<string>> input, string to_search) {
    
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            
            if (input[i][j] == to_search) {
                return true;
            }
        }
    }
    
    return false;
}

bool ContainsIn1D(vector<string> input, string to_search) {
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == to_search) {
            return true;
        }
    }
    
    return false;
}

vector<string> TeamList(vector<vector<string>> data) {
    
    vector<string> to_return;
    
    for (int i = 0; i < data.size(); i++) {
        
        if (!ContainsIn1D(to_return, data[i][2])) {
            
            to_return.push_back(data[i][2]);
        }
    }
    
    return to_return;
}
