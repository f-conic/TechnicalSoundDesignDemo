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

#ifndef _HV_HEAVY_WWISE_PLUGIN_ENGINE_H_
#define _HV_HEAVY_WWISE_PLUGIN_ENGINE_H_

#include "Hv_heavy_WwisePluginEngineParams.h"

class HeavyContextInterface;

/**
 * class Hv_heavy_WwisePluginEngine
 * Heavy context wrapper (source effect).
 */
class Hv_heavy_WwisePluginEngine : public AK::IAkSourcePlugin
{
public:
  Hv_heavy_WwisePluginEngine();
  virtual ~Hv_heavy_WwisePluginEngine();

  // Plugin initialization
  virtual AKRESULT Init(AK::IAkPluginMemAlloc *in_pAllocator,
      AK::IAkSourcePluginContext *in_pPluginContext,
      AK::IAkPluginParam *in_pParams,
      AkAudioFormat &io_rFormat) override;

  virtual AKRESULT Term(AK::IAkPluginMemAlloc *in_pAllocator) override;

  virtual AKRESULT Reset() override { return AK_Success; }

  virtual AKRESULT GetPluginInfo(AkPluginInfo & out_rPluginInfo) override;

  // Main processing loop
  virtual void Execute(AkAudioBuffer *io_pBuffer) override;

  virtual AkReal32 GetDuration() const override;

  virtual AkReal32 GetEnvelope() const override;

  virtual AKRESULT StopLooping() override;

  void PostDebugMessage(const char *str);

  void SetOutRTPC(const char *rtpcName, unsigned int nameLength, float value);

private:
  void LoadPluginMediaToHeavyTable(unsigned int mediaIndex, unsigned int tableHash,
      unsigned int tableSizeReceiverHash);

  AK::IAkSourcePluginContext *m_pPluginContext; // Plugin context interface.
  Hv_heavy_EngineParams *m_pEngineParams; // Modified by Wwise/RTPC.
  HeavyContextInterface *m_pHeavyContext; // Main Heavy patch context
  AkUInt32 m_uSampleRate;

  // Store previous RTPC values
  AkReal32 m_fPrevParam_q_branches_whistle;
  AkReal32 m_fPrevParam_vol_branches;
  AkReal32 m_fPrevParam_vol_buildings;
  AkReal32 m_fPrevParam_vol_doorways;
  AkReal32 m_fPrevParam_vol_leaves;
};

#endif // _HV_HEAVY_WWISE_PLUGIN_ENGINE_H_
