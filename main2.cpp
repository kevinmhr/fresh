#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
//#include <cstdlib>
//if you got error in exit() by compiler then does not incluede stdlib.h because //exit() is also defined in glut.h file.

float angle=0.0,deltaAngle = 0.0,ratio;
float x=0.0f,y=1.75f,z=5.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int font=(int)GLUT_BITMAP_8_BY_13;
static GLint walls_display_list;
int bitmapHeight=13;

int frame,time,timebase=0;
char s[30];

void initWindow();
void light()
{

 GLfloat mat_ambient[] = { 1,  5,  5,  0 };
GLfloat mat_shininess[] = { 100};
GLfloat light_position[] = {200, 200, 100 , 100  };
   
//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
 

glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
 //glEnable(GL_DEPTH_TEST);
  
 


 
}
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
 // Set the clipping volume
 gluPerspective(80,ratio,0.1,1000);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt(x , y , z,
       x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);


 }


void wall(){
//glutSolidCone(2 ,2,2 ,1);  
    //gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
   light();
  glPushMatrix();
 glRotatef(  -90, 1,  0,0);
glTranslatef(0, 0,2);

// Draw ground
 glColor3f(0.7f, 0.7f, 0.7f);
 
 glBegin(GL_QUADS);
  glVertex3f( -1.0f,  1.0f,  -1.0f);
  glVertex3f(  1.0f,  1.0f,   -1.0f);
  glVertex3f( 1.0f, -1.0f,  -1.0f);
  glVertex3f( -1.0f, -1.0f, -1.0f);
 glEnd();
 glColor3f(0.0f, 0.9f, 0.4f);
 glBegin(GL_QUADS);
  glVertex3f( -1.5f,  1.5f,  -1.2f);
  glVertex3f(  1.5f,  1.5f,   -1.2f);
  glVertex3f( 1.5f, -1.5f,  -1.2f);
  glVertex3f( -1.5f, -1.5f, -1.2f);
 glEnd();
    glColor3f(0.0f, 0.9f, 0.9f);
   glBegin(GL_QUADS);
  glVertex3f( -1.0f,  1.0f,   2.2f);
  glVertex3f(  1.0f,  1.0f,    2.2f);
  glVertex3f( 1.0f,  -1.0f,   2.2f);
  glVertex3f( -1.0f,  -1.0f,  2.2f);
 glEnd();  


 glColor3f(0.9f, 0.9f, 0.9f);
 glBegin(GL_QUADS);
  glVertex3f( -0.3f,  0.3f,  -1.2f);
  glVertex3f(  0.3f,  0.3f,   -1.2f);
  glVertex3f( 0.3f, -0.3f,  -1.2f);
  glVertex3f( -0.3f, -0.3f, -1.2f);
 glEnd();
 glColor3f(0.0f, 0.0f, 0.8f);
 glBegin(GL_QUADS);
  glVertex3f( -2.3f,  2.3f,  -1.2f);
  glVertex3f(  2.3f,  2.3f,   -1.2f);
  glVertex3f( 2.3f, -2.3f,  -1.2f);
  glVertex3f( -2.3f, -2.3f, -1.2f);
 glEnd();
 glBegin(GL_QUADS);
  glVertex3f( -2.3f,  2.3f,  -1.3f);
  glVertex3f(  2.3f,  2.3f,   -1.3f);
  glVertex3f( 2.3f, -2.3f,  -1.3f);
  glVertex3f( -2.3f, -2.3f, -1.3f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -2.3f,  2.3f,   2.3f);
  glVertex3f(  2.3f,  2.3f,    2.3f);
  glVertex3f( 2.3f, -2.3f,   2.3f);
  glVertex3f( -2.3f, -2.3f,  2.3f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -2.3f,  2.3f,   2.2f);
  glVertex3f(  2.3f,  2.3f,    2.2f);
  glVertex3f( 2.3f, -2.3f,   2.2f);
  glVertex3f( -2.3f, -2.3f,  2.2f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -2.3f,  -2.3f,   -1.3f);
  glVertex3f(  -2.3f,  -2.3f,    2.3f);
  glVertex3f( 2.3f, -2.3f,    2.3f);
  glVertex3f(  2.3f, -2.3f,  -1.3f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f(  -2.3f,   2.3f,   -1.3f);
  glVertex3f(  -2.3f,   2.3f,    2.3f);
  glVertex3f( 2.3f,  2.3f,    2.3f);
  glVertex3f(  2.3f,  2.3f,  -1.3f);
 glEnd();

glColor3f(0.6f, 0.3f, 0.1f);
glBegin(GL_QUADS);
  glVertex3f( -8.3f,  8.3f,  -1.8f);
  glVertex3f(  8.3f,  8.3f,   -1.8f);
  glVertex3f( 8.3f, -8.3f,  -1.8f);
  glVertex3f( -8.3f, -8.3f, -1.8f);


 glEnd();
 glPushMatrix();
 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL );
glBegin(GL_QUADS);
  glVertex3f( -4.3f,  4.3f,  -1.8f);
  glVertex3f(  4.3f,  4.3f,   -1.8f);
  glVertex3f( 4.3f, -4.3f,  -1.8f);
  glVertex3f( -4.3f, -4.3f, -1.8f);


 glEnd();

glPopMatrix();
}
void pyr(void){
    

glBegin(GL_TRIANGLES);
glColor3f(1,1,1);
// Lower left vertex
glVertex3f( 0.4f,  0.4f, 0.0f);
 glVertex3f( 0.4f,  -0.4f, 0.0f);
 glVertex3f( -0.4f,  -0.4f, 0.0f);

 glVertex3f( -0.4f,  -0.4f, 0.0f);
glVertex3f( -0.4f,  0.4f, 0.0f);
 glVertex3f( 0.4f,   0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, 0.6f);
  glVertex3f( 0.4f,   0.4f, 0.0f);
glVertex3f( -0.4f,   0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, 0.6f);
glVertex3f( -0.4f,   0.4f, 0.0f);
  glVertex3f( -0.4f,   -0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, 0.6f);
glVertex3f( -0.4f,   -0.4f, 0.0f);
glVertex3f(  0.4f,   -0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, 0.6f);
glVertex3f( -0.4f,   -0.4f, 0.0f);
glVertex3f(  0.4f,   0.4f, 0.0f);

//bottom of diamond
glVertex3f( 0.4f,  0.4f, 0.0f);
 glVertex3f( 0.4f,  -0.4f, 0.0f);
 glVertex3f( -0.4f,  -0.4f, 0.0f);

 glVertex3f( -0.4f,  -0.4f, 0.0f);
glVertex3f( -0.4f,  0.4f, 0.0f);
 glVertex3f( 0.4f,   0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, -0.6f);
  glVertex3f( 0.4f,   0.4f, 0.0f);
glVertex3f( -0.4f,   0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, -0.6f);
glVertex3f( -0.4f,   0.4f, 0.0f);
  glVertex3f( -0.4f,   -0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, -0.6f);
glVertex3f( -0.4f,   -0.4f, 0.0f);
glVertex3f(  0.4f,   -0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, -0.6f);
glVertex3f( -0.4f,   -0.4f, 0.0f);
glVertex3f(  0.4f,   0.4f, 0.0f);






glEnd();
 
     
    }

