#ifndef App_hpp
#define App_hpp
#include <vector>
#include "GlutApp.h"
#include <random>


using namespace std;



class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    class Circle {
    public:
        //
    };
    
class Vec {
public:
    float x;
    float y;
    
    Vec (){
        x = 0;
        y = 0;
    }
    
    Vec (float x, float y){
        this->x = x;
        this->y = y;
    }
    
    void add (Vec u){
        x += u.x;
        y += u.y;
    }
    
    float getX() const {
        return x;
    }
    
    float getY() const {
        return y;
    }
    
    void setX(float x) {
        this->x = x;
    }
    
    void setY(float y) {
        this->y = y;
    }
    static Vec null;
    
};
    
struct Rect {
public:
    float x;
    float y;
    float h;
    float w;
    bool b;
    bool g;
    bool r;
    
    
    
        
    Rect(float x, float y, float w, float h, bool c){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        r = c;
        b = c;
        g = c;
    }

    float getX() {
        return x;
    }
    float getY() {
        return y;
    }
    float getWidth() {
        return w;
    }
    float getHeight() {
        return h;
    }
    float getR() {
        return r;
    }
    float getG() {
        return g;
    }
    float getB() {
        return b;
    }
    
   
    
    void setX(float x) {
        this->x = x;
    }
    void setY(float y) {
        this->y = y;
    }
    void setW(float width) {
        this->w = width;
    }
    void setH(float height) {
        this->h = height;
    }
    void setR(bool c) {
        r = c;
    }
    void setG(bool c) {
        g = c;
    }
    void setB(bool c) {
        b = c;
    }
    
    
    
    bool contains(Vec v) const {
        if ( (v.x > x) && (v.x < x + w) && (v.y < y) && (v.y > y - h)){
            return true;
        }
        else
            return false;
    }
};
    
    int number;
    
    int count;
    
    bool you;
    
    
    bool random;
    Vec vec;
    vector<Rect> v;
    
    
    unsigned char k;
    
    
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void didClick();
    void didWin();
    void mouseDrag(float x, float y);
};

#endif
