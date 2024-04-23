# Instructions

Below are some instructions to operate and use the **Edstem Assignment Tracker**:

## * Windows Users

If you are using a Windows operating system you will need to confirm that you have Python and GCC installed on your device.

1. To confirm Python is installed on your device you can run `python --version`. This will print out the current version of python that is installed on your PC.
>If you do not have Python installed you can find more information [here](https://www.python.org/downloads/).

2. Confirm that GCC is installed you can run `gcc --version`. This will print the current version of gcc installed on your device.
>To install the GCC compiler you can install [Chocolatey](https://chocolatey.org/install) and then run `choco install mingw`. For more instructions visit [here](https://www.mingw-w64.org/downloads/#w64devkit).

3. After confirming Python and GCC are present you can proceed with the instructions to use the project.

## * MacOS/Unix Users

If you are using a MacOS/Unix machine you will need to make sure that Python and g++ are both present on your device.

1. To confirm that Python is installed on your device you can run `python --version`. If Python is installed you will see the current version of Python for your device.
>If you do not have Python installed you can find more information [here](https://www.python.org/downloads/).

2. Confirm that GCC is installed you can run `gcc --version`. This will print the current version of gcc installed on your device.
>If you do not have gcc installed you can install it via [homebrew](https://formulae.brew.sh/formula/gcc)

3. After confirming Python and GCC are present you can proceed with the instructions to use the project.

## Using the Edstem Tracker

### 1. Installation:
To install the Edstem Assignment Tracker Program you need to run `pip install edstem-assignment-tracker`. 
>**Note**: Some users may need to use `pip3`.


### 2. Generating a token:
To run the Edstem Assignment Tracker Program you first need to create a token for Edstem to authenticate you.
- Running `generate-env` will prompt the instructions for the user to create an environment token. 
- After following the instructions the user will now have an environment token in their current terminal.

### 3. Running Edstem Assignment Tracker:
Finally to run the program you simply need to run `ed-tracker`. This will confirm the necessary packages are installed and will proceed to collect data from edstem. 

Have fun!
