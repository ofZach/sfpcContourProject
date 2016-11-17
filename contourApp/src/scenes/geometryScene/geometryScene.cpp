

#include "geometryScene.h"

//---------------------------------------------------------------
void geometryScene::setup(){
    

}


//---------------------------------------------------------------
void geometryScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void geometryScene::draw(){
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofNoFill();
    ofSetColor(255,255,255,255);
    
    float sinScale = ofMap( sin(ofGetElapsedTimef()), -1, 1,0.1, 0.8 );
    
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        
        ofPoint pos = CT->resampleSmoothed[i];
        ofDrawRectangle(pos.x,pos.y, 100 + sin(ofGetElapsedTimef()*2.0 + i*sinScale) * 100, 20);
    }

    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
}