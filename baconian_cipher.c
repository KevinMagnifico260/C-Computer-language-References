
/*
 *	Filename : baconian_cipher.c
 *	Author & Copyright (c) : Kevin C. Magnifico
 *	Date created : 2021-12-10
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
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MIT_LICENSE "MIT License\n" \
                    "\n" \
                    "Copyright (c) 2021 Kevin C. Magnifico\n" \
                    "\n" \
                    "Permission is hereby granted, free of charge, to any person obtaining a copy\n" \
                    "of this software and associated documentation files (the \"Software\"), to deal\n" \
                    "in the Software without restriction, including without limitation the rights\n" \
                    "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n" \
                    "copies of the Software, and to permit persons to whom the Software is\n" \
                    "furnished to do so, subject to the following conditions:\n" \
                    "\n" \
                    "The above copyright notice and this permission notice shall be included in all\n" \
                    "copies or substantial portions of the Software.\n" \
                    "\n" \
                    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n" \
                    "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n" \
                    "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n" \
                    "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n" \
                    "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n" \
                    "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n" \
                    "SOFTWARE.\n"


#define BACONIAN_CIPHER 26 // You can change the value either 24 or 26 baconian ciphering

#define NULL_OFFSET 1
#define BACONIAN_SIZE 5

#if BACONIAN_CIPHER == 24
	#define A "AAAAA"
	#define B "AAAAB"
	#define C "AAABA"
	#define D "AAABB"
	#define E "AABAA"
	#define F "AABAB"
	#define G "AABBA"
	#define H "AABBB"
	// -------- Same Value --------
	#define I "ABAAA"
	#define J "ABAAA"
	// ----------------------------
	#define K "ABAAB"
	#define L "ABABA"
	#define M "ABABB"
	#define N "ABBAA"
	#define O "ABBAB"
	#define P "ABBBA"
	#define Q "ABBBB"
	#define R "BAAAA"
	#define S "BAAAB"
	#define T "BAABA"
	// -------- Same Value --------
	#define U "BAABB"
	#define V "BAABB"
	// ----------------------------
	#define W "BABAA"
	#define X "BABAB"
	#define Y "BABBA"
	#define Z "BABBB"
#elif BACONIAN_CIPHER == 26
	#define A "AAAAA"
	#define B "AAAAB"
	#define C "AAABA"
	#define D "AAABB"
	#define E "AABAA"
	#define F "AABAB"
	#define G "AABBA"
	#define H "AABBB"
	#define I "ABAAA"
	#define J "ABAAB"
	#define K "ABABA"
	#define L "ABABB"
	#define M "ABBAA"
	#define N "ABBAB"
	#define O "ABBBA"
	#define P "ABBBB"
	#define Q "BAAAA"
	#define R "BAAAB"
	#define S "BAABA"
	#define T "BAABB"
	#define U "BABAA"
	#define V "BABAB"
	#define W "BABBA"
	#define X "BABBB"
	#define Y "BBAAA"
	#define Z "BBAAB"
#else
	#error "Undefined baconian value"
#endif

static char * baconian_cipher_buffer_encryption(char value, bool all_upper_case);
static char baconian_cipher_buffer_decryption(char * value, bool is_upper_case);
static char ** baconian_cipher_encrypt(char * value, bool all_upper_case);
static char * baconian_cipher_decrypt(char ** value_arr, unsigned long int value_arr_len);

char * baconian_cipher_buffer_encryption(char value, bool all_upper_case)
{
	const unsigned int result_len = (BACONIAN_SIZE + NULL_OFFSET);
	char * result = (char *)malloc((sizeof(char) * result_len));
	char tmp_value = tolower(value);
	switch (tmp_value)
	{
		case 'a':
			strncpy(result, A, result_len);
			break;
		case 'b':
			strncpy(result, B, result_len);
			break;
		case 'c':
			strncpy(result, C, result_len);
			break;
		case 'd':
			strncpy(result, D, result_len);
			break;
		case 'e':
			strncpy(result, E, result_len);
			break;
		case 'f':
			strncpy(result, F, result_len);
			break;
		case 'g':
			strncpy(result, G, result_len);
			break;
		case 'h':
			strncpy(result, H, result_len);
			break;
		case 'i':
			strncpy(result, I, result_len);
			break;
		case 'j':
			strncpy(result, J, result_len);
			break;
		case 'k':
			strncpy(result, K, result_len);
			break;
		case 'l':
			strncpy(result, L, result_len);
			break;
		case 'm':
			strncpy(result, M, result_len);
			break;
		case 'n':
			strncpy(result, N, result_len);
			break;
		case 'o':
			strncpy(result, O, result_len);
			break;
		case 'p':
			strncpy(result, P, result_len);
			break;
		case 'q':
			strncpy(result, Q, result_len);
			break;
		case 'r':
			strncpy(result, R, result_len);
			break;
		case 's':
			strncpy(result, S, result_len);
			break;
		case 't':
			strncpy(result, T, result_len);
			break;
		case 'u':
			strncpy(result, U, result_len);
			break;
		case 'v':
			strncpy(result, V, result_len);
			break;
		case 'w':
			strncpy(result, W, result_len);
			break;
		case 'x':
			strncpy(result, X, result_len);
			break;
		case 'y':
			strncpy(result, Y, result_len);
			break;
		case 'z':
			strncpy(result, Z, result_len);
			break;
		default:
			strncpy(result, (char[2]){ value, '\0' }, 2);
			break;
	}
	if (!all_upper_case && islower(value))
	{
		for (unsigned int i = 0; i < result_len; i++)
		{
			*(result + i) = tolower(*(result + i));
		}
	}
	return result;
}

char baconian_cipher_buffer_decryption(char * value, bool is_upper_case)
{
	char result;
	for (unsigned long int i = 0; i < strlen(value); i++)  
	{
		*(value + i) = toupper(*(value + i));
	}
	if (strncmp(value, A, BACONIAN_SIZE) == 0) { result = 'a'; }
	else if (strncmp(value, B, BACONIAN_SIZE) == 0) { result = 'b'; }
	else if (strncmp(value, C, BACONIAN_SIZE) == 0) { result = 'c'; }
	else if (strncmp(value, D, BACONIAN_SIZE) == 0) { result = 'd'; }
	else if (strncmp(value, E, BACONIAN_SIZE) == 0) { result = 'e'; }
	else if (strncmp(value, F, BACONIAN_SIZE) == 0) { result = 'f'; }
	else if (strncmp(value, G, BACONIAN_SIZE) == 0) { result = 'g'; }
	else if (strncmp(value, H, BACONIAN_SIZE) == 0) { result = 'h'; }
	else if (strncmp(value, I, BACONIAN_SIZE) == 0) { result = 'i'; }
	else if (strncmp(value, J, BACONIAN_SIZE) == 0) { result = 'j'; }
	else if (strncmp(value, K, BACONIAN_SIZE) == 0) { result = 'k'; }
	else if (strncmp(value, L, BACONIAN_SIZE) == 0) { result = 'l'; }
	else if (strncmp(value, M, BACONIAN_SIZE) == 0) { result = 'm'; }
	else if (strncmp(value, N, BACONIAN_SIZE) == 0) { result = 'n'; }
	else if (strncmp(value, O, BACONIAN_SIZE) == 0) { result = 'o'; }
	else if (strncmp(value, P, BACONIAN_SIZE) == 0) { result = 'p'; }
	else if (strncmp(value, Q, BACONIAN_SIZE) == 0) { result = 'q'; }
	else if (strncmp(value, R, BACONIAN_SIZE) == 0) { result = 'r'; }
	else if (strncmp(value, S, BACONIAN_SIZE) == 0) { result = 's'; }
	else if (strncmp(value, T, BACONIAN_SIZE) == 0) { result = 't'; }
	else if (strncmp(value, U, BACONIAN_SIZE) == 0) { result = 'u'; }
	else if (strncmp(value, V, BACONIAN_SIZE) == 0) { result = 'v'; }
	else if (strncmp(value, W, BACONIAN_SIZE) == 0) { result = 'w'; }
	else if (strncmp(value, X, BACONIAN_SIZE) == 0) { result = 'x'; }
	else if (strncmp(value, Y, BACONIAN_SIZE) == 0) { result = 'y'; }
	else if (strncmp(value, Z, BACONIAN_SIZE) == 0) { result = 'z'; }
	else { result = value[0]; }
	return (is_upper_case) ? toupper(result) : tolower(result);
}

char ** baconian_cipher_encrypt(char * value, bool all_upper_case)
{
	unsigned long int val_len = strlen(value);
	char ** result = (char **)malloc((sizeof(char *) * val_len));
	for (unsigned long int i = 0; i < val_len; i++)
	{
		result[i] = baconian_cipher_buffer_encryption(value[i], all_upper_case);
	}
	return result;
}

char * baconian_cipher_decrypt(char ** value_arr, unsigned long int value_arr_len)
{
	char * result = (char *)malloc((sizeof(char) * value_arr_len) + NULL_OFFSET);
	for (unsigned long int i = 0; i < value_arr_len; i++)
	{
		bool is_upper_case = isupper(value_arr[i][0]);
		*(result + i) = baconian_cipher_buffer_decryption(value_arr[i], is_upper_case);
	}
	*(result + value_arr_len) = '\0';
	return result;
}

int main()
{
	char * name = "Kevin"; //MIT_LICENSE;
	
	unsigned long int name_len = strlen(name);
	
	// Encrypt the name
	char ** e_result = baconian_cipher_encrypt(name, false);
	
	for (unsigned long int i = 0; i < name_len; i++)
	{
		printf("%s ", e_result[i]);
	}
	
	printf("\n------------------------------------------------\n");
	
	// Decrypt the encrypted name
	char * d_result = baconian_cipher_decrypt(e_result, name_len);
	
	printf("%s \n", d_result);
	
	// Deallocate the encrypted result per index from heap memory
	for (unsigned long int i = 0; i < name_len; i++)
	{
		free(e_result[i]);
		e_result[i] = NULL;
	}
	
	// Deallocate the encrypted result from heap memory
	free(e_result);
	e_result = NULL;
	
	// Deallocate the decrypted result from heap memory
	free(d_result);
	d_result = NULL;
	
	return 0;
}

