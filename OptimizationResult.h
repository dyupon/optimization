//
// Created by User on 10/23/2017.
//

#ifndef NELDERMID_OPTIMIZATIONRESULT_H
#define NELDERMID_OPTIMIZATIONRESULT_H


#include <vector>

class OptimizationResult {
public:
    OptimizationResult (int _iter_count, int _function_evaluations_count, const std::vector<double> &_minimum_point);
    int get_iter_count() const;
    int get_func_evaluation_count() const;
    const std::vector<double> &get_extr_point() const;
private:
    const int iter_count;
    const int function_evaluations_count;
    const std::vector<double> minimum_point;
};


#endif //NELDERMID_OPTIMIZATIONRESULT_H
