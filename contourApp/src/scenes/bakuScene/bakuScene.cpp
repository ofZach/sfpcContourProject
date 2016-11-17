

#include "bakuScene.h"

//---------------------------------------------------------------
void bakuScene::setup(){
	
	displaceShader.load("baku/displace");
	
	pingPong.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
	
	ofLogNotice() << ofGetWidth() << " " << ofGetHeight();
	
	ofPushStyle();
	pingPong.src->begin();
	{
		ofSetColor(0, 0, 0);
		ofDrawRectangle(0, 0, pingPong.dst->getWidth(), pingPong.dst->getHeight());
		
	}
	pingPong.src->end();
	ofPopStyle();

}

//---------------------------------------------------------------
void bakuScene::update(){
	
	ofPolyline& contour = CT->resampleSmoothed;
	contour = contour.getSmoothed(1);
	
    if (CT->resampleSmoothed.size() == 100){
		
		pingPong.swap();
		
		// udpate canvas
		pingPong.src->begin();
		{
			
			ofSetColor(255);
			
//			for (auto& pt : contour.getVertices()) {
//				ofDrawCircle(pt, 3);
//			}
			
			contour.draw();
		}
		pingPong.src->end();
		
		// displace
		pingPong.dst->begin();
		{
			displaceShader.begin();
			displaceShader.setUniform1f("time", ofGetElapsedTimef());
			displaceShader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
			displaceShader.setUniformTexture("prevTex", pingPong.src->getTexture(), 0);
			
			ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
			
			displaceShader.end();
		}
		pingPong.dst->end();
	}
}

//---------------------------------------------------------------
void bakuScene::draw(){
	
	ofPushStyle();
	
	ofClear(0);
	ofSetColor(255);
	pingPong.dst->draw(0, 0);
	
	ofPopStyle();
}

//---------------------------------------------------------------
void bakuScene::resize(int w, int h) {
	pingPong.src->allocate(w, h);
	pingPong.dst->allocate(w, h);
}
