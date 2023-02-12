#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
//#include <cstdlib>
//if you got error in exit() by compiler then does not incluede stdlib.h because //exit() is also defined in glut.h file.

float angle=0.0,deltaAngle = 0.0,ratio;
float x=0.0f,y=0.0,z=0.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
float deltadistance = 0,h,w;
//int font=(int)GLUT_BITMAP_8_BY_13;
static GLint walls_display_list;
int bitmapHeight=13;

int frame,time,timebase=0;
char s[30];

void initWindow();
 
 
void changeSize(int w1, int h1)
 {

 // Prevent a divide by zero, when window is too short
 // (you cant make a window of zero width).
 if(h1 == 0)
  h1 = 1;

 w = w1;
 h = h1;
 ratio = 1.0f * w / h;
 // Reset the coordinate system before modifying
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 
 // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
glClearColor (0.15,0.1,0.13,0 );
  gluPerspective( /* field of view in degree */ 100.0,
  /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 70.0);
 
  gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,30) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);   
 }


 

 
void initScene() {


 

 


}


 
 
 

/*void renderBitmapString(float x, float y, void *font,char *string)
{

  char *c;
  // set position to start drawing fonts
  glRasterPos2f(x, y);
  // loop all the characters in the string
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}*/



void mainscene(){ 

    glBegin(GL_LINES);
    glVertex2f( deltadistance/2,   -(deltadistance/2) );
    glVertex2f(deltadistance/2,   -(deltadistance*2) );
    glVertex2f( -deltadistance/2,   -(deltadistance/2) );
    glVertex2f( -deltadistance/2,   -(deltadistance*2));
    
    
    
    glVertex2f(  deltadistance/2,   -deltadistance/2 );
    glVertex2f( -deltadistance/2,  -deltadistance/2);
    glVertex2f(  deltadistance/2,  -deltadistance/2 );
    glVertex2f( lx+deltadistance/2,ly);

   
   glVertex2f(-deltadistance/2,  -deltadistance/2 );
     glVertex2f( lx-deltadistance/2,ly);
     glVertex2f(lx-deltadistance/2,ly);
       glVertex2f(lx+deltadistance/2,ly);
        
       
       
          glVertex2f( -deltadistance/2,  -(deltadistance*2) );
    glVertex2f(  deltadistance/2,  -(deltadistance*2) );
 glVertex2f(  deltadistance/2,   -(deltadistance*2));
 
  
   glVertex2f( lx+deltadistance/2,-ly);

   
        glVertex2f( -deltadistance/2,   -(deltadistance*2) );
     glVertex2f( lx-deltadistance/2,-ly);
     glVertex2f(lx-deltadistance/2,-ly);
       glVertex2f(lx+deltadistance/2,-ly);
        
        glVertex2f(lx-deltadistance/2,ly);
    glVertex2f(lx-deltadistance/2,-ly);
    
        glVertex2f(lx+deltadistance/2,ly);
    glVertex2f(lx+deltadistance/2,-ly);
       
 glEnd();}
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 0.0f);
 mainscene();
 
 glutSwapBuffers();
 glutPostRedisplay();
 glFlush();
  
}

void processNormalKeys(unsigned char key, int x, int y) {

 if (key == 27)
  exit(0);
}

void pressKey(int key, int x, int y) {

 switch (key) {
  case GLUT_KEY_LEFT : lx=lx-0.1;break;
  case GLUT_KEY_RIGHT : lx=lx+0.1;break;
  case GLUT_KEY_UP : ly=ly+0.1;deltadistance+=0.1; break;
  case GLUT_KEY_DOWN :ly=ly-0.1;deltadistance-=0.1; break;
 
 
 
 }

}

void releaseKey(int key, int x, int y) {

 switch (key) {
  case GLUT_KEY_LEFT :  
     
       break;
  case GLUT_KEY_RIGHT :  
 
       break;
  case GLUT_KEY_UP : 
    
       break;
  case GLUT_KEY_DOWN :  
     
       break;
 }
}

void initWindow() {
 //glutIgnoreKeyRepeat(1);
 glutKeyboardFunc(processNormalKeys);
 glutSpecialFunc(pressKey);
 //glutSpecialUpFunc(releaseKey);
 glutDisplayFunc(renderScene);
// glutIdleFunc(renderScene);
 glutReshapeFunc(changeSize);
 initScene();

}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(640,360);
 glutCreateWindow("ktech ImageResonatorSystem");

 // register all callbacks
 initWindow();

 glutMainLoop();

 return(0);
}
