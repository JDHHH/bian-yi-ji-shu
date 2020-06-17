%{
#include <stdlib.h>
#include <stdio.h>
#define NUM 201713001
int num_chars = 0;
int num_ids=0;
int num_numbers=0;
%}
delim [ ]
letter [A-Za-z]
digit [0-9]
number {digit}+
id {letter}+

%%
{number} {int r=atoi(yytext);if(r==NUM) printf("Ï²ÑóÑó");
else printf("%s ",yytext);
num_chars+=yyleng;num_numbers+=strlen(yytext);}
{delim} {printf(" ");num_chars+=yyleng;}
{id} {printf("%s ",yytext);++num_ids;num_chars+=yyleng;}



%%
main()
{
	yylex();

	printf("\n# of ids = %d ,# of chars = %d ,# of numbers = %d",num_ids , num_chars , num_numbers);
}