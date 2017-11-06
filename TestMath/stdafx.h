// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdarg.h>
#include <cassert>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


// Include perso
#include "Constants.h"
#include "Point2.hpp"
#include "Point3.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Triangle2.hpp"
#include "Triangle3.hpp"
#include "Vector.hpp"
#include "Matrix22.hpp"
#include "Matrix33.hpp"
#include "Matrix44.hpp"
#include "Transform2.hpp"
#include "Transform3.hpp"

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Polygon2.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "Polygon3.hpp"

#include "SFML\Graphics.hpp"


#include "GameManager.hpp"
#include "SFFont.hpp"
#include "SFText.hpp"
#include "DataManager.hpp"
#include "SpriteRenderer.hpp"

// TODO: faites référence ici aux en-têtes supplémentaires nécessaires au programme
