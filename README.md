# Basic DCS QFE calculator

Super basic QFE calculator I whipped up in less than an hour. Enter your starting QNH and target elevation, and it should spit out a QFE setting for you.

## Units and Flags

By default, the program lets you input the target elevation in feet. To change the input unit, use the following flags:
 `-m` or `-M`: metric, meters
 `-i` or `-I`: imperial (US customary), feet
Example:
`./qfe_calc` -i to use imperial units.
Note: barometric pressure units are always in hectopascals (hPa).

## """Installation""

Just download the files, and run `make` on the terminal to compile.
If you somehow don't already have the basics to compile C code (such as `build-essential`), get it.

## Disclaimer

I am not a PPL, formulas used were taken from Chuck's guides for use in DCS. I am not liable for any damages, injuries, or fatalities if you try to use this in a real plane.
