/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:46:02 by tmaarela          #+#    #+#             */
/*   Updated: 2019/12/20 17:51:46 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	teststr[64] = "SAMPLE STRING STRONG!";
	char	ch = 'A';
	char	*tests;
	int		a;
	int		b;
	double	fn = 0.00005;
	double	fn2 = -13746.1337;
	int		num = 666;

	// printf("%.4s\n", "42");
	// ft_printf("%.4s\n", "42");

	// ft_printf("%c\n%c\n", 'T', 42);
	// printf("%%\n");

	// ft_printf("%.0%\n");
	// printf("%.0%\n");

	// a = ft_printf("%x\n", -42, 42);
	// b = printf("%x\n", -42);

	// ft_printf("%#X\n", 0);
	// printf("%#X\n", 0);

	// ft_printf("%.2x\n", 5427);
	// printf("%.2x\n", 5427);

	// ft_printf("%x\n", 4294967296);
	// printf("%x\n", 4294967296);

	// ft_printf("Hello%% World!\n");
	ft_printf("Number: %d and another: %d\n and string: %s\n", 12345, 666, teststr);
	printf("Number: %d and another: %d\n and string: %s\n", 12345, 666, teststr);

	ft_printf("Character: %c\n", ch);
	printf("Character: %c\n", ch);

	a = ft_printf("Pointer address: %p\n", tests);
	b = printf("Pointer address: %p\n", tests);

	ft_printf("With num 31,\n%o octal\n%x hex\n%X HEX\n", 31, 31, 31);
	printf("With num 31,\n%o octal\n%x hex\n%X HEX\n", 31, 31, 31);

	// ft_printf("int %9.6d\n", 567);
	// printf("int %9.6d\n", 567);

	// ft_printf("Flagtesting %09d\n", 12);
	// printf("Flagtesting %09d\n", 12);

	// a = ft_printf("Precision testing num 123456: %-+24.11d\n", 12347656);
	// b = printf("Noecision testing num 123456: %-+24.11d\n", 12347656);

	// ft_printf("RETURN FT_PRINTF: %d\n", a);
	// printf("RETURN PRINTF: %d\n", b);

	// ft_printf(COLOR_RED "Trying out %20.15d\n" COLOR_RESET, 88);
	// printf(COLOR_GREEN "Trying out %20.15d\n" COLOR_RESET, 88);

	// ft_printf("1Trying out %+10d\n", 87654);
	// printf("2Trying out %+10d\n\n", 87654);

	// ft_printf("Trying out %-10.8d\n", 77);
	// printf("Trying out %-10.8d\n\n", 77);

	// ft_printf("Float1:   %#.f\n", fn);
	// printf("Float2:   %#.f\n", fn);

	// ft_printf("Float1:   %.17f\n", fn);
	// printf("Float2:   %.17f\n", fn);

	// ft_printf("Float1:   %.f\n", fn);
	// printf("Float2:   %.f\n", fn);

	// ft_printf("Float1:   %f\n", fn);
	// printf("Float2:   %f\n", fn);

	// ft_printf("Float1:   %#.f\n", fn);
	// printf("Float2:   %#.f\n", fn);

	// ft_printf("Float1:   %17f\n", fn);
	// printf("Float2:   %17f\n", fn);

	// ft_printf("Float1:   %#.f\n", fn2);
	// printf("Float2:   %#.f\n", fn2);

	// ft_printf("Float1:   %.16f\n", fn2);
	// printf("Float2:   %.16f\n", fn2);

	// ft_printf("Float1:   %.f\n", fn2);
	// printf("Float2:   %.f\n", fn2);

	// ft_printf("Float1:   %f\n", fn2);
	// printf("Float2:   %f\n", fn2);

	// ft_printf("Float1:   %#.f\n", fn2);
	// printf("Float2:   %#.f\n", fn2);

	// ft_printf("Float1:   %17f\n", fn2);
	// printf("Float2:   %17f\n", fn2);

	// ft_printf("Float1:   %.44f\n", 8453455678252353453453453453453433453765745.345123456345);
	// printf("Float2:   %.44f\n", 1111111111111111111111111111111111111111111.111111111111111);

	// ft_printf("Octal flag:   %#.4o\n", num);
	// printf("Octal flag:   %#.4o\n", num);

	// ft_printf("hex flag:   %#.4x\n", num);
	// printf("hex flag:   %#.4x\n", num);

	// ft_printf("HEX flag:   %-20X\n", num);
	// printf("HEX flag:   %-20X\n", num);

	// ft_printf("1String prec:   %112s\n", "My dear, I regret nothing. Except dying.");
	// printf("2String prec:   %112s\n", "My dear, I regret nothing. Except dying.");

	// ft_printf("3String prec:   %-+12.8s\n", "My dear, I regret nothing. Except dying.");
	// printf("4String prec:   %-+12.8s\n", "My dear, I regret nothing. Except dying.");

	// ft_printf("1Trying out %hhd\n", 356);
	// printf("2Trying out %hhd\n", 356);

	// ft_printf("1Trying out %hho\n", 356);
	// printf("2Trying out %hho\n", 356);

	/*printf("char:%++-50c, %  #-3Ac, %---+54c: str:%+-10.15s, %----+++++-+s: x: % #0-10.11x, %  ++-15.5x: \n
	X: % #0-10.11X, %15.5X: u: %+ - 10.10u, %        -u: d: %++10lld %-10.10hd", '\0', '\200', 'a', "a", 
	"Hello World", 54, 3, 666, 999, -999, 999, 9999999999, 300);*/

	//ft_printf("char:%++-50c, %#-3Ac, %---+54c: str:%+-10.15s, %----+++++-+s: x: % #0-10.11x, %  ++-15.5x: \nX: % #0-10.11X, %  ++-15.5X: u: %+ - 10.10u, %        -u: d: %++10lld %-10.10hd", '\0', '\200', 'a', "a", "Hello World", 54, 3, 666, 999, -999, 999, 9999999999, 300);
	// double i = 9.999999;
	// 	printf("\n");
	// while (i > 9.99999)
	// {
	// 	printf("I == %.7f\n", i);
	// 	ft_printf("MINE: Pros:%%, Point:%p, Char:%c, Str:%s, I:%i, IN:%i, D:%d, DN:%d, U:%u, UN:%u, x:%x, XN:%X, O:%o NO:%o, f:%f, FN:%f.\n",
	// 	&i, '%', "You", 3, -3, 60, -60, 666, -666, 999, -999, 113, -113, i * 3, i);
	// 	printf("REAL: Pros:%%, Point:%p, Char:%c, Str:%s, I:%i, IN:%i, D:%d, DN:%d, U:%u, UN:%u, x:%x, XN:%X, O:%o NO:%o, f:%f, FN:%f.\n",
	// 	&i, '%', "You", 3, -3, 60, -60, 666, -666, 999, -999, 113, -113, i * 3, i);
	// 	i -= 0.0000001;
	// 	printf("\n");
	// }
	return (0);
}
