//
// Created by mathias on 03.02.19.
//

#include "Dataset.h"
#include "DataItem.h"

Dataset::Dataset() = default;

Dataset::Dataset(LoadedDataset& loadedDataset) {
    for(const DataItem& item : loadedDataset) {
        data.push_back(&item);
    }
    for(const int& label : loadedDataset.getLabels()) {
        labels.push_back(&label);
    }
}

void Dataset::add(const DataItem* item, const int* label) {
    data.push_back(item);
    labels.push_back(label);
}

float Dataset::calculateGiniIndex() const {
    auto freqs = classFrequencies();
    float result = 1;
    for(const auto &freq : freqs) {
        result -= freq.second * freq.second;
    }
    return result;
}

int Dataset::majorityVote() const {
    int vote = 0;
    float max = 0;
    for(const auto &freq : classFrequencies()) {
        if(freq.second > max) {
            vote = freq.first;
            max = freq.second;
        }
    }
    return vote;
}

std::unordered_map<int, float> Dataset::classFrequencies() const {
    auto freqs = std::unordered_map<int, float>();
    for(const int* label : labels) {
        freqs[*label] += 1;
    }
    for(auto &freq : freqs) {
        freq.second /= labels.size();
    }
    return freqs;
}

bool Dataset::allSameLabel() const {
    int label = *labels[0];
    for(const int* i : labels) {
        if(*i != label) return false;
    }
    return true;
}

std::vector<Dataset> Dataset::splitOnFeature(const std::string& feature) const {
    std::unordered_map<int, int> valueToPos;
    auto datasets = std::vector<Dataset>();
    for(int i = 0; i < data.size(); i++) {
        const DataItem* item = data[i];
        const int* label = labels[i];
        int value = item->getFeature(feature);
        if(valueToPos.find(value) == valueToPos.end()) {
            Dataset ds;
            datasets.push_back(ds);
            valueToPos[value] = (int) datasets.size() - 1;
        }
        datasets[valueToPos[value]].add(item, label);
    }
    return datasets;
}

int Dataset::size() const {
    return (int) data.size();
}

std::vector<const DataItem*>& Dataset::getData() {
    return data;
}

std::vector<const int*>& Dataset::getLabels() {
    return labels;
}

std::vector<std::string> Dataset::getFeatures() const {
    return data[0]->getFeatures();
}

std::vector<const DataItem*>::const_iterator Dataset::begin() const {return data.cbegin();}
std::vector<const DataItem*>::const_iterator Dataset::end() const {return data.cend();}