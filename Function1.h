/** \brief Inherits from Function **/

#ifndef NELDERMID_FUNCTIONOPTIMIZE_H
#define NELDERMID_FUNCTIONOPTIMIZE_H

#include "Function.h"

class Function1 : public Function {
public:
    double getFunctionValue(const std::vector<double> &x) const override;

    Function1(int _dim, const std::vector<double> &upper, const std::vector<double> &lower);

    SquareArea getDomain() const override;

private:
    int dim; /** Dimension of the area **/
    SquareArea area; /** Object of class SquareArea where the current function is defined **/
};


#endif //NELDERMID_FUNCTIONOPTIMIZE_H
