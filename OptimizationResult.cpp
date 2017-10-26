#include "OptimizationResult.h"

OptimizationResult::OptimizationResult(int _iter_count,
                                       int _function_evaluations_count,
                                       const std::vector<double> &_minimum_point):
        iter_count(_iter_count),
        function_evaluations_count(_function_evaluations_count),
        minimum_point(_minimum_point){
}

const std::vector<double> &OptimizationResult::get_extr_point() const {
    return minimum_point;
}

int OptimizationResult::get_func_evaluation_count() const {
    return function_evaluations_count;
}

int OptimizationResult::get_iter_count() const {
    return iter_count;
}
