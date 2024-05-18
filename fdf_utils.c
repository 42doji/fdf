/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:19:53 by doji              #+#    #+#             */
/*   Updated: 2024/05/18 19:19:54 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_word(int *count, int in_word)
{
	if (!in_word)
	{
		*count += 1;
		return (1);
	}
	return (0);
}

int	is_split(char c, const char *delimiter)
{
	int	idx;

	idx = 0;
	while (delimiter && delimiter[idx])
	{
		if (c == delimiter[idx])
			return (1);
		idx++;
	}
	return (0);
}

int	count_words(const char *word, char *delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (word && *word)
	{
		if (!is_split(*word, delimiter))
			in_word = is_in_word(&count, in_word);
		else
			in_word = 0;
		word++;
	}
	return (count);
}
