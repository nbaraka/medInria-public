#pragma once
/*============================================================================

The Hardware Shading (HWShading) module is protected by the
following copyright:
Copyright (c) 2007 Biomedical Image Analysis (BMIA) - Department of
Biomedical Engineering - Eindhoven University of Technology.
All rights reserved. See Copyright.txt for details.
The HWShading implementation was originally written by Tim Peeters (BMIA - TUe)
and published at the "11th International Fall Workshop on Vision, Modeling,
and Visualization 2006" (VMV'06):
"Visualization of the Fibrous Structure of the Heart", by T. Peeters et al.
See http://timpeeters.com/research/vmv2006 for more information.
This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.
============================================================================*/
/**
 * vtkUniformVec3.h
 *
 * 2005-05-17	Tim Peeters
 * - First version
 */

#include <medVtkInriaExport.h>

#include <vtkShaderUniform.h>

/**
 * Class for representing uniform vec3 variables.
 */
class MEDVTKINRIA_EXPORT vtkUniformVec3: public vtkShaderUniform
{
public:
  static vtkUniformVec3* New();
  vtkTypeMacro(vtkUniformVec3, vtkShaderUniform)

  vtkSetVector3Macro(Value, float)
  vtkGetVector3Macro(Value, float)

protected:
  vtkUniformVec3();
  ~vtkUniformVec3();

  virtual void SetGlUniformSpecific();

private:
  float Value[3];
};


