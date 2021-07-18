#ifndef STONE_H
#define STONE_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "ellipse.h"
class Stone
{
public:
    void draw(int xpos, int ypos)
    {
        glDisable(GL_TEXTURE_2D);
        Ellipse ellipse;
        ellipse.setColor(0, 0, 0);
        ellipse.draw(xpos, ypos, 50, 30, 3, false, 0, 360);
    }
};
#endif /* BIRD_H*/
