#include <iostream>
#include "matrixnxm.h"

int main(int argc, const char * argv[]) {
    Matrixmxn A;
    double array[] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    Matrixmxn B(3, 3, array);
    
    A = Matrixmxn(3, 2);
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);
    A.set(2, 0, 5); A.set(2, 1, 6);
    
    Matrixmxn C(3, 2);
    C.set(0, 0, 1); C.set(0, 1, 2);
    C.set(1, 0, 3); C.set(1, 1, 4);
    C.set(2, 0, 5); C.set(2, 1, 6);
    
    Matrixmxn D(2, 3);
    D.set(0, 0, 1); D.set(0, 1, 2); D.set(0, 2, 3);
    D.set(1, 0, 4); D.set(1, 1, 5); D.set(1, 2, -6);
    
    double A_array[] = {3,  4,  2,  1,  2,  3, -1, -2, -3,  5,  2, -1, 10,  2, -2};
    double D_array[] = {3,  2,  1,  1,  0, -3};
    
    Matrixmxn AA(5, 3, A_array);
    Matrixmxn DD(3, 2, D_array);
    
    (AA * DD).print();
//    A.print();
    return 0;
}
