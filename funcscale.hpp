/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcscale.hpp
 * Author: mposypkin
 *
 * Created on March 28, 2017, 2:16 PM
 */

#ifndef FUNCSCALE_HPP
#define FUNCSCALE_HPP

#include <vector>
#include <memory>
#include "functor.hpp"

namespace COMPI {

    /**
     * Applies variables scaling
     */
    template <class FT> class FunctorScale : public Functor <FT> {
    public:

        /**
         * Constructor 
         * @param f function 
         * @param scale the scale parameters (should be less or equal to the number of parameters)
         */
        FunctorScale(std::shared_ptr<Functor<FT>>& f, std::vector<FT> scale) :
            mF(f), mScale(scale), mX(scale.size())
        {
                
        }

        /**
         * Compute function
         * @param x argument
         * @return function value
         *
         */
        virtual FT func(const FT* x) override {
            scale(x);
            return mF->func(mX.data());
        };

        /**
         * Compute gradient (optional)        
         * @param x argument
         * @param g gradient
         */
        virtual void grad(const FT* x, FT* g) override {
            scale(x);
            mF->grad(mX.data(), g);
        }

        /**
         * Compute Hessian (optional)
         * @param x point
         * @param H hessian 
         */
        virtual void hess(const FT* x, FT* H) override {
            scale(x);
            mF->hess(mX.data(), H);
        }
        
        const std::vector<FT>& getScale() const {
            return mScale;
        }
        
        
    private:

        void scale(const FT* x) {
            const int n = mScale.size();
            for(int i = 0; i < n; i ++)
                mX[i] = x[i] * mScale[i];
        }
        
        std::shared_ptr<Functor<FT>> mF;
        const std::vector<FT> mScale;
        std::vector<FT> mX;
    };

}

#endif /* FUNCSCALE_HPP */

