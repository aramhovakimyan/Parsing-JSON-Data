#include "parse_json_data.hpp"

int main(int argc, char** argv)
{
    // Check if the user passed path.
    if (argc == 2)
    {
        // Check if the users passed path is correct and can be opened.
        if (!check_file(argv[1]))
        {
            return 0;
        }

        // Declare vector of type Person* to contain each person 
        std::vector<Person*> persons;

        // Parsing from person.json file
        parse_from_json(persons, argv[1]);

        // Append person information to person.txt file to show the parsed result
        append_to_file(persons);

        // Append person information to average_age.json file
        average_age_person(persons);

        // Delete resources from heap
        for (auto& el : persons)
        {
            delete el;
            el = nullptr;
        }

        // Print success message.
        std::cout << "SUCCESS: You can check 'result.json' and 'average_age.json' files to take a result." << std::endl;
    }
    else
    {
        // Print error message.
        std::cout << "ERROR: Add path to .json file." << std::endl;
    }
    return 0;
}
