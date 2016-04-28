#pragma once

#include <dtkCore>
#include <medAbstractGaussianFilterProcess.h>
#include <medAbstractSingleFilterOperationProcess.h>

class dtkImagingGaussianFilterBridgePlugin: public medAbstractSingleFilterOperationProcessPlugin
{
    Q_OBJECT
    Q_INTERFACES(medAbstractSingleFilterOperationProcessPlugin)
    Q_PLUGIN_METADATA(IID "fr.inria.medAbstractSingleFilterOperationProcessPlugin" FILE "dtkImagingGaussianFilterBridgePlugin.json")

public:
     dtkImagingGaussianFilterBridgePlugin(void) {}
    ~dtkImagingGaussianFilterBridgePlugin(void) {}

public:
    void initialize(void);
    void uninitialize(void);
};

