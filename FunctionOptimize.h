#ifndef NELDERMID_FUNCTIONOPTIMIZE_H
#define NELDERMID_FUNCTIONOPTIMIZE_H

#include "Function.h"

class FunctionOptimize : public Function {
public:
    double get_function_value(std::vector<double> x) override;
    explicit FunctionOptimize(int _dim);
    SquareArea get_domain() override;
private:
    int dim;
    SquareArea area;
};


#endif //NELDERMID_FUNCTIONOPTIMIZE_H
