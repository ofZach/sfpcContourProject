#include "retrocolorScene.h"

//---------------------------------------------------------------
void retrocolorScene::setup(){
    ofBackground(255, 255, 255);
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
    
    ofSetHexColor(0xDC8A6D);
    ofBeginShape();
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        ofCurveVertex(CT->resampleSmoothed[i]);
    }
    ofEndShape();
    ofSetHexColor(0x2B42B8);
    ofBeginShape();
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        ofPoint vel = CT->resampleSmoothed[i] - velocitiesSmoothed[i] * 10;
        ofCurveVertex(vel);
    }
    ofEndShape();
    ofSetHexColor(0xADBFB8);
    ofBeginShape();
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        ofPoint vel = CT->resampleSmoothed[i] - velocitiesSmoothed[i] * 5;
        ofCurveVertex(vel);
    }
    ofEndShape();
    ofSetHexColor(0xffffff);
    
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
}
