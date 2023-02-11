#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
//#include <cstdlib>
//if you got error in exit() by compiler then does not incluede stdlib.h because //exit() is also defined in glut.h file.
#define COS(X)   cos( (X) * 3.14159/180.0 )
#define SIN(X)   sin( (X) * 3.14159/180.0 )

#define RED 1
#define WHITE 2
#define CYAN 3

GLboolean IndexMode = GL_FALSE;
GLuint Ball;
GLuint spheres;
GLenum Mode;
GLfloat Zrot = 0.0, Zstep = 180.0;
GLfloat Xpos = 0.0, Ypos = 1.0;
GLfloat Xvel = 2.0, Yvel = 0.0;
GLfloat Xmin = -7.0, Xmax = 10.0;
GLfloat Ymin = -7.8, Ymax = 10.0;
GLfloat G = -9.8;
float width; 
float height;
float aspect = (float) width / (float) height;
 
float angle=0.0,deltaAngle = 0.0,ratio;
float x=0.0f,y=1.75f,z=5.0f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
void* font=GLUT_BITMAP_8_BY_13;
static GLint walls_display_list;
static GLint balls_display_list;
int bitmapHeight=13;
int l;
int m;
int n;
int qua;
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

static GLuint 
make_ball(void)
{
 
    GLuint list;
  GLfloat a, b;
  GLfloat da = 18.0, db = 18.0;
  GLfloat radius = 1.0;
  GLuint color;
  GLfloat bx, by, bz;

  list = glGenLists(1);

  glNewList(list, GL_COMPILE);

  color = 0;
  for (a = -90.0; a + da <= 90.0; a += da) {

    glBegin(GL_QUAD_STRIP);
    for (b = 0.0; b <= 360.0; b += db) {

      if (color) {
	glIndexi(RED);
        glColor3f(0, 1, 1);
      } else {
	glIndexi(WHITE);
        glColor3f(1, 1, 1);
      }

      bx = radius * COS(b) * COS(a);
      by = radius * SIN(b) * COS(a);
      bz = radius * SIN(a);
      glVertex3f(bx, by, bz);

      bx = radius * COS(b) * COS(a + da);
      by = radius * SIN(b) * COS(a + da);
      bz = radius * SIN(a + da);
      glVertex3f(bx, by, bz);

      color = 1 - color;
    }
    glEnd();

  }

  glEndList();

  return list;
}
static void 
idle(void)
{
 
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
  // light();
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
glBegin(GL_QUADS);
  glVertex3f( -0.5f,  0.5f,   2.2f);
  glVertex3f(  0.5f,  0.5f,    2.2f);
  glVertex3f( 0.5f,  -0.5f,   2.2f);
  glVertex3f( -0.5f,  -0.5f,  2.2f);
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
 glColor3f(0.0f, 0.6f, 0.8f);
 glBegin(GL_QUADS);
  glVertex3f( -1.2f,  1.2f,  -1.2f);
  glVertex3f(  1.2f,  1.2f,   -1.2f);
  glVertex3f( 1.2f, -1.2f,  -1.2f);
  glVertex3f( -1.2f, -1.2f, -1.2f);
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
 glColor3f(0.0f, 0.3f, 9.1f);
 glBegin(GL_QUADS);
  glVertex3f( -1.2f,  1.2f,   2.2f);
  glVertex3f(  1.2f,  1.2f,    2.2f);
  glVertex3f( 1.2f, -1.2f,   2.2f);
  glVertex3f( -1.2f, -1.2f,  2.2f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -2.3f,  -1.2f,   -1.3f);
  glVertex3f(  -2.3f,  -1.2f,    2.3f);
  glVertex3f( 2.3f, -1.2f,    2.3f);
  glVertex3f(  2.3f, -1.2f,  -1.3f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -1.2f,  1.2f,   2.2f);
  glVertex3f(  1.2f,  1.2f,    2.2f);
  glVertex3f( 1.2f, -1.2f,   2.2f);
  glVertex3f( -1.2f, -1.2f,  2.2f);
 glEnd();
glColor3f(0.0f, 0.3f, 9.1f);
glBegin(GL_QUADS);
  glVertex3f( -2.3f,  -2.3f,   -1.3f);
  glVertex3f(  -2.3f,  -2.3f,    2.3f);
  glVertex3f( 2.3f, -2.3f,    2.3f);
  glVertex3f(  2.3f, -2.3f,  -1.3f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -1.2f,  -1.2f,   -1.3f);
  glVertex3f(  -1.2f,  -1.2f,    2.3f);
  glVertex3f( 1.2f, -1.2f,    2.3f);
  glVertex3f(  1.2f, -1.2f,  -1.3f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f(  -2.3f,   2.3f,   -1.3f);
  glVertex3f(  -2.3f,   2.3f,    2.3f);
  glVertex3f( 2.3f,  2.3f,    2.3f);
  glVertex3f(  2.3f,  2.3f,  -1.3f);
 glEnd();

glColor3f(0.0f, 0.3f, 9.1f);

 glBegin(GL_QUADS);
  glVertex3f( -8.3f,  8.3f,  -1.62f);
  glVertex3f(  8.3f,  8.3f,   -1.62f);
  glVertex3f( 8.3f, -8.3f,  -1.62f);
  glVertex3f( -8.3f, -8.3f, -1.62f);


 glEnd();
 glBegin(GL_QUADS);
  glVertex3f( -8.3f,  8.3f,  -1.6f);
  glVertex3f(  8.3f,  8.3f,   -1.6f);
  glVertex3f( 8.3f, -8.3f,  -1.6f);
  glVertex3f( -8.3f, -8.3f, -1.6f);

glColor3f(0.5f, 0.2f, 0.0f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -8.3f,  8.3f,  -1.7f);
  glVertex3f(  8.3f,  8.3f,   -1.7f);
  glVertex3f( 8.3f, -8.3f,  -1.7f);
  glVertex3f( -8.3f, -8.3f, -1.7f);


 glEnd();
 glBegin(GL_QUADS);
  glVertex3f( -8.3f,  8.3f,  -1.8f);
  glVertex3f(  8.3f,  8.3f,   -1.8f);
  glVertex3f( 8.3f, -8.3f,  -1.8f);
  glVertex3f( -8.3f, -8.3f, -1.8f);


 glEnd();
 
 glBegin(GL_QUADS);
  glVertex3f( -8.3f,  8.3f,  -1.82f);
  glVertex3f(  8.3f,  8.3f,   -1.82f);
  glVertex3f( 8.3f, -8.3f,  -1.82f);
  glVertex3f( -8.3f, -8.3f, -1.82f);


 glEnd();
 
 glBegin(GL_QUADS);
  glVertex3f( -8.3f,  8.3f,  -1.72f);
  glVertex3f(  8.3f,  8.3f,   -1.72f);
  glVertex3f( 8.3f, -8.3f,  -1.72f);
  glVertex3f( -8.3f, -8.3f, -1.72f);
 glColor3f(0.8f, 0.6f, 0.0f);
 

 glEnd();
 glColor3f(0.8f, 0.6f, 0.0f);
 
 glPushMatrix();
 
 glColor3f(0.08f, 0.08f, 0.08f);
 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL );
glBegin(GL_QUADS);
  glVertex3f( -4.3f,  4.3f,  -1.8f);
  glVertex3f(  4.3f,  4.3f,   -1.8f);
  glVertex3f( 4.3f, -4.3f,  -1.8f);
  glVertex3f( -4.3f, -4.3f, -1.8f);

 glColor3f(0.01f, 0.01f, 0.01f);
 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -3.3f,  3.3f,  -1.81f);
  glVertex3f(  3.3f,  3.3f,   -1.81f);
  glVertex3f( 3.3f, -3.3f,  -1.81f);
  glVertex3f( -3.3f, -3.3f, -1.81f);


 glEnd();
