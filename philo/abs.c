/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:15:09 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/23 14:03:40 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
