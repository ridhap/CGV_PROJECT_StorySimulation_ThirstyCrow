/*#ifndef BIRD_H
#define BIRD_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else*/
#include <GL/glut.h>
//#endif
#include "line.h"
#include "ellipse.h"
#include "sector.h"
#include "circle.h"
#include "Triangle.h"
#include<string>
using namespace std;
class Bird
{
private:
    void tail(void)
    {
        Line line;
        line.setColor(0.128, 0.128, 0.128);
        line.draw(200, 400, 0, 350, 1);
        line.draw(200, 400, 30, 300, 1);
        line.draw(200, 400, 50, 240, 1);
        line.draw(200, 400, 110, 245, 1);
    }
    void body(void)
    {
        Ellipse ellipse;
        ellipse.setColor(0.128, 0.128, 0.128);
        ellipse.draw(500, 400, 300, 200, 2, false, 0, 360);
    }
    void wing(int flapState)
    {
        Sector sector;
        glPushMatrix();
        glTranslatef(500, 400, 0);
        glRotatef(flapState, 0, 0, 1);
        sector.setColor(0, 0, 0);
        sector.draw(400, 55, 125, 1);
        glPopMatrix();
    }
    void face(void)
    {
        Circle circle;
        circle.setColor(0.128, 0.128, 0.128);
        circle.draw(170, 900, 400, 2, false);
    }
    void eye(void)
    {
        Circle circle;
        circle.setColor(1, 1, 1);
        circle.draw(20, 1000, 400, 1, false);
    }
    void beak(void)
    {
        Triangle triangle;
        triangle.setColor(0, 0, 0);
        triangle.draw(1000, 300, 1000, 500, 1150, 400, 2);
    }
    void drawtext(float x, float y, string s)
    {
        glColor3f(0, 0, 0);
        glRasterPos2f(x, y);
        for (int i = 0; s[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
        glFlush();
    }
    void drawtext(float x, float y, string s, int t)
    {
        glColor3f(1, 1, 1);
        glRasterPos2f(x, y);
        for (int i = 0; s[i] != '\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
        glFlush();
    }
    void legs(void)
    {
        Line line;
        line.setColor(0, 0, 0);
        line.draw(600, 250, 500, 100, 2);
        line.draw(500, 100, 550, 60, 2);
        line.draw(500, 250, 400, 100, 2);
        line.draw(400, 100, 460, 10, 2);
        line.draw(550, 60, 620, 30, 1);
        line.draw(550, 60, 530, 15, 1);
        line.draw(460, 10, 510, 0, 1);
    }

public:
    void drawBird(int flapState, int xpos, int ypos)
    {
        glDisable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        tail();
        body();
        wing(flapState);
        face();
        eye();
        beak();
        glPopMatrix();
        glEnable(GL_TEXTURE_2D);
    }
    void drawBird(int flapState, int xpos, int ypos,int t)
    {
        glDisable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        tail();
        body();
        Ellipse ellipse;
        ellipse.setColor(0, 0, 0);
        ellipse.draw(500, 400, 200, 100, 1, false, 0, 360);
        legs();
        face();
        eye();
        beak();
        glPopMatrix();
    }
    void cloud(int xpos, int ypos, string line1,  string line2)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        Circle circle;
        circle.setColor(1, 1, 1);
        circle.draw(80, 80, 80, 1, false);
        circle.draw(120, 270, 200, 1, false);
        Ellipse ellipse;
        ellipse.setColor(1, 1, 1);
        ellipse.setColor(1, 1, 1);
        ellipse.draw(680, 400, 300, 200, 1, false, 0, 360);
        drawtext(500, 420, line1);
        drawtext(500, 330, line2);
        glPopMatrix();
    }
    void cloud(int xpos, int ypos,  string line1, string line2, int t)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        Circle circle;
        circle.setColor(0, 0, 0);
        circle.draw(80, 80, 80, 1, false);
        circle.draw(120, 270, 200, 1, false);
        Ellipse ellipse;
        ellipse.setColor(0, 0, 0);
        ellipse.draw(680, 400, 300, 200, 1, false, 0, 360);
        drawtext(500, 420, line1, 1);
        drawtext(500, 330, line2, 1);
        glPopMatrix();
    }
};
//#endif /* BIRD_H*/