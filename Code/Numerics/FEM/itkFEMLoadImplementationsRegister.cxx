/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkFEMLoadImplementationsRegister.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

// disable debug warnings in MS compiler
#ifdef _MSC_VER
#pragma warning(disable: 4786)
#endif

#include "itkVisitorDispatcher.h"
#include "itkFEMElements.h"
#include "itkFEMLoads.h"

namespace itk {
namespace fem {




/* This macro makes registering Load implementations easier. */
#define REGISTER_LOAD(ElementClass,LoadClass,FunctionName) \
  extern Element::LoadVectorType FunctionName(ElementClass::ConstPointer, Element::LoadElementPointer); \
  VisitorDispatcher<ElementClass, Element::LoadElementType, Element::LoadVectorType>::RegisterVisitor((LoadClass*)0, &FunctionName);



/**
 * Registers all Load classes in the FEM library with VisitorDispatcher.
 * This function must be calles before the FEM library is functional!.
 */
void LoadImplementationsRegister(void)
{

  // Loads acting on Bar2D element
  REGISTER_LOAD( Bar2D,        LoadGrav,         LoadGravImplementationBar2D    );
  REGISTER_LOAD( Bar2D,        LoadGravConst,    LoadGravImplementationBar2D    );
  REGISTER_LOAD( Bar2D,        LoadPoint,        LoadPointImplementationBar2D   );

  // Loads acting on Beam2D element
  REGISTER_LOAD( Beam2D,       LoadGrav,         LoadGravImplementationBeam2D   );
  REGISTER_LOAD( Beam2D,       LoadGravConst,    LoadGravImplementationBeam2D   );
  REGISTER_LOAD( Beam2D,       LoadPoint,        LoadPointImplementationBeam2D  );

  // Loads acting on TriC02D element
  REGISTER_LOAD( TriC02D,      LoadGrav,         LoadGravImplementationTriC02D  );
  REGISTER_LOAD( TriC02D,      LoadGravConst,    LoadGravImplementationTriC02D  );
  REGISTER_LOAD( TriC02D,      LoadEdge,         LoadEdgeImplementationTriC02D  );

  // Loads acting on QuadC02D element
  REGISTER_LOAD( QuadC02D,     LoadGrav,         LoadGravImplementationQuadC02D );
  REGISTER_LOAD( QuadC02D,     LoadGravConst,    LoadGravImplementationQuadC02D );
  REGISTER_LOAD( QuadC02D,     LoadEdge,         LoadEdgeImplementationQuadC02D );

  // Loads acting on MembraneC02D element
  REGISTER_LOAD( MembraneC02D, LoadGrav,         LoadGravImplementationMembraneC02D );
  
/*  typedef Image< unsigned char, 2 > ImageType;
  VisitorDispatcher<MembraneC02D, LoadElement, Element::LoadVectorType>
    ::RegisterVisitor( (LoadImagePairBase<ImageType,ImageType>*)0, 
                       &LoadGravImplementationMembraneC02D ); */

  // Loads acting on C1IsoCurve2D element
  REGISTER_LOAD( C1IsoCurve2D, LoadElement,      LoadImplementationC1IsoCurve2D );

  // Loads acting on HexahedronC03D element
  REGISTER_LOAD( HexahedronC03D, LoadGrav,       LoadGravImplementationHexahedronC03D );
  REGISTER_LOAD( HexahedronC03D, LoadGravConst,  LoadGravImplementationHexahedronC03D );

  // Loads acting on HexahedronC03D element
  REGISTER_LOAD( TetrahedronC03D, LoadGrav,      LoadGravImplementationTetrahedronC03D );  
  REGISTER_LOAD( TetrahedronC03D, LoadGravConst, LoadGravImplementationTetrahedronC03D );

  // Add any additional loads here in a similar fashion...
  // Make sure that the pointer to the visit function is the correct one!!!

}




}} // end namespace itk::fem
