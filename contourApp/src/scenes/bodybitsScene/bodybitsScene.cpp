

#include "bodybitsScene.h"

//---------------------------------------------------------------
void bodybitsScene::setup(){
    
    
    string path = "bodybitsScene";
    ofDirectory imgDir(path);
    //only show png files
    imgDir.allowExt("png");
    //populate the directory object
    imgDir.listDir();
    int dirSize = imgDir.size();
    cout << dirSize << endl;
    
    // load an ofImage for each PNG
    for (int i = 0; i < dirSize; i++){
        //ofImage bbimg = bodybitImages[i];
        cout << imgDir.getPath(i) << endl;
        bodybitImages[i].load(imgDir.getPath(i));
    }

    //
//    // assign image to points (we are working with 100 points and 29 images)
//    for (int i = 0; i < 100; i++){
//        pointImages[i] = &bodybitImages[i % dirSize];
//    }
//    
    cout << "Loaded bodybitsScene!!!!" << endl;

}


//---------------------------------------------------------------
void bodybitsScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed
    

}


//---------------------------------------------------------------
void bodybitsScene::draw(){
    
    
//    ofEnableAlphaBlending();
    
    //ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    ofPushStyle();
    ofSetBackgroundColor(100,100,100);
    ofDrawRectangle(0.0, 0.0, ofGetWidth(), ofGetHeight());
    
    
    if (CT->resampleSmoothed.size() == 100){
        for (int i = 0; i < CT->resampleSmoothed.size(); i++){
            
            int i_p_1 = i+1;
            int i_m_1 = i-1;
            if (i_m_1 < 0){
                i_m_1 += CT->resampleSmoothed.size();
            }
            
            if (i_p_1 == CT->resampleSmoothed.size()){
                i_p_1 = 0;
            }

            ofPoint diff = CT->resampleSmoothed[i_p_1] - CT->resampleSmoothed[i_m_1];
            diff.normalize();
            diff.rotate(-90, ofPoint(0,0,1));

            // different method of deriving same as below
            //float angle = atan2(diff.y, diff.x);
            
            // get and draw the image
            
//            int t = floor(29 * abs(sin(ofGetElapsedTimef())));
            ofPoint endPoint1 = CT->resampleSmoothed[i] + diff;
            ofPoint endPoint2 = CT->resampleSmoothed[i] + diff * 30;
//            ofPoint endPoint3 = CT->resampleSmoothed[i] + diff * 150;
            
            bodybitImages[i % 29].draw(endPoint1, 26, 25);
            bodybitImages[i % 7].draw(endPoint2, 36, 35);
//            bodybitImages[i % 7].draw(endPoint3, 36, 35);

            
        }
    }

    //ofDisableAlphaBlending();
    ofPopStyle();
    

}
