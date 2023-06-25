# binread library
A basic library for reading/retrieving the binary representation of numeric values (and arrays of numeric values).  
A personal project I wrote (and hopefully maintain) in my spare time (every miliseconds of my time).

Usage:
```cpp
// To get the binary representation of an integer.

#include <cstdlib> // std::free
#include <iostream> // std::cout
#include <binread.hpp>

int main() {
    char *binary_of_420 = number_to_bitstring(420);
    std::cout << binary_of_420 << '\n';
    std::free(binary_of_420);
    return 0;
}
```

```cpp
// To get the binary representation (of each character for now) of a C-style string (an array of characters)

#include <cstdlib> // std::free
#include <iostream> // std::cout
#include <binread.hpp>

int main() {
    const char *string = "I love you";
    char **bitstring_array = string_to_bitstring_array(string);
    
    // Loop through the bitstring for each character
    char **bitstring_array_ptr = bitstring_array;
    for (char *bitstring = *bitstring_array_ptr; bitstring != nullptr; bitstring = *(++bitstring_array_ptr))
        std::cout << bitstring << '\n';
    
    // Release the memory
    clear_bitstring_array(&bitstring_array);

    return 0;
}
```