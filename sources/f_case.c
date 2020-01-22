/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_case.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:17 by bsausage          #+#    #+#             */
/*   Updated: 2020/01/06 16:35:18 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_array_by_zero(ULL *rank, ULL *power)
{
	int		i;

	i = 0;
	while (i < MAX_RANK)
	{
		rank[i] = 0;
		power[i] = 0;
		i++;
	}
}

void	get_fraction(ULL *rank, unsigned long long fraction)
{
	int		i;

	i = 0;
	while (fraction)
	{
		rank[i++] = fraction % 1000000000;
		fraction = fraction / 1000000000;
	}
	rank[i] = -1;
}

int		len_digit_str(ULL *rank)
{
	int		i;
	int		k;
	int		len;

	i = MAX_RANK - 1;
	len = 0;
	while (!rank[i] || rank[i] == (ULL)(-1))
		i--;
	k = 1;
	while (rank[i] / k)
	{
		len++;
		k *= 10;
	}
	len += i * 9;
	return (len);
}

char	*convert_to_str(ULL *rank)
{
	char	*str;
	char	*tmp_str;
	int		len;
	int		i;
	int		k;

	len = len_digit_str(rank);
	str = (char *)malloc(sizeof(char) * (len + 2));
	tmp_str = str;
	str[len + 1] = 0;
	*str = '0';
	str++;
	k = 100000000;
	i = len / 9;
	while (k && rank[i] / k == 0)
		k /= 10;
	if (!k)
		i--;
	while (i >= 0)
	{
		if (!k)
			k = 100000000;
		while (k)
		{
			len = rank[i];
			*str = rank[i] / k + '0';
			rank[i] %= k;
			str++;
			k /= 10;
		}
		i--;
	}
	return (tmp_str);
}

int		positive_exp(t_f *f)
{
	int		len;
	//int		tmp;

	if (f->number->digits[0] == '0')
		f->number->digits++;
	len = ft_strlen(f->number->digits);
	if (!f->number->sign && f->flags->space)
		f->number->sign = '+';
	di_only_width_case(f, &len);
	return (len);
}

int		f_case(va_list arg_ptr, t_f *f)
{
	ULL				rank[MAX_RANK];
	ULL				power[MAX_RANK];
	long double			ld;
	union union_type	number;
	int					exp;
	int					len = 0;
	char				*str;
	int					i;

	fill_array_by_zero(rank, power);
	if (f->flags->lf)
		ld = va_arg(arg_ptr, long double);
	else
		ld = (long double)va_arg(arg_ptr, double);
	number.ld = ld;
	f->f_number->sign = number.part.sign ? '-' : 0;
	if (number.part.sign)
	{
		if (f->flags->space)
			f->f_number->sign = ' ';
		if (f->flags->plus)
			f->f_number->sign = '+';
	}
	get_fraction(rank, number.part.fraction);
	exp = number.part.exponent - 16383 - 63;
	//printf("exp = %d\n", exp);
	power[0] = 1;
	power[1] = -1;
	get_five_power(power, exp);
	mult(rank, power);
	str = convert_to_str(rank);
	printf("%s\n", str);

	char *tmp_str = str;
	//printf("len = %zu\n", ft_strlen(str));
	//printf("exp = %d\n", exp);
	if (exp < 0 && -exp <= (int)ft_strlen(str))
	{
		i = ft_strlen(str) + exp;
		len = ft_strlen(str) + exp + f->flags->precision;
		rounding(str + len);
		if (f->flags->precision)
		{
			len = f->flags->precision + 2;
			f->f_number->fract_part = (char*)malloc(sizeof(char) * len);
			f->f_number->fract_part[0] = '.';
			f->f_number->fract_part[len] = '\0';
			f->f_number->fract_part++;
			f->f_number->fract_part = ft_strcpy(f->f_number->fract_part, &str[i]);
			i = ft_strlen(str) - ft_strlen(f->f_number->fract_part);
			str[i] = 0;
			f->f_number->fract_part--;
		}
		if (*str == '0')
			str++;
		if (*str == 0)
			f->f_number->whole_part = ft_strdup("0");
		else
			f->f_number->whole_part = ft_strdup(str);
	}
	else if (exp < 0 && -exp > (int)ft_strlen(str))
	{
		len = ft_strlen(str + 1);
		i = -exp - len;
		if (f->flags->precision < i)
			f->f_number->fract_part = n_char('0', f->flags->precision, &len);
		else {
		rounding(str + 1 + f->flags->precision - i);
		if (*str == '0')
			str++;//i--;
		else
			i--;
		
		len = ft_strlen(str);
		f->f_number->fract_part = (char*)malloc(sizeof(char) * (len + i + 2));
		f->f_number->fract_part[0] = '.';
		f->f_number->fract_part[len + i + 1] = '\0';
		int tmp = 1;
		while (tmp <= i)
			f->f_number->fract_part[tmp++] = '0';
		f->f_number->fract_part += tmp;
		f->f_number->fract_part = ft_strcpy(f->f_number->fract_part, str);
		f->f_number->fract_part -= tmp;
		}
		f->f_number->whole_part = ft_strdup("0");
	}
	len = go_to_format(f);
	print_and_free_float_struct(f->f_number);
	ft_memdel((void**)&tmp_str);
	//i = 20;
	//while (i >= 0)
	//	printf("%09lld", rank[i--]);
	return (len);
}
//123645599999999972266584448148657233810830680711795867919921875000000000000
//123645599999999992665844494865723390830680727958679199218750000000000000000
//00012364557999999995266584450486572338083068068795867924921875005452564239
//00012364559999999999266584449486572339083068072795867919921875000000000000000000000000000000000000000
