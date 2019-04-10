#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class Proton
{
public:
    Proton(ofVec2f _pos, ofxFloatSlider* _timeGain);

    void update();
    ofVec2f getPos();
    ofVec2f getVel();
    void addVel(ofVec2f force);
    void draw(float size);
    bool isAlive();

private:
    ofVec2f vel = ofVec2f(0, 0);
    ofVec2f pos;
    int life = 0;
    int max_life;
    ofxFloatSlider* timeGain;
};
