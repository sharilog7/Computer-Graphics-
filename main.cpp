#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
bool dash=false;
void modify()
{
    glBegin(GL_LINES);
    glPointSize(8.0);
    glColor3f(1,0,0.0);
    glVertex3f(0.0,0.0,0.1);
    glVertex3f(0.0,0.0,0.8);
    glVertex3f(0,0,0);
    glVertex3f(0,0,0);
    glEnd();

}
void polygons()
{
    glBegin(GL_POLYGON);

 //glColor3f( 0.0, 1.0, 1.0 );
     glVertex3f(  0.2, -0.1, -0.3 );  // P1 is red
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f(  0.2,  0.1, -0.3 );      // P2 is green
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f( -0.2,  0.1, -0.3 );      // P3 is blue
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f( -0.2, -0.1, -0.3 );      // P4 is purple

  glEnd();

  // White side - BACK
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0, 1.0 );
  glVertex3f(  0.2, -0.1, 0.3 );
  glVertex3f(  0.2,  0.1, 0.3 );
    glVertex3f( -0.2,  0.1, 0.3 );
    glVertex3f( -0.2, -0.1, 0.3 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  //glColor3f(  0.0,  0.0,  1.0 );
  glVertex3f( 0.2, -0.1, -0.3 );
  glVertex3f( 0.2,  0.1, -0.3 );
  glVertex3f( 0.2,  0.1,  0.3 );
  glVertex3f( 0.2, -0.1,  0.3);
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f( -0.2, -0.1,  0.3 );
  glVertex3f( -0.2,  0.1,  0.3 );
  glVertex3f( -0.2,  0.1, -0.3 );
  glVertex3f( -0.2, -0.1, -0.3 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.2,  0.1,  0.3 );
  glVertex3f(  0.2,  0.1, -0.3 );
  glVertex3f( -0.2,  0.1, -0.3 );
  glVertex3f( -0.2,  0.1,  0.3 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );

  glVertex3f(  0.2, -0.1, -0.3 );
  glVertex3f(  0.2, -0.1,  0.3 );
  glVertex3f( -0.2, -0.1,  0.3 );
  glVertex3f( -0.2, -0.1, -0.3 );
  glEnd();

}

void midpolygons()
{
    glBegin(GL_POLYGON);

 //glColor3f( 0.0, 1.0, 1.0 );
     glVertex3f(  0.05, -0.09, -0.2 );  // P1 is red
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f(  0.05,  0.09, -0.2 );      // P2 is green
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f( -0.05,  0.09, -0.2 );      // P3 is blue
  //000000glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f( -0.05, -0.09, -0.2 );      // P4 is purple

  glEnd();

  // White side - BACK
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0, 1.0 );
  glVertex3f(  0.05, -0.09, 0.2 );  glVertex3f(  0.05,  0.09, 0.2 );  glVertex3f( -0.05,  0.09, 0.2 );  glVertex3f( -0.05, -0.09, 0.1 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  //glColor3f(  0.0,  0.0,  1.0 );
  glVertex3f( 0.05, -0.09, -0.2 );
  glVertex3f( 0.05,  0.09, -0.2 );
  glVertex3f( 0.05,  0.09,  0.2 );
  glVertex3f( 0.05, -0.09,  0.2);
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f( -0.05, -0.09,  0.2 );
  glVertex3f( -0.05,  0.09,  0.2 );
  glVertex3f( -0.05,  0.09, -0.2 );
  glVertex3f( -0.05, -0.09, -0.2 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.05,  0.09,  0.2 );
  glVertex3f(  0.05,  0.09, -0.2 );
  glVertex3f( -0.05,  0.09, -0.2 );
  glVertex3f( -0.05,  0.09,  0.2 );
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );

  glVertex3f(  0.05, -0.09, -0.2 );
  glVertex3f(  0.05, -0.09,  0.2 );
  glVertex3f( -0.05, -0.09,  0.2 );
  glVertex3f( -0.05, -0.09, -0.2 );
  glEnd();

}


