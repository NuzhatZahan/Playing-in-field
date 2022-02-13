#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

#define window_height 700
#define window_width 700
#define PI 3.1416
float tgt_x=0;
float tgt_y=0;
static float	tx	=  0.0;
static float	ty	=  0.0;
float minus_x=-25.0;
float plus_x=25.0;
float minus_y= -25.0;
float plus_y= 25.0;

float swing_u = 0.0;  //initialize varible to move left right up down using special key
float swing_v =0.0;

float continue_mov = -25.0;
float fruits_mov= 0.0;
float birds_mov= 0.0;

float girl_u=0.0;
float girl_v=0.0;


float sky_v=0.0;

float spin =0.0;
int state = 1; //For bouncing the Car Object
int drawaxes;

void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}


void init(void)
{
    drawaxes=1;
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(minus_x, plus_x, minus_y,plus_y, -25.0,25.0);

}

void quads(float x1, float x2, float x3, float x4,
           float x5, float x6, float x7, float x8)
{
    glBegin(GL_QUADS);
        //glColor3f(0.67, 0.93, 0.90);
        glVertex2f(x1, x2);
        glVertex2f(x3, x4);

       // glColor3f(0.98, 0.94, 0.75);
        glVertex2f(x5, x6);

        glVertex2f(x7, x8);

    glEnd();
}

void triangle(float x1, float x2, float x3,float x4, float x5, float x6)
{
      glBegin(GL_TRIANGLES);

        glVertex2f(x1, x2);
        glVertex2f(x3, x4);
        glVertex2f(x5, x6);


    glEnd();

}

void circle(float radius_x, float radius_y)
{
	int i=0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex2f (cos(angle) * radius_x, sin(angle) * radius_y);
			//glVertex2f (cos(angle) * radius_x+5, sin(angle) * radius_y);
		}

	glEnd();
}

//**SKYFunction

void sky()
{
    glBegin(GL_QUADS);
        glColor3f(0.67, 0.93, 0.90);
        //quads(-25.0, 25.0,25.0, 25.0,25.0, 7.0,-25.0, 7.0);
        glVertex2f(-25.0, 25.0);
        glVertex2f(25.0, 25.0);

        glColor3f(0.98, 0.94, 0.75);
        glVertex2f(25.0, 7.0);

        glVertex2f(-25.0, 7.0);

    glEnd();
}

void night_sky()
{
    glPushMatrix();
    glTranslatef(0, sky_v,0);
         glBegin(GL_QUADS);

            glColor3f(0.67, 0.93, 0.90);
            //quads(-25.0, 25.0,25.0, 25.0,25.0, 7.0,-25.0, 7.0);
            glVertex2f(-25.0, 7.0);
            glVertex2f(25.0, 7.0);

            glColor3f(1.0, 0.7, 0.0);
            glVertex2f(25.0, -12.0);
            glColor3f(0.62, 0.11, 0.20);
            glVertex2f(-25.0, -12.0);

        glEnd();
    glPopMatrix();

}

//**Ground***Function
void ground()
{
    glBegin(GL_QUADS);
        //glColor3f(0.59, 0.44, 0.09);
        //glColor3f(0.34, 0.51, 0.01);
        glColor3f(0.55, 0.71, 0.38);
        glVertex2f(-25.0, 7.0);

        //glColor3f(1.0, 0.96, 0.0);
        //glColor3f(0.55, 0.71, 0.38);
        glColor3f(0.75, 1.0, 0.08);
        glVertex2f(25.0, 7.0);

        //glColor3f(0.35, 0.15, 0.1);
        glColor3f(0.59, 0.44, 0.09);
        glVertex2f(25.0, -25.0);

        //glColor3f(0.01, 0.75, 0.24);
        glVertex2f(-25.0, -25.0);

    glEnd();


}

