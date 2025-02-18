/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:19:29 by femorell          #+#    #+#             */
/*   Updated: 2023/03/13 15:19:30 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;

	temp = (const unsigned char *)s;
	while (n--)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
	}
	return (NULL);
}

/*int main()
{
	printf("%s\n", (char *)memchr("bonjour", 'o', 7));
	printf("%s\n", (char *)ft_memchr("bonjour", 'o', 7));
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s\n", (char *)memchr(tab, -1, 7));
	printf("%s", (char *)ft_memchr(tab, -1, 7));

	printf("expected:\n");
	printf("%s\n", (char*)memchr("abcdefg", 'b', 3));
	//printf("%s\n", (char*)memchr("abcdefg", 'g', 5));
	printf("%s\n", (char*)memchr("abcdefg", 'c', 100));
	//printf("%s\n", (char*)memchr("abcdefg", 'z', 100));
	printf("yours:\n");
	printf("%s\n", (char*)ft_memchr("abcdefg", 'b', 3));
	//printf("%s\n", (char*)ft_memchr("abcdefg", 'g', 5));
	printf("%s\n", (char*)ft_memchr("abcdefg", 'c', 100));
	//printf("%s\n", (char*)ft_memchr("abcdefg", 'z', 100));
}*/
