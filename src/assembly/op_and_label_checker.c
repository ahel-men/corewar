/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and_label_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 03:02:40 by ahel-men          #+#    #+#             */
/*   Updated: 2021/02/23 03:28:53 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		verify_label_chars(t_env *env, char *label)
{
	int i;

	i = -1;
	while (label[++i])
	{
		if (ft_binary_search(LABEL_CHARS, label[i]) < 0)
		{
			printf("Syntax Error[%d]: ", env->line_counter);
			printf("label <%s> contains inappropriate character\n",
				label);
			exit(0);
		}
	}
	return (1);
}

int		is_label_operation_in_same_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && !IS_COMMENT_CHAR(line[i]) && line[i] != LABEL_CHAR)
		i++;
	line[i] == LABEL_CHAR ? i++ : 0;
	while (IS_SPACE(line[i]))
		i++;
	if (is_operation(&line[i]))
		return (i);
	return (0);
}

void	ft_check_args_len(t_env *env, int len)
{
	if (env->found_op->arg_len < len)
	{
		printf("Error[%d]: too many arguments to operation <%s>\n",
			env->line_counter, env->found_op->op_name);
		exit(0);
	}
	else if (!len)
	{
		printf("Error[%d]: the operation <%s> has no arguments\n",
			env->line_counter, env->found_op->op_name);
		exit(0);
	}
	else if (env->found_op->arg_len > len)
	{
		printf("Error[%d]: too few arguments to operation <%s>\n",
			env->line_counter, env->found_op->op_name);
		exit(0);
	}
}

void	check_argument_value(t_env *env, char *trimed_str)
{
	int i;
	int reg_value;

	i = 0;
	if (trimed_str[0] == 'r')
	{
		reg_value = ft_atoi(trimed_str + 1);
		if (reg_value > REG_NUMBER)
			error_big_reg_value(env);
		if (reg_value < 0)
			error_reg_value_is_negative(env);
		if (trimed_str[1] == '+')
			error_value_contains_positive_sign(env, "Registery");
		while (trimed_str[++i])
		{
			if (!ft_isdigit(trimed_str[i]))
				error_reg_value_not_digit(env);
		}
	}
	else if (trimed_str[0] == DIRECT_CHAR)
		handle_number_error(env, trimed_str, "Direct");
	else if (trimed_str[0] == LABEL_CHAR || ft_is_string_number(trimed_str))
		handle_number_error(env, trimed_str, "Indirect");
}

void	check_passing_wrong_arg(t_env *env, char *trimed_str, int i)
{
	int res;

	res = env->found_op->arg[i];
	if (res == 1)
	{
		error_passing_direct(env, trimed_str[0]);
		error_passing_indirect(env, trimed_str);
	}
	else if (res == 2)
	{
		error_passing_registry(env, trimed_str[0]);
		error_passing_indirect(env, trimed_str);
	}
	else if (res == 3)
		error_passing_indirect(env, trimed_str);
	else if (res == 6)
		error_passing_registry(env, trimed_str[0]);
}