void smallpolygons()
{
    glBegin(GL_POLYGON);

 //glColor3f( 0.0, 1.0, 1.0 );
     glVertex3f(  0.02, -0.03, -0.10 );      // P1 is red
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f(  0.02,  0.03, -0.10 );      // P2 is green
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f( -0.02,  0.03, -0.10);      // P3 is blue
  //glColor3f( 1.0, 1.0, 0.0 );
     glVertex3f( -0.02, -0.03, -0.10 );      // P4 is purple

  glEnd();

  // White side - BACK
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0, 1.0 );
  glVertex3f(  0.02, -0.03, 0.10 );
  glVertex3f(  0.02,  0.03, 0.10 );
  glVertex3f( -0.02,  0.03, 0.10 );
  glVertex3f( -0.02, -0.03, 0.10 );
  glEnd();

  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  //glColor3f(  0.0,  0.0,  1.0 );
  glVertex3f( 0.02, -0.03, -0.10);
  glVertex3f( 0.02,  0.03, -0.10);
  glVertex3f( 0.02,  0.03,  0.10);
  glVertex3f( 0.02, -0.03,  0.10);
  glEnd();

  // Green side - LEFT
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f( -0.02, -0.03,  0.1 );
  glVertex3f( -0.02,  0.03,  0.1 );
  glVertex3f( -0.02,  0.03, -0.1);
  glVertex3f( -0.02, -0.03, -0.1 );
  glEnd();

  // Blue side - TOP
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );
  glVertex3f(  0.02,  0.03,  0.1);
  glVertex3f(  0.02,  0.03, -0.1);
  glVertex3f( -0.02,  0.03, -0.1);
  glVertex3f( -0.02,  0.03,  0.1);
  glEnd();

  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  //glColor3f(   0.0,  0.0,  1.0 );

  glVertex3f(  0.02, -0.03, -0.1);
  glVertex3f(  0.02, -0.03,  0.1);
  glVertex3f( -0.02, -0.03,  0.1);
  glVertex3f( -0.02, -0.03, -0.1);
  glEnd();

}
//1st polygon

void polygon1()
{
    glPushMatrix();
    glColor3f (0,0.5,0);
    glTranslatef(-0.4,-0.2,-0.4);
    polygons();
    glPopMatrix();
}
//2nd polygon blue
void polygon2()
{
    glPushMatrix();
    glColor3f (0,0,0.6);
    glTranslatef(0.0,-0.2,-0.4);
    polygons();
    glPopMatrix();
}
void polygon21()
{
    glPushMatrix();
    glColor3f (0,0,0.6);
    glTranslatef(0.2,-0.2,-0.4);
    polygons();
    glPopMatrix();
}


//3rd polygon blue
void polygon3()
{
    glPushMatrix();
    glColor3f (0,0.5,0);
    glTranslatef(0.6,-0.2,-0.4);
    polygons();
    glPopMatrix();

}
void polygon31()
{
    glPushMatrix();
    glColor3f (0,0.0,0);
    glTranslatef(0.0,-0.2,0);
    polygons();
    glPopMatrix();

}
void backgroound()
{
    glPushMatrix();
    glColor3f (0,0.2,0);
    glTranslatef(0.,0.0,0.4);
    glRotatef(90,0.1,0.0,0);
    polygons();
    glPopMatrix();

}

