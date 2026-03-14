#include <gl/glut.h>

void drawCube(float x, float y)
{
    glBegin(GL_QUADS);
        glVertex2f(x,y);
        glVertex2f(x+0.15,y);
        glVertex2f(x+0.15,y-0.15);
        glVertex2f(x,y-0.15);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2,0.6,1.0);

    drawCube(-0.3,-0.1);
    drawCube(-0.13,-0.1);
    drawCube(0.04,-0.1);

    drawCube(-0.21,0.05);
    drawCube(-0.04,0.05);

    drawCube(-0.13,0.2);

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutCreateWindow("Kubus Bertingkat");

    glClearColor(0,0,0,1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
