#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>
#include<GL/glut.h>
#include <GL/freeglut.h>
#include"./SOIL.h"

  /* Deklaracije callback funkcija. */
void on_keyboard(unsigned char key, int x, int y);
void on_keyboards(int key, int x, int y);
void on_reshape(int width, int height);
void on_display(void);
void on_timer(int id);
void material_and_light();
void generate_polygon();
void define_textures();
void dealloc();

  /* Parametar animacije, fleg koji odredjuje da li je animacija u toku ili nije */
#define TIMER_ID 0
#define TIMER_INTERVAL 10

/*Parametar za kretanje kvadra.*/
float animation_parameter = 0;
int animation_ongoing = 0;

/*Parametri za pomeranje kamere.*/
float cam1=0, cam2=0;

int n, m, p, q, indikator=0, up_key=0, key_pre=0, ind_pre=0, count_3=0, count_4=0, 
    count_1=0, count_2=0, level=0;
static int **mat;
float curr_i=8, curr_j=2;
float rot=0;
float r_x=0, r_z=0, r_y=0;
float lx=0, lz=-1;
float x=0, z=5; 
float angle;

GLuint snow, end;

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
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    glutSpecialFunc(on_keyboards);
 
    //glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    
    /* OpenGL inicijalizacija. */
    glClearColor(0.95, 0.4, 0.2, 0);
    glEnable(GL_DEPTH_TEST);
 
    /* Postavljaju se svojstva prvog svetla */
    glEnable(GL_LIGHT0);

    glEnable(GL_NORMALIZE);
    
    define_textures();
    
    generate_polygon();
    
    /* Program ulazi u glavnu petlju. */
    glutMainLoop();
    
    return 0;
}
 
void on_keyboards(int key, int x, int y){
 switch (key){
  case GLUT_KEY_LEFT:
      if(animation_ongoing){
          
          count_3++;
          count_1=0;
          count_2=0;
          count_4=0;
          key_pre=up_key;
          ind_pre=indikator;
          up_key=3;
          if(indikator==0){   //uspravno
              indikator=1;
          }//vodoravno
          else if(indikator==1 && ind_pre==0){
              if(up_key==1 || up_key==2){
                indikator=0;
                curr_j--;
                count_3=0;
              }
              else{
                indikator=1;
            }
          }
           else if(indikator==1 && ind_pre==1){
               //if(count_3>1)
               count_3--;
               if((key_pre==4 || key_pre==3) && count_3==1){
                   indikator=0;
                   curr_j--;
                   count_3=0;
               }
               else{
                   indikator=1;
               }
           }
          curr_j-=1;
    
        glutPostRedisplay();
    }
    break;
   case GLUT_KEY_RIGHT:
          if(animation_ongoing){
              count_1=0;
              count_2=0;
              count_3=0;
              count_4++;
          key_pre=up_key;
          ind_pre=indikator;
          up_key=4;        
          if(indikator==0){
              indikator=1;
              curr_j++;
          }
          else if(indikator==1 && ind_pre==0){
              if(up_key==1 || up_key==2){
                indikator=0;
                count_4=0;
              }
              else{
                indikator=1;
              }
          }
          else if(indikator==1 && ind_pre==1){
              count_4--;
            if((key_pre==3 || key_pre==4) && count_4==1){
                indikator=0;
            count_4=0;
            }
            else{
                indikator=1;
            }
          }
          curr_j+=1;
          glutPostRedisplay();
    }
    break;
 case GLUT_KEY_UP:
          if(animation_ongoing){
              count_2=0;
              count_3=0;
              count_4=0;
              count_1++;
          key_pre=up_key;
          ind_pre=indikator;
              up_key=1;
          if(indikator==0){
              indikator=1;
              printf("5\n");
          }
          else if(indikator==1 && ind_pre==0){
              indikator=0;
            
          }
          else if(indikator==1 && ind_pre==1){
              if(count_1>1)
              count_1--;
              if((key_pre==up_key || key_pre==2 || key_pre==3  || key_pre==4) && count_1==1){
                   indikator=0;
                   curr_i--;
                   if(count_1!=0)
                    count_1=0;
              }
               else{
              indikator=1;
               printf("3\n");
               }
          }
          curr_i-=1;          
          glutPostRedisplay();
    }
    break;
 case GLUT_KEY_DOWN:
          if(animation_ongoing){
              count_1=0;
              count_3=0;
              count_4=0;
              count_2++;
          key_pre=up_key;
          ind_pre=indikator;
              up_key=2;
          if(indikator==0){
              indikator=1;
              curr_i++;
 printf("4\n");
          }
          else if(indikator==1 && ind_pre==0){
              indikator=0;
          }
          else if(indikator==1 && ind_pre==1){
              if(count_2>1)
              count_2--;
              if((key_pre==1 || key_pre==up_key || key_pre==3 || key_pre==4) && count_2==1){
                indikator=0;
                if(count_2!=0)
                 count_2=0;
              }
              else{
                indikator=1;
                curr_i++;  
            }
          }
          curr_i+=1;
          glutPostRedisplay();
    }
    break;
  }
}

