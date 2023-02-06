#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
//#include <cstdlib>
//if you got error in exit() by compiler then does not incluede stdlib.h because //exit() is also defined in glut.h file.

float angle=0.0,deltaAngle = 0.0,ratio,rotangle,rotation;
float x=0.0f,y=1.75f,z=5.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
float rotx=0.0f,roty=0.0f,rotz=0.0f;
int deltaMove = 0,h,w;
//int font=(int)GLUT_BITMAP_8_BY_13;
static GLint walls_display_list;
int bitmapHeight=13;

int frame,time,timebase=0;
char s[30];
void light();
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

 // Set the clipping volume
 gluPerspective(45,ratio,0.1,1000);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 
 }

void light(void)
{

 GLfloat mat_ambient[] = {  1,  1,  1, 1.1 };
GLfloat mat_shininess[] = {1};
GLfloat light_position[] = {1, 1,1, 60};
   
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
 

glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
 //glEnable(GL_DEPTH_TEST);
  
}
 


 void wall2(){
  
     GLfloat mat_specular[] = {  0.2,  0.1,  0.0, 1};
GLfloat mat_shininess[] = {1};
GLfloat light_position[] = {1, 1,1, 100};
   GLfloat mat_diffuse[] = {  1,  0,  0, 1.1 };
GLfloat spot_direction [] = {100,100,100,100};



glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_shininess);

glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);


glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
   
 
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

 
     
}

void wall(){
	     GLfloat mat_specular[] = {  0.9,  0.0,  1, 1.1 };
GLfloat mat_shininess[] = {50};
GLfloat light_position[] = {1, 1,1, 100};
   GLfloat mat_diffuse[] = {  0,  0,  1, 1.1 };
GLfloat spot_direction [] = {0,100,100,100};



glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_shininess);

glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);


glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
    //gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
   
 glRotatef(-90,1,0,0);
for (int o=-8;o<3;o++){
// Draw ground
  glTranslatef(0.0f, 1.0f, 0.0f);
 glutSolidSphere(0.25f,30,4);
   
    glColor3f(0.0f, 0.0f, 1.0f);
 wall2();
 glBegin(GL_QUADS);
  glVertex3f( -1.0f,  1.0f,  o );
  glVertex3f(  1.0f,  1.0f,   o );
  glVertex3f( 1.0f, -1.0f,  o );
  glVertex3f( -1.0f, -1.0f, o );
 glEnd();
 glColor3f(0.0f, 0.9f, 0.4f);
 glBegin(GL_QUADS);
  glVertex3f( -1.5f,  o,  -1.2f);
  glVertex3f(  1.5f,  o ,   -1.2f);
  glVertex3f( 1.5f, -o,  -1.2f);
  glVertex3f( -1.5f, -o, -1.2f);
 glEnd();
    glColor3f(0.0f, 0.9f, 0.9f);
   glBegin(GL_QUADS);
  glVertex3f( -1.0f,  o ,   2.2f);
  glVertex3f(  1.0f,  o ,    2.2f);
  glVertex3f( 1.0f,  -o,   2.2f);
  glVertex3f( -1.0f,  -o,  2.2f);
 glEnd();  
glColor3f(0.9f, 0.9f, 0.9f);
 glBegin(GL_QUADS);
  glVertex3f( -0.3f,  0.3f,  -1.2f);
  glVertex3f(  0.3f,  0.3f,   -1.2f);
  glVertex3f( 0.3f, -0.3f,  -1.2f);
  glVertex3f( -0.3f, -0.3f, -1.2f);
 glEnd();

 glColor3f(0.9f, 0.9f, 0.9f);
 glBegin(GL_QUADS);
  glVertex3f( -0.3f,  0.3f,  -1.2f);
  glVertex3f(  0.3f,  0.3f,   -1.2f);
  glVertex3f( 0.3f, -0.3f,  -1.2f);
  glVertex3f( -0.3f, -0.3f, -1.2f);
 glEnd();
 glColor3f(0.7f, 0.7f, 0.7f);
 glBegin(GL_QUADS);
  glVertex3f( -2.3f,  2.3f,  -1.2f);
  glVertex3f(  2.3f,  2.3f,   -1.2f);
  glVertex3f( 2.3f, -2.3f,  -1.2f);
  glVertex3f( -2.3f, -2.3f, -1.2f);
 glEnd();
  glColor3f(0.9f, 0.9f, 0.0f);
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


 

}
    
 
 
}


