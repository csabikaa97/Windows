#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int hint()
{
    cout<<endl<<"P - Power";
    cout<<endl<<"H - Home";
    cout<<endl<<"B - Back";
    cout<<endl<<"N - Notification";
    cout<<endl<<"W,A,S,D - Swipe eventek";
    cout<<endl<<"Nyilak - Dpad emu";
    cout<<endl<<"Enter";
    cout<<endl<<"Num (-) - Hang le";
    cout<<endl<<"Num (+) - Hang fel";
    cout<<endl<<"";
    cout<<endl<<"";
    cout<<endl<<"";
    cout<<endl<<"";
    cout<<endl<<"";
    cout<<endl<<"";
    cout<<endl<<"";
    cout<<endl<<"";
    cout<<endl<<"";

}
int main()
{
    setlocale(LC_ALL,"");
    string a="adb connect ";
    string command;
    string text;
    string IP;
    string ans;
    int option;
    system("adb devices");
    cout<<"Csatlakoztatva van a saj�t eszk�z�d? ( I: igen N: nem ): ";
    cin>>ans;
    if(ans=="n" || ans=="N")
    {
        system("adb kill-server");
        system("adb start-server");
        system("cls");
        cout<<"Min kereszt�l szeretn�d csatlakoztatni az eszk�z�d?: ";
        cout<<endl<<"1. Wi-Fi\n2. USB\n10. Direct IP\nV�lasz: ";
        cin>>option;
        cout<<endl;
        if(option==10)
        {
            cout<<"IP: ";
            cin>>IP;
            command=a+IP;
            system(command.c_str());
        }
        if(option==1)
        {
            cout<<endl<<"1. Csatlakozasd az eszk�z�d USB-n kereszt�l �s kapcsold be az USB hibakeres�st."<<endl;
            system("pause");
            cout<<endl;
            system("adb tcpip 5555");
            cout<<"2. Csatlakozz ugyan arra a h�l�zatra amire a sz�m��g�ped is van csalakozatva."<<endl;
            cout<<"3. �rd be az eszk�z�d IP c�m�t: ";
            cin>>IP;
            command=a+IP;
            system(command.c_str());
            cout<<endl;
            system("pause");
        }
        if(option==2)
        {
            cout<<endl<<"Csatlakoztasd az eszk�z�det a sz�m�t�g�phez USB-n kereszt�l."<<endl;
            system("pause");
        }
    }
    string b="adb shell input text ";
    int input;
    system("cls");
    hint();
    while(input!=0)
    {
        input=_getch();
        cout<<input<<endl;
        if(input==105)
        {
            cout<<endl<<"Szoveg: ";
            cin>>text;
            text=b+text;
            system(text.c_str());
        }
        if(input==112)
        {
            system("adb shell input keyevent KEYCODE_POWER");
        }
        if(input==104)
        {
            system("adb shell input keyevent KEYCODE_HOME");
        }
        if(input==98)
        {
            system("adb shell input keyevent KEYCODE_BACK");
        }
        if(input==72)
        {
            system("adb shell input keyevent KEYCODE_DPAD_UP");
        }
        if(input==80)
        {
            system("adb shell input keyevent KEYCODE_DPAD_DOWN");
        }
        if(input==75)
        {
            system("adb shell input keyevent KEYCODE_DPAD_LEFT");
        }
        if(input==77)
        {
            system("adb shell input keyevent KEYCODE_DPAD_RIGHT");
        }
        if(input==13)
        {
            system("adb shell input keyevent KEYCODE_ENTER");
        }
        if(input==117)
        {
            system("adb shell input keyevent 66");
        }
        if(input==110)
        {
            system("adb shell input swipe 360 1 360 1280");
        }
        if(input==119)
        {
            system("adb shell input swipe 360 1279 360 1");
        }
        if(input==97)
        {
            system("adb shell input swipe 1 640 719 640");
        }
        if(input==115)
        {
            system("adb shell input swipe 719 1 719 1279");
        }
        if(input==100)
        {
            system("adb shell input swipe 719 640 1 640");
        }
        if(input==43)
        {
            system("adb shell input keyevent VOLUME_UP");
        }
        if(input==45)
        {
            system("adb shell input keyevent VOLUME_DOWN");
        }
    }
}
