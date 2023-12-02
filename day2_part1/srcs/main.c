#include "../headers/advent.h"

#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14

char	**ft_sets_of_dice(char *str);

int	main(void)
{
	char	*str;
	char	**sets;
	int		fd;
	int		id;
	int		sum;
	int		i;

	sum = 0;
	fd = open("input.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		ft_printf("%s", str);
		id = ft_atoi(&str[5]);
		sets = ft_sets_of_dice(str);
		while (sets[i])
		{
			ft_printf("id:  %i set: %i %s\n", id, i + 1, sets[i]);
			free(sets[i]);
			i++;
		}
		free(sets);
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
