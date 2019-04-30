#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowPosition(0, 0);
    
    ofBackground(0,0,128);
    
    font.load("bpg_glaho_arial_v5_big.ttf", 10);
    
    // instantiate the dropdown //
    menu = gui->addDropdown("SELECT HOME TEAM LEAGUE", options);
    gui->addBreak()->setHeight(10.0f);
    
    third = gui_two->addDropdown("SELECT AWAY TEAM LEAGUE", options);
    gui_two->addBreak()->setHeight(10.0f);
    
    button = gui_three->addButton("CALCULATE");
    
    
    // register to listen for change events //
    menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    third->onDropdownEvent(this, &ofApp::onDropdownEvent);
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    menu->update();
    button->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int height;
    int mid_height;
    menu->draw();
    button->draw();
    if (button_pressed) {
        
        for (int i = 0; i < resultant_matrix.size(); i++) {
            font.drawString(to_string(i), 120, ofGetHeight()/4 + 30 * i);
            if (i == 4) {
                mid_height = ofGetHeight()/4 + 30 * i;
            }
            for (int j = 0; j < resultant_matrix[i].size(); j++) {
                if (j == 0 && i == 0) {
                    for (int k = 0; k < 10; k++) {
                        font.drawString(to_string(k), 165 + 80 * k, ofGetHeight()/4 - 30);
                    }
                }
                font.drawString(resultant_matrix[i][j], 150 + 80 * j, ofGetHeight()/4 + 30 * i);
                height = ofGetHeight()/4 + 30 * i;
            }
        }
        
        for (int i = 0; i < stats.size(); i++) {
            font.drawString(stats[i], 150, height + 50 + 30*i);
        }
        
        font.drawString(away_team_name, 10, mid_height + 10);
        font.drawString("Goal Probability", 10, mid_height + 30);
        
        font.drawString(home_team_name, 442.5, ofGetHeight()/4 - 60);
        font.drawString(" Goal Probability", 442.5 + font.stringWidth(home_team_name), ofGetHeight()/4 - 60);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e) {
    
    bool first = false;
    bool next = false;
    
    CSVReader england("/Users/sid/Downloads/E0.csv");
    CSVReader spain("/Users/sid/Downloads/LaLiga.csv");
    CSVReader netherlands("/Users/sid/Downloads/Eredivisie.csv");
    CSVReader germany("/Users/sid/Downloads/Bundesliga.csv");
    CSVReader france("/Users/sid/Downloads/Ligue1.csv");
    CSVReader italy("/Users/sid/Downloads/SeriaA.csv");
    CSVReader portugal("/Users/sid/Downloads/Portugal.csv");
    
    if (e.target->is("SELECT HOME TEAM LEAGUE")){
        if (e.child == 0) {
            first = true;
            dataListhome = england.getData();
        } else if (e.child == 1) {
            first = true;
            dataListhome = spain.getData();
        } else if (e.child == 2) {
            first = true;
            dataListhome = germany.getData();
        } else if (e.child == 3) {
            first = true;
            dataListhome = italy.getData();
        } else if (e.child == 4) {
            first = true;
            dataListhome = france.getData();
        } else if (e.child == 5) {
            first = true;
            dataListhome = netherlands.getData();
        } else if (e.child == 6) {
            first = true;
            dataListhome = portugal.getData();
        }
        
    } else if (e.target->is("SELECT AWAY TEAM LEAGUE")){
        
        if (e.child == 0) {
            next = true;
            dataListaway = england.getData();
        } else if (e.child == 1) {
            next = true;
            dataListaway = spain.getData();
        } else if (e.child == 2) {
            next = true;
            dataListaway = germany.getData();
        } else if (e.child == 3) {
            next = true;
            dataListaway = italy.getData();
        } else if (e.child == 4) {
            next = true;
            dataListaway = france.getData();
        } else if (e.child == 5) {
            next = true;
            dataListaway = netherlands.getData();
        } else if (e.child == 6) {
            next = true;
            dataListaway = portugal.getData();
        }
    }
    
    home_team_list = TeamList(dataListhome);
    away_team_list = TeamList(dataListaway);
    
    if (first) {
        second = gui->addDropdown("SELECT HOME TEAM", home_team_list);
        second->onDropdownEvent(this, &ofApp::onDropdownEvent2);
        first = false;
    } else if (next) {
        fourth = gui_two->addDropdown("SELECT AWAY TEAM", away_team_list);
        fourth->onDropdownEvent(this, &ofApp::onDropdownEvent2);
        next = false;
    }
    
}

void ofApp::onDropdownEvent2(ofxDatGuiDropdownEvent e) {
    
    if (e.target->is("SELECT HOME TEAM")){
        
        for (int i = 0; i < home_team_list.size(); i++) {
            if (e.child == i) {
                
                home_team_name = home_team_list[i];
            }
        }
        
    } else if (e.target->is("SELECT AWAY TEAM")) {
        
        for (int i = 0; i < away_team_list.size(); i++) {
            if (e.child == i) {
                
                away_team_name = away_team_list[i];
            }
        }
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    
    button_pressed = true;
    
    if (e.target->is("CALCULATE")) {
        
        home_model = ModelCreator(home_team_list, dataListhome);
        away_model = ModelCreator(away_team_list, dataListaway);
        
        resultant_matrix = ModelPrediction(home_model, away_model, home_team_name, away_team_name, get<0>(LeagueAverages(home_team_list, dataListhome)), get<2>(LeagueAverages(away_team_list, dataListaway)));
        
        stats = StatisticsCreator(resultant_matrix, home_team_name, away_team_name);
        
    }
}


