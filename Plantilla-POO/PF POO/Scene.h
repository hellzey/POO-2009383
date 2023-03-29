#ifndef __Escena
#define __Escena

#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terrain.h"
#include "Model.h"
#include "Water.h"
#include "Billboard.h"
#include "Fog.h"
#include "Camera.h"
#include <string>
#define BILLSIZE 50

//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO
	int rotacioncard = 0;
	bool rotacion = false;
	int rutaav = 0;
	bool rutaavion = false;
	float expandir = 0.1f;

class Scene : public Camera
{
public:

	HWND hWnd = 0;
	
	bool actex=false;

	short int skyIndex, lightIndex;
	float skyRotation;
	int avionrot;
	SkyDome *skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//Slide2.jpg");
	Terrain *terrain;
	Water *lago;
	GLfloat AmbMat[4] = { 255, 255, 220, 1 };

	/*EDXFramework::Model  *PC; */
	EDXFramework::Model *card;
	EDXFramework::Model *jack;
	EDXFramework::Model *loki;
	EDXFramework::Model* avion;
	EDXFramework::Model* arbol1;
	//EDXFramework::Model* arbol2;
	EDXFramework::Model* arbol3;
	EDXFramework::Model* mariposa;
	EDXFramework::Model* casa;
	EDXFramework::Model* casa2;
	EDXFramework::Model* casa3;
	EDXFramework::Model* ayu;
	EDXFramework::Model* puente;
	EDXFramework::Model* castelo;
	EDXFramework::Model* edificio;
	EDXFramework::Model* pajaro;
	Billboard *billBoard[BILLSIZE];
	

	Scene(HWND hWnd)
	{
		this->hWnd = hWnd;
		skyIndex = lightIndex, skyRotation = 0;
		
		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);

		//lago = Pista, busca en sus constructores para poder crear un lago.

		terrain = new Terrain(hWnd, L"Imagenes//terreno2.bmp", L"Imagenes//pasto.jpg", L"Imagenes//pasto.jpg", 512, 512);
	/*	PC = new EDXFramework::Model("Modelos//Laptop//laptop1.obj", "Modelos//Laptop//laptop.bmp", 1);*/
		jack=new EDXFramework::Model("Modelos//jack//untitled.obj", "Modelos//jack//jack.bmp", 1);
		card= new EDXFramework::Model("Modelos//card//card.obj", "Modelos//card//card.bmp", 1);
		loki = new EDXFramework::Model("Modelos//loki//loki.obj", "Modelos//loki//loki.bmp", 1);
		avion = new EDXFramework::Model("Modelos//avion//avion.obj", "Modelos//avion//avion.bmp", 1);
		arbol1 = new EDXFramework::Model("Modelos//arbol//arbol.obj", "Modelos//arbol//verde.bmp", 1);
	/*	arbol2 = new EDXFramework::Model("Modelos//arbol2//arbol2.obj", "Modelos//arbol2//hojas2.bmp", 1);*/
		arbol3 = new EDXFramework::Model("Modelos//arbol//arbol.obj", "Modelos//arbol//rosa.bmp", 1);
		mariposa = new EDXFramework::Model("Modelos//mariposa//mariposa.obj", "Modelos//mariposa//mariposa.bmp", 1);
		casa= new EDXFramework::Model("Modelos//casa1//casa.obj", "Modelos//casa1//casa.bmp", 1);
		casa2 = new EDXFramework::Model("Modelos//casa2//casa2.obj", "Modelos//casa2//casa2.2.bmp", 1);
		casa3 = new EDXFramework::Model("Modelos//casa3//casa3.obj", "Modelos//casa3//casa3.bmp", 1);
		ayu= new EDXFramework::Model("Modelos//ayu//ayu.obj", "Modelos//ayu//ayu.bmp", 1);
		puente= new EDXFramework::Model("Modelos//puente//puente.obj", "Modelos//puente//puente.bmp", 1);
		castelo = new EDXFramework::Model("Modelos//castelo//castelo.obj", "Modelos//castelo//castelo.bmp", 1);
		edificio = new EDXFramework::Model("Modelos//edificio//edificio.obj", "Modelos//edificio//edificio.bmp", 1);
		pajaro = new EDXFramework::Model("Modelos//pajaro//pajaro.obj", "Modelos//pajaro//pajaro.bmp", 1);
		Billboards(billBoard, hWnd);

