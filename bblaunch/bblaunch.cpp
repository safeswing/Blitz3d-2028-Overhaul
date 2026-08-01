#include <windows.h>
#include <string>

using std::string;

// Static Error Messages
static const char* md_err = "Your desktop must be in high-colour mode (at least 16-bit) to use Blitz Basic.\n\n"
"You can change your display settings from the Control Panel.";

// Converts Win32 API system error numbers into human-readable text
static string getSystemErrorMessage(DWORD errorCode) {
    if (errorCode == 0) return "No system error reported.";

    LPSTR messageBuffer = nullptr;
    size_t size = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR)&messageBuffer,
        0,
        NULL
    );

    string message = messageBuffer ? string(messageBuffer, size) : "Unknown system error.";
    LocalFree(messageBuffer);
    return message;
}

// Display error modal with custom error code format
static void fail(const string& customErrorCode, const string& description) {
    string fullMsg = "Blitz Basic Launcher Error\n\n" +
        string("Error Code: ") + customErrorCode + "\n" +
        "Details: " + description;

    ::MessageBoxA(0, fullMsg.c_str(), "Blitz Basic Error", MB_SETFOREGROUND | MB_TOPMOST | MB_ICONERROR);
    ExitProcess(-1);
}

static string getAppDir() {
    char buff[MAX_PATH];
    if (GetModuleFileNameA(0, buff, MAX_PATH)) {
        string t = buff;
        int n = t.find_last_of('\\');
        if (n != string::npos) t = t.substr(0, n);
        return t;
    }
    return "";
}

static int desktopDepth() {
    HDC hdc = GetDC(GetDesktopWindow());
    int depth = GetDeviceCaps(hdc, BITSPIXEL);
    ReleaseDC(GetDesktopWindow(), hdc);
    return depth;
}

int _stdcall WinMain(HINSTANCE inst, HINSTANCE prev, char* cmd, int show) {

    // Check display color depth
    if (desktopDepth() < 16) {
        fail("ERR_0x5X95_01", md_err);
    }

    // Determine current directory
    string appDir = getAppDir();
    if (appDir.empty()) {
        fail("ERR_0x5X95_02", "Failed to resolve application root directory.");
    }

    // Set environment variable and working path
    putenv(("blitzpath=" + appDir).c_str());
    if (!SetCurrentDirectoryA(appDir.c_str())) {
        DWORD sysErr = GetLastError();
        fail("ERR_0x5X95_03", "Could not set working directory to: " + appDir + "\nSystem Message: " + getSystemErrorMessage(sysErr));
    }

    // Target executable path
    string idePath = appDir + "\\bin\\ide.exe";
    string commandLine = idePath + " " + cmd;

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    // Launch the Blitz IDE
    if (!CreateProcessA(0, (char*)commandLine.c_str(), 0, 0, 0, 0, 0, 0, &si, &pi)) {
        DWORD sysErr = GetLastError();
        string errDetails = "Failed to launch main IDE executable.\n" +
            string("Target Path: ") + idePath + "\n" +
            "System Error (" + std::to_string(sysErr) + "): " + getSystemErrorMessage(sysErr);

        fail("ERR_0x5X95_04", errDetails);
    }

    // Wait for Blitz Basic to initialize before terminating launcher
    WaitForInputIdle(pi.hProcess, INFINITE);

    // Clean up handle allocations
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}