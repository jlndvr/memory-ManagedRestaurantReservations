#include <iostream>
#include "Restaurant.hpp"

using namespace std;

int main() {

  // Initialize Restaurant with 2 tables
  Restaurant restaurant(2);

  // Create customers and make reservations
  shared_ptr<Customer> customer1 = make_shared<Customer>("Hanna");
  shared_ptr<Customer> customer2 = make_shared<Customer>("Jeda");
  shared_ptr<Customer> customer3 = make_shared<Customer>("Mark");
  shared_ptr<Customer> customer4 = make_shared<Customer>("Juan");

  // Release a table and demonstrate waitlist notification
  cout << "Reserving table for " << (*customer1).getName() << ": " << (restaurant.reserveTable(customer1) ? "Success" : "Added to waitlist") << endl;
  restaurant.releaseTable(4);
  restaurant.printWaitlist();

  return 0;

}
