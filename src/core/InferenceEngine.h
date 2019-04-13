//
// Created by tristan on 04/04/19.
//

#ifndef POLYGONIAL_INFERENCEENGINE_H
#define POLYGONIAL_INFERENCEENGINE_H


#include "FactsEngine.h"
#include "RulesEngine.h"
#include "Record.h"

class InferenceEngine {

private:
    FactsEngine &factsEngine;
    RulesEngine &rulesEngine;

public:
    InferenceEngine(FactsEngine &factsEngine, RulesEngine &rulesEngine);

    /*
     * Routing logic to fill the record either from the fact engine or the rules engine
     */
    void process(Record &record);

};


#endif //POLYGONIAL_INFERENCEENGINE_H
