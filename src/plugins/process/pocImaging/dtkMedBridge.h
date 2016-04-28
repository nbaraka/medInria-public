/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractGaussianFilterProcess.h>

#include <itkProcessObject.h>
#include <itkSmartPointer.h>

#include "dtkItkGaussianFilter.h"


class dtkMedBridge: public medAbstractGaussianFilterProcess
{
    Q_OBJECT
public:
    dtkMedBridge(QObject* parent = NULL);
    ~dtkMedBridge();

    virtual medAbstractJob::medJobExitStatus run();
    virtual void cancel() {}
    virtual QString caption() const {return QString("dtkImagingBridge");}
    virtual QString description() const {return QString("dtkImagingBridge");}
};

inline medAbstractGaussianFilterProcess* dtkImagingGaussianFilterBridgeCreator()
{
    return new dtkMedBridge();
}
