#pragma once

#include "ofMain.h"
#include "baseScene.h"

class molmolScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();

    ofPolyline trails[100];
    
    vector < ofImage > imgs;
    
    float velSmooth[100];
     float angleSmooth[100];
    
    float scaleVari[100];
    
};