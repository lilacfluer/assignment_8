#include <iostream>
#include <cctype>
#include <cstring>
#include "obstring.h"
#include <cassert>
using namespace std;

//using namespace main_savitch_4;                                               

namespace main_savitch_4 {

	obstring::obstring(const char str[]) {		
		current_length = strlen(str);
		allocated = current_length + 1;
		sequence = new char[allocated];
		strncpy(sequence, str, current_length);		
	}

	obstring::obstring(const obstring& source) {
		char  *new_data;
		reserve(source.current_length);
		new_data = new char[source.allocated];
		delete[]sequence;
		sequence = new_data;
		allocated = source.allocated;
		current_length = source.current_length;
		copy(source.sequence, source.sequence + current_length, sequence);
	}

	obstring::~obstring() {
		delete[] sequence;
	}

	void obstring::operator +=(const obstring& addend) {
		if (current_length + addend.current_length > allocated) {
			reserve(current_length + addend.current_length);
		}	
		copy(addend.sequence, addend.sequence + addend.allocated, sequence + current_length);
		current_length += addend.current_length;
	}

	void obstring::operator +=(const char addend[]) {
		int c = 0;
		if (current_length >= allocated) {
			while (addend != '\0') {
				c++;
			}
			reserve(current_length + c);
			//      while(addend != '\0'){                                            
			//        for(int i = current_length-c; i<current_length; i++)            
			//          sequence[current_length]=c;                                   
			// }                                                                      
		}

		++current_length;
	}

	void obstring::operator +=(char addend) {
		if (current_length == allocated) {
			reserve(current_length + 1);
		}
		sequence[current_length] = addend;
		++current_length;
	}

	void obstring::reserve(size_t n) {
		char *larger_array;
		if (n == allocated) return;
		if (n < current_length)	n = current_length; // cant allocate less than we are using               

		larger_array = new char[n];
		copy(sequence, sequence + current_length, larger_array);
		delete[] sequence;
		sequence = larger_array;
		allocated = n;
	}

	void obstring::operator =(const obstring& source) {
		char  *new_data;
		reserve(source.current_length);
		new_data = new char[source.allocated];
		delete[]sequence;
		sequence = new_data;
		allocated = source.allocated;
		current_length = source.current_length;
		copy(source.sequence, source.sequence + current_length, sequence);
	}

	char obstring::operator[](size_t position) const {
		return sequence[position];
	}

	ostream& operator <<(ostream& outs, const obstring& source) {
		for (int i = 0; i < source.current_length; i++) {
			outs << source.sequence[i];
		}
		return outs;
	}

	bool operator ==(const obstring& s1, const obstring& s2) {
		return (strcmp(s1.sequence, s2.sequence) == 0);
	}

	bool operator !=(const obstring& s1, const obstring& s2) {
		return (strcmp(s1.sequence, s2.sequence) != 0);
	}

	bool operator >=(const obstring& s1, const obstring& s2) {
		return (strcmp(s1.sequence, s2.sequence) >= 0);
	}

	bool operator <=(const obstring& s1, const obstring& s2) {
		return (strcmp(s1.sequence, s2.sequence) <= 0);
	}

	bool operator > (const obstring& s1, const obstring& s2) {
		return (strcmp(s1.sequence, s2.sequence) > 0);
	}

	bool operator < (const obstring& s1, const obstring& s2) {
		return (strcmp(s1.sequence, s2.sequence) < 0);
	}

	obstring operator +(const obstring& s1, const obstring& s2) {
		obstring result;
		result += s1;
		result += s2;
		return result;
	}

	istream& operator >>(istream& ins, obstring& target) {
		char c;
		bool cap = true;
		while (ins && isspace(ins.peek())) {
			ins.ignore();
		}

		while (ins && (ins.peek() != '\n')) {
			ins >> c;
			target += c;
		}

		/*
		for(unsigned int i = 0; i<= target.length();i++){
		  if(isalpha(target[i] && cap == true)){
			  target[i] = toupper(target[i]);
			  cap = false;
			}
	     }
		*/
		return ins;
	}

	void getline(std::iostream& ins, obstring& target, char delimiter) {
		char c;
		while (ins && ((ins.peek()) != delimiter)) {
			ins >> c;
			target += c;
		}
	}
}
