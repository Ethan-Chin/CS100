#include <iostream>
#include <string>
#include <vector>
using namespace std;
//this time, I'm gonna write comments!!!!!!!!!!!
class ReportParser
{
public:
    ReportParser(int numStudents, int numInfos);//constractor,initialize something
    ~ReportParser();//dosen't cout at all(sure, for me QwQ)
    void readReport();//read  information that  users input//reading the m & n and option to sorting should be tasks to main function
    void writeStructuredReport(int sortOption);//sorting and output
    void swapRow(int a, int b);//row swapping
    void setFormat();//Make the table tidy
private:
    int n, m;//the number of students and information for each
    vector< vector<string> > format;//format is a member of this amazing class
};

void ReportParser::setFormat()
{
    char blank = ' ';
    char bar = '-';
    for (int i = 0; i < m; i++)
    {
        int maxLength = 0;
        for (int j = 0; j < n; j++)//find the longest string in each column
        {
            if (maxLength < (format[j * 2 + 1][i * 2 + 1].length()))
            {
                maxLength = format[j * 2 + 1][i * 2 + 1].length();
            }
        }
        for (int j = 0; j < n; j++)//use blank to complete strings to have the same length ,that is max length
        {
            format[j * 2 + 1][i * 2 + 1].append(maxLength - format[j * 2 + 1][i * 2 + 1].length(), blank);
        }
        for (int j = 0; j < (n + 1); j++)//form separators between rows
        {
            format[j * 2][i * 2 + 1].assign(maxLength, bar);
        }
    }
}

void ReportParser::swapRow(int a, int b)//read in two parameters (index of rows) and exchange the whole two rows
{
    for (int i = 0; i < m; i++)
    {
        string temp;
        temp = format[a][i * 2 + 1];
        format[a][i * 2 + 1] = format[b][i * 2 + 1];
        format[b][i * 2 + 1] = temp;
    }
}

ReportParser::ReportParser(int numStudents, int numInfos) 
{
    n = numStudents;
    m = numInfos;//initialize m & n
    format.resize((n * 2) + 1);//initialize length of the column,to be const
    for (int i = 0; i < ((n * 2) + 1); i++)//initialize  length of the row,to be const
    {
        format[i].resize((m * 2) + 1);
    }
    for (int i = 0; i < (m * 2 + 1); i++)//initialize the array to be a format we want,i is index of line
    {
        if (i == 0)//initialize the first column
        {
            format[0][i] = "/-";
            format[n * 2][i] = "\\-";
            for (int j = 1; j < (n * 2); j++)
            {
                if (j % 2 == 0)//mind the difference between each row(odd and even)
                {
                    format[j][i] = "|-";
                }
                else
                {
                    format[j][i] = "| ";
                }
            }
        }
        else if(i == (m * 2))//initialize the last column, mind some special occasions
        {
            format[0][i] = "-\\";
            format[n * 2][i] = "-/";
            for (int j = 1; j < (n * 2); j++)
            {
                if (j % 2 == 0)
                {
                    format[j][i] = "-|";
                }
                else
                {
                    format[j][i] = " |";
                }
            }
        }
        else if((i != 0)&&(i != (m * 2))&&(i % 2 == 0))//initiallize those lines inside this format
        {
            format[0][i] = "---";
            format[n * 2][i] = "---";
            for (int j = 1; j < (n * 2); j++)
            {
                if (j % 2 == 0)
                {
                    format[j][i] = "-|-";
                }
                else
                {
                    format[j][i] = " | ";
                }
            }
        }
    }
}

ReportParser::~ReportParser()
{
}

void ReportParser::readReport()
{
    for (int i = 0; i < n; i++)//read what users input and add it into the format
    {
        for (int j = 0; j < m; j++)
        {
            cin >> format[i * 2 + 1][j * 2 + 1];
        }
        getchar();//prevent the influence that the ‘Enter’ leads to
    }
}

void ReportParser::writeStructuredReport(int sortOption)
{
    setFormat();
    for (int i = 0; i < n; i++)//sort ascending
    {
        for(int j = 1; j < n; j++)
        {
            if (format[(j - 1) * 2 + 1][sortOption * 2 + 1] > format[j * 2 + 1][sortOption * 2 + 1])
            {
                swapRow((j - 1) * 2 + 1, j * 2 + 1);//as the function above
            }
        }
    }
    for (int i = 0; i < (n * 2 + 1); i++)
    {
        for (int j = 0; j < (m * 2 + 1); j++)//output the format
        {
            cout<<format[i][j];
            if (j == m * 2)//make sure that the format wouldn't be in a line
            {
                cout<<endl;
            }
        }
    }
    //cout<<"first "<<format[0][0]<<endl;//this is a test for debugging
}

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    int m1, n1, sortOption;
    std::cin >> m1 >> n1 >> sortOption;
    getchar();  
    ReportParser p(n1, m1);
    p.readReport();
    p.writeStructuredReport(sortOption);
    return 0;
}