#include "parse_json_data.hpp"

int	check_file(char *path)
{
    // Check if the file have '.' and add starting from there to str.
	char* str = strrchr(path, '.');
    
    // If it doesn't have '.' symbol print error message.
    if (!str)
    {
        std::cout << "ERROR: Your file must have .json extension." << std::endl;
		return 0;
    }

    // Check if the file extension is '.json'. If not, print error message.
    const char* json_ext = ".json";
    int path_len = strlen(path);
    int ext_len = strlen(json_ext);
    if (path_len <= ext_len || strcmp(path + path_len - ext_len, json_ext) != 0)
    {
        std::cout << "ERROR: Your file must have .json extension." << std::endl;
        return 0;
    }

    // Check if the file path is correct and can be opened.
    std::ifstream file(path);
    if (!file)
    {
        std::cout << "ERROR: Your file doesn't opened or doesn't exist." << std::endl;
        return 0;
    }

    // Check if file is empty
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "ERROR: File is empty" << std::endl;
        return 0;
    }
    json data;
    try {
        file >> data;
    } catch (json::parse_error& e) {
        std::cout << "ERROR: " << e.what() << std::endl;
        return 0;
    }

    // Check file validation.
    if (data.is_null()) {
        std::cout << "ERROR: File is not a valid JSON" << std::endl;
        return 0;
    }
	
    // Return indicate to success.
    return (1);
}