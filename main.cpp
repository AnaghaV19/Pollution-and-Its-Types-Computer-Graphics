#include<GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"all.h"
#include <GL/glut.h>

#define f4 GLUT_BITMAP_TIMES_ROMAN_24
#define f5 GLUT_BITMAP_HELVETICA_12
const double PI = 3.141592654;
double color1[][3]={{0.137255,0.656863,0.137255}/*0forestgreen*/,{0.498039,1.0,0.0}/*1medspringgreen*/,{0.65,.50,.039}/*2medwood*/,
					{.52,.37,.26}/*3darkwood*/,{0.88,0.70,0.40}/*4lightwood*/,{0.396078,0.9869,0.9}/*5water*/,{.20,.20,.20}/*6gray20*/,
					{.45,.45,.45}/*7gray45*/,{0.36,0.25,0.20}/*8darkbrown*/,{1.0,1.0,1.0}/*9white*/,{0.50,0.98740,0.40}/*10lightgreen*/,
					{0.309804,0.309804,0.184314}/*11DARKOLIVEGREEN*/,{.10,.10,.10}/*12gray10*/,{0.0,0.698039,1.0}/*13skyblue*/,
					{.8,.8,.8}/*14gray80*/,{0.184314,0.309804,0.309804}/*15darkslategrey*/,{0.81,0.71,0.23}/*16oldgold*/,
					{0.55,0.09,0.09}/*17scarlet*/,{0.0,0.0,0.0}/*18black*/,{0.957, 0.643, 0.376}/*19SandyBrown(skin)*/,
					{0.863, 0.078, 0.235}/*20CRIMSONRED*/,{0.729, 0.333, 0.827}/*21medorchid*/,{0.545, 0.000, 0.545}/*22darkmagenta*/,
					{1.000, 0.647, 0.000}/*23orange*/,{1.000, 0.549, 0.000}/*24darkorange*/,{0.529, 0.808, 0.980}/*25litskyblue*/,
					{0.118, 0.565, 1.000}/*26dodgerblue*/,{ 0.220, 0.220, 0.220 }/*27gray22*/,{.6,.6,.6}/*28gray60*/,/*29gray*/{0.752941,0.752941,0.752941},
					/*30gold*/{1.000, 0.843, 0.000},/*31orange*/{1.000, 0.647, 0.000},/*32wood*/{0.52,0.37,0.26},/*33orangered*/{1.000, 0.271, 0.000},
					/*34Turquoise*/{0.251, 0.878, 0.816},/*35cadetblue*/{0.373, 0.620, 0.627},/*36darkgoldenrod*/{0.722, 0.525, 0.043},
					/*37meddeepblue*/{0.000, 0.000, 0.804},/*38darkgreen*/{0.000, 0.392, 0.000},{0.0,0.0,0.0},{1.0,1.0,1.0}};

int flag=0;
int b1=0,b2=0,b3=0,b4=0,b5=0;
float pos1,pos2=250,pos3,pos4,p1,fi=500.0;
float cx1=0,cy1=30;
float c1=0.0,c2=200.0,c3=300,c4=480,c5=600,c6=480,k1=0.0,k2=100.0,k3=350.0;
int i,j=0,col=1,np=0,ap=0,wp=0,sp=0,hb=0;
double ry=400;
double r1=0,r2=0,r3=0,r4=0,r5=0,sv=0.5;
int win0,win1,win2,win3,win4,accept=0;
double scv=5,r=10;
unsigned int bg1;
unsigned int bg5;


