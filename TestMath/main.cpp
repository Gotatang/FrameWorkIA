/*Documentation							*/
/*@author	:	Quentin Ladevie			*/
/*@file		:	main.cpp				*/
/*@date		:	19/11/2015				*/
/*@brief	:	Main de la LibMath		*/
#include "stdafx.h"

using namespace DadEngine;

typedef void(*ptrFonctionEtat) (void);

#define GRAPHIC_TEST // GRAPHIC_TEST || CONSOLE_TEST


enum STATES // Etats de jeu
{
	SHUTDOWN,
	TESTPOINT2,
	TESTPOINT3,
	TESTVECTOR2,
	TESTVECTOR3,
	TESTVECTOR4,
	TESTTRIANGLE2,
	TESTTRIANGLE3,
	TESTVECTOR,
	TESTMATRIX22,
	TESTMATRIX33,
	TESTMATRIX44,
	TESTTRANSFORM,
	TESTCIRCLE,
	TESTRECTANGLE,
	TESTPOLYGON2,
	TESTBOX,
	TESTSPHERE,
	TESTPOLYGON3,
	MENU,
	MAXSTATES,
};


// Variables globales

bool bRunning = true;
sf::RenderWindow* wnd = NULL;


unsigned char ucCurrentState = MENU;
ptrFonctionEtat ptrAGamestates[STATES::MAXSTATES];



void _displayMenu();
void _displaySousMenu();


void _TestPoint2();
void _TestPoint3();
void _TestVector2();
void _TestVector3();
void _TestVector4();
void _TestTriangle2();
void _TestTriangle3();
void _TestVector();
void _TestMatrix22();
void _TestMatrix33();
void _TestMatrix44();
void _TestTransform();
void _TestCircle();
void _TestRectangle();
void _TestPolygon2();
void _TestBox();
void _TestSphere();
void _TestPolygon3();


void _Initialisation();
void _Boucle();
void _Delete();


void _shutdown();
void _choixOption(unsigned char _ucOptionsMaximumDispo);


int main(int argc, char* argv[])
{
	_Initialisation();
	_Boucle();
	_Delete();

	return 0;
}


void _displayMenu()
{
	cout << ">> Menu :" << endl << endl;

	cout << "\t1 - Teste unitaire Point2" << endl << endl;
	cout << "\t2 - Teste unitaire Point3" << endl << endl;
	cout << "\t3 - Teste unitaire Vector2" << endl << endl;
	cout << "\t4 - Teste unitaire Vector3" << endl << endl;
	cout << "\t5 - Teste unitaire Vector4" << endl << endl;
	cout << "\t6 - Teste unitaire Triangle2" << endl << endl;
	cout << "\t7 - Teste unitaire Triangle3" << endl << endl;
	cout << "\t8 - Teste unitaire Vector" << endl << endl;
	cout << "\t9 - Teste unitaire Matrice22" << endl << endl;
	cout << "\t10 - Teste unitaire Matrice33" << endl << endl;
	cout << "\t11 - Teste unitaire Matrice44" << endl << endl;
	cout << "\t12 - Teste unitaire Transform" << endl << endl;
	cout << "\t13 - Teste unitaire Cercle" << endl << endl;
	cout << "\t14 - Teste unitaire Rectangle" << endl << endl;
	cout << "\t15 - Teste unitaire Polygon2" << endl << endl;
	cout << "\t16 - Teste unitaire Cube" << endl << endl;
	cout << "\t17 - Teste unitaire Sphere" << endl << endl;
	cout << "\t18 - Teste unitaire Polygon3" << endl << endl;
	cout << "\t0 - Quitter" << endl << endl << endl;

	_choixOption(19);

	system("cls");
}

void _displaySousMenu()
{
	std::locale::global(std::locale(""));

	cout << "19 - Retour au menu" << endl << endl;
	cout << "0 - Quitter" << endl << endl << endl;

	_choixOption(20);

	system("cls");
}


