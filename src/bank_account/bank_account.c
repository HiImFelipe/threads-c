#include <unistd.h>

#define TO_MICROSECONDS 1000000

int balance = 0;

int read_balance() {
  usleep(0.25 * TO_MICROSECONDS);
  return balance;
}

void write_balance(int transaction) {
  usleep(0.25 * TO_MICROSECONDS);
  balance += transaction;
}