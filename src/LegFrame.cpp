//
//  LegFrame.cpp
//  emptyExample
//
//  Created by Greg Borenstein on 11/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "LegFrame.h"

LegFrame::LegFrame(string csvLine){
    vector<string> positions = ofSplitString(csvLine, ",");
    baseRibCage = ofPoint(ofToFloat(positions[2]), ofToFloat(positions[3]));
    rightHip = ofPoint(ofToFloat(positions[4]), ofToFloat(positions[5]));
    rightKnee = ofPoint(ofToFloat(positions[6]), ofToFloat(positions[7]));
    rightFibula = ofPoint(ofToFloat(positions[8]), ofToFloat(positions[9]));
    rightAnkle = ofPoint(ofToFloat(positions[10]), ofToFloat(positions[11]));
    rightHeel = ofPoint(ofToFloat(positions[12]), ofToFloat(positions[13]));
    rightMetatarsal = ofPoint(ofToFloat(positions[14]), ofToFloat(positions[15]));
    
    radius = 3;
}

void LegFrame::draw(){
    ofCircle(baseRibCage.x, baseRibCage.y, radius);
    ofLine(baseRibCage, rightHip);
    ofCircle(rightHip.x, rightHip.y, radius);
    ofLine(rightHip, rightKnee);
    ofCircle(rightKnee.x, rightKnee.y, radius);
    ofLine(rightKnee, rightFibula);
    ofCircle(rightFibula.x, rightFibula.y, radius);
    ofLine(rightFibula, rightAnkle);
    ofCircle(rightAnkle.x, rightAnkle.y, radius);
    ofLine(rightAnkle, rightHeel);
    ofCircle(rightHeel.x, rightHeel.y, radius);
    ofLine(rightHeel, rightMetatarsal);
    ofCircle(rightMetatarsal.x, rightMetatarsal.y, radius);
}

void LegFrame::updateLine(ofPolyline* line){
    line->clear();
    line->addVertex(baseRibCage);
    line->addVertex(rightHip);
    line->addVertex(rightKnee);
    line->addVertex(rightFibula);
    line->addVertex(rightAnkle);
    line->addVertex(rightHeel);
    line->addVertex(rightMetatarsal);
}