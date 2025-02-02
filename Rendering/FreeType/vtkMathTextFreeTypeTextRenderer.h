/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkMathTextFreeTypeTextRenderer.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

/**
 * @class   vtkMathTextFreeTypeTextRenderer
 * @brief   Default implementation of
 * vtkTextRenderer.
 *
 *
 * Default implementation of vtkTextRenderer using vtkFreeTypeTools and
 * vtkMathTextUtilities.
 *
 * @warning
 * The MathText backend does not currently support UTF16 strings, thus
 * UTF16 strings passed to the MathText renderer will be converted to
 * UTF8.
 */

#ifndef vtkMathTextFreeTypeTextRenderer_h
#define vtkMathTextFreeTypeTextRenderer_h

#include "vtkRenderingFreeTypeModule.h" // For export macro
#include "vtkTextRenderer.h"

class vtkFreeTypeTools;
class vtkMathTextUtilities;

class VTKRENDERINGFREETYPE_EXPORT vtkMathTextFreeTypeTextRenderer : public vtkTextRenderer
{
public:
  vtkTypeMacro(vtkMathTextFreeTypeTextRenderer, vtkTextRenderer);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  static vtkMathTextFreeTypeTextRenderer* New();

  ///@{
  /**
   * Test for availability of various backends
   */
  bool FreeTypeIsSupported() override;
  bool MathTextIsSupported() override;
  ///@}

  /**
   * Set the visibility of the interior lines when Matplotlib is used for the rendering.
   * Transfer call to vtkMatplotlibMathTextUtilities. Default is false.
   */
  void SetInteriorLinesVisibility(bool visibility);

  /**
   * Set the width (in pixels) of the interior lines when Matplotlib is used for the rendering.
   * Transfer call to vtkMatplotlibMathTextUtilities. Default is 1.
   */
  void SetInteriorLinesWidth(int width);

  /**
   * Set the color of the interior lines when Matplotlib is used for the rendering.
   * Transfer call to vtkMatplotlibMathTextUtilities. Default is black (0.0, 0.0, 0.0).
   */
  void SetInteriorLinesColor(double colorR, double colorG, double colorB);

protected:
  vtkMathTextFreeTypeTextRenderer();
  ~vtkMathTextFreeTypeTextRenderer() override;

  ///@{
  /**
   * Reimplemented from vtkTextRenderer.
   */
  bool GetBoundingBoxInternal(
    vtkTextProperty* tprop, const vtkStdString& str, int bbox[4], int dpi, int backend) override;
  bool GetBoundingBoxInternal(vtkTextProperty* tprop, const vtkUnicodeString& str, int bbox[4],
    int dpi, int backend) override;
  bool GetMetricsInternal(vtkTextProperty* tprop, const vtkStdString& str, Metrics& metrics,
    int dpi, int backend) override;
  bool GetMetricsInternal(vtkTextProperty* tprop, const vtkUnicodeString& str, Metrics& metrics,
    int dpi, int backend) override;
  bool RenderStringInternal(vtkTextProperty* tprop, const vtkStdString& str, vtkImageData* data,
    int textDims[2], int dpi, int backend) override;
  bool RenderStringInternal(vtkTextProperty* tprop, const vtkUnicodeString& str, vtkImageData* data,
    int textDims[2], int dpi, int backend) override;
  int GetConstrainedFontSizeInternal(const vtkStdString& str, vtkTextProperty* tprop,
    int targetWidth, int targetHeight, int dpi, int backend) override;
  int GetConstrainedFontSizeInternal(const vtkUnicodeString& str, vtkTextProperty* tprop,
    int targetWidth, int targetHeight, int dpi, int backend) override;
  bool StringToPathInternal(
    vtkTextProperty* tprop, const vtkStdString& str, vtkPath* path, int dpi, int backend) override;
  bool StringToPathInternal(vtkTextProperty* tprop, const vtkUnicodeString& str, vtkPath* path,
    int dpi, int backend) override;
  void SetScaleToPowerOfTwoInternal(bool scale) override;
  ///@}

private:
  vtkMathTextFreeTypeTextRenderer(const vtkMathTextFreeTypeTextRenderer&) = delete;
  void operator=(const vtkMathTextFreeTypeTextRenderer&) = delete;

  vtkFreeTypeTools* FreeTypeTools;
  vtkMathTextUtilities* MathTextUtilities;
};

#endif // vtkMathTextFreeTypeTextRenderer_h
