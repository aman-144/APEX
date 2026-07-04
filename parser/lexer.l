%{
#include<stdio.h>
%}

%%
"var"     { printf("KEYWORD: var\n"); }
[0-9]+    { printf("NUMBER: %s\n", yytext); }
[a-zA-Z]+ { printf("IDENTIFIER: %s\n", yytext); }
%%

int main(){
    yylex();
    return 0;
}