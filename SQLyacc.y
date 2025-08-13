%{
	#define YYINITDEPTH 2000
    #include<stdio.h>
    #include<string.h>
    #include <cctype>
	#include <string>
	#include <vector>
	#include <cstdlib>
	#include <fstream>
    #include "structT.h"
    #include "LLHSQL.h"
    using namespace std;
   
    extern int yylex(void);
    int yyerror(char * msg);
%}

%union{
    string* str;
    pair<string, string>* sps;
    vector<string>* names;
    SelectedFields* sf_var;
    CreateFieldsDef* cfd_var;
    vector<SelectedFields>* sf_list;
    vector<CreateFieldsDef>* cfd_list;
    CreateStruct* cs_var;
    Conditions* cons_var;
    vector<Conditions*>* setting_list;
    vector<SelectedTables>* st_list;
    SelectStruct* ss_var;
    InsertStruct* is_var;
    DeleteStruct* ds_var;
    UpdateStruct* us_var;
}

%token <str> NUM STRING ID
%token SELECT FROM WHERE INSERT INTO DELETE UPDATE SET TYPEINT TYPECHAR LBR RBR SEM COMMA USE DROP SHOW TABLES DATABASES TABLE DATABASE NEWLINE CREATE STAR DOT VALUES EXIT

%left OR
%left AND
%left LT LE GT GE EQ NEQ ASSIGN

%type <sf_var> SELECT_FIELD
%type <cfd_var> CREATE_FIELD
%type <sf_list> SELECT_FIELDS
%type <cfd_list> CREATE_FIELDS
%type <names> INSERT_FIELDS INSERT_VALUES
%type <cs_var> SQL_CREATE
%type <cons_var> CONS SETTING
%type <setting_list> SETTINGS
%type <st_list> SELECTED_TABLES
%type <ss_var> SQL_SELECT
%type <is_var> SQL_INSERT
%type <ds_var> SQL_DELETE
%type <us_var> SQL_UPDATE
%type <sps> TABLE_FIELD

%%

SQL_CONTENT:
    STMT SEM NEWLINE SQL_CONTENT
    | STMT SEM NEWLINE
    /* | error SEM NEWLINE SQL_CONTENT */
    | NEWLINE
    ;

STMT:
    SQL_CREATE {}
    | SQL_SELECT {}
    | SQL_INSERT {}
    | SQL_UPDATE {}
    | SQL_DELETE {}
    | DB_CREATE
    | DB_USE
    | DB_DROP
    | TABLE_DROP
    | DB_SHOW
    | TABLE_SHOW
    | EXIT {}
    ;

SQL_CREATE:
    CREATE TABLE ID LBR CREATE_FIELDS RBR {}
    ;

CREATE_FIELDS:
    CREATE_FIELDS COMMA CREATE_FIELD {}
    | CREATE_FIELD {}
    ;

CREATE_FIELD:
    ID TYPECHAR LBR NUM RBR {}
    | ID TYPEINT{}
    ;

/* DTYPE:
    TYPEINT {$$ = INT;}
    | TYPECHAR {$$ = CHAR;}
    ; */

SQL_SELECT:
    SELECT SELECT_FIELDS FROM SELECTED_TABLES WHERE CONS {}
    | SELECT STAR FROM SELECTED_TABLES WHERE CONS {}
    | SELECT SELECT_FIELDS FROM SELECTED_TABLES {}
    | SELECT STAR FROM SELECTED_TABLES {}
    ;

SELECT_FIELDS:
    SELECT_FIELDS COMMA SELECT_FIELD {}
    | SELECT_FIELD {}
    ;

SELECT_FIELD:
    ID {}
    | ID DOT ID {}
    ;

SELECTED_TABLES:
    SELECTED_TABLES COMMA ID {}
    | ID {}
    ;



CONS:
    CONS OR CONS {}
    | CONS AND CONS {}
    | TABLE_FIELD LT NUM {}
    | TABLE_FIELD GT NUM {}
    | TABLE_FIELD LE NUM {}
    | TABLE_FIELD GE NUM {}
    | TABLE_FIELD ASSIGN NUM {}
    | TABLE_FIELD NEQ NUM { }
    | TABLE_FIELD LT STRING {}
    | TABLE_FIELD GT STRING {}
    | TABLE_FIELD LE STRING {}
    | TABLE_FIELD GE STRING {}
    | TABLE_FIELD ASSIGN STRING {}
    | TABLE_FIELD NEQ STRING {}
    | LBR CONS RBR {}
    ;

TABLE_FIELD:
    ID DOT ID {}
    | ID {}
    ;

SQL_INSERT:
    INSERT INTO ID LBR INSERT_FIELDS RBR VALUES LBR INSERT_VALUES RBR {}
    ;

INSERT_FIELDS:
    INSERT_FIELDS COMMA ID {}
    | ID {}
    ;

INSERT_VALUES:
    INSERT_VALUES COMMA NUM {}
    | INSERT_VALUES COMMA STRING {}
    | NUM {}
    | STRING {}
    ;


SQL_UPDATE:
    UPDATE ID SET SETTINGS WHERE CONS {}
    | UPDATE ID SET SETTINGS {}
    ;

SETTINGS:
    SETTINGS COMMA SETTING {}
    | SETTING {}
    ;

SETTING:
    ID ASSIGN NUM {}
    | ID ASSIGN STRING {}
    ;

SQL_DELETE:
    DELETE FROM ID WHERE CONS {}
    ;

DB_CREATE:
    CREATE DATABASE ID {}
    ;

DB_USE:
    USE ID {}
    ;

DB_DROP:
    DROP DATABASE ID {}
    ;

TABLE_DROP:
    DROP TABLE ID {}
    ;

DB_SHOW:
    SHOW DATABASES {}
    ;

TABLE_SHOW:
    SHOW TABLES {}

%%
int main()
{
    //test();
    yyparse();
    return 0;
}

int yyerror(char * msg)
{
	printf("yyerror");
	return 1;
}