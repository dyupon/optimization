#ifndef NELDERMID_ABSTRACTAREA_H
#define NELDERMID_ABSTRACTAREA_H

#include <vector>
#include <cstddef>

class AbstractArea {
public:
    virtual void setBorder(const std::vector<double> &_upper, const std::vector<double> &_lower) = 0;

    virtual std::vector<double> getApproximationInsideBorder() = 0;

    virtual bool isOutOfBorder(const std::vector<double> &x) = 0;

    virtual std::vector<double> getUpper() = 0;

    virtual std::vector<double> getLower() = 0;

    virtual size_t getDim()= 0;
};



#endif //NELDERMID_ABSTRACTAREA_H
