//reverse_bits

unsigned char	reverse_bits(unsigned char octet){
	char	final = 0, pos = 7;

	for (; octet; octet /= 2){
		final += octet % 2<<pos;
		pos -= 1;
	}
	return final;
}
