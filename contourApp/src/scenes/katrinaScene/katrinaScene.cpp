

#include "katrinaScene.h"

//---------------------------------------------------------------
void katrinaScene::setup(){
    ofBackground(231,120,20);
}




//---------------------------------------------------------------
void katrinaScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void katrinaScene::draw(){
    if (CT->resampleSmoothed.size() == 100){
        for (int i = 0; i < CT->resampleSmoothed.size(); i++){
            
            int i_p_1 = i+50;
            int i_m_1 = i-50;
            if (i_m_1 < 0){
                i_m_1 += CT->resampleSmoothed.size();
            }
            
            if (i_p_1 == CT->resampleSmoothed.size()){
                i_p_1 = 0;
            }
            
        
            
            ofPoint diff = CT->resampleSmoothed[i_p_1] - CT->resampleSmoothed[i_m_1];
            diff.normalize();
            diff.rotate(120, ofPoint(0,1,1));
            
            //ofDrawLine( CT->resampleSmoothed[i], CT->resampleSmoothed[i] + diff *10 + ofGetElapsedTimef());
            ofSetColor(sin(ofGetElapsedTimef() + i)*127 + 127, 140, 120);
            
            ofDrawEllipse(CT->resampleSmoothed[i].x, CT->resampleSmoothed[i].y, 1000 * sin(i*.1 + ofGetElapsedTimef()), 150);
            //icoSphere.set(20, 1);
            //icoSphere.setPosition(CT->resampleSmoothed[i].x, CT->resampleSmoothed[i].y, 100 * sin(i*.1 + ofGetElapsedTimef()));
            //icoSphere.drawWireframe();
            
            
            
//            ofIcoSpherePrimitive icoSphere;
//            icoSphere.set(20, 1);
//            icoSphere.setPosition(CT->resampleSmoothed[i].x, CT->resampleSmoothed[i].y, 100 * sin(i*.1 + ofGetElapsedTimef()));
//            icoSphere.drawWireframe();
           

            
//            ofMesh m;
//            m.setMode(OF_PRIMITIVE_LINES);
//            m.addVertex(CT->resampleSmoothed[i]);
//            m.addColor(ofColor(255,255,255,255));
//            
//            ofSetColor(200, 300, 120);
//            
//            m.addVertex(CT->resampleSmoothed[i] + diff * 200);
//            m.addColor(ofColor(255,255,255,0));
//            
//            
//            m.draw();

            
        }
    }

}