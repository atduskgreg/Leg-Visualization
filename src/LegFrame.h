//
//  LegFrame.h
//  emptyExample
//
//  Created by Greg Borenstein on 11/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include "ofMain.h"

class LegFrame {
public:
    ofPoint baseRibCage;
    ofPoint rightHip;
    ofPoint rightKnee;
    ofPoint rightFibula;
    ofPoint rightAnkle;
    ofPoint rightHeel;
    ofPoint rightMetatarsal;
    
    float time;
    
    int radius;
    
    LegFrame(string csvLine);
    void updateLine(ofPolyline* line);
    
    void getFrameForTime(float time);
    
    void draw();
    
};