glBegin(GL_QUADS);
  glVertex3f( -3.3f,  3.3f,  -1.79f);
  glVertex3f(  3.3f,  3.3f,   -1.79f);
  glVertex3f( 3.3f, -3.3f,  -1.79f);
  glVertex3f( -3.3f, -3.3f, -1.79f);


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
     for(  l = -5;  l < 5; l++)
  for(  m=-2; m < 2; m++)
  for (  n=-7;n<10;n++) {
  
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL );
   glPushMatrix();
   glTranslatef(l*20.0,n*10,m * 20.0);
  
 glColor3f(1.2f, 0.0f, 0.0f);
glBegin(GL_QUADS);
  glVertex3f( -m,  l,   n);
  glVertex3f(  m,  l,    n);
  glVertex3f( m, -l,   n);
  glVertex3f( -m, -l,  n);

 glColor3f(1.2f, 0.0f, 0.5f);
 glEnd();
 glBegin(GL_QUADS);
  glVertex3f( -l,  m,   n);
  glVertex3f(  l,  m,    n);
  glVertex3f( l, -m,   n);
  glVertex3f( -l, -m,  n);

 glColor3f(0.2f, 0.8f, 0.9f);
 glEnd();
  glBegin(GL_QUADS);
  glVertex3f( -l,  n,   m);
  glVertex3f(  l,  n,    m);
  glVertex3f( l, -n,   m);
  glVertex3f( -l, -n,  m);
  glEnd();
  glColor3f(0.4f, 0.2f, 0.0f);
  glBegin(GL_QUADS);
  glVertex3f(  l,  -n,   m);
  glVertex3f(  -l,  -n,    m);
  glVertex3f( -l,  n,   m);
  glVertex3f(  l,  n,  m);


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

