//
// Created by mathias on 01.02.19.
//

#ifndef TRY_CLASSIFIER_H
#define TRY_CLASSIFIER_H

#include <vector>
#include "Dataset.h"
#include "DataItem.h"

class Classifier {
public:
    virtual ~Classifier();
    std::vector<int> classify(const Dataset& dataset);
    virtual int classify(const DataItem* item) = 0;
    float accuracy(Dataset& dataset);
};


#endif //TRY_CLASSIFIER_H
