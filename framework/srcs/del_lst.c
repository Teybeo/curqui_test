/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 19:47:15 by curquiza          #+#    #+#             */
/*   Updated: 2017/09/13 19:47:20 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ft_del_testlst(t_test **test)
{
	t_test	*tmp;
	t_test	*supp;

	tmp = *test;
	while (tmp)
	{
		supp = tmp;
		tmp = tmp->next;
		free(supp);
	}
}

void	ft_del_scorelst(t_score **score)
{
	t_score	*tmp;
	t_score	*supp;

	tmp = *score;
	while (tmp)
	{
		supp = tmp;
		tmp = tmp->next;
		free(supp);
	}
}
