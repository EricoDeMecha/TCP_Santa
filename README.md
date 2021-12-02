# TCP_Santa
TCP Santa

## Dependencies
* C++ Boost version 1.65+
## Setup
Build essentials
```bash
sudo apt-get install build-essential cmake make
```
Boost dev. (Ubuntu 18.04 comes with 1.65+)
```
sudo apt-get install libboost-all-dev
```

## Usage
cmake & make 
```bash
cd <dir> && cmake && make 
```
g++
```bash
g++ main.cpp -lboost_system -o exec && ./exec
```




