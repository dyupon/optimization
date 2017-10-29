//
// Created by User on 10/29/2017.
//

#ifndef NELDERMID_FUNCTION2_H
#define NELDERMID_FUNCTION2_H

#include "Function.h"

class Function2 : public Function {
public:
    double getFunctionValue(const std::vector<double> &x) const override;

    Function2(int _dim, const std::vector<double> &upper, const std::vector<double> &lower);

    SquareArea getDomain() const override;

private:
    int dim; /** Dimension of the area **/
    SquareArea area; /** Object of class SquareArea where the current function is defined **/

};


#endif //NELDERMID_FUNCTION2_H
