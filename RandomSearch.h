/** \brief Inherited from  AbstractOptimizationMethod class. Implements random search **/

#ifndef NELDERMID_RANDOMSEARCH_H
#define NELDERMID_RANDOMSEARCH_H

#include <random>
#include <memory>
#include "AbstractOptimizationMethod.h"
#include "FunctionImplementation.h"

class RandomSearch : public AbstractOptimizationMethod {
public:
    OptimizationResult optimize(const std::vector<double> &initialApproximation,
                                std::shared_ptr<AbstractCriterion> &criterion,
                                FunctionImplementation *function) override;

    explicit RandomSearch(double _p, double _resizeCoef);

private:
    double p; /** Probability of searching in the whole area **/
    std::mt19937 gen; /** PRNG **/
    std::uniform_real_distribution<> runif; /** Distribution for PRNG **/
    double resizeCoef;

    std::vector<double>
    getRandomPoint(size_t dim, const std::vector<double> &upper,
                   const std::vector<double> &lower); /** Gets random point inside the specified by bounds area **/
};


#endif //NELDERMID_RANDOMSEARCH_H
