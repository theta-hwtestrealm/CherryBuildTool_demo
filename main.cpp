#include <wx/wxprec.h>
#include <wx/notebook.h>
#include <wx/button.h>
 
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

    void OnUnimplemented(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);

    wxNotebook* notebook;
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


    // create ui skeleton
    notebook = new wxNotebook(mainPanel, wxID_ANY);
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    
    // create upper selector
    wxBoxSizer* topBarSizer = new wxBoxSizer(wxHORIZONTAL);

    wxButton* btn1 = new wxButton(panel, wxID_ANY, "Device");
    wxButton* btn2 = new wxButton(panel, wxID_ANY, "Jailbreak");
    wxButton* btn3 = new wxButton(panel, wxID_ANY, "Utility");
    wxButton* btn4 = new wxButton(panel, wxID_ANY, "Logs");
    wxButton* btn5 = new wxButton(panel, wxID_ANY, "Info");

    topBarSizer->AddStretchSpacer(1); // LSPACE
    topBarSizer->Add(btn1, 0, wxALL | wxALIGN_TOP, 5);
    topBarSizer->Add(btn2, 0, wxALL | wxALIGN_TOP, 5);
    topBarSizer->Add(btn3, 0, wxALL | wxALIGN_TOP, 5);
    topBarSizer->Add(btn4, 0, wxALL | wxALIGN_TOP, 5);
    topBarSizer->Add(btn5, 0, wxALL | wxALIGN_TOP, 5);
    topBarSizer->AddStretchSpacer(1); // RSPACE

    mainSizer->Add(topBarSizer, 0, wxEXPAND | wxALL, 5);
    mainSizer->Add(text, 1, wxEXPAND | wxALL, 10);


    panel->SetSizer(mainSizer);



    // bindings
    
    Bind(wxEVT_MENU, &MyFrame::OnShowHelp, this, ID_Help);

    Bind(wxEVT_MENU, &MyFrame::OnShowDevice_page, this, PAGE_Device);
    Bind(wxEVT_MENU, &MyFrame::OnShowJailbreak_page, this, PAGE_Jailbreak);
    Bind(wxEVT_MENU, &MyFrame::OnShowUtility_page, this, PAGE_Utility);
    Bind(wxEVT_MENU, &MyFrame::OnShowLogs_page, this, PAGE_Logs);
    Bind(wxEVT_MENU, &MyFrame::OnShowInfo_page, this, PAGE_Info);

    btn1->Bind(wxEVT_BUTTON, &MyFrame::OnShowDevice_page, this);
    btn2->Bind(wxEVT_BUTTON, &MyFrame::OnShowJailbreak_page, this);
    btn3->Bind(wxEVT_BUTTON, &MyFrame::OnShowUtility_page, this);
    btn4->Bind(wxEVT_BUTTON, &MyFrame::OnShowLogs_page, this);
    btn5->Bind(wxEVT_BUTTON, &MyFrame::OnShowInfo_page, this);

    Bind(wxEVT_MENU, &MyFrame::OnUnimplemented, this, ID_Theming);

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
    notebook->SetSelection(0);
    wxLogMessage("Device info");
}

void MyFrame::OnShowJailbreak_page(wxCommandEvent& event)
{
    notebook->SetSelection(1);
    wxLogMessage("jailbreak info");
}

void MyFrame::OnShowUtility_page(wxCommandEvent& event)
{
    notebook->SetSelection(2);
    wxLogMessage("utility info");
}

void MyFrame::OnShowLogs_page(wxCommandEvent& event)
{
    notebook->SetSelection(3);
    wxLogMessage("logs");
}

void MyFrame::OnShowInfo_page(wxCommandEvent& event)
{
    notebook->SetSelection(4);
    wxLogMessage("info info");
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