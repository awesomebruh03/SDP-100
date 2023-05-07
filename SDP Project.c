#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ADD_TASK 1006007
#define resetB 404
#define savefile 707
//set timer ID
#define TIMER_ID_1 1
#define TIMER_ID_2 2
#define TIMER_ID_3 3
#define TIMER_ID_4 4
#define TIMER_ID_5 5
#define TIMER_ID_6 6
#define TIMER_ID_7 7
#define buttonstart1 101
#define buttonstart2 102
#define buttonstart3 103
#define buttonstart4 104
#define buttonstart5 105
#define buttonstart6 106
#define buttonstart7 107
//micro;e for stop button ;; buttonstop
#define buttonstop1 201
#define buttonstop2 202
#define buttonstop3 203
#define buttonstop4 204
#define buttonstop5 205
#define buttonstop6 206
#define buttonstop7 207
//copied from stopwatch
int h = 0, m = 0, s = 0, ms = 0;
int h1 = 0, m1 = 0, s1 = 0, ms1 = 0;
int h2 = 0, m2 = 0, s2 = 0, ms2 = 0;
int h3 = 0, m3 = 0, s3 = 0, ms3 = 0;
int h4 = 0, m4 = 0, s4 = 0, ms4 = 0;
int h5 = 0, m5 = 0, s5 = 0, ms5 = 0;
int h6 = 0, m6 = 0, s6 = 0, ms6 = 0;
BOOL b1Started = FALSE;
BOOL b2Started = FALSE;
BOOL b3Started = FALSE;
BOOL b4Started = FALSE;
BOOL b5Started = FALSE;
BOOL b6Started = FALSE;
BOOL b7Started = FALSE;
//save method
void file_read(HWND);
//
void AddMenu(HWND);
HMENU hmenu;
void Add_controle(HWND);
HMENU hcontrols;
void reset_scontrol(HWND);
HMENU hreset;
HWND hsave_button; //handle for save button
//handles for static and edit controls
HWND hedit1;
HWND hedit2;
//HWND hStatic[14];
HWND hStatic1;
HWND hStatic2;
HWND hStatic3;
HWND hStatic4;
HWND hStatic5;
HWND hStatic6;
HWND hStatic7;
HWND hStatic11;
HWND hStatic12;
HWND hStatic13;
HWND hStatic14;
HWND hStatic15;
HWND hStatic16;
HWND hStatic17;
//handle for buttons
HWND hBtnStart1;
HWND hBtnStart2;
HWND hBtnStart3;
HWND hBtnStart4;
HWND hBtnStart5;
HWND hBtnStart6;
HWND hBtnStart7;

HWND hBtnStop1;
HWND hBtnStop2;
HWND hBtnStop3;
HWND hBtnStop4;
HWND hBtnStop5;
HWND hBtnStop6;
HWND hBtnStop7;
//handle for reset button
HWND hBtnReset;


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = { 0 };

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"CronoTask";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc)) {
        return -1;
    }

    CreateWindowW(L"CronoTask", L"CronoTask",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 500, 500, NULL, NULL, NULL, NULL); //this create a primary window;

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

