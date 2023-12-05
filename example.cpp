#include<iostream>
using namespace std;
int helper(char arg1, char arg2);
int helper(char arg1, char arg2, char arg3);

void zad1(string txt);
string zad2(string txt1, string txt2);
int zad3(string txt);
void zad4(string txt1, string txt2, string txt3);
void zad5(string txt);

int main()
{
   // zad1("Siala baba mak");
   // cout<<zad2("aE4R","1G6t");
   // cout<<zad3("A3R56JU2A");
   // zad4("aca","aaa","dva");
   // zad5("23AV3Bt678NE3YQ12Z");

}

void zad1(string txt)
{
    for(int i=0; i<txt.size();i++)
        if(i%3==0)
            cout<<txt[i]<<endl;
}

string zad2(string txt1, string txt2)
{
    if(txt1.size() != txt2.size())
        throw invalid_argument("not the same length");

    string result = "";
    for(int i=0;i<txt1.size();i++)
    {
        result += txt1[i];
        result += txt2[i];
    }
    return result;
}

int zad3(string txt)
{
    bool ascii[26] = {false};
    int counter = 0;

    for(int i=0;i<txt.size();i++)
        if((int)txt[i] >= 65 && (int)txt[i] <= 90)
            ascii[(int)txt[i]-65] = true;

     for(int i=0;i<26;i++)
        if(ascii[i])
            counter++;

    return counter;
}

void zad4(string txt1, string txt2, string txt3)
{
    if(txt1 <= txt2 && txt1 <= txt3)
    {
        cout<<txt1<<" ";
        if(txt2 <= txt3)
            cout<<txt2<<" "<<txt3<<endl;
        else cout<<txt3<<" "<<txt2<<endl;
    }
    else if(txt2 <= txt1 && txt2 <= txt3)
    {
        cout<<txt2<<" ";
        if(txt1 <= txt3)
            cout<<txt1<<" "<<txt3<<endl;
        else cout<<txt3<<" "<<txt1<<endl;
    }
    else
    {
        cout<<txt3<<" ";
        if(txt1 <= txt2)
            cout<<txt1<<" "<<txt2<<endl;
        else cout<<txt2<<" "<<txt1<<endl;
    }
}

void zad5(string txt)
{
    bool tab[20] = {false};
    int numbers[5];
    int numbersIterator = 0;

    for(int i=0;i<20;i++)
        if((int)txt[i] >= 48 && (int)txt[i] <= 57)
            tab[i] = true;
        else tab[i] = false;

    for(int i=0;i<20;i++) // 'i' must be egual or greater than string lenght!
    {
        if(tab[i] && !tab[i+1])
        {
            numbers[numbersIterator] = txt[i] - '0';
            numbersIterator++;
            i++;
        }
       else if(tab[i] && tab[i+1] && !tab[i+2])
        {
            numbers[numbersIterator] = helper(txt[i], txt[i+1]);
            numbersIterator++;
            i+=2;
        }
         else if(tab[i] && tab[i+1] && tab[i+2] && !tab[i+3])
        {
            numbers[numbersIterator] = helper(txt[i], txt[i+1], txt[i+2]);
            numbersIterator++;
            i+=3;
        }
    }
    for(int i=0;i<5;i++)
        cout<<numbers[i]<<endl;

    int sum=0;
    for(int item: numbers)
        sum+=item;
    cout<<"_____"<<endl;
    cout<<"Sum = "<<sum<<endl;

}

int helper(char arg1, char arg2)
{
    return (arg1-'0')*10 + (arg2-'0');
}
int helper(char arg1, char arg2, char arg3)
{
        return (arg1-'0')*100 + (arg2-'0')*10 + (arg3-'0');
}
