#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdarg.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<string.h>
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

    /* Parametar animacije, fleg koji odredjuje da li je animacija u toku ili nije.*/
#define TIMER_ID 0
#define TIMER_INTERVAL 10

    /*Parametar za kretanje kvadra.*/
int animation_ongoing = 0;

    /*Parametri za iscrtavanje i kretanje kvadra.*/
int n, m, p, q, indikator=0, up_key=0, key_pre=0, ind_pre=0, count_3=0, count_4=0, 
    count_1=0, count_2=0, count_all=0, level=0;
int **mat;
    /*Pocetna pozicija kvadra.*/
float curr_i=8, curr_j=2;
    /*Ugao rotacije za prikaz pobede.*/ 
float rotation;

    /*Stringovna reprezentacija broja poteza.*/
char buffer[20];

    /*Tekstura*/
GLuint snow;

int main(int argc, char **argv)
{
    /* Inicijalizuje se GLUT. */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
 
    /* Kreira se prozor. */
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("kvadar_do_kvadrata");
 
    /* Poziv callback funkcija. */
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    glutSpecialFunc(on_keyboards);
    glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    
    /* OpenGL inicijalizacija. */
    glClearColor(0.95, 0.4, 0.2, 0); /*prvobitna boja pozadine, kasnije stavljena tekstura*/
    glEnable(GL_DEPTH_TEST);
 
    /* Postavljaju se svojstva prvog svetla */
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    
    /*Definisemo teksturu.*/
    define_textures();
    
    /*Generisemo poligon na osnovu nivoa(level).*/
    generate_polygon();
    
    /* Program ulazi u glavnu petlju. */
    glutMainLoop();
    
    return 0;
}
 
void on_keyboards(int key, int x, int y){
 switch (key){
  case GLUT_KEY_LEFT:
      if(animation_ongoing){
	  count_all++;
          count_3++;
          count_1=0;
          count_2=0;
          count_4=0;
          key_pre=up_key;
          ind_pre=indikator;
          up_key=3;
            if(indikator==0){   /*uspravno*/
                indikator=1;  /*vodoravno*/
            }
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
             count_3--;
               if((key_pre==3 || key_pre==4) && count_3==1){
                   indikator=0;
                   curr_j--;
                   count_3=0;
               }/*
               else{
                   if(key_pre==4){
                       indikator=0;
                       curr_j--;
                   }*/
               else{
                   indikator=1;
               }
            }
          
        if((mat[(int)curr_i][(int)curr_j]==0 && indikator==0) || 
           (mat[(int)curr_i][(int)curr_j-2]==0 && mat[(int)curr_i][(int)curr_j-1]==1 && ind_pre==0) || 
            mat[(int)curr_i][(int)curr_j-1]==0){
                printf("You steped over the edge -> Game over!\n");
                exit(0);
        }
          curr_j-=1;
        glutPostRedisplay();
    }
    break;
   case GLUT_KEY_RIGHT:
      if(animation_ongoing){
          count_all++;
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
                if((key_pre==4 || key_pre==3) && count_4==1){
                    indikator=0;
                    count_4=0;
                }/*
                else{ if(key_pre==3) 
                        indikator=0;*/
                else
                    indikator=1;
          }
          
        if((mat[(int)curr_i][(int)curr_j]==0 && indikator==0) || 
           (mat[(int)curr_i][(int)curr_j+1]==0) || 
           (mat[(int)curr_i-1][(int)curr_j+1]==0 && mat[(int)curr_i][(int)curr_j+1]==1 && ind_pre==1 && indikator==1)){
                printf("You steped over the edge -> Game over!\n");
                exit(0);
        }
          curr_j+=1;
        glutPostRedisplay();
    }
    break;
 case GLUT_KEY_UP:
    if(animation_ongoing){
        count_all++;
        count_2=0;
        count_3=0;
        count_4=0;
        count_1++;
        key_pre=up_key;
        ind_pre=indikator;
        up_key=1;
          if(indikator==0){
              indikator=1;
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
               }
          }

          if((mat[(int)curr_i][(int)curr_j]==0 && indikator==0) || 
              mat[(int)curr_i-1][(int)curr_j]==0 || 
             (mat[(int)curr_i-1][(int)curr_j]==1 && mat[(int)curr_i-2][(int)curr_j]==0 && indikator==1)){
                printf("You steped over the edge -> Game over!\n");
                exit(0);
        }
          curr_i-=1;      
        glutPostRedisplay();
    }
    break;
 case GLUT_KEY_DOWN:
    if(animation_ongoing){
        count_all++;
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
          
          if((mat[(int)curr_i][(int)curr_j]==0 && indikator==0) || 
              mat[(int)curr_i+1][(int)curr_j]==0){
                printf("You steped over the edge -> Game over!\n");
                exit(0);
          }
          curr_i+=1;
          glutPostRedisplay();
    }
    break;
  }
}

