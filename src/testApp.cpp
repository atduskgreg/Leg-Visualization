#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    currentFrame = -1;
    
    ofBackground(255,255,255);
    ofSetColor(0, 0, 0);
    ofSetLineWidth(2);
    ofEnableSmoothing();
    ofSetFrameRate(70);
    
    leg = ofPolyline();
    recording = false;
    fileLoaded = false;
    recordedFrame = 0;
}



//--------------------------------------------------------------
void testApp::update(){
    if(fileLoaded){
        currentFrame++;
        if(currentFrame >= frames.size()){
            currentFrame = 0;
        }
        
        frames[currentFrame].updateLine(&leg);
    
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(ofGetWidth() - 50, ofGetHeight() - 50);
    ofRotateZ(180);
    ofScale(2.0, 2.0);
    if(fileLoaded){
        frames[currentFrame].draw();
        
        if(recording){
            cout <<  ofToString(recordedFrame) + ".png" << endl;
            ofSaveScreen(ofToDataPath( ofToString(recordedFrame) + ".png"));
            recordedFrame++;
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    ofFileDialogResult result = ofSystemLoadDialog();
    cout << result.getPath() << endl;
    
    ofFile csvFile = ofFile(result.getPath());
    
    
    string line;
    while(std::getline(csvFile,line)){
        frames.push_back(LegFrame(line));
    }
    
    fileLoaded = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    recording = !recording;
    cout << "recording: " << recording << endl;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}