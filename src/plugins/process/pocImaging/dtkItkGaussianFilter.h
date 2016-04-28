#pragma once

#include <dtkCore>
#include <dtkImaging.h>

class dtkItkGaussianFilterPrivate;

class dtkItkGaussianFilter : public dtkAbstractGaussianFilter
{
    Q_OBJECT

public:
     dtkItkGaussianFilter(void);
    ~dtkItkGaussianFilter(void);

public:
    virtual void setSigma(double sigma);
    virtual void setImage(dtkImage* image);

public: 
    virtual dtkImage* filteredImage(void) const;

public:
    void run();
    template < typename ImgT, int dim > void exec(void);

private:
    dtkItkGaussianFilterPrivate* d;
};

