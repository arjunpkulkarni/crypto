#include "TradingEngine.h"
#include "OptionsStrategy.h"
#include "Order.h"

int main() {
    TradingEngine engine;
    OptionsStrategy strategy;

    Order buyOrder("BTCUSD", BUY, 1.5, 45000, 44000, 47000);
    Order sellOrder("BTCUSD", SELL, 1.0, 45000, 43000, 46000);

    engine.addOrder(buyOrder);
    engine.addOrder(sellOrder);

    Option callOption("BTCUSD", CALL, 46000, 500, std::chrono::system_clock::now() + std::chrono::hours(24));
    strategy.coveredCall(engine, callOption, buyOrder);

    engine.executeRealTime();
    
    std::vector<Order> historicalOrders = {
        Order("ETHUSD", BUY, 2.0, 3000, 2900, 3200),
        Order("ETHUSD", SELL, 1.5, 3100, 3000, 3300)
    };
    
    engine.backtest(historicalOrders);

    return 0;
}
