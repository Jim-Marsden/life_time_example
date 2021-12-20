//
// Created by james on 12/19/2021.
//

#include "change_string.h"

change_string::change_string(std::string& to_change, std::string const & data) : to_change{to_change}, data{data} {}

change_string::~change_string()
{
    to_change = data;
}
