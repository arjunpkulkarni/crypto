#include "Order.h"
#include <chrono>

Order::Order(std::string s, OrderType t, double q, double p, double sl, double tp) 
    : symbol(s), type(t), quantity(q), price(p), stopLoss(sl), takeProfit(tp) {
    timestamp = std::chrono::system_clock::now(); 
}

Trade::Trade(std::string s, double q, double p) 
    : symbol(s), quantity(q), price(p) {
    timestamp = std::chrono::system_clock::now(); 
}

Option::Option(std::string s, OptionType ot, double sp, double pr, std::chrono::time_point<std::chrono::system_clock> exp)
    : symbol(s), optionType(ot), strikePrice(sp), premium(pr), expiration(exp) {}
