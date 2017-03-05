/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   solver.hpp
 * Author: posypkin
 *
 * Created on March 5, 2017, 4:20 PM
 */

#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <string>

namespace COMPI {

    /**
     * Abstract class for an optimization problem solver
     */
    template <class FT> class Solver {
    public:
        /**
         * Searches for optimum
         * @param x the initial vector at the beginning (optional), the result vector at the end
         * @param v the initial value at the beginning (optional) , the result value at the end
         * @return true if the improvement was made, false otherwise (the result should be ignored)
         */
        virtual bool search(FT* x, FT& v) = 0;

        /**
         * Information about the  solver
         * @return information
         */
        virtual std::string about() const {
            return "No information about solver";
        }

    };
}

#endif /* SOLVER_HPP */

