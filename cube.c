#include <GL/glut.h>

GLfloat vertices[][3] = {
    {-0.5, -0.5, -0.5},  
    { 0.5, -0.5, -0.5},  
    { 0.5,  0.5, -0.5}, 
    {-0.5,  0.5, -0.5}, 
    {-0.5, -0.5,  0.5}, 
    { 0.5, -0.5,  0.5},  
    { 0.5,  0.5,  0.5},  
    {-0.5,  0.5,  0.5}  
};

void drawCube() {
    glBegin(GL_QUADS);

    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);

    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);

    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[3]);

    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[2]);

    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[2]);

    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[1]);

    glEnd();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(1.5, 1.5, 1.5, 0, 0, 0, 0, 1, 0);
    glColor3f(1.0, 0.0, 0.0); 
    drawCube();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w/h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cube using Vertices - OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
