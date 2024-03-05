/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wawa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wneel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:50:27 by wneel             #+#    #+#             */
/*   Updated: 2024/03/05 15:53:41 by wneel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wawa.h"
#include <stdio.h>

int	ft_wawa(int ac, char *av[], char *ev[])
{
  char *text = "echo '\"Salut les mecs\"'";
  
	int i = 0;
	int in_dquotes = 0;
  int in_squotes = 0;
  while (text[i] != '\0')
  {
    if (text[i] == '\'')
    {
      if (!in_dquotes)
      {
        in_squotes = in_squotes == 1 ? 0 : 1;
      }
    }
    if (text[i] == '"')
    {
      if (!in_squotes)
      {
        in_dquotes = in_dquotes == 1 ? 0 : 1;
      }
    }
    if ((in_dquotes && text[i] != '"') || (in_squotes && text[i] != '\''))
    {
      printf("%c", text[i]);
    }
    i++;
  }
	return (0);
}
