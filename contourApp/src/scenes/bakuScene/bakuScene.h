#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxSwapBuffer.h"

class bakuScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
	
	
private:
	
	int width, height;
	
	ofShader shader;
	ofxSwapBuffer pingPong;
	
};
