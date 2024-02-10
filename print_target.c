/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:05:04 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/01/30 17:50:48 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/miyauchiryuuichi/Downloads/42tokyo/ft_printf/include/ft_printf.h"

void printf_c(t_printf_format *memo);
void printf_s(t_printf_format *memo);
void printf_p(t_printf_format *memo);
void printf_d(t_printf_format *memo);
void printf_i(t_printf_format *memo);
void printf_u(t_printf_format *memo);
void printf_x(t_printf_format *memo);
void printf_X(t_printf_format *memo);


void	printf_target(t_printf_format *memo)
{
	if (memo->type==1)
		printf_c(memo);
	else if (memo->type==2)
		printf_s(memo);
	else if (memo->type==3)
		printf_p(memo);
	else if (memo->type==4)
		printf_d(memo);
	else if (memo->type==5)
		printf_i(memo);
	else if (memo->type==6)
		printf_u(memo);
	else if (memo->type==7)
		printf_x(memo);
	else if (memo->type==8)
		printf_X(memo);
}
