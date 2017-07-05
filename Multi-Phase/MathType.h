//
//  MathType.h
//  Multi-Phase
//
//  Created by ncut on 17/6/30.
//  Copyright (c) 2017年 ncut. All rights reserved.
//

#ifndef __Multi_Phase__MathType__
#define __Multi_Phase__MathType__

#include <stdio.h>
#include <math.h>

template <typename T, int numOfDimension>
struct VectorT {
private:
    T elements[numOfDimension];
    
public:
    static VectorT<T, 3> Vector3(T x, T y, T z){
        VectorT<T, 3> vec3;
        vec3.elements[0] = x;
        vec3.elements[1] = y;
        vec3.elements[2] = z;
        
        return vec3;
    }
    double magnitude(){
        double sum = 0;
        for(int i = 0; i < numOfDimension; i++){
            sum += elements[i] * elements[i];
        }
        return pow(sum, 0.5);
    }
    long dot(VectorT<T, numOfDimension> other){
        long ret = 0;
        for(int i = 0; i < numOfDimension; i++){
            ret += elements[i] * other[i];
        }
        return ret;
    }
    
    
    VectorT<T, numOfDimension> operator+(VectorT<T, numOfDimension> other){
        VectorT<T, numOfDimension> ret;
        for(int i = 0; i < numOfDimension; i++){
            ret[i] = elements[i] + other[i];
        }
        return ret;
    }
    
    VectorT<T, numOfDimension> operator-(VectorT<T, numOfDimension> other){
        VectorT<T, numOfDimension> ret;
        for(int i = 0; i < numOfDimension; i++){
            ret.elements[i] = elements[i] - other[i];
        }
        return ret;
    }
    
    T& operator[](int idx){
        if(idx < 0 || idx >= numOfDimension)
            throw std::string("The idx out of range");
        return elements[idx];
    }
    
    const T& operator[](int idx) const{
        if(idx < 0 || idx >= numOfDimension)
            throw std::string("The idx out of range");
        return elements[idx];
    }
    
    template <typename ValueType>
    VectorT<T, numOfDimension> operator+(ValueType other){
        VectorT<T, numOfDimension> ret;
        for(int i = 0; i < numOfDimension; i++){
            ret[i] = elements[i] + other;
        }
        return ret;
    }
    
    template <typename ValueType>
    VectorT<T, numOfDimension> operator-(ValueType other){
        VectorT<T, numOfDimension> ret;
        for(int i = 0; i < numOfDimension; i++){
            ret.elements[i] = elements[i] - other;
        }
        return ret;
    }
    
    template <typename ValueType>
    VectorT<T, numOfDimension> operator*(ValueType other){
        VectorT<T, numOfDimension> ret;
        for(int i = 0; i < numOfDimension; i++){
            ret[i] = elements[i] * other;
        }
        return ret;
    }
    
    template <typename ValueType>
    VectorT<T, numOfDimension> operator/(ValueType other){
        VectorT<T, numOfDimension> ret;
        for(int i = 0; i < numOfDimension; i++){
            ret[i] = elements[i] / other;
        }
        return ret;
    }
    
    template <typename ValueType>
    VectorT<T, numOfDimension>& operator*=(ValueType other){
        for(int i = 0; i < numOfDimension; i++){
            elements[i] *= other;
        }
        return *this;
    }
    
    template <typename ValueType>
    VectorT<T, numOfDimension>& operator/=(ValueType other){
        for(int i = 0; i < numOfDimension; i++){
            elements[i] /= other;
        }
        return *this;
    }
};

typedef VectorT<float, 3> Vector3f;
typedef VectorT<int, 3> Vector3i;


namespace WZW {
    class Kernals{
    private:
        double Poly6Kernal;
        double SpikyKernal;
        double ViscosityKernal;
    public:
        Kernals(double smoothKernalRadius);
    };
}

#endif /* defined(__Multi_Phase__MathType__) */
