#include <GL/glut.h>

static int shoulder = 0, elbow = 0;
static int palm = 0;

// base
static int finger1 = 0;
static int finger2 = 0;
static int finger3 = 0;
static int finger4 = 0;
static int thumb   = 0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

// RUAS JARI
void drawFinger(int angle)
{
    // kontrol ruas 1
    glRotatef((GLfloat)angle, 0.0, 0.0, 1.0);

    // ruas 1
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0.0);
    glScalef(0.4, 0.12, 0.12);
    glutWireCube(1.0);
    glPopMatrix();

    // ruas 2
    glTranslatef(0.4, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.15, 0.0, 0.0);
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    // ruas 3
    glTranslatef(0.3, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.12, 0.0, 0.0);
    glScalef(0.25, 0.08, 0.08);
    glutWireCube(1.0);
    glPopMatrix();
}

// RUAS IBU JARI
void drawThumb(int angle)
{
    glRotatef((GLfloat)angle, 0.0, 0.0, 1.0);

    // ruas 1
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0.0);
    glScalef(0.4, 0.12, 0.12);
    glutWireCube(1.0);
    glPopMatrix();

    // ruas 2
    glTranslatef(0.35, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.12, 0.0, 0.0);
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // SHOULDER
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // ELBOW
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // PALM 
    glTranslatef(1.4, 0.0, 0.0);

    // rotasi pergelangan
    glRotatef((GLfloat)palm, 0.0, 0.0, 1.0);

    glPushMatrix();
    glScalef(0.9, 0.7, 0.4);
    glutWireCube(1.0);
    glPopMatrix();

    // FINGERS

    // jari 1
    glPushMatrix();
    glTranslatef(0.45, 0.30, 0.0);
    drawFinger(finger1);
    glPopMatrix();

    // jari 2
    glPushMatrix();
    glTranslatef(0.45, 0.10, 0.0);
    drawFinger(finger2);
    glPopMatrix();

    // jari 3
    glPushMatrix();
    glTranslatef(0.45, -0.10, 0.0);
    drawFinger(finger3);
    glPopMatrix();

    // jari 4
    glPushMatrix();
    glTranslatef(0.45, -0.30, 0.0);
    drawFinger(finger4);
    glPopMatrix();

    // THUMB
    glPushMatrix();
    glTranslatef(-0.3, -0.35, 0.0);
    glRotatef(-45, 0.0, 0.0, 1.0);
    drawThumb(thumb);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;

        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;

        // telapak
        case 'p': palm = (palm + 5) % 360; break;
        case 'P': palm = (palm - 5) % 360; break;

        // jari
        case '1': finger1 = (finger1 + 5) % 360; break;
        case '2': finger2 = (finger2 + 5) % 360; break;
        case '3': finger3 = (finger3 + 5) % 360; break;
        case '4': finger4 = (finger4 + 5) % 360; break;

        case 't': thumb = (thumb + 5) % 360; break;

        case 27: exit(0); break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(700, 600);
    glutCreateWindow("Tugas2");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
