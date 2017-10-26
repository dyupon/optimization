#ifndef NELDERMID_FUNCTION_H
#define NELDERMID_FUNCTION_H

#include <vector>
#include "AbstractArea.h"
#include "SquareArea.h"

class Function {
public:
    virtual double getFunctionValue(const std::vector<double> &x) const = 0;

    virtual SquareArea getDomain() const = 0;
};



#endif //NELDERMID_FUNCTION_H
