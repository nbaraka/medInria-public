#pragma once

#include "dtkPixelImpl.h"
#include "itkRGBPixel.h"
#include "itkRGBAPixel.h"

template <typename PixelType> class dtkItkPixelTypeTrait;

template<>
template<class StorageType >
class dtkItkPixelTypeTrait<dtkScalarPixel<StorageType> >
{
public:
    typedef StorageType itkPixelType;
};

template<>
template<class StorageType >
class dtkItkPixelTypeTrait<dtkRGBPixel<StorageType> >
{
public:
    typedef itk::RGBPixel<StorageType> itkPixelType;
};

template<>
template<class StorageType >
class dtkItkPixelTypeTrait<dtkRGBAPixel<StorageType> >
{
    public:
    typedef itk::RGBAPixel<StorageType> itkPixelType;
};
