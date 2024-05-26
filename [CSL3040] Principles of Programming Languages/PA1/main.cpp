#include <bits/stdc++.h>
#include <fstream>
#include "def.h"

using namespace std;

class Lexer
{
private:
    const vector<string> operators{"+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "<", ">", "<=", ">=", "=="};
    const vector<string> keywords{"short", "int", "float", "double", "bool", "char", "signed", "unsigned", "for", "while", "do", "return",
                                  "void", "switch", "break", "case", "continue", "goto", "long", "static", "union", "default", "if", "else"};
    const vector<string> special{"{", "}", ",", "(", ")", ";"};

    // token_ids as mentioned in def.h are used here
    const vector<int> op_ids{PLUS, MINUS, MULT, DIV, PERCENT, PLUS_PLUS, MINUS_MINUS, EQ, PLUS_EQ, MINUS_EQ, MULT_EQ, DIV_EQ, LESSER, GREATER, LESS_EQ, GREAT_EQ, EQ_EQ};
    const vector<int> key_ids{SHORT, INT, FLOAT, DOUBLE, BOOL, CHAR, SIGNED, UNSIGNED, FOR, WHILE, DO, RETURN, VOID, SWITCH, BREAK, CASE, CONTINUE, GOTO, LONG, STATIC, UNION, DEFAULT, IF, ELSE};
    const vector<int> special_ids{L_CBRACE, R_CBRACE, COMMA, L_PARAEN, R_PARAEN, SEMICOL};


    int is_keyword(string &lexeme)
    {
        int i = 0;
        for (const string keyword : keywords)
        {
            if (keyword == lexeme)
            {
                return key_ids[i];
            }
            i++;
        }

        return 0;
    }

    int is_identifier(string &lexeme)
    {
        if (is_digit(lexeme[0]))
        {
            return -1;
        }
        int i = 0;
        if (lexeme[0] == '_')
        {
            i++;
        }

        for (; i < lexeme.size(); i++)
        {
            if (lexeme[i] == '_')
            {
                if (i + 1 < lexeme.size() && lexeme[i + 1] == '_')
                {
                    return -1;
                }
                continue;
            }
            if (!(isalnum(lexeme[i])))
            {
                return -1;
            }
        }

        return IDENTIFIER;
    }

    int is_comment(string &lexeme)
    {
        return lexeme == "/*" || lexeme == "//";
    }

    bool is_digit(char c)
    {
        if (c <= '9' && c >= '0')
        {
            return true;
        }
        return false;
    }

    int is_num(string &lexeme)
    {
        bool res = true;
        bool flag = false;
        for (char c : lexeme)
        {
            if (c <= '9' && c >= '0')
            {
                continue;
            }
            if (c == '.' && !flag)
            {
                flag = true;
                continue;
            }
            return -1;
        }
        if (flag)
        {
            return FLO_CONST;
        }
        return INT_CONST;
    }

    int is_literal(string &lexeme)
    {
        return is_num(lexeme);
    }

    int is_operator(string &lexeme)
    {
        int i = 0;
        for (const auto &op : operators)
        {
            if (op == lexeme)
            {
                return op_ids[i];
            }
            i++;
        }
        return 0;
    }

    int is_special(string &lexeme)
    {
        int i=0;
        for (const auto &separate : special)
        {
            if (separate == lexeme)
            {
                return special_ids[i];
            }
            i++;
        }
        return 0;
    }

    bool is_empty(string &lexeme)
    {
        return lexeme == " " || lexeme == "\n";
    }

public:
    void tabulate_token(string &token)
    {
        ofstream pa;
        pa.open("pa_1.out", std::ios_base::app);
        ofstream table;
        table.open("symbol_table_1.out", std::ios_base::app);

        int token_id = -1;
        int token_type = -1;

        int temp = is_operator(token);

        if (temp>0)
        {
            pa<<temp<<" "<<token<<endl;
            return;
        }

        temp = is_special(token);
        if (temp>0)
        {
            pa<<temp<<" "<<token<<endl;
            return;
        }

        temp = is_keyword(token);
        if (temp>0)
        {
            pa<<temp<<" "<<token<<endl;
            table<<token<<" "<<0<<endl;
            return;
        }

        temp = is_literal(token);
        if (temp>0)
        {
            pa<<temp<<" "<<token<<endl;
            return;
        }
        temp = is_identifier(token);
        if (temp>0)
        {
            pa<<temp<<" "<<token<<endl;
            table<<token<<" "<<1<<endl;
            return;
        }
        
        temp = is_comment(token);
        if (temp>0)
        {
            return;
        }
        else
        {
            pa<<NOTOK<<" "<<token<<endl;
        }
    }

    void analyze(string &file_path)
    {
        char ch;
        string buffer;
        fstream file(file_path, fstream::in);

        if (!file.is_open())
        {
            cout << "Couldn't open the file path, enter the correct path.\n";
            exit(0);
        }

        bool multi_line_comment = false, single_line_comment = false;
        while (file >> noskipws >> ch)
        {
            if (single_line_comment || multi_line_comment)
            {
                if (single_line_comment && ch == '\n')
                    single_line_comment = false;

                if (multi_line_comment && ch == '*')
                {
                    file >> ch;
                    if (ch == EOF)
                        break;

                    if (ch == '/')
                        multi_line_comment = false;
                }
                continue;
            }

            if (ch == '/')
            {
                string comm(1, ch);
                file >> ch;
                if (ch == EOF)
                {
                    tabulate_token(comm);
                    break;
                }

                if (ch == '*')
                {
                    multi_line_comment = true;
                    comm += ch;
                }
                else if (ch == '/')
                {
                    single_line_comment = true;
                    comm += ch;
                }
                if (multi_line_comment || single_line_comment)
                {
                    tabulate_token(comm);
                    continue;
                }
            }

            string sh = string(1, ch);

            if (is_empty(sh))
            {
                if (!buffer.empty())
                {
                    tabulate_token(buffer);
                    buffer = "";
                }
                continue;
            }

            if (is_operator(sh) && !is_operator(buffer))
            {
                if (!buffer.empty())
                {
                    tabulate_token(buffer);
                    buffer = "";
                }
            }

            if (!is_operator(sh) && is_operator(buffer))
            {
                tabulate_token(buffer);
                buffer = "";
            }

            if (is_special(sh))
            {
                if (!buffer.empty())
                {
                    tabulate_token(buffer);
                    buffer = "";
                }
                if (is_special(sh))
                {
                    tabulate_token(sh);
                    continue;
                }
            }
            buffer += ch;
        }
        file.close();
    }
};

int main()
{
    // for clearing current content of pa_1.out and symbol_table_1.out files
    std::ofstream temp;
    temp.open("pa_1.out", std::ofstream::out | std::ofstream::trunc);
    temp.close();
    temp.open("symbol_table_1.out", std::ofstream::out | std::ofstream::trunc);
    temp.close();


    Lexer myLexer;
    string path = "./input.in";   // we can also use "./test.in" for testing other codes
    cout<<"Please enter the path of input file :   ";
    cin>>path;
    myLexer.analyze(path);      // does Lexical analysis and gives output in corresponding files

    return 0;
}