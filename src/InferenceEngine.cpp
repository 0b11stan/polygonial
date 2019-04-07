//
// Created by tristan on 04/04/19.
//

#include "InferenceEngine.h"

InferenceEngine::InferenceEngine(FactsEngine &factsEngine, RulesEngine &rulesEngine) : rulesEngine(rulesEngine),
                                                                                       factsEngine(factsEngine) {}
