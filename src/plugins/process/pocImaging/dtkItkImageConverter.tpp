// Version: $Id$
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include <dtkImaging.h>
#include <dtkImageData.h>
#include "itkImportImageFilter.h"


#include <dtkTemplatedImageData.h>
#include <dtkImageDefaultStorage.h>
#include <dtkPixelImpl.h>
#include <itkImage.h>
#include <dtkItkImageConverter.h>


template < typename Pixel, int dim> inline typename itk::Image<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType,dim>::Pointer dtkItkImageConverter<Pixel,dim>::convertToNative(dtkImage* source)
{
    dtkImageData* data=source->data();
    if(data->identifier()=="itkImageData")
        return NULL;
    if(data->identifier()!="default")
    {
        dtkWarn()<<"unknown input type, cannot convert";
        return NULL;
    }

    typedef itk::Image<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType,dim> ItkImageType;
    typedef itk::ImportImageFilter< typename dtkItkPixelTypeTrait<Pixel>::itkPixelType, dim >   ImportFilterType;
    typename ImportFilterType::Pointer importFilter = ImportFilterType::New();

    typename ImportFilterType::SizeType  size;

    for(int i=0;i<dim;i++)
        size[i]  = source->extent()[i];


     typename ImportFilterType::IndexType start;
     start.Fill( 0 );

     typename ImportFilterType::RegionType region;
     region.SetIndex( start );
     region.SetSize(  size  );

     importFilter->SetRegion( region );

     double origin[ dim ];
     for(int i=0;i<dim;i++)
        origin[i] = 0.0;


     importFilter->SetOrigin( origin );

     double spacing[ dim ];
     for(int i=0;i<dim;i++)
        spacing[i] = 1.0;

     importFilter->SetSpacing( spacing );
     unsigned int numberOfValues =1;
     for(int i=0;i<dim;i++)
        numberOfValues*=size[i];
     numberOfValues*=Pixel::PixelDim;

     importFilter->SetImportPointer( (typename dtkItkPixelTypeTrait<Pixel>::itkPixelType*)(source->rawData()), numberOfValues, false );
     importFilter->Update();
     return importFilter->GetOutput();
}

template < typename Pixel, int dim> void dtkItkImageConverter<Pixel,dim>::convertFromNative(typename itk::Image<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType,dim>::Pointer source, dtkImage* target)
{
    if(!target)
        target = new dtkImage(); 
qDebug()<< Q_FUNC_INFO<<__LINE__;
    typedef itk::Image<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType,dim> ImageType;

    typedef typename ImageType::SizeType SizeType;
    typedef typename ImageType::PointType PointType;
    typedef typename ImageType::SpacingType SpacingType;
qDebug()<< Q_FUNC_INFO<<__LINE__;
    typename ImageType::PixelContainer* container=source->GetPixelContainer();
    container->SetContainerManageMemory(false);
    dtkArray<qlonglong,dim> extent;
    dtkArray<double,dim> spacing(dim),origin(dim);
qDebug()<< Q_FUNC_INFO<<__LINE__;
    SizeType size = source->GetBufferedRegion().GetSize();
    for(int i=0;i<dim;i++)
        extent.append(size[i]);
qDebug()<< Q_FUNC_INFO<<__LINE__;
    PointType itkOrigin =source->GetOrigin();
    for(int i=0;i<itkOrigin.Size();i++)
        origin[i]=itkOrigin[i];
qDebug()<< Q_FUNC_INFO<<__LINE__;
    SpacingType itkSpacing=source->GetSpacing();
    for(int i=0;i<itkSpacing.Size();i++)
        spacing[i]=itkSpacing[i];
qDebug()<< Q_FUNC_INFO<<__LINE__;
    typedef typename std::conditional<std::is_class<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType>::value, dtkPixelClassDataExtractor<Pixel,dim>, dtkPixelRawDataExtractor<Pixel,dim> >::type DataExtractor;
qDebug()<< Q_FUNC_INFO<<__LINE__;

    typename Pixel::PixelType* data=DataExtractor::getData(source);
qDebug()<< Q_FUNC_INFO<<__LINE__;
    dtkImageDefaultStorage<Pixel,dim>* storage=new dtkImageDefaultStorage<Pixel,dim>(extent,data);
qDebug()<< Q_FUNC_INFO<<__LINE__<<extent;
    target->setData(storage);
    qDebug()<< Q_FUNC_INFO<<__LINE__;
    target->setSpacing(spacing);
    qDebug()<< Q_FUNC_INFO<<__LINE__;
    target->setOrigin(origin);
qDebug()<< Q_FUNC_INFO<<__LINE__;
}

//
// dtkFilterITK_p.h ends here
