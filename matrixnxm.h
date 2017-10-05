#include <stdio.h>
#include "abstract_matrix.h"


class Matrixmxn : public AbstractMatrix
{
public:
    bool set(unsigned i, unsigned j, double value);
    double get(unsigned i, unsigned j);
    Matrixmxn& operator+(Matrixmxn &B);
    Matrixmxn& operator*(Matrixmxn &B);
    void print();
    Matrixmxn(unsigned m, unsigned n, double *array);
    Matrixmxn(unsigned m, unsigned n);
    Matrixmxn();
protected:
    unsigned m;
    unsigned n;
};
