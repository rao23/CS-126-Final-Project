#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_LEFT );
//    gui->addLabel("SOURCE IMAGE SELECTION");
//    gui->addTextInput("NEW IMAGE(S)", "ENTER FULL DIRECTORY PATH");
//    gui->addButton("IMPORT IMAGE(S)");
//    gui->addBreak()->setHeight(10.0f);
//    
//    vector<string> options = {"ONE", "TWO", "THREE", "FOUR"};
//    gui->addDropdown("SELECT AN EXISTING SOURCE IMAGE", options);
//    gui->getDropdown("SELECT AN EXISTING SOURCE IMAGE")->onDropdownEvent(this, &ofApp::onDropdownEvent);
//    ofxDatGuiDropdown* myDropdown = new ofxDatGuiDropdown("League", options);
//     gui->getDropdown("SELECT AN EXISTING SOURCE IMAGE")->onDropdownEvent(this, &ofApp::onDropdownEvent);gui->onDropdownEvent(this, &ofApp::onDropdownEvent);
    
    ofSetWindowPosition(0, 0);
    
    ofBackground(0,0,128);
    //0,0,128
    // 25,25,112
    
    // instantiate the dropdown //
    menu = gui->addDropdown("SELECT HOME TEAM LEAGUE", options);
    gui->addBreak()->setHeight(10.0f);
    
    third = gui_two->addDropdown("SELECT AWAY TEAM LEAGUE", options);
    gui_two->addBreak()->setHeight(10.0f);
    
    button = gui_three->addButton("CALCULATE");
    
    // and position it in the middle of the screen //
//    menu->setPosition(1,0);
//    second->setPosition(ofGetWidth()/3, 0);
//    myMatrix->setPosition(ofGetWidth()/2 - myMatrix->getWidth()/2, ofGetHeight()/2 - myMatrix->getHeight()/2);
    
    // let's set the stripe of each option to its respective color //
    //for (int i=0; i<menu->size(); i++) menu->getChildAt(i)->setStripeColor(colors[i]);
    
    // register to listen for change events //
    menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    third->onDropdownEvent(this, &ofApp::onDropdownEvent);
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    
    // finally let's have it open by default //
    //menu->expand();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    menu->update();
    button->update();
    //second->update();
    //myMatrix->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    menu->draw();
    button->draw();
//    second->draw();
    //myMatrix->draw();
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
//    ofSetBackgroundColor(colors[e.child]);
//    menu->setStripeColor(ofColor::white);
    
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
        //  button 2 was clicked, do something else //
        
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
        
    } else if (e.target->is("SELECT AWAY TEAM")){
        //  button 2 was clicked, do something else //
        
        for (int i = 0; i < away_team_list.size(); i++) {
            if (e.child == i) {
                
                away_team_name = away_team_list[i];
            }
        }
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    
    double win;
    double loss;
    double draw;
    
    if (e.target->is("CALCULATE")) {
        
        home_model = ModelCreator(home_team_list, dataListhome);
        away_model = ModelCreator(away_team_list, dataListaway);
        
        resultant_matrix = ModelPrediction(home_model, away_model, home_team_name, away_team_name, get<0>(LeagueAverages(home_team_list, dataListhome)), get<2>(LeagueAverages(away_team_list, dataListaway)));
        
        double max = 0.0;
        int home = 0;
        int away = 0;
        
        for (int i = 0; i < resultant_matrix.size(); i++) {
            for (int j = 0; j < resultant_matrix[i].size(); j++) {
                cout << resultant_matrix[i][j] << " ";
                if (max < stod(resultant_matrix[i][j])) {
                    max = stod(resultant_matrix[i][j]);
                    home = j;
                    away = i;
                }
                if (i > j) {
                    win += stod(resultant_matrix[i][j]);
                } else if (i < j) {
                    loss += stod(resultant_matrix[i][j]);
                } else {
                    draw += stod(resultant_matrix[i][j]);
                }
            }
            
            cout << endl;
        }
        
        cout << endl;
        
        cout << home_team_name <<" Win Probability = " << loss << " %" << endl;
        cout << away_team_name << " Win Probability = " << win << " %" << endl;
        cout << "Draw Probability = " << draw << " %" << endl;
        cout << "Expected Score: " << home_team_name << " " << home << " - " << away << " " << away_team_name << endl;
        
    }
}


