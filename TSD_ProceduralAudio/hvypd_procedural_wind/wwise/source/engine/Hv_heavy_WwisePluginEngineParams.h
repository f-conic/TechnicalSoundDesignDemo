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

#ifndef _HV_HEAVY_WWISE_PLUGIN_ENGINE_PARAMS_H_
#define _HV_HEAVY_WWISE_PLUGIN_ENGINE_PARAMS_H_

#include <AK/SoundEngine/Common/IAkPlugin.h>
#include <AK/Tools/Common/AkAssert.h>

/** Generated RTPC IDs */

// Input Parameters
static const AkPluginParamID HV_HEAVY_PARAM_IN_Q_BRANCHES_WHISTLE_ID = 0;
static const AkPluginParamID HV_HEAVY_PARAM_IN_VOL_BRANCHES_ID = 1;
static const AkPluginParamID HV_HEAVY_PARAM_IN_VOL_BUILDINGS_ID = 2;
static const AkPluginParamID HV_HEAVY_PARAM_IN_VOL_DOORWAYS_ID = 3;
static const AkPluginParamID HV_HEAVY_PARAM_IN_VOL_LEAVES_ID = 4;

/** Parameters structure for this effect. */
struct Hv_heavy_RTPCParams {
  /** Generated Heavy Parameters */
  AkReal32 fHVParam_q_branches_whistle;
  AkReal32 fHVParam_vol_branches;
  AkReal32 fHVParam_vol_buildings;
  AkReal32 fHVParam_vol_doorways;
  AkReal32 fHVParam_vol_leaves;
};

/**
 * class Hv_heavy_EngineParams
 * Implementation of Heavy Wwise plugin shared parameters.
 */
class Hv_heavy_EngineParams : public AK::IAkPluginParam {
 public:
  /** Allow effect to call accessor functions for retrieving parameter values. */
  friend class Hv_heavy_WwisePluginEngine;

  /** Default Constructor. */
  Hv_heavy_EngineParams();

  /** Destructor. */
  virtual ~Hv_heavy_EngineParams();

  /** Copy constructor. */
  Hv_heavy_EngineParams(const Hv_heavy_EngineParams &in_rCopy);

  /** Create duplicate. */
  virtual IAkPluginParam *Clone(AK::IAkPluginMemAlloc *in_pAllocator);

  /** Parameters node initialization. */
  virtual AKRESULT Init(AK::IAkPluginMemAlloc *in_pAllocator, const void *in_pParamsBlock,
      AkUInt32 in_uBlockSize);

  /** Terminate. */
  virtual AKRESULT Term(AK::IAkPluginMemAlloc *in_pAllocator);

  /** Set all parameters at once. */
  virtual AKRESULT SetParamsBlock(const void * in_pParamsBlock,
      AkUInt32 in_uBlockSize);

  /** Update one parameter. */
  virtual AKRESULT SetParam(AkPluginParamID in_ParamID, const void *in_pValue,
      AkUInt32 in_uParamSize);

private:
  /** Hide assignment operator. */
  Hv_heavy_EngineParams &operator=(const Hv_heavy_EngineParams &in_rCopy) = default;

  /** RTPC'd Heavy Parameter Getter Methods */
  AkReal32 GetParam_q_branches_whistle();
  AkReal32 GetParam_vol_branches();
  AkReal32 GetParam_vol_buildings();
  AkReal32 GetParam_vol_doorways();
  AkReal32 GetParam_vol_leaves();

  /** RTPC Parameter structure. */
  Hv_heavy_RTPCParams m_Params;
};

/** Getter methods for generated Heavy parameters */
inline AkReal32 Hv_heavy_EngineParams::GetParam_q_branches_whistle() {
  AkReal32 fParam_q_branches_whistle = m_Params.fHVParam_q_branches_whistle;
  AKASSERT(fParam_q_branches_whistle >= 0.0 && fParam_q_branches_whistle <= 1500.0);
  return fParam_q_branches_whistle;
}

inline AkReal32 Hv_heavy_EngineParams::GetParam_vol_branches() {
  AkReal32 fParam_vol_branches = m_Params.fHVParam_vol_branches;
  AKASSERT(fParam_vol_branches >= 0.0 && fParam_vol_branches <= 15.0);
  return fParam_vol_branches;
}

inline AkReal32 Hv_heavy_EngineParams::GetParam_vol_buildings() {
  AkReal32 fParam_vol_buildings = m_Params.fHVParam_vol_buildings;
  AKASSERT(fParam_vol_buildings >= 0.0 && fParam_vol_buildings <= 3.0);
  return fParam_vol_buildings;
}

inline AkReal32 Hv_heavy_EngineParams::GetParam_vol_doorways() {
  AkReal32 fParam_vol_doorways = m_Params.fHVParam_vol_doorways;
  AKASSERT(fParam_vol_doorways >= 0.0 && fParam_vol_doorways <= 10.0);
  return fParam_vol_doorways;
}

inline AkReal32 Hv_heavy_EngineParams::GetParam_vol_leaves() {
  AkReal32 fParam_vol_leaves = m_Params.fHVParam_vol_leaves;
  AKASSERT(fParam_vol_leaves >= 0.0 && fParam_vol_leaves <= 5.0);
  return fParam_vol_leaves;
}


#endif // _HV_HEAVY_WWISE_PLUGIN_ENGINE_PARAMS_H_
