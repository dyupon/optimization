/** \brief Inherited from AbstactOptimization class to present Nelder-Mead optimization **/

#ifndef NELDERMID_NELDERMEADOPTIMIZATION_H
#define NELDERMID_NELDERMEADOPTIMIZATION_H

#include <memory>
#include "AbstractOptimizationMethod.h"
#include "OptimizationResult.h"
#include "FunctionImplementation.h"

class NelderMeadOptimization : public AbstractOptimizationMethod {
private:
    static const int MAX_IT = 1000; /** Upper bound for probable amount of iterations for avoiding infinite looping**/
    static const double ALPHA; /** Const used for regulating simplex deformation at each step. Optimal values are chosen as default **/
    static const double BETA; /** Const used for regulating simplex deformation at each step. Optimal values are chosen as default **/
    static const double GAMMA; /** Const used for regulating simplex deformation at each step. Optimal values are chosen as default **/

    const size_t dim; /** Dimension of the area **/
    const double scale; /** Const used for regulating simplex deformation at each step. Optimal values are chosen as default **/
public:
    NelderMeadOptimization(size_t _dim, double _scale);

    OptimizationResult optimize(const std::vector<double> &initialApproximation,
                                std::shared_ptr<AbstractCriterion> &criterion,
                                FunctionImplementation *function) override;
};

#endif //NELDERMID_NELDERMEADOPTIMIZATION_H
