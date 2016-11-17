

#include "velocityScene.h"

//---------------------------------------------------------------
void velocityScene::setup(){
    
    for (int i = 0; i < 100; i++){
        velocitiesSmoothed[i].set(0,0);
        
    }

}


//---------------------------------------------------------------
void velocityScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed
    
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
void velocityScene::draw(){
    
    for (int i = 0; i < CT->resampleSmoothed.size(); i++){
        
        
        // printf(...)                  // run dmc
        //cout << velocities[i].length() << endl;  // asap
        
        float scale = ofMap(velocitiesSmoothed[i].length(), 0, 10, 1, 30, true);
        ofDrawCircle(CT->resampleSmoothed[i], scale);
        //ofLine(CT->resampleSmoothed[i],
        //       CT->resampleSmoothed[i] + velocities[i] * 4);
        
        
    }
    

}