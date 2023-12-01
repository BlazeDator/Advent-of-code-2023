#include "../headers/advent.h"

int	ft_first_digit(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			break ;
		str++;
	}
	return (*str - '0');
}

int	ft_last_digit(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = *str - '0';
		str++;
	}
	return (num);
}

int	main(void)
{
	char	*str;
	int		fd;
	int		first;
	int		last;
	int		sum;

	sum = 0;
	fd = open("input.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		first = ft_first_digit(str);
		last = ft_last_digit(str);
		sum = sum + (first * 10 + last);	
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	ft_printf("The sum is: %i \n", sum);
	return (0);
}
