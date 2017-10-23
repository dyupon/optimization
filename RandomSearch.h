#ifndef NELDERMID_RANDOMSEARCH_H
#define NELDERMID_RANDOMSEARCH_H

#include <random>
#include "AbstractOptimizationMethod.h"

class RandomSearch : public AbstractOptimizationMethod {
public:
    std::vector<double> optimize(std::vector<double> const& initial_approximation, AbstractCriterion const& criteria, Function const& function) override;
    RandomSearch(double _p);
private:
    double p;
    std::mt19937 gen;
    std::uniform_real_distribution<> runif;
    std::vector<double> get_random_point (int dim, std::vector<double> &upper, std::vector<double> &lower);
    std::vector<double> sum(std::vector<double> a,std::vector<double> b);
    std::vector<double> diff(std::vector<double> a,std::vector<double> b);
};


#endif //NELDERMID_RANDOMSEARCH_H