void loadintro(void)
{
	glGenTextures(1, &bg1);
	glBindTexture(GL_TEXTURE_2D, bg1);
	// set the bg1 wrapping/filtering options (on the currently bound bg1 object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the bg1
	int width, height, nrChannels;
	unsigned char* data = stbi_load("C:\\Users\\Anagha v\\Desktop\\sampleproject\\pollutiontypes\\intro1.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf("Failed to load bg1");
		printf(stbi_failure_reason());
		exit(0);
	}
	stbi_image_free(data);
}
void displayIntro() //this function makes the picture appear on screen according to coordinates mentioned as my full page coordinates are 500x500 so to appear in full page i gave those coordinates
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, bg1);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glTexCoord2f(0, 0);
	glVertex2f(0, 500);
	glTexCoord2f(0, 1);
	glVertex2f(500, 500);
	glTexCoord2f(1, 1);
	glVertex2f(500, 0);
	glTexCoord2f(1, 0);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();

}
void loadintro1(void)
{
	glGenTextures(1, &bg5);
	glBindTexture(GL_TEXTURE_2D, bg5);
	// set the bg1 wrapping/filtering options (on the currently bound bg1 object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load and generate the bg1
	int width5, height5, nrChannels5;
	unsigned char* data5 = stbi_load("C:\\Users\\Anagha v\\Desktop\\sampleproject\\pollutiontypes\\green.png", &width5, &height5, &nrChannels5, 0);
	if (data5)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width5, height5, 0, GL_RGBA, GL_UNSIGNED_BYTE, data5);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf("Failed to load bg1");
		printf(stbi_failure_reason());
		exit(0);
	}
	stbi_image_free(data5);
}
void displayIntro1() //this function makes the picture appear on screen according to coordinates mentioned as my full page coordinates are 5000x5000 so to appear in full page i gave those coordinates
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, bg5);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glTexCoord2f(0, 0);
	glVertex2f(0, 500);
	glTexCoord2f(0, 1);
	glVertex2f(500, 500);
	glTexCoord2f(1, 1);
	glVertex2f(500, 0);
	glTexCoord2f(1, 0);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();

}
void PrintText(float x, float y, void* font,int col, char *string)
{
  int len;
  glColor3dv(color1[col]);
  glPointSize(5.0);
  glRasterPos2f(x, y);
  len = (int)strlen(string);
  for (int i = 0; i < len; i++)
  {
    glutBitmapCharacter(font, string[i]);
  }
}
void draw_text1(float x,float y,float z,char* s)
{
    glRasterPos3f(x,y,z);
    int i;
    glClearColor(1.0,0.0,0.0,0.0);
    for(i=0;s[i]!='\0';i++)
    {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
    }
}
void slow()
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(-10,-10);
	glVertex2f(-50,-10);
	glVertex2f(-50,-50);
	glVertex2f(-10,-50);
	glEnd();
}
void drawrain()
{
	glColor3dv(color1[39]);
	glBegin(GL_POLYGON);
	glVertex2f(10,15);
	glVertex2f(6,3);
	glVertex2f(7,2);
	glVertex2f(8,1);
	glVertex2f(10,0);
	glVertex2f(12,1);
	glVertex2f(13,2);
	glVertex2f(14,3);
	glEnd();
}
void rainmotion()
{
	for(i=0;i<=1200;i+=75)
	{
		glPushMatrix();
		glTranslated(i,ry,0);
		drawrain();
		glPopMatrix();
	}
	ry-=5;
	for(int j=0;j<=5000;j++)
	{
		glPushMatrix();
		glTranslated(j,0,0);
		glPopMatrix();
	}
	if(ry<0)
	{
		ry=1400;
		col=15;
	}
}
void drawCircle(int l,int m,int col1,float r)
{
    int i, x, y;
    double radius = r;
    glColor3dv(color1[col1]);
    double twoPi = 2.0 * 3.142;
    x =l, y =m;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f((x + (radius * cos(i * twoPi / 20))), (y + (radius * sin(i * twoPi / 20))));
    }
    glEnd();
}
void AdrawCircle(int l,int m,int col1,float r)
{
    int i, x, y;
    double radius = r;
    glColor3dv(color1[col1]);
    double twoPi = 2.0 * 3.142;
    x =l, y =m;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f((x + (radius * cos(i * twoPi / 20))), (y + (radius * sin(i * twoPi / 20))));
    }
    glEnd();
}
//to drop ellipse for dialog box
void black9(int col1)
{
	AdrawCircle(402,30,col1,27);//smoke from car
}
void black10(int col1)
{
	AdrawCircle(122,225,col1,27);//smoke from factory
}
void black11(int col1)
{
	AdrawCircle(122,225,col1,27);//sewage waste
}
void black12(int col1)
{
	AdrawCircle(445,225,col1,30);
}
void drawsmoke()
{
	glPushMatrix();
	glTranslated(178,300,0);
	glBegin(GL_POLYGON);
	glColor3dv(color1[12]);
	glVertex2f(60,10);
	glVertex2f(70,0);
	glVertex2f(100,0);
	glVertex2f(120,20);
	glVertex2f(120,40);
	glColor3dv(color1[14]);
	glVertex2f(100,60);
	glVertex2f(70,60);
	glVertex2f(60,50);
	glVertex2f(50,60);
	glVertex2f(20,60);
	glColor3dv(color1[12]);
	glVertex2f(0,40);
	glVertex2f(0,20);
	glVertex2f(20,0);
	glVertex2f(50,0);
    glEnd();
	glPopMatrix();
}
void carsmoke()
{
	glPushMatrix();
	glTranslated(500+r4,75,0);
	glScaled(0.03*sv,0.03*sv,0);
	drawsmoke();
	sv+=0.005;
	r4+=0.13;
	glPopMatrix();
	if(r4>200)
	{
		r4=0;
		sv=0;
	}
}
void drawcars(int x,int y,int col,float r)
{
	glColor3f(0.9,0.1,0.0);//red
	glBegin(GL_POLYGON);
	glVertex2f(60,10);
	glVertex2f(60,20);
	glVertex2f(80,20);
	glVertex2f(90,30);
	glVertex2f(110,30);
	glVertex2f(120,20);
	glVertex2f(140,20);
	glVertex2f(140,10);
	glEnd();
	drawCircle(x,y,col,r);
	drawCircle(x+40,y,col,r);
}
void cars()
{	glPushMatrix();
	glTranslated(400,75,0);
	drawcars(80,7,6,6.5);
	glPopMatrix();
}
void carmotion()
{
	glPushMatrix();
	glTranslated(k1,0,0);
	cars();
	carsmoke();
	k1-=0.2;
	glPopMatrix();
	glPushMatrix();
	glTranslated(k2,0,0);
	cars();carsmoke();
	k2-=0.2;
	glPopMatrix();
	glPushMatrix();
	glTranslated(k3,0,0);
	cars();carsmoke();
	k3-=0.2;
	glPopMatrix();
}
void drawhouse(void)
{
    glColor3f(1.0f, 0.0f, 0.0f);
	// Create the polygon door
	glBegin(GL_POLYGON);
	glVertex2i(25, 100);
	glVertex2i(45, 100);
    glVertex2i(45, 130);
	glVertex2i(25, 130);
	glEnd();
	glColor3f(0.5f, 0.5f, 0.5f);
	// Begin the polygon house1
	glBegin(GL_POLYGON);
	glVertex2i(10, 100);
	glVertex2i(60, 100);
    glVertex2i(60, 150);
	glVertex2i(10, 150);
	glEnd();
	//triangle
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
    glVertex2i(60, 150);
	glVertex2i(10, 150);
	glVertex2i(35, 200);
	glEnd();
//second house
 glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
	// Create the polygon door
	glVertex2i(85, 100);
	glVertex2i(105, 100);
    glVertex2i(105, 130);
	glVertex2i(85, 130);
	glEnd();
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2i(70, 100);
	glVertex2i(120, 100);
    glVertex2i(120, 150);
	glVertex2i(70, 150);
	glEnd();
	//triangle
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
    glVertex2i(70, 150);
    glVertex2i(120, 150);
	glVertex2i(95, 200);
    glEnd();
//Building
//door
glBegin(GL_POLYGON);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2i(310, 125);
glVertex2i(365, 125);
glVertex2i(365, 155);
glVertex2i(310, 155);
glEnd();
//2nd door
glBegin(GL_POLYGON);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2i(310, 165);
glVertex2i(365, 165);
glVertex2i(365, 195);
glVertex2i(310, 195);
glEnd();
//3rd door
glBegin(GL_POLYGON);
glColor3f(0.0f, 1.0f, 1.0f);
glVertex2i(310, 205);
glVertex2i(365, 205);
glVertex2i(365, 235);
glVertex2i(310, 235);
glEnd();
 glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2i(300, 100);
	glVertex2i(375, 100);
    glVertex2i(375, 250);
	glVertex2i(300, 250);
	glEnd();
}
void factory(int col1,int col2)
{ //building
glPointSize(2.0);
glPushMatrix();
glBegin(GL_POLYGON);
glColor3dv(color1[col1]);
glVertex2f(158.0,100.0);
glVertex2f(165.0,170.0);
glVertex2f(250.0,170.0);
glVertex2f(255.0,125.0);
glVertex2f(265.0,150.0);
glVertex2f(265.0,125.0);
glVertex2f(275.0,150.0);
glVertex2f(275.0,125.0);
glVertex2f(285.0,150.0);
glVertex2f(285.0,100.0);
glEnd();
//Chimney1
glShadeModel(GL_SMOOTH);
glColor3dv(color1[col2]);
glBegin(GL_POLYGON);
glVertex2f(178.0,150.0);
glVertex2f(180.0,300.0);
glVertex2f(188.0,300.0);
glVertex2f(190.0,150.0);
glEnd();
//Chimney2
glBegin(GL_POLYGON);
glVertex2f(196.0,150.0);
glVertex2f(198.0,280.0);
glVertex2f(206.0,280.0);
glVertex2f(208.0,150.0);
glEnd();
//Chimney3
glBegin(GL_POLYGON);
glVertex2f(212.0,150.0);
glVertex2f(214.0,260.0);
glVertex2f(222.0,260.0);
glVertex2f(224.0,150.0);
glEnd();
glPopMatrix();
}
void tree(float dist,int col2)
{
glColor3dv(color1[col2]);
glBegin(GL_POLYGON);
glVertex2f(430.0+dist,100.0);
glVertex2f(435.0+dist,150.0);
glVertex2f(440.0+dist,170.0);
glVertex2f(440.0+dist,100.0);
glVertex2f(450.0+dist,150.0);
glVertex2f(455.0+dist,170.0);
glEnd();
}
void NPCharacter(int ch)
{
	glPushMatrix();
	glTranslated(190,0,0);
	//mask
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(122.5,168);
	glVertex2f(122.5,175);
	glVertex2f(132.5,175);
	glVertex2f(132.5,168);
	glEnd();
	//head
	drawCircle(128,176,18,9.5);
	drawCircle(128,176,19,9.5);
	glColor3f(0.957, 0.643, 0.376);
	glBegin(GL_POLYGON);
	glVertex2f(126.5,162);
	glVertex2f(126.5,176);
	glVertex2f(129.5,176);
	glVertex2f(129.5,162);
	glEnd();
	//Hands
	if(ch)
	{
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(105,160);
		glVertex2f(122.5,180);
		glVertex2f(127.5,180);
		glVertex2f(111.5,160);
		glEnd();
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(150,160);
		glVertex2f(133.5,180);
		glVertex2f(128.5,180);
		glVertex2f(144.5,160);
		glEnd();
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(105,160);
		glVertex2f(110,165);
		glVertex2f(147,165);
		glVertex2f(150,160);
		glVertex2f(147,157);
		glVertex2f(110,157);
		glEnd();
	}else
	{
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(116,135);
		glVertex2f(116,160);
		glVertex2f(120,160);
		glVertex2f(120,135);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(137,160);
		glVertex2f(141,160);
		glVertex2f(141,135);
		glVertex2f(137,135);
		glEnd();
	}
	//shirt
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(120,130);
	glVertex2f(120,160);
	glVertex2f(137,160);
	glVertex2f(137,130);
	glEnd();
	//legs
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(121,100);
	glVertex2f(121,140);
	glVertex2f(127,140);
	glVertex2f(127,100);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(129,100);
	glVertex2f(129,140);
	glVertex2f(135,140);
	glVertex2f(135,100);
	glEnd();
	glPopMatrix();
}
void backdrop1(int col)
{
glBegin(GL_POLYGON);
glColor3dv(color1[col]);
glVertex2f(0,0);
glVertex2f(1200,0);
glVertex2f(1200,700);
glVertex2f(0,700);
glEnd();
}
void backdrop(int col)
{
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2f(0,0);
glVertex2f(1200,0);
glColor3dv(color1[col]);
glVertex2f(1200,700);
glVertex2f(0,700);
glEnd();
}
void strips(float dist)
{	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(20.0+dist,70.0);
	glVertex2f(20.0+dist,75.0);
	glVertex2f(60.0+dist,75.0);
	glVertex2f(60.0+dist,70.0);
	glEnd();
}
void land_road(int col1,int col2)
{	float d=0.0;
	for(int i=0;i<7;i++)
	{	strips(d);
		d+=70.0;
	}
	//greenland
	glPointSize(2.0);
	glPushMatrix();
	glColor3dv(color1[col1]);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,45);
	glVertex2f(500,45);
	glVertex2f(500,0);
	glEnd();
	//road
	glBegin(GL_POLYGON);
	glColor3dv(color1[col2]);
	glVertex2f(0,0);
	glVertex2f(0,100);
	glVertex2f(380,100);
	//glVertex2f(410,95);
	//glVertex2f(460,92);
	glVertex2f(500,100);
	glVertex2f(500,0);
	glEnd();
	glPopMatrix();
}
void blackclouds2(int col1)
{
	drawCircle(10,450,col1,58);
	drawCircle(116,450,col1,58);
	drawCircle(220,450,col1,58);
	drawCircle(330,450,col1,58);
	drawCircle(430,450,col1,58);
	drawCircle(530,450,col1,58);
}
void blackclouds1()
{
	drawCircle(-38,392,27,58);
	drawCircle(60,392,27,58);
	drawCircle(160,392,27,58);
	drawCircle(215,352,27,40);
	drawCircle(210,300,27,10);
	drawCircle(220,280,27,8);
	drawCircle(270,392,27,58);
	drawCircle(380,392,27,58);
	drawCircle(480,392,27,58);

}
void drawcloud(int col1)
{
	drawCircle(100,110,col1,30);
	drawCircle(150,130,col1,40);
	drawCircle(130,90,col1,20);
	drawCircle(190,110,col1,31);
	drawCircle(168,90,col1,25);
}
void clouds(int high,int col1)
{
	glPushMatrix();
	glTranslated(400,high,0);
	drawcloud(col1);
	glPopMatrix();
}
void cloudmotion(int col1)
{  	glPushMatrix();
	glTranslated(c1,0,0);
	clouds(290,col1);
	c1-=0.3;
	glPopMatrix();
	glPushMatrix();
	glTranslated(c2,0,0);
	clouds(250,col1);
	c2-=0.30;
	glPopMatrix();
	glPushMatrix();
	glTranslated(c3,0,0);
	clouds(300,col1);
	c3-=0.30;
	glPopMatrix();
	glPushMatrix();
	glTranslated(c4,0,0);
	clouds(270,col1);
	c4-=0.30;
	glPopMatrix();
}
void smokemotion()
{
	glPushMatrix();
	glTranslated(178,300,0);
	glScaled(-0.03*sv,0.06*sv,0);
	drawsmoke();
	sv+=0.009;
	r1+=0.0;
	glPopMatrix();
	if(r1>200)
	{
		r1=0;
		sv=0;
	}
	glPushMatrix();
	glTranslated(205,270,0);
	glScaled(-0.02*sv,0.04*sv,0);
	drawsmoke();
	sv+=0.009;
	r2+=0.00;
	glPopMatrix();
	if(r2>200)
	{
		r2=0;
		sv=0;
	}
	glPushMatrix();
	glTranslated(219,250,0);
	glScaled(-0.015*sv,0.05*sv,0);
	drawsmoke();
	sv+=0.009;
	r3+=0.0;
	glPopMatrix();
	if(r3>200)
	{
		r3=0;
		sv=0;
	}
}
void reshape1(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,450);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}


void display4()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(0.0,0.0,0.0);
	draw_text1(420,230,1,"FALLING OF ");
    draw_text1(420,215,1,"LEAVES FROM");
	draw_text1(425,200,1," TREES");
    	black12(40);
	glPushMatrix();
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	land_road(11,12);
	drawhouse();
	tree(0.0,8);
	tree(45.0,3);
	cloudmotion(28);
	blackclouds2(7);
	backdrop(6);
	glPopMatrix();
	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		window2();
	}
    glutPostRedisplay();
	glFlush();
}
void display3()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0,0.0,0.0);
	draw_text1(105,220,1,"ACID RAIN");
    	black11(40);
	glPushMatrix();
	blackclouds2(7);
	rainmotion();
	cloudmotion(28);
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	smokemotion();
	blackclouds1();
	land_road(10,12);
	drawhouse();
	drawCircle(440,150,10,30);
	tree(0.0,8);
	drawCircle(480,150,11,30);
	tree(45.0,3);
	backdrop(6);
	glPopMatrix();
	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display4);
	}
    glutPostRedisplay();
	glFlush();
}
void display2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
		glColor3f(0.0,0.0,0.0);
	draw_text1(380,30,1,"SMOKE FROM ");
	    draw_text1(385,15,1,"VEHICLES");
    	black9(40);
	glColor3f(0.0,0.0,0.0);
	draw_text1(100,230,1,"SMOKE FROM ");
	    draw_text1(105,210,1,"FACTORY");
    	black10(40);
	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	smokemotion();
	cloudmotion(14);
	blackclouds2(7);
	land_road(0,12);
	drawhouse();
	drawCircle(440,150,0,30);
	tree(0.0,8);
	drawCircle(480,150,1,30);
	tree(45.0,3);
	backdrop(13);
	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display3);
	}
    glutPostRedisplay();
	glFlush();
}

