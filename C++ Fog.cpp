#include <GL/glut.h>

void init() {
    glEnable(GL_DEPTH_TEST); // Enables depth testing for 3D effects
    glEnable(GL_FOG);        // Enables fog effect

    // Set fog color to a light grayish tone
    GLfloat fogColor[4] = { 0.7f, 0.7f, 0.7f, 1.0f };
    glFogfv(GL_FOG_COLOR, fogColor);

    // Set fog density (how thick the fog is)
    glFogf(GL_FOG_DENSITY, 0.05f);
    glFogi(GL_FOG_MODE, GL_EXP2);  // Fog mode: exponential squared for smoother effect

    glHint(GL_FOG_HINT, GL_NICEST); // Quality hint for better fog
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set camera position
    gluLookAt(0.0, 0.0, 5.0,   // Camera position
        0.0, 0.0, 0.0,   // Look-at point
        0.0, 1.0, 0.0);  // Up direction

    // Draw objects to be affected by fog
    glColor3f(1.0, 0.5, 0.2);  // Set color for the object
    glutSolidTeapot(1.0);      // Draw a teapot as an example object

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Fog Effect in OpenGL");

    init();                 // Initialize fog and OpenGL settings
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
