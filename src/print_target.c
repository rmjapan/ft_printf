/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:05:04 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/03/05 12:40:02 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_target(t_printf_format *memo, int *return_result)
{
	if (memo->type == 1)
		printf_c(memo, return_result);
	else if (memo->type == 2)
		printf_s(memo, return_result);
	else if (memo->type == 3)
		printf_p(memo, return_result);
	else if (memo->type == 4 || memo->type == 5 || memo->type == 6)
		printf_d_i_u(memo, return_result);
	else if (memo->type == 7)
		printf_x(memo, return_result);
	else if (memo->type == 8)
		printf_xx(memo, return_result);
}
