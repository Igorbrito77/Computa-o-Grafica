
#include <stdio.h>
#include <GL/glut.h>

void teclado(unsigned char , int , int);
void init();
void remodelar(int, int);
void display();

bool tela_cheia = false;
int largura_tela = 800;
int altura_tela = 800;

int main(int argc, char **argv)
{	
	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (largura_tela, altura_tela);
	glutInitWindowPosition (100, 100);

	glutCreateWindow ("Game Test");

	init();

	glutDisplayFunc(display);

	glutReshapeFunc(remodelar);
	glutKeyboardFunc(teclado);

	glutMainLoop();

	
	return 0;
}



void init(){

   glClearColor (0.0, 0.0, 0.0, 0.0); // seleciona cor de fundo preta

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //define uma matriz de projeção ortogonal 2D

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void display(){

   glClear (GL_COLOR_BUFFER_BIT);

   glBegin(GL_POLYGON);

   		glColor3f(0.0, 0.0, 1.0);
     	glVertex3f(-1.0, 1.0, 0.0);

     	glColor3f(0.5, 0.5, 0.5);
     	glVertex3f(1.0, -1.0, 0.0);

     	glColor3f(1.0, 0.0, 1.0);
     	glVertex3f(-1.0, -1.0, 0.0);

	    glColor3f (0.0, 1.0, 0.0);
	    glVertex3f (1.0, 1.0, 0.0);
    

   glEnd();


   glutSwapBuffers ();
}

void remodelar(int largura, int altura){

	if(!tela_cheia){
		largura_tela = largura;
		altura_tela = altura;
	}

	glViewport (0, 0, (GLsizei) largura, (GLsizei) altura);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    if (largura <= altura)
        glOrtho (-1, 1, -1*(GLfloat)altura/(GLfloat)largura, 1*(GLfloat)altura/(GLfloat)largura, -10.0, 10.0);
    else
        glOrtho (-1*(GLfloat)largura/(GLfloat)altura, 1*(GLfloat)largura/(GLfloat)altura, -1, 1, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void teclado(unsigned char tecla, int x, int y){

	switch(tecla){
		case 27:
			exit(0);
		break;

		case 'f':
			tela_cheia = !tela_cheia;
			if(tela_cheia)
				glutFullScreen();
			else
				glutReshapeWindow(largura_tela, altura_tela);
		break;
	}

}
