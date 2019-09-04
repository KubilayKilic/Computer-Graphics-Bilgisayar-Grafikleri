//
//
//
//	Yazar : Kubilay Kaan K�l�� 
//
//	��r No: 140-320-034
//
//	�nemli! ��renci no rakamlar� toplam� 017. Daha sonra kullan�lacakt�r.
//
//	Proje : Bilgisayar Grafikleri Dersi D�nem Projesi - II
//
//	A��klama : Bir GLUT penceresi olu�turur ve OpenGL ilkelleri ile birden fazla nesne �izer, nesneler a�a�� d��er.
//
//	Kullan�c� klavyesindeki ok tu�lar� ile alttaki �ubu�u hareket ettirebilir.
//
//	Kontrol ;
//	Sol ok - Sola D�nd�rme
//	Sa� ok - Sa�a D�nd�rme
//	�st ok - Yukar� D�nd�rme
//	Alt ok - A�a�� D�nd�rme

// ----------------------------------------------------------
// Eklenen K�t�phaneler
// ----------------------------------------------------------
#include <GL/glut.h>
#include <stdlib.h>
#include <random>
#include <iostream>
#include <cmath>
#include <gl/glut.h>

using namespace std;

// ----------------------------------------------------------
// Global De�i�kenler
// ----------------------------------------------------------
double dondury, ucgeny = 45;
double dondurx, ucgenx = 45;
double ytranslate = 1.02;
double ytranslate2 = 1.11;
double ytranslate3 = 1.07;
double ytranslate4 = 1.23;

double a1 = 0.0;
double c1 = 0.0;
double a, b;
double klavyex = 0;
double klavyey = -0.8;
int i;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(3.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 600.0, 0.0, 900);

}

// nesnelerin ekrandan ��kt�ktan sonra tekrar ekrana gelmesi i�in kullan�lan fonksiyon
void tekrar() {
	if (ytranslate < -1.1) {
		ytranslate = 1.02;
	}
	if (ytranslate2 < -1.1) {
		ytranslate2 = 1.11;
	}
	if (ytranslate3 < -1.1) {
		ytranslate3 = 1.07;
	}
	if (ytranslate4 < -1.1) {
		ytranslate4 = 1.23;
	}

}

void calculate() {
	dondurx += 0.5;
	dondury += -0.5;
	ucgeny += 0.4;
	ucgenx += 0.4;
	a1 += 0.005;
	c1 += 0.01;
	ytranslate = ytranslate - 0.005;
	ytranslate2 = ytranslate2 - 0.007;
	ytranslate3 = ytranslate3 - 0.003;
	ytranslate4 = ytranslate4 - 0.004;

}

// ----------------------------------------------------------
// display() Callback Fonksiyonu
// ----------------------------------------------------------

