//
// Created by mathias on 03.02.19.
//

#ifndef TRY_LOADEDDATASET_H
#define TRY_LOADEDDATASET_H

#include <string>
#include <vector>
#include "DataItem.h"

class LoadedDataset {
public:
    explicit LoadedDataset(std::string path);
    std::vector<int>& getLabels();
    std::vector<DataItem>::const_iterator begin() const;
    std::vector<DataItem>::const_iterator end() const;

private:
    std::vector<DataItem> data;
    std::vector<int> labels;
};


#endif //TRY_MEMORYDATASET_H
