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
#pragma once

#include <QObject>


class dtkImage;
#include "itkImage.h"
#include <dtkItkPixelTypeTrait.h>

template <typename Pixel, int dim> class dtkPixelClassDataExtractor
{
public:
	static typename Pixel::PixelType* getData(typename itk::Image<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType,dim>::Pointer image)
	{
        return (typename Pixel::PixelType*)(image->GetBufferPointer()->GetDataPointer());
	}
};

template <typename Pixel, int dim> class dtkPixelRawDataExtractor
{
public:
	static typename Pixel::PixelType* getData(typename itk::Image<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType,dim>::Pointer image)
	{
        return (typename Pixel::PixelType*)(image->GetBufferPointer());
	}
};

template <typename Pixel, int dim> class  dtkItkImageConverter
{

public:
    typedef itk::Image<typename dtkItkPixelTypeTrait<Pixel>::itkPixelType,dim> ItkImageType;

    static typename ItkImageType::Pointer convertToNative(dtkImage* source);
    static void convertFromNative(typename ItkImageType::Pointer source,dtkImage* target);
};

#include "dtkItkImageConverter.tpp"

//
