/** \brief Inherits from Function **/

#ifndef NELDERMID_FUNCTIONOPTIMIZE_H
#define NELDERMID_FUNCTIONOPTIMIZE_H

#include "FunctionImplementation.h"

class Function1 : public FunctionImplementation {
public:
    double getFunctionValue(const std::vector<double> &x) const override;

    Function1(int _dim, const std::vector<double> &upper, const std::vector<double> &lower);
};


#endif //NELDERMID_FUNCTIONOPTIMIZE_H
