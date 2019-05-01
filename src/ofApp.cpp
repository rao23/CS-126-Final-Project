#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowPosition(0, 0);
    
    // set background colour to navy blue.
    ofBackground(0,0,128);
    
    // load font of size 10 and type Arial.
    font.load("bpg_glaho_arial_v5_big.ttf", 10);
    
    // instantiate the dropdowns and add breaks between them //
    home_team_league_names_dropdown = gui->addDropdown("SELECT HOME TEAM LEAGUE", league_options);
    gui->addBreak()->setHeight(10.0f);
    
    away_team_league_names_dropdown = gui_two->addDropdown("SELECT AWAY TEAM LEAGUE", league_options);
    gui_two->addBreak()->setHeight(10.0f);
    
    // instantiate the button //
    button = gui_three->addButton("CALCULATE");
    
    
    // register to listen for change events //
    home_team_league_names_dropdown->onDropdownEvent(this, &ofApp::onDropdownEvent);
    away_team_league_names_dropdown->onDropdownEvent(this, &ofApp::onDropdownEvent);
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    home_team_league_names_dropdown->update();
    button->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int height;
    int mid_height;
    home_team_league_names_dropdown->draw();
    button->draw();
    
    // If the button is pressed, calculate the confusion matrix of scoreline probabilities and the stats,
    // and print it out on the console.
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

// Based on what league is chosen, a dropdown is added with the all the team names from that league.
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
        home_team_names_dropdown = gui->addDropdown("SELECT HOME TEAM", home_team_list);
        home_team_names_dropdown->onDropdownEvent(this, &ofApp::onDropdownEvent2);
        first = false;
    } else if (next) {
        away_team_names_dropdown = gui_two->addDropdown("SELECT AWAY TEAM", away_team_list);
        away_team_names_dropdown->onDropdownEvent(this, &ofApp::onDropdownEvent2);
        next = false;
    }
    
}

// When the team name is selected from the second dropdown, register the chosen names to call into the functions.
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


// When the button is pressed, call all the functions with the selected data.
// Basically, on the press of the button, the code is compiled.
void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    
    button_pressed = true;
    
    if (e.target->is("CALCULATE")) {
        
        home_model = ModelCreator(home_team_list, dataListhome);
        away_model = ModelCreator(away_team_list, dataListaway);
        
        resultant_matrix = ModelPrediction(home_model, away_model, home_team_name, away_team_name, get<0>(LeagueAverages(home_team_list, dataListhome)), get<2>(LeagueAverages(away_team_list, dataListaway)));
        
        stats = StatisticsCreator(resultant_matrix, home_team_name, away_team_name);
        
    }
}


