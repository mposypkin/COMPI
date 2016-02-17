#include <iostream>
#include "mpproblem.hpp"

class F : public COMPI::Functor <double> {
    public:
        
        double func(const double* x) {
            return x[0] * x[1];
        }
}; 

int main() {
    COMPI::MPProblem<double> mpp;
    mpp.mObjectives.push_back(new F());
    for(int i = 0; i < 3; i ++) {
        mpp.mEqConstr.push_back(new F());
    }
    for(int i = 0; i < 3; i ++) {
        mpp.mEqConstr.push_back(new F());
    }
    return 0;
}
