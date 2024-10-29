//
// Created by mathias on 01.02.19.
//

#include "DataItem.h"

void DataItem::setFeature(const std::string &feature, int value) {
    features[feature] = value;
}

std::vector<std::string> DataItem::getFeatures() const {
    std::vector<std::string> features;
    features.reserve(this->features.size());
    for (const auto &feature: this->features) {
        features.push_back(feature.first);
    }
    return features;
}

int DataItem::getFeature(const std::string &feature) const {
    return features.at(feature);
}
