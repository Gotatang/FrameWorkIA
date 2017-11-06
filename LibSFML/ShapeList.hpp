/*Documentation														*/
/*@author	:	Quentin Ladevie										*/
/*@file		:	ShapeList.hpp										*/
/*@date		:	12/12/2015											*/
/*@brief	:	Fichier d'en-tête de la liste des formes instancier	*/
#ifndef __SHAPELIST_H_
#define __SHAPELIST_H_

#include "ExportSFML.hpp"
#include "Singleton.hpp"
#include <list>


namespace DadEngine
{
	class Shape;

	class DADENGINE_SFMLAPI ShapeList : public Singleton<ShapeList>
	{

		DADENGINE_SFMLAPI friend Singleton<ShapeList>;


	public:

		ShapeList();

		~ShapeList();


		// Get
		std::list <Shape*> GetList() const;


		// Handling functions
		void Add(Shape* _s);
		void Delete(Shape* _s);
		void DeleteAll();


		// Debug
		void Display();


	protected:

		std::list<Shape*> m_lShapeList;
	};
}

#endif // __SHAPELIST_H_