/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa_evars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:22:50 by wneel             #+#    #+#             */
/*   Updated: 2024/03/16 11:35:37 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wawa.h"

int	var_name_end(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
		{
			i++;
			continue ;
		}
		return (i);
	}
	return (i);
}

int	calc_expanded_size(char *str, int i)
{
	t_quote_status	quote_status;
	char			*evar_value;
	char			*evar;
	int				chr;
	int				j;

	ft_init_quote_status(&quote_status);
	i = 0;
	j = 0;
	while (str[i])
	{
		update_quote_status(str[i], &quote_status);
		if (str[i] == '$' && !quote_status.in_squotes)
		{
			chr = var_name_end(&str[j + 1]);
			evar = ft_substr(str, i + 1, chr);
			evar_value = getenv(evar);
			j += ft_strlen(evar_value) - 1;
			i += ft_strlen(evar);
			free(evar);
		}
		i++;
		j++;
	}
	return (j);
}

void	assign_evar(char *str, char *expanded_char, int *j, int *k)
{
	char	*evar_value;
	char	*evar;
	int		chr;
	int		l;

	l = 0;
	chr = var_name_end(&str[*j + 1]);
	evar = ft_substr(str, *j + 1, chr);
	evar_value = getenv(evar);
	while (evar_value && evar_value[l])
	{
		expanded_char[*k] = evar_value[l];
		*k += 1;
		l++;
	}
	*k -= 1;
	*j += ft_strlen(evar);
	free(evar);
}

char	*expand_vars(char *str)
{
	t_quote_status	quote_status;
	char			*expanded_char;
	int				exp_size;
	int				k;
	int				j;

	ft_init_quote_status(&quote_status);
	exp_size = calc_expanded_size(str, 0);
	expanded_char = ft_calloc(exp_size + 1, sizeof(char));
	j = 0;
	k = 0;
	while (str[j])
	{
		update_quote_status(str[j], &quote_status);
		if (str[j] == '$' && !quote_status.in_squotes)
			assign_evar(str, expanded_char, &j, &k);
		else
			expanded_char[k] = str[j];
		j++;
		k++;
	}
	free(str);
	return (expanded_char);
}
