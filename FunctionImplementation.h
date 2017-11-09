//
// Created by User on 10/29/2017.
//

#ifndef NELDERMID_FUNCTIONIMPLEMENTATION_H
#define NELDERMID_FUNCTIONIMPLEMENTATION_H


#include "Function.h"

class FunctionImplementation : public Function {
public:
    virtual ~FunctionImplementation() = default;

    double getFunctionValue(const std::vector<double> &x) const override = 0;

    FunctionImplementation(int _dim, const std::vector<double> &upper, const std::vector<double> &lower);

    SquareArea getDomain() const override;

private:
    int dim; /** Dimension of the area **/
    SquareArea area; /** Object of class SquareArea where the current function is defined **/

};


#endif //NELDERMID_FUNCTIONIMPLEMENTATION_H
