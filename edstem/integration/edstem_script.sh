#!/bin/bash

# TODO: ask the user to follow a link to get authentication token. Then create a .env file with the token and then run python.

# Run the python file to collect the data from edstem.
python3 edstem/integration/get_data.py

# delay for 5 seconds
sleep 5

# Run the cpp files to sort data
g++ -std=c++11 edstem/integration/storage/main.cpp -o edstem/integration/storage/store-data && ./edstem/integration/storage/store-data

# implement other things later