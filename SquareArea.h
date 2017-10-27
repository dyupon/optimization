/** \brief Inherited from  AbstractArea class. Specifies to square area **/

#ifndef NELDERMID_SQUAREAREA_H
#define NELDERMID_SQUAREAREA_H

#include <cstddef>
#include "AbstractArea.h"

class SquareArea : public AbstractArea {
private:
    std::vector<double> upper; /** Upper bound of the area **/
    std::vector<double> lower; /** Lower bound of the area **/
    size_t dim;
public:
    explicit SquareArea(size_t _dim);

    SquareArea();

    size_t getDim() override;

    void setBorder(const std::vector<double> &_upper,
                   const std::vector<double> &_lower) override; /** Sets the borders of the square domain **/

    std::vector<double> getUpper() override;

    std::vector<double> getLower() override;

    std::vector<double> getApproximationInsideBorder() override;

    bool isOutOfBorder(const std::vector<double> &x) override;

    std::vector<double>
    getRandomPointOnBorder(const std::vector<double> &point_1, const std::vector<double> &point_2);
};


#endif //NELDERMID_SQUAREAREA_H