void blue()
{
    //1st layer
    glPushMatrix();
    glColor3f (0,0.0,0.7);
    glTranslatef(-0.4,-0.2,0.4);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0,0.0,0.6);
    glTranslatef(0.0,-0.2,0.4);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0,0.0,0.7);
    glTranslatef(0.2,-0.2,0.4);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0,0.0,0.8);
    glTranslatef(0.6,-0.2,0.4);
    polygons();
    glPopMatrix();

    //2nd layer
    glPushMatrix();
    glColor3f (0,0.0,0.9);
    glTranslatef(-0.4,-0.0,0.4);
    polygons();
    glPopMatrix();
    glPushMatrix();
    glColor3f (0,0.0,0.8);
    glTranslatef(0.0,-0.0,0.4);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0,0.0,0.7);
    glTranslatef(0.2,-0.0,0.4);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0,0.0,0.6);
    glTranslatef(0.6,-0.0,0.4);
    polygons();
    glPopMatrix();

    // 3rd layer

    glPushMatrix();
    glColor3f (0,0.0,0.9);
    glTranslatef(-0.4,0.2,0.4);
    polygons();
    glPopMatrix();
    glPushMatrix();
    glColor3f (0,0.0,0.8);
    glTranslatef(0.0,0.2,0.4);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0,0.0,0.7);
    glTranslatef(0.2,0.2,0.4);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f (0,0.0,0.6);
    glTranslatef(0.6,0.2,0.4);
    polygons();
    glPopMatrix();

}

void middle()
{
   // glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   // glMatrixMode(GL_MODELVIEW);
  //  glLoadIdentity();

  //brown left
  //greyy
    glColor3f(0.2,0.2,0.2);
    glRotatef(90,1.0,0.0,0.0); //rotate object by 30 degree with respect to y-axis
    glTranslatef(-0.4,0.0,-0.0);
    polygons();
    glPopMatrix();

     //blue
    glColor3f(0.0,0.0,0.5);
    glRotatef(180,0.0,0.0,0.0); //rotate object by 30 degree with respect to y-axis
   // glRotatef(90,0.0,1.0,0.0);
    glTranslatef(-0.4,0.0,0.0);
    polygons();
    glPopMatrix();

     glColor3f(0.0,0.0,0.5);
    glRotatef(-180,0.0,1.0,0.0); //rotate object by 30 degree with respect to y-axis
   // glRotatef(90,0.0,1.0,0.0);
    glTranslatef(0.2,0.0,0.0);
    polygons();
    glPopMatrix();
//grey
    glColor3f(0.2,0.2,0.2);
    glRotatef(-180,0.0,1.0,0.0); //rotate object by 30 degree with respect to y-axis
   // glRotatef(90,0.0,1.0,0.0);
    glTranslatef(-0.4,0.0,0.0);
    polygons();
    glPopMatrix();
}

void road()
{
  //  glPushMatrix();
    glColor3f (0.1,0.1,0.1);
    glTranslatef(0.8,0.0,0.4);
    glRotatef(90,0.0,1.0,0.0);
    midpolygons();
    glPopMatrix();
   glColor3f (0.1,0.1,0.1);
    glTranslatef(0.0,0.0,-0.4);
    glRotatef(180,0.0,1.0,0.0);
    midpolygons();
    glPopMatrix();

      glColor3f (0.1,0.1,0.1);
    glTranslatef(0.0,0.0,0.3);
    glRotatef(180,0.0,1.0,0.0);
    midpolygons();
    glPopMatrix();    //
}


void bridge()
{
     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.2,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,0.13,0.40);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,0.13,0.40);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,0.13,0.40);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,0.13,0.40);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,0.13,0.40);
    smallpolygons();
    glPopMatrix();


      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,0.13,0.40);
    smallpolygons();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.8,0.13,0.40);
    smallpolygons();
    glPopMatrix();
//front side of bridge..
     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.999,0.15,0.1);
    glRotatef(10,1,0,0);
    polygons();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.001,0.15,0.1);
    glRotatef(10,1,0,0);
    polygons();
    glPopMatrix();
