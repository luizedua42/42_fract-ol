/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:21:46 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/01 18:22:14 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractollib.h"

int	key_press(int kode, t_mlx *param)
{
	if (kode == XK_Escape)
		close_win(param);
	return (0);
}
