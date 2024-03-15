#pragma once
#include "TwoDimShape.h"
class Circle :
    public TwoDimShape
{
public:
    Circle(int, int, char);
    virtual void print();
    virtual double getArea() const;
    virtual void draw();


    bool operator<(const Circle&) const;
    bool operator<=(const Circle&) const;
    bool operator>(const Circle&) const;
    bool operator>=(const Circle&) const;
    bool operator==(const Circle&) const;
    bool operator!=(const Circle&) const;
private:
    const double p = 3.14;
};

