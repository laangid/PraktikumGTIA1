#include <gl/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // GL_LINE_STRIP
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9,0.7);
        glVertex2f(-0.7,0.5);
        glVertex2f(-0.5,0.7);
        glVertex2f(-0.3,0.5);
    glEnd();

    // GL_LINE_LOOP
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2,0.7);
        glVertex2f(0.0,0.5);
        glVertex2f(0.2,0.7);
        glVertex2f(0.0,0.9);
    glEnd();

    // GL_TRIANGLE_STRIP
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.9,0.2);
        glVertex2f(-0.7,0.2);
        glVertex2f(-0.8,0.0);
        glVertex2f(-0.6,0.0);
        glVertex2f(-0.7,-0.2);
    glEnd();

    // GL_TRIANGLE_FAN
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.2,0.1);
        glVertex2f(-0.4,-0.2);
        glVertex2f(-0.1,-0.3);
        glVertex2f(0.1,-0.2);
        glVertex2f(0.0,0.1);
    glEnd();

    // GL_QUADS
    glColor3f(1,0,1);
    glBegin(GL_QUADS);
        glVertex2f(0.2,0.2);
        glVertex2f(0.4,0.2);
        glVertex2f(0.4,0.0);
        glVertex2f(0.2,0.0);
    glEnd();

    // GL_QUAD_STRIP
    glColor3f(0,1,1);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.5,0.3);
        glVertex2f(0.5,0.0);

        glVertex2f(0.7,0.3);
        glVertex2f(0.7,0.0);

        glVertex2f(0.9,0.3);
        glVertex2f(0.9,0.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutCreateWindow("Primitive Drawing");

    glClearColor(0,0,0,1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
