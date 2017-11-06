/*Documentation									*/
/*@author	:	Quentin Ladevie					*/
/*@file		:	Sphere.hpp						*/
/*@date		:	10/12/2015						*/
/*@brief	:	Fichier d'en-tête des spheres	*/
#ifndef __SPHERE_H_
#define __SPHERE_H_

#include "ExportSFML.hpp"
#include "Shape3D.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Sphere : public Shape3D
	{

	public:

		Sphere(float _fRadius = 1.f, int _iCountTriangle = 100);
		Sphere(const Point3& _pOrigin, const Point3& _pPosition, const Matrix33& _mDirection, float _fRadius = 1.f, int _iCountTriangle = 100);

		virtual ~Sphere();


		// Get/Set
		virtual Point3 GetPoint(int _iIndex) const override;
		virtual int GetPointCount() override;


		float GetRadius() const;
		void SetRadius(float _fNewRadius);


		// Display
		virtual void Draw(sf::RenderWindow* _wnd);


		// Debug
		virtual void Display() const;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Sphere& _s);


	private:

		float m_fRadius;
		int m_iCountTriangle;
	};
}

#endif // __SPHERE_H_