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

    size_t getDim() override;

    void setBorder(const std::vector<double> &_upper, const std::vector<double> &_lower) override;

    std::vector<double> getUpper() override;

    std::vector<double> getLower() override;

    std::vector<double> getApproximationInsideBorder() override;

    bool isOutOfBorder(const std::vector<double> &x) override;

    std::vector<double>
    getRandomPointOnBorder(const std::vector<double> &point_1, const std::vector<double> &point_2);
};


#endif //NELDERMID_SQUAREAREA_H
