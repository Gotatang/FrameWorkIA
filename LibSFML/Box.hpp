/*Documentation								*/
/*@author	:	Quentin Ladevie				*/
/*@file		:	Box.hpp						*/
/*@date		:	09/12/2015					*/
/*@brief	:	Fichier d'en-tête des cubes	*/
#ifndef __BOX_H_
#define __BOX_H_

#include "ExportSFML.hpp"
#include "Shape3D.hpp"


#define BOX_POINT_COUNT 8


namespace DadEngine
{
	class DADENGINE_SFMLAPI Box : public Shape3D
	{

	public:

		Box(float _fWidth = 1.f, float _fheight = 1.f, float _fDepth = 1.f);
		Box(const Point3& _pOrigin, const Point3& _pPosition, const Matrix33& _mDirection, float _fWidth = 1.f, float _fheight = 1.f, float _fDepth = 1.f);

		~Box();


		// Get/Set
		virtual Point3 GetPoint(int _iIndex) const override;
		virtual int GetPointCount() override;


		float GetWidth() const;
		float GetHeight() const;
		float GetDepth() const;

		void SetWidth(float _fNewWidth);
		void SetHeight(float _fNewHeight);
		void SetDepth(float _fNewDepth);


		// Display
		virtual void Draw(sf::RenderWindow* _wnd);


		// Debug
		virtual void Display() const;

		DADENGINE_SFMLAPI friend ostream& operator<< (ostream& _out, const Box& _b);


	private:

		float m_fWidth, m_fHeight, m_fDepth;
	};
}

#endif // __BOX_H_