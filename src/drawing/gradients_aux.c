#include "fdf.h"

int	hex_to_int(const char *hex_string)
{
	int	result;
	char c;
	int value;

	result = 0;
	hex_string = (hex_string + 2);
	while (*hex_string != '\0')
	{
		c = *hex_string;
		value = 0;
		if (ft_isdigit(c))
			value = c - '0';
		else if (c >= 'a' && c <= 'f')
			value = 10 + (c - 'a');
		else if (c >= 'A' && c <= 'F')
			value = 10 + (c - 'A');
		else
			return (0);
		result = (result << 4) | value;
		hex_string++;
	}
	return (result);
}
