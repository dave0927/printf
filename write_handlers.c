#include "main.h"

#define BUFF_SIZE 256

void handle_padding(char buffer[], int flags, int width,
    char padd, char extra_c) 
{
	int i;
	
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
		{
			buffer[BUFF_SIZE - i - 2] = padd;
        }
		if (flags & F_MINUS) 
		{
			if (extra_c)
				buffer[BUFF_SIZE - i - 1] = extra_c;
        } else {
			if (extra_c)
                buffer[0] = extra_c;
        }
    }
}

int handle_write_char(char c, char buffer[], int flags, int width,
	int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';
	handle_padding(buffer, flags, width, padd, 0);
	return (write(1, &buffer[0], 1));
}

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
    else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	if (prec == 0 && ind == BUFF_SIZE - 2 &&
		buffer[ind] == '0' && width == 0)
    	return (0);
    if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';

	while (prec > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	handle_padding(buffer, flags, width, padd, extra_ch);
	return (write(1, &buffer[ind], length));
}