void tree_leaf()
{
    glPushMatrix();


    glTranslatef(-21.0,11.0,0);
    glColor3f(0.34, 0.51, 0.09);
	circle(6,6);

	glTranslatef(8.0,-1.0,0);
    glColor3f(0.34, 0.51, 0.01);
	circle(5,5);

	glTranslatef(7.0,3.0,0);
    glColor3f(0.34, 0.51, 0.01);
	circle(5,5);

	glTranslatef(4.0,-2.0,0);
    glColor3f(0.34, 0.51, 0.01);
	circle(4,4);


    glTranslatef(5.0,3.0,0);
    glColor3f(0.34, 0.51 , 0.01);
	circle(4.4,4.4);

	glTranslatef(-0.10,5.0,0);
    glColor3f(0.55, 0.71 , 0.0);
	circle(4.4,4.4);

	glTranslatef(-1.0,3.0,0);
    glColor3f(0.55, 0.71 , 0.0);
	circle(4,4);



	glPopMatrix();

     glBegin(GL_QUADS);//1
      glColor3f(0.0, 0.42, 0.24);
      glVertex2f(-25.0, 25.0);

        glColor3f(0.34, 0.51, 0.01);
        glVertex2f(0.0, 25.0);

        glColor3f(0.34, 0.51, 0.01);
        glVertex2f(0.0, 16.0);

        glColor3f(0.34, 0.51 , 0.01);
        glVertex2f(-25.0, 10.0);

    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.0, 0.5, 0.24);
        glVertex2f(-9.0, 25.0);

        glColor3f(0.55, 0.71 , 0.0);
        glVertex2f(4.0, 25.0);

        glColor3f(0.55, 0.71 , 0.0);
        glVertex2f(7.0, 19.0);

        glColor3f(0.55, 0.71 , 0.0);
        glVertex2f(0.0, 16.0);
    glEnd();



}

void tree_root()
{
    glBegin(GL_QUADS);//1
       glColor3f(0.24, 0.08, 0.08);
        glVertex2f(-25.0, 13.0);
        glVertex2f(-23.0, 13.0);
        glVertex2f(-23.0, 1.0);

        glVertex2f(-25.0, 1.0);

    glEnd();

     glBegin(GL_QUADS);//2
         glColor3f(0.24, 0.08, 0.08);
        glVertex2f(-25.0, 1.0);

        glColor3f(0.49, 0.37, 0.38);
        glVertex2f(-16.0, 12.0);
        glVertex2f(-14.0, 11.0);

        glColor3f(0.24, 0.08, 0.08);
        glVertex2f(-25.0, -2.0);



    glBegin(GL_QUADS);//3
        glColor3f(0.24, 0.08, 0.08);
        glVertex2f(-25.0, 3.0);

        glColor3f(0.49, 0.37, 0.38);
        glVertex2f(-21.0, 3.0);

        glVertex2f(-21.0, -25.0);

        glColor3f(0.24, 0.08, 0.08);
        glVertex2f(-25.0, -25.0);

    glEnd();


}

void tree()
{
    tree_root();
    tree_leaf();
}

