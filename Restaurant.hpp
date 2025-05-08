#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <memory>
#include "Table.hpp"
#include "Customer.hpp"
using namespace std;

class Restaurant {
private:
    vector<unique_ptr<Table>> tables;
    vector<shared_ptr<Customer>> activeCustomers;
    vector<weak_ptr<Customer>> waitList;

public:
    Restaurant(int initialTableCount);
    bool reserveTable(shared_ptr<Customer> &_customer);
    void printWaitlist();
    bool releaseTable(int tableNumber);
    void notifyWaitlist();
};

#endif
