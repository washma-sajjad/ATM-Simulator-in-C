# ATM Application

## Description
This is a simple command-line ATM simulation program written in C. It allows users to:
- Check account balance
- Deposit money
- Withdraw money
- Exit the application

## Features
- PIN-based access (default PIN: 2346)
- 3 login attempts
- Input validation for deposits and withdrawals
- Color-coded output for user-friendly interaction

## Requirements
- C compiler (e.g., GCC)

## How to Compile
Use the following command to compile the program:

```bash
gcc atm_app.c -o atm_app
```
##After compiling, run the program using:

```bash
./atm_app
```
###otes
-Initial balance is set to 1,000,000
-Withdrawals must not exceed the current balance
-Deposits and withdrawals must be positive integers