void display1(void)
{	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	carmotion();
	glPushMatrix();
	glScaled(.7,.7,0);
	glTranslated(-130,40,0);
	NPCharacter(0);
	glPopMatrix();
	factory(6,7);
	land_road(1,12);
	drawhouse();
	drawCircle(440,150,0,30);
	tree(0.0,8);
	drawCircle(480,150,1,30);
	tree(45.0,3);
	cloudmotion(9);
	//messenger();
	backdrop(13);//background gradient
	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display2);
	}
    glutPostRedisplay();
	glFlush();
}
void firstpage_A(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(160,200,f4,17,"AIR POLLUTION");
	backdrop1(5);
	if(ap)
	{
		glClearColor(0,0.6,0.8,0);
		ap=0;
		glutDisplayFunc(display1);
	}
    glutPostRedisplay();
	glFlush();
}
void main_menu(int choice)
{
   glLoadIdentity();
    backdrop(16);
    switch(choice){
    case 1:glutDisplayFunc(firstpage_A);
        break;
    case 2:window2();
        break;
    case 3:window3();
            break;
    case 4:window4();
            break;
    case 5:exit(0);
           break;
    }
}
void display0(void)
{ glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
PrintText(200,220,f4,17,"POLLUTION AND ITS TYPES");
PrintText(220,200,f5,17,"Right click and select menu option");
//draw_rectangle();
    glutCreateMenu(main_menu);
backdrop1(5);
glutAddMenuEntry("Air pollution",1);
glutAddMenuEntry("Noise pollution",2);
glutAddMenuEntry("Water pollution",3);
glutAddMenuEntry("Soil pollution",4);
glutAddMenuEntry("Exit",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
backdrop1(25);//background gradient
if(ap)
{
glClearColor(0,0.6,0.8,0);
ap=0;
glutDisplayFunc(firstpage_A);
}
    glutPostRedisplay();
glFlush();
}
void APmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		ap=1;
	}
}
void APkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			ap=1;
		}
}
void airpollutioninit()
{
	glutDisplayFunc(display0);
	glutMouseFunc(APmouse);
	glutKeyboardFunc(APkeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}

void mouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
j=1;
}
}
void keys(unsigned char key,int x,int y)
{
if(key==27)
{
exit(0);
}
if(key==13 || key==32) //enter key value
{
j=1;
}
}

/***** Noise pollution**/
/*<<<<<<<<<-----------------------NOISE POLLUTION--------------------------->>>>>>>>>*/

void NdrawCircle(int l,int m,int col1,float r)
{
    int i, x, y;
    double radius = r;
    glColor3dv(color1[col1]);
    double twoPi = 2.0 * 3.142;
    x =l, y =m;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f((x + (radius * cos(i * twoPi / 20))), (y + (radius * sin(i * twoPi / 20))));
    }
    glEnd();
}

