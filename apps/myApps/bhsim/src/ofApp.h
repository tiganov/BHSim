#pragma once

#include "ofMain.h"
#include "proton.h"
#include "ofxGui.h"

#define MAX_PROTONS 1000
#define BH_RADIUS 10
#define SPAWN_GAIN 15000

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // generates new random protons
    ofVec2f randomPointsOnPerimeter();
    ofVec2f randomPoint();
    
private:
    // control panel
    ofxPanel gui;
    ofxFloatSlider gravGainSlider;
    ofxFloatSlider rotGainSlider;
    ofxToggle gravToggle;
    ofxToggle rotToggle;
    ofxFloatSlider numProtSlider;
    ofxFloatSlider protSizeSlider;
    ofxFloatSlider timeGainSlider;
    
    vector<Proton> protons;
    
    ofVec2f blackHole;
    
    // camera
    ofEasyCam m_cam;
    
};
