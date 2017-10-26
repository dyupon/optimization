#ifndef NELDERMID_SQUAREAREA_H
#define NELDERMID_SQUAREAREA_H

#include <cstddef>
#include "AbstractArea.h"

class SquareArea : public AbstractArea {
private:
    std::vector<double> upper, lower;
    size_t dim;
public:
    explicit SquareArea(size_t _dim);

    SquareArea();

    size_t get_dim() override;

    void set_border(const std::vector<double> &_upper, const std::vector<double> &_lower) override;
    std::vector<double> get_upper() override;
    std::vector<double> get_lower() override;
    std::vector<double> get_approximation_inside_border() override;

    bool is_out_of_border(const std::vector<double> &x) override;

    std::vector<double>
    get_random_point_on_border(const std::vector<double> &point_1, const std::vector<double> &point_2);
};


#endif //NELDERMID_SQUAREAREA_H
