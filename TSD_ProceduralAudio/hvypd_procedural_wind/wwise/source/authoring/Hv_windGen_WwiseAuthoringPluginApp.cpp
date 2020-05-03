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

#include "stdafx.h"
#include <AK/Wwise/Utilities.h>
#include <AK/Tools/Common/AkAssert.h>
#include "Hv_windGen_WwiseSourcePluginFactory.h"
#include "Hv_windGen_WwiseAuthoringPlugin.h"
#include "Hv_windGen_WwiseAuthoringPluginApp.h"

BEGIN_MESSAGE_MAP(Hv_windGen_WwiseAuthoringPluginApp, CWinApp)
END_MESSAGE_MAP()

/** Only one PluginApp should exist */
Hv_windGen_WwiseAuthoringPluginApp windGenApp;

BOOL Hv_windGen_WwiseAuthoringPluginApp::InitInstance() {
  __super::InitInstance();
  AK::Wwise::RegisterWwisePlugin();
  return TRUE;
}

/** Plugin Creation DLL export. */
AK::Wwise::IPluginBase* __stdcall AkCreatePlugin(
    unsigned short in_usCompanyID, unsigned short in_usPluginID) {
  if (in_usCompanyID == Hv_windGen_WwiseAuthoringPlugin::CompanyID &&
      in_usPluginID == Hv_windGen_WwiseAuthoringPlugin::PluginID) {
    return new Hv_windGen_WwiseAuthoringPlugin(in_usPluginID);
  }
  return NULL;
}

/** Dummy assert hook for Wwise plug-ins using AKASSERT (cassert used by default). */
DEFINEDUMMYASSERTHOOK;
