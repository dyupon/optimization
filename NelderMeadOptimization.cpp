#include <cmath>
#include <iostream>
#include "NelderMeadOptimization.h"
#include "OptimizationResult.h"

const double NelderMeadOptimization::ALPHA = 1.0;
const double NelderMeadOptimization::BETA = 0.5;
const double NelderMeadOptimization::GAMMA = 2.0;

NelderMeadOptimization::NelderMeadOptimization(int _dim, double _scale) : dim(_dim), scale(_scale) {
    simplex.resize(dim + 1);
    for (int i = 0; i < simplex.size(); ++i) {
        simplex[i].resize(dim);
    };
    function_values.resize(dim + 1);
    vertex_reflection.resize(dim);
    vertex_expansion.resize(dim);
    vertex_contraction.resize(dim);
    vm.resize(dim);
}

OptimizationResult NelderMeadOptimization::optimize(std::vector<double> const& first_approximation,
                                                     AbstractCriterion const& criteria,
                                                     Function const& function) {
    std::vector<double> initial_approximation = first_approximation;
    double reflection_point, expansion_point, contraction_point, simplex_vertex_1, simplex_vertex_2, center;

    simplex_vertex_1 = scale * (std::sqrt(dim + 1) - 1 + dim) / (dim * std::sqrt(2));
    simplex_vertex_2 = scale * (std::sqrt(dim + 1) - 1) / (dim * std::sqrt(2));
   /* SquareArea domain = function.get_domain();
    std::vector<double> upper = domain.get_upper();
    std::vector<double> lower = domain.get_lower();*/

    for (int i = 0; i < dim; ++i) {
        simplex[0][i] = initial_approximation[i];
    }

    for (int i = 1; i <= dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            if (i - 1 == j) {
                simplex[i][j] = simplex_vertex_1 + initial_approximation[j];
            } else {
                simplex[i][j] = simplex_vertex_2 + initial_approximation[j];
            }
        }
    }

    for (int i = 0; i <= dim; ++i) {
        function_values[i] = function.get_function_value(simplex[i]);
    }

    function_evaluations_count = dim + 1;

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

        for (int i = 0; i <= dim - 1; i++) {
            vertex_reflection[i] = vm[i] + ALPHA * (vm[i] - simplex[largest_value_vertex][i]);
        }

//            TODO: while deforming the simplex fit all the new vertices in borders

        reflection_point = function.get_function_value(vertex_reflection);
        ++function_evaluations_count;

        if (reflection_point < function_values[next_smallest_value_vertex] && reflection_point >= function_values[smallest_value_vertex]) {
            for (int i = 0; i <= dim - 1; i++) {
                simplex[largest_value_vertex][i] = vertex_reflection[i];
            }
            function_values[largest_value_vertex] = reflection_point;
        }

        if (reflection_point < function_values[smallest_value_vertex]) {
            for (int i = 0; i <= dim - 1; ++i) {
                vertex_expansion[i] = vm[i] + GAMMA * (vertex_reflection[i] - vm[i]);
            }

            expansion_point = function.get_function_value(vertex_expansion);
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
            if (reflection_point < function_values[largest_value_vertex] && reflection_point >= function_values[next_smallest_value_vertex]) {
                for (int i = 0; i <= dim - 1; ++i) {
                    vertex_contraction[i] = vm[i] + BETA * (vertex_reflection[i] - vm[i]);
                }
                contraction_point = function.get_function_value(vertex_contraction);
                ++function_evaluations_count;
            } else {
                for (int i = 0; i <= dim - 1; ++i) {
                    vertex_contraction[i] = vm[i] - BETA * (vm[i] - simplex[largest_value_vertex][i]);
                }
                contraction_point = function.get_function_value(vertex_contraction);
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

                function_values[largest_value_vertex] = function.get_function_value(simplex[largest_value_vertex]);
                ++function_evaluations_count;

                function_values[next_smallest_value_vertex] = function.get_function_value(
                        simplex[next_smallest_value_vertex]);
                ++function_evaluations_count;
            }
        }
        std::cout << "Iteration " << iter_count << std::endl;
        for (int j = 0; j <= dim; ++j) {
            for (int i = 0; i < dim; ++i) {
                std::cout << simplex[j][i] << ' ';
            }
            std::cout << std::endl << function_values[j] << std::endl;
        }
        if (criteria.is_converged(function_values)) break;
    }

    for (int i = 0; i < dim; ++i) {
        initial_approximation[i] = simplex[smallest_value_vertex][i];
    }
    std::cout << function_evaluations_count << " Function Evaluations" << std::endl;
    std::cout << iter_count << " Iterations through program" << std::endl;
    OptimizationResult optimizationResult = OptimizationResult(iter_count, function_evaluations_count, initial_approximation);
    return optimizationResult;
}
