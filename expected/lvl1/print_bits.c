//print_bits

#include <unistd.h>

void	print_bits(unsigned char octet){
	if (octet > 1) print_bits(octet / 2);
	write(1, &"01"[octet % 2], 1);
}
