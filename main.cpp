#include <iostream>
#include <format>
#include "change_string.h"

/*
 * So constructors are called at the end of their life. Below is a non-inclusive list.
 * 1) Including the end of a closing }.
 * 2) An object being made without a name.
 * 3) Or calling delete on something.
 */
int main()
{
    std::string message{"empty"};

    change_string* to_delete = nullptr;

    auto print = [call_count = 0, &message]() mutable {
        call_count++;
        std::cout << std::format("Index: {}, \t message's value: {}\n", call_count, message);
    };

    { // Explicit scope to show that you the final result;
        change_string cs1{message, "not empty"};
        print(); // "empty" because cs1's destructor isn't called until line 39

        change_string{message, "null"}; // message is changed to "null" here because it was unnamed, and has no reason to continue to exist.
        print(); // message is still not empty.

        { // Explicit code as another example of lifetimes
            change_string local(message, "not null");
            print(); // message is still "null" because local's destructor isn't called until the bracket at line 32
        } print(); // message is now "not null".

        if(message == "not null"){ // any brackets define a scope, ergo destructor lifetimes behave the same in any necessary scopes
            change_string local(message, "no value");
            print(); // message is still "not null" because local's destructor isn't called until the bracket at line 39
        } print(); // message is now "no value".
        to_delete = new change_string{message, "delete"}; // to_delete  exists untile delete is called at 42.
    }

    print(); // message is "not empty"
    delete to_delete; // to_delete's constructor is called right here.
    print(); // message is now "delete"
    
    return 0;
}
