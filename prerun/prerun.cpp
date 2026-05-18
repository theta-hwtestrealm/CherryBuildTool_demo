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
    
    //init
    
    wxString RepairUpdateWizard = verifyFile(root, "Updater");

    bool data_pages = !(dirExists(root, "Pages") == "")
    bool data_tools = !(dirExists(root, "tools") == "")
    bool data_bin = !(dirExists(root, "bin") == "")

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

    // damage checks

    if (recommendedFree > currentFree) {
        wxString spaceNeeded = FormatBytes(recommendedFree - currentFree);
        wxString spacetext = ("It is recommended to free [" + spaceNeeded + "] to use this applications functions");
        wxMessageBox(spacetext, LABEL, wxOK | wxICON_INFORMATION);
    }

    if (!data_pages || !data_tools || !data_bin) {
        wxString spacetext = ("The installation is missing files and the repair wizard will be opened if available");
        wxMessageBox(spacetext, LABEL, wxOK | wxICON_INFORMATION);
        if (RepairUpdateWizard != "") {
            wxExecute(RepairUpdateWizard, wxEXEC_ASYNC);
            wxExit();
        }
    }

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
        wxMessageBox(fileName + " Panic! [damaged installation]",
                 LABEL, wxOK | wxICON_INFORMATION);
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