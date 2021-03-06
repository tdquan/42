/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_num_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:30:29 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/14 12:09:13 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char		*move_min_num(char *solution, t_super_stack *super_stack)
{
	if (super_stack->stack_a->min_idx == 1)
	{
		perform_op("sa", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		solution = update_solution(solution, "sa");
	}
	else if (super_stack->stack_a->min_idx >
				(super_stack->stack_a->cur_size / 2))
	{
		perform_op("rra", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		solution = update_solution(solution, "rra");
	}
	else if (super_stack->stack_a->min_idx <=
						(super_stack->stack_a->cur_size / 2))
	{
		perform_op("ra", super_stack->stack_a,
					super_stack->stack_b, super_stack->flags);
		solution = update_solution(solution, "ra");
	}
	return (solution);
}

char		*min_num_solver(char *solution, t_super_stack *super_stack)
{
	int		top;

	while (!(is_sorted(super_stack->stack_a->nums,
		super_stack->stack_a->cur_size) && !super_stack->stack_b->cur_size))
	{
		if (super_stack->stack_a->cur_size == 3)
			solution = handle_three(solution, super_stack);
		find_min(super_stack->stack_a);
		while ((top = super_stack->stack_a->nums[0]) && top !=
				super_stack->stack_a->min_num)
			solution = move_min_num(solution, super_stack);
		if (!is_sorted(super_stack->stack_a->nums, super_stack->stack_a->cur_size))
		{
			solution = update_solution(solution, "pb");
			perform_op("pb", super_stack->stack_a,
						super_stack->stack_b, super_stack->flags);
		}
		else
		{
			while (super_stack->stack_b->cur_size)
			{
				solution = update_solution(solution, "pa");
				perform_op("pa", super_stack->stack_a,
							super_stack->stack_b, super_stack->flags);
			}
		}
	}
	return (solution);
}

void		find_min(t_stack *stack)
{
	int		min_num;
	int		min_idx;
	int		i;

	min_num = stack->nums[0];
	min_idx = 0;
	i = 1;
	while (i < stack->cur_size)
	{
		if (stack->nums[i] < min_num)
		{
			min_num = stack->nums[i];
			min_idx = i;
		}
		i++;
	}
	stack->min_num = min_num;
	stack->min_idx = min_idx;
}
