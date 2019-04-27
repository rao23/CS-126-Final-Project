//
//  Training.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 24/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Training.hpp"

int number_of_teams = 20;
int games_played = 19;
int goals_scored = 0;
int goals_conceded = 0;
int home_goals_scored = 0;
int home_goals_conceded = 0;
int away_goals_scored = 0;
int away_goals_conceded = 0;
int total_goals_scored = 0;
int total_goals_conceded = 0;
float home_avg_goals_for = 0.0;
float home_avg_goals_against = 0.0;
float away_avg_goals_for = 0.0;
float away_avg_goals_against = 0.0;

using namespace std;

tuple<float,float,float,float> LeagueAverages(vector<string> team_names, vector<vector<string>> data) {
    
    int count = 0;
    
    while (team_names.size() != 0) {
        count++;
        for (int j = 0; j < data.size(); j++) {
            //cout << j;
            //cout << team_names[0] << endl;
            if (team_names[0] == data[j][2]) {
                home_goals_scored += stoi(data[j][4]);
                home_goals_conceded += stoi(data[j][5]);
            } else if (team_names[0] == data[j][3]) {
                //cout << data[j][3] << endl;
                away_goals_scored += stoi(data[j][5]);
                away_goals_conceded += stoi(data[j][4]);
            }
        }
        
//        cout << home_goals_scored << endl;
//        cout << home_goals_conceded << endl;
            
            //            cout << home_goals_scored << endl;
            //            cout << games_played << endl;
            //            cout << home_avg_goals_for << endl;
            //            cout << count << endl;
            //            cout << endl;
        
//        cout << team_names[0] <<endl;
//        cout << "HGS: ";
//        cout << (float)home_goals_scored/19 << endl;
//        cout << "HGC: ";
//        cout << (float)home_goals_conceded/19 << endl;
//        cout << "AGS: ";
//        cout << (float)away_goals_scored/19 << endl;
//        cout << "AGC: ";
//        cout << (float)away_goals_conceded/19 << endl;
//        cout << endl;
        
        home_avg_goals_for += (float) home_goals_scored / (float) games_played;
        home_avg_goals_against += (float) home_goals_conceded / (float) games_played;
        away_avg_goals_for += (float) away_goals_scored / (float) games_played;
        away_avg_goals_against += (float) away_goals_conceded / (float) games_played;
            
        home_goals_scored = 0;
        home_goals_conceded = 0;
        away_goals_scored = 0;
        away_goals_conceded = 0;
        
        cout << team_names[0] << endl;
            
        team_names.erase(team_names.begin());
    }
//    for (int i = 0; i < team_names.size(); i++) {
//
//        if (get<0>(ContainsIn1D(team_names, data[i][2]))) {
//
//            count++;
//            for (int j = 0; j < data.size(); j++) {
//                //cout << j;
//
//                if (data[i][2] == data[j][2]) {
//                    //cout << data[j][4];
//                    home_goals_scored += stoi(data[j][4]);
//                    home_goals_conceded += stoi(data[j][5]);
//                } else if (data[i][2] == data[j][3]) {
//                    cout << data[j][3] << endl;
//                    away_goals_scored += stoi(data[i][5]);
//                    away_goals_conceded += stoi(data[i][4]);
//                }
//            }
//
////            cout << home_goals_scored << endl;
////            cout << games_played << endl;
////            cout << home_avg_goals_for << endl;
////            cout << count << endl;
////            cout << endl;
//            home_avg_goals_for += (double) home_goals_scored / (double) games_played;
//            home_avg_goals_against += (double) home_goals_conceded / (double) games_played;
//            away_avg_goals_for += (double) away_goals_scored / (double) games_played;
//            away_avg_goals_against += (double) away_goals_conceded / (double) games_played;
//
//            home_goals_scored = 0;
//            home_goals_conceded = 0;
//            away_goals_scored = 0;
//            away_goals_conceded = 0;
//
//            team_names.erase(team_names.begin() + get<1>(ContainsIn1D(team_names, data[i][2])));
//
////            for (int i = 0; i < team_names.size(); i++) {
////                cout << team_names[i] << endl;
////            }
////
//            //cout << endl;
//        }
    
    float league_avg_home_goals_for = home_avg_goals_for / (float) number_of_teams;
    home_avg_goals_for = 0;
    
    float league_avg_home_goals_against = home_avg_goals_against / (float) number_of_teams;
    home_avg_goals_against = 0;
    
    float league_avg_away_goals_for = away_avg_goals_for / (float) number_of_teams;
    away_avg_goals_for = 0;
    
    float league_avg_away_goals_against = away_avg_goals_against / (float) number_of_teams;
    away_avg_goals_against = 0;
    
    return make_tuple(league_avg_home_goals_for, league_avg_home_goals_against, league_avg_away_goals_for, league_avg_away_goals_against);
}


vector<vector<string>> ModelCreator(vector<string> team_names, bool home_team, vector<vector<string>> data) {
    
    vector<vector<string>> result;
    vector<string>::iterator iter;
    
    vector<string> tmp;
    //vector<string> team_names;
    
    
    
    for (int i = 0; i < data.size(); i++) {
        
        if (get<0>(ContainsIn1D(team_names, data[i][2]))) {
            
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

pair<bool, int> ContainsIn1D(vector<string> input, string to_search) {
    
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == to_search) {
            return make_pair(true, i);
        }
    }
    
    return make_pair(false, 0);
}

vector<string> TeamList(vector<vector<string>> data) {
    
    vector<string> to_return;
    
    for (int i = 1; i < data.size(); i++) {
        
        if (!get<0>(ContainsIn1D(to_return, data[i][2]))) {
            
            to_return.push_back(data[i][2]);
        }
    }
    
    sort(to_return.begin(), to_return.end());
    
    return to_return;
}
