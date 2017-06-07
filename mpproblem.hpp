/* 
 * File:   mpproblem.hpp
 * Author: medved
 *
 * Created on February 17, 2016, 2:09 PM
 */

#ifndef MPPROBLEM_HPP
#define MPPROBLEM_HPP

#include <vector>
#include <cstddef>
#include <string>
#include <memory>
#include <box/box.hpp>
#include "functor.hpp"

namespace COMPI {

    /**
     * Generic interface to mathematical programming problem
     */
    template <class FT> class MPProblem {
    public:

        MPProblem() : mBox(nullptr) {
        }

        /**
         * Information about the problem
         * @return Problem description
         */
        virtual std::string about() const {
            return "No problem description provided";
        }

        /**
         * Objective functions (maybe more than one if the problem is multicriterial)
         */
        std::vector< std::shared_ptr<Functor<FT>> > mObjectives;

        /**
         * Inequality constraints in the form g(x) <= 0
         */
        std::vector< std::shared_ptr<Functor<FT>> > mIneqConstr;

        /**
         * Equality constraints in the form g(x) = 0
         */
        std::vector< std::shared_ptr<Functor<FT>> > mEqConstr;

        /**
         * Bounding box
         */
        snowgoose::Box<FT>* mBox;

        enum VariableTypes {
            /**
             * Normal continuos variable
             */
            GENERIC,
            /**
             * Integral
             */
            INTEGRAL,
            /**
             * Boolean
             */
            BOOLEAN
        };

        /**
         * Characteristics of variables
         */
        
        std::vector<VariableTypes> mVarTypes;
    };

}

#endif /* MPPROBLEM_HPP */

