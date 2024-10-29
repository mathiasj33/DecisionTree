//
// Created by mathias on 01.02.19.
//

#ifndef TRY_DATAITEM_H
#define TRY_DATAITEM_H

#include <string>
#include <vector>
#include <unordered_map>

class DataItem {
public:
    void setFeature(const std::string& feature, int value);
    int getFeature(const std::string& feature) const;
    std::vector<std::string> getFeatures() const;
private:
    std::unordered_map<std::string, int> features;
};


#endif //TRY_DATAITEM_H
