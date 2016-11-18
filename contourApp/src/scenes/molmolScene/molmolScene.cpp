

#include "molmolScene.h"

//---------------------------------------------------------------
void molmolScene::setup(){
    
    ofDirectory dir;
    dir.listDir("molmol");
    for (int i = 0; i < dir.size(); i++){
        
        cout << dir.getPath(i) << endl;
        
        ofImage img;
        imgs.push_back(img);
        imgs.back().load(dir.getPath(i));
        
//        
//        
//        for (int j = 0; j < imgs.back().getPixels().size(); j++){
//            imgs.back().getPixels()[j] = 255 - imgs.back().getPixels()[j];
//        }
//        
//        imgs.back().update();
//        
//        imgs.back().save(ofToString(imgs.size()) + ".png");
        //cout << imgs.back().getWidth() << endl;
        
    }
    
    for (int i = 0; i < 100; i++){
        velSmooth[i] = 0.0;
        angleSmooth[i] = 0.0;
        scaleVari[i] = ofRandom(0.2, 0.6);;
        
    }
    
}


//---------------------------------------------------------------
void molmolScene::update(){
    
    if (CT->resampleSmoothed.size() == 100){
        
        for (int i = 0; i < 100; i++){
            trails[i].addVertex(CT->resampleSmoothed[i] );
            
            if (trails[i].size() > 3){
                trails[i].getVertices().erase(trails[i].getVertices().begin());
            }
        }
        
    }
    
}


//---------------------------------------------------------------
void molmolScene::draw(){
    
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetRectMode(OF_RECTMODE_CENTER);
    int count = 0;
    for (int i = 0; i < 100; i+=5){
    
        
        if ( trails[i].size() > 0){
        
            //cout << "hi! " << endl;
            
            int me_m_1 = i-2;
            int me_p_1 = i+2;
            if (me_m_1 < 0) me_m_1 += 100;
            me_p_1 %= 100;
            
            
            ofPoint diff = (trails[i][me_m_1] - trails[i][me_p_1]);
            float dist = (trails[i][0] - trails[i][trails[i].size()-1]).length();
            float angle = atan2(diff.y, diff.x);
            float angleDiff = angle - angleSmooth[i];
            if (angleDiff < -PI) angleDiff += TWO_PI;
            if (angleDiff > PI) angleDiff -= TWO_PI;
            angleSmooth[i] += angleDiff * 0.1;
            velSmooth[i] = 0.9 * velSmooth[i] + 0.1 * dist;
            //cout << dist << endl;
            float scale = ofMap( velSmooth[i], 0, ofGetMouseX()*0.1, 0.0, 4.2);
            
            ofSetColor(255);
            
            ofPushMatrix();
            ofTranslate(trails[i][0]);
            ofScale(scaleVari[i], scaleVari[i]);
            ofRotateZ(angleSmooth[i] * RAD_TO_DEG + ofGetMouseX());
           // ofTranslate(scale*300.0, 0);
            imgs[count % imgs.size()].draw( 0,0);
            ofPopMatrix();
            count++;
        }
        
        //trails[i].draw();
    }
    
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    
    
    
    //CT->resampleSmoothed.draw();
    
}