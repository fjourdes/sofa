/***************************************************************************
                  StructuralComponentProperties.cpp  -  custom StructuralComponent properties
                             -------------------
    auto-generated       : Tuesday 6 July 2004 at 17:5:15
    copyright            : (C) 2001-2004 TIMC (E. Promayon, M. Chabanas)
    email                : Emmanuel.Promayon@imag.fr
    Date                 : $Date: 2004/07/06 16:00:22 $
    Version              : $Revision: 1.2 $
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "PhysicalModelIO.h"
#include "StructuralComponentProperties.h"

//--------------- Constructor -------------
void StructuralComponentProperties::init() {
    myCustomProperty1 = 0;
    myCustomProperty2 = "~";
    
}
 
//--------------- destructor --------------
StructuralComponentProperties::~StructuralComponentProperties()  {
}

// --------------- xmlPrint ---------------
void StructuralComponentProperties::xmlPrint(std::ostream &o) {
        
        // beginning of the atom properties
        beginXML(o);

		for(std::map<std::string, std::string>::iterator it = fields.begin(); it!=fields.end() ; it++)
			o << " "<<(*it).first<<"=\"" <<(*it).second<< "\" ";
        
        // print the custom properties only if different than default value
        if (myCustomProperty1 != 0) {
            o << " myCustomProperty1=\"" << myCustomProperty1 << "\" ";
        }
        if (myCustomProperty2 != "~") {
            o << " myCustomProperty2=\"" << myCustomProperty2 << "\" ";
        }
    
        // end of the properties
        endXML(o);
}

