#pragma once

#include "IProduct.h"

class A : public ProductBase {
public:
    A( double APrice ) : ProductBase( "A", APrice ) { }
};

class B : public ProductBase {
public:
    B( double APrice ) : ProductBase( "B", APrice ) { }
};

class C : public ProductBase {
public:
    C( double APrice ) : ProductBase( "C", APrice ) { }
};

class D : public ProductBase {
public:
    D( double APrice ) : ProductBase( "D", APrice ) { }
};
