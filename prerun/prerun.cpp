#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/stdpaths.h>
#include <wx/filename.h>

#include <cJSON.h>


wxString exeName = "CherryRa1n";

wxString getScriptDir();
wxString dirExists(wxString fromRoot, wxString subDir);
wxString verifyFile(wxString fromRoot, wxString fileName);
wxString panicVerifyFile(wxString fromRoot, wxString fileName);
wxLongLong verifyVolumeSize(wxString root);
wxString FormatBytes(wxLongLong bytes);

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

#ifdef __WINDOWS__
    exeName = exeName + ".exe"
#endif


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    //dire checks

    wxString root = getScriptDir();
    wxString config = panicVerifyFile(root,"config.json");
    wxString mainexec =  panicVerifyFile("root", exeName);
    panicVerifyFile(root, "userdata"); //as a general rule i wont touch user data
    panicVerifyFile(root, "Pages");
    panicVerifyFile(root, "tools");
    panicVerifyFile(root, "bin");
    
    //init
    
    wxString RepairUpdateWizard = verifyFile(root, "Updater");

    bool checkUpdates;
    wxLongLong recommendedFree;
    wxLongLong currentFree = verifyVolumeSize(root);

    wxFile file(config, wxFile::read);
    if (file.IsOpened()) {
        wxString content;
        file.ReadAll(&content);

        cJSON *cj = cJSON_Parse(content.mb_str());
        if (cj) {
            cJSON *cu = cJSON_GetObjectItemCaseSensitive(cj, "checkUpdates");
            checkUpdates = cJSON_IsBool(cu) ? cJSON_IsTrue(cu) : false;

            cJSON *rf = cJSON_GetObjectItemCaseSensitive(cj, "bytesRecommendedFree");
            if (cJSON_IsNumber(rf)) {
                recommendedFree = (long long)rf->valuedouble;
            }

            cJSON_Delete(cj);
        }
    }

    // other checks

    if (recommendedFree > currentFree) {
        wxString spaceNeeded = FormatBytes(recommendedFree - currentFree);
        wxString spacetext = ("It is recommended to have [" + spaceNeeded + "] available");
        wxMessageBox(spacetext, "Low Storage", wxOK | wxICON_INFORMATION);
    }

    // repair wizard?

    wxExecute(mainexec, wxEXEC_ASYNC);
    wxExit();

    return true;
}


wxString getScriptDir() {
    wxString exePath = wxStandardPaths::Get().GetExecutablePath();
    
    wxFileName fn(exePath);
    return fn.GetPathWithSep(); 
}

wxString dirExists(wxString fromRoot, wxString subDir) {
    wxFileName fn;
    fn.AssignDir(fromRoot);
    fn.AppendDir(subDir);

    if (wxDirExists(fn.GetPath())) {
        return fn.GetPathWithSep();
    }
    return "";
}

wxString verifyFile(wxString fromRoot, wxString fileName) {
    wxFileName fn;
    fn.AssignDir(fromRoot);
    fn.SetFullName(fileName);

    if (fn.verifyFile()) {
        return fn.GetFullPath();
    }
    return "";
}

wxString panicVerifyFile(wxString fromRoot, wxString fileName) {
    bool result = verifyFile(wxString fromRoot, wxString fileName);

    if (result == "") {
        wxMessageBox("Fatal! the app is damaged and must be reinstalled",
                 fileName, wxOK | wxICON_INFORMATION);
        wxExit();
    }
}

wxLongLong verifyVolumeSize(wxString root) {
    wxLongLong totalSpace, freeSpace;
    wxFileName fn = wxFileName::DirName(root);
    wxString drive = fn.GetVolume(); 

    if (wxGetDiskSpace(root, &totalSpace, &freeSpace)) {
        return freeSpace;
    }

    return 0;
}

wxString FormatBytes(wxLongLong bytes) {
    double size = bytes.ToDouble();
    const char* units[] = { "B", "KB", "MB", "GB", "TB" };
    int i = 0;

    while (size >= 1024 && i < 3) {
        size /= 1024;
        i++;
    }

    return i == 0 
        ? wxString::Format("%lld B", bytes.GetValue()) 
        : wxString::Format("%.1f %s", size, units[i]);
}