void fruits()
{
    ///tree fruits
    glPushMatrix(); //fruit1
    glTranslatef(-21.0,17.0,0);
    glColor3f(0.89,0.26, 0.20);
	circle(0.7,1);
	glPopMatrix();
	 glPushMatrix(); //fruit1
    glTranslatef(-22.0,17.0,0);
    glColor3f(1.0,0.75, 0.0);
	circle(0.7,1);
	glPopMatrix();
	 glPushMatrix(); //fruit1
    glTranslatef(-22.0,19.0,0);
    glColor3f(1.0,0.83, 0.0);
	circle(0.7,1);
	glPopMatrix();
	 glPushMatrix(); //fruit1
    glTranslatef(-24.0,17.0,0);
    glColor3f(1.0,0.20, 0.0);
	circle(0.7,1);
	glPopMatrix();


    glPushMatrix(); //fruit2
    glTranslatef(-13.0,11.0,0);
    glColor3f(1.0,0.49,0.0);
	circle(0.7,1);
	glPopMatrix();

	  glPushMatrix(); //fruit2
    glTranslatef(-12.0,12.0,0);
    glColor3f(1.0,0.83,0.0);
	circle(0.7,1);
	glPopMatrix();


    glPushMatrix(); //fruit3
    glTranslatef(-10.0,19.0,0);
    glColor3f(1.0,0.45,0.0);
	circle(0.7,1);
	glPopMatrix();
	 glPushMatrix(); //fruit3
    glTranslatef(-11.0,19.0,0);
    glColor3f(1.0,0.55,0.0);
	circle(0.7,1);
	glPopMatrix();
	 glPushMatrix(); //fruit3
    glTranslatef(-8.0,20.0,0);
    glColor3f(1.0,0.83,0.0);
	circle(0.7,1);
	glPopMatrix();


	 glPushMatrix(); //fruit4
    glTranslatef(-2.0,21.0,0);
    glColor3f(1.0,0.75, 0.0);
	circle(0.7,1);
	glPopMatrix();
	 glPushMatrix(); //fruit4
    glTranslatef(-1.0,22.0,0);
    glColor3f(1.0,0.83, 0.0);
	circle(0.7,1);
	glPopMatrix();
	 glPushMatrix(); //fruit4
    glTranslatef(0.0,22.0,0);
    glColor3f(0.89,0.26, 0.20);
	circle(0.7,1);
	glPopMatrix();

	  glPushMatrix(); //fruit5
    glTranslatef(-23.0,8.0,0);
     glColor3f(1.0,0.49,0.0);
	circle(0.7,1);
	glPopMatrix();

	 glPushMatrix(); //fruit6
    glTranslatef(-18.0,23.0,0);
   glColor3f(1.0,0.75, 0.0);
	circle(0.7,1);
	glPopMatrix();

	 glPushMatrix(); //fruit7
    glTranslatef(-1.0,12.0,0);
     glColor3f(1.0,0.22,0.0);
	circle(0.7,1);
	glPopMatrix();

	///moving fruits
	glPushMatrix();
	glTranslatef(0.0, fruits_mov, 0.0);

        glPushMatrix(); //fruit1
        glTranslatef(-22.0,-2.0,0);
        glColor3f(1.0,0.75, 0.20);
        circle(0.7,1);
        glPopMatrix();

         glPushMatrix(); //fruit1
        glTranslatef(-20.0,-8.0,0);
        glColor3f(1.0,0.22, 0.0);
        circle(0.7,1);
        glPopMatrix();
    glPopMatrix();


	///ground fruits

	 glPushMatrix(); //fruit1
    glTranslatef(-22.0,-23.0,0);
    glColor3f(0.89,0.26, 0.20);
	circle(1, 0.7);
	glPopMatrix();

    glPushMatrix(); //fruit2
    glTranslatef(-18.0,-24.0,0);
    glColor3f(1.0,0.75,0.0);
	circle(1, 0.7);
	glPopMatrix();


    glPushMatrix(); //fruit3
    glTranslatef(-19.0,-22.0,0);
    glColor3f(1.0,0.55,0.0);
    circle(1, 0.7);
	glPopMatrix();

	 glPushMatrix(); //fruit4
    glTranslatef(-16.0,-23.0,0);
    glColor3f(0.89,0.26, 0.20);
	circle(1, 0.7);
	glPopMatrix();

	  glPushMatrix(); //fruit5
    glTranslatef(-14.0,-23.0,0);
     glColor3f(1.0,0.22,0.0);
	circle(1, 0.7);
	glPopMatrix();

	 glPushMatrix(); //fruit6
    glTranslatef(-8.0,-24.0,0);
   glColor3f(0.34, 0.51, 0.01);
	circle(1, 0.7);
	glPopMatrix();

	 glPushMatrix(); //fruit7
    glTranslatef(-11.0,-24.0,0);
   glColor3f(1.0,0.75, 0.20);
	circle(1, 0.7);
	glPopMatrix();

	 glPushMatrix(); //fruit7
    glTranslatef(-3.0,-24.0,0);
    glColor3f(0.89,0.26, 0.20);
	circle(1, 0.7);
	glPopMatrix();

	 glPushMatrix(); //fruit8
    glTranslatef(-3.0,-23.0,0);
   glColor3f(0.34, 0.51, 0.01);
	circle(1, 0.7);
	glPopMatrix();


    glPushMatrix(); //fruit9
    glTranslatef(0.0,-24.0,0);
    glColor3f(1.0,0.22, 0.0);
	circle(1, 0.7);
	glPopMatrix();


	glPushMatrix(); //fruit10
    glTranslatef(5.0,-24.0,0);
    glColor3f(1.0,0.75, 0.20);
	circle(1, 0.7);
	glPopMatrix();


	glPushMatrix(); //fruit11
    glTranslatef(5.0,-22.0,0);
    glColor3f(1.0,0.22, 0.0);
	circle(1, 0.7);
	glPopMatrix();

	glPushMatrix(); //fruit12
    glTranslatef(10.0,-23.0,0);
    glColor3f(1.0,0.83, 0.0);
	circle(1, 0.7);
	glPopMatrix();


	glPushMatrix(); //fruit12
    glTranslatef(13.0,-25.0,0);
    glColor3f(1.0,0.83, 0.0);
	circle(1, 0.7);
	glPopMatrix();






}


