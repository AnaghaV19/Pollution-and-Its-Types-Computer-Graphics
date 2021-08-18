#include <math.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

int treeSeed = 0;
float branchAngle = .2618;

//void GroworShrink()
//{
//
//	if(treeSeed <=10 && treeSeed != 0)
//	{
//		int i;
//		for(i = 0; i <=10 ; i++)
//		{
//
//
//
//
//		}
//
//	}

	//else

//}


//void treeAninmation()
//{
//
//	glutPostRedisplay();
//}


/*
	Draws a leaf on the branch.
	If the seed axiom is at zero,
	a new leaf is drawn. Otherwise,
	the branch shrinks to accomodate
	existing leaves.


*/

void DrawLeaf()
{


	if(treeSeed==0)
	{
		glBegin(GL_QUADS);
		glColor3f(0.0f,1.0f,0.0f);

		glVertex2f(-0.05, -40.5);
		glVertex2f(-0.05, -20.5);
		glVertex2f(-0.02, -40.5);
		glVertex2f(-0.02,-20.5);

	}
	/*else
	{

		GroworShrink();
		DrawTwig(treeSeed-1);
		glPushMatrix();
				glRotate(branchAngle,1.0f,0.0f,0.0f);
				DrawLeaf(treeSeed-1);
		glPopMatrix();
		glPushMatrix();
				glRotate(branchAngle, );
				DrawLeaf(treeSeed-1);
		glPopMatrix();
	}*/

}


void DrawTwig()
{

	/*

		Draws trunk of tree
		Represents base scenario of
		recursion

	*/
	if(treeSeed==0)
	{

		glLineWidth(5.0);

 		glBegin(GL_LINE_STRIP);

		glColor3f(0.60f,0.40f,0.12f);

		glVertex2f(-0.10, -80.5);
		glVertex2f(-0.10, -100.5);

		glEnd();

	}

	/*else
	{

		GroworShrink();
		DrawTwig(treeSeed-1);

	}*/
}



/* Draws the tree with leaves *
	Uses recursion to draw tree structure
	Relies on L-System formula in order
	to produce a tree

*/

void DrawTree()
{

	DrawTwig(treeSeed);
	//DrawLeaf(treeSeed);


}




/* Draws the horizon, the sky, and the ground*/

void RenderScene(void)
{
	// clears color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	/*
	//GLfloat y;
	GLfloat fSizes[2]; // Store supported line width range
	GLfloat size;  // Store supported line width increments
	*/

	//The horizon lies in the xy plane

	glBegin(GL_LINE_STRIP);

	glColor3f(0.0f,0.0f,0.0f); //sets color of horizon to black
	glVertex2f(-135.0,0.0);
	glVertex2f(135.0,0.0);

	glEnd();

	//The sky lies in the xy plane
	//Starts at horizon line,
	//goes upwards to height edge of screen,
	//and goes rightwards to width edge of screen.


	glBegin(GL_QUADS);

	glColor3f(0.0f,0.0f,1.0f);

	glVertex2f(135.0, 0.0);
	glVertex2f(-135.0, 0.0);
	glVertex2f(-135.0, 100.0);
	glVertex2f(135.0,100.0);


	glEnd();

	DrawTree();

	glFlush();

}


void SetupRC(void)
{

	glClearColor(1.0f,1.0f,1.0f,1.0f);

}


void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;

	//prevents divison by zero
	if(h ==0)
		h = 1;

	//set Viewport to window dimensions
	glViewport(0,0,w,h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right,bottom,top,near,far

	aspectRatio = (GLfloat)w/(GLfloat)h;

	if (w <= h)
		glOrtho (-100.0, 100.0, -100/aspectRatio, 100/aspectRatio,1.0,-1.0);
	else
		glOrtho (-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);

/* Testing basic display functions for now */

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("falling leaves");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
	//glutIdleFunc(treeAnimation);
	//glutDisplayFunc(DrawTree);
	SetupRC();
    glutMainLoop();
}
