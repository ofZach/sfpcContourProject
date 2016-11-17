#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ctmf.h"
#include "ofxGui.h"
#include "ofxKinectV2.h"

using namespace milton;

#define USE_VIDEO

class inputManager {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void changeMovie( string fileName);
    
    
#ifdef USE_VIDEO
    ofVideoPlayer player;
#else
    shared_ptr<ofxKinectV2>  kinect;
    ofTexture texDepth;
    ofTexture texRGB;
#endif
    
    
    
    // I basically have a contour that represents the blob on this frame.
    
    bool bFoundABlobThisFrame;
    unsigned char * thresholdedImage;
    
    unsigned char * graypixels;
    unsigned char * medianFiltered;
    
    ofImage medianFilteredResult;
    
    ofxCv::ContourFinder finder;
    
    ofParameterGroup group;
    ofParameter < int > threshold;
    ofParameter < int > medianFilterAmount;
    ofParameter < float > speed;
    ofxPanel panel;
    
    
};