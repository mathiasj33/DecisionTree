//
// Created by mathias on 01.02.19.
//

#ifndef TRY_DATASET_H
#define TRY_DATASET_H

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <iterator>
#include "DataItem.h"
#include "LoadedDataset.h"

class Dataset {
public:
    Dataset();
    Dataset(LoadedDataset& loadedDataset);
    void add(const DataItem* item, const int* label);
    float calculateGiniIndex() const;
    std::unique_ptr<std::vector<Dataset>> splitOnFeature(std::string feature) const;
    int majorityVote() const;
    bool allSameLabel() const;
    int size() const;
    std::vector<const DataItem*>& getData();
    std::vector<const int*>& getLabels();
    std::vector<std::string> getFeatures() const;
    std::vector<const DataItem*>::const_iterator begin() const;
    std::vector<const DataItem*>::const_iterator end() const;

private:
    std::vector<const DataItem*> data;
    std::vector<const int*> labels;
    virtual std::unordered_map<int, float> classFrequencies() const;
};


#endif //TRY_DATASET_H
