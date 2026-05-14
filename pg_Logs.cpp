
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/simplebook.h>
#include <wx/html/htmlwin.h>

#include "main.hpp"

wxBoxSizer* pageSizer;

wxPanel* Pages::LogsPage(wxSimplebook* Simplebook) {
    wxScrolledWindow* scrollPage = new wxScrolledWindow(Simplebook, wxID_ANY);
    scrollPage->SetScrollRate(0, 10);
    pageSizer = new wxBoxSizer(wxVERTICAL);
    //pageSizer->Add(new wxStaticText(scrollPage, wxID_ANY, "--- START OF LOGS ---"), 0, wxALL, 10);

    wxHtmlWindow* newHTML = new wxHtmlWindow(scrollPage, wxID_ANY);
    const wxString source = "<b>--- START OF LOGS ---</b>";
    newHTML->AppendToPage(&source);
    pageSizer->Add(newHTML, 0, wxALL, 10);

    for(int i = 1; i <= 50; ++i) {
        wxString logMsg = wxString::Format("Log Entry #%d: Testimng...", i);
        pageSizer->Add(new wxStaticText(scrollPage, wxID_ANY, logMsg), 0, wxLEFT | wxRIGHT | wxBOTTOM, 10);
    }

    scrollPage->SetSizer(pageSizer);

    return scrollPage;
}

void Events::OnLogLog(wxString Msg) {
    wxHtmlWindow* newHTML = new wxHtmlWindow(scrollPage, wxID_ANY);
    const wxString source = Msg;
    newHTML->AppendToPage(&source);
    pageSizer->Add(newHTML, 0, wxALL, 10);
}

wxPanel* Pages::DevicePage(wxSimplebook* Simplebook) {
    wxPanel* page = new wxPanel(Simplebook);
    return page;
}

wxPanel* Pages::JailbreakPage(wxSimplebook* Simplebook) {
    wxPanel* page = new wxPanel(Simplebook);
    return page;
}

wxPanel* Pages::UtilityPage(wxSimplebook* Simplebook) {
    wxPanel* page = new wxPanel(Simplebook);
    return page;
}


// wxPanel* page1 = new wxPanel(Simplebook);
// new wxStaticText(page1, wxID_ANY, "THIS IS PAGE ONE", wxPoint(20, 20));