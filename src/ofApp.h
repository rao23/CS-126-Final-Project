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
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
    void onDropdownEvent2(ofxDatGuiDropdownEvent e);
    void onButtonEvent(ofxDatGuiButtonEvent e);
    
    ofxDatGui* gui = new ofxDatGui(ofxDatGuiAnchor::TOP_LEFT);
    ofxDatGui* gui_two = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
    ofxDatGui* gui_three = new ofxDatGui(ofxDatGuiAnchor::BOTTOM_RIGHT);
    
    ofxDatGuiDropdown* second;
    ofxDatGuiDropdown* menu;
    
    ofxDatGuiButton* button;
    
    ofxDatGuiDropdown* third;
    ofxDatGuiDropdown* fourth;
    
    vector<string> home_team_list;
    vector<string> away_team_list;
    
    string home_team_name;
    string away_team_name;
    
    ofxDatGuiMatrix* myMatrix =  new ofxDatGuiMatrix("MATRIX", 100, false);
    
    vector<string> options = {"PREMIER LEAGUE", "LA LIGA", "BUNDESLIGA", "SERIE A", "LIGUE 1", "EREDIVISIE", "PRIMEIRA LIGA"};
    
    std::vector<std::vector<std::string>> dataListhome;
    std::vector<std::vector<std::string>> dataListaway;
    
    vector<vector<string>> home_model;
    vector<vector<string>> away_model;
    
    vector<vector<string>> resultant_matrix;
//    std::vector<std::vector<std::string>> dataList = england.getData();
		
};
