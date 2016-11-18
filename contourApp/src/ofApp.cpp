#include "ofApp.h"
#include "trailsScene.h"
#include "emptyScene.h"
#include "geometryScene.h"
#include "offsetScene.h"
#include "velocityScene.h"
#include "medhirScene.h"
#include "katrinaScene.h"
#include "bodybitsScene.h"
#include "molmolScene.h"
#include "retrocolorScene.h"
#include "adnanScene.h"
#include "bakuScene.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    IM.setup();
    
    SM.scenes.push_back(new bakuScene());

    SM.scenes.push_back(new adnanScene());
   SM.scenes.push_back(new retrocolorScene());
    SM.scenes.push_back(new molmolScene());
    SM.scenes.push_back(new katrinaScene());
    SM.scenes.push_back(new bodybitsScene());
    SM.scenes.push_back(new medhirScene());
    SM.scenes.push_back(new offsetScene());
    SM.scenes.push_back(new velocityScene());
    
    SM.scenes.push_back(new geometryScene());
    SM.scenes.push_back(new trailsScene());
    SM.scenes.push_back(new emptyScene());
    
    // share a pointer to the CT object 
    for (int i = 0; i < SM.scenes.size(); i++){
        SM.scenes[i]->CT = &CT;
    }
    
    SM.setup();
    
    
    bDrawDebug = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    IM.update();
    
    
    ofRectangle input(0,0,IM.medianFilteredResult.getWidth(), IM.medianFilteredResult.getHeight());
    ofRectangle output(0,0, ofGetWidth(), ofGetHeight());
    
    ofRectangle inputScaled = input;
    inputScaled.scaleTo(output);
    
    
    
    if (IM.finder.size() > 0){
     
        ofPolyline tempLine = IM.finder.getPolyline(0);
        for (int i = 0; i < tempLine.size(); i++){ 
            float x = tempLine[i].x;
            float y = tempLine[i].y;
            float newX = ofMap(x, input.x, input.x + input.width,
                               inputScaled.x + inputScaled.width, inputScaled.x);
            float newY = ofMap(y, input.y, input.y + input.height,
                               inputScaled.y, inputScaled.y + inputScaled.height);
            tempLine[i].set(newX, newY);
            
        }
        CT.analyze(tempLine);
    }
    
    SM.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0,0,0);
    
    
    if (bDrawDebug){
        IM.draw();
    }else {
        SM.draw();
        
    }

    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_RIGHT){
        SM.nextScene();
    }
    
    if (key == ' '){
        bDrawDebug = !bDrawDebug;
    }
    
    if (key == 'f'){
        ofToggleFullscreen();
    }
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
