# ATM_controller
C++ code for ATM_controller

## Build & Run Instructions

### Prerequisites
* C++ Compiler (g++, clang, or MSVC)
* Git

### 1. Clone the Repository
```bash
git clone https://github.com/Anony-doro/ATM_controller
cd ATM_controller
```

### 2. Run main program
```bash
g++ main.cpp BankSystem.cpp ATMController.cpp -o atm
# Mac/Linux
./atm

# Windows
./atm.exe
```

### 3. Run Test code

To run the automated test suite (verifies PIN logic, overdraft protection, etc.):
```bash
g++ test.cpp BankSystem.cpp ATMController.cpp -o run_tests
# Mac/Linux
./run_tests

# Windows
./run_tests.exe
```