void swing()
{
      glColor3f(0.54, 0.20, 0.14);
      quads(-14.0, 20.0, -14.5,20.0, -14.5, -8.0, -14.0,-8.0);//left
      quads(-0.5, 20.0, 0.0,20.0, 0.0, -8.0, -0.5, -8.0);//right
      quads(-14.0,-7.0, -10.0,-7.0, -10.0,-8.0, -14.0,-8.0);//down

      glColor3f(0.80, 0.50, 0.20);
      //quads(-14.0,-6.0, 0.0,-6.0, 2.0,-10.0, -12.0,-10.0);
      glBegin(GL_QUADS);//sit
        glColor3f(0.53, 0.33, 0.04);
        glVertex2f(-14.0,-6.0);
        glVertex2f(0.0,-6.0);

        glColor3f(0.93, 0.57, 0.13);
        glVertex2f( 2.0,-8.0);

       glColor3f(0.53, 0.33, 0.04);
        glVertex2f(-12.0,-8.0);

    glEnd();
}

void slipper()
{
     glColor3f(0.37,0.62,0.63);
     quads(25.0, 13.0, 24.5,13.0, 24.5,0.0, 25.0, 0.0 );
     glPushMatrix(); //head
        glTranslatef(25.0, 13.0,0);
        //glColor3f(0.0,0.0, 0.0);
        circle(1.0, 1.0);
	glPopMatrix();

    glBegin(GL_QUADS);

      glColor3f(0.70, 0.13, 0.13);
        glVertex2f(24.5, 12.0);
        glVertex2f(8.0,-1.0);

        glColor3f(1.0, 0.50, 0.31);
        glVertex2f(14.0,0.0);
        glVertex2f(24.5, 9.0);
    glEnd();

     glColor3f(0.0, 0.0, 0.0);
     quads(14.0, 0.0, 14.0, 0.5, 24.75, 9, 24.75, 9.5 );
     quads(11.0, 1.0, 11.0, 1.5, 24.75, 12, 24.75, 12.5 );

}

void seasaw()
{
    glColor3f(0.09, 0.09, 0.11);
    quads(0.0, 2.0, 1.0, 2.0, 1.0, 0.0, 0.0, 0.0 );
    glColor3f(0.73, 0.31, 0.28);
    quads(-8.0, -2.0, 11.0, 6.0, 12.0,8.0,  -10.0, 0.0 );


}

void human()
{
    glColor3f(0.88,0.66,0.37);
    quads(-8.0,2.0, -7.0,2.0, -7.0,-3.0, -8.0,-3.0 );//neck
    quads(-14.0,-2.0, 0.0,-2.0, 0.0,-3.0, -14.0,-3.0 );//hand

    glColor3f(0.12,0.46,1.0);
    quads(-10.0,-5.0, -8.0,-5.0, -7.0,-8.0, -9.0,-8.0 );//leg1
    quads(-9.0,-8.0, -7.0,-8.0, -7.0,-12.0, -9.0,-12.0 );//leg2

    quads(-7.0,-5.0, -5.0,-5.0, -2.0,-8.0, -4.0,-8.0 );//leg3
    quads(-4.0,-8.0, -2.0,-8.0, -2.0,-12.0, -4.0,-12.0 );//leg3

    glColor3f(1.0,1.0,0.0);
    quads(-12.0,-1.0, -1.0,-1.0, -1.0,-3.0, -12.0,-3.0 );//body/dress
     quads(-10.0,-3.0, -3.0,-3.0, -3.0,-5.0, -10.0,-5.0 );//body/dress


    glPushMatrix(); //face
    glTranslatef(-7.0,3.0,0);
    glColor3f(0.88,0.66,0.37);

	circle(3,3);
	glPopMatrix();


	glColor3f(1.0,0.0,0.0); //cap
	quads(-10.0, 6.0, -4.0,6.0, -4.0,3.0, -10.0,3.0 );
	quads(-11.0, 4.0, -3.0,4.0, -3.0,3.0, -11.0,3.0 );


    glPushMatrix(); //eyes
    glTranslatef(-5.0,2.0,0);
    //glColor3f(0.88,0.66,0.37);
    glColor3f(0.0,0.0,0.0);
	circle(0.3,0.3);
	glPopMatrix();
	glPushMatrix();
    glTranslatef(-8.0,2.0,0);
    //glColor3f(0.88,0.66,0.37);
    glColor3f(0.0,0.0,0.0);
	circle(0.3,0.3);
	glPopMatrix();

	glColor3f(1.0,0.0,0.0);//lips
	quads(-7.0, 1.0, -6.0,1.0, -6.0,0.5, -7.0,0.5 );

    glColor3f(0.0,0.0,0.0);
	triangle(-10.0, 3.0, -9.0,3.0, -10.0,2.0); //hair
	triangle(-9.0, 3.0, -7.0,3.0, -8.0,2.7);
	triangle(-7.0, 3.0, -5.0,3.0, -6.0,2.7);
	triangle(-5.0, 3.0, -4.0,3.0, -4.0,2.0);

	glColor3f(1.0,0.0,0.0);//shoes
	quads(-9.0, -11.0, -6.0,-11.5, -6.0,-12.0, -9.0,-12.0 );
	quads(-4.0, -12.0, -1.0,-12.5, -1.0,-13.0, -4.0,-13.0 );




}