void pyr(void){
    light();
    for (int o=-5;o<5;o++){
    glClearColor(0.0, 0.14, 0.16 ,0.0);
 glPushMatrix();
       glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
       glColor3f(1,0.2,0);
glBegin(GL_TRIANGLES);
glColor3f(1,0.2,1);
// Lower left vertex
glVertex3f( 0.4f,  o , o);
 glVertex3f( 0.4f,  -o, o);
 glVertex3f( -0.4f,  -o, o);

 glVertex3f( -0.4f,  -o, 0.0f);
glVertex3f( -0.4f,  o, 0.0f);
 glVertex3f( 0.4f,   o , 0.0f);

 glVertex3f(  0.0f,  o, 0.6f);
  glVertex3f( 0.4f,   o, 0.0f);
glVertex3f( -0.4f,   o, 0.0f);

 glVertex3f(  0.0f,  o, 0.6f);
glVertex3f( -0.4f,   o, 0.0f);
  glVertex3f( -0.4f,   o, 0.0f);

 glVertex3f(  0.0f,   0.0f, 0.6f);
glVertex3f( -0.4f,   -0.4f, 0.0f);
glVertex3f(  0.4f,   -0.4f, 0.0f);

 glVertex3f(  0.0f,   0.0f, 0.6f);
glVertex3f( -0.4f,   -0.4f, 0.0f);
glVertex3f(  0.4f,   0.4f, 0.0f);

//bottom of diamond
glVertex3f( o,  0.4f, 0.0f);
 glVertex3f( o,  -0.4f, 0.0f);
 glVertex3f( -o,  -0.4f, 0.0f);

 glVertex3f( -o,  -o, 0.0f);
glVertex3f( -o,  o, 0.0f);
 glVertex3f( o,   o, 0.0f);
GLfloat mat_ambient[] = {  0, 0,  0.6, 0.1 };
GLfloat mat_shininess[] = {1};
GLfloat light_position[] = {1, 1,1, 60};
   
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_ambient);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
 

glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT2);
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

glColor3f(1,0,0);



glPopMatrix();

glColor3f(0.2f, 0.2f, 0.9f);
glBegin(GL_QUADS);
  glVertex3f( o,  8.3f,  -1.3f);
  glVertex3f(  o,  8.3f,   -1.3f);
  glVertex3f( o, -8.3f,  -1.3f);
  glVertex3f( o, -8.3f, -1.3f);

  glEnd();
glBegin(GL_QUADS);
  glVertex3f(  o ,  o,  -1.3f);
  glVertex3f(  o ,  o,   -1.3f);
  glVertex3f( o , o,  -1.3f);
  glVertex3f( o , o, -1.3f);
 glEnd();   

 glColor3f(0.2f, 0.2f, 0.8f);
glBegin(GL_QUADS);
  glVertex3f( -8.3f,  o ,  -1.3f);
  glVertex3f(  8.3f,  o,   -1.3f);
  glVertex3f( 8.3f, -o,  -1.3f);
  glVertex3f( -8.3f, -o, -1.3f);
 glEnd();
glColor3f(0 , 0.2f, 0.2 );
 
 
 
 glBegin(GL_QUADS);
  glVertex3f( -o,  5.5f,  -o);
  glVertex3f(  o,  5.5f,   -o);
  glVertex3f( o, -5.5f,  -o);
  glVertex3f( -o, -5.5f, -o);
 glEnd();
 
  
 
 glColor3f(0.5 , 0.0f, 0.5 );
    
  
 
glBegin(GL_QUADS);
  glVertex3f( -7.9f,  sin(o)  ,  -1.3f);
  glVertex3f(  7.9f,  sin(o),   -1.3f);
  glVertex3f( 7.9f, cos(o),  -1.3f);
  glVertex3f( -7.9f, cos(o), -1.3f);
 glEnd();   
glEnd();
    }
     
    }


