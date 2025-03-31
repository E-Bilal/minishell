/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:20:29 by senayat           #+#    #+#             */
/*   Updated: 2024/11/08 14:34:40 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	swap_env(t_env **a, t_env **b)
{
	t_env	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_env(t_env **env, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (strcmp(env[j]->var, env[j + 1]->var) > 0)
				swap_env(&env[j], &env[j + 1]);
			j++;
		}
		i++;
	}
}

int	total_env(t_env *env)
{
	int		count;
	t_env	*current;

	count = 0;
	current = env;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

bool	print_sorted_env(t_env *env)
{
	int		i;
	int		count;
	t_env	*current;
	t_env	**sorted_env;

	count = total_env(env);
	sorted_env = ft_calloc(count, sizeof(t_env *));
	if (!sorted_env)
		return (false);
	current = env;
	i = 0;
	while (i < count)
	{
		sorted_env[i++] = current;
		current = current->next;
	}
	sort_env(sorted_env, count);
	i = 0;
	while (i < count)
	{
		printf("%s=%s\n", sorted_env[i]->var, sorted_env[i]->val);
		i++;
	}
	free(sorted_env);
	return (true);
}

bool	execute_export(t_msh *sh, char **args)
{
	int		i;
	t_env	*env;

	if (!sh || !args)
		return (false);
	sh->exit_code = 0;
	i = 1;
	if (!args[i])
		return (print_sorted_env(sh->env));
	while (args[i])
	{
		if (!is_valid_env_var(args[i]))
		{
			ft_printerr("export: `%s`: not a valid identifier\n", args[i]);
			sh->exit_code = 1;
		}
		else
		{
			env = env_from_envstr(args[i]);
			set_env_var_export(sh, env->var, env->val);
			free(env);
		}
		i++;
	}
	return (true);
}