void floors(){
     for( int l = -2;  l < 2; l++)
  for(int  m=-2; m < 2; m++)
  for (int  n=0;n<5;n++) {
   glPushMatrix();
   glTranslatef(l*20.0,n*25,m * 20.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL );
 glColor3f(1.2f, 0.5f, 0.5f);
glBegin(GL_QUADS);
  glVertex3f( -4.3f,  4.3f,   50.3f);
  glVertex3f(  4.3f,  4.3f,    50.3f);
  glVertex3f( 4.3f, -4.3f,   50.3f);
  glVertex3f( -4.3f, -4.3f,  50.3f);


 glEnd();
 
   glPopMatrix();
     
     
     }


}
void drawsome() {


 glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body 
 glTranslatef(0.0f ,0.75f, 0.0f);
 glutSolidSphere(0.75f,20,20);


// Draw Head
 glTranslatef(0.0f, 1.0f, 0.0f);
 glutSolidSphere(0.25f,20,20);

// Draw Eyes
 glPushMatrix();
 glColor3f(0.0f,0.0f,0.0f);
 glTranslatef(0.05f, 0.10f, 0.18f);
 glutSolidSphere(0.05f,10,10);
 glTranslatef(-0.1f, 0.0f, 0.0f);
 glutSolidSphere(0.05f,10,10);
 glPopMatrix();

// Draw Nose
 glColor3f(1.0f, 0.5f , 0.5f);
 glRotatef(0.0f,1.0f, 0.0f, 0.0f);
 glutSolidCone(20 ,20.0f,100,2);
}