void black6(int col1)
{
	NdrawCircle(60,340,col1,25);
}
void black7(int col1)
{
	NdrawCircle(440,350,col1,25);
}
void black8(int col1)
{
	NdrawCircle(290,360,col1,25);
}
void NPwaves(float x,float y,int col1,float r,int index,int range)
{
	int i;
    double radius = r;
    glColor3dv(color1[col1]);
    double Pib2 = 3.142/10;
    glBegin(GL_LINE_STRIP); //BEGIN CIRCLE
    //glVertex2f(x, y); // center of circle
    for (i =index ; i <= range; i++)   {
        glVertex2f((x + (radius * cos(i * Pib2 / 20))), (y + (radius * sin(i * Pib2 / 20))));
    }
    glEnd();
	glBegin(GL_LINE_STRIP); //BEGIN CIRCLE
    for (i = index; i <= range; i++)   {
        glVertex2f((x + ((radius*1.5) * cos(i * Pib2 / 20))), (y + ((radius*1.5) * sin(i * Pib2 / 20))));
    }
    glEnd();
	glBegin(GL_LINE_STRIP); //BEGIN CIRCLE
    for (i = index; i <= range; i++)   {
        glVertex2f((x + ((radius*2) * cos(i * Pib2 / 20))), (y + ((radius*2) * sin(i * Pib2 / 20))));
    }
    glEnd();//END
}
void drawcircle(float x,float y,int col1,float r,float num, int index,int range)
{
    int i;
    double radius = r;
    glColor3dv(color1[col1]);
    double NPi = (2.0* 3.142)/num;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    for (i = index; i <=range; i++)   {
        glVertex2f((x + (radius * cos(i * NPi / 20))), (y + (radius * sin(i * NPi / 20))));
    }
    glEnd(); //END
}
void NPsounds(float x,float y,int col1,int col2,float r, int seg,float a,float b)
{
    int i;
    double radius = r;
    double twoPi = 2.0 * 3.142;
	PrintText(a,b,f5,col2,"HONK");
	glColor3dv(color1[col1]);
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	glVertex2f(x,y);
    for (i = 0; i <= 55; i++)
	{
		if(i%2==0)
		{	if(i%4==0)
			    glVertex2f((x + ((radius*2) * cos(i * twoPi / seg))), (y + ((radius*2) * sin(i * twoPi / seg))));
			else
				glVertex2f((x + ((radius*1.79) * cos(i * twoPi / seg))), (y + ((radius*1.79) * sin(i * twoPi / seg))));
        }else
				glVertex2f((x + (radius * cos(i * twoPi / seg))), (y + (radius * sin(i * twoPi / seg))));
    }
    glEnd();
}
void NPwavemotion()
{
	glPushMatrix();
	glTranslated(230,170,0);
	glScaled(0.03*scv,0.03*scv,0);
	NPwaves(250,350,18,r,0,100);
	scv+=0.00002;
	r+=0.45;
	glPopMatrix();
	glPushMatrix();
	glTranslated(160,210,0);
	glScaled(-0.03*scv,0.03*scv,0);
	NPwaves(250,350,18,r,0,100);
	scv+=0.00002;
	r+=.45;
	glPopMatrix();
	glPushMatrix();
	glTranslatef(170,290,0);
	glScaled(0.03*scv,0.03*scv,0);
	NPwaves(250,350,18,r,20,120);
	scv+=0.00002;
	r+=.45;
	glPopMatrix();
	glPushMatrix();
	glTranslated(450,250,0);
	glScaled(-0.03*scv,0.03*scv,0);
	NPwaves(450,250,18,r,20,120);
	scv+=0.00002;
	r+=.45;
	glPopMatrix();
	if(r>200)
	{
		r=.45;
		scv=5;
	}
}
void NPMisc()
{
	glColor3f(0.6 ,0.09, 0.09);//SCARLET
	glBegin(GL_POLYGON);
	glVertex2f(138,240);
	glVertex2f(138,250);
	glVertex2f(128,250);
	glVertex2f(128,240);
	glEnd();
	glColor3f(0.6 ,0.8,0.196078);//MIC
	glBegin(GL_POLYGON);
	glVertex2f(113,255);
	glVertex2f(128,260);
	glVertex2f(128,230);
	glVertex2f(113,235);
	glEnd();
	glColor3f(.10,.10,.10);//POLE
	glBegin(GL_POLYGON);
	glVertex2f(138,100);
	glVertex2f(138,250);
	glVertex2f(143,250);
	glVertex2f(143,100);
	glEnd();
}
void NPbackdrop(int col)
{
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(0,0);
		glVertex2f(1200,0);
		glColor3dv(color1[col]);//0.0,0.698039,1.0
		glVertex2f(1200,700);
		glVertex2f(0,700);
		glEnd();
}
void NPdrawtruck()
{	drawcircle(85,95,14,9,1.0,0,20);
	drawcircle(85,95,12,20,1.0,0,20);
	drawcircle(185,95,14,9,1.0,0,20);
	drawcircle(185,95,12,20,1.0,0,20);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(45,140);
	glVertex2f(63,170);
	glVertex2f(80,170);
	glVertex2f(80,140);
	glEnd();
	glColor3f(0.50,0.50,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(98,200);
	glVertex2f(98,210);
	glVertex2f(218,210);
	glVertex2f(218,200);
	glEnd();
	glColor3f(0.80,0.80,0.80);
	glBegin(GL_POLYGON);
	glVertex2f(100,100);
	glVertex2f(100,200);
	glVertex2f(215,200);
	glVertex2f(215,100);
	glEnd();
	glColor3f(0.50,0.50,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(40,110);
	glVertex2f(40,140);
	glVertex2f(65,180);
	glVertex2f(100,180);
	glVertex2f(100,110);
	glEnd();
	glColor3f(0.20,0.20,0.20);
	glBegin(GL_POLYGON);
	glVertex2f(35,100);
	glVertex2f(35,110);
	glVertex2f(100,110);
	glVertex2f(100,100);
	glEnd();
}
void NPredcar(int x,int y,int col,int col2,float r)
{
	drawCircle(x,y,col2,r-10);
	drawCircle(x,y,col,r);
	drawCircle(x+70,y,col2,r-10);
	drawCircle(x+70,y,col,r);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(95,40);
	glVertex2f(110,55);
	glVertex2f(120,55);
	glVertex2f(120,40);
	glEnd();
	glColor3f(0.9,0.1,0.0);//red
	glBegin(GL_POLYGON);
	glVertex2f(60,10);
	glVertex2f(60,40);
	glVertex2f(90,40);
	glVertex2f(110,60);
	glVertex2f(150,60);
	glVertex2f(170,40);
	glVertex2f(190,40);
	glVertex2f(190,10);
	glEnd();
}
void NPTruckmotion()
{
		if(c5<279)
		{
			c5=278;
			glPushMatrix();
			NPsounds(420,140,20,9,16,24,410,140);
			glTranslated(c5,85,0);
			NPredcar(90,7,12,14,17);
			glPopMatrix();
		}
		glPushMatrix();
		glTranslated(c5,85,0);
		NPredcar(90,7,12,14,17);
		c5-=2;
		glPopMatrix();
		if(c6<87)
		{
			c6=86;
			glPushMatrix();
			glTranslated(c6,0,0);
			NPsounds(90,190,20,9,16,24,70,185);
			NPdrawtruck();
			glPopMatrix();
		}
		glPushMatrix();
		glTranslated(c6,0,0);
		NPdrawtruck();
		c6-=2;
		glPopMatrix();

}
void NPCar(float x,float y,int col1,int col2)
{   glPushMatrix();
	glTranslated(x,y,0);
	drawcircle(30,138,9,8,1.0,0,20);
	drawcircle(90,138,9,8,1.0,0,20);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(16,115);
	glVertex2f(16,125);
	glVertex2f(104,125);
	glVertex2f(104,115);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(40,135);
	glVertex2f(40,140);
	glVertex2f(80,140);
	glVertex2f(80,135);
	glEnd();
	glColor3dv(color1[col1]);
	glBegin(GL_POLYGON);
	glVertex2f(18,125);
	glVertex2f(18,140);
	glVertex2f(24,150);
	glVertex2f(96,150);
	glVertex2f(102,140);
	glVertex2f(102,125);
	glEnd();
	glColor3f(0.678431 ,0.917647 ,0.917647);//window
	glBegin(GL_POLYGON);
	glVertex2f(33,134);
	glVertex2f(38,173);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(80,173);
	glVertex2f(88,134);
	glEnd();
	glColor3dv(color1[col2]);//darkturqoise
	glBegin(GL_POLYGON);
	glVertex2f(24,130);
	glVertex2f(32,180);
	glVertex2f(86,180);
	glVertex2f(96,130);
	glEnd();
	glColor3f(0.0,0.0,0.0);//leftwheel
	glBegin(GL_POLYGON);
	glVertex2f(23,100);
	glVertex2f(23,130);
	glVertex2f(41,130);
	glVertex2f(41,100);
	glEnd();
	glColor3f(0.0,0.0,0.0);//rightwheel
	glBegin(GL_POLYGON);
	glVertex2f(79,100);
	glVertex2f(79,130);
	glVertex2f(97,130);
	glVertex2f(97,100);
	glEnd();
	glPopMatrix();
}
void NPBuildings(int col1,int col2)
{
	glColor3f(1.0,1.0,1.0);
	int i,j;
	for( i=0;i<31;i+=22)
	{	for(j=0;j<90;j+=22)
		{	glBegin(GL_POLYGON);
			glVertex2f(176+(float)i,110+(float)j);
			glVertex2f(176+(float)i,125+(float)j);
			glVertex2f(191+(float)i,125+(float)j);
			glVertex2f(191+(float)i,110+(float)j);
			glEnd();
		}
	}for( i=0;i<31;i+=22)
	{	for( j=0;j<90;j+=22)
		{	glBegin(GL_POLYGON);
			glVertex2f(226+(float)i,110+(float)j);
			glVertex2f(226+(float)i,125+(float)j);
			glVertex2f(241+(float)i,125+(float)j);
			glVertex2f(241+(float)i,110+(float)j);
			glEnd();
		}
	}
	//building2
     glColor3f(1.0,0.0,0.0);//cornflowerblue
	 glBegin(GL_POLYGON);
	 glVertex2f(170,100);
	 glVertex2f(170,270);
	 glVertex2f(220,225);
	 glVertex2f(220,100);
	 glEnd();
	 //Chimney2
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(180,320);
	 glVertex2f(180,340);
	 glVertex2f(210,340);
	 glVertex2f(210,320);
	 glEnd();
	 glColor3f(1.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(180,200);
	 glVertex2f(180,350);
	 glVertex2f(210,350);
	 glVertex2f(210,200);
	 glEnd();
	 //building3
	 glColor3f( 1.0 ,0.498039, 0.0);//coral
	 glBegin(GL_POLYGON);
	 glVertex2f(220,100);
	 glVertex2f(220,270);
	 glVertex2f(270,225);
	 glVertex2f(270,100);
	 glEnd();
	 //Chimney3
	 glColor3dv(color1[col1]);
	 glBegin(GL_POLYGON);
	 glVertex2f(230,360);
	 glVertex2f(230,380);
	 glVertex2f(260,380);
	 glVertex2f(260,360);
	 glEnd();
	 glColor3f(1.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(230,200);
	 glVertex2f(230,400);
	 glVertex2f(260,400);
	 glVertex2f(260,200);
	 glEnd();
	 //HOSPITAL
	 PrintText(389,176,f5,18,"BUILDING");
	 glColor3f(.8,.8,.8);
	 glBegin(GL_POLYGON);
	 glVertex2f(385,170);
	 glVertex2f(385,200);
	 glVertex2f(475,200);
	 glVertex2f(475,170);
	 glEnd();
	 glColor3f(1.0,0.0,0.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(400,90);
	 glVertex2f(400,130);
	 glVertex2f(430,130);
	 glVertex2f(430,90);
	 glEnd();
	 glColor3f(0.0,0.0,1.0);//blueviolet
	 glBegin(GL_POLYGON);
	 glVertex2f(380,90);
	 glVertex2f(380,300);
	 glVertex2f(480,300);
	 glVertex2f(480,90);
	 glEnd();

}
void NPLand(int col1,int col2)
{	float d=0.0;
	for(int i=0;i<7;i++)
	{
		strips(d);
		d+=70.0;
	}
	//land
	glPointSize(2.0);
	glPushMatrix();
	glColor3dv(color1[col1]);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,40);
	glVertex2f(500,40);
	glVertex2f(500,0);
	glEnd();
	//road
	glBegin(GL_POLYGON);
	glColor3f(.30,.30,.30);
	glVertex2f(0,0);
	glVertex2f(0,100);
	glVertex2f(500,100);
	glVertex2f(500,0);
	glEnd();
	glPopMatrix();
}
/*void lastpage_N(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	 PrintText(40,400,f4,40,"CAUSES OF NOISE POLLUTION ");
	PrintText(40,370,f4,18,"1. Industrialization ");
	PrintText(40,350,f4,18,"2. Social Events");
	PrintText(40,330,f4,18,"3. Poor Urban Planning");
    PrintText(40,310,f4,18,"4. Construction Activities");
	PrintText(40,280,f4,40,"EFFECTS OF NOISE POLLUTION ");
	PrintText(40,250,f4,18,"1. Hearing Problems");
	PrintText(40,230,f4,18,"2. Psychological Issues");
	PrintText(40,210,f4,18,"3. Sleeping Disorders");
	PrintText(40,190,f4,18,"4. Cardiovascular Problems");
	PrintText(40,160,f4,40,"SOLUTION TO REDUCE NOISE POLLUTION ");
	PrintText(40,130,f4,18,"1. Minimize The Use Of Fossil Fuel Powered Automobiles");
	PrintText(40,110,f4,18,"2. Charging Fines For Exceeding Limit");
	PrintText(40,90,f4,18,"3. Get Your Vehicle Checked Regularly And Lubricate It Properly So That It Doesnt Produce Too Much Noise");
	backdrop(23);
	if(np)
	{
		np=0;
		flag=0;
		window3();
	}
    glutPostRedisplay();
	glFlush();
}*/
void NPScene2(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0,0.0,0.0);
	   draw_text1(45,350,1,"TRAFFIC ");
	    draw_text1(55,330,1,"NOISE");
    	black6(40);
	glColor3f(0.0,0.0,0.0);
	   draw_text1(270,360,1,"INDUSTRIAL ");
       draw_text1(275,340,1,"NOISE");
        black7(40);
	glColor3f(0.0,0.0,0.0);
	   draw_text1(425,360,1,"SOCIAL");
       draw_text1(430,340,1,"EVENTS");
        black8(40);
	NPsounds(30,220,19,20,20,24,10,215);
	NPsounds(90,190,20,9,16,16,70,185);
	NPTruckmotion();
	NPwavemotion();//waves from industries
	NPCharacter(1);
	NPMisc();
	NPCar(0,0,25,26);NPCar(20,0,23,24);NPCar(-30,0,21,22);
	NPLand(14,7);
	NPBuildings(17,3);
	NPbackdrop(13);
	if(np)
	{
		np=0;
		window3();
	}
	glutPostRedisplay();
	glFlush();
}
void NPScene1(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	NPCharacter(0);
	NPMisc();
	NPCar(0,0,25,26);NPCar(20,0,23,24);NPCar(-30,0,21,22);
	NPLand(14,7);
	NPBuildings(17,3);
	NPbackdrop(13);
	if(np)
	{
		np=0;
		glutDisplayFunc(NPScene2);
	}
	glutPostRedisplay();
	glFlush();
}
void NPmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		np=1;
	}
}
void NPkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			np=1;
		}
}
void firstpage_N(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(160,200,f4,17,"NOISE POLLUTION");
	backdrop1(5);
	if(np)
	{
		glClearColor(0,0.6,0.8,0);
		np=0;
		glutDisplayFunc(NPScene1);
	}
    glutPostRedisplay();
	glFlush();
}
void NoisePollutioninit()
{
	glutDisplayFunc(firstpage_N);
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(NPmouse);
	glutKeyboardFunc(NPkeys);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}
