#include <type_traits>

template <typename Ty>
	requires std::is_arithmetic_v<Ty>
extern char *number_to_bitstring(const Ty);

template <typename Ty>
	requires std::is_arithmetic_v<Ty>
extern char **string_to_bitstring_array(const char *const);

extern void clear_bitstring_array(char ***const);