//betweennnn
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,0.15,0.2);
    glRotatef(15,1,0,0);
    smallpolygons();
    glPopMatrix();
    //blue slide ...

      glPushMatrix();
    glColor3f(0.0,0.0,0.6);
    glTranslatef(0.6,0.10,0.1);
    glRotatef(15,1,0,0);
    polygons();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.0,0.0,0.6);
    glTranslatef(0.4,0.10,0.1);
    glRotatef(15,1,0,0);
    polygons();
    glPopMatrix();


}
//back side
void backbridge()
{


     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.9,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.0,-0.12,0.45);
    smallpolygons();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.2,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,-0.12,0.45);
    smallpolygons();
    glPopMatrix();


      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.8,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.9,-0.12,0.45);
    smallpolygons();
    glPopMatrix();

   //2nd layer
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.9,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.0,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.2,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.3,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.6,-0.12,0.60);
    smallpolygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.7,-0.12,0.60);
    smallpolygons();
    glPopMatrix();


      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.8,-0.12,0.60);
    smallpolygons();
    glPopMatrix();
}

void bridgeside()
{
    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,0.0,1.10);
    glRotatef(90,0,1,0);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.1,0.0,-0.4);
    glRotatef(90,0,1,0);
    polygons();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.5,0.0,1.0);
    glRotatef(180,0,0,1);
    polygons();
    glPopMatrix();

      glPushMatrix();
    glColor3f(0.2,0.2,0.2);
    glTranslatef(0.4,0.0,-0.4);
    glRotatef(90,0,1,0);
    polygons();
    glPopMatrix();


}

void frontbridge()
{

      glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    glTranslatef(-0.1,0.1,0.7);
    glRotatef(90,0,0,1);
    midpolygons();
    glPopMatrix();

       glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    glTranslatef(-0.1,0.1,0.3);
    glRotatef(90,0,0,1);
    midpolygons();
    glPopMatrix();

       glPushMatrix();
    glColor3f(0.3,0.3,0.3);
    glTranslatef(-0.1,0.1,0.0);
    glRotatef(90,0,0,1);
    midpolygons();
    glPopMatrix();

}
void tree()
{
    glColor3f(0.9,0.2,0.0);//right 2nd tree
    glPushMatrix();
    glTranslatef(0.4,0.4,-0.05);
    glRotatef(90,0,0,1);
    glScalef(0.25,2.0,0.25);
    glutSolidCube(0.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.21,0.4,-0.05);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.3,0.4,-0.02);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.3,0.4,-0.07);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();

     /*   glPushMatrix();         //fruit
    glColor3f(0.8,0.8,0.0);
    glTranslatef(0.21,0.5,-0.05);
    glScalef(0.01,0.01,0.01);
    glutSolidSphere(1,10,10);
    glPopMatrix();

     glPushMatrix();         //fruit
    glColor3f(0.8,0.8,0.0);
    glTranslatef(0.31,0.5,-0.08);
    glScalef(0.01,0.01,0.01);
    glutSolidSphere(1,10,10);
    glPopMatrix();
*/

    glColor3f(0.9,0.2,0.0);//right 1st tree
    glPushMatrix();
    glTranslatef(0.4,0.6,-0.25);
    glRotatef(90,0,0,1);
    glScalef(0.25,2.0,0.25);
    glutSolidCube(0.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.21,0.6,-0.25);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.3,0.6,-0.22);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.3,0.6,-0.27);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
}

void Lefttree()
{   glPushMatrix();
    glTranslatef(-0.05,0.0,1.1);
    tree();
    glPopMatrix();


}
    /*glColor3f(0.9,0.2,0.0);//left 1st tree
    glPushMatrix();
    glTranslatef(0.4,0.4,0.825);
    glRotatef(90,0,0,1);
    glScalef(0.25,2.0,0.25);
    glutSolidCube(0.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.3,0.4,0.825);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.21,0.4,0.890);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.21,0.4,0.800);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();

    glColor3f(0.9,0.2,0.0);//left 2nd tree
    glPushMatrix();
    glTranslatef(0.4,0.6,1.03);
    glRotatef(90,0,0,1);
    glScalef(0.25,2.0,0.25);
    glutSolidCube(0.15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0,0.7,0.0);
    glTranslatef(0.3,0.6,1.03);
    glScalef(0.1,0.1,0.1);
    glutSolidSphere(1,10,10);
    glPopMatrix();
   */