int currentStaticControl = 1;
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    wchar_t text[50];
    static char szTime[256];
    static char szTime1[256];
    static char szTime2[256];
    static char szTime3[256];
    static char szTime4[256];
    static char szTime5[256];
    static char szTime6[256];
    switch (msg) {
        	    case WM_COMMAND:
        	        switch (LOWORD(wp)){
        case savefile:
                printf("yamete kudasai");
                save_file(hWnd);
                break;
        case 6:                            //i have no idea how this part works, but somehow it works so i am not touching it
        if (LOWORD(wp) == 6) { // Check if the ADD TASK button is clicked
            GetWindowTextW(hedit1, text, 50);
            switch (currentStaticControl) {
            case 1:
                SetWindowTextW(hStatic1, text);
                break;
            case 2:
                SetWindowTextW(hStatic2, text);
                break;
            case 3:
                SetWindowTextW(hStatic3, text);
                break;
            case 4:
                SetWindowTextW(hStatic4, text);
                break;
            case 5:
                SetWindowTextW(hStatic5, text);
                break;
            case 6:
                SetWindowTextW(hStatic6, text);
                break;
            case 7:
                SetWindowTextW(hStatic7, text);
                break;
            default:
                break;
            }
            currentStaticControl++;
            if (currentStaticControl > 7) {
                currentStaticControl = 1; // Reset the counter if it exceeds the number of static controls
            }
        }
        break;
            case buttonstart1:
                        GetWindowTextW(hStatic1, text, 50);
                        if(strlen(text)>0){
                        b1Started = TRUE;
                        SetTimer(hWnd, TIMER_ID_1, 10, NULL);
                        EnableWindow(hBtnStart1, FALSE);
                        EnableWindow(hBtnStop1, TRUE);
                        }

            break;
            case buttonstart2:
                        GetWindowTextW(hStatic2, text, 50);
                        if(strlen(text)>0){
                        b2Started = TRUE;
                        SetTimer(hWnd, TIMER_ID_2, 10, NULL);
                        EnableWindow(hBtnStart2, FALSE);
                        EnableWindow(hBtnStop2, TRUE);
                        }
            break;
            case buttonstart3:
                        GetWindowTextW(hStatic3, text, 50);
                        if(strlen(text)>0){
                        b3Started = TRUE;
                        SetTimer(hWnd, TIMER_ID_3, 10, NULL);
                        EnableWindow(hBtnStart3, FALSE);
                        EnableWindow(hBtnStop3, TRUE);
                        }
            break;
            case buttonstart4:
                        GetWindowTextW(hStatic4, text, 50);
                        if(strlen(text)>0){
                        b4Started = TRUE;
                        SetTimer(hWnd, TIMER_ID_4, 10, NULL);
                        EnableWindow(hBtnStart4, FALSE);
                        EnableWindow(hBtnStop4, TRUE);
                        }
            break;
            case buttonstart5:
                        GetWindowTextW(hStatic5, text, 50);
                        if(strlen(text)>0){
                        b5Started = TRUE;
                        SetTimer(hWnd, TIMER_ID_5, 10, NULL);
                        EnableWindow(hBtnStart5, FALSE);
                        EnableWindow(hBtnStop5, TRUE);
                        }
            break;
            case buttonstart6:
                        GetWindowTextW(hStatic6, text, 50);
                        if(strlen(text)>0){
                        b6Started = TRUE;
                        SetTimer(hWnd, TIMER_ID_6, 10, NULL);
                        EnableWindow(hBtnStart6, FALSE);
                        EnableWindow(hBtnStop6, TRUE);
        	        }
            break;
            case buttonstart7:
                        GetWindowTextW(hStatic7, text, 50);
                        if(strlen(text)>0){
                        b7Started = TRUE;
                        SetTimer(hWnd, TIMER_ID_7, 10, NULL);
                        EnableWindow(hBtnStart7, FALSE);
                        EnableWindow(hBtnStop7, TRUE);
                        }
            break;

                break;
            case resetB:
                reset_scontrol(hWnd);
                EnableWindow(hBtnStart1, TRUE);
                EnableWindow(hBtnStop1, TRUE);
                EnableWindow(hBtnStart2, TRUE);
                EnableWindow(hBtnStop2, TRUE);
                EnableWindow(hBtnStart3, TRUE);
                EnableWindow(hBtnStop3, TRUE);
                EnableWindow(hBtnStart4, TRUE);
                EnableWindow(hBtnStop4, TRUE);
                EnableWindow(hBtnStart5, TRUE);
                EnableWindow(hBtnStop5, TRUE);
                EnableWindow(hBtnStart6, TRUE);
                EnableWindow(hBtnStop6, TRUE);
                EnableWindow(hBtnStart7, TRUE);
                EnableWindow(hBtnStop7, TRUE);
                break;
            case buttonstop1:
                b1Started = FALSE;
                KillTimer(hWnd, 1);
                EnableWindow(hBtnStart1, TRUE);
                EnableWindow(hBtnStop1, FALSE);
                break;
            case buttonstop2:
                b2Started = FALSE;
                KillTimer(hWnd, 1);
                EnableWindow(hBtnStart2, TRUE);
                EnableWindow(hBtnStop2, FALSE);

                break;
            case buttonstop3:
                b3Started = FALSE;
                KillTimer(hWnd, 1);
                EnableWindow(hBtnStart3, TRUE);
                EnableWindow(hBtnStop3, FALSE);

                break;
            case buttonstop4:
                b4Started = FALSE;
                KillTimer(hWnd, 1);
                EnableWindow(hBtnStart4, TRUE);
                EnableWindow(hBtnStop4, FALSE);

                break;
            case buttonstop5:
                b5Started = FALSE;
                KillTimer(hWnd, 1);
                EnableWindow(hBtnStart5, TRUE);
                EnableWindow(hBtnStop5, FALSE);

                break;
            case buttonstop6:
                b6Started = FALSE;
                KillTimer(hWnd, 1);
                EnableWindow(hBtnStart6, TRUE);
                EnableWindow(hBtnStop6, FALSE);

                break;
            case buttonstop7:
                b7Started = FALSE;
                KillTimer(hWnd, 1);
                EnableWindow(hBtnStart7, TRUE);
                EnableWindow(hBtnStop7, FALSE);
                break;
        	        }

        break;
    case WM_TIMER:
    // Handle the timer event
    if (b1Started && wp == TIMER_ID_1)
    {
        ms += 1;
        if (ms >= 100)
        {
            s += 1;
            ms = 0;
        }
        if (s >= 60)
        {
            m += 1;
            s = 0;
        }
        if (m >= 60)
        {
            h += 1;
            m = 0;
        }
        // Update the time display
        sprintf_s(szTime, sizeof(szTime), "%02d:%02d:%02d:%02d", h, m, s, ms);
        SetWindowText(hStatic11, szTime);
    }
    //break;

     if (b2Started && wp == TIMER_ID_2)
    {
        ms1 += 1;
        if (ms1 >= 100)
        {
            s1 += 1;
            ms1 = 0;
        }
        if (s1 >= 60)
        {
            m1 += 1;
            s1 = 0;
        }
        if (m1 >= 60)
        {
            h1 += 1;
            m1 = 0;
        }
        // Update the time display
        sprintf_s(szTime1, sizeof(szTime1), "%02d:%02d:%02d:%02d", h1, m1, s1, ms1);
        SetWindowText(hStatic12, szTime1);
    }
    if (b3Started && wp == TIMER_ID_3)
    {
        ms2 += 1;
        if (ms2 >= 100)
        {
            s2 += 1;
            ms2 = 0;
        }
        if (s2 >= 60)
        {
            m2 += 1;
            s2 = 0;
        }
        if (m2 >= 60)
        {
            h2 += 1;
            m2 = 0;
        }
        // Update the time display
        sprintf_s(szTime1, sizeof(szTime1), "%02d:%02d:%02d:%02d", h2, m2, s2, ms2);
        SetWindowText(hStatic13, szTime1);
    }
    if (b4Started && wp == TIMER_ID_4)
    {
        ms3 += 1;
        if (ms3 >= 100)
        {
            s3 += 1;
            ms3 = 0;
        }
        if (s3 >= 60)
        {
            m3 += 1;
            s3 = 0;
        }
        if (m3 >= 60)
        {
            h3 += 1;
            m3 = 0;
        }
        // Update the time display
        sprintf_s(szTime3, sizeof(szTime3), "%02d:%02d:%02d:%02d", h3, m3, s3, ms3);
        SetWindowText(hStatic14, szTime3);
    }
    if (b5Started && wp == TIMER_ID_5)
    {
        ms4 += 1;
        if (ms4 >= 100)
        {
            s4 += 1;
            ms4 = 0;
        }
        if (s4 >= 60)
        {
            m4 += 1;
            s4 = 0;
        }
        if (m4 >= 60)
        {
            h4 += 1;
            m4 = 0;
        }
        // Update the time display
        sprintf_s(szTime4, sizeof(szTime4), "%02d:%02d:%02d:%02d", h4, m4, s4, ms4);
        SetWindowText(hStatic15, szTime4);
    }
    if (b6Started && wp == TIMER_ID_6)
    {
        ms5 += 1;
        if (ms5 >= 100)
        {
            s5 += 1;
            ms5 = 0;
        }
        if (s5 >= 60)
        {
            m5 += 1;
            s5 = 0;
        }
        if (m5 >= 60)
        {
            h5 += 1;
            m5 = 0;
        }
        // Update the time display
        sprintf_s(szTime5, sizeof(szTime5), "%02d:%02d:%02d:%02d", h5, m5, s5, ms5);
        SetWindowText(hStatic16, szTime5);
    }
    if (b7Started && wp == TIMER_ID_7)
    {
        ms6 += 1;
        if (ms6 >= 100)
        {
            s6 += 1;
            ms6 = 0;
        }
        if (s6 >= 60)
        {
            m6 += 1;
            s6 = 0;
        }
        if (m6 >= 60)
        {
            h6 += 1;
            m6 = 0;
        }
        // Update the time display
        sprintf_s(szTime6, sizeof(szTime6), "%02d:%02d:%02d:%02d", h6, m6, s6, ms6);
        SetWindowText(hStatic17, szTime6);
    }
    break;

    case WM_CREATE:
        // call the function to add menu
       Add_save_button(hWnd);
        //call the function to add controls
        Add_controle(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }

    return 0;
}


