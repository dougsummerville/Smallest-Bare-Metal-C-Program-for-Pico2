# Smallest-Bare-Metal-C-Program-for-Pico2
Example to show the bare minimum needed to get a program running on the Raspberry Pi Pico2 entirely in C without any SDK, external libraries or header files.  The example program flashes the onboard LED.

The goal of this project is a starting point for a bare metal system for the Raspberry Pi Pico2, written in C, which does not require any external libraries, SDKs, etc.  This is not meant to be a full-fledged enviroment but an example of the minimum required to flash a LED. Only the GCC cross-compiler is required.  Python is needed to convert the .efl to .uf2, but any other ELF-to-UF2 convertor should also work.

If you're looking for a more useful bare metal environment for the Pico 2, consider this [Bare Metal Raspberry Pi Pico 2](https://github.com/dougsummerville/Bare-Metal-Raspberry-Pi-Pico-2)

# Running the Example
Type make and then copy the UF2 to the Pico2.
