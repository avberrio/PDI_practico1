#include <iostream>
#include <stdexcept>
#include "matrixnxm.h"

bool Matrixmxn::set(unsigned i, unsigned j, double value)
{
    if (i < 100 || j < 100)
    {
        double *tmp;
        tmp = data_p;
        tmp += this->n * i + j;
        *tmp = value;
        return true;
    }
    else
    {
        return false;
    }
}

double Matrixmxn::get(unsigned i, unsigned j)
{
    return *(data_p + this->n * i + j);
}

Matrixmxn& Matrixmxn::operator+(Matrixmxn &B)
{
    if (this->m != B.m || this->n != B.n)
    {
        throw std::invalid_argument("Para sumar matrices, asegurese de que tengan la misma dimension mxn");
    }
    Matrixmxn *result = new Matrixmxn(this->m, this->n);
    for (unsigned i = 0; i < this->m; i++)
        for (unsigned j = 0; j < this->n; j++)
        {
            result->set(i, j, this->data_p[this->n * i + j] + B.get(i, j));
        }
    return *result;
}

Matrixmxn& Matrixmxn::operator*(Matrixmxn &B)
{
    if (this->n != B.m)
    {
        throw std::invalid_argument("Dimensiones no coinciden");
    }
    Matrixmxn *result = new Matrixmxn(this->m, B.n);
    for (unsigned ri = 0; ri < this->m; ri++)
    {
        for (unsigned rj = 0; rj < B.n; rj++)
        {
            double tmp = 0;
            for (unsigned k = 0; k < this->n; k++)
            {
                tmp += this->get(ri, k) * B.get(k, rj);
            }
            result->set(ri, rj, tmp);
        }
    }
    return *result;
}

void Matrixmxn::print()
{
    for (unsigned i = 0; i < this->m; i++)
    {
        for (unsigned j = 0; j < this->n; j++)
        {
            std::cout << this->get(i, j);
            if (j < this->n - 1)
            {
                std::cout << "; ";
            }
            if (j == this->n - 1)
            {
                std::cout << std::endl;
            }
        }
    }
}

Matrixmxn::Matrixmxn()
{
    
}

Matrixmxn::Matrixmxn(unsigned m, unsigned n, double *array)
{
    if (m > 100 || n > 100)
    {
        throw std::invalid_argument("Las matriz debe tener a lo mas una dimension de 100x100");
    }
    this->m = m;
    this->n = n;
    data_p = array;
}

Matrixmxn::Matrixmxn(unsigned m, unsigned n)
{
    if (m > 100 || n > 100)
    {
        throw std::invalid_argument("Las matriz debe tener a lo mas una dimension de 100x100");
    }
    this->m = m;
    this->n = n;
    data_p = new double[m * n];
}


