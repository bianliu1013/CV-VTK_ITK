/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkHyperOctreeToUniformGridFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkHyperOctreeToUniformGridFilter
 * @brief   Flat the octree into a uniform
 * grid
 *
 * vtkHyperOctreeToUniformGridFilter creates a uniform grid with a resolution
 * based on the number of levels of the hyperoctree. Then, it copies celldata
 * in each cell of the uniform grid that belongs to an actual leaf of the
 * hyperoctree.
 *
 * @sa
 * vtkGeometryFilter vtkStructuredGridGeometryFilter.
*/

#ifndef vtkHyperOctreeToUniformGridFilter_h
#define vtkHyperOctreeToUniformGridFilter_h

#include "vtkFiltersHyperTreeModule.h" // For export macro
#include "vtkImageAlgorithm.h"

#if !defined(VTK_LEGACY_REMOVE)
class vtkHyperOctreeCursor;
class vtkCellData;
class vtkDataSetAttributes;

class VTKFILTERSHYPERTREE_EXPORT vtkHyperOctreeToUniformGridFilter : public vtkImageAlgorithm
{
public:
  static vtkHyperOctreeToUniformGridFilter *New();
  vtkTypeMacro(vtkHyperOctreeToUniformGridFilter,vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

protected:
  vtkHyperOctreeToUniformGridFilter();
  ~vtkHyperOctreeToUniformGridFilter() override;

  int RequestInformation (vtkInformation * vtkNotUsed(request),
                          vtkInformationVector **inputVector,
                          vtkInformationVector *outputVector) override;

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *) override;
  int FillInputPortInformation(int port, vtkInformation *info) override;

  void CopyCellData(int cellExtent[6]);

  // Variables used by generate recursively.
  // It avoids to pass to much argument.
  vtkDataSetAttributes *InputCD;
  vtkCellData *OutputCD;
  vtkHyperOctreeCursor *Cursor;
  int YExtent;
  int ZExtent;
  vtkImageData *Output;

private:
  vtkHyperOctreeToUniformGridFilter(const vtkHyperOctreeToUniformGridFilter&) = delete;
  void operator=(const vtkHyperOctreeToUniformGridFilter&) = delete;
};
#endif // LEGACY remove

#endif
