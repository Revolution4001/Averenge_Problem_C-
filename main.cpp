#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

void load(float *tab,int &amount); // load table standard

void load_pointer(float *tab, int &amount); // load table pointer

void write_normal(float *tab,int &amount); // use table

void write_pointer(float *tab, int &amount); // use pointer on table

float average(float *tab, int &amount);

float average_pointer(float *tab, int &amount);

void find_nearby(float *tab, int &amount, float &average);

void find_nearby_v2(float *tab, float *tab2, int &amount, float &average);

void function_all(float *tab, float *tab2, int &amount); // One function do all the job (without others)

void function_all_divide(float *tab, float *tab2, int &amount);

int main()
{
    int amount;
    float srednia;
    cout<<"Podaj ilosc liczb ? :";
    cin>>amount;
    float *tablica;
    tablica = new float [amount];
    float *tablicaW;
    tablicaW = new float [amount];


    // Tier I - use load or load_pointer
    //load(tablica,amount);
    //load_pointer(tablica,amount);

    // Tier II -- optional use write_normal or write_pointer

    //write_normal(tablica,amount);
    //write_pointer(tablica,amount);

    // Tier III
    // use average or average_pointer

    //srednia=average(tablica,amount);
    //srednia=average_pointer(tablica,amount);

    // Tier IV - find the closest number
    // use find_nearby or find_nearby_v2

    //find_nearby(tablica,amount,srednia);
    //find_nearby_v2(tablica,tablicaW,amount,srednia);

    // Tier V - only one function

    //function_all(tablica,tablicaW,amount);

    // Tier VI -  debugging debugging and .... debugging :)

    // Tier VII - only one function but one function with others in

    //function_all_divide(tablica,tablicaW,amount);

    delete [] tablica;
    delete [] tablicaW;

    return 0;
}

void load(float *tab, int &amount)
{
    cout<<"Podaj teraz "<<amount<<" liczb-y (kazda liczbe zatwierdz enterem): "<<endl;

    for (int i=0;i<amount;i++)
    {
         cout<<"Podaj liczbe numer "<<i+1<<" : ";
         cin>>tab[i];

    }
}

void load_pointer(float *tab, int &amount)
{
    cout<<"Podaj teraz "<<amount<<" liczb-y (kazda liczbe zatwierdz enterem): "<<endl;

    float *point=tab;


    for (int i=0;i<amount;i++)
    {
         cout<<"Podaj liczbe numer "<<i+1<<" : ";
         cin>>*point;
         point++;
    }

}



void write_normal(float *tab, int &amount)
{
    for (int i=0;i<amount;i++)
    {
        cout<<"Tab["<<i<<"] = "<<tab[i]<<endl;
    }
}

void write_pointer(float *tab, int &amount)
{
    for (int i=0;i<amount;i++)
    {
       cout<<"Tab["<<i<<"] = "<<*tab<<endl;
       tab++; // move pointer to next position // name of table is also pointer to her first element
    }
}

float average(float *tab, int &amount)
{
    float suma=0,srednia;

    // Summary Table
    for (int i=0; i<amount;i++)
    {
        suma+=tab[i];
    }

    srednia=suma/amount;

    return srednia;
}

float average_pointer(float *tab, int &amount)
{
    float suma=0,srednia;

    // Summary Table
    for (int i=0; i<amount;i++)
    {
        suma+=*tab;
        tab++;
    }

    srednia=suma/amount;

    return srednia;
}

void find_nearby(float *tab, int &amount, float &average)
{

    float m,n;
    float srednia=average;
    for (int i=0;i<amount;i++)
    {
        if (i==0)
        {
            m=fabs(tab[0]-srednia); // Insert first
            n=tab[i];
        }

        // find the closest
        if (fabs(tab[i]-srednia)<m)
        {
            m=fabs(tab[i]-srednia);
            n=tab[i];
        }
    }
    cout<<endl<<"Srednia = "<<srednia<<endl;
    cout<<"Najblizej sredniej znajduje sie liczba: "<<n;
}

