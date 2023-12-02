#include "../headers/advent.h"

#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14

char	**ft_sets_of_dice(char *str);
int		ft_check_sets(char **sets);
int		ft_min_cubes(char *str, int rgb);

int	main(void)
{
	char	*str;
	char	**sets;
	int		fd;
	int		sum;

	sum = 0;
	fd = open("input.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		ft_printf("----------\n%s\n", str);
		sets = ft_sets_of_dice(str);
		sum += ft_check_sets(sets);
		str = get_next_line(fd);
	}
	ft_printf("The sum of the minimum set of cubes is %i\n", sum);
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
	int	sum;
	int	red;
	int	green;
	int	blue;

	i = 0;
	sum = 0;
	red = 1;
	green = 1;
	blue = 1;
	while (sets[i])
	{
		ft_printf("set: %s", sets[i]);
		if (sets[i + 1])
			ft_printf("\n");
		if (ft_min_cubes(sets[i], 0) > red)
			red = ft_min_cubes(sets[i], 0);
		if (ft_min_cubes(sets[i], 1) > green)
			green = ft_min_cubes(sets[i], 1);
		if (ft_min_cubes(sets[i], 2) > blue)
			blue = ft_min_cubes(sets[i], 2);
		free(sets[i]);
		i++;
	}
	ft_printf("\nminimums:\nred:   %i\ngreen: %i\nblue:  %i\n\n",
		red,
		green,
		blue);
	sum = red * green * blue;
	free(sets);
	return (sum);
}

int	ft_min_cubes(char *str, int rgb)
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
	if (rgb == 0)
		return (red);
	if (rgb == 1)
		return (green);
	if (rgb == 2)
		return (blue);
	return (0);
}
