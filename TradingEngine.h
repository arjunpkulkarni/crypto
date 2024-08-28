#ifndef TRADINGENGINE_H
#define TRADINGENGINE_H

#include <vector>
#include "Order.h"

class TradingEngine {
private:
    std::vector<Order> orderBook;
    std::vector<Trade> tradeHistory;

    void applyRiskManagement(Order& order);

public:
    void addOrder(const Order& order);
    void matchOrders();
    void executeRealTime();
    void backtest(const std::vector<Order>& historicalOrders); 

    std::vector<Trade> getTradeHistory() const; 
};

#endif
