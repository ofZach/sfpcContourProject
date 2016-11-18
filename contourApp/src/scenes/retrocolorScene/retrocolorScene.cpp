#include "retrocolorScene.h"
// by Dan Gorelick

//---------------------------------------------------------------
void retrocolorScene::setup(){
}


//---------------------------------------------------------------
void retrocolorScene::update(){

    if (CT->resampleSmoothed.size() == 100){
        if (prevFrame.size() != 100){
            prevFrame = CT->resampleSmoothed;
        }
        
        for (int i = 0; i < 100; i++){
            velocities[i] = CT->resampleSmoothed[i] - prevFrame[i];
            velocitiesSmoothed[i] = 0.9 * velocitiesSmoothed[i] + 0.1 * velocities[i];
        }
        
        prevFrame = CT->resampleSmoothed;
    }

}


//---------------------------------------------------------------
void retrocolorScene::draw(){
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofSetHexColor(0xff0000);
    ofBeginShape();
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        ofCurveVertex(CT->resampleSmoothed[i]);
    }
    ofEndShape();
    
    int LOOPS = 15;
    for (int j = 0; j < LOOPS; j++) {
        ofSetColor(0,255 - j*(255/LOOPS),0);
        ofBeginShape();
        for (int i = 0; i < CT->resampleSmoothed.size(); i++){
            ofPoint vel = CT->resampleSmoothed[i] - velocitiesSmoothed[i] * 4*(j+1) + 1;
            ofCurveVertex(vel);
        }
        ofEndShape();
        
        ofSetColor(0,0,255 - j*(255/LOOPS));
        ofBeginShape();
        for (int i = 0; i < CT->resampleSmoothed.size(); i++){
            ofPoint vel = CT->resampleSmoothed[i] + velocitiesSmoothed[i] * 4*(j+1);
            ofCurveVertex(vel);
        }
        ofEndShape();
    }

//
//    ofBeginShape();
//    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
//        ofPoint vel = CT->resampleSmoothed[i] - velocitiesSmoothed[i] * 5;
//        ofCurveVertex(vel);
//    }
//    ofEndShape();
//    ofSetHexColor(0xffffff);
    
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
}
