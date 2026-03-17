#include <gl/glut.h>
#include <math.h>

void lingkaran(float cx, float cy, float r, int segments) {
    glBegin(GL_POLYGON);

    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1416f * i / segments;
        float x = r * cos(theta);
        float y = r * sin(theta);

        glVertex2f(cx + x, cy + y);
    }

    glEnd();
}

void awan(float x, float y) {
    glColor3f(1.0, 1.0, 1.0);

    lingkaran(x, y, 0.08, 50);
    lingkaran(x + 0.12, y - 0.02, 0.08, 50);
    lingkaran(x - 0.12, y - 0.01, 0.08, 50);
    lingkaran(x + 0.05, y + 0.08, 0.08, 50);
    lingkaran(x - 0.05, y + 0.1, 0.08, 50);
}

void pohon() {
    glColor3f(0.48,0.32,0.03);
    glBegin(GL_QUADS);
        glVertex2f(-0.8,-0.2);
        glVertex2f(-0.7,-0.2);
        glVertex2f(-0.7,-0.4);
        glVertex2f(-0.8,-0.4);
    glEnd();
    
    glColor3f(0.09,0.71,0.02);
    glBegin(GL_TRIANGLE_STRIP);
    	glVertex2f(-0.9,-0.2);
    	glVertex2f(-0.6,-0.2);
    	glVertex2f(-0.75,0.1);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    	glVertex2f(-0.9,-0.1);
    	glVertex2f(-0.6,-0.1);
    	glVertex2f(-0.75,0.2);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    	glVertex2f(-0.9,0.0);
    	glVertex2f(-0.6,0.0);
    	glVertex2f(-0.75,0.3);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    	glVertex2f(-0.9,0.1);
    	glVertex2f(-0.6,0.1);
    	glVertex2f(-0.75,0.4);
    glEnd();
    
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Jalan
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_QUADS);
        glVertex2f(-1.0,-0.4);
        glVertex2f(1.0,-0.4);
        glVertex2f(1.0,-1.0);
        glVertex2f(-1.0,-1.0);
    glEnd();
    
    // Garis Marka
    glLineWidth(6.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
	    glVertex3f(-1.0, -0.9, 0.0);
	    glVertex3f(1.0, -0.9, 0.0);
    glEnd();
    
    // Rumput
    glColor3f(0.76,1.0,0.45);
    glBegin(GL_QUADS);
        glVertex2f(-1.0,-0.1);
        glVertex2f(1.0,-0.1);
        glVertex2f(1.0,-0.4);
        glVertex2f(-1.0,-0.4);
    glEnd();
    
    // Langit
    glColor3f(0.61,0.96,1.0);
    glBegin(GL_QUADS);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);
        glVertex2f(1.0,-0.1);
        glVertex2f(-1.0,-0.1);
    glEnd();
    
    //Matahari
    glColor3f(1.0,0.87,0.35);
    lingkaran(0.75, 0.7, 0.15, 50);
    
    // Awan-Awan
    glPushMatrix();
	    glTranslatef(0.0, 0.3, 0.0);
	    glRotated(15, 0.0, 0.0, 1.0);
	    awan(0.0, 0.0);
	glPopMatrix();
    
    glPushMatrix();
    	glTranslatef(-0.9, 0.59, 0.0);
    	glRotated(350, 0.0, 0.0, 1.0);
        awan(0.0, 0.0);
    glPopMatrix();
    
    awan(0.97, 0.52);
    awan(0.3, 0.85);
    awan(-0.4, 0.74);
    
    // Pohon-Pohon
    pohon();
    
    glPushMatrix();
        glTranslatef(0.75, 0.00, 0.00);
        pohon();
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(1.5, 0.00, 0.00);
        pohon();
    glPopMatrix();
    
    // Mobil Box
    // box
    glColor3f(0.96,0.96,0.96);
    glBegin(GL_QUADS);
        glVertex2f(-0.7,0.2);
        glVertex2f(0.1,0.2);
        glVertex2f(0.1,-0.6);
        glVertex2f(-0.7,-0.6);
    glEnd();
    
    // box strip
    glColor3f(0.41,0.41,0.41);
    glBegin(GL_QUADS);
        glVertex2f(-0.7,-0.5);
        glVertex2f(0.1,-0.5);
        glVertex2f(0.1,-0.6);
        glVertex2f(-0.7,-0.6);
    glEnd();
    
    // IF
    glLineWidth(4.0f);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
	    glVertex3f(-0.4, 0.0, 0.0);
	    glVertex3f(-0.4, -0.3, 0.0);
    glEnd();
    glBegin(GL_LINES);
	    glVertex3f(-0.3, 0.0, 0.0);
	    glVertex3f(-0.3, -0.3, 0.0);
    glEnd();
    glBegin(GL_LINES);
	    glVertex3f(-0.3, 0.0, 0.0);
	    glVertex3f(-0.2, 0.0, 0.0);
    glEnd();
    glBegin(GL_LINES);
	    glVertex3f(-0.3, -0.15, 0.0);
	    glVertex3f(-0.2, -0.15, 0.0);
    glEnd();
    
    // kepala
    glColor3f(1.0,0.87,0.35);
    glBegin(GL_POLYGON);
		glVertex2f(0.1,0.0);  
		glVertex2f(0.4,0.0);   
		glVertex2f(0.46,-0.2);    
		glVertex2f(0.6,-0.3);    
		glVertex2f(0.6,-0.6);    
		glVertex2f(0.1,-0.6);   
	glEnd();
	
	// kaca
	glColor3f(0.96,0.96,0.96);
    glBegin(GL_POLYGON);
		glVertex2f(0.2,-0.1);  
		glVertex2f(0.3,-0.1);   
		glVertex2f(0.4,-0.3);    
		glVertex2f(0.2,-0.3);       
	glEnd();
	
	// handle
	glLineWidth(4.0f);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
	    glVertex3f(0.2, -0.35, 0.0);
	    glVertex3f(0.27, -0.35, 0.0);
    glEnd();
    
    // roda
    glColor3f(0.0, 0.0, 0.0);
    lingkaran(-0.48, -0.62, 0.14, 50);
    glColor3f(0.84, 0.84, 0.84);
    lingkaran(-0.48, -0.62, 0.07, 50);
    
    glColor3f(0.0, 0.0, 0.0);
    lingkaran(0.35, -0.62, 0.14, 50);
    glColor3f(0.84, 0.84, 0.84);
    lingkaran(0.35, -0.62, 0.07, 50);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutCreateWindow("Mobil");

    glClearColor(0,0,0,1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
