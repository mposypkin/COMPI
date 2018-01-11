#include <iostream>
#include "mpproblem.hpp"
#include "mputils.hpp"
#include "funccnt.hpp"

class F : public COMPI::Functor <double> {
public:

    double func(const double* x) const {
        return x[0] * x[1];
    }
};

int main() {
    COMPI::MPProblem<double> mpp;
    auto fun = std::make_shared<F>();
    auto funcnt = std::make_shared<COMPI::FuncCnt<double>>(fun);
    mpp.mObjectives.push_back(funcnt);
    const int n = 4, neq = 2, nineq = 3;
    mpp.mVarTypes.assign(n, COMPI::MPProblem<double>::VariableTypes::BOOLEAN);

    for (int i = 0; i < neq; i++) {
        mpp.mEqConstr.push_back(fun);
    }
    for (int i = 0; i < nineq; i++) {
        mpp.mEqConstr.push_back(fun);
    }

    snowgoose::Box<double> box(n);
    for (int i = 0; i < n; i++) {
        box.mA[i] = 0;
        box.mB[i] = 1;
    }
    mpp.mBox = &box;
    SG_ASSERT(COMPI::MPUtils::getProblemType(mpp) == COMPI::MPUtils::ProblemTypes::BOXCONSTR |
            COMPI::MPUtils::ProblemTypes::SINGLEOBJ |
            COMPI::MPUtils::ProblemTypes::CONTINUOUS);


    return 0;
}
