#include "../headers/advent.h"

#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14

char	**ft_sets_of_dice(char *str);
int		ft_check_sets(char **sets);
int		ft_check_possible(char *str);

int	main(void)
{
	char	*str;
	char	**sets;
	int		fd;
	int		id;
	int		sum;

	sum = 0;
	fd = open("input.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		id = ft_atoi(&str[5]);
		ft_printf("%s", str);
		ft_printf("id:  %i\n", id);
		sets = ft_sets_of_dice(str);
		if (ft_check_sets(sets))
			sum = sum + id;
		str = get_next_line(fd);
	}
	ft_printf("The sum of possible games ids is %i\n", sum);
	close(fd);
	return (0);
}

char	**ft_sets_of_dice(char *str)
{
	char	**temp;

	temp = ft_split(str, ':');
	free(str);
	str = temp[1];
	free(temp[0]);
	free(temp);
	temp = ft_split(str, ';');
	free(str);
	return (temp);
}

int	ft_check_sets(char **sets)
{
	int	i;
	int	possible;

	i = 0;
	possible = 1;
	while (sets[i])
	{
		ft_printf("set: %s\n", sets[i]);
		if (!ft_check_possible(sets[i]))
			possible = 0;
		free(sets[i]);
		i++;
	}
	free(sets);
	return (possible);
}

int	ft_check_possible(char *str)
{
	int	red;
	int	green;
	int	blue;
	int	num;

	num = 0;
	red = 0;
	green = 0;
	blue = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			num = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		if (ft_isalpha(*str))
		{
			if (*str == 'r')
				red = num;
			if (*str == 'g')
				green = num;
			if (*str == 'b')
				blue = num;
			num = 0;
			while (ft_isalpha(*str))
				str++;
		}
		if (!*str)
			break ;
		str++;
	}
	if (red <= RED_CUBES
		&& green <= GREEN_CUBES
		&& blue <= BLUE_CUBES)
		return (1);
	return (0);
}
