/**
 * Copyright (c) 2020 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include <locale>
#include <codecvt>
#include <iostream>
#include <fstream>

#include "stdafx.h"
#include <AK/Tools/Common/AkAssert.h>
#include <AK/Tools/Common/AkFNVHash.h>
#include <libnyquist/WavDecoder.h>
#include <libnyquist/WavEncoder.h>

#include "Hv_windGen_WwiseAuthoringPlugin.h"
#include "Hv_windGen_WwiseResource.h"
#include "Hv_windGen_WwisePluginIDs.h"

DEFINE_PLUGIN_REGISTER_HOOK

/** Table of display name resources (one for each property). */
struct DisplayNameInfo {
  LPCWSTR wszPropName;
  UINT uiDisplayName;
};

static DisplayNameInfo g_DisplayNames[] = {
  { L"q_branches_whistle", IDS_HV_PARAM_Q_BRANCHES_WHISTLE },
  { L"vol_branches", IDS_HV_PARAM_VOL_BRANCHES },
  { L"vol_buildings", IDS_HV_PARAM_VOL_BUILDINGS },
  { L"vol_doorways", IDS_HV_PARAM_VOL_DOORWAYS },
  { L"vol_leaves", IDS_HV_PARAM_VOL_LEAVES },
  { L"vol_master", IDS_HV_PARAM_VOL_MASTER },
  { L"wind_intensity", IDS_HV_PARAM_WIND_INTENSITY },
  { NULL, NULL }
};

// These IDs must be the same as those specified in the plug-in's XML definition file.
// Note that there are restrictions on the values you can use for CompanyID, and PluginID
// must be unique for the specified CompanyID. Furthermore, these IDs are persisted
// in project files. NEVER CHANGE THEM or existing projects will not recognize this Plug-in.
// Be sure to read the SDK documentation regarding Plug-ins XML definition files.
const short Hv_windGen_WwiseAuthoringPlugin::CompanyID = HV_COMPANY_ID;
const short Hv_windGen_WwiseAuthoringPlugin::PluginID = HV_WINDGEN_PLUGIN_ID;

Hv_windGen_WwiseAuthoringPlugin::Hv_windGen_WwiseAuthoringPlugin(AkUInt16 in_idPlugin) {
  m_pObjectMedia = nullptr;
  m_pPSet = nullptr;
  m_hwndPropView = nullptr;
  m_hwndObjPane = nullptr;
  m_idDialogBig = IDD_HV_WINDGEN_PLUGIN_BIG;
  m_idDialogSmall = IDD_HV_WINDGEN_PLUGIN_SMALL;
}

void Hv_windGen_WwiseAuthoringPlugin::Destroy() {
  delete this;
}

AK::Wwise::IPluginMediaConverter* Hv_windGen_WwiseAuthoringPlugin::GetPluginMediaConverterInterface() {
  return this;
}

AK::Wwise::ConversionResult Hv_windGen_WwiseAuthoringPlugin::ConvertFile(const GUID & in_guidPlatform,
    const BasePlatformID &in_basePlatform, LPCWSTR in_szSourceFile, LPCWSTR in_szDestFile,
    AkUInt32 in_uSampleRate, AkUInt32 in_uBlockLength, AK::Wwise::IProgress* in_pProgress,
    AK::Wwise::IWriteString* io_pError) {

  if (wcslen(in_szSourceFile) > 0) {
    // convert input file to 32bit floating point wav
    nqr::NyquistIO loader;
    std::shared_ptr<nqr::AudioData> fileData = std::make_shared<nqr::AudioData>();
    std::string inPath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(in_szSourceFile);
    loader.Load(fileData.get(), inPath);

    std::string outPath = std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(in_szDestFile);
    nqr::WavEncoder::WriteFile({ 1, nqr::PCM_FLT, nqr::DITHER_NONE }, fileData.get(), outPath);
  } else {
    // Note(joe): because we create dummy media sources for the patch tables the input file here doesn't exist
    // but we still need to create a dummy output file to avoid errors
    std::ofstream outfile(in_szDestFile);
    outfile.close();
  }
  return AK::Wwise::ConversionSuccess;
}

ULONG Hv_windGen_WwiseAuthoringPlugin::GetCurrentConversionSettingsHash(const GUID & in_guidPlatform,
    AkUInt32 in_uSampleRate, AkUInt32 in_uBlockLength) {
  AK::FNVHash32 hashFunc;

  // Generate a Hash from effect parameters that have an influence on the conversion
  // Take the source file name
  CString szInputFileName;
  m_pObjectMedia->GetMediaSourceFileName(szInputFileName.GetBuffer(_MAX_PATH), _MAX_PATH);
  szInputFileName.ReleaseBuffer();
  szInputFileName.MakeLower();
  return hashFunc.Compute((unsigned char *) (LPCTSTR) szInputFileName, szInputFileName.GetLength()*sizeof(TCHAR));
}

void Hv_windGen_WwiseAuthoringPlugin::SetPluginPropertySet(AK::Wwise::IPluginPropertySet *in_pPSet) {
  m_pPSet = in_pPSet;
}