GLuint createDL() {



 GLuint wallsDL;

 // Create the id for the list
 wallsDL = glGenLists(2);

 glNewList(wallsDL+1,GL_COMPILE);
  //drawSnowMan();
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE );
 pyr();
  glColor3f(0.4f, 0.1f , 0.1f);
  
  	 glutSolidCone(20  ,10.0f,20,2);
       glColor3f(1.4f, 1.1f , 1.1f);
        glutSolidSphere(0.40f,20,10);
 
   wall();
 
 glEndList();
 // start list
 glNewList(wallsDL,GL_COMPILE);
 
 // call the function that contains the rendering commands
 for(int i = -2; i < 2; i++)
  for(int j=-2; j < 2; j++)
  for (int k=-3;k<3;k++) {
   glPushMatrix();
   glTranslatef(i*10.0,k*10,j * 10.0);
  
   glCallList(wallsDL+1);
   glPopMatrix();

  }

 // endList
 glEndList();

 return(wallsDL);







}

void initScene() {

 glEnable(GL_DEPTH_TEST);
 walls_display_list = createDL();

}

void orientMe(float ang) {


 lx = sin(ang);
 lz = -cos(ang);
 glLoadIdentity();
 gluLookAt(x, y, z,
       x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);

  





}


void moveMeFlat(int i) {
 x = x + i*(lx)*0.1;
 z = z + i*(lz)*0.1;
 glLoadIdentity();
 gluLookAt(x, y, z,
       x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);



}

void setOrthographicProjection() {

 // switch to projection mode
 glMatrixMode(GL_PROJECTION);
 // save previous matrix which contains the
 //settings for the perspective projection
 glPushMatrix();
 // reset matrix
 glLoadIdentity();
 // set a 2D orthographic projection
 gluOrtho2D(0, w, 0, h);
 // invert the y axis, down is positive
 glScalef(1, -1, 1);
 // mover the origin from the bottom left corner
 // to the upper left corner
 glTranslatef(0, -h, 0);
 glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() {
 // set the current matrix to GL_PROJECTION
 glMatrixMode(GL_PROJECTION);
 // restore previous settings
 glPopMatrix();
 // get back to GL_MODELVIEW matrix
 glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font,char *string)
{

  char *c;
  // set position to start drawing fonts
  glRasterPos2f(x, y);
  // loop all the characters in the string
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}




void renderScene(void) {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 if (deltaMove)
  moveMeFlat(deltaMove);
 if (deltaAngle) {
  angle += deltaAngle;
  orientMe(angle);
 

 
 
 
 }
// Draw ground

floors();

 

// Draw 36 Snow Men

  glCallList(walls_display_list);
 
 frame++;
 time=glutGet(GLUT_ELAPSED_TIME);
 if (time - timebase > 1000) {
  sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
  timebase = time;  
  frame = 0;
 }
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL );
		//  glutPostRedisplay();
 glColor3f(0.0f,1.0f,1.0f);
 setOrthographicProjection();
 glPushMatrix();
 glLoadIdentity();
 renderBitmapString(30,15,(void *)font,"k");
 renderBitmapString(30,35,(void *)font,s);
 renderBitmapString(30,55,(void *)font,"Esc - Quit");
 glPopMatrix();
 resetPerspectiveProjection();
 
 glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {

 if (key == 27)
  //exit(0);
 
y=y++;


}

void pressKey(int key, int x, int y) {

 switch (key) {
  case GLUT_KEY_LEFT : deltaAngle = -0.01f;break;
  case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break;
  case GLUT_KEY_UP : deltaMove = 1;break;
  case GLUT_KEY_DOWN : deltaMove = -1;break;
 
 
 
 }

}

void releaseKey(int key, int x, int y) {

 switch (key) {
  case GLUT_KEY_LEFT : if (deltaAngle < 0.0f)
        deltaAngle = 0.0f;
       break;
  case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
        deltaAngle = 0.0f;
       break;
  case GLUT_KEY_UP : if (deltaMove > 0)
        deltaMove = 0;
       break;
  case GLUT_KEY_DOWN : if (deltaMove < 0)
        deltaMove = 0;
       break;
 }
}

void initWindow() {
 glutIgnoreKeyRepeat(1);
 glutKeyboardFunc(processNormalKeys);
 glutSpecialFunc(pressKey);
 glutSpecialUpFunc(releaseKey);
 glutDisplayFunc(renderScene);
 glutIdleFunc(renderScene);
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
