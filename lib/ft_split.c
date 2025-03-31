/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:42:06 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/31 13:53:08 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_mem(char **res, int j)
{
    while (--j >= 0)
    {
        free(res[j]);
    }
    free(res);
    return (NULL);
}

// Counts the number of substrings needed for the malloc
static int	how_many(char const *s, char c)
{
    int	i;
    int	len;
    int	word_check;

    i = 0;
    len = 0;
    word_check = 0;
    while (s[i])
    {
        if (s[i] != c && word_check == 0)
        {
            word_check = 1;
            len++;
        }
        else if (s[i] == c)
            word_check = 0;
        i++;
    }
    return (len);
}

// Updates the position of start & end for the substrings
static void	update_start_end(char const *s, char c, int *start, int *end)
{
    while (s[*start] == c)
    {
        *start += 1;
    }
    *end = *start;
    while (s[*end] && s[*end] != c)
    {
        *end += 1;
    }
}

static char	**fill_res(char **res, char const *s, char c)
{
    int		start;
    int		end;
    int		j;

    start = 0;
    end = 0;
    j = 0;
    while (s[start])
    {
        update_start_end(s, c, &start, &end);
        if (start < end)
        {
            res[j] = malloc(sizeof(char) * (end - start + 1));
            if (!res[j])
                return (free_mem(res, j), NULL);
            ft_strlcpy(res[j], s + start, end - start + 1);
            start = end;
            j++;
        }
    }
    res[j] = NULL;
    return (res);
}

char	**ft_split(char const *s, char c)
{
    char	**res;

    if (!s)
        return (NULL);
    res = (char **)malloc(sizeof(char *) * (how_many(s, c) + 1));
    if (!res)
        return (NULL);

    return (fill_res(res, s, c));
}
