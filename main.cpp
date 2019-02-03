#include <iostream>
#include <string>

#include "Dataset.h"
#include "DecisionTree.h"
#include "chrono"

int main() {
    auto loadedTrainDataset = LoadedDataset("data/synthetic.social.train");
    auto trainDataset = Dataset(loadedTrainDataset);

    auto start = std::chrono::high_resolution_clock::now();

    DecisionTree tree = DecisionTree(500);
    tree.train(trainDataset);
    Classifier& model = tree;
    std::cout << model.accuracy(trainDataset) << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}