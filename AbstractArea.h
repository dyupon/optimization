/** \brief Abstract base class for area **/

#ifndef NELDERMID_ABSTRACTAREA_H
#define NELDERMID_ABSTRACTAREA_H
#include <vector>
#include <cstddef>

class AbstractArea {
public:
    virtual void setBorder(const std::vector<double> &_upper,
                           const std::vector<double> &_lower) = 0; /** Sets upper and lower bounds for Area**/

    virtual std::vector<double>
    getApproximationInsideBorder() = 0; /** Gets current approximation of extremum in case it steps out of Area **/

    virtual bool isOutOfBorder(const std::vector<double> &x) = 0; /** Checks if the point is out of Area **/

    virtual std::vector<double> getUpper() = 0; /** Gets upper bounds of Area **/

    virtual std::vector<double> getLower() = 0; /** Gets lower bounds of Area **/

    virtual size_t getDim()= 0;
};


#endif //NELDERMID_ABSTRACTAREA_H