void window2()
{
	glutInitWindowSize(450,350);
	glutInitWindowPosition(910,0);
	win2=glutCreateWindow("Noise Pollution");
	glutCreateMenu(main_menu);
backdrop1(5);
glutAddMenuEntry("Air pollution",1);
glutAddMenuEntry("Noise pollution",2);
glutAddMenuEntry("Water pollution",3);
glutAddMenuEntry("Soil pollution",4);
glutAddMenuEntry("Exit",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutReshapeFunc(reshape1);
	NoisePollutioninit();
glutMainLoop();
}
/***** water pollution**/
/*<<<<<<<<<-----------------------Water POLLUTION--------------------------->>>>>>>>>*/


void draw_text(float x,float y,float z,char* s)
{
    glRasterPos3f(x,y,z);
    int i;
    for(i=0;s[i]!='\0';i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
}
/*void lastpage_W(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(40,400,f4,40,"CAUSES OF WATER POLLUTION ");
	PrintText(40,370,f4,18,"1. Industrial Waste ");
	PrintText(40,350,f4,18,"2. Sewage and Wastewater");
	PrintText(40,330,f4,18,"3. Oil Leaks and Spills");
	PrintText(40,300,f4,40,"EFFECTS OF WATER POLLUTION ");
	PrintText(40,270,f4,18,"1. Contamination of food chain");
	PrintText(40,250,f4,18,"2. Diseases like cholera,dysentery etc.");
	PrintText(40,230,f4,18,"3. Lack of portable water");
	PrintText(40,210,f4,18,"4. Infant mortality ");
	PrintText(40,190,f4,18,"5. Destruction of biodiversity");
	PrintText(40,160,f4,40,"SOLUTION TO REDUCE WATER POLLUTION ");
	PrintText(40,130,f4,18,"1. Reduce CO2 emissions to prevent global warming and acidification of oceans ");
	PrintText(40,110,f4,18,"2. Reduce the use of chemical pesticides and nutrients on crops");
	PrintText(40,90,f4,18,"3. Reduce and safely treat waste water ,it can be reused for irrigation and energy production ");
	PrintText(40,70,f4,18,"4. Restrict the use of single-use plastics that end up floating in rivers,oceans as microplastics");
	backdrop(23);
	if(wp)
	{
		wp=0;
		window4();
	}
    glutPostRedisplay();
	glFlush();
}*/
void WdrawCircle(int l,int m,int col1,float r)
{
    int i, x, y;
    double radius = r;
    glColor3dv(color1[col1]);
    double twoPi = 2.0 * 3.142;
    x =l, y =m;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f((x + (radius * cos(i * twoPi / 20))), (y + (radius * sin(i * twoPi / 20))));
    }
    glEnd();
}

void black3(int col1)
{
	WdrawCircle(170,360,col1,25);
}
void black4(int col1)
{
	WdrawCircle(430,150,col1,25);//sewage waste
}
void black5(int col1)
{
	WdrawCircle(65,150,col1,25);
}

void drawcirclew1(float x,float y,int col1,float r,float num, int index,int range)
{
    int i;
    double radius = r;
    glColor3dv(color1[col1]);
    double NPi = (2.0* 3.142)/num;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    for (i = index; i <=range; i++)   {
        glVertex2f((x + (radius * cos(i * NPi / 20))), (y + (radius * sin(i * NPi / 20))));
    }
    glEnd(); //END
}
void NPCharacterw(int ch)
{
	glPushMatrix();
	glTranslated(190,0,0);
	//head
	drawcirclew1(145,275,18,9.5,20.0,30,150);
	drawcirclew1(145,275,19,9.5,1.0,0,20);
	glColor3f(0.957, 0.643, 0.376);
	glBegin(GL_POLYGON);
	glVertex2f(142,260);
	glVertex2f(142,270);
	glVertex2f(145,270);
	glVertex2f(145,260);
	glEnd();
	//Hands
	if(ch)
	{
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(105,160);
		glVertex2f(122.5,180);
		glVertex2f(127.5,180);
		glVertex2f(111.5,160);
		glEnd();
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(150,160);
		glVertex2f(133.5,180);
		glVertex2f(128.5,180);
		glVertex2f(144.5,160);
		glEnd();
	}else
	{
		glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(137,240);
		glVertex2f(137,260);
		glVertex2f(140,260);
		glVertex2f(140,240);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(151,240);
		glVertex2f(151,260);
		glVertex2f(154,260);
		glVertex2f(154,240);
		glEnd();
	}
	//shirt
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(140,240);
	glVertex2f(140,260);
	glVertex2f(151,260);
	glVertex2f(151,240);
	glEnd();
	//legs
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(140,230);
	glVertex2f(140,240);
	glVertex2f(144,240);
	glVertex2f(144,230);
	glEnd();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(147,230);
	glVertex2f(147,240);
	glVertex2f(151,240);
	glVertex2f(151,230);
	glEnd();
	glPopMatrix();
}
void Wsky ()
{
	glColor3f(0.74902,0.847059,0.847059);
	glBegin(GL_POLYGON);
	glVertex2f(260,340);
	glVertex2f(280,340);
	glVertex2f(340,340);
	glVertex2f(360,340);
	glVertex2f(420,340);
	glVertex2f(440,340);
	glVertex2f(499.9,340);
	glVertex2f(499.9,499.9);
	glVertex2f(260,499.9);
	glEnd();

	glColor3f(0.74902,0.847059,0.847059);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,340);
	glVertex2f(19,340);
	glVertex2f(131,340);
	glVertex2f(260,340);
	glVertex2f(260,499.9);
	glVertex2f(0.1,499.9);
	glEnd();
}
void Wcircle(GLint x,GLint y,GLint r,int col1,int col2)
{
	GLint i;
	glColor3dv(color1[col1]);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
		glColor3dv(color1[col2]);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Wrays()
{
	glColor3f(1.000, 0.647, 0.000);
	glBegin(GL_LINE_STRIP);
	glVertex2f(230,450);
	glVertex2f(220,435);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(240,450);
	glVertex2f(240,432);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(250,450);
	glVertex2f(260,435);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(260,455);
	glVertex2f(270,445);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(220,455);
	glVertex2f(210,445);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(220,465);
	glVertex2f(205,465);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(260,465);
	glVertex2f(275,465);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(260,475);
	glVertex2f(275,485);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(220,475);
	glVertex2f(205,485);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(230,485);
	glVertex2f(215,499.9);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(240,490);
	glVertex2f(240,499.9);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2f(250,485);
	glVertex2f(265,499.9);
	glEnd();
}
void Wsun()
{
int xc=240,yc=470,r=20;
Wcircle(xc,yc,r,30,31);
//glRotatef(20,xc,yc,0.0);
Wrays();
}

void Wgrass()
{
	glColor3f(0.196078,0.8,0.196078);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,339.9);
	glVertex2f(259.9,339.9);
	glVertex2f(259.9,249.9);
	glVertex2f(0.1,249.9);
	glEnd();

	glColor3f(0.196078,0.8,0.196078);
	glBegin(GL_POLYGON);
	glVertex2f(259.9,339.9);
	glVertex2f(499.9,339.9);
	glVertex2f(499.9,249.9);
	glVertex2f(259.9,249.9);
	glEnd();
}
void Wunderground()
{
	glColor3f(0.81,0.71,0.23);
	glBegin(GL_POLYGON);
	glVertex2f(260,250);
	glVertex2f(260,260);
	glVertex2f(499.9,260);
	glVertex2f(499.9,250);
	glEnd();
}
void Wpipe2()
{
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(307,259.9);
	glVertex2f(312,259.9);
	glVertex2f(312,249.9);
	glVertex2f(307,249.9);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(387,259.9);
	glVertex2f(392,259.9);
	glVertex2f(392,249.9);
	glVertex2f(387,249.9);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(467,259.9);
	glVertex2f(472,259.9);
	glVertex2f(472,249.9);
	glVertex2f(467,249.9);
	glEnd();
}
void Wbin()
{
	//stripes
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(10,200);
	glVertex2f(15,200);
	glVertex2f(15,230);
	glVertex2f(10,230);
	glEnd();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(10,200);
	glVertex2f(15,200);
	glVertex2f(15,230);
	glVertex2f(10,230);
	glEnd();
	//cap
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(2,232);
	glVertex2f(5,238);
	glVertex2f(20,238);
	glVertex2f(23,232);
	glEnd();
	//cap1
	glColor3f(1.000, 0.589, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(10,238.0);
	glVertex2f(15,250.0);
	glVertex2f(15,238.0);
	glVertex2f(10,250.0);
	glEnd();
	//waste
	glColor3f(0.52,0.67,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(20,200.0);
	glVertex2f(25,210.0);
	glVertex2f(30,210.0);
	glVertex2f(25,200.0);
	glEnd();
		glColor3f(0.52,0.67,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(26,200.0);
	glVertex2f(25,210.0);
	glVertex2f(26,210.0);
	glVertex2f(30,200.0);
	glEnd();
	glColor3f(0.52,0.67,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(2,200.0);
	glVertex2f(5,210.0);
	glVertex2f(3,210.0);
	glVertex2f(2,200.0);
	glEnd();
    glColor3f(0.52,0.67,0.50);
	glBegin(GL_POLYGON);
	glVertex2f(0,200.0);
	glVertex2f(5,210.0);
	glVertex2f(6,210.0);
	glVertex2f(4,200.0);
	glEnd();
	//body
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(5,200);
	glVertex2f(20,200);
	glVertex2f(20,230);
	glVertex2f(5,230);
	glEnd();

}
void Wfactory()
{
	// window
	glColor3dv(color1[13]);
	glBegin(GL_POLYGON);
	glVertex2f(30,352.5);
	glVertex2f(50,352.5);
	glColor3dv(color1[13]);
	glVertex2f(50,397.5);
	glVertex2f(30,397.5);
	glEnd();

	glColor3dv(color1[13]);
	glBegin(GL_POLYGON);
	glVertex2f(70,352.5);
	glVertex2f(90,352.5);
	glColor3dv(color1[13]);
	glVertex2f(90,397.5);
	glVertex2f(70,397.5);
	glEnd();

	glColor3dv(color1[13]);
	glBegin(GL_POLYGON);
	glVertex2f(110,352.5);
	glVertex2f(125,352.5);
	glColor3dv(color1[13]);
	glVertex2f(125,397.5);
	glVertex2f(110,397.5);
	glEnd();

	//door
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(70,250);
	glVertex2f(90,250);
	glVertex2f(90,290);
	glVertex2f(70,290);
	glEnd();
   	 //base
	glColor3dv(color1[27]);
	glBegin(GL_POLYGON);
	glVertex2f(20,300);
	glVertex2f(130,300);
	glVertex2f(130,330);
	glVertex2f(20,330);
	glEnd();

     glColor3dv(color1[27]);
	glBegin(GL_POLYGON);
	glVertex2f(1,250);
	glVertex2f(150,250);
	glVertex2f(150,300);
	glVertex2f(1,300);
	glEnd();

	//body
	glColor3dv(color1[12]);
    glBegin(GL_POLYGON);
	glVertex2f(20,330);
	glVertex2f(20,420);
	glVertex2f(130,420);
	glVertex2f(130,330);
	glEnd();

    glColor3dv(color1[12]);
    glBegin(GL_LINE_LOOP);
	glVertex2f(20,330);
	glVertex2f(20,420);
	glVertex2f(130,420);
	glVertex2f(130,330);
	glEnd();

// Chimney
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f( 25,420);
	glVertex2f( 40,420);
	glVertex2f(40,480);
	glVertex2f(25,480);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(22,480);
	glVertex2f(43,480);
	glVertex2f(43,490);
	glVertex2f(22,490);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f( 55,420);
	glVertex2f(65,420);
	glVertex2f( 65,480);
	glVertex2f( 55,480);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(52,480);
	glVertex2f(68,480);
	glVertex2f(68,490);
	glVertex2f(52,490);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(85,420);
	glVertex2f(95,420);
	glVertex2f(95,480);
	glVertex2f(85,480);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(82,480);
	glVertex2f(98,480);
	glVertex2f(98,490);
	glVertex2f(82,490);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(110,420);
	glVertex2f(125,420);
	glVertex2f(125,480);
	glVertex2f(110,480);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(107,480);
	glVertex2f(128,480);
	glVertex2f(128,490);
	glVertex2f(107,490);
	glEnd();
}

void Wpipe()
{   // pipe
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(130,300);
	glVertex2f(160,300);
	glVertex2f(160,320);
	glVertex2f(130,320);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
    glBegin(GL_POLYGON);
	glVertex2f(150,320);
	glVertex2f(160,320);
	glVertex2f(160,250);
	glVertex2f(150,250);
	glEnd();
}

void Wroads()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(499.9,250);
	glVertex2f(499.9,200);
	glVertex2f(0.1,200);
	glVertex2f(0.1,250);
	glEnd();
}

void Wcar(int x)
{
		if(pos1<500)
	pos1+=1.0;
	if(pos1==500)
	pos1-=500;
	if(cx1<500)
	cx1+=0.5;
	if(cx1>=500)
	cx1-=500;
		//body of car//
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(10+x,220);
		glVertex2f(10+x,235);
		glVertex2f(60+x,235);
		glVertex2f(60+x,220);
		glEnd();
		//bars of car//
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(15+x,235);
		glVertex2f(20+x,245);
		glVertex2f(20+x,243);
		glVertex2f(17+x,235);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(20+x,245);
		glVertex2f(40+x,245);
		glVertex2f(40+x,243);
		glVertex2f(20+x,243);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(40+x,245);
		glVertex2f(45+x,235);
		glVertex2f(43+x,235);
		glVertex2f(40+x,243);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(28+x,243);
		glVertex2f(32+x,243);
		glVertex2f(32+x,235);
		glVertex2f(28+x,235);
		glEnd();

		//glass//
		glBegin(GL_POLYGON);
		glColor3f(0.9,0.9,0.9);
		glVertex2f(20+x,243);
		glVertex2f(40+x,243);
		glVertex2f(43+x,235);
		glVertex2f(17+x,235);
		glEnd();
}

void Wcircles(int x,int y,int r,int col)
{
	GLint i;
	glColor3dv(color1[col]);//darkgoldenrod
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Wbubble(int xc,int r, int y,int col)
{
 int yc=150+y;
 int i,n=40;
for(i=0;i<n;i+=5)
{
	Wcircles(xc,yc+i,r,col);
}
glEnd();
}

void Wwater(int col)
{
	glColor3dv(color1[col]);
	glBegin(GL_POLYGON);
	glVertex2f(0.1,200);
    glVertex2f(499.9,200);
	glVertex2f(499.9,0.1);
	glVertex2f(0.1,0.1);
	glEnd();
}
void Wunderpipe1()
{
   	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(150,200);
	glVertex2f(160,200);
	glVertex2f(160,180);
	glVertex2f(150,180);
	glEnd();
	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(150,180);
	glVertex2f(160,180);
	glVertex2f(170,170);
	glVertex2f(140,170);
	glVertex2f(150,180);
	glEnd();

	glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(370,200);
	glVertex2f(380,200);
	glVertex2f(380,180);
	glVertex2f(370,180);
	glEnd();

    glColor3f(0.556863,0.137255,0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(370,180);
	glVertex2f(380,180);
	glVertex2f(390,170);
	glVertex2f(360,170);
	glVertex2f(370,180);
	glEnd();
}
void Wstripesy(float dist)//road stripe
{	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(238.5,330-dist);
	glVertex2f(241.5,330-dist);
	glVertex2f(241.5,300-dist);
	glVertex2f(238.5,300-dist);//dist=50
	glEnd();
}

void Wstripesx(float dist)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(5+dist,223);
	glVertex2f(5+dist,227);
	glVertex2f(25+dist,227);
	glVertex2f(25+dist,223); //dist=40
	glEnd();
}
void Wstripesmall(int dist)
{	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(265+dist,275);
	glVertex2f(275+dist,275);
	glEnd();
}
void Wstripes(int d,int d1,int d2)
 {
	for(i=0;i<=12;i++)
	{
		Wstripesx(d1);
		d1+=40;
	}
 }
void Wcircle1(GLint x,GLint y,GLint r,int col1,int col2)
{
	GLint i;
	glColor3dv(color1[col1]);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
    glColor3dv(color1[col2]);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Wbottle()
{;
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(105,170);
glVertex2f(107,150);
glVertex2f(112,150);
glVertex2f(114,170);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(123,170);
glVertex2f(125,150);
glVertex2f(130,150);
glVertex2f(132,170);
glEnd();
}
void Wbottle1()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(235,170);
glVertex2f(237,150);
glVertex2f(242,150);
glVertex2f(244,170);
glEnd();
}

void Whouse()
{
	 glColor3f(1,1,1);
	 glBegin(GL_POLYGON);
	 glVertex2f(300,290);
	 glVertex2f(300,325);
	 glVertex2f(320,325);
	 glVertex2f(320,290);
	 glEnd();

// Wsewageplant()
	glColor3f(0.000, 1.000, 1.000);
	glBegin(GL_POLYGON);
	glVertex2f(480,290);
	glVertex2f(445,290);
	glVertex2f(445,350);
	glVertex2f(480,350);
	glEnd();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(470,290);
	glVertex2f(450,290);
	glVertex2f(450,350);
	glVertex2f(470,350);
	glEnd();
	//cap
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(495,290);
	glVertex2f(430,290);
	glVertex2f(430,350);
	glVertex2f(495,350);
	glEnd();
Wcircle1(463,350,32,3,3);

	 glColor3f(1,1,1);
	 glBegin(GL_POLYGON);
	 glVertex2f(380,290);
	 glVertex2f(380,325);
	 glVertex2f(400,325);
	 glVertex2f(400,290);
	 glEnd();

	glColor3f(0.52,0.39,0.39);
	glBegin(GL_POLYGON);
	glVertex2f(280,290);
	glVertex2f(340,290);
	glVertex2f(340,360);
	glVertex2f(280,360);
	glEnd();

	 glColor3f(0,0,0);
	 glBegin(GL_POLYGON);
	 glVertex2f(275,360);
	 glVertex2f(310,410);
	 glVertex2f(345,360);
	 glVertex2f(275,360);
	 glEnd();

    glColor3f(0.52,0.39,0.39);
  	glBegin(GL_POLYGON);
	glVertex2f(360,290);
	glVertex2f(420,290);
	glVertex2f(420,360);
	glVertex2f(360,360);
	glEnd();

	 glColor3f(0,0,0);
	 glBegin(GL_POLYGON);
	 glVertex2f(355,360);
	 glVertex2f(390,410);
	 glVertex2f(425,360);
	 glVertex2f(355,360);
	 glEnd();
}

void WParc(float x,float y,int col1,float r,int index,int range)
{
	int i;
    double radius = r;
    glColor3dv(color1[col1]);
    double Pib2 = 3.142/10;
    glBegin(GL_POLYGON); //BEGIN CIRCLE
    for (i =index ; i <= range; i++)   {
        glVertex2f((x + (radius * cos(i * Pib2 / 20))), (y + (radius * sin(i * Pib2 / 20))));
    }
    glEnd();
}
void Wfish(int col,int x,int y)
{
	Wcircle(240+x,63+y,2,9,9);
	WParc(250+x,50+y,col,22,35,165);
	WParc(250+x,75.5+y,col,22,240,360);
	glColor3dv(color1[col]);
	glBegin(GL_POLYGON);
	glVertex2f(260+x,63+y);
	glVertex2f(280+x,70+y);
	glVertex2f(275+x,63+y);
	glVertex2f(280+x,56+y);
	glVertex2f(260+x,63+y);
	glEnd();
}
void Wfishmotion(int ch)
{	int col=31;

	if(fi<-550)
	{
		fi=450;
	}
	if(ch)
		{
			if(fi<=300)
				col=32;

			if(fi<150)
				b1-=2;
			glPushMatrix();
			glTranslated(fi,b1,0);
			Wfish(col,0,0);
			fi-=1.0;
			glPopMatrix();
			if(fi<100)
				b2-=2;
			glPushMatrix();
			glTranslated(fi,b2,0);
			Wfish(col,150,10);
			fi-=.06;
			glPopMatrix();
			if(fi<50)
				b3-=2;
			glPushMatrix();
			glTranslated(fi,b3,0);
			Wfish(col,100,30);
			fi-=.4;
			glPopMatrix();
			if(fi<-100)
				b4-=2;
			glPushMatrix();
			glTranslated(fi,b4,0);
			Wfish(col,-200,50);
			fi-=.06;
			glPopMatrix();
			if(fi<-150)
				b5-=2;
			glPushMatrix();
			glTranslated(fi,b5,0);
			Wfish(col,-100,20);
			fi-=.21;
			glPopMatrix();

			}
	else
	{
		if(fi<=-50)
		{	col=32;
		}
	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,0,0);
	fi-=1.0;
	glPopMatrix();

	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,150,10);
	fi-=.06;
	glPopMatrix();

	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,100,30);
	fi-=.4;
	glPopMatrix();

	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,-200,50);
	fi-=.06;
	glPopMatrix();

	glPushMatrix();
	glTranslated(fi,0,0);
	Wfish(col,-100,20);
	fi-=.21;
	glPopMatrix();
	glutPostRedisplay();
}
}
void Wroads2()
{
	glColor3f(0.42,0.26,0.15);
	glBegin(GL_POLYGON);
	glVertex2f(300,290);
	glVertex2f(320,290);
	glVertex2f(330,235);
	glVertex2f(290,235);
	glEnd();

    glColor3f(0.42,0.26,0.15);
	glBegin(GL_POLYGON);
	glVertex2f(380,290);
	glVertex2f(400,290);
	glVertex2f(410,235);
	glVertex2f(370,235);
	glEnd();

	glColor3f(0.42,0.26,0.15);
	glBegin(GL_POLYGON);
	glVertex2f(440,290);
	glVertex2f(480,290);
	glVertex2f(490,235);
	glVertex2f(435,235);
	glEnd();
}
void Wcar_dumpmotion()
{

	glPushMatrix();
	glTranslated(120,cy1,0);
	cy1-=.6;
	glPopMatrix();
	if(cy1<-120)
	{
		cy1=30;
	}
}
void window4()
{
	glutInitWindowSize(450,350);
	glutInitWindowPosition(910,340);
	win4=glutCreateWindow("Soil Pollution");
	glutCreateMenu(main_menu);
backdrop1(5);
glutAddMenuEntry("Air pollution",1);
glutAddMenuEntry("Noise pollution",2);
glutAddMenuEntry("Water pollution",3);
glutAddMenuEntry("Soil pollution",4);
glutAddMenuEntry("Exit",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutReshapeFunc(reshape2);
soilpollutioninit();
glutMainLoop();
}
void WDisplay2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0,0.0,0.0);
	   draw_text1(45,150,1,"GARBAGE ");
	    draw_text1(55,135,1,"WASTE");
    	black3(40);
	glColor3f(0.0,0.0,0.0);
	   draw_text1(150,360,1,"INDUSTRIAL ");
       draw_text1(155,340,1,"WASTE");
