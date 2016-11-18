#pragma once

#include "ofMain.h"
#include "baseScene.h"

class bodybitsScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
    
    ofImage bbimg;
    ofImage bodybitImages[29];
//    ofImage * pointImages[100];
    string path;
    ofDirectory imgDir;
    int dirSize;

};
