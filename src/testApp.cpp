// Simple video Picker
// by Berio. November 2008.
// Do whatever you want with this
// More info: http://www.berio.alg-a.org/spip.php?article136

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
	ofHideCursor();
	
	ofBackground(0,0,0);
	vidPlayer.loadMovie("video05.mov");
	vidPlayer.play();
	cWidth = vidPlayer.width;
	cHeight = vidPlayer.height;
	cropWidth = 100;
	cropHeight = 100;
    
}

//--------------------------------------------------------------
void testApp::update(){
	vidPlayer.idleMovie();
	pixels = vidPlayer.getPixels();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(256, 256, 256);
	vidPlayer.draw(0, 0, cWidth, cHeight);
    
	//______Draw the rgb channels and colors____________________
	ofFill();
	ofSetColor(rColor, gColor, bColor);
	ofRect(10, cHeight + 10, 100, 100);
	ofSetColor(rColor, rColor, rColor);
	ofRect(120, cHeight + 10, 100, 100);
	ofSetColor(gColor, gColor, gColor);
	ofRect(230, cHeight + 10, 100, 100);
	ofSetColor(bColor, bColor, bColor);
	ofRect(340, cHeight + 10, 100, 100);
	
    
	//____________Draw the selection rectangle__________________
	ofNoFill();
	ofRect((mouseX-cropWidth/2), (mouseY-cropHeight/2), cropWidth, cropHeight);
	ofRect(mouseX, mouseY, 2, 2);
	
	//______________________Draw the text info__________________
	string rgbString = "RGB";
	string rChannel = "Red: " + ofToString(rColor);
	string gChannel = "Green: " + ofToString(gColor);
	string bChannel = "Blue: " + ofToString(bColor);
	
	ofSetColor(250,250,250);
	ofDrawBitmapString(rgbString , 10,vidPlayer.height + 130);
	ofDrawBitmapString(rChannel , 120,vidPlayer.height + 130);
	ofDrawBitmapString(gChannel , 230,vidPlayer.height + 130);
	ofDrawBitmapString(bChannel , 340,vidPlayer.height + 130);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){	
	rColor = pixels[(mouseY * cWidth * 3) + mouseX * 3    ];
	gColor = pixels[(mouseY * cWidth * 3) + mouseX * 3 + 1];
	bColor = pixels[(mouseY * cWidth * 3) + mouseX * 3 + 2];
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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