void find_nearby_v2(float *tab, float *tab2,int &amount, float &average)
{
    int j=0;
    float m;
    float srednia=average;
    for (int i=0;i<amount;i++)
    {
        // Starting condition
        if (i==0)
        {
            m=fabs(tab[0]-srednia);
            tab2[0]=tab[0];
        }

        // find the closest
        if (fabs(tab[i]-srednia)<m)
        {
            m=fabs(tab[i]-srednia);
            tab2[j]=tab[i];


        }
        // if two or more number are the closest
        else if ((fabs(tab[i]-srednia)==m &&i!=0))
        {
            j++; // Wstaw ale do nastepne
            tab2[j]=tab[i];

        }


    }

    // Debugging options
    cout<<endl<<"TABLE 2"<<endl;
    cout<<"j = "<<j<<endl;
    for (int i=0;i<=j;i++)
    {
        cout<<"tab2["<<i<<"] ="<<tab2[i]<<endl;
    }


    cout<<endl<<"Srednia = "<<srednia<<endl;
    if (j==0) // znalazlem tylko jedna liczbe
    {
        cout<<"Najblizej sredniej jest liczba: "<<tab2[0];
    }
    else
    {
        cout<<"Najblizej sredniej znajduja sie liczby: ";
        for (int i=0;i<=j;i++)
        {

            cout<<tab2[i]<<" , ";
        }


    }
}

void function_all(float *tab, float *tab2, int &amount)
{


    // Load
    cout<<"Podaj teraz "<<amount<<" liczb-y (kazda liczbe zatwierdz enterem): "<<endl;

    float suma=0,srednia,m;
    int j=0;
    float *point = tab;

    for (int i=0; i<amount; i++)
    {
         cout<<"Podaj liczbe numer "<<i+1<<" : ";
         cin>>*point;
         suma+=*point;
         point++; //tab++; // Tak nie pojdzie bede kosmiczne wartosci zeby zadzialalo musisz uzyc dodatkowej zmiennej wskaznikowej

    }
    srednia=suma/amount;

    // Find

    for (int i=0;i<amount;i++)
    {
        // Starting condition
        if (i==0)
        {
            m=fabs(tab[0]-srednia);
            tab2[0]=tab[0];
        }

        // find the closest
        if (fabs(tab[i]-srednia)<m)
        {
            m=fabs(tab[i]-srednia);
            tab2[j]=tab[i];


        }
        // if two or more number are the closest
        else if ((fabs(tab[i]-srednia)==m &&i!=0))
        {
            j++; // Wstaw ale do nastepne
            tab2[j]=tab[i];

        }
    }


     // Debugging options
//    cout<<endl<<"TABLE 2"<<endl;
//    cout<<"j = "<<j<<endl;
//    for (int i=0;i<=j;i++)
//    {
//        cout<<"tab2["<<i<<"] ="<<tab2[i]<<endl;
//    }

    cout<<"Srednia wynosi : "<<srednia<<endl;

    if (j==0) // znalazlem tylko jedna liczbe
    {
        cout<<"Najblizej sredniej znajduje sie liczba: "<<tab2[0];
    }
    else
    {
        cout<<"Najblizej sredniej znajduja sie liczby: ";
        for (int i=0;i<=j;i++)
        {
            cout<<tab2[i]<<" , ";
        }
    }

}

void function_all_divide(float *tab, float *tab2, int &amount)
{
    float srednia,m;
    int j=0;
    load_pointer(tab,amount);

    srednia=average_pointer(tab,amount);

    for (int i=0;i<amount;i++)
    {
        // Starting condition
        if (i==0)
        {
            m=fabs(tab[0]-srednia);
            tab2[0]=tab[0];
        }

        // find the closest
        if (fabs(tab[i]-srednia)<m)
        {
            m=fabs(tab[i]-srednia);
            tab2[j]=tab[i];
        }
        // if two or more number are the closest
        else if((fabs(tab[i]-srednia))==m && i!=0)
        {
           j++;
           tab2[j]=tab[i];
        }
    }

    cout<<"Srednia wynosi : "<<srednia<<endl;

    if (j==0) //only one is the closest
    {
        cout<<"Najblizej srednia znajduje sie liczba: "<<tab2[0];
    }
    else
    {
        cout<<"Najblizej sredniej znajduja sie liczby: ";
        for(int i=0;i<=j;i++)
        {
            if (i!=j)
                cout<<tab2[i]<<" , ";
            else
                cout<<tab2[i];
        }
    }
}



