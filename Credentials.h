#ifndef _Login_
#define _Login_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Credential
{
    string username, password;
};

vector<Credential> readCredentials()
{
    vector<Credential> credentials;
    vector<string> data;
    string fname = "login_data.txt";
    ifstream f(fname.c_str());
    string tmp;
    while (f >> tmp)
    {
        data.push_back(tmp);
    }
    f.close();
    for (int i = 0; i < data.size(); i += 2)
    {
        Credential temp;
        temp.username = data[i];
        temp.password = data[i + 1];
        credentials.push_back(temp);
    }
    return credentials;
}

void addCredentials(string username, string password)
{
    ofstream f("login_data.txt", ios_base::app);
    f << username << endl;
    f << password << endl;
    f.close();
}

bool canLogin(string username, string password)
{
    for (Credential cred : readCredentials())
    {
        if (cred.username == username && cred.password == password)
        {
            return true;
        }
    }
    return false;
}

#endif //_Login_
