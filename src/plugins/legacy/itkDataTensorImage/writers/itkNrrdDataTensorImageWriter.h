#pragma once
/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2020. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <itkDataTensorImagePluginExport.h>
#include <itkDataTensorImageWriterBase.h>

class ITKDATATENSORIMAGEPLUGIN_EXPORT itkNrrdDataTensorImageWriter : public itkDataTensorImageWriterBase
{
    Q_OBJECT

public:
    itkNrrdDataTensorImageWriter();
    virtual ~itkNrrdDataTensorImageWriter();

    virtual QString identifier()  const;
    virtual QString description() const;
    virtual QStringList supportedFileExtensions() const;

    static bool registered();

    static dtkAbstractDataWriter* create();
};
