

#include "inputManager.h"

//---------------------------------------------------------------
void inputManager::setup(){
    
    
    group.setName("settings");
    group.add(threshold.set("threshold", 100, 0, 255));
    group.add(speed.set("speed", 1, 0,2));
    group.add(medianFilterAmount.set("medianFilterAmount", 5, 0, 30));
    
    
    panel.setup();
    panel.add(group);
    
#ifdef USE_VIDEO
    player.load("videos/atwood.mov");
    player.play();
    player.setLoopState(OF_LOOP_NORMAL);
#else
    ofxKinectV2 tmp;
    vector <ofxKinectV2::KinectDeviceInfo> deviceList = tmp.getDeviceList();
    kinect = shared_ptr <ofxKinectV2> (new ofxKinectV2());
    kinect->open(deviceList[0].serial);
    panel.add(kinect->params);
#endif
    
    graypixels = new unsigned char[512*424];
    medianFiltered = new unsigned char[512*424];
    medianFilteredResult.allocate(512, 424, OF_IMAGE_GRAYSCALE);
    
    panel.loadFromFile("settings.xml");
    
    
    
}

void inputManager::changeMovie( string fileName){
#ifdef USE_VIDEO
    player.stop();
    player.load(fileName);
    player.play();
    player.setLoopState(OF_LOOP_NORMAL);
#endif
}


//---------------------------------------------------------------
void inputManager::update(){
    
    //cout << player.getWidth() << " " << player.getHeight() << endl;
#ifdef USE_VIDEO
    player.update();
    player.setVolume(0);
    player.setSpeed(speed);
    
    
    if (player.isFrameNew() == true){
        
        unsigned char * data  = player.getPixels().getData();
        for (int i = 0; i < 512*424; i++){
            graypixels[i] = data[i*3];
        }
        
        
        ctmf(graypixels, medianFiltered,
             512, 424, 512, 512,medianFilterAmount, 1);
        
        medianFilteredResult.setFromPixels(medianFiltered, 512, 424, OF_IMAGE_GRAYSCALE);
        
        finder.setSortBySize(true);
        finder.setThreshold(threshold);
        
        finder.findContours(medianFilteredResult);
    }
#else
    kinect->update();
    if( kinect->isFrameNew() ){
        texDepth.loadData( kinect->getDepthPixels() );
        //texRGB.loadData( kinect->getRgbPixels() );
        
        unsigned char * data  = kinect->getDepthPixels().getData();
        
        
        // todo is this OK ???
        for (int i = 0; i < 512*424; i++){
            graypixels[i] = data[i];
        }
        
        // todo move this to kinect.
        ctmf(graypixels, medianFiltered,
             512, 424, 512, 512,medianFilterAmount, 1);
        
        medianFilteredResult.setFromPixels(medianFiltered, 512, 424, OF_IMAGE_GRAYSCALE);
        
        finder.setSortBySize(true);
        finder.setThreshold(threshold);
        
        finder.findContours(medianFilteredResult);
        
    }
    
    
#endif
    
}


//---------------------------------------------------------------
void inputManager::draw(){
    
#ifdef USE_VIDEO
    player.draw(0,0);
    medianFilteredResult.draw(512,0);
    if (finder.size() > 0){
        ofPushMatrix();
        ofTranslate(0,424);
        finder.getPolyline(0).draw();
        ofPopMatrix();
        
    }
    //finder.draw();
#else
    texDepth.draw(0,0);
    medianFilteredResult.draw(512,0);
    if (finder.size() > 0){
        ofPushMatrix();
        ofTranslate(0,424);
        finder.getPolyline(0).draw();
        ofPopMatrix();
        
    }
#endif
    
    
    panel.draw();
}