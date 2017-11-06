// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <typeinfo>
#include <iterator>
#include <map>
#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <sstream>

using std::pair;
using std::iterator;
using std::map;
using std::string;
using std::cout;
using std::endl;
using std::list;
using std::ifstream;
using std::vector;
using std::stringstream;


// Include perso
// Math
#include "Point2.hpp"
#include "Point3.hpp"
#include "Vector2.hpp"
#include "Matrix22.hpp"
#include "Matrix33.hpp"
#include "Matrix44.hpp"
#include "Constants.h"

// Shapes
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Polygon2.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "Polygon3.hpp"
#include "ShapeList.hpp"

// SFML++
#include "GameManager.hpp"
#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "DataManager.hpp"
#include "EntityManager.hpp"

#include "SFTexture.hpp"
#include "SFText.hpp"
#include "SFFont.hpp"

#include "Entity.hpp"
#include "Component.hpp"

#include "Scene.hpp"

// SFMl
#include "SFML\Graphics.hpp"

// TODO: faites référence ici aux en-têtes supplémentaires nécessaires au programme