GLuint createDL() {
 GLuint wallsDL;

 // Create the id for the list
 wallsDL = glGenLists(2);


 glNewList(wallsDL+1,GL_COMPILE);
  //drawSnowMan();
 wall();
glColor3f(1,0,0);

glutWireCone(2,3,10,10);
 

 pyr();
  
 glEndList();
 // start list
 glNewList(wallsDL,GL_COMPILE);
 
 // call the function that contains the rendering commands
 for(int i = -2; i < 2; i++)
  for(int j=-1; j < 1; j++) 
 for (int k = -1; k<1;k++){
      glPushMatrix();
   glTranslatef(i*30.0,0,j * 30.0);
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
   
   roty=roty+0.1;
roty=rotz-0.1;
    rotx = sin(rotangle)*3;
 roty =   rotangle ;
 rotz =rotangle*1;
 lx = sin(ang);
 lz = -cos(ang);
 glLoadIdentity();
 gluLookAt(x, y, z,
       x + lx,y + ly,z + lz,
     rotx,roty,rotz);

  





}


void moveMeFlat(int i) {
 i++;
    x = x + i*(lx)*0.1;
 z = z + i*(lz)*0.1;
 glLoadIdentity();
 gluLookAt(x, y, z,
       x + lx,y + ly,z + lz,
    rotx,roty,rotz);
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




void renderScene(void) {
 
   if (rotangle>=1){rotangle==1;}
     if (rotangle<=-1){rotangle==-1;}
 
   if (rotation=1){rotation==1;}
     if (rotation<=-1){rotation==-1;}
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  angle += deltaAngle;
      rotangle +=rotation;
 
 
      if (angle > 5.0f) angle == 5;if (angle <-5.0f) angle== -5;

 
  moveMeFlat(deltaMove); 
 if (deltaAngle) { 
 orientMe(angle);
}



 

 
// Draw ground
 
 glColor3f(0.2f, 0.2f, 0.2f);
 glBegin(GL_QUADS);
  glVertex3f(-100.0f, 0.0f, -100.0f);
  glVertex3f(-100.0f, 0.0f,  100.0f);
  glVertex3f( 100.0f, 0.0f,  100.0f);
  glVertex3f( 100.0f, 0.0f, -100.0f);
 glEnd();

 

  glCallList(walls_display_list);

 frame++;
 time=glutGet(GLUT_ELAPSED_TIME);
 if (time - timebase > 100) {
  sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
  timebase = time;  
  frame = 0;
 }
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		  glutPostRedisplay();
 glColor3f(0.0f,1.0f,1.0f);
 setOrthographicProjection();
 glPushMatrix();
 glLoadIdentity();
 //renderBitmapString(30,15,(void *)font,"k");
 //renderBitmapString(30,35,(void *)font,s);
 //renderBitmapString(30,55,(void *)font,"Esc - Quit");
 glPopMatrix();
 resetPerspectiveProjection();

 glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {

 if (key == 27)
  exit(0);
}

void pressKey(int key, int x, int y) {

 switch (key) {
  case GLUT_KEY_LEFT : deltaAngle = -0.01f;  rotation =  2;  if (angle > 1.0f) angle == 5;if (angle <-5.0f) angle== -5; break;
  case GLUT_KEY_RIGHT : deltaAngle = 0.01f; rotation = -2; if (angle > 1.0f) angle == 5;if (angle <-5.0f) angle== -5;break;
  case GLUT_KEY_UP : deltaMove += 1;if (deltaAngle > 0)
        deltaMove  -= 0.01;if (deltaAngle < 0);break;
        deltaMove  += 0.01;
  case GLUT_KEY_DOWN : deltaMove +=  -1;if (deltaAngle > 0)
        deltaAngle  -= 0.01;if (deltaAngle < 0)
        deltaAngle += 0.01;break;
 
   
 
 }

}

void releaseKey(int key, int x, int y) {

 switch (key) {
  case GLUT_KEY_LEFT :   if (rotation = 0.0f) rotation == 0.0;  
        if (rotation > 0.0f) rotation -= 0.5;if (rotation < 0.0f) rotation += 0.5;
        
 
      
       break;
  case GLUT_KEY_RIGHT :   if (rotation = 0.0f) rotation == 0.0;  
     
        if (rotation > 0.0f) rotation -= 0.5;if (rotation < 0.0f) rotation += 0.5;
 
       break;
  case GLUT_KEY_UP : if (deltaMove > 0)
        deltaMove  += 1;if (deltaAngle > 0)
        deltaAngle  -= 0.01;if (deltaAngle < 0)
        deltaAngle  += 0.01;
       break;
      
  case GLUT_KEY_DOWN : if (deltaMove < 0)
        deltaMove  -= 1;if (deltaAngle > 0)
        deltaAngle  -= 0.01;if (deltaAngle < 0)
        deltaAngle  += 0.01;
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
 glutCreateWindow("space resonation");

 // register all callbacks
 initWindow();

 glutMainLoop();

 return(0);
}
