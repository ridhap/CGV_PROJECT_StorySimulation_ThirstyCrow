/*#ifndef SECTOR_H
#define SECTOR_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else*/
#include <GL/glut.h>
//#endif
#include <math.h>
#include <iostream>
#include <string>
class Sector
{
private:
    float color[3];

public:
    void setColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    void draw(int r, int startAngle, int stopAngle, int depthIndex)
    {
        float x = 0;
        float y = 0;
        glPushMatrix();
        glColor3fv(color);
        x = r * cos((startAngle * 3.142) / 180);
        y = r * sin((startAngle * 3.142) / 180);
        float t1x = x;
        float t1y = y;
        glBegin(GL_POLYGON);
        for (float t = startAngle; t <= stopAngle; t++)
        {
            float angle = (t * 3.142) / 180;
            x = r * cos(angle);
            y = r * sin(angle);
            glVertex3f(x, y, depthIndex);
        }
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(x, y, depthIndex);
        glVertex3f(t1x, t1y, depthIndex);
        glVertex3f(0, 0, depthIndex);
        glEnd();
        glPopMatrix();
    }
    void drawWing(int state, int depthIndex, int xpos, int ypos)
    {
        glPushMatrix();
        glTranslatef(xpos, ypos, 0);
        glRotatef(state, 0, 0, 1);
        draw(400, 45, 135, depthIndex);
        glPopMatrix();
    }
};
//#endif /* SECTOR_H */
#pragma once