void on_keyboard(unsigned char key, int x, int y)
{
    float c = 0.1;
   
    
    switch (key) {
    case 27:  /* Zavrsava se program. */
      exit(0);
        break;
    case 'g':
    case 'G':
        if (!animation_ongoing) {
            animation_ongoing = 1;
            glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
        break;                    
    } 
}
 

    /*    sajt odakle je preuzeta nijansa plave boje
        https://community.khronos.org/t/color-tables/22518
        CadetBlue = color red 0.372549 green 0.623529 blue 0.623529
    */

void generate_polygon(){

 FILE *dat;
 if(level==0){
    dat = fopen("lvl1.txt", "r");
 }
 else if(level==1){
    dat = fopen("lvl2.txt", "r");
    curr_i=7;
    curr_j=3;
 }
 else if(level==2){
     dat = fopen("lvl3.txt", "r");
 }

 if(dat==NULL)
  exit(0);
 fscanf(dat, "%d%d", &n, &m);
 fscanf(dat, "%d%d", &p, &q);

 mat = malloc(n*sizeof(int*));
 if(mat==NULL)
  exit(0);

 for(int r=0;r<n;r++){
  mat[r]=malloc(m*sizeof(int));
  if(mat[r]==NULL)
   exit(0);
 }

 for(int i=0; i<n; i++)
   for(int j=0; j<m; j++)
     fscanf(dat, "%d", &mat[i][j]);
   
 fclose(dat); 
}

void on_display(void)
{
    /* Brise se prethodni sadrzaj prozora. */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    /* Inicijalizuje se matrica transformacije. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-0.4, 0.9, 1.5, 0, 0, 0, 0, 1, 0);
        material_and_light();
    
    gluLookAt(
            8, 8, 14,
            x+lx, 1, z+lz,
            0, 1, 0
        );
    
    if(level<=2){
        glBegin(GL_LINES);
     /*X-red*/
            glColor3f(1,0,0);
            glVertex3f(0, 0, 0);
            glVertex3f(100, 0, 0);
    /*Y-green*/ 
            glColor3f(0,1,0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 100, 0);
    /*Z-blue*/
            glColor3f(0,0,1);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, 100);
        glEnd();

        /* Omogucavamo teksture */
        glEnable(GL_TEXTURE_2D);
    
        
       glTranslatef(10, -9, -10);
        glRotatef(-40, 0,1,0);
        glRotatef(40, 1,0,0);
        glBindTexture(GL_TEXTURE_2D, snow);
        glBegin(GL_QUADS);
            glNormal3f(1, -1, 1);

            glTexCoord2f(0, 0);
            glVertex3f(-400.0, 0, 400.0);

            glTexCoord2f(4, 0);
            glVertex3f(400.0, 0, 400.0);

            glTexCoord2f(4, 4);
            glVertex3f(400.0, 0, -400.0);

            glTexCoord2f(0, 4);
            glVertex3f(-400.0, 0, -400.0);
        glEnd();
        glRotatef(-40, 1,0,0);
        glRotatef(40, 0,1,0);
        glTranslatef(-10, 9, 10);
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);
     int ind=0;   
   
     /*0-padanje, 1-kocka, 4-cilj*/
 for(int i=0; i<n; i++){
   for(int j=0; j<m; j++){
       ind++;
    if(mat[i][j]==1){
      glPushMatrix();
    	glTranslatef(j, 0, i);
        if(ind%2==1)
        glColor3f(0.372549, 0.62329, 0.623529);
        else
        glColor3f(0.1, 0.8, 0.4);    
       glutSolidCube(1);
      glPopMatrix();
    }
   else if(mat[i][j]==4){
      glPushMatrix();
    	glTranslatef(j, 0, i);
    	glColor3f(0, 0, 0);
       glutSolidCube(1);
      glPopMatrix();
      if(curr_i==i && curr_j==j){
           printf("SUCCESS!!!\n");
           level++;
           dealloc();
           // exit(0);
           generate_polygon();
      }
    }
    else if(mat[i][j]==0){
      /*  if(curr_i==i && curr_j==j){
            printf("padanje");
            exit(0);*/
      continue;
    }
    
    else 
      continue;
   }
 }
 
 /*uspravan kvadar*/
    if(indikator==0){
        if(up_key==1 || up_key==2){
            glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(curr_j, 1.5, curr_i);
            glScalef(1, 2, 1);
            glutSolidCube(1);
            glPopMatrix();
     }
      else{ //crtamo uspravan kvadar
        glPushMatrix();
     	glColor3f(1, 0, 0);
     	glTranslatef(curr_j, 1.5, curr_i);
     	glScalef(1, 2, 1);
     	glutSolidCube(1);
     glPopMatrix();
      }
    }
    else if(indikator==1){
        if((up_key==1 || up_key==2) && ind_pre==1 && (key_pre==3 || key_pre==4)){
            glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(curr_j-0.5, 1, curr_i);
            glScalef(2, 1, 1);
            glutSolidCube(1);
            glPopMatrix();
        }
        else if((ind_pre==1 && up_key==4) || (ind_pre==1 && up_key==3) || 
             (indikator==1 && up_key==1) || (indikator==1 && up_key==2)){
            glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(curr_j, 1, curr_i-0.5);
            glScalef(1, 1, 2);
            glutSolidCube(1);
            glPopMatrix();
         }
         else{ //vodoravno po x
            glPushMatrix();
            glColor3f(1, 0, 0);
            glTranslatef(curr_j-0.5, 1, curr_i);
            glScalef(2, 1, 1);
            glutSolidCube(1);
            glPopMatrix();
        }
    }

    
    }
    else{  //kraj
         glLoadIdentity();
        gluLookAt(-1, 0, 0, 
                   0, 0, 0, 
                   0, 1, 0);
        
//         glTranslatef(0,-50,0);
//         glScalef(0.8,1,1.5);
//         glEnable(GL_TEXTURE_2D);
//         glBindTexture(GL_TEXTURE_2D, end);
//         glBegin(GL_QUADS);
//             glNormal3f(1, -1, 1);
// 
//             glTexCoord2f(0, 0);
//             glVertex3f(400, 0, -400);
//  
//             glTexCoord2f(1, 0);
//             glVertex3f(400, 0, 400);
//    
//             glTexCoord2f(1, 1);
// 
//             glTexCoord2f(0, 1);
//             glVertex3f(400, 100, -400);
//         glEnd();
//         glDisable(GL_TEXTURE_2D);
//         glEnable(GL_COLOR_MATERIAL);
    }
    /* Nova slika se salje na ekran. */
    glutSwapBuffers();
}
 
void on_timer(int id)
{
    animation_parameter += 1;
 
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
    gluPerspective(70, (float)width / height, 1, 100);
}


void dealloc(){
for(int i=0; i<n; i++)
    free(mat[i]);

  free(mat);
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

void define_textures(){
    
      /* Inicijalizuje se tekstura */
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    /* Pozadina */
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

        snow = SOIL_load_OGL_texture("./snow.png", 
                                SOIL_LOAD_AUTO, 
                                SOIL_CREATE_NEW_ID, 
                                SOIL_FLAG_INVERT_Y);
    /* U slucaju da ucitavanje strukture nije uspelo, ispisati vrstu greske i prekinuti program */
     if(snow == 0)
         exit(0);
     glBindTexture(GL_TEXTURE_2D, snow);
     glTexParameteri(GL_TEXTURE_2D,
                     GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D,
                     GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);
}