		cameraInitialize();
	}

	void Billboards(Billboard *bills[], HWND hWnd)
	{
		//Aqui puedes crear algo util con un FOR quiza.

		/*for (int i = 0; i < ; i++)
		{

		}*/
	}
	

	void render(HDC hDC)
	{

		if (rotacion==false)
		{
			rotacioncard++;
			if (rotacioncard==360)
			{
				rotacion = true;
			}
		}

		if (rotacion == true)
		{
			rotacioncard--;
			if (rotacioncard == 0)
			{
				rotacion = false;
			}
		}



		if (rutaavion == false)
		{
			rutaav++;
			if (rutaav == 100)
			{
				rutaavion = true;
			}
		}

		if (rutaavion == true)
		{
			rutaav--;
			if (rutaav == -100)
			{
				rutaavion = false;
			}
		}
	


		if (actex == false)
		{
			expandir +=0.001f;
			if (expandir >=0.2f)
			{
				actex = true;
			}
		}



		if (actex == true)
		{
			expandir -= 0.001f;
			if (expandir<= 0.1f)
			{
				actex = false;
			}
		}










		avionrot < 360 ? avionrot += 1 : avionrot = 0;
	
		skyRotation < 360 ? skyRotation +=0.1f : skyRotation = 0;

		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		GLfloat AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
		py = terrain->Superficie(px, pz) * 4 + 6;

		cameraUpdate();

		//Skydome
		glPushMatrix();
			glTranslatef(0, 8, 0);
			glRotatef(skyRotation, 0, 1, 0);
			skyDome->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
			glScalef(1, 4, 1);
			terrain->Draw();
		glPopMatrix();

		//PC
		/*glPushMatrix();
			glTranslatef(0, 30.0f, -110);			
			PC->Draw();
		glPopMatrix();*/


		//jack
		glPushMatrix();
		glTranslatef(0, 37.0f, -110);
		glScalef(.05, .05, .05);
		jack->Draw();
		glPopMatrix();

		
		//card
		glPushMatrix();
		glTranslatef(80, 40.0f, 0);
		glRotated(90,90,0,0);
		glRotated(rotacioncard,0,0, rotacioncard);
		glScalef(expandir, expandir, expandir);
		card->Draw();
		glPopMatrix();



		//avion
	
		glPushMatrix();
		glTranslatef(rutaav, 150.0f, 0);
		glScalef(10, 10, 10);
		glRotatef(avionrot, 0, 1, 0);
	
		
		avion->Draw();
		glPopMatrix();



		/*glPushMatrix();
		glTranslatef(0, 150.0f, 0);
		glScalef(10, 10, 10);
		glRotatef()
		avion->Draw();
		glPopMatrix();*/

		//loki

		glPushMatrix();
		glTranslatef(-10, 40.0f, -110);
		glScalef(.05, .05, .05); 
		loki->Draw();
		glPopMatrix();


		//arbol
		glPushMatrix();
		glTranslatef(180, 36,-35);
		glScalef(10, 10,10);
		arbol1->Draw();
		glPopMatrix();


		glPushMatrix();
		glTranslatef(180, 36, 35);
		glScalef(10, 10, 10);
		arbol1->Draw();
		glPopMatrix();


		glPushMatrix();
		glTranslatef(95, 36, 80);
		glScalef(10, 10, 10);
		arbol1->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(40, 36, - 70);
		glScalef(10, 10, 10);
		arbol1->Draw();
		glPopMatrix();




		//arbol2
	/*	glPushMatrix();
		glTranslatef(-10, 20.0f, -80);

		arbol2->Draw();
		glPopMatrix();*/

//arbol3
		glPushMatrix();
		glTranslatef(100, 36.0f, 0);
		glScalef(10, 10, 10);
		arbol3->Draw();
		glPopMatrix();







		//mariposa

		glPushMatrix();
		glTranslatef(px, 50.0f, pz);
		glRotatef(avionrot,1,1,1);
		mariposa->Draw();
		glPopMatrix();



		//casa
		glPushMatrix();
		glTranslatef(150, 36.0f, -60);
		glRotated(340, 0, 340, 0);
		glScaled(6, 6, 6);
		casa->Draw();
		glPopMatrix();

		//casa2
		glPushMatrix();
		glTranslatef(110,33.5f,-70);
		glScaled(5.9, 5.9,5.9);
		casa2->Draw();
		glPopMatrix();

		//casa3
		glPushMatrix();
		glTranslatef(70, 36, -70);
		glScaled(2, 2,2);
		glRotated(180,0,180,0);
		casa3->Draw();
		glPopMatrix();

		//ayu

		glPushMatrix();
		glTranslatef(170, 37.0f, 80);
		glRotated(110, 0,110,0);
		glScaled(2, 2, 2);
		ayu->Draw();
		glPopMatrix();
		//puente

		glPushMatrix();
		glTranslatef(0, 40.0f, 100);
		puente->Draw();
		glPopMatrix();



		//castelo
		glPushMatrix();
		glTranslatef( 220, 36.0f, 240);
		glRotated(180,0,90,0);
		glScalef(3,3,3);
		castelo->Draw();
		glPopMatrix();


		//pajaro
		glPushMatrix();
		glTranslatef(200, 90.0f, 0);
		glScalef(.1, .1, .1);
		glRotated(270, 0, 270, 0);
		pajaro->Draw();
		glPopMatrix();


		glPushMatrix();
		glTranslatef(200, 95.0f, 7);
		glScalef(.1, .1, .1);
		glRotated(270, 0, 270, 0);
		pajaro->Draw();
		glPopMatrix();


		glPushMatrix();
		glTranslatef(200, 95.0f, -7);
		glScalef(.1, .1, .1);
		glRotated(270, 0, 270, 0);
		pajaro->Draw();
		glPopMatrix();

		//edificio
		glPushMatrix();
		glTranslatef(120, 36.0f, 80);
		glRotated(90,0 , 90, 0);
		glScalef(2, 2, 2);
		edificio->Draw();
		glPopMatrix();

		


		glPushMatrix();
		for (int i = 0; i < BILLSIZE; i++)
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.
		glPopMatrix();


		SwapBuffers(hDC);
		
	}

	~Scene()
	{
		//NO OLVIDES PONER AQUI TODOS TUS PUNTEROS
		delete skyDome;
		/*delete PC;*/
		delete card;
		delete jack;
		delete loki;
		delete arbol1;
	/*	delete arbol2;*/
		delete arbol3;
		delete mariposa;
		delete casa;
		delete casa2;
		delete casa3;
		delete edificio;
		delete castelo;
		delete puente;
		delete ayu;
		delete avion;
		delete pajaro;
	}
};
#endif
