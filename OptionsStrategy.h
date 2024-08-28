#ifndef OPTIONSSTRATEGY_H
#define OPTIONSSTRATEGY_H

#include "TradingEngine.h"

class OptionsStrategy {
public:
    void coveredCall(TradingEngine& engine, const Option& option, const Order& underlyingAssetOrder);
    void straddle(TradingEngine& engine, const Option& callOption, const Option& putOption);
};

#endif
