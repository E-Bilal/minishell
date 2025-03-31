/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:40:28 by senayat           #+#    #+#             */
/*   Updated: 2024/11/08 14:32:37 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	set_env_var_export(t_msh *sh, char *var, char *val)
{
	t_env	**current;

	if (!sh)
		return (false);
	current = &(sh->env);
	while (*current && ft_strncmp((*current)->var, var, ft_strlen(var)) != 0)
		current = &((*current)->next);
	if (!*current)
	{
		*current = ft_calloc(1, sizeof(t_env));
		if (!*current)
			return (false);
		(*current)->var = var;
		(*current)->val = val;
	}
	else if (*current && ft_strlen((*current)->val) != 0)
	{
		free(val);
	}
	else if (*current && ft_strlen(val) > 0)
	{
		free((*current)->val);
		(*current)->val = val;
	}
	return (true);
}

bool	set_env_var(t_msh *sh, char *var, char *val)
{
	t_env	**current;

	if (!sh)
		return (false);
	current = &(sh->env);
	while (*current && ft_strncmp((*current)->var, var, ft_strlen(var)) != 0)
		current = &((*current)->next);
	if (!*current)
	{
		*current = ft_calloc(1, sizeof(t_env));
		if (!*current)
			return (false);
		(*current)->var = var;
	}
	else
		free((*current)->val);
	(*current)->val = val;
	return (true);
}