black4(40);
	glColor3f(0.0,0.0,0.0);
	   draw_text1(415,150,1,"SEWAGE ");
       draw_text1(420,130,1,"WASTE");
black5(40);
Wbin();
	Wcar_dumpmotion();
	Wcar(cx1);
	Wsun();
	 NPCharacterw(0);
	Wfactory();
	Wstripes(0,0,0);
	Wroads();
	Whouse();
	Wroads2();
	Wpipe();
	Wunderpipe1();
    Wbottle();
    Wbottle1();
	Wgrass();
	Wbubble(155,5,cy1,18);
	Wbubble(375,5,cy1,36);
	Wfishmotion(1);
	Wwater(35);
	backdrop(13);


    if(wp)
	{
		wp=0;
		window4();
	}
	glutPostRedisplay();
	glFlush();
}


void WaterPollution()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	Wbin();
	Wcar_dumpmotion();
	Wcar(cx1);
	Wsun();
	 NPCharacterw(0);
	Wfactory();
	Wstripes(0,0,0);
	Wroads();
	Whouse();
	Wroads2();
	Wpipe();
	Wunderpipe1();
    Wbottle();
    Wbottle1();
	Wgrass();
	Wbubble(155,5,cy1,18);
	Wbubble(375,5,cy1,36);
	Wfishmotion(0);
	Wwater(34);
	backdrop(13);

	if(wp)
	{
		wp=0;
		glutDisplayFunc(WDisplay2);
	}
	glutPostRedisplay();
	draw_text(440,355,1,"SEWAGE TREATMENT ");
	glFlush();
}

