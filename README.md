
# Parsing JSON Data and Calculating Average Age of Persons

This program reads a sample JSON file containing basic information about people (e.g., name, age, address, gender, height, weight), parses the JSON data using the nlohmann/json library, and calculates the average age of the people in the dataset. The program also outputs to JSON the calculated average age and the names of people with ages above the average.

## Usage

To use the program, follow these steps:

1.  Add  custom JSON file (`custom.json`), which contains valid JSON data with the expected structure and data types (e.g. existing `person.json`). Please implement your `custom.json` as it is implemented in `person.json` in this repository, if not, you will have error message by nlohmann.json library. Don't use `result.json` and `average_age.json` files as input, it will generate excpetion.
2.  Compile the program using a sample `make` command and then run following command (by added path to your .json file in this way) `./main /path/to/json`.
3.  View the output of the program in the output files.

## Requirements

The program requires the following software and libraries:

-   C++ compiler that supports the C++11 standard or later (e.g., g++, clang++)
-   nlohmann/json library (included in the `json.hpp` header file)

## Input

The program reads a sample JSON file called `custom.json`, which contains basic information about people, such as their name, age, address, gender, height, and weight (e.g. `person.json`).

## Output

The check_file function in this program takes a path to a JSON file as input, and checks if the file exists and can be opened. The function returns an integer code that indicates the result of the check:

 - If the file path does not end with the `.json` extension, the function returns an error code and prints the message `Your file must have .json extension.`
 - If the file cannot be opened or does not exist at the given path, the function returns an error code and prints the message `Your file doesn't opened or doesn't exist.`
 - If the file path is valid and the file can be opened, the function returns a success code and the file object can be used in the rest of the program.
  
If the file path is valid and the file can be opened, the program outputs the following files:

-   `result.json`: contains the parsed information about people, in the format `name, age, address, gender, height, weight`.
-   `average_age.json`: contains the calculated average age of the persons in the dataset, as well as the names of people with ages above the average, in JSON format.

## Design Choices

The program is designed as a collection of three C++ source files:

-   `parse.cpp`: reads the `person.json` file, parses the JSON data using the nlohmann/json library, and stores the parsed information in a C++ data structure.
-   `add_file.cpp`: reads the parsed information from the C++ data structure created by `parse.cpp`, formats the information as `name, age, address, gender, height, weight`, and adds the information to the `result.json` file.
-   `average_age_persons.cpp`: calculates the average age of the persons in the dataset, and adds the names of people with ages above the average to the `average_age.json` file.
-   The `check_json.cpp`: checks if the path to a JSON file exists, can be opened and validation of JSON file.   

The program uses the nlohmann/json library to parse the JSON data and handle JSON objects and arrays.

The program stores the parsed information in a vector of a custom `Person` struct, which stores the name, age, address, gender, height, and weight of a person.

The program calculates the average age of the persons in the dataset by summing the ages of all persons and dividing by the total number of persons.

The program adds the names of people with ages above the average to the `average_age.json` file by creating a new JSON object that contains the average age and an array of the names of people with ages above the average.

## Limitations

The program has the following limitations:

-   The program assumes that the `person.json` file contains valid JSON data with the expected structure and data types.
-   The program does not handle errors that may occur during file I/O, parsing, or calculations.
-   The program does not handle memory allocation or deallocation explicitly, relying on the default behavior of C++ data structures and the RAII mechanism.