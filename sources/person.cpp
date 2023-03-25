#include "../includes/person.h"

Person::Person()
{}

Person::~Person()
{}

void Person::set_name(const std::string& name)
{
    _name = name;
}
void Person::set_address(const std::string& address_street, const std::string& address_city,const std::string& address_state,const std::string& address_zip)
{
    _address.push_back(address_street);
    _address.push_back(address_state);
    _address.push_back(address_city);
    _address.push_back(address_zip);
}
void Person::set_age(int age)
{
    _age = age;
}
void Person::set_gender(const std::string& gender)
{
    _gender = gender;
}
void Person::set_height(int height)
{
    _height = height;
}
void Person::set_weight(int weight)
{
    _weight = weight;
}
std::string Person::get_name() const
{
    return _name;
}
std::string Person::get_address() const
{
    return static_cast<std::string>(_address[0]) + " " + static_cast<std::string>(_address[1])
                                + " " + static_cast<std::string>(_address[2]) + " " + static_cast<std::string>(_address[3]);
}
std::string Person::get_gender() const
{
    return _gender;
}
int Person::get_age() const
{
    return _age;
}
int Person::get_height() const
{
    return _height;
}
int Person::get_weight() const
{
    return _weight;
}