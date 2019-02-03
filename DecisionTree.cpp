//
// Created by mathias on 01.02.19.
//

#include "DecisionTree.h"

DecisionTree::DecisionTree(int maxDepth, int numFeatures) {
    this->maxDepth = maxDepth;
    this->numFeatures = numFeatures;
}

void DecisionTree::train(const Dataset& trainDataset) {
    auto features = trainDataset.getFeatures();
    if(numFeatures == -1) {
        numFeatures = (int) features.size();
    }
    root.train(trainDataset, features, 1, maxDepth, numFeatures);
}

int DecisionTree::classify(const DataItem* item) {
    DecisionNode* node = &root;
    while(!node->getChildren().empty()) {
        bool foundChild = false;
        for(int i = 0; i < node->getChildren().size(); i++) {
            int value = node->getChildren()[i]->getPrevSplitValue();
            if(value == item->getFeature(node->getSplitFeature())) {
                node = node->getChildren()[i].get();
                foundChild = true;
                break;
            }
        }
        if(!foundChild) {
            //randomly use the first child
            node = node->getChildren()[0].get();
        }
    }
    return node->getLabel();
}
