//dma.h --inheritance and dynamic memory allocation

#ifndef DMA_H_
#define DMA_H_

#include <iostream>

//Abstract Base Class
class DMAABC{
private:
    char * label;
    int rating;
public:
    DMAABC(const char * l = "null", int r = 0);
    DMAABC(const DMAABC & rs);
    virtual ~DMAABC();
    DMAABC & operator=(const DMAABC & rs);
    virtual void view() const = 0;
};

//baseDMA
class baseDMA :public DMAABC{
public:
     baseDMA(const char * l = "null", int r = 0) :DMAABC(l,r){};
     baseDMA(const DMAABC & rs) :DMAABC(rs){};
     virtual void view() const;
};

//lacksDMA
class lacksDMA :public DMAABC{
private:
     enum {COL_LEN = 40};
     char color[COL_LEN];
public:
     lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
     lacksDMA(const char * c, const DMAABC & rs);
     virtual void view() const;
};

//hadDMA
class hasDMA :public DMAABC{
private:
     char * style;
public:
     hasDMA(const char * s = "none", const char * l = "null", int r = 0);
     hasDMA(const char * s, const DMAABC & rs);
     hasDMA(const hasDMA & hs);
     ~hasDMA();
     hasDMA & operator=(const hasDMA & hs);
     virtual void view() const;
};

#endif
