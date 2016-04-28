#include "dtkItkGaussianFilter.h"
#include "dtkItkImageConverter.h"

#include <dtkImaging.h>
#include <dtkFilterExecutor.h>

#include <itkImage.h>
#include <itkSmoothingRecursiveGaussianImageFilter.h>

// /////////////////////////////////////////////////////////////////
//
// /////////////////////////////////////////////////////////////////

class dtkItkGaussianFilterPrivate
{
    public:
        dtkImage* m_imageIn;
        dtkImage* m_imageOut;

        double m_sigma;
};
// ///////////////////////////////////////////////////////////////////
//
// ///////////////////////////////////////////////////////////////////

dtkItkGaussianFilter::dtkItkGaussianFilter(void): d(new dtkItkGaussianFilterPrivate)
{
    d->m_imageIn=NULL;
    d->m_imageOut=new dtkImage();
    
    d->m_sigma=0;
}

dtkItkGaussianFilter::~dtkItkGaussianFilter(void)
{
    if(d)
        delete d;
}

void dtkItkGaussianFilter::setSigma(double sigma)
{
    d->m_sigma=sigma;
}

void dtkItkGaussianFilter::setImage(dtkImage* image)
{
    d->m_imageIn=image;
}

dtkImage* dtkItkGaussianFilter::filteredImage(void) const
{
    return d->m_imageOut;
}

void dtkItkGaussianFilter::run(void)
{
    if(!d->m_imageIn)
        dtkWarn()<<Q_FUNC_INFO<<"no image input";
    
    dtkFilterExecutor<dtkItkGaussianFilter>::run(this, d->m_imageIn);
}

template < typename ImgT, int dim> inline void dtkItkGaussianFilter::exec(void)
{
    typedef itk::Image<typename dtkItkPixelTypeTrait<ImgT>::itkPixelType,dim> ImageType;
    typedef dtkItkImageConverter<ImgT,dim> Converter;
    typename ImageType::Pointer image=Converter::convertToNative(d->m_imageIn);

    if(image)
    {
        typedef itk::SmoothingRecursiveGaussianImageFilter <ImageType, ImageType> GaussianImageFilterType;
        typename GaussianImageFilterType::Pointer filter = GaussianImageFilterType::New();
        
        filter->SetInput(image);
        filter->SetSigma(d->m_sigma);
        
        filter->Update();
        Converter::convertFromNative(filter->GetOutput(),d->m_imageOut);
    }
        qDebug()<<Q_FUNC_INFO<<__LINE__;
}
