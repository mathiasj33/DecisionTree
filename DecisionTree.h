//
// Created by mathias on 01.02.19.
//

#ifndef TRY_DECISIONTREE_H
#define TRY_DECISIONTREE_H

#include "Classifier.h"
#include "DecisionNode.h"

class DecisionTree : public Classifier {
public:
    explicit DecisionTree(int maxDepth, int numFeatures = -1);
    void train(const Dataset& trainDataset);
    int classify(const DataItem* item) override;

private:
    int maxDepth;
    int numFeatures;
    DecisionNode root;
};



#endif //TRY_DECISIONTREE_H
