#pragma once

#include "ofxDatGui.h"
#include "ofTrueTypeFont.h"
#include "ofMain.h"
#include "CSVReader.hpp"
#include "Training.hpp"
#include "Predictor.hpp"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    // I create 2 dropdown events, one for the team league selection dropdown
    // and one for the team name selection dropdown.
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
    void onDropdownEvent2(ofxDatGuiDropdownEvent e);
    
    // The button event which when the button is pressed is called.
    void onButtonEvent(ofxDatGuiButtonEvent e);
    
    // I create three ofxDatGui pointers for each corner button/dropdown menu set.
    ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
    ofxDatGui* gui_two = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
    ofxDatGui* gui_three = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
    
    // Home team selection dropdowns
    ofxDatGuiDropdown* home_team_league_names_dropdown;
    ofxDatGuiDropdown* home_team_names_dropdown;
    
    // The calculate button
    ofxDatGuiButton* button;
    
    // Away team selection dropdowns
    ofxDatGuiDropdown* away_team_league_names_dropdown;
    ofxDatGuiDropdown* away_team_names_dropdown;
    
    // ofTrueTypeFont object which helps print out the stats on the display console.
    ofTrueTypeFont font;
    
    // Vector of strings with each league name to choose from in the league dropdowns.
    vector<string> league_options = {"PREMIER LEAGUE", "LA LIGA", "BUNDESLIGA", "SERIE A", "LIGUE 1", "EREDIVISIE", "PRIMEIRA LIGA"};
    
    // Home team league - team choices
    vector<string> home_team_list;
    
    // Away team league - team choices
    vector<string> away_team_list;
    
    // The respective team names
    string home_team_name;
    string away_team_name;
    
    // Home and away team data
    std::vector<std::vector<std::string>> dataListhome;
    std::vector<std::vector<std::string>> dataListaway;
    
    // Home and away team trained models
    vector<vector<string>> home_model;
    vector<vector<string>> away_model;
    
    // The confusion matrix with all scoreline probabilities
    vector<vector<string>> resultant_matrix;
    
    // The vector of strings with the home_win probability, away_win probability, draw probability and expected scoreline.
    vector<string> stats;
    
    // boolean to check if the button is pressed
    bool button_pressed = false;
};
