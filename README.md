# CSC 212 Research Project

## Description
<!-- Description of the project -->
Our project for CSC 212 is a grade/assignment tracker for CSC 212. We will be using Edstem based APIs to interact with Edstem and collect information on Edstem to provide an easy method for tracking assignments in the course.

This project uses a modified version of edapi called [edapiwl](docs/api_doc.md)(wl: with lessons). We Use this API to collect data from the user and we then store the data in various data structures.

This project is [published](https://pypi.org/project/edstem-assignment-tracker/) and available for download via `pip`. 

For this project we use three data structures:
* Splay Tree
* Binary Heap
* AVL Tree
>For information on each data structure [click here](docs/dsa.md).

## Goals
<!-- Write goals for project -->
- Modify Edstem API to retrieve course and lesson data
- Parse through data generated by Python in C++
- Store data in specified data structures
- Give users the option to view their data in different ways based off of some options/modes.


## Instructions

To begin using the Edstem Assignment Tracker you first need to install the package using `pip`.

1. If you have `pip` installed then you can run `pip install edstem-assignment-tracker`
>**Windows users**, If you experience errors during the installation process make sure that your terminal is compiling with g++.

2. After the installation is complete the next step is to run `generate-env`. This command will prompt you with the instructions to create an environment token for the 2nd command.

![gen-env gif](docs/gifs/gen-env-demo.gif)

3. Once you have created your environment token you can now run `ed-tracker`. Running this command will compile the script which collects the data, stores it, and gives the user 5 filtering options for their lesson data.

![ed-tracker gif](docs/gifs/ed-tracker-demo.gif)

### Additional Information

* [Group Information](docs/members.md)
* [Resources Used](docs/resources.md)