void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:  /* Zavrsava se program. */
      exit(0);
        break;
    case 'g': /*Pocinjemo igricu.*/
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
        dat = fopen("./Level/lvl1.txt", "r");
    }
    else if(level==1){
        dat = fopen("./Level/lvl2.txt", "r");
        curr_i=6; /*Inicijalna pozicija kvadra.*/
        curr_j=12;
    }
    else if(level==2){
        dat = fopen("./Level/lvl3.txt", "r");
        curr_i=8; /*Inicijalna pozicija kvadra.*/
        curr_j=2;
    }
 
    if(dat==NULL){
        printf("Datoteka nije ucitana!\n"); 
        exit(0);
    }  
 
    fscanf(dat, "%d%d", &n, &m); /*Ucitavamo broj kolona i vrsta matrice.*/
    fscanf(dat, "%d%d", &p, &q); /*Koordinate kraja.*/

    mat = malloc(n*sizeof(int*));
 
    if(mat==NULL){
        printf("Neuspesna alokacija!\n");
        exit(0);
    }

    for(int r=0;r<n;r++){
        mat[r]=malloc(m*sizeof(int));
        
        if(mat[r]==NULL){
            printf("Neuspesna alokacija!\n");
            exit(0);
        }
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
            0, 1, 4,  //TODO
                      /*check umesto 3 je bilo 4*/
            0, 1, 0
        );
    if(level<=2){
        
    /*  glBegin(GL_LINES);
    // X-red
            glColor3f(1,0,0);
            glVertex3f(0, 0, 0);
            glVertex3f(100, 0, 0);
    //Y-green 
            glColor3f(0,1,0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 100, 0);
    //Z-blue
            glColor3f(0,0,1);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, 100);
        glEnd();
      */
        
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

     
     int ind=0; /*Za kockice poligona, u odnosu na ind se postavlja plava ili zelena boja.*/   
   
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
                if(level==2)
                    glColor3f(1, 0, 0);
                else
                    glColor3f(0, 0, 0);
       
                glutSolidCube(1);
                glPopMatrix();
      
                if(curr_i==i && curr_j==j && indikator==0){
                    printf("SUCCESS!!!\n");
                    if(level<=2){
                        level++;
                        dealloc();
                    }
                    if(level<=2){
                        generate_polygon();
                    }
                }
            }
        }
    }
    
    /*Uspravan kvadar.*/
    if(indikator==0){
        if(up_key==1 || up_key==2){
            glPushMatrix();
                glColor3f(1, 0, 0);
                glTranslatef(curr_j, 1.5, curr_i);
                glScalef(1, 2, 1);
                glutSolidCube(1);
            glPopMatrix();
        }
        else{ 
            glPushMatrix();
                glColor3f(1, 0, 0);
                glTranslatef(curr_j, 1.5, curr_i);
                glScalef(1, 2, 1);
                glutSolidCube(1);
            glPopMatrix();
        }
    }
    /*Vodoravan kvadar u odnosu na z i x osu.*/
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
         else{ 
            glPushMatrix();
                glColor3f(1, 0, 0);
                glTranslatef(curr_j-0.5, 1, curr_i);
                glScalef(2, 1, 1);
                glutSolidCube(1);
            glPopMatrix();
        }
    }

    /*Tekst-broj pocetak, poruka i broj nivoa.*/
    glPopMatrix();
        glColor3f(0.8, 0.8, 0);
        glPushAttrib(GL_ENABLE_BIT);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
            glLoadIdentity();
            gluOrtho2D(0, 300, 0, 300);
            glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        
        glLoadIdentity();

    int number;

    /*count_all se uvecava svaki put kada se pritisne neka strelica na tastaturi*/
    number=count_all;

    sprintf(buffer, "Moves: %d", number);

    if(level==0){
        glRasterPos2i(33, 290);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "Press g/G to start!");
        glRasterPos2i(38, 280);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "Good luck :)");
        glRasterPos2i(250, 280);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "Level: 1/3");
	glRasterPos2i(110, 18);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     buffer);
    }
    else if(level==1){
        glRasterPos2i(38, 280);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "Good luck :)");
        glRasterPos2i(260, 280);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "Level: 2/3");
	glRasterPos2i(110, 18);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     buffer);
    }
    else if(level==2){
        glRasterPos2i(38, 280);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "Good luck :)");
        glRasterPos2i(260, 280);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "Level: 3/3");
	glRasterPos2i(110, 18);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     buffer);
    }
  
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glPopAttrib();
 }
    /*Ako smo stigli do crvene kocke(kraja).*/
    else{
    /*glBegin(GL_LINES);
    // X-red
            glColor3f(1,0,0);
            glVertex3f(0, 0, 0);
            glVertex3f(100, 0, 0);
    //Y-green 
            glColor3f(0,1,0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 100, 0);
    //Z-blue
            glColor3f(0,0,1);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, 100);
      glEnd();*/
         
    glClearColor(0, 0, 0, 0);
    
    glPushMatrix();
        glColor3f(1, 0, 0);
        glTranslatef(20, -20, 4);
        glRotatef(rotation, 0, 1, 1);
        glutSolidCube(4);
    glPopMatrix();
         
    glPushMatrix();
        glColor3f(1, 0, 0);
        glTranslatef(-10, -7, 0);
        glRotatef(rotation, 0, 1, 1);
        glutSolidCube(3);
    glPopMatrix();
  
    glColor3f(1, 1, 0.5);
    glPushAttrib(GL_ENABLE_BIT);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 300, 0, 300);
        glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();

        glRasterPos2i(250, 280);
        glutBitmapString(GLUT_BITMAP_HELVETICA_12,
                     "Press esc to exit...");
        
        glRasterPos2i(80, 150);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18,
                     "C O N G R A T U L A T I O N S !!!");

        glRasterPos2i(80, 100);
        glutBitmapString(GLUT_BITMAP_9_BY_15,
                     buffer);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glPopAttrib();         
	       
    }
    
    /* Nova slika se salje na ekran. */
    glutSwapBuffers();
}

void on_timer(int id)
{
    rotation+=5;
 
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

/*Dealociramo matricu.*/
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
    
      /* Inicijalizuje se tekstura.*/
    glEnable(GL_TEXTURE_2D);
    
    /* Pozadina.*/
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    snow = SOIL_load_OGL_texture("./Texture/snow.png", 
                                SOIL_LOAD_AUTO, 
                                SOIL_CREATE_NEW_ID, 
                                SOIL_FLAG_INVERT_Y);
    
     if(snow == 0){
         printf("Neuspesno ucitavanje teksture!\n");
         exit(0);
     }
     
     glBindTexture(GL_TEXTURE_2D, snow);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    /* Iskljucujemo aktivnu teksturu */
    glBindTexture(GL_TEXTURE_2D, 0);
}
