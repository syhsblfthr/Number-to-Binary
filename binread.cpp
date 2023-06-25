#include "binread.hpp"

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <climits>

template <typename Ty>
struct sizeof_bits {
public:	
	static constexpr const std::size_t value = sizeof(Ty) * CHAR_BIT;
};

template <typename Ty>
static inline constexpr const std::size_t sizeof_bits_v = sizeof_bits<Ty>::value;

template <typename Ty>
	requires std::is_arithmetic_v<Ty>
static inline bool get_bit_reverse(const Ty number, const std::size_t nth) {
	static constexpr const std::size_t bits = sizeof_bits_v<Ty>;
	const std::size_t bit_mask = ((std::size_t)1 << (bits - 1)) >> nth;

	return (number & bit_mask);
}

template <typename Ty>
	requires std::is_arithmetic_v<Ty>
char *number_to_bitstring(const Ty number) {
	static constexpr const std::size_t bits = sizeof_bits_v<Ty>;
	char * bitstring = (char **)std::malloc(sizeof(char *) * (bits + 1));
	bitstring[bits] = '\0';

	for (std::size_t index = 0; index < bits; ++index)
		bitstring[index] = '0' + get_bit_reverse(number, index);

	return bitstring;
}

char **string_to_bitstring_array(const char *const str) {
	const std::size_t str_size = std::strlen(str);
	char **bitstring_array = (char**)std::malloc(sizeof(char**) * (str_size + 1));

	for (std::size_t index = 0; index < str_size; ++index)
		bitstring_array[index] = number_to_bitstring(str[index]);

	bitstring_array[str_size] = nullptr;

	return bitstring_array;
}

void clear_bitstring_array(char ***const bitstring_array_ptr) {
	char **bitstring_array = *bitstring_array_ptr;
	for (char *bitstring = *bitstring_array; bitstring != nullptr; bitstring = *(++bitstring_array)) {
		std::free(bitstring);
		*bitstring_array = nullptr;
	}
	std::free(*bitstring_array_ptr);
	*bitstring_array_ptr = nullptr;
}