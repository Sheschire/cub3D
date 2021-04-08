/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:55:53 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 10:23:45 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_H
# define OS_H

# if defined(__linux__)
#  define PLATFORM 2
# elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
#  include <sys/param.h>
#  if defined(BSD)
#   define PLATFORM 2
#  endif
# elif defined(__APPLE__) && defined(__MACH__)
#  define PLATFORM 1
# endif

# if PLATFORM == 1
#  include "../mlxopengl/mlx.h"
# define W 13
# define A 0
# define D 2
# define S 1
# define TAB 48
# define ENTER 36
# define SHIFT 257
# define SPACE 49
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53
# elif PLATFORM == 2
#  include "../minilibx-linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define R 114
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define LEFT_ARROW 65361
#  define RIGHT_ARROW 65363
#  define TAB 65289
#  define SPACE_BAR 32
#  define SHIFT 65505
#  define ENTER 65293
# endif
#endif
