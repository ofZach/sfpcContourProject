

#include "offsetScene.h"

//---------------------------------------------------------------
void offsetScene::setup(){
    

}


//---------------------------------------------------------------
void offsetScene::update(){
   
    //the info you want is here:
    //CT->resampleSmoothed

}


//---------------------------------------------------------------
void offsetScene::draw(){
    
    
    
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
            
            //float angle = atan2(diff.y, diff.x);
            
//            ofLine( CT->resampleSmoothed[i],
//                    CT->resampleSmoothed[i] + diff * 90);
           
            
            ofMesh m;
            m.setMode(OF_PRIMITIVE_LINES);
            m.addVertex(CT->resampleSmoothed[i]);
            m.addColor(ofColor(255,255,255,255));
            
            m.addVertex(CT->resampleSmoothed[i] + diff * 200);
            m.addColor(ofColor(255,255,255,0));
            
            m.draw();
            
            
            
            //ofDrawLine( CT->resampleSmoothed[i],
            ///            CT->resampleSmoothed[ (i+1) % CT->resampleSmoothed.size() ]);
            
            
        }
    }

}