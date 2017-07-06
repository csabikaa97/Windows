#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <string>
#include <iostream>
#include <sstream>
#include <tchar.h>
#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("Számológép");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Számológép"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           400,                 /* The programs width */
           360,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}HWND textfield,button;


/*  This function is called by the Windows function DispatchMessage()  */
std::string Szoveg;
std::stringstream buffer;
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        textfield = CreateWindow ("STATIC",
                                  "0",
                                  WS_BORDER | WS_CHILD | WS_VISIBLE,
                                  20,20,345,20,
                                  hwnd, NULL, NULL, NULL);

        button = CreateWindow ("BUTTON",
                               "1",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               40,60,60,40,
                               hwnd, (HMENU) 2, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "2",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               120,60,60,40,
                               hwnd, (HMENU) 3, NULL, NULL);
        button = CreateWindow ("BUTTON",
                               "3",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               200,60,60,40,
                               hwnd, (HMENU) 4, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "4",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               280,60,60,40,
                               hwnd, (HMENU) 5, NULL, NULL);
        button = CreateWindow ("BUTTON",
                               "5",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               40,120,60,40,
                               hwnd, (HMENU) 6, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "6",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               120,120,60,40,
                               hwnd, (HMENU) 7, NULL, NULL);
        button = CreateWindow ("BUTTON",
                               "7",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               200,120,60,40,
                               hwnd, (HMENU) 8, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "8",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               280,120,60,40,
                               hwnd, (HMENU) 9, NULL, NULL);
        button = CreateWindow ("BUTTON",
                               "9",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               40,180,60,40,
                               hwnd, (HMENU) 10, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "0",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               120,180,60,40,
                               hwnd,(HMENU) 11, NULL, NULL);

        button = CreateWindow ("BUTTON",
                               "+",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               200,180,60,40,
                               hwnd, (HMENU) 12, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "-",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               280,180,60,40,
                               hwnd, (HMENU) 13, NULL, NULL);

        button = CreateWindow ("BUTTON",
                               "x",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               40,240,60,40,
                               hwnd, (HMENU) 14, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "/",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               120,240,60,40,
                               hwnd, (HMENU) 15, NULL, NULL);

        button = CreateWindow ("BUTTON",
                               "c",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               200,240,60,40,
                               hwnd, (HMENU) 16, NULL, NULL);

         button = CreateWindow ("BUTTON",
                               "=",
                               WS_BORDER | WS_CHILD | WS_VISIBLE,
                               280,240,60,40,
                               hwnd, (HMENU) 17, NULL, NULL);
                               break;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case 2:
                    Szoveg=Szoveg+"1";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 3:
                    Szoveg=Szoveg+"2";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 4:
                    Szoveg=Szoveg+"3";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 5:
                    Szoveg=Szoveg+"4";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 6:
                    Szoveg=Szoveg+"5";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 7:
                    Szoveg=Szoveg+"6";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 8:
                    Szoveg=Szoveg+"7";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 9:
                    Szoveg=Szoveg+"8";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 10:
                    Szoveg=Szoveg+"9";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 11:
                    Szoveg=Szoveg+"0";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 12:
                    Szoveg=Szoveg+"+";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 13:
                    Szoveg=Szoveg+"-";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 14:
                    Szoveg=Szoveg+"x";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 15:
                    Szoveg=Szoveg+"/";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 16:
                    Szoveg="";
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
                case 17:
                    int muveletszamlalo=0;
                    for(int i=0; i<Szoveg.length(); i++)
                    {
                        if(Szoveg[i]=='x' || Szoveg[i]=='/' || Szoveg[i]=='-' || Szoveg[i]=='+')
                        {
                            muveletszamlalo++;
                        }
                    }
                    if(muveletszamlalo==1)
                    {
                        bool found;
                        int foundone;
                        int i=1;
                        while(found!=true)
                        {
                            if(Szoveg[i]=='+' || Szoveg[i]=='-' || Szoveg[i]=='x' || Szoveg[i]=='/')
                            {
                                found=true;
                                foundone=i;
                            }
                            i++;
                        }
                        std::string fel1;
                        std::string fel2;
                        std::stringstream buffer3;
                        buffer3<<Szoveg[foundone];
                        std::string muvelet=buffer3.str();
                        for(int i=0; i<foundone; i++)
                        {
                            fel1=fel1+Szoveg[i];
                        }
                        for(int i=foundone+1; i<Szoveg.length(); i++)
                        {
                            fel2=fel2+Szoveg[i];
                        }
                        int fel1i=atoi(fel1.c_str());
                        int fel2i=atoi(fel2.c_str());
                        int eredmeny;
                        switch(muvelet[0])
                        {
                            case '+': eredmeny=fel1i+fel2i;
                                break;
                            case '-': eredmeny=fel1i-fel2i;
                                break;
                            case '/': eredmeny=fel1i/fel2i;
                                break;
                            case 'x': eredmeny=fel1i*fel2i;
                                break;
                        }
                        buffer.str("");
                        buffer<<eredmeny;
                        Szoveg=buffer.str();
                        SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    }
                    else
                    {
                        buffer<<muveletszamlalo;
                        Szoveg=buffer.str();
                    }
                    SetWindowText(textfield, TEXT(Szoveg.c_str()));
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
