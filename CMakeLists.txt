cmake_minimum_required(VERSION 3.8)
project(NelderMid)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AbstractArea.h AbstractCriterion.h AbstractOptimizationMethod.h Function.h EpsilonCriterion.cpp EpsilonCriterion.h Function1.cpp Function1.h RandomSearch.cpp RandomSearch.h SquareArea.cpp SquareArea.h NelderMeadOptimization.cpp NelderMeadOptimization.h EuclidNormCriterion.cpp EuclidNormCriterion.h OptimizationResult.cpp OptimizationResult.h Function2.cpp Function2.h Function3.cpp Function3.h FunctionImplementation.cpp FunctionImplementation.h)
add_executable(NelderMid ${SOURCE_FILES})