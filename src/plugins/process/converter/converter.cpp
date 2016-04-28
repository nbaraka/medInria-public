#include "converter.h"

#include <medAbstractImageData.h>
#include <medAbstractDataFactory.h>
#include <dtkImaging>
#include <dtkCore.h>


dtkImage* converter::toDtkImage(medAbstractImageData* medImage)
{
    if(!medImage)
        return NULL;            
            
            
    dtkImage* image = new dtkImage();
    dtkImageData* imageData = NULL;
    QString id=medImage->identifier();

    if ( id == "itkDataImageChar3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<char>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (char*)medImage->image());
    else if ( id == "itkDataImageUChar3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<unsigned char>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (unsigned char*)medImage->image());
    else if ( id == "itkDataImageShort3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<short>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (short*)medImage->image());
    else if ( id == "itkDataImageUShort3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<unsigned short>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (unsigned short*)medImage->image());
    else if ( id == "itkDataImageInt3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<int>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (int*)medImage->image());
    else if ( id == "itkDataImageUInt3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<unsigned int>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (unsigned int*)medImage->image());
    else if ( id == "itkDataImageLong3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<long>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (long*)medImage->image());
    else if ( id== "itkDataImageULong3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<unsigned long>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (unsigned long*)medImage->image());
    else if ( id == "itkDataImageFloat3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<float>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (float*)medImage->image());
    else if ( id == "itkDataImageDouble3" )
        imageData = new dtkImageDefaultStorage<dtkScalarPixel<double>, 3>(medImage->xDimension(), medImage->yDimension(), medImage->zDimension(), (double*)medImage->image());

    image->setData(imageData);
    return image;
}

medAbstractImageData* converter::toMedImage(dtkImage* image)
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<image;
    QString id="itkDataImage";
    switch(image->storageType())
    {
        case QMetaType::Char:
            id+="Char";
        break;
        
        case QMetaType::UChar:
            id+="UChar";
        break;
        
        case QMetaType::Short:
            id+="Short";
        break;

        case QMetaType::UShort:
            id+="UShort";
        break;
            
        case QMetaType::Int:
            id+="Int";
        break;
            
        case QMetaType::UInt:
            id+="UInt";
        break;
    
        case QMetaType::Long:
            id+="Long";
        break;
            
        case QMetaType::ULong:
            id+="ULong";
        break;
 
        case QMetaType::Float:
            id+="Float";
        break;
            
        case QMetaType::Double:
            id+="Double";
        break;
    }
    qDebug()<<Q_FUNC_INFO<<__LINE__;
    id+=QString::number(image->dim());
    medAbstractImageData *out= qobject_cast<medAbstractImageData *>(medAbstractDataFactory::instance()->create(id));
        qDebug()<<Q_FUNC_INFO<<__LINE__<<out<<image<<image->rawData()<<image->extent();
    out->setData(image->rawData());
        qDebug()<<Q_FUNC_INFO<<__LINE__;
    return out;
}
