#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person
{
private:
    std::string _name;
    std::vector<std::string> _address;
    std::string _gender;
    int _age;
    int _height;
    int _weight;
public:
    Person();

    void set_name(const std::string& name);
    void set_address(const std::string& address_street, const std::string& address_city,const std::string& address_state,const std::string& address_zip);
    void set_age(int age);
    void set_gender(const std::string& gender);
    void set_height(int height);
    void set_weight(int weight);
    std::string get_name() const;
    std::string get_address() const;
    std::string get_gender() const;
    int get_age() const;
    int get_height() const;
    int get_weight() const;

    ~Person();
};

#endif