#pragma once

#include "ofMain.h"
#include "baseScene.h"

class adnanScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    int randomizedIndexes[100];
    ofPoint reorderedPoints[100];
    bool pointUsed[100];    
};