/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:52:04 by mtani             #+#    #+#             */
/*   Updated: 2023/10/20 16:49:36 by mtani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_strlen.c"
//#include <stdlib.h>
#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*trimmed;
	int		i;

	begin = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	while (s1[begin] != '\0' && ft_check_set(s1[begin], set) == 1)
		begin++;
	while (end > begin && ft_check_set(s1[end], set) == 1)
		end--;
	trimmed = (char *)malloc(((end - begin) * sizeof(char)) + 2);
	if (trimmed == NULL)
		return (NULL);
	while (begin < (end + 1))
	{
		trimmed[i] = s1[begin];
		i++;
		begin++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

/*int main()
{
	char string[] = "";
	char set[] =  "z";
	printf("%s\n",  ft_strtrim(string, set));
}*/
