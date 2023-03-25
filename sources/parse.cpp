#include "../includes/parse_json_data.hpp"

void parse_from_json(std::vector<Person*>& person_arr, const std::string& path)
{
    // Declare json file
    std::ifstream file(path);
    json j_obj;

    // Add file containing to json object
    file >> j_obj;

    // Close resource
    file.close();

    // index to vector elements
    int i = 0;

    //Adding information of persons to person objects
    for (const auto& person : j_obj)
    {
        person_arr.emplace_back(new Person);
        person_arr[i]->set_name(person["name"]);
        person_arr[i]->set_age(person["age"]);
        person_arr[i]->set_address(person["address"]["street"], person["address"]["city"], person["address"]["state"], person["address"]["zip"]);
        person_arr[i]->set_gender(person["gender"]);
        person_arr[i]->set_height(person["height"]);
        person_arr[i]->set_weight(person["weight"]);
        ++i;
    }
}