#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum warehouse_status { overcapacity, operational, closed };

struct warehouse {
  char *city;
  int capacity;
  enum warehouse_status status;
};

struct warehouse warehouses[5];

void simulate_warehouse_operation(struct warehouse *w) {
  w->capacity = rand() % 101; // set a random capacity between 0% and 100%

  if (w->capacity < 20) {
    w->status = closed;
  } else if (w->capacity > 80) {
    w->status = overcapacity;
  } else {
    w->status = operational;
  }
}

void display_warehouse_information(struct warehouse *w) {
  printf("City: %s\n", w->city);
  printf("Capacity: %d%%\n", w->capacity);
  printf("Status: ");
  switch (w->status) {
    case overcapacity:
      printf("Overcapacity\n");
      break;
    case operational:
      printf("Operational\n");
      break;
    case closed:
      printf("Closed\n");
      break;
  }
}

int main() {
  // seed the random number generator
  srand(time(0));

  // initialize the warehouses
  warehouses[0].city = "Dublin";
  warehouses[0].capacity = 52;
  warehouses[0].status = operational;

  warehouses[1].city = "Limerick";
  warehouses[1].capacity = 83;
  warehouses[1].status = overcapacity;

  warehouses[2].city = "Cork";
  warehouses[2].capacity = 0;
  warehouses[2].status = closed;

  // simulate 365 days of operation
  for (int i = 0; i < 365; i++) {
    for (int j = 0; j < 3; j++) {
      simulate_warehouse_operation(&warehouses[j]);
      printf("Day %d\n", i + 1);
      display_warehouse_information(&warehouses[j]);
      printf("\n");
    }
  }

  return 0;
}