void Hv_windGen_WwiseAuthoringPlugin::InitToDefault() {
  
}

void Hv_windGen_WwiseAuthoringPlugin::SetPluginObjectMedia(AK::Wwise::IPluginObjectMedia *in_pObjectMedia) {
  m_pObjectMedia = in_pObjectMedia;
}

void Hv_windGen_WwiseAuthoringPlugin::NotifyPluginMediaChanged() {
  m_pPSet->NotifyInternalDataChanged(AK::IAkPluginParam::ALL_PLUGIN_DATA_ID);
}

HINSTANCE Hv_windGen_WwiseAuthoringPlugin::GetResourceHandle() const {
  return AfxGetStaticModuleState()->m_hCurrentResourceHandle;
}

bool Hv_windGen_WwiseAuthoringPlugin::GetDialog(eDialog in_eDialog,
    UINT &out_uiDialogID, AK::Wwise::PopulateTableItem *&out_pTable) const {
  // Determine what dialog just get called and set the property names to
  // UI control binding populated table.
  CComVariant varProp;

  switch (in_eDialog) {
    case SettingsDialog: {
      out_uiDialogID = m_idDialogBig;
      out_pTable = nullptr;
      return true;
    }
    case ContentsEditorDialog: {
      out_uiDialogID = m_idDialogSmall;
      out_pTable = nullptr;
      return true;
    }
    default: return false;
  }
}

bool Hv_windGen_WwiseAuthoringPlugin::WindowProc(eDialog in_eDialog,
    HWND in_hWnd, UINT in_message, WPARAM in_wParam, LPARAM in_lParam,
    LRESULT &out_lResult) {
  // Standard window function, user can intercept what ever message that is
  // of interest to him to implement UI behavior.
  switch (in_message) {
    case WM_INITDIALOG: {
      if (in_eDialog == ContentsEditorDialog) {
        m_hwndObjPane = in_hWnd;
      }
      else if (in_eDialog == SettingsDialog) {
        m_hwndPropView = in_hWnd;

        
      }
      break;
    }

    

    case WM_DESTROY: {
      if (in_eDialog == SettingsDialog) {
        m_hwndPropView = nullptr;
      } else if ( in_eDialog == ContentsEditorDialog ) {
        m_hwndObjPane = nullptr;
      }
      break;
    }

    // Catch window command actions (regardless if it is object pane or property
    // view) to enable/disable controls
    case WM_COMMAND: {
      break;
    }

    case WM_ENABLE: {
      // Enable/Disable all child controls
      HWND hWnd = ::GetWindow(in_hWnd, GW_CHILD);
      while(hWnd) {
        ::EnableWindow(hWnd, in_wParam == TRUE);
        hWnd = ::GetWindow(hWnd, GW_HWNDNEXT);
      }
      return true;
    }
  }
  out_lResult = 0;
  return false;
}

// Store current plugin settings into banks when asked to.
bool Hv_windGen_WwiseAuthoringPlugin::GetBankParameters(const GUID &in_guidPlatform,
    AK::Wwise::IWriteData *in_pDataWriter) const {
  CComVariant varProp;
  m_pPSet->GetValue(in_guidPlatform, szHv_windGen_Param_q_branches_whistle, varProp);
  in_pDataWriter->WriteReal32(varProp.fltVal);
  m_pPSet->GetValue(in_guidPlatform, szHv_windGen_Param_vol_branches, varProp);
  in_pDataWriter->WriteReal32(varProp.fltVal);
  m_pPSet->GetValue(in_guidPlatform, szHv_windGen_Param_vol_buildings, varProp);
  in_pDataWriter->WriteReal32(varProp.fltVal);
  m_pPSet->GetValue(in_guidPlatform, szHv_windGen_Param_vol_doorways, varProp);
  in_pDataWriter->WriteReal32(varProp.fltVal);
  m_pPSet->GetValue(in_guidPlatform, szHv_windGen_Param_vol_leaves, varProp);
  in_pDataWriter->WriteReal32(varProp.fltVal);
  m_pPSet->GetValue(in_guidPlatform, szHv_windGen_Param_vol_master, varProp);
  in_pDataWriter->WriteReal32(varProp.fltVal);
  m_pPSet->GetValue(in_guidPlatform, szHv_windGen_Param_wind_intensity, varProp);
  in_pDataWriter->WriteReal32(varProp.fltVal);

  return true;
}

bool Hv_windGen_WwiseAuthoringPlugin::Help(
    HWND in_hWnd, eDialog in_eDialog, LPCWSTR in_szLanguageCode) const {
  return false;
};

bool Hv_windGen_WwiseAuthoringPlugin::SaveAudioFileToTableId(unsigned int tableId) {
  static TCHAR BASED_CODE szFilter[] = _T("Audio Files (*.wav)|*.wav|");
  CFileDialog dialog(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
  if (dialog.DoModal() == IDOK) {
    m_pObjectMedia->SetMediaSource(dialog.GetPathName(), tableId, true);
    return true;
  }
  return false;
};
