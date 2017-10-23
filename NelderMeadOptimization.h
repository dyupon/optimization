#ifndef NELDERMID_NELDERMEADOPTIMIZATION_H
#define NELDERMID_NELDERMEADOPTIMIZATION_H

#include "AbstractOptimizationMethod.h"

class NelderMeadOptimization : public AbstractOptimizationMethod {
private:
    static const int MAX_IT = 1000;
    static const double ALPHA;
    static const double BETA;
    static const double GAMMA;
    std::vector<std::vector<double>> simplex;
    std::vector<double> vertex_reflection;
    std::vector<double> vertex_expansion;
    std::vector<double> vertex_contraction;
    std::vector<double> vm;
    const int dim;
    const double scale;
public:
    NelderMeadOptimization(int _dim, double _scale);

    std::vector<double> optimize(std::vector<double> const& initial_approximation, AbstractCriterion const&criteria, Function const&function) override;
};


#endif //NELDERMID_NELDERMEADOPTIMIZATION_H
