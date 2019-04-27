//
//  Training.cpp
//  FinalProject
//
//  Created by Siddhant Rao on 24/04/19.
//  Copyright © 2019 Sid Rao. All rights reserved.
//

#include "Training.hpp"

const int number_of_teams = 20;
const int games_played = 19;

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

using namespace std;

tuple<double,double,double,double> LeagueAverages(vector<string> team_names, vector<vector<string>> data) {
    
    vector<string> team_list = team_names;
    
    while (team_list.size() != 0) {
        
        for (int j = 0; j < data.size(); j++) {
            //cout << j;
            //cout << team_names[0] << endl;
            if (team_list[0] == data[j][2]) {
                home_goals_scored += stoi(data[j][4]);
                home_goals_conceded += stoi(data[j][5]);
            } else if (team_list[0] == data[j][3]) {
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
        
        cout << team_list[0] <<endl;
        cout << "HGS: ";
        cout << (float)home_goals_scored/19 << endl;
        cout << "HGC: ";
        cout << (float)home_goals_conceded/19 << endl;
        cout << "AGS: ";
        cout << (float)away_goals_scored/19 << endl;
        cout << "AGC: ";
        cout << (float)away_goals_conceded/19 << endl;
        cout << endl;
        
        home_avg_goals_for += (double) home_goals_scored / (double) games_played;
        home_avg_goals_against += (double) home_goals_conceded / (double) games_played;
        away_avg_goals_for += (double) away_goals_scored / (double) games_played;
        away_avg_goals_against += (double) away_goals_conceded / (double) games_played;
            
        home_goals_scored = 0;
        home_goals_conceded = 0;
        away_goals_scored = 0;
        away_goals_conceded = 0;
            
        team_list.erase(team_list.begin());
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
    
    double league_avg_home_goals_for = home_avg_goals_for / (double) number_of_teams;
    home_avg_goals_for = 0;
    
    double league_avg_home_goals_against = home_avg_goals_against / (double) number_of_teams;
    home_avg_goals_against = 0;
    
    double league_avg_away_goals_for = away_avg_goals_for / (double) number_of_teams;
    away_avg_goals_for = 0;
    
    double league_avg_away_goals_against = away_avg_goals_against / (double) number_of_teams;
    away_avg_goals_against = 0;
    
    return make_tuple(league_avg_home_goals_for, league_avg_home_goals_against, league_avg_away_goals_for, league_avg_away_goals_against);
}


vector<vector<string>> ModelCreator(vector<string> team_names, vector<vector<string>> data) {
    
    vector<string> team_list_one = team_names;
    //vector<string> team_list_two = team_names;
    
    
    vector<vector<string>> result;
    
    vector<string> tmp;
    
    double avg_one = get<0>(LeagueAverages(team_names, data));
    double avg_two = get<1>(LeagueAverages(team_names, data));
    double avg_three = get<2>(LeagueAverages(team_names, data));
    double avg_four = get<3>(LeagueAverages(team_names, data));
    
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
        
        home_avg_goals_for = (double) home_goals_scored / (double) games_played;
        home_goals_scored = 0;
        
        home_avg_goals_against = (double) home_goals_conceded / (double) games_played;
        home_goals_conceded = 0;
        
        away_avg_goals_for = (double) away_goals_scored / (double) games_played;
        away_goals_scored = 0;
        
        away_avg_goals_against = (double) away_goals_conceded / (double) games_played;
        away_goals_conceded = 0;
        
//        cout << team_names[0] <<endl;
//        cout << "HAGS: ";
//        cout << home_avg_goals_for << endl;
//        cout << "HAGC: ";
//        cout << home_avg_goals_against << endl;
//        cout << "AAGS: ";
//        cout << away_avg_goals_for << endl;
//        cout << "AAGC: ";
//        cout << away_avg_goals_against << endl;
//        cout << endl;


        //cout << get<0>(LeagueAverages(team_list_two, data)) <<endl;
        //cout << team_list_two.size() << endl;
        double home_AS = home_avg_goals_for/avg_one;
        home_avg_goals_for = 0.0;
        
        //cout << get<1>(LeagueAverages(team_list_two, data)) <<endl;
        //cout << team_list_two.size() << endl;
        double home_DS = home_avg_goals_against/avg_two;
        home_avg_goals_against = 0.0;
        
        //cout << get<2>(LeagueAverages(team_list_two, data)) <<endl;
        //cout << team_list_two.size() << endl;
        double away_AS = away_avg_goals_for/avg_three;
        away_avg_goals_for = 0.0;
        
        //cout << get<3>(LeagueAverages(team_list_two, data)) <<endl;
        //cout << team_list_two.size() << endl;
        double away_DS = away_avg_goals_against/avg_four;
        away_avg_goals_against = 0.0;
        
        //cout << endl;
        
//        cout << team_names[0] <<endl;
//        cout << "HAS: ";
//        cout << home_AS << endl;
//        cout << "HDS: ";
//        cout << home_DS << endl;
//        cout << "AAS: ";
//        cout << away_AS << endl;
//        cout << "ADS: ";
//        cout << away_DS << endl;
//        cout << endl;
        
        
        tmp.push_back(team_list_one[0]);
        tmp.push_back(to_string(home_AS));
        tmp.push_back(to_string(home_DS));
        tmp.push_back(to_string(away_AS));
        tmp.push_back(to_string(away_DS));
        
        cout << endl;
        
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i];
            cout << " ";
        }

        cout << endl;
        
        result.push_back(tmp);
        
        tmp.clear();
        
        team_list_one.erase(team_list_one.begin());
        
    }
    
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
