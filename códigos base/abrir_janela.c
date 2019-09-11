#include <GL/glut.h>
#include <math.h>

int main(int argc, char** argv){

	glutInit(&argc, argv); //inicializa a biblioteca CLUT
   	glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB); //parâmetros iniciais de display
   	glutInitWindowSize(250,250); //define o tamanho da janela
	glutInitWindowPosition (100, 100); // posição da janela na tela
	glutCreateWindow ("Abrindo uma Janela..."); //cria a janela principal
	glutMainLoop();// mantém a janela aberta 

	return 0;
}
