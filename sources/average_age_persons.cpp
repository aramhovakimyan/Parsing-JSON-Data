#include "parse_json_data.hpp"

void average_age_person(const std::vector<Person*>& persons)
{
    // Declare average_age.json file
    std::ofstream file("average_age.json");

    // Declare json object for each person and object which contain that persons
    json each_person;
    json j_obj;

    // Variable to contain average age of persons
    int average_age = 0;

    // Getting average age
    for (const auto& person : persons)
    {
        average_age += person->get_age();
    }
    average_age /= persons.size();

    //Add persons to j_obj object, whose age is above average
    for (const auto& person : persons)
    {
        if (person->get_age() >= average_age)
        {
            each_person = {
                    {"Name", person->get_name()},
                    {"Age", person->get_age()},
                    {"Address", person->get_address()},
                    {"Gender", person->get_gender()},
                    {"Height", person->get_height()},
                    {"Weight", person->get_weight()}
            };
            j_obj.push_back(each_person);
        }   
    }

    //Append persons in average_age.json file
    file << j_obj.dump(4);

    //Close resource
    file.close();
}
