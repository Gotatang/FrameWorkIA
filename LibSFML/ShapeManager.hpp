/*Documentation																	*/
/*@author	:	Quentin Ladevie													*/
/*@file		:	ShapeManager.hpp												*/
/*@date		:	15/12/2015														*/
/*@brief	:	Fichier d'en-tête de la classe de gestions des formes instancier*/
#ifndef __SHAPEMANAGER_H_
#define __SHAPEMANAGER_H_

#include "Singleton.hpp"


namespace DadEngine
{
	class Shape;

	class DADENGINE_SFMLAPI ShapeManager : public Singleton<ShapeManager>
	{

		DADENGINE_SFMLAPI friend Singleton<ShapeManager>;


	public:

		ShapeManager();

		~ShapeManager();


		// Parsing functions
		void ParseFile(const std::string& _sFilename);

		void Split(std::vector<std::string>& _vSplitedString, std::string& _sOriginalString, char _cDelimiter);

		int Strcicmp(char const * _sz1, char const *_sz2);


		// Debug
		void Display();


	private:

		std::map<std::string, Shape*> m_mInstanciedFromTextFile;
	};
}

#endif // __SHAPEMANAGER_H_