/** \brief Class used for introduction of results of the optimization **/


#ifndef NELDERMID_OPTIMIZATIONRESULT_H
#define NELDERMID_OPTIMIZATIONRESULT_H

#include <vector>

class OptimizationResult {
public:
    OptimizationResult(int _iterCount, int _functionEvaluationsCount,
                       const std::vector<double> &_minimumPoint); /** Constructor for OptimizationResult class **/

    int getIterCount() const; /** Gets general number of iterations done while optimizing **/

    int getFuncEvaluationCount() const; /** Gets general number of the function evaluations done while optimizing **/

    const std::vector<double> &getExtrPoint() const; /** Gets the point where the minimum is found at **/
private:
    const int iterCount; /** General number of iterations **/
    const int functionEvaluationsCount; /** General number of the function evaluations **/
    const std::vector<double> minimumPoint; /** Point where the minimum is found at **/
};


#endif //NELDERMID_OPTIMIZATIONRESULT_H
