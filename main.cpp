#include <wx/wxprec.h>
#include <wx/artprov.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

const wxString LABEL = "Cherryra1n";
const wxString VER = "0.0";

//test
 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class MyFrame : public wxFrame
{
public:
    MyFrame();
 
private:
    void OnShowHelp(wxCommandEvent& event);

    void OnShowDevice_page(wxCommandEvent& event);
    void OnShowJailbreak_page(wxCommandEvent& event);
    void OnShowUtility_page(wxCommandEvent& event);
    void OnShowLogs_page(wxCommandEvent& event);
    void OnShowInfo_page(wxCommandEvent& event);

    void OnShowExtras(wxCommandEvent& event);

    void OnUnimplemented(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
};
 
enum
{
    ID_Help = 1,
    
    PAGE_Device,
    PAGE_Jailbreak,
    PAGE_Utility,
    PAGE_Logs,
    PAGE_Info,

    ID_Theming,

    ID_Test1,
    ID_Test2,
    ID_Test3
};
 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
 
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, (LABEL + " V" + VER)) //set topmost text
{

    // Create "Main/Navigation menu" (alternative navigation to gui buttons)
    wxMenu *mainMenu = new wxMenu;
    mainMenu->Append(ID_Help, "&Help\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    mainMenu->AppendSeparator();
    
    // Create "Extra Menu" (theming, settings, more)
    wxMenu *extraMenu = new wxMenu;
    extraMenu->Append(ID_Help, "&Help\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    extraMenu->AppendSeparator();

    // "Main/Navigation menu" main buttons

    mainMenu->Append(PAGE_Device, "&Device\tCtrl-H",
                     "Device stats");

    mainMenu->Append(PAGE_Jailbreak, "&Device\tCtrl-H",
                     "Main Jailbreak Page");

    mainMenu->Append(PAGE_Utility, "&Utilities\tCtrl-H",
                     "Other tools");

    mainMenu->Append(PAGE_Logs, "&Logs\tCtrl-H",
                     "Debug");

    // mainMenu->Append(PAGE_Info, "&Info\tCtrl-H",
    //                  "More info");

    // "Main/Navigation menu" end buttons
    
    mainMenu->AppendSeparator();
    mainMenu->Append(wxID_EXIT);

    // "Extra Menu" buttons

    extraMenu->Append(ID_Theming, "&Theming\tCtrl-H",
                     "Themes");

    // Set Topbar
    wxMenuBar *topBar = new wxMenuBar;
    topBar->Append(mainMenu, "&Menu");
    topBar->Append(extraMenu, "&Other");
    SetMenuBar( topBar );
 
    CreateStatusBar();
    //SetStatusText("wxWidgets program");
    
    Bind(wxEVT_MENU, &MyFrame::OnShowHelp, this, ID_Help);

    Bind(wxEVT_MENU, &MyFrame::OnShowDevice_page, this, PAGE_Device);
    Bind(wxEVT_MENU, &MyFrame::OnShowJailbreak_page, this, PAGE_Jailbreak);
    Bind(wxEVT_MENU, &MyFrame::OnShowUtility_page, this, PAGE_Utility);
    Bind(wxEVT_MENU, &MyFrame::OnShowLogs_page, this, PAGE_Logs);
    Bind(wxEVT_MENU, &MyFrame::OnShowInfo_page, this, PAGE_Info);

    Bind(wxEVT_MENU, &MyFrame::OnShowExtras, this, ID_Theming);

    Bind(wxEVT_MENU, &MyFrame::OnUnimplemented, this, ID_Test1);
    Bind(wxEVT_MENU, &MyFrame::OnUnimplemented, this, ID_Test2);
    Bind(wxEVT_MENU, &MyFrame::OnUnimplemented, this, ID_Test3);

    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnShowHelp(wxCommandEvent& event)
{
    wxMessageBox("[Giving Help]",
                 LABEL, wxOK | wxICON_INFORMATION);
}



void MyFrame::OnShowDevice_page(wxCommandEvent& event)
{
    wxLogMessage("Device info");
}

void MyFrame::OnShowJailbreak_page(wxCommandEvent& event)
{
    wxLogMessage("jailbreak info");
}

void MyFrame::OnShowUtility_page(wxCommandEvent& event)
{
    wxLogMessage("utiliyu info");
}

void MyFrame::OnShowLogs_page(wxCommandEvent& event)
{
    wxLogMessage("logs");
}

void MyFrame::OnShowInfo_page(wxCommandEvent& event)
{
    wxLogMessage("info info");
}


 
void MyFrame::OnShowExtras(wxCommandEvent& event)
{
    wxLogMessage("Showing extra theming utilities");

    wxToolBar* toolbar = CreateToolBar();
    toolbar->AddTool(ID_Test1, "New", wxArtProvider::GetBitmap(wxART_NEW));
    toolbar->AddTool(ID_Test2, "Open", wxArtProvider::GetBitmap(wxART_FILE_OPEN));
    
    toolbar->AddSeparator();
    toolbar->AddTool(ID_Test3, "Exit", wxArtProvider::GetBitmap(wxART_QUIT));
    toolbar->Realize();
}

void MyFrame::OnUnimplemented(wxCommandEvent& event)
{
    wxMessageBox("Unimplemented feature.",
                 LABEL, wxOK | wxICON_INFORMATION);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("[INSERT link to software info]",
                 LABEL, wxOK | wxICON_INFORMATION);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}