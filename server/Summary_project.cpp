#include <iostream>
#include "Simulator.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <fstream>
using namespace std;
int main()
{
    Simulator s = Simulator();   
    fstream newfile;
    newfile.open("config.txt", ios::in);
    if (newfile.is_open()) {
        string tp;
        while (getline(newfile, tp)) {
            string key = tp.substr(0, tp.find(':'));
            string num = tp.substr(tp.find(':') + 1);
            stringstream geek(num);
            int x = 0;
            geek >> x;
            if (key == "numOfCameras") {
                s.size = stoi(num);
            }
            else {
                if (key == "messageInSecond") {
                    s.arrCamera[0].messageInSecond = stoi(num);
                }
                else {
                    if (key == "ip") {
                        for (int i = 0; i < s.size; i++) {
                            s.arrCamera[i].ip = num.c_str();
                        }
                    }
                    else {
                        if (key == "port") {
                            for (int i = 0; i < s.size; i++) {
                                s.arrCamera[i].port = stoi(num);
                            }
                        }
                    }
                }
            }
        }
    }
    s.start();
}

