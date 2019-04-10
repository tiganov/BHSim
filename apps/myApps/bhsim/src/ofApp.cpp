#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // 2D camera setup as per https://github.com/roymacdonald/ofxInfiniteCanvas
    m_cam.removeAllInteractions();
    m_cam.addInteraction(ofEasyCam::TRANSFORM_TRANSLATE_XY, OF_MOUSE_BUTTON_LEFT);
    m_cam.addInteraction(ofEasyCam::TRANSFORM_TRANSLATE_Z, OF_MOUSE_BUTTON_RIGHT);
    m_cam.enableOrtho();
    m_cam.setNearClip(-1000000);
    m_cam.setFarClip(1000000);
    m_cam.setVFlip(true);
    
    // setup gui
    gui.setup();
    gui.add(gravGainSlider.setup("Grav Gain", 1, 0.1, 50));
    gui.add(rotGainSlider.setup("Rot Gain", 1, 0.1, 50));
    gui.add(gravToggle.setup("Toggle Grav", true));
    gui.add(rotToggle.setup("Toggle Rot", true));
    gui.add(numProtSlider.setup("# Protons", 1000, 1, 100000));
    gui.add(protSizeSlider.setup("Proton Size", 1, 1, 50));
    gui.add(timeGainSlider.setup("Time Gain", 1, 1, 50));

    ofSetBackgroundColor(ofColor::black);
    // set black hole locations
    blackHole = ofVec2f(0, 0);
    
    // generate protons
    for (int i = 0; i < numProtSlider; ++i)
    {
        protons.push_back(Proton(randomPoint(), &timeGainSlider));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    int to_add = 0;
    for (auto proton = protons.begin(); proton < protons.end(); ++proton)
    {
        if ((*proton).isAlive() && (blackHole.distance((*proton).getPos()) > (BH_RADIUS * (timeGainSlider / 3))))
        {
            ofVec2f betweenVector = blackHole - (*proton).getPos();
            
            // add gravitational force
            if (gravToggle) {
                ofVec2f gravForce = betweenVector.normalize() * (gravGainSlider / pow(betweenVector.length(), 2));
                (*proton).addVel(gravForce);
            }
            
            if (rotToggle) {
                // add rotational force
                ofVec2f rotVector = betweenVector.rotate(-90);
                ofVec2f rotForce = rotVector.normalize() * (rotGainSlider / pow(betweenVector.length(), 2));
                (*proton).addVel(rotForce);
            }
            
            // apply velocity to position
            (*proton).update();
        } else {
            protons.erase(proton);
            ++to_add;
        }
    }
    for (int i = 0; i < to_add; ++i)
    {
        protons.push_back(Proton(randomPointsOnPerimeter(), &timeGainSlider));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    m_cam.begin();
    ofSetColor(ofColor::yellow);
    for (Proton proton: protons) {
        proton.draw(protSizeSlider);
    }
    ofSetColor(ofColor::grey);
    ofDrawCircle(blackHole, BH_RADIUS);
    m_cam.end();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c')
    {
        protons.clear();
    }
    if (key == 'g')
    {
        // generate protons
        for (int i = 0; i < numProtSlider; ++i)
        {
            protons.push_back(Proton(randomPoint(), &timeGainSlider));
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
// borrowed from  https://stackoverflow.com/questions/9005750/generate-a-random-point-on-a-rectangles-perimeter-with-uniform-distribution
// user: scgrn
ofVec2f ofApp::randomPointsOnPerimeter() {
    int x1 = -SPAWN_GAIN;
    int x2 = SPAWN_GAIN;
    int y1 = -SPAWN_GAIN;
    int y2 = SPAWN_GAIN;
    int width = abs(x2 - x1);
    int height = abs(y2 - y1);
    int perimeter = (width * 2) + (height * 2);
    
    //  number of points proportional to perimeter
    int n = (int)(perimeter / 8.0f);
    
    for (int i = 0; i < n; i++) {
        int x, y;
        int dist = rand() % perimeter;
        
        if (dist <= width) {
            x = (rand() % width) + x1;
            y = y1;
        } else if (dist <= width + height) {
            x = x2;
            y = (rand() % height) + y1;
        } else if (dist <= (width * 2) + height) {
            x = (rand() % width) + x1;
            y = y2;
        } else {
            x = x1;
            y = (rand() % height) + y1;
        }
        
        return ofVec2f(x,y);
        
    }
}

//--------------------------------------------------------------
ofVec2f ofApp::randomPoint()
{
    return ofVec2f(ofRandom(-SPAWN_GAIN, SPAWN_GAIN), ofRandom(-SPAWN_GAIN, SPAWN_GAIN));
}
