#include <iostream>
#include "mpproblem.hpp"
#include "mputils.hpp"

class F : public COMPI::Functor <double> {
    public:
        
        double func(const double* x) {
            return x[0] * x[1];
        }
}; 

int main() {
    COMPI::MPProblem<double> mpp;
    mpp.mObjectives.push_back(new F());
    const int n = 4, neq = 2, nineq = 3;
    for(int i = 0; i < n; i ++) {
        mpp.mVarTypes.push_back(COMPI::MPProblem<double>::VariableTypes::BOOLEAN);
    }
    /*
    for(int i = 0; i < neq; i ++) {
        mpp.mEqConstr.push_back(new F());
    }
    for(int i = 0; i < nineq; i ++) {
        mpp.mEqConstr.push_back(new F());
    }
    
    SG_ASSERT(COMPI::MPUtils::getProblemType(mpp) == COMPI::MPUtils::ProblemTypes::BOXCONSTR | 
                                                     COMPI::MPUtils::ProblemTypes::SINGLEOBJ |
                                                     COMPI::MPUtils::ProblemTypes::CONTINUOUS);
    
     */
    return 0;
}
