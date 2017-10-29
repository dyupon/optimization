//
// Created by User on 10/29/2017.
//

#ifndef NELDERMID_FUNCTION2_H
#define NELDERMID_FUNCTION2_H

#include "Function.h"
#include "FunctionImplementation.h"

class Function2 : public FunctionImplementation {
public:
    double getFunctionValue(const std::vector<double> &x) const override;

    Function2(int _dim, const std::vector<double> &upper, const std::vector<double> &lower);
};


#endif //NELDERMID_FUNCTION2_H
