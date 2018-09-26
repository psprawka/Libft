/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 03:34:45 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/26 06:02:24 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DEFINE
# define LIBFT_DEFINE

# define NORMAL			"\x1B[0m"
# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAGNETA		"\x1B[35m"
# define CYAN			"\x1B[36m"
# define WHITE			"\x1B[37m"
# define PINK			"\033[38;5;200m"
# define ORANGE			"\033[38;5;208m"
# define PURPLE			"\033[38;5;55m"
# define MAROON			"\033[38;5;88m"
# define GREY			"\033[38;5;246m"

# define BOLD			"\033[1m"
# define ITALIC			"\033[3m"
# define UNDERLINE 		"\033[4m"
# define CROSSED 		"\033[9m"
# define NO_BOLD		"\033[21m"
# define NO_ITALIC		"\033[23m"
# define NO_UNDERLINE 	"\033[24m"
# define NO_CROSSED 	"\033[29m"

# define IS_ALNUM(c)		(c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123) ? 1 : 0;
# define IS_ALPHA(c)		(c > 64 && c < 91) || (c > 96 && c < 123) ? 1 : 0;
# define IS_ASCII(c)		(c >= 0 && c < 128) ? 1 : 0;
# define IS_DIGIT(c)		(c > 47 && c < 58) ? 1 : 0;
# define IS_PRINTABLE(c)	(c > 31 && c < 127) ? 1 : 0;
# define IS_WHITE(c)		(c == '\t' || c == ' ' || c == '\v') ? 1 : 0

# define TO_UPPER(c)		(c > 96 && c < 123) ? c - 32 : c;
# define TO_LOWER(c)		(c > 64 && c < 91) ? c + 32 : c;

/*
**	prime numbers greater than ASCII
*/
# define HASH_BASE			151
# define HASH_BASE2			167

#endif
