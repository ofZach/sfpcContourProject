#pragma once

#include "ofMain.h"
#include "baseScene.h"

class trailsScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();

    ofPolyline trails[100];
    
    
    
};