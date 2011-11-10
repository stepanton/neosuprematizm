#include <stdlib.h>
#include <GL/glut.h>

#ifdef random
#undef random
#endif

#define random(m) (float)rand()*m/RAND_MAX

GLint Width = 512, Height = 400;
int mx,my;
int   Times = 100;
int   FillFlag  = 1;
long  Seed = 0;
float r, g, b;
float x3,y3,x4,y4;
void
DrawRect( float x1, float y1, float x2, float y2,
          int FillFlag )

{
  glBegin(FillFlag ? GL_TRIANGLES : GL_LINE_LOOP);
r = (random(1));
b = (random(1));
g = (random(1));
glColor3f( r, g, b );
  glVertex2f((x2+x1)/2, y1);
  glVertex2f(x2, y2);   
  glVertex2f(x1, y2);
  
  glVertex2f(abs(Width-(x2+x1)/2),  y1);
  glVertex2f(abs(Width-x2), y2);   
  glVertex2f(abs(Width-x1), y2);
  glEnd();
  if(rand()%2==1){
glBegin( GL_LINE_LOOP);
r = random(1);
b = random(1);
g = random(1);
glColor3f( r, g, b );
  glVertex2f((x2+x1)/2, y1);
  glVertex2f(x2, y2);   
  glVertex2f(x1, y2);
  glVertex2f(abs(Width-(x2+x1)/2),  y1);
  glVertex2f(abs(Width-x2), y2);   
  glVertex2f(abs(Width-x1), y2);
  glEnd();
}
else
  {    glBegin( GL_LINE_LOOP);
r  = random(1);
b  = random(1);
g  = random(1);
glColor3f( r, g, b );
  glVertex2f((x2+x1)/2, y1);
  glVertex2f(x2, y2);   
  glVertex2f(x1, y2);
  glEnd(); 
  glBegin( GL_LINE_LOOP);
  glVertex2f(abs(Width-(x2+x1)/2),  y1);
  glVertex2f(abs(Width-x2), y2);   
  glVertex2f(abs(Width-x1), y2);
  glEnd();
  }
//---------------------------------  
 for (int io=0;io<random(50);io++){
	x3 = random(1) * Width;
    y3 = random(1) * Height;
  for (int ip=0;ip<random(40)+5;ip++){
	  x3+=random(3)-2;
	  y3+=random(4)-2;

  glBegin(GL_QUADS);
  glVertex2f(x3+ip*5,y3);
  glVertex2f(x3+ip*5,y3+25);
  glVertex2f(x3+2+ip*5,y3+25);
  glVertex2f(x3+2+ip*5,y3);
  glEnd();}
}

//-------brilliant

	float x5,y5,xs;
	x4 = random(1) * Width;
    y4 = random(1) * Height;
    x5 = random(1) * 150;
    y5 = random(1) * 150; 
	xs=(2*x5)/2;
    glBegin(GL_LINE_LOOP);					
  glVertex2f(x4,y4);
  glVertex2f(x4-100,y4+150);
  glVertex2f(x4-80,y4+180);
  glVertex2f(x4+80,y4+180);
    glVertex2f(x4+100,y4+150);
  glVertex2f(x4-100,y4+150);
  glVertex2f(x4-80,y4+180);
  glVertex2f(x4-60,y4+150);
  glVertex2f(x4-40,y4+180);
 if (rand()%3==2)
  {
  glVertex2f(x4,y4+150);
  glVertex2f(x4,y4);  glVertex2f(x4,y4+150);
  }  
  glVertex2f(x4+40,y4+180);
  glVertex2f(x4+60,y4+150);
  glVertex2f(x4+80,y4+180);
  glVertex2f(x4+100,y4+150);
  glVertex2f(x4,y4);
  glVertex2f(x4+60,y4+150);
  glVertex2f(x4-60,y4+150);
glEnd();


}


void Display(void)
{
  int i;
  float x1, y1, x2, y2;


  srand(Seed);

  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  
glBegin(GL_QUADS);
 r = random(1);
    g = random(1);
    b = random(1);
    glColor3f( r, r, r );
  glVertex2f(0, 0);    r = random(1);

    glColor3f( r, r, r );
  glVertex2f(0, Height);   
    glColor3f( g, g, g );
  glVertex2f( Width,Height);    
    glColor3f( b, b, b );
  glVertex2f(Width, 0);    r = random(1);
    glColor3f( r, r, r );
  glEnd();
  
  for( i = 0; i < random(Times); i++ ) {
    x1 = random(1) * Width;
    y1 = random(1) * Height;
    x2 = random(1) * Width;
    y2 = random(1) * Height;
    x3 = random(1) * Width;
    y3 = random(1) * Height;
    DrawRect(x1, y1, x2, y2, FillFlag);
  }

  glFinish();
}


void
Reshape(GLint w, GLint h)
{
  Width = w;
  Height = h;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, w, 0, h, -1.0, 1.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


void timer(int=0)
{
     Display();
  ///   printf("\nx=%d y=%d",x,y);
     glutTimerFunc(1000,timer,0);
      Seed = random(RAND_MAX);
      glutPostRedisplay();
}
void
Mouse(int button, int state, int ax, int ay)
{
	 mx=ax;
     my=ay;
    // glutPostRedisplay();
  if( state == GLUT_DOWN )
  { 
    switch( button ) {
      case GLUT_LEFT_BUTTON:
        Seed = random(RAND_MAX);
        break;
      case GLUT_RIGHT_BUTTON:
        FillFlag = !FillFlag;
        break;
    }
    glutPostRedisplay();
  } 
}
void motion (int ax,int ay)
{
     mx=ax;
     my=ay;  
}

void
Keyboard( unsigned char key, int x, int y )
{
#define ESCAPE '\033'

  if( key == ESCAPE )
      exit(0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(Width, Height);
  glutCreateWindow("neosuprematizm");

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
   //timer();
  glutKeyboardFunc(Keyboard);
  glutMouseFunc(Mouse);
glutPassiveMotionFunc(motion);
  glutMainLoop();
}
