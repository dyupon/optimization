/** \brief Inherited from  AbstractOptimizationMethod class. Implements random search **/

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
    double p; /** Probability of searching in the whole area **/
    std::mt19937 gen; /** PRNG **/
    std::uniform_real_distribution<> runif; /** Distribution for PRNG **/

    std::vector<double>
    getRandomPoint(size_t dim, const std::vector<double> &upper,
                   const std::vector<double> &lower); /** Gets random point inside the specified by bounds area **/

    std::vector<double> sum(const std::vector<double> &a,
                            const std::vector<double> &b) const; /** Returns componentwise sum of 2 vectors **/

    std::vector<double> diff(const std::vector<double> &a,
                             const std::vector<double> &b) const; /** Returns componentwise diff of 2 vectors **/
};


#endif //NELDERMID_RANDOMSEARCH_H
