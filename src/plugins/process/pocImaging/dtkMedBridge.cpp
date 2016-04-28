#include "dtkMedBridge.h"

#include "medDoubleParameter.h"
#include "medCore.h"
#include "medAbstractImageData.h"

dtkMedBridge::dtkMedBridge(QObject* parent): medAbstractGaussianFilterProcess(parent)
{
 
}
 
dtkMedBridge::~dtkMedBridge()
{

}


medAbstractJob::medJobExitStatus dtkMedBridge::run()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    medAbstractImageData* medImage = this->input();
    double sigma=this->doubleParameter()->value();
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    
    QStringList convKeys=medCore::converter::pluginFactory().keys();
    if(convKeys.isEmpty())
        return medAbstractJob::MED_JOB_EXIT_FAILURE;
qDebug()<<Q_FUNC_INFO<<__LINE__;
    medAbstractConverter* convPlugin=medCore::converter::pluginFactory().create(convKeys.at(0));
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    
    dtkImage* image=convPlugin->toDtkImage(medImage);
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    dtkItkGaussianFilter filter;
    filter.setImage(image);
    filter.setSigma(sigma);
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    filter.run();
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    dtkImage* outImage = filter.filteredImage();
        qDebug()<<Q_FUNC_INFO<<__LINE__<<outImage;
    medAbstractImageData* outputImage = convPlugin->toMedImage(outImage);
        qDebug()<<Q_FUNC_INFO<<__LINE__<<outputImage;
    this->setOutput(outputImage);
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    return medAbstractJob::MED_JOB_EXIT_SUCCESS;
}
