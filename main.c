#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
 
  /* Deklaracije callback funkcija. */
void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int width, int height);
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
    glutReshapeFunc(on_reshape);
    glutKeyboardFunc(on_keyboard);
 
    /* OpenGL inicijalizacija. */
    glClearColor(0.95, 0.4, 0.2, 0);
    glEnable(GL_DEPTH_TEST);
 
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
 

    /*    sajt odakle je preuzeta nijansa plave boje
        https://community.khronos.org/t/color-tables/22518
        CadetBlue = color red 0.372549 green 0.623529 blue 0.623529
    */

void stage(){
    
    glPushMatrix();
    	glColor3f(1, 0, 0);
    	glTranslatef(0.5, 1, 0.5);
    	glScalef(1, 2, 1);
    	glutSolidCube(1);
    glPopMatrix();
    
    /*Poligon*/

    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(1, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(0.38, 0.70, 0.70);
       glTranslatef(1, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(2, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(2, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.5,0.70,0.80);
       glTranslatef(2, 0, 4);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.4,0.8,0.9);
       glTranslatef(3, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.37,0.68,0.9);
       glTranslatef(3, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.4,0.7,0.8);
       glTranslatef(3, 0, 4);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(4, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    	glColor3f(0.38, 0.70, 0.70);
       glTranslatef(4, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(4, 0, 4);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(4, 0, 5);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.5,0.70,0.80);
       glTranslatef(4, 0, 6);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.4,0.8,0.9);
       glTranslatef(4, 0, 7);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.37,0.68,0.9);
       glTranslatef(5, 0, 5);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    /*Cilj*/
    glPushMatrix();
       glColor3f(0,0,0);
       glTranslatef(5, 0, 6);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(5, 0, 7);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(6, 0, 1);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.38, 0.70, 0.70);
       glTranslatef(6, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
     glColor3f(0.4,0.70,0.80);
       glTranslatef(6, 0, 5);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(6, 0, 6);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.5,0.70,0.80);
       glTranslatef(6, 0, 7);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.8,0.9);
       glTranslatef(6, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.9);
       glTranslatef(6, 0, 9);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(7, 0, 1);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(7, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.38, 0.70, 0.70);
       glTranslatef(7, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(7, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    /* otvara se ako se negde stane
    glPushMatrix();
    //   glColor3f(0.5,1,0);
       glTranslatef(1, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    */
    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(7, 0, 7);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

//stavi X
    glPushMatrix();
       glColor3f(0.5,0.70,0.80);
       glTranslatef(7, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.8,0.9);
       glTranslatef(7, 0, 9);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.9);
       glTranslatef(8, 0, 1);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(8, 0, 2);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(8, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.38, 0.70, 0.70);
       glTranslatef(8, 0, 7);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(8, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(8, 0, 9);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.5,0.70,0.80);
       glTranslatef(9, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.8,0.9);
       glTranslatef(9, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(10, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(10, 0, 4);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.38, 0.70, 0.70);
       glTranslatef(10, 0, 5);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(10, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(11, 0, 3);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.5,0.70,0.80);
       glTranslatef(11, 0, 4);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.8,0.9);
       glTranslatef(11, 0, 5);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.9);
       glTranslatef(11, 0, 6);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(11, 0, 7);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(11, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.38, 0.70, 0.70);
       glTranslatef(11, 0, 9);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(12, 0, 4);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(12, 0, 5);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.5,0.70,0.80);
       glTranslatef(12, 0, 6);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.8,0.9);
       glTranslatef(12, 0, 7);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.37,0.68,0.9);
       glTranslatef(12, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.4,0.70,0.80);
       glTranslatef(12, 0, 9);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.372549,0.623529,0.623529);
       glTranslatef(13, 0, 4);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
       glColor3f(0.38, 0.70, 0.70);
       glTranslatef(13, 0, 5);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    /* otvara se
    glPushMatrix();
       glColor3f(0.5,1,0);
       glTranslatef(13, 0, 8);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
    */
    glPushMatrix();
       glColor3f(0.37,0.68,0.75);
       glTranslatef(13, 0, 9);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();

//staviti X
    glPushMatrix();
       glColor3f(0.37,0.68,0.9);
       glTranslatef(13, 0, 10);
       glScalef(1, 0.05, 1);
       glutSolidCube(1);
    glPopMatrix();
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
 
        material_and_light();
    
    gluLookAt(
            10, 15, 25,
            0, 0, 0,
            0, 1, 0
        );
    
        glBegin(GL_LINES);
     /*X*/
            glColor3f(1,0,0);
            glVertex3f(0, 0, 0);
            glVertex3f(100, 0, 0);
    /*Y*/ 
            glColor3f(0,1,0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 100, 0);
    /*Z*/
            glColor3f(0,0,1);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, 100);
        glEnd();
 
    /*
     * Kreira se kocka i primenjuje se skaliranje.
     */
   stage();
    
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

void on_reshape(int width, int height)
{
    /* Podesava se viewport. */
    glViewport(0, 0, width, height);
 
    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)width / height, 1, 100);
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
