#include "dtkImagingGaussianFilterBridgePlugin.h"
#include "dtkMedBridge.h"
#include "dtkMedBridgePresenter.h"
#include <medCore.h>
#include <medWidgets.h>
#include <dtkCore>
#include "dtkImaging.h"

// ///////////////////////////////////////////////////////////////////
// dtkItkGaussianFilterPlugin
// ///////////////////////////////////////////////////////////////////

void dtkImagingGaussianFilterBridgePlugin::initialize(void)
{
    medCore::singleFilterOperation::gaussianFilter::pluginFactory().record(dtkMedBridge::staticMetaObject.className(), dtkImagingGaussianFilterBridgeCreator);
    medWidgets::singleFilterOperation::gaussianFilter::presenterFactory().record(dtkMedBridge::staticMetaObject.className(), dtkMedBridgePresenterCreator);
    qDebug()<<dtkMedBridge::staticMetaObject.className();
}

void dtkImagingGaussianFilterBridgePlugin::uninitialize(void)
{

}

// ///////////////////////////////////////////////////////////////////
// Plugin meta data
// ///////////////////////////////////////////////////////////////////

DTK_DEFINE_PLUGIN(dtkImagingGaussianFilterBridge)

