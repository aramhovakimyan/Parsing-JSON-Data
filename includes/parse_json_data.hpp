#ifndef PARSE_JSON_DATA_H
#define PARSE_JSON_DATA_H

#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "../includes/person.h"

using json = nlohmann::json;

//Declare the using funcitons
void parse_from_json(std::vector<Person*>& person_arr, const std::string& path);
void append_to_file(std::vector<Person*>& persons);
void average_age_person(const std::vector<Person*>& persons);
int	check_file(char *file);

#endif