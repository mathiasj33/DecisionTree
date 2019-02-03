cmake_minimum_required(VERSION 3.13)
project(try)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
set(CMAKE_CXX_STANDARD 17)

add_executable(try main.cpp Dataset.h DataItem.cpp DataItem.h Classifier.cpp Classifier.h DecisionTree.cpp DecisionTree.h DecisionNode.cpp DecisionNode.h LoadedDataset.cpp LoadedDataset.h Dataset.cpp)