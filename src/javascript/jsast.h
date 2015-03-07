#ifndef _jsast_h
#define _jsast_h

#include <string>
#include <vector>
#include <boost/optional.hpp>
#include <boost/none.hpp>

using namespace std;

namespace ast {
    class ASTNode {
    public:
        virtual void execute() {
        }
    };

    class Statement : public ASTNode {
    };



    class Expression : public ASTNode, public Statement {
    };

    class IfStatement : public Statement {
    private:
        Expression *expression;
        Statement *ifStatement;
        Statement *elseStatement;
    public:

        IfStatement(Expression *expression, Statement *statement)
                : expression(expression), ifStatement(statement), elseStatement(nullptr) {
        }

        IfStatement(Expression *expression, Statement *statement, Statement *elseStatement)
                : expression(expression), ifStatement(statement), elseStatement(elseStatement) {
        }

        virtual void execute() {
            std::cout << "if:";

            if (ifStatement != nullptr) {
                ifStatement->execute();
            }

            if (elseStatement != nullptr) {
                elseStatement->execute();
            }
        }
    };

    class WhileStatement : public Statement {
    private:
        Expression* condition;
        Statement* statement;

    public:
        WhileStatement(Expression *condition, Statement *statement) : condition(condition), statement(statement) {
        }
    };

    class BreakStatement : public Statement {};
    class ContinueStatement : public Statement {};
    class ReturnStatement : public Statement {
    private:
        Expression* returnExpression;

    public:
        ReturnStatement(Expression *returnExpression) : returnExpression(returnExpression) {
        }
    };

    class EmptyStatement : public Statement {
    };

    class LiteralExpression : public Expression {
    };

    class BooleanLiteralExpression : public Expression {
    private:
        bool value;
    public:
        BooleanLiteralExpression(bool value) : value(value) {
        }
    };

#define U_PLUS 0
#define U_SUB 1
#define U_INC 2
#define U_DEC 3
#define U_POST_INC 4
#define U_POST_DEC 5
#define U_NEW 6
#define U_DEL 7

    class UnaryExpression : public Expression {
    private:
        int operation;
        Expression *node;
    public:
        Expression *getNode() const {
            return node;
        }

    public:
        UnaryExpression(Expression *node, int operation) : node(node), operation(operation) {
        }
    };

#define E_MUL 0
#define E_DIV 1
#define E_SUB 2
#define E_ADD 3
#define E_LT 4
#define E_LTE 5
#define E_GT 6
#define E_GTE 7
#define E_SLEFT 8
#define E_SRIGHT 9

    class BinaryExpression : public Expression {
    private:
        Expression *left;
        Expression *right;
        int operation;

    public:
        BinaryExpression(Expression *left, Expression *right, int operation)
                : left(left), right(right), operation(operation) {
        }
    };

    class StatementList : public ASTNode {
    private:
        std::vector<Statement *> statements;

    public:
        StatementList() : statements() {
        }

        void add(Statement *statement) {
            statements.push_back(statement);
        }

        virtual void execute() {
            for (std::vector<Statement *>::iterator it = statements.begin(); it != statements.end(); ++it) {
                (*it)->execute();
            }
        }
    };

    class BlockStatement : public Statement {
    private:
        StatementList *statements;


    public:
        BlockStatement(StatementList *statements) : statements(statements) {
        }

        virtual void execute() {
            statements->execute();
        }

    };

    class Function : ASTNode {
    private:
        boost::optional<string> name;
        std::vector<string> parameters;

    public:
        Function(boost::optional<string>, std::vector<string> parameters) : name(name), parameters(parameters) {
        }

        boost::optional<string> getName() const {
            return name;
        }

        static Function *named(string name, std::vector<string> parameters) {
            return new Function(boost::optional<string>(name), parameters);
        }

        static Function *unamed(std::vector<string> parameters) {
            return new Function(boost::none, parameters);
        }
    };

    class Program : ASTNode {
    private:
        StatementList *statementList;


    public:
        Program(StatementList *statementList) : statementList(statementList) {
        }

        virtual void execute() {
            statementList->execute();
        }
    };
}

#endif

