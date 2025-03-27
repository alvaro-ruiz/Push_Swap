/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:44:25 by aruiz-bl          #+#    #+#             */
/*   Updated: 2024/10/02 16:54:10 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	char	*temp;

	d = malloc(ft_strlen(s) + 1);
	if (d == NULL)
	{
		return (NULL);
	}
	temp = d;
	while (*s != '\0')
	{
		*temp++ = *s++;
	}
	*temp = '\0';
	return (d);
}
