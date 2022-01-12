
/*
 *	Filename : function_pointer_with_vardiac.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-12-17
 *	Written in : C
 *
 *	---------------------------------------------------------------------------------
 *
 *	MIT License
 *
 *	Copyright (c) 2021 Kevin C. Magnifico
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static double add_operation(int num_length, ...);
static double sub_operation(int num_length, ...);
static double mul_operation(int num_length, ...);
static double div_operation(int num_length, ...);

static double arithmetic_operation(double (*operation)(int num_length, ...), int num_len, ...);

double add_operation(int num_length, ...)
{
	double result = 0.00;
	va_list ap;
	va_start(ap, num_length);
	for (unsigned int i = 0; i < num_length; i++)
	{
		if (i == 0) 
		{ 
			result = va_arg(ap, double);
		}
		else
		{ 
			result += va_arg(ap, double); 
		}
	}
	va_end(ap);
	return result;
}

double sub_operation(int num_length, ...)
{
	double result = 0.00;
	va_list ap;
	va_start(ap, num_length);
	for (unsigned int i = 0; i < num_length; i++)
	{
		if (i == 0) 
		{ 
			result = va_arg(ap, double);
		}
		else
		{ 
			result -= va_arg(ap, double); 
		}
	}
	va_end(ap);
	return result;	
}

double mul_operation(int num_length, ...)
{
	double result = 0.00;
	va_list ap;
	va_start(ap, num_length);
	for (unsigned int i = 0; i < num_length; i++)
	{
		if (i == 0) 
		{ 
			result = va_arg(ap, double);
		}
		else
		{ 
			result *= va_arg(ap, double); 
		}
	}
	va_end(ap);
	return result;
}

double div_operation(int num_length, ...)
{
	double result = 0.00;
	va_list ap;
	va_start(ap, num_length);
	for (unsigned int i = 0; i < num_length; i++)
	{
		if (i == 0)
		{
			result = va_arg(ap, double);
		}
		else
		{
			result /= va_arg(ap, double);
		}
	}
	va_end(ap);
	return result;
}

double arithmetic_operation(double (*operation)(int num_length, ...), int num_len, ...)
{
	double result;
	va_list ap;
	va_start(ap, num_len);
	result = operation(num_len, va_arg(ap, double));
	va_end(ap);
	return result;
}

int main()
{
	double result;
	
	result = arithmetic_operation(add_operation, 2, 5.0, 3.0);
	printf("Result add = %.2lf\n", result);

	result = arithmetic_operation(sub_operation, 2, 5.0, 3.0);
	printf("Result sub = %.2lf\n", result);

	result = arithmetic_operation(mul_operation, 2, 5.0, 3.0);
	printf("Result mul = %.2lf\n", result);
	
	result = arithmetic_operation(div_operation, 2, 5.0, 3.0);
	printf("Result div = %.2lf\n", result);

	return 0;
}
