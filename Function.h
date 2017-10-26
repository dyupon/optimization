/** \brief Base abstract class for function definition **/


#ifndef NELDERMID_FUNCTION_H
#define NELDERMID_FUNCTION_H

#include <vector>
#include "AbstractArea.h"
#include "SquareArea.h"

class Function {
public:
    virtual double getFunctionValue(const std::vector<double> &x) const = 0; /** Gets function value at point x **/

    virtual SquareArea
    getDomain() const = 0; /** Gets an object of class SquareArea where current function is defined **/
};


#endif //NELDERMID_FUNCTION_H
