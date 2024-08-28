#include "OptionsStrategy.h"
#include <iostream>

void OptionsStrategy::coveredCall(TradingEngine& engine, const Option& option, const Order& underlyingAssetOrder) {
    std::cout << "Executing Covered Call Strategy" << std::endl;
    engine.addOrder(underlyingAssetOrder);
    
    if (underlyingAssetOrder.type == BUY) {
        Order sellCallOrder(underlyingAssetOrder.symbol, SELL, underlyingAssetOrder.quantity, option.strikePrice, 0, 0);
        engine.addOrder(sellCallOrder);
        std::cout << "Sold Call Option for " << underlyingAssetOrder.symbol << " @ " << option.strikePrice << std::endl;
    }
}

void OptionsStrategy::straddle(TradingEngine& engine, const Option& callOption, const Option& putOption) {
    std::cout << "Executing Straddle Strategy" << std::endl;
    
    if (callOption.optionType == CALL && putOption.optionType == PUT && callOption.strikePrice == putOption.strikePrice) {
        Order buyCallOrder(callOption.symbol, BUY, 1.0, callOption.strikePrice, 0, 0);
        Order buyPutOrder(putOption.symbol, BUY, 1.0, putOption.strikePrice, 0, 0);

        engine.addOrder(buyCallOrder);
        engine.addOrder(buyPutOrder);

        std::cout << "Bought Call and Put Options for " << callOption.symbol << " @ " << callOption.strikePrice << std::endl;
    } else {
        std::cerr << "Error: Mismatch in options for straddle strategy" << std::endl;
    }
}