void girl()
{
    glPushMatrix();
    glTranslatef(0.0,-5.0,0);
        glPushMatrix(); //head
        glTranslatef(10.0,-1.0,0);
        glColor3f(0.0,0.0, 0.0);
        circle(2.5,2.5);
        glPopMatrix();
        quads(12.0,0.0, 14.0,0.0, 15.0,-2.0, 13.0,-1.0);//hair
        quads(6.0,0.0, 8.0,0.0, 7.0,-1.0, 5.0,-2.0);//hair

        glColor3f(1.0,0.78, 0.50);

        quads(9.5,-3.5, 10.5,-3.5, 10.5,-6.0, 9.5,-6.0); //neck

        quads(4.0, -5.0, 16.0,-5.0, 16.0,-6.0, 4.0,-6.0);//hand
        quads(4.0,-2.0, 5.0,-2.0, 5.0,-5.0, 4.0,-5.0);//hand
        quads(15.0,-2.0, 16.0,-2.0, 16.0,-5.0, 15.0,-5.0);//hand

        quads(8.0,-12.0, 9.0,-12.0, 9.0,-14.0, 8.0,-14.0);//leg
        quads(11.0,-12.0, 12.0,-12.0, 12.0,-14.0, 11.0,-14.0);//leg

         glColor3f(1.0,0.33, 0.64);
        quads(6.0, -5.0, 14.0,-5.0, 14.0,-6.5, 6.0,-6.5);//dress
        quads(8.0, -6.5, 12.0,-6.5, 12.0,-8.0, 8.0,-8.0);//dress
        quads(8.0, -8.0, 12.0,-8.0, 14.0,-13.0, 6.0,-13.0);//dress

        glLineWidth(5); //rope
        glBegin(GL_LINES);
        glColor3f(0.82, 0.41, 0.12);
        glVertex2f(4.5,-2.0);
        glVertex2f(5.7, 4.0);

        glVertex2f(15.5,-2.0);
        glVertex2f(14.7, 4.0);

        glVertex2f(5.7, 4.0);
        glVertex2f(14.7, 4.0);
        glEnd();


      glPopMatrix();


}




void bird(){
    glPushMatrix();
    glTranslatef(0,birds_mov, 0);
        glPushMatrix();
        glTranslatef(continue_mov,0, 0);
        glColor3f(0.0f, 0.20f, 0.13f);
        quads(-23.0, 16.0, -14.0,17.0, -14.0, 17.0, -22.0, 15.0);
        glColor3f(0.55f, 0.0f, 0.0f);
        triangle(-14.0,17.0, -12.0,16.0, -16.0,17.0);
        glColor3f(0.0f, 0.39f, 0.0f);
        triangle(-15.0,17.0, -13.0,13.0, -20.0,17.0);
        glPopMatrix();
    glPopMatrix();
}


void girl_mov()
{
    glPushMatrix();
    glTranslatef(girl_u, girl_v, 0);
    girl();
    glPopMatrix();
}


void swing_mov(){

    glPushMatrix();
    glRotatef(spin,1,0,0);
    glTranslatef(0, swing_v, 0);
    swing();
    human();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    night_sky();
    ground();
    tree();
    slipper();
    seasaw();

    swing_mov();
    bird();
    girl_mov();
    fruits();

    glFlush();
}

