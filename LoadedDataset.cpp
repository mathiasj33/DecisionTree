//
// Created by mathias on 03.02.19.
//

#include "LoadedDataset.h"
#include "Dataset.h"
#include "DataItem.h"
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

LoadedDataset::LoadedDataset(const std::string& path) {
    std::ifstream infile(path);
    if(infile.is_open()) {
        std::string line;
        while(std::getline(infile, line)) {
            std::vector<std::string> parts(10);
            boost::trim(line);
            boost::split(parts, line, boost::is_any_of(" "));
            labels.push_back(std::stoi(parts[0]));
            parts.erase(parts.begin());

            auto item = DataItem();
            for(const auto &part : parts) {
                std::vector<std::string> featureAndValue;
                boost::split(featureAndValue, part, boost::is_any_of(":"));
                item.setFeature(featureAndValue[0], std::stoi(featureAndValue[1]));
            }
            data.push_back(item);
        }
        infile.close();
    }
}

std::vector<int>& LoadedDataset::getLabels() {
    return labels;
}
std::vector<DataItem>::const_iterator LoadedDataset::begin() const {return data.cbegin();}
std::vector<DataItem>::const_iterator LoadedDataset::end() const {return data.cend();}