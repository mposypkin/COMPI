/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funccnt.hpp
 * Author: mikhail
 *
 * Created on 26 февраля 2016 г., 11:10
 */

#ifndef FUNCCNT_HPP
#define FUNCCNT_HPP

#include <memory>
#include <atomic>
#include "functor.hpp"

namespace COMPI {

    /**
     * The wrapper around functor that computes 
     * the number of function, gradient and hessian evaluations
     */
    template <class FT> class FuncCnt : public Functor<FT> {
    public:

        struct Counters {
            Counters() {
                mFuncCalls = 0;
                mGradCalls = 0;
                mHessCalls = 0;
            }
            
            /**
             * Number of function calls
             */
            mutable std::atomic_uint mFuncCalls;
            /**
             * Number of gradient calls
             */
            mutable std::atomic_uint mGradCalls;
            /**
             * Number of Hessian calls
             */
            mutable std::atomic_uint mHessCalls;
        };

        /**
         * Counters
         */
        const Counters mCounters;

        /**
         * Constructor
         * @param f wrapper functor
         */
        FuncCnt(std::shared_ptr< Functor<FT> > f) : mF(f) {
            reset();   
        }

        FT func(const FT* x) const {
            mCounters.mFuncCalls++;
            FT v = mF->func(x);
            return v;
        }

        void grad(const FT* x, FT* g) const {
            mCounters.mGradCalls ++;
            mF->grad(x, g);
        }

        void hess(const FT* x, FT* H) const {
            mCounters.mHessCalls ++;
            mF->hess(x, H);            
        }
        
        /**
         * Reset counters
         */
        void reset() {
            mCounters.mFuncCalls = 0;
            mCounters.mGradCalls = 0;
            mCounters.mHessCalls = 0;
        }

        
    private:
        const std::shared_ptr<Functor <FT>> mF;
    };

}

#endif /* FUNCCNT_HPP */

