# Basic QFE calculator

Super basic QFE calculator I whipped up in less than an hour. Enter your starting QNH and target elevation, and it should spit out a QFE setting for you.
Now it even has a port for the TI-84 CE Plus

## Desktop version

By default, the program lets you input the target elevation in feet. To change the input unit, use the following flags:
 `-m` or `-M`: metric, meters
 `-i` or `-I`: imperial (US customary), feet
Example:
`./qfe_calc` -i to use imperial units.
Note: barometric pressure units are always in hectopascals (hPa).

## Desktop """Installation"""

Just download the files, and run `make` on the terminal to compile.
If you somehow don't already have the basics to compile C code (such as `build-essential`), get it.

## TI-84 CE Plus version

There is no unit selector on this port, rather each unit system gets their own respective version of the program.

## TI-84 CE Plus installation

You'll need the [CE C/C++ Toolchain](https://ce-programming.github.io/toolchain/index.html) to compile the code. Install the toolchain, then simply run `make` in either the ti84cep_imperial or ti84cep_metric folders to compile the version you want.
To load the program onto the calculator, you'll need either [TI Connect CE](https://education.ti.com/en/us/products/computer_software/connectivity-software/ti-connect-ce-software/tabs/overview) or an open source alternative that doesn't come with TI's baggage.

## Disclaimer

I am not a PPL, formulas used were taken from Chuck's DCS guides. I am not liable for any damages, injuries, or fatalities if you try to use this in a real plane.
