#ifndef NELDERMID_SQUAREAREA_H
#define NELDERMID_SQUAREAREA_H

#include "AbstractArea.h"

class SquareArea : public AbstractArea {
private:
    std::vector<double> upper, lower;
    int dim;
public:
    SquareArea(int _dim);

    SquareArea();

    int get_dim() override ;
    void set_border(std::vector<double> _upper, std::vector<double> _lower) override;
    std::vector<double> get_upper() override;
    std::vector<double> get_lower() override;
    std::vector<double> get_approximation_inside_border() override;
    bool is_out_of_border(std::vector<double> x) override;
    std::vector<double> get_random_point_on_border(std::vector<double> point_1, std::vector<double> point_2);
};


#endif //NELDERMID_SQUAREAREA_H
