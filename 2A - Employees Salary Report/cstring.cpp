/*
Name:          Mohit Kishorbhai Sheladiya
Student ID:    117979203
Student Email: mksheladiya@myseneca.ca
Date:          21/01/27
*/

#include <iostream>
#include "cstring.h"

namespace sdds {

	void strCpy(char* des, const char* src) {

		while ((*des++ = *src++) != '\0');

	}

	void strnCpy(char* des, const char* src, int len) {

		char* a = des;

		while (len) {
			if ((*a = *src) != 0) {
				src++;
			}
			a++;
			len--;
		}

	}

	int strCmp(const char* s1, const char* s2) {

		unsigned char char1, char2;

		while (1) {

			char1 = *s1++;
			char2 = *s2++;

			if (char1 != char2) {
				return char1 < char2 ? -1 : 1;
			}
			if (!char1) {
				break;
			}
		}
		return 0;
	}

	int strnCmp(const char* s1, const char* s2, int len) {

		unsigned char char1, char2;

		while (len) {

			char1 = *s1++;
			char2 = *s2++;

			if (char1 != char2) {
				return char1 < char2 ? -1 : 1;
			}
			if (!char1) {
				break;
			}
			len--;
		}
		return 0;
	}

	int strLen(const char* s) {

		const char* s1;
		char s2;

		for (s1 = s; *s1 != '\0'; ++s1);
		s2 = s1 - s;

		return s2;
	}

	int match(const char* str1, const char* str2) // Not in the question but for creating strStr function
	{
		char a;

		while (*str1 && *str2)
		{
			if (*str1 != *str2) {
				return 0;
			}
			str1++;
			str2++;
		}

		a = (*str2 == '\0');
		return a;
	}

	const char* strStr(const char* str1, const char* str2) {

		while (*str1 != '\0')
		{
			if ((*str1 == *str2) && match(str1, str2)) {
				return str1;
			}
			str1++;
		}

		return 0;
	}

	void strCat(char* des, const char* src) {

		while (*des) {
			des++;
		}
		while ((*des++ = *src++) != '\0');
	}
}