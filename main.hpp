#pragma once

class wxPanel;
class wxSimplebook;
class wxString;

class Pages {
public:
    wxPanel* DevicePage(wxSimplebook* Simplebook);
    wxPanel* JailbreakPage(wxSimplebook* Simplebook);
    wxPanel* UtilityPage(wxSimplebook* Simplebook);
    wxPanel* LogsPage(wxSimplebook* Simplebook);
    wxPanel* InfoPage(wxSimplebook* Simplebook);
};

class Events {
public:
    void OnLogLog(wxString Msg)
};

Pages::DevicePage(wxSimplebook* Simplebook) {
    wxPanel* page = new wxPanel(Simplebook);
    return page;
}

Pages::JailbreakPage(wxSimplebook* Simplebook) {
    wxPanel* page = new wxPanel(Simplebook);
    return page;
}

Pages::UtilityPage(wxSimplebook* Simplebook) {
    wxPanel* page = new wxPanel(Simplebook);
    return page;
}