void _TestPoint2()
{
	// cin.sync() & cin.clear() pour securiser le cin

	Point2 point2Test;
	Point2 tempPoint;
	Point2 lerpResult;
	Point2 newPoint2;
	float fX, fY;
	float fCoef;

	cout << ">> Test unitaire Point2 :" << endl << endl << endl;

	cout << "Entrez une valeur en X puis en Y :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;

	cout << endl;

	point2Test = Point2(fX, fY);

	cout << "Le point crée est :" << endl << endl;

	point2Test.Display();


	// Translate
	cout << endl << "Entrez une valeur de déplacement en X puis en Y :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;

	cout << endl;


	tempPoint = point2Test;

	cout << "Le point avant déplacement est :" << endl << endl;

	tempPoint.Display();

	tempPoint.Translate(fX, fY);

	cout << "Le point après déplacement est :" << endl << endl;

	tempPoint.Display();

	// LERP
	cout << endl << "Entrez des valeurs pour le point à interpoler :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;

	cout << endl;

	cout << endl << "Entrez le coeficient d'interpolation (entre 0 et 1) :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fCoef;

	cout << endl;


	tempPoint.SetX(fX);
	tempPoint.SetX(fY);

	lerpResult = point2Test.Lerp(tempPoint, fmodf(fCoef, 1.f));

	cout << "Le résultat de l'interpolation du point " << endl << endl;

	point2Test.Display();

	cout << " et du point " << endl << endl;

	tempPoint.Display();

	cout << " par le coefficient " << fCoef << " est " << endl << endl;

	lerpResult.Display();


	// Operateurs
	// Flux
	cout << "Operateurs : " << endl << endl << endl;
	cout << "Operateurs de flux : " << endl << endl;
	cout << "Création d'un nouveau point 2 dimension " << endl << endl;
	cin >> newPoint2;

	cout << "Vous avez crée le point :" << endl;
	cout << newPoint2;


	// Multiplicatio externe
	cout << "Operateurs de multiplication externe : " << endl << endl;

	cout << "Le point " << newPoint2 << " multiplier par " << 3 << " donne le point " << 3 * newPoint2 << endl << endl;
	point2Test = 3 * newPoint2;


	// Comparaison
	cout << "Operateurs de comparaison : " << endl << endl;

	cout << "Le point " << point2Test << " est " << ((point2Test == newPoint2) ? (" similaire ") : (" différent ")) << " au point" << newPoint2 << endl << endl;
	cout << "Le point " << point2Test << " est " << ((point2Test != newPoint2) ? (" différent ") : (" similaire ")) << " au point" << newPoint2 << endl << endl;


	// Unaire
	cout << "Operateurs unaire : " << endl << endl;

	cout << "Le vecteur est " << +point2Test;
	cout << "Le vecteur " << point2Test << " sous forme négative est " << -point2Test;


	// Binaire sans affectation
	cout << "Operateurs binaire sans affectation : " << endl << endl;

	cout << "Le point " << point2Test << " + " << newPoint2 << " donne le point " << point2Test + newPoint2 << endl << endl;
	point2Test = point2Test + newPoint2;

	cout << "Le point " << point2Test << " - " << newPoint2 << " donne le point " << point2Test - newPoint2 << endl << endl;
	point2Test = point2Test - newPoint2;

	cout << "Le point " << point2Test << " * 5 donne le point " << point2Test * 5 << endl << endl;
	point2Test = point2Test * 5;

	cout << "Le point " << point2Test << " / 7 donne le point " << point2Test / 7 << endl << endl;
	point2Test = point2Test / 7;


	// Binaire avec affectation
	cout << "Operateurs binaire avec affectation : " << endl << endl;

	cout << "Le point " << point2Test << " + " << newPoint2 << " donne le point " << (point2Test += newPoint2) << endl << endl;
	cout << "Le point " << point2Test << " - " << newPoint2 << " donne le point " << (point2Test -= newPoint2) << endl << endl;
	cout << "Le point " << point2Test << " * 5 donne le point " << (point2Test *= 5) << endl << endl;
	cout << "Le point " << point2Test << " / 7 donne le point " << (point2Test /= 7) << endl << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestPoint3()
{
	// cin.sync() & cin.clear() pour securiser le cin

	Point3 point3Test;
	Point3 tempPoint;
	Point3 lerpResult;
	Point3 newPoint3;
	float fX, fY, fZ;
	float fCoef;

	cout << ">> Test unitaire Point3 :" << endl << endl << endl;

	cout << "Entrez une valeur en X, en Y puis en Z :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;

	cout << endl;

	point3Test = Point3(fX, fY, fZ);

	cout << "Le point crée est :" << endl << endl;

	point3Test.Display();


	// Translate
	cout << endl << "Entrez une valeur de déplacement en X, en Y puis en Z :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;

	cout << endl;

	tempPoint = point3Test;

	cout << "Le point avant déplacement est :" << endl << endl;

	tempPoint.Display();

	tempPoint.Translate(fX, fY, fZ);

	cout << "Le point après déplacement est :" << endl << endl;

	tempPoint.Display();

	// LERP
	cout << endl << "Entrez des valeurs pour le point à interpoler :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;

	cout << endl;

	cout << endl << "Entrez le coeficient d'interpolation (entre 0 et 1) :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fCoef;

	cout << endl;


	tempPoint.SetX(fX);
	tempPoint.SetX(fY);
	tempPoint.SetX(fZ);

	lerpResult = point3Test.Lerp(tempPoint, fmodf(fCoef, 1.f));

	cout << "Le résultat de l'interpolation du point " << endl << endl;

	point3Test.Display();

	cout << " et du point " << endl << endl;

	tempPoint.Display();

	cout << " par le coefficient " << fCoef << " est " << endl << endl;

	lerpResult.Display();


	// Operateurs
	// Flux
	cout << "Operateurs : " << endl << endl << endl;
	cout << "Operateurs de flux : " << endl << endl;
	cout << "Création d'un nouveau point 3 dimension " << endl << endl;
	cin >> newPoint3;

	cout << "Vous avez crée le point :" << endl;
	cout << newPoint3;


	// Multiplicatio externe
	cout << "Operateurs de multiplication externe : " << endl << endl;

	cout << "Le point " << newPoint3 << " multiplier par " << 3 << " donne le point " << 3 * newPoint3 << endl << endl;
	point3Test = 3 * newPoint3;


	// Comparaison
	cout << "Operateurs de comparaison : " << endl << endl;

	cout << "Le point " << point3Test << " est " << ((point3Test == newPoint3) ? (" similaire ") : (" différent ")) << " au point" << newPoint3 << endl << endl;
	cout << "Le point " << point3Test << " est " << ((point3Test != newPoint3) ? (" différent ") : (" similaire ")) << " au point" << newPoint3 << endl << endl;


	// Unaire
	cout << "Operateurs unaire : " << endl << endl;

	cout << "Le point est " << +point3Test;
	cout << "Le point " << point3Test << " sous forme négative est " << -point3Test;


	// Binaire sans affectation
	cout << "Operateurs binaire sans affectation : " << endl << endl;

	cout << "Le point " << point3Test << " + " << newPoint3 << " donne le point " << point3Test + newPoint3 << endl << endl;
	point3Test = point3Test + newPoint3;

	cout << "Le point " << point3Test << " - " << newPoint3 << " donne le point " << point3Test - newPoint3 << endl << endl;
	point3Test = point3Test - newPoint3;

	cout << "Le point " << point3Test << " * 5 donne le point " << point3Test * 5 << endl << endl;
	point3Test = point3Test * 5;

	cout << "Le point " << point3Test << " / 7 donne le point " << point3Test / 7 << endl << endl;
	point3Test = point3Test / 7;


	// Binaire avec affectation
	cout << "Operateurs binaire avec affectation : " << endl << endl;

	cout << "Le point " << point3Test << " + " << newPoint3 << " donne le point " << (point3Test += newPoint3) << endl << endl;
	cout << "Le point " << point3Test << " - " << newPoint3 << " donne le point " << (point3Test -= newPoint3) << endl << endl;
	cout << "Le point " << point3Test << " * 5 donne le point " << (point3Test *= 5) << endl << endl;
	cout << "Le point " << point3Test << " / 7 donne le point " << (point3Test /= 7) << endl << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestVector2()
{
	// cin.sync() & cin.clear() pour securiser le cin

	Vector2 vector2Test;
	Vector2 tempVecteur;
	Vector2 lerpResult;
	Vector2 newVector2;
	float fX, fY;
	float fCoef;

	cout << ">> Test unitaire Vector2 :" << endl << endl << endl;

	cout << "Entrez une valeur en X puis en Y :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;

	cout << endl;

	vector2Test = Vector2(fX, fY);

	cout << "Le point crée est :" << endl << endl;

	vector2Test.Display();


	// Translate
	cout << endl << "Entrez une valeur de déplacement en X, puis en Y :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;

	cout << endl;

	tempVecteur = vector2Test;

	cout << "Le vecteur avant déplacement est :" << endl << endl;

	tempVecteur.Display();

	tempVecteur.Translate(fX, fY);

	cout << "Le vecteur après déplacement est :" << endl << endl;

	tempVecteur.Display();

	// LERP
	cout << endl << "Entrez des valeurs pour le vecteur à interpoler :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;

	cout << endl;

	cout << endl << "Entrez le coeficient d'interpolation (entre 0 et 1) :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fCoef;

	cout << endl;


	tempVecteur.SetX(fX);
	tempVecteur.SetY(fY);

	lerpResult = Vector2::Lerp(vector2Test, tempVecteur, fmodf(fCoef, 1.f));

	cout << "Le résultat de l'interpolation du vecteur " << endl << endl;

	vector2Test.Display();

	cout << " et du vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " par le coefficient " << fCoef << " est " << endl << endl;

	lerpResult.Display();


	// length
	cout << "La longueur du vecteur " << endl << endl;

	vector2Test.Display();

	cout << " est " << vector2Test.Length() << endl << endl;


	// NULL by epsilon
	cout << "Le vecteur " << endl << endl;

	vector2Test.Display();

	if (vector2Test.IsNullByEpsilon())
	{
		cout << " à une taille inférieur à epsilon." << endl << endl;
	}

	else
	{
		cout << " à une taille supérieur à epsilon." << endl << endl;
	}


	// Unit by epsilon
	cout << "Le vecteur " << endl << endl;

	vector2Test.Display();

	if (vector2Test.IsNullByEpsilon())
	{
		cout << " à une taille inférieur à 1 + epsilon." << endl << endl;
	}

	else
	{
		cout << " à une taille supérieur à 1 + epsilon." << endl << endl;
	}


	// Normalize
	cout << "Le vecteur " << endl << endl;

	vector2Test.Display();
	tempVecteur = vector2Test;
	vector2Test.Normalize();

	cout << " une fois unitaire est " << endl << endl;

	vector2Test.Display();


	// Dot
	cout << endl << "Entrez des valeurs pour le vecteur avec lequel on feras un produit scalaire :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;

	tempVecteur.SetX(fX);
	tempVecteur.SetY(fY);

	cout << "Le produit scalaire entre le vecteur " << endl << endl;

	vector2Test.Display();

	cout << " et le vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " donne le produit scalaire " << vector2Test.Dot(tempVecteur) << "." << endl << endl;


	// Angle
	cout << "L'angle entre le vecteur " << endl << endl;

	vector2Test.Display();

	cout << " et le vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " donne l'angle " << vector2Test.Angle(tempVecteur) << "." << endl << endl;


	// Operateurs
	// Flux
	cout << "Operateurs : " << endl << endl << endl;
	cout << "Operateurs de flux : " << endl << endl;
	cout << "Création d'un nouveau vecteur 2 dimension " << endl << endl;
	cin >> newVector2;

	cout << "Vous avez crée le vecteur :" << endl;
	cout << newVector2;


	// Multiplicatio externe
	cout << "Operateurs de multiplication externe : " << endl << endl;

	cout << "Le vecteur " << newVector2 << " multiplier par " << 3 << " donne le vecteur " << 3 * newVector2 << endl << endl;
	vector2Test = 3 * newVector2;


	// Comparaison
	cout << "Operateurs de comparaison : " << endl << endl;

	cout << "Le vecteur " << vector2Test << " est " << ((vector2Test == newVector2) ? (" similaire ") : (" différent ")) << " au vecteur" << newVector2 << endl << endl;
	cout << "Le vecteur " << vector2Test << " est " << ((vector2Test != newVector2) ? (" différent ") : (" similaire ")) << " au vecteur" << newVector2 << endl << endl;


	// Unaire
	cout << "Operateurs unaire : " << endl << endl;

	cout << "Le vecteur est " << +vector2Test;
	cout << "Le vecteur " << vector2Test << " sous forme négative est " << -vector2Test;


	// Binaire sans affectation
	cout << "Operateurs binaire sans affectation : " << endl << endl;

	cout << "Le vecteur " << vector2Test << " + " << newVector2 << " donne le vecteur " << vector2Test + newVector2 << endl << endl;
	vector2Test = vector2Test + newVector2;

	cout << "Le vecteur " << vector2Test << " - " << newVector2 << " donne le vecteur " << vector2Test - newVector2 << endl << endl;
	vector2Test = vector2Test - newVector2;

	cout << "Le vecteur " << vector2Test << " * 5 donne le vecteur " << vector2Test * 5 << endl << endl;
	vector2Test = vector2Test * 5;

	cout << "Le vecteur " << vector2Test << " / 7 donne le vecteur " << vector2Test / 7 << endl << endl;
	vector2Test = vector2Test / 7;


	// Binaire avec affectation
	cout << "Operateurs binaire avec affectation : " << endl << endl;

	cout << "Le vecteur " << vector2Test << " + " << newVector2 << " donne le vecteur " << (vector2Test += newVector2) << endl << endl;
	cout << "Le vecteur " << vector2Test << " - " << newVector2 << " donne le vecteur " << (vector2Test -= newVector2) << endl << endl;
	cout << "Le vecteur " << vector2Test << " * 5 donne le vecteur " << (vector2Test *= 5) << endl << endl;
	cout << "Le vecteur " << vector2Test << " / 7 donne le vecteur " << (vector2Test /= 7) << endl << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestVector3()
{
	// cin.sync() & cin.clear() pour securiser le cin

	Vector3 vector3Test;
	Vector3 tempVecteur;
	Vector3 lerpResult;
	Vector3 newVecteur3;
	float fX, fY, fZ;
	float fCoef;

	cout << ">> Test unitaire Vector3 :" << endl << endl << endl;

	cout << "Entrez une valeur en X, en Y puis en Z :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;

	cout << endl;

	vector3Test = Vector3(fX, fY, fZ);

	cout << "Le point crée est :" << endl << endl;

	vector3Test.Display();


	// Translate
	cout << endl << "Entrez une valeur en X, en Y puis en Z :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;

	cout << endl;

	tempVecteur = vector3Test;

	cout << "Le vecteur avant déplacement est :" << endl << endl;

	tempVecteur.Display();

	tempVecteur.Translate(fX, fY, fZ);

	cout << "Le vecteur après déplacement est :" << endl << endl;

	tempVecteur.Display();

	// LERP
	cout << endl << "Entrez des valeurs pour le vecteur à interpoler :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;

	cout << endl;

	cout << endl << "Entrez le coeficient d'interpolation (entre 0 et 1) :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fCoef;

	cout << endl;


	tempVecteur.SetX(fX);
	tempVecteur.SetY(fY);
	tempVecteur.SetZ(fZ);

	lerpResult = Vector3::Lerp(vector3Test, tempVecteur, fmodf(fCoef, 1.f));

	cout << "Le résultat de l'interpolation du vecteur " << endl << endl;

	vector3Test.Display();

	cout << " et du vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " par le coefficient " << fCoef << " est " << endl << endl;

	lerpResult.Display();


	// length
	cout << "La longueur du vecteur " << endl << endl;

	vector3Test.Display();

	cout << " est " << vector3Test.Length() << endl << endl;


	// NULL by epsilon
	cout << "Le vecteur " << endl << endl;

	vector3Test.Display();

	if (vector3Test.IsNullByEpsilon())
	{
		cout << " à une taille inférieur à epsilon." << endl << endl;
	}

	else
	{
		cout << " à une taille supérieur à epsilon." << endl << endl;
	}


	// Unit by epsilon
	cout << "Le vecteur " << endl << endl;

	vector3Test.Display();

	if (vector3Test.IsNullByEpsilon())
	{
		cout << " à une taille inférieur à 1 + epsilon." << endl << endl;
	}

	else
	{
		cout << " à une taille supérieur à 1 + epsilon." << endl << endl;
	}


	// Normalize
	cout << "Le vecteur " << endl << endl;

	vector3Test.Display();
	tempVecteur = vector3Test;
	vector3Test.Normalize();

	cout << " une fois unitaire est " << endl << endl;

	vector3Test.Display();


	// Dot
	cout << endl << "Entrez des valeurs pour le vecteur avec lequel on feras un produit scalaire :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;

	tempVecteur.SetX(fX);
	tempVecteur.SetY(fY);
	tempVecteur.SetZ(fZ);

	cout << "Le produit scalaire entre le vecteur " << endl << endl;

	vector3Test.Display();

	cout << " et le vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " donne le produit scalaire " << vector3Test.Dot(tempVecteur) << "." << endl << endl;


	// Angle
	cout << "L'angle entre le vecteur " << endl << endl;

	vector3Test.Display();

	cout << " et le vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " donne l'angle " << vector3Test.Angle(tempVecteur) << "." << endl << endl;

	cout << endl << endl << endl;


	// Cross
	cout << "Le vecteur resultat du produit vectorielle entre le vecteur " << endl << endl;

	vector3Test.Display();

	cout << " et le vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " donne le vecteur " << endl << endl;

	lerpResult = vector3Test.Cross(tempVecteur);

	lerpResult.Display();


	// Operateurs
	// Flux
	cout << "Operateurs : " << endl << endl << endl;
	cout << "Operateurs de flux : " << endl << endl;
	cout << "Création d'un nouveau vecteur 3 dimension " << endl << endl;
	cin >> newVecteur3;

	cout << "Vous avez crée le vecteur :" << endl;
	cout << newVecteur3;


	// Multiplicatio externe
	cout << "Operateurs de multiplication externe : " << endl << endl;

	cout << "Le vecteur " << newVecteur3 << " multiplier par " << 3 << " donne le vecteur " << 3 * newVecteur3 << endl << endl;
	vector3Test = 3 * newVecteur3;


	// Comparaison
	cout << "Operateurs de comparaison : " << endl << endl;

	cout << "Le vecteur " << vector3Test << " est " << ((vector3Test == newVecteur3) ? (" similaire ") : (" différent ")) << " au vecteur" << newVecteur3 << endl << endl;
	cout << "Le vecteur " << vector3Test << " est " << ((vector3Test != newVecteur3) ? (" différent ") : (" similaire ")) << " au vecteur" << newVecteur3 << endl << endl;


	// Unaire
	cout << "Operateurs unaire : " << endl << endl;

	cout << "Le vecteur est " << +vector3Test;
	cout << "Le vecteur " << vector3Test << " sous forme négative est " << -vector3Test;


	// Binaire sans affectation
	cout << "Operateurs binaire sans affectation : " << endl << endl;

	cout << "Le vecteur " << vector3Test << " + " << newVecteur3 << " donne le vecteur " << vector3Test + newVecteur3 << endl << endl;
	vector3Test = vector3Test + newVecteur3;

	cout << "Le vecteur " << vector3Test << " - " << newVecteur3 << " donne le vecteur " << vector3Test - newVecteur3 << endl << endl;
	vector3Test = vector3Test - newVecteur3;

	cout << "Le vecteur " << vector3Test << " * 5 donne le vecteur " << vector3Test * 5 << endl << endl;
	vector3Test = vector3Test * 5;

	cout << "Le vecteur " << vector3Test << " / 7 donne le vecteur " << vector3Test / 7 << endl << endl;
	vector3Test = vector3Test / 7;


	// Binaire avec affectation
	cout << "Operateurs binaire avec affectation : " << endl << endl;

	cout << "Le vecteur " << vector3Test << " + " << newVecteur3 << " donne le vecteur " << (vector3Test += newVecteur3) << endl << endl;
	cout << "Le vecteur " << vector3Test << " - " << newVecteur3 << " donne le vecteur " << (vector3Test -= newVecteur3) << endl << endl;
	cout << "Le vecteur " << vector3Test << " * 5 donne le vecteur " << (vector3Test *= 5) << endl << endl;
	cout << "Le vecteur " << vector3Test << " / 7 donne le vecteur " << (vector3Test /= 7) << endl << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestVector4()
{
	// cin.sync() & cin.clear() pour securiser le cin

	Vector4 Vector4Test;
	Vector4 tempVecteur;
	Vector4 lerpResult;
	float fX, fY, fZ, fW;
	float fCoef;

	cout << ">> Test unitaire Vector4 :" << endl << endl << endl;

	cout << "Entrez une valeur en X, en Y, en Z puis en W :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;
	cin.clear();
	cin.sync();
	cin >> fW;

	cout << endl;

	Vector4Test = Vector4(fX, fY, fZ, fW);

	cout << "Le point crée est :" << endl << endl;

	Vector4Test.Display();


	// Translate
	cout << "Entrez une valeur en X, en Y, en Z puis en W :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;
	cin.clear();
	cin.sync();
	cin >> fW;

	cout << endl;

	tempVecteur = Vector4Test;

	cout << "Le vecteur avant déplacement est :" << endl << endl;

	tempVecteur.Display();

	tempVecteur.Translate(fX, fY, fZ, fW);

	cout << "Le vecteur après déplacement est :" << endl << endl;

	tempVecteur.Display();

	// LERP
	cout << endl << "Entrez des valeurs pour le vecteur à interpoler :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;
	cin.clear();
	cin.sync();
	cin >> fW;

	cout << endl;

	cout << endl << "Entrez le coeficient d'interpolation (entre 0 et 1) :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fCoef;

	cout << endl;


	tempVecteur.SetX(fX);
	tempVecteur.SetY(fY);
	tempVecteur.SetZ(fZ);
	tempVecteur.SetX(fW);

	lerpResult = Vector4::Lerp(Vector4Test, tempVecteur, fmodf(fCoef, 1.f));

	cout << "Le résultat de l'interpolation du vecteur " << endl << endl;

	Vector4Test.Display();

	cout << " et du vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " par le coefficient " << fCoef << " est " << endl << endl;

	lerpResult.Display();


	// length
	cout << "La longueur du vecteur " << endl << endl;

	Vector4Test.Display();

	cout << " est " << Vector4Test.Length() << endl << endl;


	// NULL by epsilon
	cout << "Le vecteur " << endl << endl;

	Vector4Test.Display();

	if (Vector4Test.IsNullByEpsilon())
	{
		cout << " à une taille inférieur à epsilon." << endl << endl;
	}

	else
	{
		cout << " à une taille supérieur à epsilon." << endl << endl;
	}


	// Unit by epsilon
	cout << "Le vecteur " << endl << endl;

	Vector4Test.Display();

	if (Vector4Test.IsNullByEpsilon())
	{
		cout << " à une taille inférieur à 1 + epsilon." << endl << endl;
	}

	else
	{
		cout << " à une taille supérieur à 1 + epsilon." << endl << endl;
	}


	// Normalize
	cout << "Le vecteur " << endl << endl;

	Vector4Test.Display();
	tempVecteur = Vector4Test;
	Vector4Test.Normalize();

	cout << " une fois unitaire est " << endl << endl;

	Vector4Test.Display();


	// Dot
	cout << endl << "Entrez des valeurs pour le vecteur avec lequel on feras un produit scalaire :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> fX;
	cin.clear();
	cin.sync();
	cin >> fY;
	cin.clear();
	cin.sync();
	cin >> fZ;
	cin.clear();
	cin.sync();
	cin >> fW;

	tempVecteur.SetX(fX);
	tempVecteur.SetY(fY);
	tempVecteur.SetZ(fZ);
	tempVecteur.SetW(fW);

	cout << "Le produit scalaire entre le vecteur " << endl << endl;

	Vector4Test.Display();

	cout << " et le vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " donne le produit scalaire " << Vector4Test.Dot(tempVecteur) << "." << endl << endl;


	// Angle
	cout << "L'angle entre le vecteur " << endl << endl;

	Vector4Test.Display();

	cout << " et le vecteur " << endl << endl;

	tempVecteur.Display();

	cout << " donne l'angle " << Vector4Test.Angle(tempVecteur) << "." << endl << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestTriangle2()
{
	Triangle2 triangle(Point2(0.f, 0.f), Point2(1.f, 0.f), Point2(0.f, 1.f));
	Triangle2 newTriangle;

	cout << ">> Test unitaire Triangle2 :" << endl << endl << endl;

	triangle.Display();


	// Operateurs
	// Flux
	cout << "Operateurs : " << endl << endl << endl;
	cout << "Operateurs de flux : " << endl << endl;
	cout << "Création d'un nouveau triangle 2 dimension " << endl << endl;
	cin >> newTriangle;

	cout << "Vous avez crée le triangle :" << endl;
	cout << newTriangle;


	// Comparaison
	cout << "Operateurs de comparaison : " << endl << endl;

	cout << "Le triangle " << triangle << " est " << ((triangle == newTriangle) ? (" similaire ") : (" différent ")) << " au triangle" << newTriangle << endl << endl;
	cout << "Le triangle " << triangle << " est " << ((triangle != newTriangle) ? (" différent ") : (" similaire ")) << " au triangle" << newTriangle << endl << endl;


	// Unaire
	cout << "Operateurs unaire : " << endl << endl;

	cout << "Le triangle est " << +triangle;
	cout << "Le triangle " << triangle << " sous forme négative est " << -triangle;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestTriangle3()
{
	unsigned int uiSize;
	Triangle3 triangle(Point3(1.f, 0.f, 0.f), Point3(0.f, 1.f, 0.f), Point3(0.f, 0.f, 1.f));
	Triangle3* ptrTriangle = NULL;
	Triangle3 newTriangle;

	cout << ">> Test unitaire Triangle3 :" << endl << endl << endl;

	cout << "Affichage d'un triangle en 3 dimension :" << endl << endl;

	triangle.Display();

	cout << "Entrez le nombre de tringle que vous voulez instancier :" << endl << endl;

	cin.clear();
	cin.sync();
	cin >> uiSize;

	ptrTriangle = new Triangle3[uiSize];

	for (unsigned int i = 0; i < uiSize; ++i)
	{
		cout << "Triangle " << i + 1 << " : " << endl << endl;

		ptrTriangle[i] = Triangle3(Point3((float)(rand() % 255), (float)(rand() % 255), (float)(rand() % 255)),
			Point3((float)(rand() % 255), (float)(rand() % 255), (float)(rand() % 255)),
			Point3((float)(rand() % 255), (float)(rand() % 255), (float)(rand() % 255)));

		ptrTriangle[i].Display();
	}

	cout << endl;

	cout << "Le nombre de triangle 3 instancier est de " << Triangle3::GetTriangles3Count() << " triangles." << endl << endl;

	delete[uiSize] ptrTriangle;
	ptrTriangle = NULL;

	cout << "Le nombre de triangle 3 instancier est de " << Triangle3::GetTriangles3Count() << " triangles." << endl << endl;


	// Operateurs
	// Flux
	cout << "Operateurs : " << endl << endl << endl;
	cout << "Operateurs de flux : " << endl << endl;
	cout << "Création d'un nouveau triangle 3 dimension " << endl << endl;
	cin >> newTriangle;

	cout << "Vous avez crée le triangle :" << endl;
	cout << newTriangle;


	// Comparaison
	cout << "Operateurs de comparaison : " << endl << endl;

	cout << "Le triangle " << triangle << " est " << ((triangle == newTriangle) ? (" similaire ") : (" différent ")) << " au triangle" << newTriangle << endl << endl;
	cout << "Le triangle " << triangle << " est " << ((triangle != newTriangle) ? (" différent ") : (" similaire ")) << " au triangle" << newTriangle << endl << endl;


	// Unaire
	cout << "Operateurs unaire : " << endl << endl;

	cout << "Le triangle est " << +triangle;
	cout << "Le triangle " << triangle << " sous forme négative est " << -triangle;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestVector()
{
	float* ptrf = new float[3];

	ptrf[0] = 6.f;
	ptrf[1] = 2.f;
	ptrf[2] = 7.f;

	Vector vector(3, ptrf);
	Vector newVector;

	cout << ">> Test unitaire Vector :" << endl << endl << endl;

	// Operateurs
	// Flux
	cout << "Operateurs : " << endl << endl << endl;
	cout << "Operateurs de flux : " << endl << endl;
	cout << "Création d'un nouveau vecteur 2 dimension " << endl << endl;
	cin.clear();
	cin.sync();
	cin >> newVector;

	cout << "Vous avez crée le vecteur :" << endl;
	cout << newVector;


	// Multiplicatio externe
	cout << "Operateurs de multiplication externe : " << endl << endl;

	cout << "Le vecteur " << newVector << " multiplier par " << 3 << " donne le vecteur " << (3 * newVector) << endl << endl;
	vector = 3 * newVector;


	// Comparaison
	cout << "Operateurs de comparaison : " << endl << endl;

	cout << "Le vecteur " << vector << " est " << ((vector == newVector) ? (" similaire ") : (" différent ")) << " au vecteur" << newVector << endl << endl;
	cout << "Le vecteur " << vector << " est " << ((vector != newVector) ? (" différent ") : (" similaire ")) << " au vecteur" << newVector << endl << endl;


	// Unaire
	cout << "Operateurs unaire : " << endl << endl;

	cout << "Le vecteur est " << +vector;
	cout << "Le vecteur " << vector << " sous forme négative est " << -vector;


	// Binaire sans affectation
	cout << "Operateurs binaire sans affectation : " << endl << endl;

	cout << "Le vecteur " << vector << " + " << newVector << " donne le vecteur " << vector + newVector << endl << endl;
	vector = vector + newVector;

	cout << "Le vecteur " << vector << " - " << newVector << " donne le vecteur " << vector - newVector << endl << endl;
	vector = vector - newVector;

	cout << "Le vecteur " << vector << " * 5 donne le vecteur " << vector * 5 << endl << endl;
	vector = vector * 5;

	cout << "Le vecteur " << vector << " / 7 donne le vecteur " << vector / 7 << endl << endl;
	vector = vector / 7;


	// Binaire avec affectation
	cout << "Operateurs binaire avec affectation : " << endl << endl;

	cout << "Le vecteur " << vector << " + " << newVector << " donne le vecteur " << (vector += newVector) << endl << endl;
	cout << "Le vecteur " << vector << " - " << newVector << " donne le vecteur " << (vector -= newVector) << endl << endl;
	cout << "Le vecteur " << vector << " * 5 donne le vecteur " << (vector *= 5) << endl << endl;
	cout << "Le vecteur " << vector << " / 7 donne le vecteur " << (vector /= 7) << endl << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestMatrix22()
{
	Matrix22 matrix22Test;
	Matrix22 tempMatrix22;

	Vector2 vector2Test(2.5f, 1.f);

	int iRow, iColumn;

	float fAngle = (rand() * 3.14159f) / 180.f;


	cout << ">> Test unitaire Matrice dimension 2 :" << endl << endl << endl;

	// Debug functions
	cin >> matrix22Test;
	cout << matrix22Test;

	tempMatrix22 = matrix22Test;

	// Set/get
	cout << "Rotation X, angle en radians : " << fAngle << endl;
	tempMatrix22.SetRotation(fAngle);

	cout << tempMatrix22 << endl;


	cout << "Scale X : 2, Scale Y : 4" << endl;
	tempMatrix22.SetScale(2.f, 4.f);

	cout << tempMatrix22 << endl;

	cout << "Matrice identité" << endl;
	tempMatrix22.SetIdentity();

	cout << tempMatrix22 << endl;

	cout << "Matrice null" << endl;
	tempMatrix22.SetZero();

	cout << tempMatrix22 << endl;

	tempMatrix22 = matrix22Test;


	// assignment operators
	cout << endl << endl << "Operateur d'affecttation :" << endl << endl;

	cout << "opérateur *= entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	matrix22Test *= tempMatrix22;

	cout << matrix22Test << endl;

	cout << "opérateur += entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	matrix22Test += tempMatrix22;

	cout << matrix22Test << endl;

	cout << "opérateur -= entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	matrix22Test -= tempMatrix22;

	cout << matrix22Test << endl;

	cout << "opérateur *= entre " << matrix22Test << " et 2 :" << endl;
	matrix22Test *= 2.f;

	cout << matrix22Test << endl;

	cout << "opérateur /= entre " << matrix22Test << " et 4 :" << endl;
	matrix22Test /= 4.f;

	cout << matrix22Test << endl;


	// unary operators
	cout << endl << endl << "Operateur unaire :" << endl << endl;

	cout << "opérateur + sur " << matrix22Test << " :" << endl;
	cout << +matrix22Test << endl;

	cout << "opérateur - sur " << matrix22Test << " :" << endl;
	cout << -matrix22Test << endl;


	// binary operators
	cout << endl << endl << "Operateur binaire :" << endl << endl;

	cout << "opérateur * entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	cout << matrix22Test * tempMatrix22 << endl;

	cout << "opérateur + entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	cout << matrix22Test + tempMatrix22 << endl;

	cout << "opérateur - entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	cout << matrix22Test - tempMatrix22 << endl;

	cout << "opérateur * entre " << matrix22Test << " et 2 :" << endl;
	cout << matrix22Test * 2.f << endl;

	cout << "opérateur / entre " << matrix22Test << " et 4 :" << endl;
	cout << matrix22Test / 4.f << endl;


	cout << "opérateur == entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	cout << ((matrix22Test == tempMatrix22) ? ("Les matrices sont les mêmes") : ("Les matrices sont différentes")) << endl;

	cout << "opérateur != entre " << matrix22Test << " et " << tempMatrix22 << " :" << endl;
	cout << ((matrix22Test != tempMatrix22) ? ("Les matrices sont différentes") : ("Les matrices sont les mêmes")) << endl;


	cout << "opérateur * entre " << matrix22Test << " et " << vector2Test << " :" << endl;
	cout << matrix22Test * vector2Test << endl;


	// accessor
	cout << endl << endl << "Acceseur (Operateur parenthèse) :" << endl << endl;
	cout << "Entrez une ligne :" << endl;
	cin.clear();
	cin.sync();
	cin >> iRow;
	cout << endl << endl;

	cout << "Entrez une colonne :" << endl;
	cin.clear();
	cin.sync();
	cin >> iColumn;
	cout << endl << endl;

	cout << "opérateur () sur " << matrix22Test << " pour la ligne : " << iRow << " et la colonne : " << iColumn << endl;
	cout << matrix22Test(iRow, iColumn) << endl;


	// matrix operation
	cout << "La transposer de la matrice " << tempMatrix22 << endl << endl;
	tempMatrix22.Transpose();
	cout << tempMatrix22 << endl;

	cout << "La inverse de la matrice " << tempMatrix22 << endl << endl;
	tempMatrix22.Inverse();
	cout << tempMatrix22 << endl;


	// DADENGINE_API friend function
	cout << endl << endl << "Fonction DADENGINE_API friend :" << endl << endl;

	cout << "Opérateur amies entre " << vector2Test << " et " << tempMatrix22 << " :" << endl << endl;
	cout << vector2Test * tempMatrix22 << endl;


	cout << "Opérateur amies entre 2 et " << tempMatrix22 << " :" << endl << endl;
	cout << 2.f * tempMatrix22 << endl;


	// debug function

	cout << "La affichage de la matrice " << tempMatrix22 << endl << endl;
	tempMatrix22.Display();

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestMatrix33()
{
	Matrix33 matrix33Test(5.f, 8.f, 4.f,
		2.f, 7.f, 1.f,
		6.f, 5.f, 3.f);
	Matrix33 tempMatrix33;

	Vector4 vector4Test(2.5f, 1.f, 3.f, 7.5f);
	Vector3 vecto3Test(1.f, 1.f, 1.f);

	int iRow, iColumn;

	float fAngle = (rand() * 3.14159f) / 180.f;

	cout << ">> Test unitaire Matrice dimension 3 :" << endl << endl << endl;

	// Debug functions
	cin >> matrix33Test;
	cout << matrix33Test;

	tempMatrix33 = matrix33Test;

	// Set/get
	cout << "Rotation autour de l'axe " << vecto3Test << ", avec un angle en radians : " << fAngle << endl;
	tempMatrix33.SetRotation(fAngle, vecto3Test);

	cout << tempMatrix33 << endl;

	cout << "Rotation X, avec un angle en radians : " << fAngle << endl;
	tempMatrix33.SetRotationX(fAngle);

	cout << tempMatrix33 << endl;

	cout << "Rotation Y, avec un angle en radians : " << fAngle << endl;
	tempMatrix33.SetRotationY(fAngle);

	cout << tempMatrix33 << endl;

	cout << "Rotation Z, avec un angle en radians : " << fAngle << endl;
	tempMatrix33.SetRotationZ(fAngle);

	cout << tempMatrix33 << endl;


	cout << "Scale X : 2, Scale Y : 4, Scale Z : 8" << endl;
	tempMatrix33.SetScale(2.f, 4.f, 8.f);

	cout << tempMatrix33 << endl;

	cout << "Matrice identité" << endl;
	tempMatrix33.SetIdentity();

	cout << tempMatrix33 << endl;

	cout << "Matrice null" << endl;
	tempMatrix33.SetZero();

	cout << tempMatrix33 << endl;

	// Set to non null matrix
	tempMatrix33 = matrix33Test;


	// assignment operators
	cout << endl << endl << "Operateur d'affecttation :" << endl << endl;

	cout << "opérateur *= entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	matrix33Test *= tempMatrix33;

	cout << matrix33Test << endl;

	cout << "opérateur += entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	matrix33Test += tempMatrix33;

	cout << matrix33Test << endl;

	cout << "opérateur -= entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	matrix33Test -= tempMatrix33;

	cout << matrix33Test << endl;

	cout << "opérateur *= entre " << matrix33Test << " et 2 :" << endl;
	matrix33Test *= 2.f;

	cout << matrix33Test << endl;

	cout << "opérateur /= entre " << matrix33Test << " et 4 :" << endl;
	matrix33Test /= 4.f;

	cout << matrix33Test << endl;


	// unary operators
	cout << endl << endl << "Operateur unaire :" << endl << endl;

	cout << "opérateur + sur " << matrix33Test << " :" << endl;
	cout << +matrix33Test << endl;

	cout << "opérateur - sur " << matrix33Test << " :" << endl;
	cout << -matrix33Test << endl;


	// binary operators
	cout << endl << endl << "Operateur binaire :" << endl << endl;

	cout << "opérateur * entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	cout << matrix33Test * tempMatrix33 << endl;

	cout << "opérateur + entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	cout << matrix33Test + tempMatrix33 << endl;

	cout << "opérateur - entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	cout << matrix33Test - tempMatrix33 << endl;

	cout << "opérateur * entre " << matrix33Test << " et 2 :" << endl;
	cout << matrix33Test * 2.f << endl;

	cout << "opérateur / entre " << matrix33Test << " et 4 :" << endl;
	cout << matrix33Test / 4.f << endl;


	cout << "opérateur == entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	cout << ((matrix33Test == tempMatrix33) ? ("Les matrices sont les mêmes") : ("Les matrices sont différentes")) << endl;

	cout << "opérateur != entre " << matrix33Test << " et " << tempMatrix33 << " :" << endl;
	cout << ((matrix33Test != tempMatrix33) ? ("Les matrices sont différentes") : ("Les matrices sont les mêmes")) << endl;


	cout << "opérateur * entre " << matrix33Test << " et " << vecto3Test << " :" << endl;
	cout << matrix33Test * vecto3Test << endl;


	// accessor
	cout << endl << endl << "Acceseur (Operateur parenthèse) :" << endl << endl;
	cout << "Entrez une ligne :" << endl;
	cin.clear();
	cin.sync();
	cin >> iRow;
	cout << endl << endl;

	cout << "Entrez une colonne :" << endl;
	cin.clear();
	cin.sync();
	cin >> iColumn;
	cout << endl << endl;

	cout << "opérateur () sur " << matrix33Test << " pour la ligne : " << iRow << " et la colonne : " << iColumn << endl;
	cout << matrix33Test(iRow, iColumn) << endl;


	// matrix operation
	cout << "La transposer de la matrice " << tempMatrix33 << endl << endl;
	tempMatrix33.Transpose();
	cout << tempMatrix33 << endl;

	cout << "La inverse de la matrice " << tempMatrix33 << endl << endl;
	tempMatrix33.Inverse();
	cout << tempMatrix33 << endl;


	// DADENGINE_API friend function
	cout << endl << endl << "Fonction DADENGINE_API friend :" << endl << endl;

	cout << "Opérateur amies entre " << vecto3Test << " et " << tempMatrix33 << " :" << endl << endl;
	cout << vecto3Test * tempMatrix33 << endl;


	cout << "Opérateur amies entre 2 et " << tempMatrix33 << " :" << endl << endl;
	cout << 2.f * tempMatrix33 << endl;


	// debug function

	cout << "La affichage de la matrice " << tempMatrix33 << endl << endl;
	tempMatrix33.Display();


	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestMatrix44()
{
	Matrix33 matrix33Test(5.f, 8.f, 4.f,
		2.f, 7.f, 1.f,
		6.f, 5.f, 3.f);

	Matrix44 matrix44Test(3.f, 0.f, 2.f, -1.f,
		1.f, 2.f, 0.f, -2.f,
		4.f, 0.f, 6.f, -3.f,
		5.f, 0.f, 2.f, 0.f);
	Matrix44 tempMatrix44;

	Vector4 vector4Test(2.5f, 1.f, 3.f, 7.5f);

	int iRow, iColumn;

	float fAngle = (rand() * 3.14159f) / 180.f;

	cout << ">> Test unitaire Matrice dimension 4 :" << endl << endl << endl;

	// Debug functions
	cin >> matrix44Test;
	cout << matrix44Test;

	tempMatrix44 = matrix44Test;

	// Set/get
	cout << "Rotation X, avec un angle en radians : " << fAngle << endl;
	matrix33Test.SetRotationX(fAngle);
	tempMatrix44.SetRotation(matrix33Test);

	cout << tempMatrix44 << endl;


	cout << "Scale X : 2, Scale Y : 4, Scale Z : 8" << endl;
	tempMatrix44.SetScale(Vector3(2.f, 4.f, 8.f));

	cout << tempMatrix44 << endl;

	cout << "Matrice identité" << endl;
	tempMatrix44.SetIdentity();

	cout << tempMatrix44 << endl;

	cout << "Matrice null" << endl;
	tempMatrix44.SetZero();

	cout << tempMatrix44 << endl;

	// Set to non null matrix
	tempMatrix44 = matrix44Test;


	// assignment operators
	cout << endl << endl << "Operateur d'affecttation :" << endl << endl;

	cout << "opérateur *= entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	matrix44Test *= tempMatrix44;

	cout << matrix44Test << endl;

	cout << "opérateur += entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	matrix44Test += tempMatrix44;

	cout << matrix44Test << endl;

	cout << "opérateur -= entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	matrix44Test -= tempMatrix44;

	cout << matrix44Test << endl;

	cout << "opérateur *= entre " << matrix44Test << " et 2 :" << endl;
	matrix44Test *= 2.f;

	cout << matrix44Test << endl;

	cout << "opérateur /= entre " << matrix44Test << " et 4 :" << endl;
	matrix44Test /= 4.f;

	cout << matrix44Test << endl;


	// unary operators
	cout << endl << endl << "Operateur unaire :" << endl << endl;

	cout << "opérateur + sur " << matrix44Test << " :" << endl;
	cout << +matrix44Test << endl;

	cout << "opérateur - sur " << matrix44Test << " :" << endl;
	cout << -matrix44Test << endl;


	// binary operators
	cout << endl << endl << "Operateur binaire :" << endl << endl;

	cout << "opérateur * entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	cout << matrix44Test * tempMatrix44 << endl;

	cout << "opérateur + entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	cout << matrix44Test + tempMatrix44 << endl;

	cout << "opérateur - entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	cout << matrix44Test - tempMatrix44 << endl;

	cout << "opérateur * entre " << matrix44Test << " et 2 :" << endl;
	cout << matrix44Test * 2.f << endl;

	cout << "opérateur / entre " << matrix44Test << " et 4 :" << endl;
	cout << matrix44Test / 4.f << endl;


	cout << "opérateur == entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	cout << ((matrix44Test == tempMatrix44) ? ("Les matrices sont les mêmes") : ("Les matrices sont différentes")) << endl;

	cout << "opérateur != entre " << matrix44Test << " et " << tempMatrix44 << " :" << endl;
	cout << ((matrix44Test != tempMatrix44) ? ("Les matrices sont différentes") : ("Les matrices sont les mêmes")) << endl;


	cout << "opérateur * entre " << matrix44Test << " et " << vector4Test << " :" << endl;
	cout << matrix44Test * vector4Test << endl;


	// accessor
	cout << endl << endl << "Acceseur (Operateur parenthèse) :" << endl << endl;
	cout << "Entrez une ligne :" << endl;
	cin.clear();
	cin.sync();
	cin >> iRow;
	cout << endl << endl;

	cout << "Entrez une colonne :" << endl;
	cin.clear();
	cin.sync();
	cin >> iColumn;
	cout << endl << endl;

	cout << "opérateur () sur " << matrix44Test << " pour la ligne : " << iRow << " et la colonne : " << iColumn << endl;
	cout << matrix44Test(iRow, iColumn) << endl;


	// matrix operation
	cout << "La transposer de la matrice " << tempMatrix44 << endl << endl;
	tempMatrix44.Transpose();
	cout << tempMatrix44 << endl;

	cout << "La inverse de la matrice " << tempMatrix44 << endl << endl;
	tempMatrix44.Inverse();
	cout << tempMatrix44 << endl;


	// DADENGINE_API friend function
	cout << endl << endl << "Fonction DADENGINE_API friend :" << endl << endl;

	cout << "Opérateur amies entre " << vector4Test << " et " << tempMatrix44 << " :" << endl << endl;
	cout << vector4Test * tempMatrix44 << endl;


	cout << "Opérateur amies entre 2 et " << tempMatrix44 << " :" << endl << endl;
	cout << 2.f * tempMatrix44 << endl;


	// debug function

	cout << "La affichage de la matrice " << tempMatrix44 << endl << endl;
	tempMatrix44.Display();

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestTransform()
{
	Matrix33* matrix33Test = new Matrix33(5.f, 8.f, 4.f,
		2.f, 7.f, 1.f,
		6.f, 5.f, 3.f);

	Transform3 matrixTransformTest(3.f, 0.f, 2.f, -1.f,
		1.f, 2.f, 0.f, -2.f,
		4.f, 0.f, 6.f, -3.f,
		5.f, 0.f, 2.f, 0.f);
	Transform3 tempMatrixTransform;

	Vector3* vector3TestTranslation = new Vector3(2.5f, 2.5f, 3.f);
	Vector3* vector3TestScale = new Vector3(4.f, 4.f, 4.f);
	Vector4 vector4Test(2.5f, 1.f, 3.f, 7.5f);

	float fAngle = (rand() * 3.14159f) / 180.f;

	cout << ">> Test unitaire Matrice transform :" << endl << endl << endl;

	// Debug functions
	cin >> matrixTransformTest;
	cout << matrixTransformTest;

	tempMatrixTransform = matrixTransformTest;


	// Set/Get
	cout << "Rotation X, avec un angle en radians : " << fAngle << endl;
	matrix33Test->SetRotationX(fAngle);
	tempMatrixTransform.SetRotation(matrix33Test);

	cout << *tempMatrixTransform.GetRotation() << endl;


	cout << "Translation, le nouveau vecteur de translation est : " << fAngle << endl;
	tempMatrixTransform.SetTranslation(vector3TestTranslation);

	cout << *tempMatrixTransform.GetTranslation() << endl;


	cout << "Translation, le nouveau vecteur de scale est : " << fAngle << endl;
	tempMatrixTransform.SetScale(vector3TestScale);

	cout << *tempMatrixTransform.GetScale() << endl;


	matrixTransformTest.SetMatrix(tempMatrixTransform.GetMatrix());
	cout << "Transform, la nouvel matrice RTS est : " << matrixTransformTest.GetMatrix() << endl;

	// Binary operators

	cout << "opérateur *= entre " << tempMatrixTransform << " et " << matrixTransformTest << " :" << endl;
	//tempMatrixTransform *= matrixTransformTest;
	cout << tempMatrixTransform << endl;

	cout << "opérateur * entre " << tempMatrixTransform << " et " << matrixTransformTest << " :" << endl;
	cout << tempMatrixTransform * matrixTransformTest << endl;

	cout << "opérateur == entre " << matrixTransformTest << " et " << tempMatrixTransform << " :" << endl;
	cout << ((matrixTransformTest == tempMatrixTransform) ? ("Les matrices sont les mêmes") : ("Les matrices sont différentes")) << endl;

	cout << "opérateur != entre " << matrixTransformTest << " et " << tempMatrixTransform << " :" << endl;
	cout << ((matrixTransformTest != tempMatrixTransform) ? ("Les matrices sont différentes") : ("Les matrices sont les mêmes")) << endl;

	cout << "opérateur * entre " << tempMatrixTransform << " et " << vector4Test << " :" << endl;
	cout << tempMatrixTransform * vector4Test << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
}

void _TestCircle()
{
	Circle cTestCircle(Point2 (400.f, 300.f), 50.f, 3);

#ifdef CONSOLE_TEST
	int iPointCount = 0;
	int iPointIndex = 0;
	float fNewRadius = 0.f;

	cout << ">> Test unitaire Cercle :" << endl << endl << endl;

	cout << "Entrez un rayon pour le cercle : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewRadius;

	cout << "Entrez un nombre de point pour le cercle : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointCount;

	cTestCircle = Circle(fNewRadius, iPointCount);

	cout << cTestCircle << endl << endl;

	cout << "Le nombre de point du cercle est " << cTestCircle.GetPointCount() << endl << endl;

	cout << "Le rayon du cercle est " << cTestCircle.GetRadius() << endl << endl;

	cout << "Entrez un nouveau rayon pour le cercle : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewRadius;
	cTestCircle.SetRadius(fNewRadius);

	cout << "Le nouveau rayon du cercle est " << cTestCircle.GetRadius() << endl << endl;

	cout << "Entrez un index de point choisir un point du cercle : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointIndex;

	cout << "Le point choisis est le suivant : " << cTestCircle.GetPoint(iPointIndex) << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
#endif
#ifdef GRAPHIC_TEST

	cTestCircle.Draw();

#endif
}

void _TestRectangle()
{
	Rectangle cTestRectangle( Point2(400.f, 300.f), 200.f, 200.f);

#ifdef CONSOLE_TEST
	int iPointCount = 0;
	int iPointIndex = 0;
	float fNewWidth = 0.f;
	float fNewHeight = 0.f;

	cout << ">> Test unitaire Rectangle :" << endl << endl << endl;

	cout << "Entrez une largeur pour le rectangle : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewWidth;

	cout << "Entrez une hauteur pour le rectangle : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewHeight;

	cTestRectangle = Rectangle(fNewWidth, fNewHeight);

	cout << cTestRectangle << endl << endl;

	cout << "Le nombre de point du rectangle est " << cTestRectangle.GetPointCount() << endl << endl;

	cout << "La largeur du rectangle est " << cTestRectangle.GetWidth() << endl << endl;
	cout << "La hauteur du rectangle est " << cTestRectangle.GetHeight() << endl << endl;

	cout << "Entrez une nouvelle largeur pour le rectangle : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewWidth;
	cTestRectangle.SetWidth(fNewWidth);

	cout << "La nouvelle largeur du rectangle est " << cTestRectangle.GetWidth() << endl << endl;

	cout << "Entrez une nouvelle hauteur pour le rectangle : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewHeight;
	cTestRectangle.SetHeight(fNewHeight);

	cout << "La nouvelle hauteur du rectangle est " << cTestRectangle.GetHeight() << endl << endl;


	cout << "Entrez un index de point choisir un point du rectangle : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointIndex;

	cout << "Le point choisis est le suivant : " << cTestRectangle.GetPoint(iPointIndex) << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
#endif
#ifdef GRAPHIC_TEST

	cTestRectangle.Draw(NULL);

#endif
}

void _TestPolygon2()
{
	Polygon2 cTestPolygon;

#ifdef CONSOLE_TEST
	int iPointCount = 0;
	int iPointIndex = 0;

	cout << ">> Test unitaire Polygon2 :" << endl << endl << endl;

	cout << "Entrez un nombre de point pour le polygon : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointCount;

	cTestPolygon = Polygon2(iPointCount);

	cout << cTestPolygon << endl << endl;

	cout << "Le nombre de point du polygon est " << cTestPolygon.GetPointCount() << endl << endl;

	for (int i = 0; i < cTestPolygon.GetPointCount(); ++i)
	{
		Point2 pTempPoint2;

		cout << "Entrez les coordonnées du point : " << endl << endl;
		cin >> pTempPoint2;

		cTestPolygon.SetPoint(pTempPoint2, i);
	}

	cout << cTestPolygon << endl << endl;

	cout << "Entrez un index de point choisir un point du polygon : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointIndex;

	cout << "Le point choisis est le suivant : " << cTestPolygon.GetPoint(iPointIndex) << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
#endif

#ifdef GRAPHIC_TEST

	cTestPolygon.Draw(NULL);

#endif
}

void _TestBox()
{
	Box cTestBox;

#ifdef CONSOLE_TEST
	int iPointCount = 0;
	int iPointIndex = 0;
	float fNewWidth = 0.f;
	float fNewHeight = 0.f;
	float fNewDepth = 0.f;

	cout << ">> Test unitaire Cube :" << endl << endl << endl;

	cout << "Entrez une largeur pour le cube : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewWidth;

	cout << "Entrez une hauteur pour le cube : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewHeight;

	cout << "Entrez une profondeur pour le cube : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewDepth;

	cTestBox = Box(fNewWidth, fNewHeight, fNewDepth);

	cout << cTestBox << endl << endl;

	cout << "Le nombre de point du cube est " << cTestBox.GetPointCount() << endl << endl;

	cout << "La largeur du cube est " << cTestBox.GetWidth() << endl << endl;
	cout << "La hauteur du cube est " << cTestBox.GetHeight() << endl << endl;
	cout << "La profondeur du cube est " << cTestBox.GetDepth() << endl << endl;

	cout << "Entrez une nouvelle largeur pour le cube : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewWidth;
	cTestBox.SetWidth(fNewWidth);

	cout << "La nouvelle largeur du cube est " << cTestBox.GetWidth() << endl << endl;

	cout << "Entrez une nouvelle hauteur pour le cube : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewHeight;
	cTestBox.SetHeight(fNewHeight);

	cout << "La nouvelle hauteur du cube est " << cTestBox.GetHeight() << endl << endl;

	cout << "Entrez une nouvelle profondeur pour le cube : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewDepth;
	cTestBox.SetDepth(fNewDepth);

	cout << "La nouvelle profondeur du cube est " << cTestBox.GetDepth() << endl << endl;


	cout << "Entrez un index de point choisir un point du cube : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointIndex;

	cout << "Le point choisis est le suivant : " << cTestBox.GetPoint(iPointIndex) << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
#endif

#ifdef GRAPHIC_TEST

	cTestBox.Draw(wnd);

#endif
}

void _TestSphere()
{
	Sphere cTestSphere;

#ifdef CONSOLE_TEST
	int iPointCount = 0;
	int iPointIndex = 0;
	float fNewRadius = 0.f;

	cout << ">> Test unitaire de la Spehre :" << endl << endl << endl;

	cout << "Entrez un rayon pour la sphere : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewRadius;

	cout << "Entrez un nombre de point pour la sphere : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointCount;

	cTestSphere = Sphere(fNewRadius, iPointCount);

	cout << cTestSphere << endl << endl;

	cout << "Le nombre de point de la sphere est " << cTestSphere.GetPointCount() << endl << endl;

	cout << "Le rayon de la sphere est " << cTestSphere.GetRadius() << endl << endl;

	cout << "Entrez un nouveau rayon pour la sphere : " << endl;
	cin.clear();
	cin.sync();
	cin >> fNewRadius;
	cTestSphere.SetRadius(fNewRadius);

	cout << "Le nouveau rayon de la sphere est " << cTestSphere.GetRadius() << endl << endl;

	cout << "Entrez un index de point choisir un point de la sphere : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointIndex;

	cout << "Le point choisis est le suivant : " << cTestSphere.GetPoint(iPointIndex) << endl;

		cout << endl << endl << endl;

	_displaySousMenu();
#endif
#ifdef GRAPHIC_TEST

	cTestSphere.Display();

#endif
}

void _TestPolygon3()
{
	Polygon3 cTestPolygon;

#ifdef CONSOLE_TEST
	int iPointCount = 0;
	int iPointIndex = 0;

	cout << ">> Test unitaire Polygon3 :" << endl << endl << endl;

	cout << "Entrez un nombre de point pour le polygon : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointCount;

	cTestPolygon = Polygon3(iPointCount);

	cout << cTestPolygon << endl << endl;

	cout << "Le nombre de point du polygon est " << cTestPolygon.GetPointCount() << endl << endl;

	for (int i = 0; i < cTestPolygon.GetPointCount(); ++i)
	{
		Point3 pTempPoint3;

		cout << "Entrez les coordonnées du point : " << endl << endl;
		cin >> pTempPoint3;

		cTestPolygon.SetPoint(pTempPoint3, i);
	}

	cout << cTestPolygon << endl << endl;

	cout << "Entrez un index de point choisir un point du polygon : " << endl;
	cin.clear();
	cin.sync();
	cin >> iPointIndex;

	cout << "Le point choisis est le suivant : " << cTestPolygon.GetPoint(iPointIndex) << endl;

	cout << endl << endl << endl;

	_displaySousMenu();
#endif

#ifdef GRAPHIC_TEST

	cTestPolygon.Draw(wnd);

#endif
}


// Fonctions majeurs
void _Initialisation()
{
	std::locale::global(std::locale(""));

#ifdef GRAPHIC_TEST
	GameManager::GetInstance()->Init(NULL);

	ucCurrentState = TESTCIRCLE;
#endif

	// Init la machine à états
	ptrAGamestates[MENU] = _displayMenu;
	ptrAGamestates[TESTPOINT2] = _TestPoint2;
	ptrAGamestates[TESTPOINT3] = _TestPoint3;
	ptrAGamestates[TESTVECTOR2] = _TestVector2;
	ptrAGamestates[TESTVECTOR3] = _TestVector3;
	ptrAGamestates[TESTVECTOR4] = _TestVector4;
	ptrAGamestates[TESTTRIANGLE2] = _TestTriangle2;
	ptrAGamestates[TESTTRIANGLE3] = _TestTriangle3;
	ptrAGamestates[TESTVECTOR] = _TestVector;
	ptrAGamestates[TESTMATRIX22] = _TestMatrix22;
	ptrAGamestates[TESTMATRIX33] = _TestMatrix33;
	ptrAGamestates[TESTMATRIX44] = _TestMatrix44;
	ptrAGamestates[TESTTRANSFORM] = _TestTransform;
	ptrAGamestates[TESTCIRCLE] = _TestCircle;
	ptrAGamestates[TESTRECTANGLE] = _TestRectangle;
	ptrAGamestates[TESTPOLYGON2] = _TestPolygon2;
	ptrAGamestates[TESTBOX] = _TestBox;
	ptrAGamestates[TESTSPHERE] = _TestSphere;
	ptrAGamestates[TESTPOLYGON3] = _TestPolygon3;
	ptrAGamestates[SHUTDOWN] = _shutdown;

	/*sf::RenderWindow* wnd = NULL;
	SFFont* m_ptrfTitleFont = NULL;
	SFText* m_ptrtTitle = NULL;
	SFTexture* m_ptrTexture = NULL;
	SpriteRenderer* m_ptrSprite = NULL;

	GameManager::GetInstance()->Init(NULL, 1280, 1080);
	wnd = GameManager::GetInstance()->GetWnd();

	m_ptrfTitleFont = (DadEngine::SFFont*)DadEngine::DataManager::GetInstance()->CreateAsset((int)DadEngine::DataManager::ASSETTYPE::SFFONT, "arial");
	//m_ptrfTitleFont->LoadFont("arial.ttf");

	m_ptrTexture = (DadEngine::SFTexture*)DadEngine::DataManager::GetInstance()->CreateAsset((int)DadEngine::DataManager::ASSETTYPE::SFTEXTURE, "blue_circle");
	m_ptrSprite = new SpriteRenderer (m_ptrTexture);

	m_ptrtTitle = (DadEngine::SFText*)DadEngine::DataManager::GetInstance()->CreateAsset((int)DadEngine::DataManager::ASSETTYPE::SFTEXT, "title");
	m_ptrtTitle->GetText().setFont(m_ptrfTitleFont->GetFont());
	m_ptrtTitle->GetText().setString("CreaNaval");

	wnd->clear();

	m_ptrSprite->Draw();
	wnd->draw(m_ptrtTitle->GetText());
	wnd->display();*/

	// Lance la machine à etats
	ptrAGamestates[ucCurrentState];

	srand((unsigned)time(NULL));
}

void _Boucle()
{
#ifdef GRAPHIC_TEST
	while (wnd->isOpen())
	{
		sf::Event event;

		while (wnd->pollEvent(event))
		{
			if (event.Closed == event.type)
			{
				wnd->close();
			}

			if (event.KeyPressed == event.type)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					wnd->close();
				}
			}
		}

		wnd->clear();

		ptrAGamestates[ucCurrentState]();

		wnd->display();
	}
#endif
#ifdef CONSOLE_TEST
	while (bRunning)
	{
		cout << "\t\tProgramme des testes unitaire de la bibliohtèque de math" << endl << endl << endl;

		ptrAGamestates[ucCurrentState]();
	}
#endif
}

void _Delete()
{

}



// Quitte le programme
void _shutdown()
{
	bRunning = false;
}



// Permet de choisir une option parmis le nombre dispo en paramètre
void _choixOption(unsigned char _nOptionsMaximumDispo)
{
	unsigned short unCHoice = std::numeric_limits<short>::max(); // Pour une valeur hors de porter

	cout << "Entrez le chiffre correspondant a l'option choisis :" << endl << endl;

	_nOptionsMaximumDispo--; // La première option est attribuer à 0

	// Choix des options dispo
	while (_nOptionsMaximumDispo < unCHoice) // Tant que l'on entre pas une valeur viable
	{
		cin.sync();
		cin >> unCHoice;

		if ((ucCurrentState != MENU) && (unCHoice != (int)STATES::MENU && unCHoice != (int)STATES::SHUTDOWN)) // Uniquement quand on se trouve dans un sous menu
		{
			unCHoice = std::numeric_limits<short>::max();
		}

		if (_nOptionsMaximumDispo < unCHoice)
		{
			cout << endl << "Entrez une valeur utilisable par l'application" << endl << endl;
			cin.clear();
		}
	}

	ucCurrentState = (unsigned char)unCHoice;
}