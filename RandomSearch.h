#ifndef NELDERMID_RANDOMSEARCH_H
#define NELDERMID_RANDOMSEARCH_H

#include <random>
#include "AbstractOptimizationMethod.h"

class RandomSearch : public AbstractOptimizationMethod {
public:
    OptimizationResult optimize(const std::vector<double> &initialApproximation,
                                const AbstractCriterion &criteria,
                                const Function &function) override;

    explicit RandomSearch(double _p);
private:
    double p;
    std::mt19937 gen;
    std::uniform_real_distribution<> runif;

    std::vector<double>
    get_random_point(size_t dim, const std::vector<double> &upper, const std::vector<double> &lower);

    std::vector<double> sum(const std::vector<double> &a, const std::vector<double> &b) const;

    std::vector<double> diff(const std::vector<double> &a, const std::vector<double> &b) const;
};


#endif //NELDERMID_RANDOMSEARCH_H
