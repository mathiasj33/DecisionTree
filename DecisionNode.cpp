//
// Created by mathias on 01.02.19.
//

#include "DecisionNode.h"
#include <algorithm>
#include <random>

void DecisionNode::train(const Dataset &dataset, std::vector<std::string> features, int depth, int maxDepth,
                         int numFeatures) {
    if (depth >= maxDepth || dataset.allSameLabel() || dataset.size() == 1 || features.empty()) {
        label = dataset.majorityVote();
        return;
    }

    std::vector<std::string> consideredFeatures = features;
    if (numFeatures <= consideredFeatures.size()) {
        std::shuffle(consideredFeatures.begin(), consideredFeatures.end(), std::default_random_engine());
        while (consideredFeatures.size() > numFeatures) {
            consideredFeatures.pop_back();
        }
    }

    float currentGini = dataset.calculateGiniIndex();
    std::pair<std::string, float> bestSplitGini = calculateBestSplit(dataset, consideredFeatures);
    if (bestSplitGini.second > currentGini) {
        label = dataset.majorityVote();
        return;
    }

    splitFeature = bestSplitGini.first;
    auto newFeatures = features;
    newFeatures.erase(std::remove(newFeatures.begin(), newFeatures.end(), splitFeature), newFeatures.end());
    auto splits = dataset.splitOnFeature(splitFeature);

    #pragma omp parallel for
    for (int i = 0; i < splits.size(); i++) {
        Dataset subset = splits[i];
        auto child = DecisionNode();
        child.prevSplitValue = subset.getData()[0]->getFeature(splitFeature);
        child.train(subset, newFeatures, depth + 1, maxDepth, numFeatures);
        children.push_back(std::move(child));
    }
}

std::pair<std::string, float>
DecisionNode::calculateBestSplit(const Dataset &dataset, std::vector<std::string> consideredFeatures) {
    std::string feature;
    float gini = 10;
    for (const std::string &f : consideredFeatures) {
        auto splits = dataset.splitOnFeature(f);
        float splitGini = 0;
        for (const auto &set : splits) {
            splitGini += (((float) set.size()) / dataset.size()) * set.calculateGiniIndex();
        }
        if (splitGini < gini) {
            gini = splitGini;
            feature = f;
        }
    }
    return std::make_pair<>(feature, gini);
}

std::vector<DecisionNode> &DecisionNode::getChildren() {
    return children;
}

std::vector<int> DecisionNode::getFeatureValues() const {
    return featureValues;
}

std::string DecisionNode::getSplitFeature() const {
    return splitFeature;
}

int DecisionNode::getLabel() const {
    return label;
}

int DecisionNode::getPrevSplitValue() const {
    return prevSplitValue;
}