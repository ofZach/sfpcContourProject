

#include "medhirScene.h"

//---------------------------------------------------------------
void medhirScene::setup(){
    

}


//---------------------------------------------------------------
void medhirScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed
    
    if (CT->resampleSmoothed.size() == 100){
        for (int i = 0; i < 100; i++){
            nodes[i].setPosition(CT->resampleSmoothed[i].x, CT->resampleSmoothed[i].y, CT->resampleSmoothed[i].z);
            trails[i].addVertex(nodes[i].getGlobalPosition());
            if(trails[i].size() > 20){
                trails[i].getVertices().erase(trails[i].getVertices().begin());
            }
            
            nodes[i].rotate(1, 0, 1, 1);
//            nodes[i].rotate(0, 0, 0, 1);
            
            for (int j = 0; j < 10; j++){
                children[i*10+j].setParent(nodes[i]);
                children[i*10+j].setPosition(-sin(i*10+j)*100, 0, 0);
               children[i*10+j].rotateAround(ofQuaternion(0,0,0,1), nodes[i].getGlobalPosition());
               // children[i*10+j].rotateAround(ofQuaternion(0,1,0,1), nodes[i].getGlobalPosition());
                childTrails[i*10+j].addVertex(children[i*10+j].getGlobalPosition());
                
                if(childTrails[i*10+j].size() > 10) {
                    childTrails[i*10+j].getVertices().erase(childTrails[i*10+j].getVertices().begin());
                }
            }
        }
    }
}


//---------------------------------------------------------------
void medhirScene::draw(){
//    camera.begin();
    for (int i = 0; i < 100; i++){
//        trails[i].draw();
    }
    
    float sinScale = ofMap(sin(ofGetElapsedTimef()), -1, 1,0.1, 0.2);
    float cosScale = ofMap(cos(ofGetElapsedTimef()), -1, 1, 0.1, 0.9);
    
    for (int i = 0; i < 1000; i++)
    {
        ofNoFill();
        ofSetLineWidth(cos(ofGetElapsedTimef())*0.05);
        ofDrawCircle(children[i].getGlobalPosition().x, children[i].getGlobalPosition().y, cos(ofGetElapsedTimef()+i*sinScale*cosScale)*17);
    }
//    camera.end();
}