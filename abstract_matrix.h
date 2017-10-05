#ifndef ABSTRACT_MATRIX 
#define ABSTRACT_MATRIX 

#include <iostream> 
#include <vector> 

using namespace std;
 
class AbstractMatrix 
{
public: 
	virtual bool set(unsigned i, unsigned j, double value) = 0;
	virtual double get(unsigned i, unsigned j) = 0; 
	virtual void print() = 0; 
protected: // Ud puede elegir utilizar uno de estos atributos 
	double* data_p; 
	vector<double> data_v; 
}; 
#endif // ABSTRACT_MATRIX