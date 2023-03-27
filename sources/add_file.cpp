#include "parse_json_data.hpp"

void append_to_file(std::vector<Person*>& persons)
{
    // Declare result.json file
    std::ofstream file("result.json");

    // Declare json object for each person and object which contain that persons
    json each_person;
    json j_obj;

    //Append each person information to file
    for (const auto& person: persons)
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
    //Append persons in result.json file
    file << j_obj.dump(4);

    //Close resource
    file.close();
}