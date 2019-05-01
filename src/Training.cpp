//
//  Training.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 24/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Training.hpp"

using namespace std;

// variables used to keep track of goals data.
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


// Function calculates the league average goals scored and conceded at home and away.
tuple<double,double,double,double> LeagueAverages(vector<string> team_names, vector<vector<string>> data) {
    
    // copies the input list of all the team names into a new string vector.
    vector<string> team_list = team_names;
    
    // loop continues till the team list is not emptied.
    while (team_list.size() != 0) {
        
        // If the specific team we are looking for in the data is found in the third column of the data,
        // add that teams data on that line to the home goal stats,
        // else add it to the away goal stats if team we are looking for is found in the fourth column.
        for (int j = 0; j < data.size(); j++) {
            if (team_list[kFirstElementIndex] == data[j][kHomeTeamNameRow]) {
                home_goals_scored += stoi(data[j][kHomeGSRow]);
                home_goals_conceded += stoi(data[j][kHomeGCRow]);
            } else if (team_list[kFirstElementIndex] == data[j][kAwayTeamNameRow]) {
                away_goals_scored += stoi(data[j][kAwayGSRow]);
                away_goals_conceded += stoi(data[j][kAwayGSRow]);
            }
        }
        
        // Adds the avg goals scored and conceded at home and away of all teams to these variables.
        home_avg_goals_for += (double) home_goals_scored / (double) kGamesPlayed;
        home_avg_goals_against += (double) home_goals_conceded / (double) kGamesPlayed;
        away_avg_goals_for += (double) away_goals_scored / (double) kGamesPlayed;
        away_avg_goals_against += (double) away_goals_conceded / (double) kGamesPlayed;
            
        home_goals_scored = 0;
        home_goals_conceded = 0;
        away_goals_scored = 0;
        away_goals_conceded = 0;
        
        // Once added erase the teams name from the copy list we created.
        team_list.erase(team_list.begin());
    }
    
    // Calculate the averages by dividing the data we found from above by the total number of teams.
    
    double league_avg_home_goals_for = home_avg_goals_for / (double) kNumberOfTeams;
    home_avg_goals_for = 0;
    
    double league_avg_home_goals_against = home_avg_goals_against / (double) kNumberOfTeams;
    home_avg_goals_against = 0;
    
    double league_avg_away_goals_for = away_avg_goals_for / (double) kNumberOfTeams;
    away_avg_goals_for = 0;
    
    double league_avg_away_goals_against = away_avg_goals_against / (double) kNumberOfTeams;
    away_avg_goals_against = 0;
    
    // Return the calculated averages as a tuple.
    return make_tuple(league_avg_home_goals_for, league_avg_home_goals_against, league_avg_away_goals_for, league_avg_away_goals_against);
}


vector<vector<string>> ModelCreator(vector<string> team_names, vector<vector<string>> data) {
    
    // copies the input list of all the team names into a new string vector.
    vector<string> team_list_one = team_names;
    
    // empty 2d vector in which the data will be added and then this vector will be returned.
    vector<vector<string>> result;
    
    // a temp 1d vector used to input the data into the 2d vector to be returned.
    vector<string> tmp;
    
    // Calculated league averages -
    double league_avg_home_goals_for = get<0>(LeagueAverages(team_names, data));
    double league_avg_home_goals_against = get<1>(LeagueAverages(team_names, data));
    double league_avg_away_goals_for = get<2>(LeagueAverages(team_names, data));
    double league_avg_away_goals_against = get<3>(LeagueAverages(team_names, data));
    
    // loop continues till the team list is not emptied.
    while (team_list_one.size() != 0) {
        
        // If the specific team we are looking for in the data is found in the third column of the data,
        // add that teams data on that line to the home goal stats,
        // else add it to the away goal stats if team we are looking for is found in the fourth column.
        
        for (int j = 0; j < data.size(); j++) {
            if (team_list_one[kFirstElementIndex] == data[j][kHomeTeamNameRow]) {
                home_goals_scored += stoi(data[j][kHomeGSRow]);
                home_goals_conceded += stoi(data[j][kHomeGCRow]);
            } else if (team_list_one[kFirstElementIndex] == data[j][kAwayTeamNameRow]) {
                away_goals_scored += stoi(data[j][kAwayGSRow]);
                away_goals_conceded += stoi(data[j][kAwayGCRow]);
            }
        }
        
        // Avg goals scored and conceded at home and away the team.
        home_avg_goals_for = (double) home_goals_scored / (double) kGamesPlayed;
        home_goals_scored = 0;
        
        home_avg_goals_against = (double) home_goals_conceded / (double) kGamesPlayed;
        home_goals_conceded = 0;
        
        away_avg_goals_for = (double) away_goals_scored / (double) kGamesPlayed;
        away_goals_scored = 0;
        
        away_avg_goals_against = (double) away_goals_conceded / (double) kGamesPlayed;
        away_goals_conceded = 0;
        
        // Using the above data the attacking and defensive strength at home and away is calculated for the team.
        double home_AS = home_avg_goals_for/league_avg_home_goals_for;
        home_avg_goals_for = 0.0;
        
        double home_DS = home_avg_goals_against/league_avg_home_goals_against;
        home_avg_goals_against = 0.0;
        
        double away_AS = away_avg_goals_for/league_avg_away_goals_for;
        away_avg_goals_for = 0.0;
        
        double away_DS = away_avg_goals_against/league_avg_away_goals_against;
        away_avg_goals_against = 0.0;
    
        // The team name and attacking and defensive strength at home and away is added to the temporary vector.
        tmp.push_back(team_list_one[kFirstElementIndex]);
        tmp.push_back(to_string(home_AS));
        tmp.push_back(to_string(home_DS));
        tmp.push_back(to_string(away_AS));
        tmp.push_back(to_string(away_DS));
        
        // The temporary vector is then added to the 2d vector to be returned and is then cleared.
        result.push_back(tmp);
        tmp.clear();
        
        // Once added erase the teams name from the copy list we created.
        team_list_one.erase(team_list_one.begin());
        
    }
    
    return result;
}

// Helper function returns true if the string to be searched is found in the vector otherwise false is returned.
bool ContainsIn1D(vector<string> input, string to_search) {

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == to_search) {
            return true;
        }
    }

    return false;
}

// Function to create the team list from the leagues data
vector<string> TeamList(vector<vector<string>> data) {
    
    // The string which is to be returned.
    vector<string> to_return;
    
    for (int i = 1; i < data.size(); i++) {
        
        // if the team is not already added to the vector to return add it else skip it.
        if (!(ContainsIn1D(to_return, data[i][kHomeTeamNameRow]))) {
            
            to_return.push_back(data[i][kHomeTeamNameRow]);
        }
    }
    
    // sort the list in alphabetical order for convenience.
    sort(to_return.begin(), to_return.end());
    
    return to_return;
}
