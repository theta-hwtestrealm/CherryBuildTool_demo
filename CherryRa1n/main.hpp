#pragma once

class wxPanel;
class wxSimplebook;
class wxString;

class Pages {
public:
    static wxPanel* DevicePage(wxSimplebook* Simplebook);
    static wxPanel* JailbreakPage(wxSimplebook* Simplebook);
    static wxPanel* UtilityPage(wxSimplebook* Simplebook);
    static wxPanel* LogsPage(wxSimplebook* Simplebook);
    static wxPanel* InfoPage(wxSimplebook* Simplebook);
};

class Events {
public:
    static void OnLogLog(wxString Msg);
};

