#include <Windows.h>
#include <stdio.h>

// Dialog box procedure
BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        // Initialize the dialog box controls
        SetDlgItemInt(hwndDlg, IDC_EDIT1, 0, FALSE);
        SetDlgItemInt(hwndDlg, IDC_EDIT2, 0, FALSE);
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_START:
            // Get the user input from the dialog box
            int hours = GetDlgItemInt(hwndDlg, IDC_EDIT1, NULL, FALSE);
            int minutes = GetDlgItemInt(hwndDlg, IDC_EDIT2, NULL, FALSE);
            int seconds = hours * 3600 + minutes * 60;

            // Create a timer with the specified interval
            SetTimer(hwndDlg, IDT_TIMER1, seconds * 1000, NULL);

            // Disable the start button and enable the stop button
            EnableWindow(GetDlgItem(hwndDlg, IDC_START), FALSE);
            EnableWindow(GetDlgItem(hwndDlg, IDC_STOP), TRUE);
            return TRUE;

        case IDC_STOP:
            // Stop the timer
            KillTimer(hwndDlg, IDT_TIMER1);

            // Enable the start button and disable the stop button
            EnableWindow(GetDlgItem(hwndDlg, IDC_START), TRUE);
            EnableWindow(GetDlgItem(hwndDlg, IDC_STOP), FALSE);
            return TRUE;

        case IDCANCEL:
            // Close the dialog box
            EndDialog(hwndDlg, 0);
            return TRUE;
        }
        break;

    case WM_CLOSE:
        // Close the dialog box
        EndDialog(hwndDlg, 0);
        return TRUE;
    }

    return FALSE;
}

// Timer callback function
VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    // This function will be called when the timer interval has elapsed
    MessageBox(hwnd, "Timer tick!", "Timer", MB_OK | MB_ICONINFORMATION);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Create the dialog box
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);

    return 0;
}
