#include<iostream>
#include "markup.h"
using namespace std;
int main()
{
	cout<<markup::convert("!!!qwq!!!")<<endl;//shining word "qwq"
	cout<<markup::convert("!!!qwq!!!","\033[31m")<<endl;//red shining word "qwq"
}