void display() {
	calculate();
	tekrar();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// D�nd�rmeleri s�f�rlama
	glLoadIdentity();
	glTranslated(0.0, ytranslate, -0.05);
	// rotate_x ve rotate_y De�i�kenlerine Ba�l� Olarak D�nd�rme Hareketi
	glRotatef(dondurx, 1.0, 0.0, 0.0);
	glRotatef(dondury, 0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.4, 0.0);
	glVertex3f(0.05, -0.05, -0.05);
	glColor3f(0.3, 0.2, 0.0);
	glVertex3f(0.05, 0.05, -0.05);
	glColor3f(0.0, 0.3, 0.4);
	glVertex3f(-0.05, 0.05, -0.05);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.05, -0.05, -0.05);
	glEnd();
	// 2
	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.4, 0.0); //��renci no 140
	glVertex3f(0.05, -0.05, 0.05);
	glVertex3f(0.05, 0.05, 0.05);
	glVertex3f(-0.05, 0.05, 0.05);
	glVertex3f(-0.05, -0.05, 0.05);
	glEnd();
	// 3.
	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.2, 0.0); // �p�renci no 320
	glVertex3f(0.05, -0.05, -0.05);
	glVertex3f(0.05, 0.05, -0.05);
	glVertex3f(0.05, 0.05, 0.05);
	glVertex3f(0.05, -0.05, 0.05);
	glEnd();
	// 4. 
	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.3, 0.4);	// �p�renci no 034
	glVertex3f(-0.05, -0.05, 0.05);
	glVertex3f(-0.05, 0.05, 0.05);
	glVertex3f(-0.05, 0.05, -0.05);
	glVertex3f(-0.05, -0.05, -0.05);
	glEnd();
	// 5. 
	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.4, 1.0);	// �p�renci no 140
	glVertex3f(0.05, 0.05, 0.05);
	glVertex3f(0.05, 0.05, -0.05);
	glVertex3f(-0.05, 0.05, -0.05);
	glVertex3f(-0.05, 0.05, 0.05);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.2, 0.0);	// �p�renci no 320
	glVertex3f(0.05, -0.05, -0.05);
	glVertex3f(0.05, -0.05, 0.05);
	glVertex3f(-0.05, -0.05, 0.05);
	glVertex3f(-0.05, -0.05, -0.05);
	glEnd();

	glLoadIdentity();
	glTranslated(0.2, ytranslate4, -0.2);
	glRotatef(-dondurx, 1.0, 0.0, 0.0);
	glRotatef(-dondury, 0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 1.0); glVertex3f(0.05, -0.05, -0.05);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0.05, 0.05, -0.05);
	glColor3f(1.0, 0.0, 1.0); glVertex3f(-0.05, 0.05, -0.05);
	glColor3f(1.0, 0.0, 1.0); glVertex3f(-0.05, -0.05, -0.05);
	glEnd();
	// 2. 
	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.3, 0.4);	// �p�renci no 034
	glVertex3f(0.05, -0.05, 0.05);
	glVertex3f(0.05, 0.05, 0.05);
	glVertex3f(-0.05, 0.05, 0.05);
	glVertex3f(-0.05, -0.05, 0.05);
	glEnd();
	// 3. 
	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.4, 0.0);	// �p�renci no 140
	glVertex3f(0.05, -0.05, -0.05);
	glVertex3f(0.05, 0.05, -0.05);
	glVertex3f(0.05, 0.05, 0.05);
	glVertex3f(0.05, -0.05, 0.05);
	glEnd();
	// 4.
	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.2, 0.0);	// �p�renci no 320
	glVertex3f(-0.05, -0.05, 0.05);
	glVertex3f(-0.05, 0.05, 0.05);
	glVertex3f(-0.05, 0.05, -0.05);
	glVertex3f(-0.05, -0.05, -0.05);
	glEnd();
	// 5. K�p�n Mavi Renkli �ST Y�z�
	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.3, 0.4);	// �p�renci no 034
	glVertex3f(0.05, 0.05, 0.05);
	glVertex3f(0.05, 0.05, -0.05);
	glVertex3f(-0.05, 0.05, -0.05);
	glVertex3f(-0.05, 0.05, 0.05);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.1, 0.7);	// �p�renci no rakamlar� toplam� 017
	glVertex3f(0.05, -0.05, -0.05);
	glVertex3f(0.05, -0.05, 0.05);
	glVertex3f(-0.05, -0.05, 0.05);
	glVertex3f(-0.05, -0.05, -0.05);
	glEnd();

	/*�UBUK*/
	glLoadIdentity();

	glTranslated(klavyex, klavyey, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 1.0);
	glVertex3f(0.2, -0.02, -0.05);
	glVertex3f(0.2, 0.02, -0.05);
	glVertex3f(-0.2, 0.02, -0.05);
	glVertex3f(-0.2, -0.02, -0.05);
	glEnd();

	glLoadIdentity();

	/* if (a1 > 1) { // E�er bu kod �al��t�r�l�r ise ��gen prizmalardan bir tanesi sa� ekran penceresinin sa� taraf�na �arp�p sola do�ru hareket edecektir.
		glTranslated(2 - a1, ytranslate3, 0.01f);
	}
	else if (a1 > 0.0f)

		glTranslated(0.0f + a1  , ytranslate3, 0.01f);


	else { glTranslated(a1, ytranslate3, 0.01f); }

	*/
	glTranslated(0, ytranslate3, 0.01f);



	glRotatef(-ucgenx, 1.0, 0.0, 0.0);
	glRotatef(-ucgeny, 0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
	   // Front
	glColor3f(0.1f, 0.4f, 0.0f);	// �p�renci no 140
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);

	// Right
	glColor3f(0.3f, 0.2f, 0.0f);	// �p�renci no 320
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(0.05f, -0.05f, 0.05f);
	glVertex3f(0.05f, -0.05f, -0.05f);

	// Back
	glColor3f(0.0f, 0.3f, 0.4f);    // �p�renci no 034
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);

	// Left
	glColor3f(0.0f, 0.1f, 0.7f);	// �p�renci no rakamlar� toplam� 017
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(-0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glEnd();



	glLoadIdentity();
	glTranslatef(-0.5f, ytranslate2, 0.01f);  // Move left and into the screen
	glRotatef(ucgenx, 1.0, 0.0, 0.0);
	glRotatef(ucgeny, 0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLES);	//piramit �izimi
	   // Front
	glColor3f(0.1f, 0.4f, 0.0f); // �p�renci no 140
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glVertex3f(0.05f, -0.05f, 0.05f);

	// Right
	glColor3f(0.3f, 0.2f, 0.0f);	// �p�renci no 320 
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(0.05f, -0.05f, 0.05f);
	glVertex3f(0.05f, -0.05f, -0.05f);

	// Back
	glColor3f(0.0f, 0.3f, 0.4f);	// �p�renci no 034
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, -0.05f);

	// Left
	glColor3f(0.0f, 0.1f, 0.7f);	// �p�renci no rakamlar� toplam� 017
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(-0.05f, -0.05f, -0.05f);
	glVertex3f(-0.05f, -0.05f, 0.05f);
	glEnd();

	// ekrana g�sterme ve bufferlar� de�i�tirme
	glFlush();
	glutSwapBuffers();

}
// ----------------------------------------------------------
// specialKeys() Callback Fonksiyonu
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT)
		klavyex += 0.015;	// Sa� Ok Tu�u 
	else if (key == GLUT_KEY_LEFT)
		klavyex -= 0.015;	// Sol Ok Tu�u 
	else if (key == GLUT_KEY_UP)
		klavyey += 0.015;	// Yukar� Ok Tu�u
	else if (key == GLUT_KEY_DOWN)
		klavyey -= 0.015;	//A�a�� Ok Tu�u
	glutPostRedisplay();	// G�r�nt� g�ncellenmesini talep eder
}
// ----------------------------------------------------------
// Timer() Fonksiyonu
// ----------------------------------------------------------
void Timer(int value) {
	glutTimerFunc(1000 / 60, Timer, value);
	glutPostRedisplay();
}
// ----------------------------------------------------------
// main() Fonksiyonu
// ----------------------------------------------------------
int main(int argc, char** argv) {
	// GLUT penceresi ilklendirme
	glutInit(&argc, argv);

	// �ift Buffer ile RGB format�nda renklendirilmi� Derinlik destekli GLUT penceresi
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);


	// Pencere Boyutlar�
	glutInitWindowSize(600, 900);

	// Pencere Olu�turma
	glutCreateWindow("Kbly-proje2");

	glEnable(GL_DEPTH_TEST);
	init();
	Timer(0);

	// Callback fonksiyonlar�
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	// GLUT �evrimine girer
	glutMainLoop();
	return 0;
}