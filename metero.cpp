#include <iostream>
#include <string.h>
#include <climits>
#include <fstream>
#include <Windows.h>
using namespace std;
#define INF 999
int mindistance(float distance[], bool stat[])
{
    float minimum = INT_MAX, ind;
    for (int k = 0; k < 25; k++)
    {
        if (stat[k] == false && distance[k] <= minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}
void dijkstra(float graph[25][25], int source, string stations[24])
{
    float distance[25];
    bool stat[25];
    for (int k = 0; k < 25; k++)
    {
        distance[k] = INT_MAX;
        stat[k] = false;
    }
    distance[source] = 0;
    for (int k = 0; k < 25; k++)
    {
        int m = mindistance(distance, stat);
        stat[m] = true;
        for (int k = 0; k < 25; k++)
        {
            if (!stat[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }
    cout << "\n\n\nMinimum Number of Stations from "
         << "[" << stations[source] << "]"
         << " To every station\n\n\n"
         << endl;
    for (int k = 0; k < 24; k++)
    {

        cout << "Enter"
             << " " << k << " "
             << "To Cheak Distance Between " << stations[source] << " To "
             << "[" << stations[k] << "]"
             << " "
             << "Station" << endl;
    }
    int n;
    cout << "Enter Station to cheak distance to Each other:" << endl;
    cin >> n;
    cout << "Total Distance from "
         << "[" << stations[source] << "]"
         << " To " << stations[n] << "  are  "
         << "[" << distance[n] << "]"
         << "KM" << endl;
    for (int k = source; k <= n; k++)
    {

        cout << stations[source] << " -> " << stations[k] << " "
             << "Station"
             << "[" << distance[k] << "]"
             << "KM" << endl;
    }
}

int login()
{
    char dum, u_name[30], name[30], g_pwd[30], pwd[30];
    int flag = 0, s = 1;
    cout << "\t\t\t\t\t\t*WELLCOME TO LOGIN*" << endl;
    cout << "\t\t\t\t\t  " << endl;
    if (s == 1)
    {

        cout << "Enter your USER NAME  : " << endl;
        cin >> name;
    }

    cout << "Enter the PASSWORD   : " << endl;
    cin >> pwd;
    fstream f;
    f.open("user_logins.txt", ios::in);
    f.seekg(0);
    while (f)
    {
        f.get(dum);
        f.get(u_name, 30);
        f.get(dum);
        f.get(g_pwd, 30);
        if (strcmp(u_name, name) == 0 && strcmp(pwd, g_pwd) == 0)
        {
            flag = 1;
            string phrase = "\n\t\t\tYou have Successfully LOGGED IN\n ";
            cout << phrase;
            break;
        }
        else if (strcmp(u_name, name) == 0 && strcmp(pwd, g_pwd) != 0)
        {
            do
            {
                string phrase = "\t\t\t----INCORRECT Credentials!!!----\n";
                cout << phrase;
                login();
            } while (strcmp(pwd, g_pwd) != 0);

            string phrase = "\n\t\t\t\t\t\tYou have Successfully LOGGED IN";
            cout<<phrase;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n\t\t\t\t\t\tSORRY!!! USER NAME and PASSWORD does not Exist" << endl;
    f.close();
    return flag;
}

void signup()
{
    cout << "\t\t\t\t\t\t*WELLCOME TO SIGNUP*" << endl;
    cout << "\t\t\t\t\t  " << endl;
    char name[30], pwd[30], check_pwd[30];
    fstream f;
    f.open("user_logins.txt", ios::in);
    char g_name[30], g_pwd[30], dum;
    int flag;
    cout << "Enter the USER NAME : ";
    cin >> name;
    do
    {
        f.seekg(0);
        while (f)
        {
            flag = 1;
            f.get(dum);
            f.get(g_name, 30);
            f.get(dum);
            f.get(g_pwd, 30);
            if (strcmp(g_name, name) == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "\n\t\t\t----SORRY! USER-NAME ALREADY EXIST----" << endl;
            cout << "Enter the USER NAME : ";
            cin >> name;
        }
    } while (flag == 0);
    f.close();
    f.open("user_logins.txt", ios::out | ios::app);
    cout << "Enter your PASSWORD : ";
    cin >> pwd;
    cout << "Re-Enter your PASSWORD : ";
    cin >> check_pwd;
    while (strcmp(pwd, check_pwd) != 0)
    {
        cout << "\t\t\t----INCORRECT PASSWORD!!!----" << endl;
        cout << "Enter your PASSWORD : ";
        cin >> pwd;
        cout << "Re-Enter your PASSWORD : ";
        cin >> check_pwd;
    }
    f << endl
      << name << endl
      << pwd;
    cout << "\n\t\t\t\t\t  YOUR NEW ID IS CREATING PLEASE WAIT";
    for (int i = 0; i < 6; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << "\n\n\t\t\t\t\t\aCONGRATULATION!!!YOUR ID CREATED SUCCESSFULL....Please wait";
    Sleep(500);
    system("CLS");
    f.close();
}
int main()
{
    float graph[25][25] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1.1, 0, 0.7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0.7, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1.1, 0, 2.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2.3, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1.1, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 3.8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 3.8, 0, 1.2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.2, 0, 0.9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.9, 0, 1.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.5, 0, 2.5, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.5, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1.1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 3.5, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.5, 0, 1.2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.2, 0, 1.3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.3, 0, 1.1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.1, 0, 0.5, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 3.5}};
    int source;
    int n, W, ch, flag;
    char s;
    cout << "\t\t\t\t\t\t----------------------------------------WELCOME TO Chennai Metro Distance Counter----------------------------------------\n\n";
    do
    {
        cout << endl;
        cout << "\t\t\t\t\t\t\t \t\t\t\t\t_____________\n";
        cout << "\t\t\t\t\t\t\t \t\t\t\t\t_____________\n";
        cout << "\t\t\t\t\t\t\t \t\t\t\t\t 1) LOGIN    \n";
        cout << "\t\t\t\t\t\t\t \t\t\t\t\t 2) REGISTER \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t 3) EXIT     \n";
        cout << "\t\t\t\t\t\t\t \t\t\t\t\t____________\n";
        cout << "\t\t\t\t\t\t\t \t\t\t\t\t_____________\n";
        cout << "Enter your Choice : ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case 1:
            flag = login();
            break;
        case 2:
            signup();
            cout << "Do you want to LOGIN (Y/N)? : ";
            cin >> s;
            if (s == 'y' || s == 'Y')
                flag = login();
            else
            {
                cout << "\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
                cout << "\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
                cout << "\t\t\t\t\t\t\t \t\t\t\t\t|___________|\n";
                exit(1);
            }
            break;
        case 3:
            cout << "\t\t\t\t\t\t\t \t\t\t\t\t ___________ \n";
            cout << "\t\t\t\t\t\t\t \t\t\t\t\t| THANK YOU |\n";
            cout << "\t\t\t\t\t\t\t \t\t\t\t\t|___________|\n";
            exit(0);
            break;
        default:
            cout << "\t\t\t----INCORRECT CHOICE!!!----" << endl;
            break;
        }
    } while (flag != 1);
    if (flag == 1)
    {
        string stations[24] = {"Wimco Nagar Depot ", "Wimco Nagar ", "Tiruvottriyur ", "Tiruvottriyur Theradi ", "Kaladipet ", "Toll Gate ", "New Washermanpet", "Tondiarpet ", " Sir Theagaraya College ", "Washermanpet", " Mannadi", "High Court", " MGR Central (Chennai Central) ",
                               "Government Estate ", "LIC ", "Thousand Lights ", "AG DMS ", "Teynampet ", "Nandanam ", "Saidapet", "Little Mount ", " Guindy", "Nanganallur Road", "Chennai International Airport"};

        char x;
        cout << "\t\t\t\t\t\t*WELLCOME TO Chennai Metro Distance Counter*" << endl;
        cout << "\t\t\t\t\t  " << endl;
        do
        {
            for (int i = 0; i < 24; i++)
            {
                cout << "Enter "
                     << " " << i << " "
                     << " for " << stations[i] << endl;
            }
            cout << "Enter the source station" << endl;
            cin >> source;
            system("cls");
            dijkstra(graph, source, stations);

            cout << "Do you want to continue (Y/N)? : ";

            cin >> x;
            system("cls");
        } while (x == 'y' || x == 'Y');
        return 0;
    }
}