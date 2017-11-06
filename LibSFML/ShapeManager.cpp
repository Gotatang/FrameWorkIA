/*Documentation																	*/
/*@author	:	Quentin Ladevie													*/
/*@file		:	ShapeManager.cpp												*/
/*@date		:	15/12/2015														*/
/*@brief	:	Fichier source de la classe de gestions des formes instancier	*/
#include "stdafx.h"
#include "ShapeManager.hpp"


namespace DadEngine
{
	ShapeManager::ShapeManager()
	{}


	ShapeManager::~ShapeManager()
	{
		m_mInstanciedFromTextFile.clear();
	}


	// Parsing functions
	void ShapeManager::ParseFile(const string& _sFilename)
	{
		ifstream file(_sFilename);

		if (!file.is_open())
		{
			cout << "File " + _sFilename + " can't be opened" << endl << endl;

			file.close();
		}

		while (file.good())
		{
			// Read one line of the file
			char szFileStream[256] = "\0";

			file.getline((char*)szFileStream, sizeof(szFileStream));


			// Put the line into a string
			vector<string> sSplitedLine;
			string s(szFileStream);

			Split(sSplitedLine, s, ' ');


			// Browse the data from this line
			vector<float> vShapeDatas;
			Shape* ptrsNewShape = NULL;

			// Get new shape components
			for (size_t i = 2; i < sSplitedLine.size(); ++i) // i = 2 because 0 = data type & 1 = name in map
			{
				float fNewValue = std::stof(sSplitedLine[i]); // Convert string to float

				vShapeDatas.push_back(fNewValue);
			}

			// Create a pointer to the wanted type shape
			if (Strcicmp(sSplitedLine[0].c_str(), "CIRCLE"))
			{
				// 0 -> point count
				// 1 -> radius
				ptrsNewShape = new Circle(vShapeDatas[1], (int)vShapeDatas[0]);
			}

			if (Strcicmp(sSplitedLine[0].c_str(), "BOX"))
			{
				// 0 -> width
				// 1 -> height
				// 2 -> depth
				ptrsNewShape = new Box(vShapeDatas[0], vShapeDatas[1], vShapeDatas[2]);
			}

			if (Strcicmp(sSplitedLine[0].c_str(), "SPHERE"))
			{
				// 0 -> point count
				// 1 -> radius
				ptrsNewShape = new Sphere(vShapeDatas[1], (int)vShapeDatas[0]);
			}

			if (Strcicmp(sSplitedLine[0].c_str(), "POLYGON2"))
			{
				// 0 -> point count
				ptrsNewShape = new Polygon2((int)vShapeDatas[0]);
			}

			if (Strcicmp(sSplitedLine[0].c_str(), "POLYGON3"))
			{
				// 0 -> point count
				ptrsNewShape = new Polygon3((int)vShapeDatas[0]);
			}

			if (Strcicmp(sSplitedLine[0].c_str(), "RECTANGLE"))
			{
				// 0 -> width
				// 1 -> height
				ptrsNewShape = new Rectangle(vShapeDatas[0], vShapeDatas[1]);
			}

			// Add new shape to the map
			m_mInstanciedFromTextFile.insert(std::pair<string, Shape*>(sSplitedLine[1], ptrsNewShape));


			cout << typeid(*ptrsNewShape).name() << "has been load." << endl << endl;

			cout << *ptrsNewShape << endl;
		}

		file.close();
	}

	void ShapeManager::Split(vector<string>& _vSplitedString, string& _sOriginalString, char _cDelimiter)
	{
		stringstream ss(_sOriginalString);
		string sToken;

		while (std::getline(ss, sToken, _cDelimiter))
		{
			_vSplitedString.push_back(sToken);
		}
	}

	int ShapeManager::Strcicmp(char const *_sz1, char const *_sz2)
	{
		for (;; ++_sz1, ++_sz2) {
			int d = tolower(*_sz1) - tolower(*_sz2);
			if (d != 0 || !*_sz1)
				return d;
		}
	}


	// Debug
	void ShapeManager::Display()
	{
		for (map<string, Shape*>::iterator it = m_mInstanciedFromTextFile.begin(); it != m_mInstanciedFromTextFile.end(); ++it)
		{
			cout << typeid(*it).name() << "has been load." << endl << endl;

			cout << it->second << endl << endl;
		}
	}
}