void spinDisplay_left(void)
{
    spin = spin + 0.01; //to increase or decrease speed change the value added to spin
    if (spin > 45.0)
        spin = spin - 45.0;
    //the above if block is given only for clear understanding, otherwise 370 degrees is the same as 10 degrees

    glutPostRedisplay(); //calls the display function again
}

void spinDisplay_right(void)
{
    spin = spin - 0.01;
    if (spin < -45.0)
        spin = spin + 90.0;
    glutPostRedisplay();
}

void MyMouseFunc(int button, int action, int xPixel, int yPixel)
{

    if (button == 0 && action == GLUT_DOWN)
    {
        PlaySound("bird.wav",NULL,ASYNC_MODE_COMPATIBILITY);

    }



    if(button == 2 && action == GLUT_DOWN )
    {

        if (yPixel<=350)
        {
            if(xPixel<=350)
            {
            tgt_x = (xPixel-350)/(350/25);//-625;
            tgt_y = (yPixel-350)/-(350/25);//325-
            }
            else
            {
            tgt_x = (xPixel-350)/(350/25);//-625;
            tgt_y = (yPixel-350)/-(350/25);//325-
            }

        }
        else{
            if(xPixel<=350)
            {
            tgt_x = (xPixel-350)/(350/25);//-625;
            tgt_y = (yPixel-350)/-(350/25);//325-
            }
            else{
            tgt_x = (xPixel-350)/(350/25);//-625;
            tgt_y = (yPixel-350)/-(350/25);//325-
            }
        }
            //if (xpixel<=250&&yPixel<=250)
            //else if(xpixel>250&&yPixel<=250)
            //PlaySound("giant.wav",NULL,ASYNC_MODE_COMPATIBILITY);
            //tgt_x = xPixel;//-625;
            //tgt_y = yPixel;//325-
            printf("x= %f, y=%f \n",tgt_x,tgt_y);

    }

    glutPostRedisplay();
}

void custom_special_key(int key, int x, int y)
{
    switch (key)
    {

    case GLUT_KEY_LEFT:
        glutIdleFunc(spinDisplay_left); //to move the swing left when left key pressed. To make movement faster or slower, try changing values of u

        break;

    case GLUT_KEY_RIGHT:
        glutIdleFunc(spinDisplay_right);
        break;
    case GLUT_KEY_DOWN:
       glutIdleFunc(NULL);
        break;

    case GLUT_KEY_UP:// swing can up a height
        swing_v +=0.25;
        glutPostRedisplay();
        break;



    default:
        break;
    }

}

void custom_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'd':
        fruits_mov -=0.25; //to move fruits down
        glutPostRedisplay();

        break;

    case 'B':
        birds_mov +=0.5; //to move birds up
        glutPostRedisplay();

        break;

     case 'b':
        birds_mov -=0.5; //to move birds down
        glutPostRedisplay();

        break;

    case 'l':
        girl_u -=0.5; //to move girl left
        glutPostRedisplay();

        break;

     case 'r':
        girl_u +=0.5; //to move girl right
        glutPostRedisplay();

        break;

     case 'u':
        girl_v +=0.5; //to move girl up
        glutPostRedisplay();

        break;

     case 'v':
        girl_v -=0.5; //to move girl down
        glutPostRedisplay();

        break;

     case 's':
       sky_v +=0.5; //to move sky up
        glutPostRedisplay();

        break;

     case 'S':
        sky_v -=0.5; //to move sky down
        glutPostRedisplay();

        break;




    default:
        break;
    }
}

void timer(int)
{
    glutPostRedisplay();

    //if(u<=25) u=u+0.13;
    //else u=-25;
    glutTimerFunc(1000/60,timer,0);

    switch(state)
    {
    case 1:
        if (continue_mov<40)
        {
            continue_mov +=0.5;

        }
        else state = -1;
        break;
    case -1:
        if(continue_mov>-25){
            continue_mov -=0.5;
        }
        else state = 1;
        break;
    }
}
int main()
{
    glutInitWindowPosition(0,0);
    glutInitWindowSize(window_height, window_width);
    glutCreateWindow("2D animation Scenery");
    init();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMouseFunc(MyMouseFunc);
    glutTimerFunc(1000,timer,0);
    glutSpecialFunc(custom_special_key);
    glutKeyboardFunc(custom_keyboard);
    glutMainLoop();
}