GLuint BALLSDL(){
    GLuint spheres;
 spheres = glGenLists(1);
  glNewList(spheres,GL_COMPILE);
  
  for(int i = -3; i < 3; i++)
  for(int j=-2; j < 2; j++)
  for (int k=-2;k<2;k++) {
   glPushMatrix();
   glTranslatef(i*7.0,k*5,j * 7.0);
      
  glColor3f(1.1f, 0.1f , 0.1f);
   glutSolidSphere(1.40f,10,10);
 
 
 

   glPopMatrix();

  }
 glEndList();
    
     return(spheres);
    
    
    
}

GLuint createDL() {

  
 // Create the id for the list
 


 GLuint wallsDL;

 // Create the id for the list
 wallsDL = glGenLists(2);

 glNewList(wallsDL+1,GL_COMPILE);
  //drawSnowMan();
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE );
 pyr();
  glColor3f(1.1f, 0.1f , 0.1f);
  
  	// glutSolidCone(20  ,5.0f,20,2);
       glColor3f(1.4f, 2.1f , 0.1f);
       
 
   wall();
  glutSolidSphere(1.40f,10,10);
 glEndList();
 // start list
 glNewList(wallsDL,GL_COMPILE);
 
 // call the function that contains the rendering commands
 for(int i = -3; i < 3; i++)
  for(int j=-2; j < 2; j++)
  for (int k=-2;k<2;k++) {
   glPushMatrix();
   glTranslatef(i*7.0,k*5,j * 7.0);
      
 
 
 
   
  pyr();
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
 balls_display_list= BALLSDL();
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





void renderScene(void) {
    

 
    
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 //if (deltaMove){
  moveMeFlat(deltaMove) ;
 //if (deltaAngle) {
  angle += deltaAngle;
  orientMe(angle);
 

 
 
 
 
// Draw ground


 

  

   static float vel0 = -100.0;
  static double t0 = -1.;
  double t, dt;
 
  t = glutGet(GLUT_ELAPSED_TIME) / 2000.;
  

  if (t0 < 0.)
     t0 = t;
  dt = t - t0;
  t0 = t;

  Zrot += Zstep*dt;

  Xpos += Xvel*dt;
  if (Xpos >= Xmax) {
    Xpos = Xmax;
    Xvel = -Xvel;
    Zstep = -Zstep;
  }
  if (Xpos <= Xmin) {
    Xpos = Xmin;
    Xvel = -Xvel;
    Zstep = -Zstep;
  }
  Ypos += Yvel*dt;
  Yvel += G*dt;
  if (Ypos < Ymin) {
    Ypos = Ymin;
    if (vel0 == -100.0)
      vel0 = fabs(Yvel);
    Yvel = vel0;
  }
  glutPostRedisplay();


// Draw 36 Snow Men


 
 frame++;



   for(int i = -3; i < 3; i++)
  for(int j=-2; j < 2; j++)
  for (int k=-2;k<2;k++) {
   glPushMatrix();
   glTranslatef(i*Ypos+Xpos,k*Xpos+Ypos,j * 7.0);
        
 
  glRotatef(Zrot, 0.0, 0.0, 1.0);
  glColor3f(1.1f, 0.1f , 0.1f);
  // glutSolidSphere(1.40f,10,10);
  
     glCallList(Ball);
 
 

   glPopMatrix();

  }
     
  
  floors();

  glCallList(walls_display_list);

   glTranslatef(Xpos, Ypos, 0.0);
 
  glRotatef(Zrot, 0.0, 0.0, 1.0);
 

   
   
     
     //glCallList(balls_display_list);
 
 
 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL );
		//  glutPostRedisplay();
 glColor3f(0.0f,1.0f,1.0f);
 setOrthographicProjection();
 glPushMatrix();
 glLoadIdentity();
 //renderBitmapString(30,15,font,"k");
 //renderBitmapString(30,35,font,s);
 ////renderBitmapString(30,55,font,"Esc - Quit");
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
   case  GLUT_KEY_PAGE_UP    :  
       y++;
      break;
 
 
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
 Ball = make_ball();
 // register all callbacks
 initWindow();

 glutMainLoop();

 return(0);
}
