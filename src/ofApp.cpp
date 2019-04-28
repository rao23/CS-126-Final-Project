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
    
    // create a vector of colors to populate our dropdown //
    
    // convert the hex values of those colors to strings for the menu labels //
    vector<string> options = {"ONE", "TWO", "THREE", "FOUR"};
    vector<string> options_TWO = {"FOUR", "FIVE", "SIX", "SEVEN"};
    
    // instantiate the dropdown //
    menu = new ofxDatGuiDropdown("SELECT HOME TEAM", options);
    second = new ofxDatGuiDropdown("SELECT AWAY TEAM", options_TWO);
    
    // and position it in the middle of the screen //
    menu->setPosition(1,0);
    second->setPosition(ofGetWidth()/3, 0);
    myMatrix->setPosition(ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    
    // let's set the stripe of each option to its respective color //
    //for (int i=0; i<menu->size(); i++) menu->getChildAt(i)->setStripeColor(colors[i]);
    
    // register to listen for change events //
    menu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    second->onDropdownEvent(this, &ofApp::onDropdownEvent);
    
    // finally let's have it open by default //
    //menu->expand();
    

}

//--------------------------------------------------------------
void ofApp::update(){

    menu->update();
    second->update();
    myMatrix->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    menu->draw();
    second->draw();
    myMatrix->draw();
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
}



