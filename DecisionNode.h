//
// Created by mathias on 01.02.19.
//

#ifndef TRY_DECISIONNODE_H
#define TRY_DECISIONNODE_H

#include <vector>
#include <string>
#include <memory>
#include <utility>
#include "Dataset.h"

class DecisionNode {
public:
    void train(const Dataset& dataset, std::vector<std::string> features, int depth, int maxDepth, int numFeatures);
    std::vector<DecisionNode>& getChildren();
    std::vector<int> getFeatureValues() const;
    std::string getSplitFeature() const;
    int getLabel() const;
    int getPrevSplitValue() const;

private:
    std::pair<std::string, float> calculateBestSplit(const Dataset& dataset, std::vector<std::string> consideredFeatures);
    std::vector<DecisionNode> children;
    std::vector<int> featureValues;
    std::string splitFeature;
    int label;
    int prevSplitValue;
};


#endif //TRY_DECISIONNODE_H