void firstpage_W(void)
{	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	PrintText(160,200,f4,17,"WATER POLLUTION");
	backdrop1(5);
	if(wp)
	{
		glClearColor(0,0.6,0.8,0);
		wp=0;
		glutDisplayFunc(WaterPollution);
	}
    glutPostRedisplay();
	glFlush();
}
void WPmouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		wp=1;
	}
}

void WPkeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			wp=1;
		}
}
void waterpollutioninit()
{
	glutDisplayFunc(firstpage_W);
	glutMouseFunc(WPmouse);
	glutKeyboardFunc(WPkeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}
/*<<<<<<<<-------------------------------------soil pollution---------------------------->>>>>>>>>*/

int frameNumber=0;
void doFrame(int v)
{
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(200, doFrame, 0);
}
//drawing wind mill
void drawWindmill()
{
    glPushMatrix();
    glTranslatef(420, 350, 1);//base movement
    int i;

    glTranslatef(0, 3, 0);
    glRotated(frameNumber * (180.0 / 136), 0, 0, 1);
    glColor3f(0.20f, 0.20f, 0.20f);
    for (i = 0; i < 3; i++)
    {
        glRotated(220, 0, 0, 1); // Note: These rotations accumulate.
        glBegin(GL_POLYGON);
        glVertex2f(5, 5);
        glVertex2f(25, 10);//(point near sttand,)
        glVertex2f(50, 5);
        glVertex2f(25, -5);
        glEnd();
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(420, 350, 1);//base movement
    glColor3f(0.60f, 0.60f, 0.60f);
    glBegin(GL_POLYGON);
    glVertex2f(10, -50);//base
    glVertex2f(-8, -50);
    glVertex2f(-8, 8);
    glVertex2f(10, 8);
    glEnd();
    glPopMatrix();
}
/*void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 12; d++) {
		double angle = 2*PI/12 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}
void drawSun() {
	int i;
	glColor3f(1,1,0);
	for (i = 0; i < 10; i++) { // Draw 13 rays, with different rotations.
		glRotatef( 360 / 10, 0, 0, 1 ); // Note that the rotations accumulate!
		glBegin(GL_LINES);
		glVertex2f(250,100);
		glVertex2f(0.25f, 0);
		glEnd();
	}
	drawDisk(0.2);
	glColor3f(0,0,0);
}*/
void Searth(int x,int y,int r)
{
	GLint i;
	glColor3f(0.878, 1.000, 1.000);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Scircle()
{
GLint xc=200,yc=150,r=120;
	Searth(xc,yc,r);
}

void Sbattery2()
{
	glColor3f(0.118, 0.565, 1.00);//disposal of batteries
	glBegin(GL_POLYGON);
	glVertex2f(115.5,93.5);
	glVertex2f(115.5,95.5);
	glVertex2f(121.5,95.5);
	glVertex2f(121.5,93.5);
	glEnd();

	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(87.9,93.5);
	glVertex2f(87.9,95.5);
	glVertex2f(91.5,95.5);
	glVertex2f(91.5,93.5);
	glEnd();

	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(117.5,91);
	glVertex2f(117.5,98);
	glVertex2f(119.5,98);
	glVertex2f(119.5,91);
	glEnd();

	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(114,80);
	glVertex2f(114,110);
	glVertex2f(123,110);
	glVertex2f(123,80);
	glEnd();

	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(87,80);
	glVertex2f(87,110);
	glVertex2f(92,110);
	glVertex2f(92,80);
	glEnd();

	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(85,80);
	glVertex2f(85,110);
	glVertex2f(125,110);
	glVertex2f(125,80);
	glEnd();
	glColor3f(0.118, 0.565, 1.00);
	glBegin(GL_POLYGON);
	glVertex2f(125,92.5);
	glVertex2f(125,95.5);
	glVertex2f(127.5,95.5);
	glVertex2f(127.5,92.5);
	glEnd();
}
void Sbattery1()
{	//standing battery
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(70,82);
	glVertex2f(70,88);
	glVertex2f(100,88);
	glVertex2f(100,82);
	glEnd();
	//plus
	glColor3f(0.000, 0.000, 0.502);
	glBegin(GL_POLYGON);
	glVertex2f(83,119);
	glVertex2f(83,126);
	glVertex2f(87,126);
	glVertex2f(87,119);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(80,120.5);
    glVertex2f(80,123.5);
	glVertex2f(90,123.5);
	glVertex2f(90,120.5);
	glEnd();
	//yellowthick bar
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(70,118);
	glVertex2f(70,127);
	glVertex2f(100,127);
	glVertex2f(100,118);
	glEnd();

	glColor3f(0.000, 0.000, 0.502);
	glBegin(GL_POLYGON);
	glVertex2f(70,80);
	glVertex2f(70,130);
	glVertex2f(100,130);
	glVertex2f(100,80);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(83,130);
	glVertex2f(83,134);
	glVertex2f(87,134);
	glVertex2f(87,130);
	glEnd();
}

void Sbase()
{
	glColor3f(0.941, 0.902, 0.549);
	glBegin(GL_POLYGON);
	glVertex2f(120,25);
	glVertex2f(120,45);
	glVertex2f(280,45);
	glVertex2f(280,25);
	glEnd();
}

void Strees()
{   //body
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2f(140,45);
	glColor3f(0.502, 0.0, 0.0);
	glVertex2f(150,170);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(160,45);
	glEnd();

	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2f(180,45);
	glColor3f(0.502, 0.0, 0.0);
	glVertex2f(190,170);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(200,45);
	glEnd();

    glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_POLYGON);
	glVertex2f(220,45);
	glColor3f(0.502, 0.0, 0.0);
	glVertex2f(230,170);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(240,45);
	glEnd();

    //branches 1
	 glColor3f(0.545, 0.271, 0.075);
	 glBegin(GL_POLYGON);
	 glVertex2f(145,100);
	 glVertex2f(146,115);
	 glVertex2f(120,145);
	 glVertex2f(145,100);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glVertex2f(185,100);
	 glVertex2f(186,115);
	 glVertex2f(160,145);
	 glVertex2f(185,100);
	 glEnd();

	 glBegin(GL_POLYGON);
	 glVertex2f(225,100);
	 glVertex2f(226,115);
	 glVertex2f(200,145);
	 glVertex2f(225,100);
	 glEnd();

	  glBegin(GL_POLYGON);
	  glVertex2f(151,155);
	  glVertex2f(151,150);
	  glVertex2f(170,175);
	  glVertex2f(153,155);
	  glEnd();

	   glBegin(GL_POLYGON);
	  glVertex2f(191,155);
	  glVertex2f(191,150);
	  glVertex2f(210,175);
	  glVertex2f(191,155);
	  glEnd();

	   glBegin(GL_POLYGON);
	  glVertex2f(231,155);
	  glVertex2f(231,150);
	  glVertex2f(250,175);
	  glVertex2f(231,155);
	  glEnd();

}
void Sleaves(int x,int y,int r)
{
	GLint i;
	glColor3f(0.486, 0.988, 0.000);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Strl(GLint xc,GLint yc,int r)
{
		Sleaves(xc,yc,r);
}

void Sdustbin()
{
	//stripes
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(75,180);
	glVertex2f(75,245);
	glVertex2f(85,245);
	glVertex2f(85,180);
	glEnd();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(95,180);
	glVertex2f(95,245);
	glVertex2f(105,245);
	glVertex2f(105,180);
	glEnd();
	//cap
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(65,247);
	glVertex2f(60,250);
	glVertex2f(118,260);
	glVertex2f(113,255);
	glEnd();
	//cap1
	glColor3f(1.000, 0.549, 1.000);
	glBegin(GL_POLYGON);
	glVertex2f(84,255);
	glVertex2f(84,260);
	glVertex2f(88,260);
	glVertex2f(88,255);
	glEnd();
	//body
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(70,180);
	glVertex2f(70,245);
	glVertex2f(110,245);
	glVertex2f(110,180);
	glEnd();
}
void S_oil()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(280,80);
	glVertex2f(310,75);
	glVertex2f(350,80);
	glVertex2f(310,85);
	glEnd();
}
void Sdrum1()
{
	//stripes
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(299,135);
	glVertex2f(299,137.5);
	glVertex2f(331,137.5);
	glVertex2f(331,135);
	glEnd();
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,95);
	glVertex2f(300,97.5);
	glVertex2f(330,97.5);
	glVertex2f(330,95);
	glEnd();
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,120);
	glVertex2f(300,122.5);
	glVertex2f(330,122.5);
	glVertex2f(330,120);
	glEnd();
	glColor3f(1.000, 0.549, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(299,80);
	glVertex2f(299,82.5);
	glVertex2f(331,82.5);
	glVertex2f(331,80);
	glEnd();
	//body
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,80);
	glVertex2f(300,135);
	glVertex2f(330,135);
	glVertex2f(330,80);
	glEnd();
}
void Sdrum2()
{
	S_oil();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(247,111.5);
	glVertex2f(251,111.5);
	glVertex2f(251,79);
	glVertex2f(247,79);
	glEnd();
	glColor3f(1.000, 1.000, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(270,110.5);
	glVertex2f(275,110.5);
	glVertex2f(275,80);
	glVertex2f(270,80);
	glEnd();
	glColor3f(1.000, 0.647, 0.000);
	glBegin(GL_POLYGON);
	glVertex2f(300,110.5);
	glVertex2f(250,110.5);
	glVertex2f(250,80);
	glVertex2f(300,80);
	glEnd();
}
void Ssymbol(int x,int y,int r)
{
	GLint i;
	glColor3f(0,0,0);
	glPointSize(0.1);
	glBegin(GL_POINTS);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void Strl1(GLint xc,GLint yc,int r)
{
	Ssymbol(xc,yc,r);
}

void Sdanger1()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(315,110);
	glVertex2f(312,102);
	glVertex2f(318,102);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(315,110);
	glVertex2f(307,113.5);
	glVertex2f(313,116.4);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(315,110);
	glVertex2f(317,116.4);
	glVertex2f(323,113.5);
	glEnd();
}
void Sdanger2()
{
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(288,95);
	glVertex2f(286,88.3);
	glVertex2f(290,88.3);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(288,95);
	glVertex2f(296,98.5);
	glVertex2f(292,101.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(288,95);
	glVertex2f(284,101.5);
	glVertex2f(280,98.5);
	glEnd();
}
void drawCircle0(int l,int m,int col1,float r)
{
    int i, x, y;
    double radius = r;
    glColor3dv(color1[col1]);
    double twoPi = 2.0 * 3.142;
    x =l, y =m;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f((x + (radius * cos(i * twoPi / 20))), (y + (radius * sin(i * twoPi / 20))));
    }
    glEnd();
}
void triangle(int col1)
{
    glColor3dv(color1[col1]);
    glBegin(GL_TRIANGLES); //BEGIN CIRCLE
    glVertex2f(75,225);
    glVertex2f(125,225);
    glVertex2f(23,225);
    glEnd();
}
void black(int col1)
{
	drawCircle0(25,65,col1,25);
}
void black1(int col1)
{
	drawCircle0(350,150,col1,15);
}
void black2(int col1)
{
	drawCircle0(330,300,col1,25);
}
void blackw(int col1)
{
	drawCircle0(25,225,col1,25);
}
void cloud(int x,int y,int r)
{
	GLint i;
	glColor3f(0.000, 0.545, 0.545);
	glPointSize(0.5);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		glVertex2f(x+sin(i)*r,y+cos(i)*r);
	}
	glEnd();
}
void clouds(GLint xc,GLint yc,int r)
{
		cloud(xc,yc,r);
}
void Sbolt()
{
	glColor3f(0.000, 0.808, 0.820);
	glBegin(GL_POLYGON);
	glVertex2f(200,290);
	glVertex2f(210,290);
	glVertex2f(200,275);
	glVertex2f(190,275);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(195,275);
	glVertex2f(205,275);
	glVertex2f(195,260);
	glVertex2f(185,260);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(190,260);
	glVertex2f(200,260);
	glVertex2f(180,240);
	glEnd();
}
void Sclouds()
{
	Sbolt();
	cloud(200,260,15);
	cloud(180,265,15);
	cloud(190,275,15);
	cloud(220,265,15);
	cloud(210,275,15);
	cloud(68,185,5);
	cloud(65,180,5);
	cloud(73,178,5);
	cloud(110,178,5);
	cloud(118,180,5);
	cloud(115,185,5);
	cloud(185,230,3);
	cloud(200,235,3);
	cloud(170,240,3);
	cloud(215,230,3);
	cloud(225,240,3);
	cloud(200,220,3);
}
void SDisp2()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    //drawSun();
	glutTimerFunc(200,doFrame,0);
	 drawWindmill();
	 draw_text1(250,80,1,"DEFORESTATION");
	 glColor3f(1.0,1.0,1.0);
	draw_text1(270,390,1,"ACID RAIN");
	glPushMatrix();
	glTranslated(25,40,0);
	glScaled(1.3,1.3,0);
	Sclouds();
	Strl1(288,95,8);
	Sdanger2();
	Sdanger1();
	Strl1(315,110,8);
	Sdrum2();
	Sdrum1();
	Sdustbin();
	Strees();
	Sbase();
	glColor3f(0.0,0.0,0.0);
	   draw_text1(10,65,1,"DISPOSAL OF ");
    draw_text1(10,55,1,"BATTERIES ");
    	black(40);
	glColor3f(0.0,0.0,0.0);
	   draw_text1(340,145,1,"MINING");
