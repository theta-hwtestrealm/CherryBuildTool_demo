
#include <wx/wxprec.h>
#include <wx/scrolwin.h>
#include <wx/simplebook.h>

#include "main.hpp"

wxPanel* Pages::LogsPage(wxSimplebook* Simplebook) {
    wxScrolledWindow* scrollPage = new wxScrolledWindow(Simplebook, wxID_ANY);
    scrollPage->SetScrollRate(0, 10);
    wxBoxSizer* pageSizer = new wxBoxSizer(wxVERTICAL);
    pageSizer->Add(new wxStaticText(scrollPage, wxID_ANY, "--- START OF LOGS ---"), 0, wxALL, 10);

    for(int i = 1; i <= 50; ++i) {
        wxString logMsg = wxString::Format("Log Entry #%d: Testimng...", i);
        pageSizer->Add(new wxStaticText(scrollPage, wxID_ANY, logMsg), 0, wxLEFT | wxRIGHT | wxBOTTOM, 10);
    }

    scrollPage->SetSizer(pageSizer);

    return scrollPage;
}


// wxPanel* page1 = new wxPanel(Simplebook);
// new wxStaticText(page1, wxID_ANY, "THIS IS PAGE ONE", wxPoint(20, 20));