GLfloat ys=0.0,xs=0.0,zs=0.0;
void line()
{
if(dash)
{


 glPushMatrix();
 glTranslatef(ys,0.0,0.0);
// glTranslatef(ys,0.0,0.0);

    //glPushMatrix();
    //glTranslatef(1.0,0.0,0.0)

    glColor3f(0.9,0.9,0.9);
    glLineWidth(2);
     glRotatef(10,0,0,1);
    glBegin(GL_LINES);
    glVertex3f(0.00,0.25,0.35);
    glVertex3f(0.05,0.25,0.35);
    glEnd();

   glPopMatrix();

  glPushMatrix();
 glTranslatef(0.0,xs,0.0);


    glColor3f(0.9,0.9,0.9);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(0.49,0.2,0.35);
    glVertex3f(0.49,0.15,0.35);
    glEnd();

   glPopMatrix();
   glPushMatrix();
 glTranslatef(zs,0.0,0.0);

    glColor3f(0.9,0.9,0.9);
    glLineWidth(4);

    glBegin(GL_LINES);
    glVertex3f(0.50,0.70,0.35);
    glVertex3f(0.45,0.70,0.35);
    glEnd();
glPopMatrix();

}
}

void flow()
{


    glPushMatrix();
    glTranslatef(0.00,0.0,0.30);
    //glColor3f(0.0,0.1,0.0);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,0.32);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,0.335);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,0.28);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,0.22);
    line();
    glPopMatrix();

         glPushMatrix();
    glTranslatef(0.00,0.0,0.20);
    line();
    glPopMatrix();


     glPushMatrix();
    glTranslatef(0.00,0.0,0.18);
    line();
    glPopMatrix();


     glPushMatrix();
    glTranslatef(0.00,0.0,0.12);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,0.10);
    line();
    glPopMatrix();


     glPushMatrix();
    glTranslatef(0.00,0.0,0.08);
    line();
    glPopMatrix();


     glPushMatrix();
    glTranslatef(0.00,0.0,0.02);
    line();
    glPopMatrix();


     glPushMatrix();
    glTranslatef(0.00,0.0,-0.02);
    line();
    glPopMatrix();


     glPushMatrix();
    glTranslatef(0.00,0.0,-0.08);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,-0.1);
    line();
    glPopMatrix();


     glPushMatrix();
    glTranslatef(0.00,0.0,-0.12);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,-0.18);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,-0.20);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,-0.22);
    line();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0.00,0.0,-0.24);
    line();
    glPopMatrix();
}


void idle()
{

    ys+=0.001;

    if(ys>0.5)
    {

        ys=0.2;

    }
xs+=0.001;
if(xs>0.5)
{

    xs=-0.1;
}
zs+=0.001;
if(zs>0.2)
{

    zs=0.05;
}
    glutPostRedisplay();


}



void display(){
int i=0;
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0,1.0,1.0,1.0);
    //glPointSize(10.0);

  // Reset transformations
  glLoadIdentity();

 glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

polygon1();
polygon2();
polygon21();
polygon3();
// polygon4();
blue();
middle();
bridge();
backbridge();

//bridge2();
//smallpolygons();
road();
bridgeside();
line();
flow();
//modify();
tree();
Lefttree();
frontbridge();



glFlush();
glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;


  //  Request display update
  glutPostRedisplay();

}
void mykey(unsigned char key,int x,int y)
{
    if(key=='o')
    {

    dash=true;


    }
    if(key=='c')
    {

    dash=false;

    }
    glutPostRedisplay();
    display();

}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);

  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // Create window
  glutCreateWindow("WATER DAM");

  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);

  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
 glutKeyboardFunc(mykey);

  glutIdleFunc(idle);
 //  Pass control to GLUT for events
  glutMainLoop();

  //  Return to OS
  return 0;

}
