/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SQLYACC_TAB_H_INCLUDED
# define YY_YY_SQLYACC_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     STRING = 259,
     ID = 260,
     SELECT = 261,
     FROM = 262,
     WHERE = 263,
     INSERT = 264,
     INTO = 265,
     DELETE = 266,
     UPDATE = 267,
     SET = 268,
     TYPEINT = 269,
     TYPECHAR = 270,
     LBR = 271,
     RBR = 272,
     SEM = 273,
     COMMA = 274,
     USE = 275,
     DROP = 276,
     SHOW = 277,
     TABLES = 278,
     DATABASES = 279,
     TABLE = 280,
     DATABASE = 281,
     NEWLINE = 282,
     CREATE = 283,
     STAR = 284,
     DOT = 285,
     VALUES = 286,
     EXIT = 287,
     OR = 288,
     AND = 289,
     ASSIGN = 290,
     NEQ = 291,
     EQ = 292,
     GE = 293,
     GT = 294,
     LE = 295,
     LT = 296
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 18 "SQLyacc.y"

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


/* Line 2058 of yacc.c  */
#line 117 "SQLyacc.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SQLYACC_TAB_H_INCLUDED  */
