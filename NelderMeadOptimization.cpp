#include <cmath>
#include <iostream>
#include "NelderMeadOptimization.h"

const double NelderMeadOptimization::ALPHA = 1.0;
const double NelderMeadOptimization::BETA = 0.5;
const double NelderMeadOptimization::GAMMA = 2.0;

NelderMeadOptimization::NelderMeadOptimization(size_t _dim, double _scale) : dim(_dim), scale(_scale) {
}

OptimizationResult NelderMeadOptimization::optimize(const std::vector<double> &initialApproximation,
                                                    const AbstractCriterion &criteria,
                                                    const Function &function) {
    std::vector<double> function_values;
    function_values.reserve(dim + 1);
    std::vector<double> vm;
    vm.reserve(dim);

    std::vector<double> initial_approximation = initialApproximation;
    double reflection_point, expansion_point, contraction_point, simplex_vertex_1, simplex_vertex_2, center;

    simplex_vertex_1 = scale * (std::sqrt(dim + 1) - 1 + dim) / (dim * std::sqrt(2));
    simplex_vertex_2 = scale * (std::sqrt(dim + 1) - 1) / (dim * std::sqrt(2));
    /* SquareArea domain = function.getDomain();
     std::vector<double> upper = domain.getUpper();
     std::vector<double> lower = domain.getLower();*/

    std::vector<std::vector<double>> simplex;
    simplex.reserve(dim + 1);
    simplex.push_back(initial_approximation);

    for (int i = 1; i <= dim; ++i) {
        std::vector<double> simplex_row;
        simplex_row.reserve(dim);
        for (int j = 0; j < dim; ++j) {
            if (i - 1 == j) {
                simplex_row.push_back(simplex_vertex_1 + initial_approximation[j]);
            } else {
                simplex_row.push_back(simplex_vertex_2 + initial_approximation[j]);
            }
        }
        simplex.push_back(simplex_row);
    }

    for (int i = 0; i <= dim; ++i) {
        function_values.push_back(function.getFunctionValue(simplex[i]));
    }

    int function_evaluations_count = dim + 1;

    std::cout << "Initial Values" << std::endl;
    for (int i = 0; i <= dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            std::cout << simplex[i][j] << ' ';
        }
        std::cout << std::endl  << function_values[i] << std::endl;
    }

    int largest_value_vertex = 0;
    int smallest_value_vertex = 0;
    int iter_count;

    for (iter_count = 1; iter_count <= MAX_IT; ++iter_count) {

        for (int i = 0; i <= dim; ++i) {
            if (function_values[i] > function_values[largest_value_vertex]) {
                largest_value_vertex = i;
            }
            if (function_values[i] < function_values[smallest_value_vertex]) {
                smallest_value_vertex = i;
            }
        }

        int next_smallest_value_vertex = smallest_value_vertex;
        for (int i = 0; i <= dim; i++) {
            if (function_values[i] > function_values[next_smallest_value_vertex] && function_values[i] < function_values[largest_value_vertex]) {
                next_smallest_value_vertex = i;
            }
        }

        for (int i = 0; i <= dim - 1; ++i) {
            center = 0.0;
            for (int j = 0; j <= dim; ++j) {
                if (j != largest_value_vertex) {
                    center += simplex[j][i];
                }
            }
            vm[i] = center / dim;
        }

        std::vector<double> vertex_reflection;
        vertex_reflection.reserve(dim);
        for (int i = 0; i <= dim - 1; i++) {
            vertex_reflection.push_back(vm[i] + ALPHA * (vm[i] - simplex[largest_value_vertex][i]));
        }

//            TODO: while deforming the simplex fit all the new vertices in borders

        reflection_point = function.getFunctionValue(vertex_reflection);
        ++function_evaluations_count;

        if (reflection_point < function_values[next_smallest_value_vertex] && reflection_point >= function_values[smallest_value_vertex]) {
            for (int i = 0; i <= dim - 1; i++) {
                simplex[largest_value_vertex][i] = vertex_reflection[i];
            }
            function_values[largest_value_vertex] = reflection_point;
        }

        if (reflection_point < function_values[smallest_value_vertex]) {
            std::vector<double> vertex_expansion;
            vertex_expansion.reserve(dim);
            for (int i = 0; i <= dim - 1; ++i) {
                vertex_expansion.push_back(vm[i] + GAMMA * (vertex_reflection[i] - vm[i]));
            }

            expansion_point = function.getFunctionValue(vertex_expansion);
            function_evaluations_count++;

            if (expansion_point < reflection_point) {
                for (int i = 0; i <= dim - 1; ++i) {
                    simplex[largest_value_vertex][i] = vertex_expansion[i];
                }
                function_values[largest_value_vertex] = expansion_point;
            } else {
                for (int i = 0; i <= dim - 1; ++i) {
                    simplex[largest_value_vertex][i] = vertex_reflection[i];
                }
                function_values[largest_value_vertex] = reflection_point;
            }
        }

        if (reflection_point >= function_values[next_smallest_value_vertex]) {
            std::vector<double> vertex_contraction;
            vertex_contraction.reserve(dim);
            if (reflection_point < function_values[largest_value_vertex] && reflection_point >= function_values[next_smallest_value_vertex]) {
                for (int i = 0; i <= dim - 1; ++i) {
                    vertex_contraction.push_back(vm[i] + BETA * (vertex_reflection[i] - vm[i]));
                }
                contraction_point = function.getFunctionValue(vertex_contraction);
                ++function_evaluations_count;
            } else {
                for (int i = 0; i <= dim - 1; ++i) {
                    vertex_contraction.push_back(vm[i] - BETA * (vm[i] - simplex[largest_value_vertex][i]));
                }
                contraction_point = function.getFunctionValue(vertex_contraction);
                ++function_evaluations_count;
            }

            if (contraction_point < function_values[largest_value_vertex]) {
                for (int i = 0; i <= dim - 1; ++i) {
                    simplex[largest_value_vertex][i] = vertex_contraction[i];
                }
                function_values[largest_value_vertex] = contraction_point;
            } else {
                for (int row = 0; row <= dim; row++) {
                    if (row != smallest_value_vertex) {
                        for (int i = 0; i <= dim - 1; ++i) {
                            simplex[row][i] = simplex[smallest_value_vertex][i] + (simplex[row][i] - simplex[smallest_value_vertex][i]) / 2.0;
                        }
                    }
                }

                function_values[largest_value_vertex] = function.getFunctionValue(simplex[largest_value_vertex]);
                ++function_evaluations_count;

                function_values[next_smallest_value_vertex] = function.getFunctionValue(
                        simplex[next_smallest_value_vertex]);
                ++function_evaluations_count;
            }
        }
        if (criteria.isConverged(function_values)) break;
    }

    for (int i = 0; i < dim; ++i) {
        initial_approximation[i] = simplex[smallest_value_vertex][i];
    }
    OptimizationResult optimizationResult = OptimizationResult(iter_count, function_evaluations_count, initial_approximation);
    return optimizationResult;
}
