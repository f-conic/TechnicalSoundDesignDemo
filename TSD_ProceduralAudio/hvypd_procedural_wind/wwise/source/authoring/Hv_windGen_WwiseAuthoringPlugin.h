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

#ifndef _HV_WINDGEN_WWISE_PLUGIN_H_
#define _HV_WINDGEN_WWISE_PLUGIN_H_

#include <AK/Wwise/AudioPlugin.h>

/**
 * Plugin property names
 * NOTE: These should be named the same as the respective Property Name value
 * in the plugin xml definition
 */
static LPCWSTR szHv_windGen_Param_q_branches_whistle = L"q_branches_whistle";
static LPCWSTR szHv_windGen_Param_vol_branches = L"vol_branches";
static LPCWSTR szHv_windGen_Param_vol_buildings = L"vol_buildings";
static LPCWSTR szHv_windGen_Param_vol_doorways = L"vol_doorways";
static LPCWSTR szHv_windGen_Param_vol_leaves = L"vol_leaves";
static LPCWSTR szHv_windGen_Param_vol_master = L"vol_master";
static LPCWSTR szHv_windGen_Param_wind_intensity = L"wind_intensity";

class Hv_windGen_WwiseAuthoringPlugin : public AK::Wwise::DefaultAudioPluginImplementation,
                                         public AK::Wwise::IPluginMediaConverter {
public:
  Hv_windGen_WwiseAuthoringPlugin(AkUInt16 in_idPlugin);

  ~Hv_windGen_WwiseAuthoringPlugin() {};

  /** AK::Wwise::IPluginBase Overrides */
  virtual void Destroy(); // Implement the destruction of the Wwise source plugin.

  /** AK:WWise::IPluginMediaConverter Overrides */
  virtual AK::Wwise::IPluginMediaConverter* GetPluginMediaConverterInterface() override;

  virtual AK::Wwise::ConversionResult ConvertFile(const GUID &in_guidPlatform, const BasePlatformID &in_basePlatform,
      LPCWSTR in_szSourceFile, LPCWSTR in_szDestFile, AkUInt32 in_uSampleRate, AkUInt32 in_uBlockLength,
      AK::Wwise::IProgress *in_pProgress, AK::Wwise::IWriteString *io_pError) override;

  virtual ULONG GetCurrentConversionSettingsHash(const GUID & in_guidPlatform,
    AkUInt32 in_uSampleRate, AkUInt32 in_uBlockLength) override;

  /** DefaultAudioPluginImplementation */
  virtual void InitToDefault() override;

  /** AK::Wwise::IAudioPlugin Overrides */
  virtual void SetPluginPropertySet(AK::Wwise::IPluginPropertySet * in_pPSet);

  virtual void SetPluginObjectMedia(AK::Wwise::IPluginObjectMedia *in_pObjectMedia) override;

  virtual void NotifyPluginMediaChanged() override;

  virtual void NotifyPropertyChanged(const GUID & in_guidPlatform,
      LPCWSTR in_szPropertyName) {};

  virtual HINSTANCE GetResourceHandle() const;

  virtual bool GetDialog(eDialog in_eDialog, UINT & out_uiDialogID,
      AK::Wwise::PopulateTableItem *& out_pTable) const;

  virtual bool WindowProc(eDialog in_eDialog, HWND in_hWnd, UINT in_message,
      WPARAM in_wParam, LPARAM in_lParam, LRESULT & out_lResult);

  virtual bool GetBankParameters(const GUID & in_guidPlatform,
      AK::Wwise::IWriteData* in_pDataWriter) const;

  virtual bool Help(HWND in_hWnd, eDialog in_eDialog,
      LPCWSTR in_szLanguageCode) const;

  static const short CompanyID;
  static const short PluginID;

private:
  bool SaveAudioFileToTableId(unsigned int tableId);

  AK::Wwise::IPluginPropertySet *m_pPSet;
  AK::Wwise::IPluginObjectMedia *m_pObjectMedia;
  HWND m_hwndPropView;
  HWND m_hwndObjPane;
  AkUInt16 m_idDialogBig;
  AkUInt16 m_idDialogSmall;
  };

#endif // _HV_WINDGEN_WWISE_PLUGIN_H_
