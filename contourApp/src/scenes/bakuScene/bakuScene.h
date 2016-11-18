#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxSwapBuffer.h"

class bakuScene : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();
	void resize(int w, int h);
	
	
private:
	
	int width, height;
	
	ofShader displaceShader;
	ofxSwapBuffer pingPong;

	
};
