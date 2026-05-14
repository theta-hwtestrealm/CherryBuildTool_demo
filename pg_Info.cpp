
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "main.hpp"

wxPanel* Pages::InfoPage(wxSimplebook* Simplebook) {
    wxPanel* page = new wxPanel(Simplebook);
    new wxStaticText(page, wxID_ANY, "INFORMATION PAGE", wxPoint(20, 20));

    return page;
}