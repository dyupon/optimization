#ifndef NELDERMID_NELDERMEADOPTIMIZATION_H
#define NELDERMID_NELDERMEADOPTIMIZATION_H

#include "AbstractOptimizationMethod.h"
#include "OptimizationResult.h"

class NelderMeadOptimization : public AbstractOptimizationMethod {
private:
    static const int MAX_IT = 1000;
    static const double ALPHA;
    static const double BETA;
    static const double GAMMA;

    const size_t dim;
    const double scale;
public:
    NelderMeadOptimization(size_t _dim, double _scale);

    OptimizationResult optimize(const std::vector<double> &initial_approximation,
                                const AbstractCriterion &criteria,
                                const Function &function) override;
};

#endif //NELDERMID_NELDERMEADOPTIMIZATION_H
