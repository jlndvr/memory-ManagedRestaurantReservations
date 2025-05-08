#include <iostream>
#include "Restaurant.hpp"
#include "Customer.hpp"
#include "removeElement.hpp"
using namespace std;

Restaurant::Restaurant(int initialTableCount) {
    for (int i = 1; i <= initialTableCount; i++) {
        tables.push_back(unique_ptr<Table>(new Table(i)));
    }
}

bool Restaurant::reserveTable(shared_ptr<Customer> &_customer) {
    for (unique_ptr<Table> &_table : tables) {
        if ((*_table).getIsAvailable()) {
            (*_table).reserve(); // Changed to match Table::reserve()
            activeCustomers.push_back(_customer);
            return true;
        }
    }
    waitList.push_back(_customer);
    cout << "Reservation not available at this time!" << endl;
    return false;
}

void Restaurant::printWaitlist() {
    cout << "The following people are waiting for a table: ";
    for (weak_ptr<Customer> &_customer : waitList) {
        shared_ptr<Customer> customerPtr = _customer.lock(); 
        if (customerPtr) {
            cout << (*customerPtr).getName() << " ";
        }
    }
    cout << endl;
}

bool Restaurant::releaseTable(int tableNumber) {
    for (unique_ptr<Table> &_table : tables) {
        if ((*_table).getNumber() == tableNumber) {
            if (!(*_table).getIsAvailable()) {
                (*_table).release();
                notifyWaitlist();
                return true;
            }
            return false;
        }
    }
    return false;
}

void Restaurant::notifyWaitlist() {
  if (waitList.empty()) return;
  shared_ptr<Customer> customer;
  customer = waitList[0].lock();
  if (customer) {
      reserveTable(customer);
      removeElement(waitList, waitList[0]);
  }
}