void Add_save_button(HWND hWnd) {
    hmenu = CreateMenu();
    AppendMenu(hmenu, MF_STRING,savefile, "Save File");
    SetMenu(hWnd, hmenu);

}
void Add_controle(HWND hWnd) {
    hedit1 = CreateWindowW(L"Edit", L"ENTER TASK", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10, 8, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    //hedit2 = CreateWindowW(L"Edit", L"HR:MIN:SEC", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT | ES_MULTILINE | ES_AUTOHSCROLL, 350, 8, 100, 20, hWnd, (HMENU)5, NULL, NULL);
    //this is for static controls. this is for storing the task name from edit control. this section starts from here
    hStatic1 = CreateWindowW(L"static", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10,  50, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    hStatic2 = CreateWindowW(L"static", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10, 100, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    hStatic3 = CreateWindowW(L"static", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10, 150, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    hStatic4 = CreateWindowW(L"static", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10, 200, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    hStatic5 = CreateWindowW(L"static", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10, 250, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    hStatic6 = CreateWindowW(L"static", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10, 300, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    hStatic7 = CreateWindowW(L"static", L"", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 10, 350, 200, 25, hWnd, (HMENU)5, NULL, NULL);
    // to here
    // this is buttons. this section starts from here
               hBtnStart1=CreateWindowW(L"button", L"START", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 250, 50,  50, 25, hWnd, (HMENU)buttonstart1, NULL, NULL);
               hBtnStart2=CreateWindowW(L"button", L"START", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 250, 100, 50, 25, hWnd, (HMENU)buttonstart2, NULL, NULL);
               hBtnStart3=CreateWindowW(L"button", L"START", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 250, 150, 50, 25, hWnd, (HMENU)buttonstart3, NULL, NULL);
               hBtnStart4=CreateWindowW(L"button", L"START", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 250, 200, 50, 25, hWnd, (HMENU)buttonstart4, NULL, NULL);
               hBtnStart5=CreateWindowW(L"button", L"START", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 250, 250, 50, 25, hWnd, (HMENU)buttonstart5, NULL, NULL);
               hBtnStart6=CreateWindowW(L"button", L"START", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 250, 300, 50, 25, hWnd, (HMENU)buttonstart6, NULL, NULL);
               hBtnStart7=CreateWindowW(L"button", L"START", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 250, 350, 50, 25, hWnd, (HMENU)buttonstart7, NULL, NULL);
               //CreateWindowW(L"button", L"Deadline", WS_CHILD | WS_BORDER | WS_VISIBLE | BS_AUTOCHECKBOX | SS_LEFT,250, 8, 80, 25, hWnd, (HMENU)5, NULL, NULL);
               // to here
                // this is for time. this section starts from here
                hStatic11=CreateWindowW(L"static", L"00:00:00:00", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT , 315,  50, 80, 20, hWnd, NULL, NULL, NULL);
                hStatic12=CreateWindowW(L"static", L"00:00:00:00", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT , 315, 100, 80, 20, hWnd, NULL, NULL, NULL);
                hStatic13=CreateWindowW(L"static", L"00:00:00:00", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT , 315, 150, 80, 20, hWnd, NULL, NULL, NULL);
                hStatic14=CreateWindowW(L"static", L"00:00:00:00", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT , 315, 200, 80, 20, hWnd, NULL, NULL, NULL);
                hStatic15=CreateWindowW(L"static", L"00:00:00:00", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT , 315, 250, 80, 20, hWnd, NULL, NULL, NULL);
                hStatic16=CreateWindowW(L"static", L"00:00:00:00", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT , 315, 300, 80, 20, hWnd, NULL, NULL, NULL);
                hStatic17=CreateWindowW(L"static", L"00:00:00:00", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT , 315, 350, 80, 20, hWnd, NULL, NULL, NULL);
                // to here
                // i hate my life. why am i doing this to my self? i mean why? should have chosen something easer or better friends.
                CreateWindowW(L"button", L"ADD TASK", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT,125, 400, 200, 25, hWnd,(HMENU)6, NULL, NULL);
                //stop buttons
               hBtnStop1=CreateWindowW(L"button", L"STOP", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 422, 50,  50, 25, hWnd, (HMENU)buttonstop1, NULL, NULL);
               hBtnStop2=CreateWindowW(L"button", L"STOP", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 422, 100, 50, 25, hWnd, (HMENU)buttonstop2, NULL, NULL);
               hBtnStop3=CreateWindowW(L"button", L"STOP", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 422, 150, 50, 25, hWnd, (HMENU)buttonstop3, NULL, NULL);
               hBtnStop4=CreateWindowW(L"button", L"STOP", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 422, 200, 50, 25, hWnd, (HMENU)buttonstop4, NULL, NULL);
               hBtnStop5=CreateWindowW(L"button", L"STOP", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 422, 250, 50, 25, hWnd, (HMENU)buttonstop5, NULL, NULL);
               hBtnStop6=CreateWindowW(L"button", L"STOP", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 422, 300, 50, 25, hWnd, (HMENU)buttonstop6, NULL, NULL);
               hBtnStop7=CreateWindowW(L"button", L"STOP", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 422, 350, 50, 25, hWnd, (HMENU)buttonstop7, NULL, NULL);
               //reset button
               hBtnReset=CreateWindowW(L"button", L"reset", WS_CHILD | WS_BORDER | WS_VISIBLE | SS_LEFT, 330, 8, 50, 25, hWnd, (HMENU)resetB, NULL, NULL);
}
void reset_scontrol(HWND hWnd){
        static char szTim[256];
        h = 0, m = 0, s = 0, ms = 0; // reset button wont work properly if you don't initialize for all seven set
        h1 = 0, m1 = 0, s1 = 0, ms1 = 0;
        h2 = 0, m2 = 0, s2 = 0, ms2 = 0;
        h3 = 0, m3 = 0, s3 = 0, ms3 = 0;
        h4 = 0, m4 = 0, s4 = 0, ms4 = 0;
        h5 = 0, m5 = 0, s5 = 0, ms5 = 0;
        h6 = 0, m6 = 0, s6 = 0, ms6 = 0;
        sprintf_s(szTim, sizeof(szTim), "%02d:%02d:%02d:%02d", h, m, s, ms);
        SetWindowText(hStatic11, szTim);
        SetWindowText(hStatic12, szTim);
        SetWindowText(hStatic13, szTim);
        SetWindowText(hStatic14, szTim);
        SetWindowText(hStatic15, szTim);
        SetWindowText(hStatic16, szTim);
        SetWindowText(hStatic17, szTim);
}
void file_read(HWND hWnd){


}
void save_file(HWND hWnd){
    OPENFILENAME ofn;
    HANDLE hFile;
    DWORD dwBytesWritten;
    char buffer[1024];

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = malloc(MAX_PATH);
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_OVERWRITEPROMPT;

    // Get text from seven static controls and append to buffer
    GetDlgItemText(hWnd, hStatic1, buffer, sizeof(buffer));
    strcat(buffer, "\n"); // add newline between control text
    GetDlgItemText(hWnd, hStatic2, buffer + strlen(buffer), sizeof(buffer) - strlen(buffer));
    strcat(buffer, "\n");
    GetDlgItemText(hWnd, hStatic3, buffer + strlen(buffer), sizeof(buffer) - strlen(buffer));
    strcat(buffer, "\n");
    GetDlgItemText(hWnd, hStatic4, buffer + strlen(buffer), sizeof(buffer) - strlen(buffer));
    strcat(buffer, "\n");
    GetDlgItemText(hWnd, hStatic5, buffer + strlen(buffer), sizeof(buffer) - strlen(buffer));
    strcat(buffer, "\n");
    GetDlgItemText(hWnd, hStatic6, buffer + strlen(buffer), sizeof(buffer) - strlen(buffer));
    strcat(buffer, "\n");
    GetDlgItemText(hWnd, hStatic7, buffer + strlen(buffer), sizeof(buffer) - strlen(buffer));

    if (GetSaveFileName(&ofn)) {
        hFile = CreateFile(ofn.lpstrFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            printf("Error: Unable to create file!\n");
            return;
        }

        if (!WriteFile(hFile, buffer, strlen(buffer), &dwBytesWritten, NULL)) {
            printf("Error: Unable to write to file!\n");
            CloseHandle(hFile);
            return;
        }

        CloseHandle(hFile);

        printf("Data saved to file: %s\n", ofn.lpstrFile);
    }

    free(ofn.lpstrFile);
 }


