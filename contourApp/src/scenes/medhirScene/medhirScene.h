#pragma once

#include "ofMain.h"
#include "baseScene.h"

class medhirScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofEasyCam camera;
    ofNode nodes[100];
    ofNode children[1000];
    ofPolyline trails[100];
    ofPolyline childTrails[1000];
    
};