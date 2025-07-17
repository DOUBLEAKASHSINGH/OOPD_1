# Tax Calculator Program.
_Both question follows same method just a small change in the second question._
## Overview
* #### This program calulates the Long-term capital gains(LTCG) tax on a property based on inflation and growth rates over the years. The data for calculation is provided in a CSV file.

## Build Instructions

### Requirements

* #### Compiler: g++ or any other C++ compiler that supports C++11 or later.
* #### Make Utility: Ensure that make is installed on your system.

### Commands to Build the Program

    1.Compile the Debug Version:
* Command: make debug
* Description: This command compiles the program with debugging symbols enabled. The generated binary is named tax_calculator_debug.

### Compile the Optimized Version:
* Command: make release
* Description: This command compiles the program with optimization flags enabled. The generated binary is named tax_calculator_release.

### Clean Up:
* Command: make clean
* Description: This command removes all the object files and the compiled binaries.

## Running the Program
#### After building the program, you can run it by executing the following commands:
* #### Debug Version:
  * ./tax_calculator_debug
* Optimized Version:
  * ./tax_calculator_release


# 1 - Tax Calculation
#### This part of the program covers the basic calculation of the LTCG tax based on the provided growth and inflation rates. The classes and functions are designed to read the CSV file, compute the selling price, and then compute the LTCG tax based on the difference between the selling price and the original purchase price.

## Key Features:
* #### Tax_calculator Class: Handles the parsing of CSV data and computation of the tax.


# 2 - Tax Calculation with New and Old Scheme 
#### For the second question, additional features or modifications are implemented on a separate branch in the GitHub repository. This could include extended functionality, performance optimizations, or additional validation features.

## Key Features:
#### Special Tax Rate Logic:
* #### Before 2024: The LTCG tax is calculated at 20% of the profit.
* #### Starting from 2024: The LTCG tax rate is reduced to 12.5% of the profit.
___


* *  ## _Took help from github and chatgpt._
