//
//  Training.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 24/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Training.hpp"

using namespace std;

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

tuple<double,double,double,double> LeagueAverages(vector<string> team_names, vector<vector<string>> data) {
    
    vector<string> team_list = team_names;
    
    while (team_list.size() != 0) {
        
        for (int j = 0; j < data.size(); j++) {
            if (team_list[0] == data[j][2]) {
                home_goals_scored += stoi(data[j][4]);
                home_goals_conceded += stoi(data[j][5]);
            } else if (team_list[0] == data[j][3]) {
                //cout << data[j][3] << endl;
                away_goals_scored += stoi(data[j][5]);
                away_goals_conceded += stoi(data[j][4]);
            }
        }
        
        home_avg_goals_for += (double) home_goals_scored / (double) kGamesPlayed;
        home_avg_goals_against += (double) home_goals_conceded / (double) kGamesPlayed;
        away_avg_goals_for += (double) away_goals_scored / (double) kGamesPlayed;
        away_avg_goals_against += (double) away_goals_conceded / (double) kGamesPlayed;
            
        home_goals_scored = 0;
        home_goals_conceded = 0;
        away_goals_scored = 0;
        away_goals_conceded = 0;
            
        team_list.erase(team_list.begin());
    }
    
    double league_avg_home_goals_for = home_avg_goals_for / (double) kNumberOfTeams;
    home_avg_goals_for = 0;
    
    double league_avg_home_goals_against = home_avg_goals_against / (double) kNumberOfTeams;
    home_avg_goals_against = 0;
    
    double league_avg_away_goals_for = away_avg_goals_for / (double) kNumberOfTeams;
    away_avg_goals_for = 0;
    
    double league_avg_away_goals_against = away_avg_goals_against / (double) kNumberOfTeams;
    away_avg_goals_against = 0;
    
    return make_tuple(league_avg_home_goals_for, league_avg_home_goals_against, league_avg_away_goals_for, league_avg_away_goals_against);
}


vector<vector<string>> ModelCreator(vector<string> team_names, vector<vector<string>> data) {
    
    vector<string> team_list_one = team_names;
    //vector<string> team_list_two = team_names;
    
    
    vector<vector<string>> result;
    
    vector<string> tmp;
    
    double league_avg_home_goals_for = get<0>(LeagueAverages(team_names, data));
    double league_avg_home_goals_against = get<1>(LeagueAverages(team_names, data));
    double league_avg_away_goals_for = get<2>(LeagueAverages(team_names, data));
    double league_avg_away_goals_against = get<3>(LeagueAverages(team_names, data));
    
    while (team_list_one.size() != 0) {
        
        for (int j = 0; j < data.size(); j++) {
            //cout << j;
            //cout << team_names[0] << endl;
            if (team_list_one[0] == data[j][2]) {
                home_goals_scored += stoi(data[j][4]);
                home_goals_conceded += stoi(data[j][5]);
            } else if (team_list_one[0] == data[j][3]) {
                //cout << data[j][3] << endl;
                away_goals_scored += stoi(data[j][5]);
                away_goals_conceded += stoi(data[j][4]);
            }
        }
        
        home_avg_goals_for = (double) home_goals_scored / (double) kGamesPlayed;
        home_goals_scored = 0;
        
        home_avg_goals_against = (double) home_goals_conceded / (double) kGamesPlayed;
        home_goals_conceded = 0;
        
        away_avg_goals_for = (double) away_goals_scored / (double) kGamesPlayed;
        away_goals_scored = 0;
        
        away_avg_goals_against = (double) away_goals_conceded / (double) kGamesPlayed;
        away_goals_conceded = 0;
        
        
        double home_AS = home_avg_goals_for/league_avg_home_goals_for;
        home_avg_goals_for = 0.0;
        
        double home_DS = home_avg_goals_against/league_avg_home_goals_against;
        home_avg_goals_against = 0.0;
        
        double away_AS = away_avg_goals_for/league_avg_away_goals_for;
        away_avg_goals_for = 0.0;
        
        double away_DS = away_avg_goals_against/league_avg_away_goals_against;
        away_avg_goals_against = 0.0;
    
        
        tmp.push_back(team_list_one[0]);
        tmp.push_back(to_string(home_AS));
        tmp.push_back(to_string(home_DS));
        tmp.push_back(to_string(away_AS));
        tmp.push_back(to_string(away_DS));
        
        result.push_back(tmp);
        
        tmp.clear();
        
        team_list_one.erase(team_list_one.begin());
        
    }
    
    return result;
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
    
    for (int i = 1; i < data.size(); i++) {
        
        if (!(ContainsIn1D(to_return, data[i][2]))) {
            
            to_return.push_back(data[i][2]);
        }
    }
    
    sort(to_return.begin(), to_return.end());
    
    return to_return;
}
