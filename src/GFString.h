#ifndef __GF_STRING__
#define __GF_STRING__

#include <stdio.h>
#define MAX_SIZE 1024
class GFString {
private:
	char text[1024];	
	inline int strlen(const char *str) {
		int i=0;
		if (!str) return 0;
		while (str[i]!='\0') i++; 
		return i;		
	}
	inline void strcpy(char *dest, const char *ori) {
		if (!ori) return;
		if (!dest) return;
		for (int i=0; ori[i]!='\0'; i++) {
			dest[i]=ori[i];
		}
		dest[i]='\0';
	}
	inline void strcat(char *dest, const char *ori) {
		if (!ori) return;
		if (!dest) return;
		int offset = strlen(dest);
		for (int i=offset; ori[i-offset]!='\0'; i++) {
			dest[i]=ori[i - offset];
		}
		dest[i]='\0';
	}
protected:
public:
	GFString() {
		//text = new char[1];		
		text[0]='\0';
	}
	GFString(const char *newstr) {				
		//text = new char[1];		
		text[0]='\0';
		Replace(newstr);
	}
	GFString(GFString &other) {		
		//text = new char[1];		
		text[0]='\0';
		Replace(other.text);		
	}
	~GFString() {}
	inline int Length() { return strlen(text); }
	inline const char *GetData() { 		
		return (const char *)text; }
	inline void Replace(const char *newstr) {
		/*delete text;
		int size=strlen(newstr)+1;
		text = new char[size];
		strcpy(text, newstr);*/

		strcpy(text, newstr);
		//printf("string set to '%s'\n", text);
	}
	inline void Append(const char *str) {
		/*int size = strlen(str) + strlen(text)+1;
		char *newstr = new char[size];
		strcpy(newstr, text);
		strcat(newstr, str);
		delete text;
		text = new char[size];
		strcpy(text, newstr);
		*/
		strcat(text, str);
	}	
};

#endif //__GF_STRING__
