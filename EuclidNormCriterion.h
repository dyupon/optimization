//
// Created by User on 10/12/2017.
//

#ifndef NELDERMID_EUCLIDNORMCRITERIA_H
#define NELDERMID_EUCLIDNORMCRITERIA_H


#include "AbstractCriterion.h"

class EuclidNormCriterion: public AbstractCriterion {
public:
    EuclidNormCriterion();

    bool is_converged(const std::vector<double> &function) const override;

    bool is_converged(size_t dim,
                      double eps,
                      const std::vector<double> &previous_approximation,
                      const std::vector<double> &new_approximation) const override;
private:
    const int MAX_ITER_COUNT = 50000;
    mutable int iter_count;
};


#endif //NELDERMID_EUCLIDNORMCRITERIA_H
