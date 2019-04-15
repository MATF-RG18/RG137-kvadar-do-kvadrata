#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
 
  /* Deklaracije callback funkcija. */
void on_keyboard(unsigned char key, int x, int y);
void on_display(void);
void on_timer(int id);
void material_and_light();

  /* Parametar animacije, fleg koji odredjuje da li je animacija u toku ili nije */
#define TIMER_ID 0
#define TIMER_INTERVAL 10
float animation_parameter = 0;
int animation_ongoing = 0;
 
int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
 
    /* Kreira se prozor. */
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(400, 400);
    glutCreateWindow(argv[0]);
 
    /* Poziv callback funkcija. */
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
 
    /* OpenGL inicijalizacija. */
    glClearColor(0.95, 0.4, 0.2, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
 
    /* Postavljaju se svojstva prvog svetla */
    glEnable(GL_LIGHT0);
 
    /* Program ulazi u glavnu petlju. */
    glutMainLoop();
 
    return 0;
}
 
void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;
    case 'g':
    case 'G':
        if (!animation_ongoing) {
            animation_ongoing = 1;
            glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
        break;
    case 's':
    case 'S':
        animation_ongoing = 0;
        break;
    } 
}
 
void on_display(void)
{
    /* Pozicija svetla (u pitanju je beskonacno daleko svetlo). */
    //GLfloat light_position[] = { 1, 1, 1, 0 };
 
    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    /* Inicijalizuje se matrica transformacije. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
    /* Nova slika se salje na ekran. */
    glutSwapBuffers();
}
 
void on_timer(int id)
{
    animation_parameter += .1;
 
    if (animation_ongoing) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
 
    glutPostRedisplay();
}

void material_and_light(){
     /* Parametri svetla i podrazumevanog materijala */
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };
    GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };
    GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };
 
    GLfloat ambient_coeffs[] = { 0.3, 0.7, 0.3, 1 };
    GLfloat diffuse_coeffs[] = { 0.2, 1, 0.2, 1 };
    GLfloat specular_coeffs[] = { 1, 1, 1, 1 };
    GLfloat shininess = 30;   

    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
 
    /* Postavljaju se svojstva materijala */
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
