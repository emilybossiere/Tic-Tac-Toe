#include "App.h"
#include <vector>
#include <random>
#include <iostream>


const float pi = 3.14159265;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    
    cout << "Press A for single player, B for multiplayer" << endl;
    
    
    
    Rect rect1 = Rect(0.25, -0.25, 0.5, 0.5, false); 
    v.push_back(rect1);
    
    Rect rect2 = Rect(-0.25, -0.25, 0.5, 0.5, false);
    v.push_back(rect2);
    
    Rect rect3 = Rect(-0.75, -0.25, 0.5, 0.5, false);
    v.push_back(rect3);
    
    Rect rect4 = Rect(0.25, 0.25, 0.5, 0.5, false);
    v.push_back(rect4);
    
    Rect rect5 = Rect(-0.25, 0.25, 0.5, 0.5, false);
    v.push_back(rect5);
    
    Rect rect6 = Rect(-0.75, 0.25, 0.5, 0.5, false);
    v.push_back(rect6);
    
    Rect rect7 = Rect(0.25, 0.75, 0.5, 0.5, false);
    v.push_back(rect7);
    
    Rect rect8 = Rect(-0.25, 0.75, 0.5, 0.5, false);
    v.push_back(rect8);
    
    Rect rect9 = Rect(-0.75, 0.75, 0.5, 0.5, false);
    v.push_back(rect9);
    
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    number = -1;
    count = 0;
    you = true;
    random = true;
}



void App::draw() {
    
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    // Draw some points
/*    glBegin(GL_POINTS);
    
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    
    glEnd();
    
    // Draw a yellow cross
    glColor3d(1.0, 1.0, 0.0);
    
    glBegin(GL_LINES);
    
    glVertex2f(mx - 0.05f, my);
    glVertex2f(mx + 0.05f, my);
    
    glVertex2f(mx, my - 0.05f);
    glVertex2f(mx, my + 0.05f);
    
    glEnd(); */
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    
    
    for (int i = 0; i < v.size(); i++) {
        glColor3d(0.0, 0.0, 0.0);
        //draw X
        glBegin(GL_LINES);

        if (v[i].getR()) {
            glVertex2f(v[i].getX()+0.1, v[i].getY()-0.1);
            glVertex2f(v[i].getX() +0.4, v[i].getY()-0.4);
            glVertex2f(v[i].getX() +0.1, v[i].getY()-0.4);
            glVertex2f(v[i].getX() +0.4, v[i].getY() - 0.1);
        }
        glEnd();
        
        //draw O
        if (v[i].getG()) {
            
            glBegin(GL_LINE_LOOP);
            for (int j = 0; j <= 300; j++) {
                double angle = (2 * pi * j) / 300;
                
                double y = sin(angle);
                double x = cos(angle);
                
                
                glVertex2d(x*0.15+v[i].getX()+0.25, y*0.15+v[i].getY()-0.25);
            }
            glEnd();
        }
    }
    ////////////BOARD///////////////
    //square 1
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.713725490196078, 0.756862745098039);
    
    glVertex2f(-0.75, 0.75);
    glVertex2f(-0.75, 0.25);
    glVertex2f(-0.25, 0.25);
    glVertex2f(-0.25, 0.75);
    
    glEnd();
    
    //square 2
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 0.5);
    
    glVertex2f(-0.25, 0.75);
    glVertex2f(-0.25, 0.25);
    glVertex2f(0.25, 0.25);
    glVertex2f(0.25, 0.75);
    
    glEnd();
    
    //square 3
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.713725490196078, 0.756862745098039);
    
    glVertex2f(0.25, 0.75);
    glVertex2f(0.25, 0.25);
    glVertex2f(0.75, 0.25);
    glVertex2f(0.75, 0.75);
    
    glEnd();
    
    //square 4
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 0.5);
    
    glVertex2f(-0.75, 0.25);
    glVertex2f(-0.75, -0.25);
    glVertex2f(-0.25, -0.25);
    glVertex2f(-0.25, 0.25);
    
    glEnd();
    
    //square 5
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.713725490196078, 0.756862745098039);
    
    glVertex2f(-0.25, 0.25);
    glVertex2f(-0.25, -0.25);
    glVertex2f(0.25, -0.25);
    glVertex2f(0.25, 0.75);
    
    glEnd();
    
    //square 6
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 0.5);
    
    glVertex2f(0.25, 0.75);
    glVertex2f(0.25, -0.25);
    glVertex2f(0.75, -0.25);
    glVertex2f(0.75, 0.75);
    
    glEnd();
    
    //square 7
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.713725490196078, 0.756862745098039);
    
    glVertex2f(-0.75, -0.25);
    glVertex2f(-0.75, -0.75);
    glVertex2f(-0.25, -0.75);
    glVertex2f(-0.25, -0.25);
    
    glEnd();
    
    //square 8
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 0.5);
    
    glVertex2f(-0.25, -0.25);
    glVertex2f(-0.25, -0.75);
    glVertex2f(0.25, -0.75);
    glVertex2f(0.25, 0.25);
    
    glEnd();
    
    //square 9
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.713725490196078, 0.756862745098039);
    
    glVertex2f(0.25, 0.25);
    glVertex2f(0.25, -0.75);
    glVertex2f(0.75, -0.75);
    glVertex2f(0.75, -0.25);
    
    glEnd();
    ////////////////////////////
    
    
    glFlush();
    glutSwapBuffers();
}

