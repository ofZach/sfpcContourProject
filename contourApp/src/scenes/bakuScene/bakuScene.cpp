

#include "bakuScene.h"

//---------------------------------------------------------------
void bakuScene::setup(){
	
	shader.load("baku/feedback.vert", "baku/feedback.frag");
	
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
			shader.begin();
			shader.setUniform1f("time", ofGetElapsedTimef());
			shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
			shader.setUniformTexture("prevTex", pingPong.src->getTexture(), 0);
			
			ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
			
			shader.end();
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
