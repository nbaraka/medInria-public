/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractGaussianFilterProcessPresenter.h>
#include <dtkMedBridge.h>


class dtkMedBridgePresenter: public medAbstractGaussianFilterProcessPresenter
{
    Q_OBJECT
public:
    dtkMedBridgePresenter(dtkMedBridge *parent)
        : medAbstractGaussianFilterProcessPresenter(parent)
    {m_process = parent;}
    virtual dtkMedBridge* process() const {return m_process;}
private:
    dtkMedBridge *m_process;
};


inline medAbstractGaussianFilterProcessPresenter* dtkMedBridgePresenterCreator(medAbstractProcess* abstractProcess) 
{ 
    medAbstractGaussianFilterProcessPresenter *presenter = NULL; 
    if(dtkMedBridge *process = qobject_cast<dtkMedBridge *>(abstractProcess)) 
        presenter = new dtkMedBridgePresenter(process); 
    return presenter; 
}