void App::didWin() {
    
    if (v[0].getG() && v[1].getG() && v[2].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[0].getG() && v[3].getG() && v[6].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[0].getG() && v[4].getG() && v[8].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[1].getG() && v[4].getG() && v[7].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[2].getG() && v[4].getG() && v[6].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[2].getG() && v[5].getG() && v[8].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[3].getG() && v[4].getG() && v[5].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[6].getG() && v[7].getG() && v[8].getG()) {
        cout << "O wins!" << endl;
        return;
    }
    if (v[0].getR() && v[1].getR() && v[2].getR()) {
        cout << "X wins!" << endl;
        return;
    }
    if (v[0].getR() && v[3].getR() && v[6].getR()) {
        cout << "X wins!" << endl;
        return;
    }
    if (v[0].getR() && v[4].getR() && v[8].getR()) {
        cout << "X wins!" << endl;
        return;
    }
    if (v[1].getR() && v[4].getR() && v[7].getR()) {
        cout << "X wins!" << endl;
        return;
    }
    if (v[2].getR() && v[4].getR() && v[6].getR()) {
        cout << "X wins!" << endl;
        return;
    }
    if (v[2].getR() && v[5].getR() && v[8].getR()) {
        cout << "X wins!" << endl;
        return;
    }
    
    if (v[3].getR() && v[4].getR() && v[5].getR()) {
        cout << "X wins!" << endl;
        return;
    }
    if (v[6].getR() && v[7].getR() && v[8].getR()) {
        cout << "X wins!" << endl;
        return;
    }
   /* if ((v[0].getG() && v[1].getG()  v[2].getG() && v[3].getG() && v[4].getG() && v[5].getG() && v[6].getG() && v[7].getG() && v[8].getG()) && (v[0].getR() && v[1].getR() && v[2].getR() && v[3].getR() && v[4].getR() && v[5].getR() && v[6].getR() && v[7].getR() && v[8].getR())){
        cout << "Tie Game!" << endl;
        return;
    } */
}

void App::didClick() {
    if (you) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].contains(vec) && v[i].getB() == false) {
                if (number == -1) {
                    v[i].setG(true);
                    number = i;
                    v[i].setB(true);
                }
                else {
                    if (v[number].getG()) {
                        v[i].setR(true);
                        number = i;
                        v[i].setB(true);
                    }
                    else {
                        v[i].setG(true);
                        number = i;
                        v[i].setB(true);
                    }
                }
            }
        }
        redraw();
    } else {
        for (int c = 0; c < v.size(); c++) {
            if (v[c].contains(vec) && v[c].getB() == false) {
                
                v[c].setG(true);
                
                v[c].setB(true);
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i].getB() == false) {
                
                v[i].setR(true);
                
                v[i].setB(true);
                break;
            }
        }
    }
        
    redraw();
    
}

void App::mouseDown(float x, float y) {
    mx = x;
    my = y;
    vec = Vec(mx, my);
    didClick();
    didWin();
}


void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    
    if (key == 27) {
        // Exit the app when Esc key is pressed
        exit(0);
    }
    
    if (key == 'a') {
        cout << "Make the first move" << endl;
        
        you = false;
    }
    if (key == 'b') {
        cout << "Two player game" << endl;
        
    }
    
}
