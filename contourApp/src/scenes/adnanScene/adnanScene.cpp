

#include "adnanScene.h"

//---------------------------------------------------------------
void adnanScene::setup(){
    for(int i = 0; i < 100; i++) {
        int randomIndex = ofRandom(0, 100);
        
        while(pointUsed[randomIndex]) {
            randomIndex = ofRandom(0, 100);
        }
        
        randomizedIndexes[i] = randomIndex;
        pointUsed[randomIndex] = true;
    }
    

//    vector < int > order;
//    for (int i = 0; i < 100; i++){
//        order.push_back(i);
//    }
//    
//    ofRandomize(order);
    
    
}


//---------------------------------------------------------------
void adnanScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed
    
}


//---------------------------------------------------------------
void adnanScene::draw(){
//    cout << CT->resampleSmoothed.size() << endl;

    
    for(int i = 0; i < CT->resampleSmoothed.size(); i++) {
        if (CT->resampleSmoothed.size() == 100) {
            reorderedPoints[i] = CT->resampleSmoothed[randomizedIndexes[i]];
        }
    }
    
    for(int i = 0; i < CT->resampleSmoothed.size(); i++) {
        if(i + 1 < CT->resampleSmoothed.size()) {
            ofDrawLine(reorderedPoints[i], reorderedPoints[i+1]);
        } else {
            ofDrawLine(reorderedPoints[CT->resampleSmoothed.size() - 1], reorderedPoints[0]);
        }
    }
}