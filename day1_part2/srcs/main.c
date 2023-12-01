#include "../headers/advent.h"

int	ft_long_digit(char *str)
{
	if (*str == 'o' && ft_strncmp(str, "one", 3) == 0)
		return (1);
	else if (*str == 't' && ft_strncmp(str, "two", 3) == 0)
		return (2);
	else if (*str == 't' && ft_strncmp(str, "three", 5) == 0)
		return (3);
	else if (*str == 'f' && ft_strncmp(str, "four", 4) == 0)
		return (4);
	else if (*str == 'f' && ft_strncmp(str, "five", 4) == 0)
		return (5);
	else if (*str == 's' && ft_strncmp(str, "six", 3) == 0)
		return (6);
	else if (*str == 's' && ft_strncmp(str, "seven", 5) == 0)
		return (7);
	else if (*str == 'e' && ft_strncmp(str, "eight", 5) == 0)
		return (8);
	else if (*str == 'n' && ft_strncmp(str, "nine", 4) == 0)
		return (9);
	return (0);
}

int	ft_first_digit(char *str)
{
	int	num;

	while (*str)
	{
		num = ft_long_digit(str);
		if (num)
			return (num);
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
		if (ft_long_digit(str))
			num = ft_long_digit(str);
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
		ft_printf("line: %s || first:%i last:%i\n", str, first, last);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	ft_printf("The sum is: %i \n", sum);
	return (0);
}
