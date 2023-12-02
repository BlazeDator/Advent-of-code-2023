#include "../headers/advent.h"

#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14

int	main(void)
{
	char	*str;
	char	**temp;
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
		temp = ft_split(str, ':');
		free(str);
		str = temp[1];
		free(temp[0]);
		free(temp);
		temp = ft_split(str, ';');
		free(str);
		while (temp[i])
		{
			ft_printf("id:  %i set: %i %s\n", id, i + 1, temp[i]);
			free(temp[i]);
			i++;
		}
		free(temp);
		str = get_next_line(fd);
	}
	ft_printf("The sum of possible games ids is %i\n", sum);
	close(fd);
	return (0);
}
