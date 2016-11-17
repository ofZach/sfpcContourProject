

#include "trailsScene.h"

//---------------------------------------------------------------
void trailsScene::setup(){
    
    
    
}


//---------------------------------------------------------------
void trailsScene::update(){
    
    if (CT->resampleSmoothed.size() == 100){
        for (int i = 0; i < 100; i++){
            trails[i].addVertex(CT->resampleSmoothed[i]);
            
            if (trails[i].size() > 50){
                trails[i].getVertices().erase(trails[i].getVertices().begin());
            }
        }
        
    }
    
}


//---------------------------------------------------------------
void trailsScene::draw(){
    
    
    for (int i = 0; i < 100; i++){
        trails[i].draw();
    }

    
}