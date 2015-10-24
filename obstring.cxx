#include <iostream>
#include <cstdlib>
#include "obstring.h"

using namespace std;
using namespace main_savitch_4;

obstring::obstring(const char str[ ]){
    current_length = strlen(str);
    allocated = current_length + 1;
    sequence = new char[allocated];
    strcpy(sequence, str);
    
    
}
obstring::obstring(const obstring& source){
    sequence = new char[source.allocated];
    allocated = source.allocated;
    current_length = source.current_length;
}
obstring::~obstring( ){
    delete [ ] sequence;
    
}
void obstring::operator +=(const obstring& addend){
    
}
void obstring::operator +=(const char addened [ ]){
    
}
void obstring::operator +=(char addened){
    
}
void obstring::reserve(size_t n){
    char *larger_array;
    
    if(n == allocated)
        return;
    if(n < current_length)
        n = current_length; // cant allocate less than we are using
    
    larger_array = new char[n];
    copy(sequence, sequence + current_length, larger_array);
    obstring::~obstring();
    sequence = larger_array;
    allocated = n;
}
void obstring::operator =(const obstring& source){
    
}
char obstring::operator[](size_t position) const{
    return sequence[position];
}
ostream& operator <<(std::ostream& outs, const obstring& source){
    for (int i = 0; i < ; <#increment#>) {
        <#statements#>
    }
    return outs;
}
iostream& operator >>(std::iostream& ins, obstring& target){
    char c;
    while(ins && isspace(ins.peek()))
        ins.ignore();
    while(ins && isspace((ins.peek())) != '\0'){
        ins >> c;
        target +=c;
    }
    return ins;
}
void getline(std::iostream& ins, obstring& target, char delimiter){
    char c;
    while(ins && ((ins.peek()) != delimiter)){
        ins >> c;
        target += c;
    }
 }
