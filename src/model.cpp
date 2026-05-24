#include "model.h"

Model::Model() {}

Model::Model(const Model& obj) : systems(obj.systems), flows(obj.flows) {}

Model::~Model() {}

Model& Model::operator=(const Model& obj) {
    if (this != &obj) {
        systems = obj.systems;
        flows = obj.flows;
    }
    return *this;
}

void Model::add(System* system) {
    systems.push_back(system);
}

void Model::add(Flow* flow) {
    flows.push_back(flow);
}

void Model::execute(int initialTime, int finalTime) {
    for (int t = initialTime; t < finalTime; ++t) {
        vector<double> results;
        
        for (Flow* f : flows) {
            results.push_back(f->execute());
        }
        
        for (size_t i = 0; i < flows.size(); ++i) {
            System* src = flows[i]->getSource();
            System* tgt = flows[i]->getTarget();
            
            if (src != nullptr) {
                src->setValue(src->getValue() - results[i]);
            }
            if (tgt != nullptr) {
                tgt->setValue(tgt->getValue() + results[i]);
            }
        }
    }
}