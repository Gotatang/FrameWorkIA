/*Documentation													*/
/*@author	:	Quentin Ladevie									*/
/*@file		:	Polygon2.hpp									*/
/*@date		:	08/12/2015										*/
/*@brief	:	Fichier d'en-tête des polygones en 2 dimensions	*/
#ifndef __POLYGON2_H_
#define __POLYGON2_H_

#include "ExportSFML.hpp"
#include "Shape2D.hpp"


#define POLYGON_RADIUS 10.f


namespace DadEngine
{
	class DADENGINE_SFMLAPI Polygon2 : public Shape2D
	{

	public:

		Polygon2(int _iPointCount = 3);
		Polygon2(Point2& _pOrigin, Point2& _pPosition, Matrix22& _mDirection, int _iPointCount = 3);
		Polygon2(const Polygon2& _p);

		virtual ~Polygon2();


		// Get/Set
		virtual Point2 GetPoint(int _iIndex) const override;
		void SetPoint(const Point2& _pNewPoint, int _iIndex);

		virtual int GetPointCount() override;
		void SetPointCount(int _iNewSize);


		// Operators
		Polygon2& operator = (const Polygon2& _p);


		// Display
		virtual void Draw(SFTexture* _applyedTexture = NULL);


		// Debug
		virtual void Display() const;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Polygon2& _p);


	private:

		Point2* m_ptrpPoints;
		int m_iPointCount;
	};
}

#endif // __POLYGON2_H_