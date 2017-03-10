#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void hint()
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
    cout<<endl<<"T - APK install";
    cout<<endl<<"Shift + S - shell";
    cout<<endl;

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
    cout<<"Csatlakoztatva van a saját eszközöd? ( I: igen N: nem ): ";
    cin>>ans;
    if(ans=="n" || ans=="N")
    {
        system("adb kill-server");
        system("adb start-server");
        system("cls");
        cout<<"Min keresztül szeretnéd csatlakoztatni az eszközöd?: ";
        cout<<endl<<"1. Wi-Fi\n2. USB\n3. ADB tcpip 5555 spam\n4. Direct IP\nVálasz: ";
        cin>>option;
        cout<<endl;
        if(option==4)
        {
            cout<<"IP: ";
            cin>>IP;
            command=a+IP;
            system(command.c_str());
        }
        if(option==3)
        {
            string TempIP;
            int keyevent;
            while(keyevent!=12000)
            {
                keyevent=_getch();
                switch(keyevent)
                {
                case 13:
                    {
                        system("adb devices");
                        cout<<"Disconnect device and type it's IP: ";
                        cin>>TempIP;
                        string commandLOL;
                        commandLOL="adb connect "+TempIP;
                        system(commandLOL.c_str());
                        keyevent=12000;
                    }
                    break;

                case 27: {
                    system("adb tcpip 5555");
                    }
                    break;
                case 114: {
                    system("adb devices");
                    }
                    break;
                }
            }
        }
        if(option==1)
        {
            cout<<endl<<"1. Csatlakozasd az eszközöd USB-n keresztül és kapcsold be az USB hibakeresést."<<endl;
            system("pause");
            cout<<endl;
            system("adb tcpip 5555");
            cout<<"2. Csatlakozz ugyan arra a hálózatra amire a számíógéped is van csalakozatva."<<endl;
            cout<<"3. Írd be az eszközöd IP címét: ";
            cin>>IP;
            command=a+IP;
            system(command.c_str());
            cout<<endl;
            system("pause");
        }
        if(option==2)
        {
            cout<<endl<<"Csatlakoztasd az eszközödet a számítógéphez USB-n keresztül."<<endl;
            system("pause");
        }
    }
    string b="adb shell input text ";
    int input=10;
    system("cls");
    hint();
    while(input!=0)
    {
        string TempPATH;
        input=_getch();
        if(input==105)
        {
            cout<<endl<<"Szöveg: ";
            cin>>text;
            text=b+text;
            system(text.c_str());
        }
        if(input==112)
        {
            system("adb shell input keyevent KEYCODE_POWER");
        }
        if(input==116)
        {
            cout<<endl<<"APK helye: ";
            cin>>TempPATH;
            string command2="adb install "+TempPATH;
            system(command2.c_str());
            cout<<endl;
        }
        if(input==83)
        {
            cout<<endl;
            system("adb shell");
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
