#include "TradingEngine.h"
#include <iostream>
#include <algorithm>
#include <chrono>

void TradingEngine::applyRiskManagement(Order &order)
{
    if (order.type == BUY && order.price <= order.stopLoss)
    {
        std::cout << "Stop-loss triggered for " << order.symbol << " at " << order.stopLoss << std::endl;
        order.quantity = 0;
    }
    else if (order.type == SELL && order.price >= order.takeProfit)
    {
        std::cout << "Take-profit triggered for " << order.symbol << " at " << order.takeProfit << std::endl;
        order.quantity = 0;
    }
}

void TradingEngine::addOrder(const Order &order)
{
    Order newOrder = order;
    applyRiskManagement(newOrder);
    if (newOrder.quantity > 0)
    {
        orderBook.push_back(newOrder);
        std::cout << "Order added: " << order.symbol << " " << order.quantity << " @ " << order.price << std::endl;
        matchOrders();
    }
}

void TradingEngine::matchOrders()
{
    for (size_t i = 0; i < orderBook.size(); ++i)
    {
        for (size_t j = i + 1; j < orderBook.size(); ++j)
        {
            if (orderBook[i].symbol == orderBook[j].symbol &&
                orderBook[i].price == orderBook[j].price &&
                orderBook[i].type != orderBook[j].type)
            {

                Trade trade(orderBook[i].symbol, std::min(orderBook[i].quantity, orderBook[j].quantity), orderBook[i].price);
                tradeHistory.push_back(trade);

                std::cout << "Trade executed: " << trade.symbol << " " << trade.quantity << " @ " << trade.price << std::endl;

                orderBook[i].quantity -= trade.quantity;
                orderBook[j].quantity -= trade.quantity;

                if (orderBook[i].quantity == 0)
                {
                    orderBook.erase(orderBook.begin() + i);
                    --i;
                    break;
                }
                if (orderBook[j].quantity == 0)
                {
                    orderBook.erase(orderBook.begin() + j);
                }
            }
        }
    }
}

void TradingEngine::executeRealTime()
{
    auto now = std::chrono::system_clock::now();
    for (auto &order : orderBook)
    {
        if (order.timestamp <= now)
        {
            matchOrders();
        }
    }
}

void TradingEngine::backtest(const std::vector<Order> &historicalOrders)
{
    for (const auto &order : historicalOrders)
    {
        addOrder(order);
    }
}

std::vector<Trade> TradingEngine::getTradeHistory() const
{
    return tradeHistory;
}
