
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INT_LITERAL = 259,
     FLOAT_LITERAL = 260,
     STR_LITERAL = 261,
     FUNCTION = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     BREAK = 267,
     CONTINUE = 268,
     WITH = 269,
     VAR = 270,
     NEW = 271,
     DELETE = 272,
     THIS = 273,
     TRUE = 274,
     FALSE = 275,
     _NULL = 276,
     IN = 277,
     RETURN = 278,
     COMMA = 279,
     SEMI = 280,
     LBRACE = 281,
     RBRACE = 282,
     LPAREN = 283,
     RPAREN = 284,
     EQUALS = 285,
     ASSIGN = 286,
     QMARK = 287,
     COLON = 288,
     LOGICAL_OR = 289,
     LOGICAL_AND = 290,
     BITWISE_OR = 291,
     BITWISE_XOR = 292,
     BITWISE_AND = 293,
     DOT = 294,
     LBRACKET = 295,
     RBRACKET = 296,
     MUL = 297,
     DIV = 298,
     PLUS = 299,
     MINUS = 300,
     LT = 301,
     LTE = 302,
     GT = 303,
     GTE = 304,
     STRICT_EQUALS = 305,
     SLEFT = 306,
     SRIGHT = 307,
     INC = 308,
     DEC = 309,
     MULT = 310
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT_LITERAL 259
#define FLOAT_LITERAL 260
#define STR_LITERAL 261
#define FUNCTION 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define FOR 266
#define BREAK 267
#define CONTINUE 268
#define WITH 269
#define VAR 270
#define NEW 271
#define DELETE 272
#define THIS 273
#define TRUE 274
#define FALSE 275
#define _NULL 276
#define IN 277
#define RETURN 278
#define COMMA 279
#define SEMI 280
#define LBRACE 281
#define RBRACE 282
#define LPAREN 283
#define RPAREN 284
#define EQUALS 285
#define ASSIGN 286
#define QMARK 287
#define COLON 288
#define LOGICAL_OR 289
#define LOGICAL_AND 290
#define BITWISE_OR 291
#define BITWISE_XOR 292
#define BITWISE_AND 293
#define DOT 294
#define LBRACKET 295
#define RBRACKET 296
#define MUL 297
#define DIV 298
#define PLUS 299
#define MINUS 300
#define LT 301
#define LTE 302
#define GT 303
#define GTE 304
#define STRICT_EQUALS 305
#define SLEFT 306
#define SRIGHT 307
#define INC 308
#define DEC 309
#define MULT 310




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "C:/dev/jsrtl/res/javascript/parser.grammar"

  int		int_val;
  float     float_val;
  string*	str_val;
  ast::ASTNode* node_val;
  ast::Statement* statement;
  ast::StatementList* statements;
  ast::Expression* expression;
  ast::Variable* variable;



/* Line 1676 of yacc.c  */
#line 175 "C:/dev/jsrtl/src/javascript/parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


