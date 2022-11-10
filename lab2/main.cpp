#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class chart
{
private:
    std::string file_name;
    std::string chart_name;
    //std::vector<std::string> column_name;
    std::vector<std::string> name;
    std::vector<std::string> num;
    std::vector<std::string> way;
    std::vector<std::string> time;
    std::string note;
    int num_column;
    int num_row;

public:

    void fill (const char* str)
    {
        //this->file_name = str;
        std::ifstream fin;
        fin.open(str);
        if (fin.is_open()==0)
        {
            printf("file is not open");
            return;
        }
        else
        {
            std::cout<<"file is open"<<std::endl;
        };

        char ch;
        fin.get(ch);
        do
        {
            this->chart_name.push_back(ch);
            fin.get(ch);
        }while (ch!='\n');

        /*fin.get(ch);
        this->num_column = int(ch) - 48;

        fin.get(ch);


        for (int i = 0; i< this->num_column; ++i ) {
            fin.get(ch);
            std::string s="";
                do {
                    s.push_back(ch);
                    fin.get(ch);
                }while (ch != ',' && ch!='\n');
            this->column_name.push_back(s);
        }*/

        fin.get(ch);
        this->num_row=int(ch)-48;
        fin.get(ch);
        fin.get(ch);

        for (int i=0; i<this->num_row; ++i) {

            std::string s="";
            do {
                s.push_back(ch);
                fin.get(ch);
            } while (ch != ',');
            this->name.push_back(s);
            fin.get(ch);

            s="";
            do {
                s.push_back(ch);
                fin.get(ch);
            } while (ch != ',');
            this->num.push_back(s);
            fin.get(ch);

            s="";
            do {
                s.push_back(ch);
                fin.get(ch);
            } while (ch != ',');
            this->way.push_back(s);
            fin.get(ch);

            s="";
            do {
                s.push_back(ch);
                fin.get(ch);
            } while (ch != '\n');
            this->time.push_back(s);
            fin.get(ch);
        }

        while (ch!='\n')
        {
            note.push_back(ch);
            fin.get(ch);
        }

        fin.close();
    }

    void chart_print()
    {
        unsigned long lenght_chart=0;
        lenght_chart = this->name[0].size()+this->num[0].size()+this->way[0].size()+this->time[0].size();
        lenght_chart+=13;
        std::cout<<std::string(lenght_chart, '-')<<std::endl
                <<"| "<<this->chart_name<<std::string((lenght_chart - this->chart_name.size() - 3), ' ')<<"|\n"
                <<std::string(lenght_chart, '-')<<std::endl;
        /*for (int i=0; i<this->num_column; ++i) {
            std::cout << '|' << this->column_name[i] << ' ';
        }
        std::cout<<"|\n";*/

        for (int i=0; i<num_row; ++i)
        {
            std::cout<<"| "<<this->name[i]<<std::string((this->name[0].size()+1-this->name[i].size()), ' ')
                    <<"| "<<this->num[i]<<std::string((this->num[0].size()+1-this->num[i].size()), ' ')
                    <<"| "<<this->way[i]<<std::string((this->way[0].size()+1-this->way[i].size()), ' ')
                    <<"| "<<this->time[i]<<std::string((this->time[0].size()+1-this->time[i].size()), ' ')
                    <<"|\n"<<std::string(lenght_chart, '-')<<std::endl;
        }

        std::cout<<"| "<<this->note<<std::string ((lenght_chart-this->note.size()-3), ' ')<<'|'<<std::endl
                <<std::string(lenght_chart, '-')<<std::endl;

    }

};

int main()
{
    setlocale(LC_ALL, "rus");

    chart c;
    c.fill("/home/iryna/projects/labs/lab2/names.txt");
    c.chart_print();
}

