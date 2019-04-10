#include "proton.h"

Proton::Proton(ofVec2f _pos, ofxFloatSlider* _timeGain)
{
    timeGain = _timeGain;
    pos = _pos;
    vel = ofVec3f(ofRandom(-5, 5), ofRandom(-5, 5), ofRandom(-5, 5)).normalize();
    max_life = ofRandom(3000, 5000);
}

void Proton::update()
{
    pos += vel.normalize() * (*timeGain);
    vel = ofVec2f(0, 0);
    ++life;
}

ofVec2f Proton::getPos()
{
    return pos;
}

ofVec2f Proton::getVel()
{
    return vel;
}

bool Proton::isAlive()
{
    return life < max_life;
}

void Proton::addVel(ofVec2f force)
{
    vel += force;
}

void Proton::draw(float size)
{
    ofDrawCircle(pos, size);
}
