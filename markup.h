#ifndef _MARKUP_H_
#define _MARKUP_H_
#include<string>
#define CONTROL_NULL "\033[0m"+default_style
#define CONTROL_LINE "\033[4m"
#define CONTROL_BOLD "\033[1m"
#define CONTROL_SHINE "\033[5m"
#define CONTROL_ITALIC "\033[3m"
#define CONTROL_DELETE "\033[9m"
namespace markup
{
	std::string convert(std::string str,std::string default_style="")
	{
		std::string dealtmpp="";
		bool in_line=0,in_bold=0,in_shine=0,in_italic=0,in_delete=0;
		for(unsigned i=0;i<str.size();i++)
		{
			bool mark=0;
				 if(str[i]=='/' && str[i+1]=='/' && str[i+2]=='/')
				mark=1,in_italic^=1,i+=2;
			else if(str[i]=='*' && str[i+1]=='*' && str[i+2]=='*')
				mark=1,in_bold  ^=1,i+=2;
			else if(str[i]=='_' && str[i+1]=='_' && str[i+2]=='_')
				mark=1,in_line  ^=1,i+=2;
			else if(str[i]=='-' && str[i+1]=='-' && str[i+2]=='-')
				mark=1,in_delete^=1,i+=2;
			else if(str[i]=='!' && str[i+1]=='!' && str[i+2]=='!')
				mark=1,in_shine ^=1,i+=2;
			else	dealtmpp+=str[i];
			if(!mark)	continue;
			dealtmpp+=CONTROL_NULL;
			if(in_shine )	dealtmpp+=CONTROL_SHINE ;
			if(in_bold  )	dealtmpp+=CONTROL_BOLD  ;
			if(in_italic)	dealtmpp+=CONTROL_ITALIC;
			if(in_line  )	dealtmpp+=CONTROL_LINE  ;
			if(in_delete)	dealtmpp+=CONTROL_DELETE;
		}
		if(dealtmpp[dealtmpp.size()-1]!='\n')	dealtmpp+="\n";
		if(in_line || in_bold || in_shine || in_italic || in_delete)
			dealtmpp+=CONTROL_NULL;
		dealtmpp[dealtmpp.size()]=0;
		return dealtmpp;
	}
}
#undef CONTROL_NULL
#undef CONTROL_LINE
#undef CONTROL_BOLD
#undef CONTROL_SHINE
#undef CONTROL_ITALIC
#undef CONTROL_DELETE
#endif
