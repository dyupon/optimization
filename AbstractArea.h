#ifndef NELDERMID_ABSTRACTAREA_H
#define NELDERMID_ABSTRACTAREA_H

#include <vector>
#include <cstddef>

class AbstractArea {
public:
    virtual void set_border(const std::vector<double> &_upper, const std::vector<double> &_lower) = 0;
    virtual std::vector<double> get_approximation_inside_border() = 0;

    virtual bool is_out_of_border(const std::vector<double> &x) = 0;
    virtual std::vector<double> get_upper() = 0;
    virtual std::vector<double> get_lower() = 0;

    virtual size_t get_dim()= 0;
};



#endif //NELDERMID_ABSTRACTAREA_H
