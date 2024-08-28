#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <chrono>

enum OrderType { BUY, SELL };
enum OptionType { CALL, PUT };

struct Order {
    std::string symbol;
    OrderType type;
    double quantity;
    double price;
    double stopLoss;  
    double takeProfit; 
    std::chrono::time_point<std::chrono::system_clock> timestamp; 

    Order(std::string s, OrderType t, double q, double p, double sl, double tp);
};

struct Trade {
    std::string symbol;
    double quantity;
    double price;
    std::chrono::time_point<std::chrono::system_clock> timestamp; 

    Trade(std::string s, double q, double p);
};

struct Option {
    std::string symbol;
    OptionType optionType;
    double strikePrice;
    double premium;
    std::chrono::time_point<std::chrono::system_clock> expiration;

    Option(std::string s, OptionType ot, double sp, double pr, std::chrono::time_point<std::chrono::system_clock> exp);
};

#endif