black1(40);
	glColor3f(0.0,0.0,0.0);
	   draw_text1(305,300,1,"CONSTRUCTION OF ");
	   draw_text1(315,290,1,"  WINDMILLS");
black2(40);
	glColor3f(0.0,0.0,0.0);
	   draw_text1(5,225,1,"DUSTBIN WASTE");
blackw(40);
	Sbattery2();
	Sbattery1();
	Scircle();
	glPopMatrix();
	backdrop(7);
	if(sp)
	{
		sp=0;
		glutDisplayFunc(FinalPage);
	}
	glutPostRedisplay();
	glFlush();
}
void SDisp1()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    draw_text1(250,80,1,"FOREST");
	draw_text1(130,300,1,"DUSTBIN");
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glTranslated(25,40,0);
	glScaled(1.3,1.3,0);
	cloud(200,260,15);
	cloud(180,265,15);
	cloud(190,275,15);
	cloud(220,265,15);
	cloud(210,275,15);
	Sdanger1();//symbol
	Strl1(315,110,8);
	 draw_text1(305,85,1,"MINING");
	Sdrum1();
	Sdustbin();
	Strl(240,150,15);
	Strl(235,155,15);
	Strl(245,170,15);
	Strl(200,155,15);
	Strl(225,150,15);
	Strl(210,140,15);
	Strl(225,170,20);
	Strl(160,155,15);
	Strl(185,150,15);
	Strl(170,140,15);
	Strl(185,170,20);
	Strl(120,155,15);
	Strl(145,150,15);
	Strl(130,140,15);
	Strl(145,170,20);
	Strees();
	Sbase();
	glColor3f(1.0,0.0,0.0);
	draw_text1(70,65,1,"BATTERY");
	Sbattery1();
	Scircle();
	glPopMatrix();
	backdrop(37);
	if(sp)
	{
		sp=0;
		glutDisplayFunc(SDisp2);
	}
	glutPostRedisplay();
	glFlush();
}

void Smouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		sp=1;
	}
}

void Skeys(unsigned char key,int x,int y)
{
		if(key==27)
		{
			exit(0);
		}

		if(key==13 || key==32) //enter key value
		{
			sp=1;
		}
}

void firstpage_S()
{	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	PrintText(160,200,f4,17,"SOIL POLLUTION");
	backdrop1(5);
	if(sp)
	{
		sp=0;
		glutDisplayFunc(SDisp1);
	}
    glutPostRedisplay();
	glFlush();
}
void soilpollutioninit()
{
	glutDisplayFunc(firstpage_S);
	glutMouseFunc(Smouse);
	glutKeyboardFunc(Skeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}
/*<<<<<<<<-------------------------------------------------------MAIN WINDOW------------------------------------------>>>>>>>>>>*/

void reshape2(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void mkeys(unsigned char key,int x,int y)
{


		if( key==32) //enter key value
		{
			window1();
		}
}

void firstpage_M()
{ glClearColor(0.0,0.0,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
    loadintro();
   glutDisplayFunc(displayIntro);
   	glutKeyboardFunc(mkeys);
if(j)
{
j=0;
}
    glutPostRedisplay();
glFlush();
}
void FinalPage()
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
 loadintro1();
   glutDisplayFunc(displayIntro1);
glutPostRedisplay();
glFlush();
}

void FinalWindow()
{
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
win1=glutCreateWindow("win1");
glutReshapeFunc(reshape1);
glutDisplayFunc(FinalPage);
}
void MainWindowinit()
{
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutReshapeFunc(reshape1);
glutDisplayFunc(firstpage_M);//bit
glutMouseFunc(mouse);
glutKeyboardFunc(keys);
glEnable(GL_DEPTH_TEST);
glClearColor(0.0,0.0,0.0,1.0);
glutMainLoop();
}
void Introduction(GLint sizex,GLint sizey,GLint posx,GLint posy)
{
glutInitWindowSize(sizex,sizey);//420,900
glutInitWindowPosition(posx,posy);//474,0
win0=glutCreateWindow("INTRODUCTION");
MainWindowinit();
}
void window3()
{
	glutInitWindowSize(450,350);
	glutInitWindowPosition(0,340);
	win3=glutCreateWindow("Water Pollution");
		glutCreateMenu(main_menu);
backdrop1(5);
glutAddMenuEntry("Air pollution",1);
glutAddMenuEntry("Noise pollution",2);
glutAddMenuEntry("Water pollution",3);
glutAddMenuEntry("Soil pollution",4);
glutAddMenuEntry("Exit",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutReshapeFunc(reshape2);
	waterpollutioninit();
	glutMainLoop();
}
void start()
{
Introduction(500,500,0,0);
}
void window1()
{
	glutInitWindowSize(450,350);
	glutInitWindowPosition(0,0);
	win1=glutCreateWindow("Air Pollution");
	glutReshapeFunc(reshape1);
	airpollutioninit();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("Air pollution");
	glutDisplayFunc(start);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
	return 0;
}
