//
// Created by james on 12/19/2021.
//

#ifndef EXAMPLE_FOR_ALEX_CHANGE_STRING_H
#define EXAMPLE_FOR_ALEX_CHANGE_STRING_H

#include <string>
class change_string{
public:
    change_string(std::string & to_change, std::string const & data);
    ~change_string();

    change_string(change_string const &) = default;
private:
    std::string & to_change;
    std::string data;
};

#endif //EXAMPLE_FOR_ALEX_CHANGE_STRING_H
