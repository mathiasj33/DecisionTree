//
// Created by mathias on 01.02.19.
//

#include "Classifier.h"
#include "DataItem.h"

Classifier::~Classifier() = default;

std::vector<int> Classifier::classify(const Dataset& dataset) {
    auto result = std::vector<int>();
    for(const DataItem* item : dataset) {
        result.push_back(classify(item));
    }
    return result;
};

float Classifier::accuracy(Dataset &dataset) {
    const auto predictions = classify(dataset);
    if(dataset.getLabels().size() != predictions.size()) return -1;
    float accuracy = 0;
    for(int i = 0; i < predictions.size(); i++) {
        accuracy += predictions[i] == *dataset.getLabels()[i] ? 1 : 0;
    }
    return accuracy / dataset.getLabels().size();
}