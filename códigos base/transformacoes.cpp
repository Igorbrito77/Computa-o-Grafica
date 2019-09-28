#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angulo = 0;
float escala = 1.0;

float x = 0, y = 0, z = 0;

bool habilitarMenu = false;

bool tela_cheia = false;
int largura_tela = 800;
int altura_tela = 800;


void init();
void display();
void exibe_menu();
void mouse(int, int, int, int);
void teclado(unsigned char, int, int);

int main(int argc, char ** argv){

	glutInit(&argc, argv); //inicializa a biblioteca CLUT
   	glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB); //parâmetros iniciais de display
   	glutInitWindowSize(altura_tela, largura_tela); //define o tamanho da janela
	glutInitWindowPosition (100, 100); // posição da janela na tela
	glutCreateWindow ("Transformacoes C.G"); //cria a janela principal

	init();

	glutDisplayFunc(display);

	glutMouseFunc( mouse );
	glutKeyboardFunc(teclado);


	glutMainLoop();// mantém a janela aberta 


	return 0;
}


void desenhaEixos()
{
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_LINES);
      glVertex2f (0.0, -100.0);
      glVertex2f (0.0, 100.0);
      glVertex2f (-100.0, 0.0);
      glVertex2f (100.0, 0.0);
   glEnd();
}



void display(){

	// Limpar todos os pixels
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Inicializa com matriz identidade

	desenhaEixos();

	glColor3f (0.5, 1.0, 0.0);

	glPushMatrix();
	  glTranslatef(x, y, 0);
	  glRotatef(angulo, 0.0, 0.0, 1.0);
	  glScalef(escala, escala, escala);
	  glutWireCube(35); //desenha um cubo na tela
	glPopMatrix();

	glutSwapBuffers ();//atualiza a janela 
	glutPostRedisplay();

	//if(habilitarMenu) exibe_menu();

}

// Mouse callback
void mouse(int botao, int estado, int x, int y)
{
   if ( botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
      habilitarMenu = 1;
}


void teclado(unsigned char tecla, int x_, int y_){

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
		case 'd':
			x+= 1;
			break;
		case 'w':
			y+= 1;
			break;
		case 'a':
			x-= 1;
			break;
		case 's':
			y-= 1;
			break;
		case '+':
			escala +=1;
			break;
		case '-':
			escala -=1;
			break;
		case 'r':
			angulo +=1;
			break;
		case 'R': // shift + r 
			angulo -=1;
			break;
	}

}



void init(){

   glClearColor (0.5, 0.0, 0.0, 0.0); // seleciona cor de fundo (red, grenn, blue)

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0); //define uma matriz de projeção ortogonal 2D

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}