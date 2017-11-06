/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Polygon3.hpp									*/
/*@date		:	10/12/2015										*/
/*@brief	:	Fichier d'en-tête des polygones en 3 dimensions	*/
#ifndef __POLYGON3_H_
#define __POLYGON3_H_

#include "ExportSFML.hpp"
#include "Shape3D.hpp"


namespace DadEngine
{
	class DADENGINE_SFMLAPI Polygon3 : public Shape3D
	{

	public:

		Polygon3(int _iCountPoint = 3);
		Polygon3(const Point3& _pOrigin, Point3& _pPosition, const Matrix33& _mDirection, int _iCountPoint = 3);
		Polygon3(const Polygon3& _p);

		virtual ~Polygon3();

		// Get/Set
		virtual Point3 GetPoint(int _iIndex) const;
		void SetPoint(const Point3& _pNewValue, int _iIndex);

		virtual int GetPointCount();
		void SetPointCount(int _iNewSize);


		// Operators
		Polygon3& operator= (const Polygon3& _p);


		// Display
		virtual void Draw(sf::RenderWindow* _wnd);


		// Debug
		virtual void Display() const;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Polygon3& _p);


	private:

		Point3* m_ptrpPoints;
		int m_iPointCount;
	};
}

#endif // __POLYGON3_H_