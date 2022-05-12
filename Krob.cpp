#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM_COLORS 256

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03

int height= 320;
int width= 200;
int ff();
#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char byte;

byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x,y,c) *(VGA+(x)+(y)+height)=c
#define GETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int i,k,l,c,o,z,p,xtrig,ytrig;
  int r;
  int ol=0;
int x=100;
int  y=150;
int null=2;
int key;
int re,co;
void set_mode(byte mode)
{
   union REGS regs;
  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86( VIDEO_INT, &regs, &regs );
}
int charax[]={5,5,5,5,5,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1};
int charay[]={1,2,9,9,9,9,9,1,1,1,1,2,8,8,8,8,8,8,9,10,1,2,3,4,5,6,7,8,9,10,7,7,7,7,7,1,1,1,1,1};
int charac[]={3,3,3,3,3,3,3,3,3,3,4,2,2,2,2,2,2,2,2,4,4,2,2,2,2,2,2,2,2,4,3,3,3,3,3,3,3,3,3,3};
void put_pixels(){

 union REGS regs;
  regs.h.ah = 0x0c;
  regs.h.al = 4;
  regs.x.cx = x;
  regs.x.dx = y;
  int86( VIDEO_INT, &regs, &regs );



}

void default_scene()
		       {
	   for (l=0;l<40;l++){
	 
	      SETPIX( charax[l] , charay[l]*1, charac[l]+null );

		GETPIX( charax[l]+x, charay[l]+y, charac[l+key] );


	      charax[l]=charax[l]+0.1;
	  
	      charay[l]=charay[l]+0.1;
	   
	      charac[l]=charac[l++]+0.1;
			   
			      }


}
void clsc(){


       for(l=0;l<200;l++){


				 SETPIX( x+1, y+1, 3 );
  for(c=0;c<320;c++){
		    
    GETPIX (c,l,0);

    SETPIX( x+4, y+4, 0 );
    SETPIX( x+4, y+1, x+y );
    SETPIX( x+5, y+5, x+y );
    SETPIX( x+4, y+1, 3 );
	   // SETPIX( re, co,null );
      null=null+key;

      }}

// GETPIX( xtrig, ytrig,key  );
xtrig=xtrig+20;
 ytrig=ytrig+20;
 }

void player(){



}
void bullet()    {

		 if (ol >=     3)
			    {
			    for (key=0;key<50;key++){

			// null=0;

			GETPIX( x+key, y, charac[l+1] );
			 xtrig=re;
			 ytrig=co;

		   
			} }
	ol=0;

}

int main(){






  char kc = 0;
  char s[255];
  byte *pal;

  set_mode( VGA_256_COLOR_MODE );



  /* printf("Hello, world!\n"); */


  /* loop until ESC pressed */
  while( kc!=0X1b )


  {
if (y>190){y=190;}
if (x>310){x=310;}
if(y<10){y=10;}
 if (x<10){x=10;}
if (z>0){z=0;}



bullet();

k=k+z;

x=x+o;
y=y+r;
clsc();

//player();
key++;
put_pixels();       

 default_scene();

    if(kbhit()) {

	       //	printf(s, "r",s);

       kc=getch();
      if( kc == (char)0 ) {
	kc=getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */
	     r=r-1;
	
	   z=z-1;

	break;
	case 0x4d:

	       //left

 
	      r=0;
	      o=1;



	 break;
	case 0x4b:

		 r=0;
      
		o=-1;
	  break;

	case 0x50: /* down arrow */
		   o=0;
		k=k-2;
		z=z++;
		  r=1;
     
	  //strcpy(s, "down arrow");

	   break;

		case 0x52:
		   

		     ol=3;

		
				 break;
	default: /* other special keys */
	
	  sprintf(s, "00 %02x", kc);

	}
      }


      else {
  //	sprintf(s, "%02x", kc);
       r=0;o=0;    // null=0;
      }
//     printf("Key pressed: %s\n", s);



  }


}
default_scene();
 set_mode( TEXT_MODE );

  return 0;
}

