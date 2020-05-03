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

#ifndef _HEAVY_CONTEXT_WINDGEN_HPP_
#define _HEAVY_CONTEXT_WINDGEN_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalTabwrite.h"
#include "HvTable.h"
#include "HvControlIf.h"
#include "HvSignalCPole.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvSignalBiquad.h"
#include "HvControlRandom.h"
#include "HvSignalTabread.h"
#include "HvMath.h"
#include "HvSignalRPole.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"

class Heavy_windGen : public HeavyContext {

 public:
  Heavy_windGen(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_windGen();

  const char *getName() override { return "windGen"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        Q_BRANCHES_WHISTLE = 0x5C92F556, // q_branches_whistle
        VOL_BRANCHES = 0x228BAFC9, // vol_branches
        VOL_BUILDINGS = 0x67C201F5, // vol_buildings
        VOL_DOORWAYS = 0x18604B87, // vol_doorways
        VOL_LEAVES = 0xBDBA399A, // vol_leaves
        VOL_MASTER = 0x60CE831, // vol_master
        WIND_INTENSITY = 0x5F708FA1, // wind_intensity
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_cyraW2SN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_OnygtdZE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_7rQLx3AK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bYqj64MT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_LOOaFK9f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ThwcwXkx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0voFUrtD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aWZcN8bR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5CpX96HO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IqT11wk0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZO9NaCxB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eTDRHdMm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m9d3K5Px_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o1p5uDHq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6kgA67KT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B4kfQ7qR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hEq81dsR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5NZ5AedU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_F29Xp4K5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BtkoPqvk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qcxSFkzi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_x2Y3DCI0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_keMZVH4q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rP144bbO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xKl3FCbJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_LegADxHi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_16qRMLCZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Nd3iz2Md_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_XJCh0AX4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Mkvkdx0Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M51DJVYk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cvWRebaz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yzaiF4qJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_TEh3ASgo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Vb3h0pvu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uvBIxlwQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5xSrmXd3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rurWDkZQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TEPQLTbK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cQX4UFcs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vnf5mu7C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DZjxhQWj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Z4PND2NY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_BQx000ut_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DugDDVHg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SinbzF1S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KMrrDQ1H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kraisuOr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bhp8tauH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TwVGbm8O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_MyMTVMaz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_A4rY2AQj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_620riYJ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Gbgg9S17_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xpUiMMjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_UQCnvvkD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4476W1eS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aUZnS1TF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qwf7bQJS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XuTGm5oR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_duTf7qhP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_dILXJw3T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GLtBa7Ui_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x2XnNjqn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bdwq7lvk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EYAzKvgX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FFj2Z6tW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KimsK1T4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9tBhgfuW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kduWoaTW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pdmYwzlX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3JKTtUn3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Bi9GjGUo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rT5legGK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YM1I5VSl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1lAittUi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qhX8GIxS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dalKFzU3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WsSuo66G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H8QCMI8g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_g9YRzMfP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_m9yBCBY0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4MpoUezF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_roH0Knax_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vKX7Ow7R_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cUnop_DEFuuLf6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_yM64lNTc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FLLDqNEj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WIVIYAcW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_w3QhJixP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AgxvTceX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ICumoWZ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lkXvGg7l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dA8mFBs4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TQTE9l3N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pfxujPJh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EusxcNIy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3zNtiVCY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eIwIlA70_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DQNtobhZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l1837p0D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qCNETVQS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L4tcbCfe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6crCoCZH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9OUTUM6s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VoQItGYq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cvaEibBu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zE4wDVS7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MX83kyuV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Sqhe2fWJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CCO70IDc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QfEUoYUN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CgFlkZZi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EU5F4grh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_j0g6vvGO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e7rvpb2r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s2PGHc4F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ksEHdVwI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AJOgJB8G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OTRLH1wp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9C7k73ni_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DQsmcR4R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3li8Fk9o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EVXtL1p4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_TimDVE4D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XuOfFf4k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hfm5wfHu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oePu08MA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fUTV5NvH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0i3L2IWw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GzUHNGLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_JyG81Qgf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FyekxMAT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kypmhv44_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XZ93fufm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1m5aqVaM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0FIvRVlB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OsfC9IyX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jHKuLwQV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_pTZ8arrI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p9SwEtu7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VrWLXlUa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oLJg6ZiV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aV8HuuNt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gG7vgmP3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3uQu9dvG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2VFREwWa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_SBXMhD8H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_h51936EA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TvGVhuLV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TNNT3h1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KqfIycAg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nDRXJuUM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2sEJMDPJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_jTV3ZuHR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_znbGxeLM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_Fygbla1G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cre7gKan_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_sqCxsRtg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_cHPCidFr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_tf5DEa7E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dm7nbe2w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_38Gm5RKg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_r1nepf4k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JF63GE4G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WfosrVz4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_szCjaHUn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WV42BisO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8cJ4XXV5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b0t5a16R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6uMaJxqA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ry47Jses_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_29hgXvB7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rQESBjX6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_yDMAAr8f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NSScRCi7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_I3b1ici7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wH3pfWdl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1nFbYvAW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qYRDOrMc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yDviiIyK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kxOsLTkR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_COoCRwdP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4e9zouPk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WmkPJJtR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rE4f6lFK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0uHQJeNR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Sca5LXlY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0Pg7M4bY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nbqtADAL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_91bZyfcT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nF0K1NJP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CSQNvw3r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9vWyyjSR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Lu1ouIoQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y69HdJro_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OIYUdWOC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WcttvRL9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QCqPtx8Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_K06FdgbJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_LiACPLTm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_GTixlW5T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6i6n3EZx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_YsklFfWR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QYjCXnJO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gpDNMLui_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5cAovgKE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5me6ba1E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z1VpNAVy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PgW7zCCz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T3FVYocL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OdaNIhqH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_x00mMotM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AZNUJARV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fjjgkLMH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_rMD9sFSX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_mvJpr8iC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e05B3mn1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H58gFTCr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v6NzAVvT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P199jyf4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OlmmmQ1s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8vDb2mhR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uY25VMPn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uYtOSafz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_36vqowBw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vOltnciC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yVO1Csxm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LcdF0xtJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SpXUkYSY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Z2EDFxLM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_U8vBFlbv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_r2RdNTRW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bugupyOT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kWCiLnPX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4eh9LTmO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cunn6TNE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_f0yc5vc5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q6borehM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nD1Xrz5c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ao1xhyBs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rgx7p5An_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MOWzEINv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ahUlPoHF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_E1y65Kcb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GuWjO0Hk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uq5oX0ui_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AZxELPr6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jS1bNsUg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9ssiM0R9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_amW7EUi7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9tXk9QEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MCrmJQQx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b9e6EcsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hvS1l7on_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_531Hf3Dx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_rnCpFcPL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EOGWIKqv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BHFN4QbF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6HQe9kSM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iNSajlJF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1tH6hFi6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_trNIpJ8T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_fH4DPihC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bClUS8HQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7CygVWUi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y2YsNqfE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RsfxifzB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7xP72zA6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0u937PZ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yoCAUJn1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BBO8qIZ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ASYxM8BX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_TRqQPj2m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WruG5NaA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VRwDGzso_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_P2aoqt93_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qg9GOEDQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qcpSn9Jy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_as4BF1bd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gaPl3hvw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_2R7G0ifr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_trLriyDf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FhtzxrKg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5mfSennX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rFhWGTwR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_4eryWYSA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Khx1jNnI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_UsqgB2ZU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_spYlychT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nAafolHP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2rLHlEgg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eIsa7pnR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bgrAfGpA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_45Lj1LG5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_DYGNbFhZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e8CXS7XT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ndgqnsSY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_FE2y4TcF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WAiOgHTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TY1fnApG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_lrVPEIqA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ctD5UrL4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_cE5FgxpC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_IfUWN2l3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_duHO93FF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qcAur9To_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_khJr0P5b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZFZpDsCw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2z1qNgK8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_M8LpecoS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_o825F25e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_92XVRIoK_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabhead sTabhead_FlUfUVok;
  SignalTabread sTabread_GXKoAZll;
  SignalTabread sTabread_cRq04gcO;
  SignalCPole sCPole_gj4IW0R1;
  SignalTabhead sTabhead_Twf3b2kK;
  SignalTabread sTabread_eTp7qZXD;
  SignalTabread sTabread_4i5dmliu;
  SignalBiquad_k sBiquad_k_Dm9GL8hZ;
  SignalDel1 sDel1_PjHHYJ8K;
  SignalTabhead sTabhead_YdJxrPVT;
  SignalTabread sTabread_kac0wRpQ;
  SignalTabread sTabread_Qjb8RhDs;
  SignalCPole sCPole_qRsf5CBy;
  SignalTabhead sTabhead_7FJ2vbLS;
  SignalTabread sTabread_Qx7ONZhV;
  SignalTabread sTabread_5yPKNLw3;
  SignalRPole sRPole_gu9mcFdm;
  SignalRPole sRPole_YZ3OiX1T;
  SignalDel1 sDel1_O9rKdXJ1;
  SignalRPole sRPole_qfq5d57P;
  SignalBiquad_k sBiquad_k_TWYN0EXQ;
  SignalTabhead sTabhead_1Wk2pKEK;
  SignalTabread sTabread_3ZqJrYPJ;
  SignalTabread sTabread_zCz3PpM2;
  SignalRPole sRPole_48d5mzmx;
  SignalPhasor sPhasor_xgSGQTB1;
  SignalBiquad_k sBiquad_k_zBjX4SMt;
  SignalTabhead sTabhead_tb8ZUi97;
  SignalTabread sTabread_hrkAK5x2;
  SignalTabread sTabread_gMHroshT;
  SignalRPole sRPole_iw5MDSKl;
  SignalPhasor sPhasor_oLEIN0wU;
  SignalPhasor sPhasor_fKP08iwB;
  SignalRPole sRPole_e0KQ32CS;
  SignalRPole sRPole_Y0VpjC5s;
  SignalRPole sRPole_gwaD4Rnz;
  SignalDel1 sDel1_Ik6k3rte;
  SignalRPole sRPole_EqlYbrMa;
  SignalRPole sRPole_WpTbkRFR;
  SignalRPole sRPole_yLnv67vZ;
  SignalDel1 sDel1_QgVcNjvi;
  SignalTabwrite sTabwrite_FhMXREbk;
  ControlVar cVar_cyraW2SN;
  SignalVarf sVarf_l5hhZHL6;
  SignalVarf sVarf_tYbaZYML;
  ControlBinop cBinop_aWZcN8bR;
  ControlVar cVar_5CpX96HO;
  SignalVarf sVarf_EJDaROSP;
  ControlBinop cBinop_ZO9NaCxB;
  SignalVarf sVarf_3PZ3CDp0;
  SignalVarf sVarf_HRE33aGl;
  SignalVarf sVarf_cWgkNgOV;
  ControlBinop cBinop_m9d3K5Px;
  ControlBinop cBinop_o1p5uDHq;
  ControlBinop cBinop_B4kfQ7qR;
  ControlVar cVar_5NZ5AedU;
  SignalVarf sVarf_Knqqopca;
  ControlBinop cBinop_BtkoPqvk;
  SignalVarf sVarf_Sl5aFLeD;
  SignalVarf sVarf_4ufXwHlQ;
  SignalVarf sVarf_zzyweif8;
  ControlBinop cBinop_xKl3FCbJ;
  ControlIf cIf_LegADxHi;
  ControlBinop cBinop_16qRMLCZ;
  ControlBinop cBinop_Mkvkdx0Y;
  ControlBinop cBinop_M51DJVYk;
  ControlBinop cBinop_cvWRebaz;
  ControlVar cVar_uvBIxlwQ;
  ControlBinop cBinop_5xSrmXd3;
  ControlBinop cBinop_rurWDkZQ;
  SignalVarf sVarf_IzSIigD6;
  SignalVarf sVarf_5pYbPBTs;
  SignalVarf sVarf_2MB6b3aa;
  SignalVarf sVarf_vffhrFzo;
  ControlVar cVar_cQX4UFcs;
  ControlBinop cBinop_Vnf5mu7C;
  ControlBinop cBinop_DZjxhQWj;
  ControlBinop cBinop_SinbzF1S;
  ControlBinop cBinop_KMrrDQ1H;
  ControlBinop cBinop_kraisuOr;
  SignalVarf sVarf_oNJfWks0;
  ControlVar cVar_bhp8tauH;
  ControlBinop cBinop_TwVGbm8O;
  ControlVar cVar_620riYJ1;
  ControlBinop cBinop_Gbgg9S17;
  SignalVarf sVarf_EF50fPR0;
  ControlVar cVar_4476W1eS;
  SignalVarf sVarf_9v224X5j;
  ControlBinop cBinop_aUZnS1TF;
  ControlBinop cBinop_qwf7bQJS;
  ControlBinop cBinop_XuTGm5oR;
  ControlBinop cBinop_duTf7qhP;
  ControlVar cVar_GLtBa7Ui;
  ControlBinop cBinop_x2XnNjqn;
  ControlBinop cBinop_bdwq7lvk;
  ControlBinop cBinop_EYAzKvgX;
  ControlBinop cBinop_FFj2Z6tW;
  ControlBinop cBinop_9tBhgfuW;
  ControlBinop cBinop_kduWoaTW;
  ControlVar cVar_pdmYwzlX;
  ControlBinop cBinop_3JKTtUn3;
  ControlBinop cBinop_YM1I5VSl;
  ControlBinop cBinop_1lAittUi;
  ControlBinop cBinop_qhX8GIxS;
  ControlBinop cBinop_dalKFzU3;
  ControlBinop cBinop_WsSuo66G;
  ControlBinop cBinop_H8QCMI8g;
  ControlVar cVar_m9yBCBY0;
  ControlBinop cBinop_4MpoUezF;
  ControlSlice cSlice_roH0Knax;
  ControlRandom cRandom_yM64lNTc;
  SignalVari sVari_rE9yBWsR;
  SignalVarf sVarf_DzCuV7EE;
  ControlVar cVar_WIVIYAcW;
  ControlBinop cBinop_lkXvGg7l;
  ControlBinop cBinop_dA8mFBs4;
  SignalVarf sVarf_O2QXY4CX;
  ControlBinop cBinop_TQTE9l3N;
  ControlBinop cBinop_pfxujPJh;
  ControlBinop cBinop_EusxcNIy;
  SignalVarf sVarf_bZt6VyJ6;
  ControlBinop cBinop_3zNtiVCY;
  ControlBinop cBinop_l1837p0D;
  ControlBinop cBinop_L4tcbCfe;
  ControlBinop cBinop_6crCoCZH;
  ControlBinop cBinop_9OUTUM6s;
  ControlVar cVar_VoQItGYq;
  SignalVarf sVarf_uruExZKR;
  SignalVarf sVarf_sFlbCBBy;
  SignalVarf sVarf_MG9r5lq8;
  ControlBinop cBinop_cvaEibBu;
  SignalVarf sVarf_0gE7JUSh;
  ControlVar cVar_zE4wDVS7;
  ControlBinop cBinop_MX83kyuV;
  SignalVarf sVarf_vSveWv11;
  ControlBinop cBinop_EU5F4grh;
  ControlIf cIf_j0g6vvGO;
  ControlBinop cBinop_e7rvpb2r;
  ControlBinop cBinop_s2PGHc4F;
  ControlBinop cBinop_AJOgJB8G;
  SignalVarf sVarf_twRSP1PD;
  SignalVarf sVarf_WLMyyxab;
  SignalVarf sVarf_FzQK82cm;
  SignalVarf sVarf_TRrcpirM;
  SignalVarf sVarf_Aybj4zjb;
  ControlVar cVar_XuOfFf4k;
  ControlBinop cBinop_oePu08MA;
  ControlVar cVar_fUTV5NvH;
  ControlBinop cBinop_0i3L2IWw;
  ControlVar cVar_GzUHNGLP;
  SignalVarf sVarf_CCTowUa0;
  SignalVarf sVarf_dIODxUcP;
  ControlBinop cBinop_kypmhv44;
  ControlVar cVar_XZ93fufm;
  SignalVarf sVarf_pILr6UfK;
  ControlVar cVar_0FIvRVlB;
  SignalVarf sVarf_Wgkd0q7P;
  ControlBinop cBinop_OsfC9IyX;
  SignalVarf sVarf_XAVegxys;
  ControlBinop cBinop_p9SwEtu7;
  ControlBinop cBinop_VrWLXlUa;
  ControlBinop cBinop_oLJg6ZiV;
  ControlBinop cBinop_gG7vgmP3;
  ControlVar cVar_3uQu9dvG;
  ControlBinop cBinop_2VFREwWa;
  SignalVarf sVarf_PFIhmQXb;
  ControlBinop cBinop_TvGVhuLV;
  SignalVarf sVarf_ZQtUz39Q;
  ControlBinop cBinop_TNNT3h1P;
  ControlBinop cBinop_KqfIycAg;
  ControlBinop cBinop_nDRXJuUM;
  SignalVari sVari_P6UojO3l;
  ControlBinop cBinop_znbGxeLM;
  ControlRandom cRandom_Fygbla1G;
  ControlSlice cSlice_cre7gKan;
  ControlBinop cBinop_cHPCidFr;
  ControlBinop cBinop_38Gm5RKg;
  SignalVarf sVarf_h6kHpfcy;
  ControlBinop cBinop_JF63GE4G;
  ControlBinop cBinop_WfosrVz4;
  SignalVarf sVarf_0nX3QOcn;
  ControlVar cVar_szCjaHUn;
  ControlBinop cBinop_WV42BisO;
  ControlBinop cBinop_8cJ4XXV5;
  ControlBinop cBinop_b0t5a16R;
  SignalVarf sVarf_hF5cR2gK;
  ControlBinop cBinop_6uMaJxqA;
  ControlBinop cBinop_ry47Jses;
  ControlBinop cBinop_29hgXvB7;
  ControlVar cVar_I3b1ici7;
  SignalVarf sVarf_uXRuv4Hj;
  ControlVar cVar_wH3pfWdl;
  ControlBinop cBinop_1nFbYvAW;
  ControlBinop cBinop_qYRDOrMc;
  SignalVarf sVarf_pJxSOZqn;
  SignalVarf sVarf_L3zLCbS6;
  ControlBinop cBinop_yDviiIyK;
  ControlBinop cBinop_kxOsLTkR;
  ControlBinop cBinop_rE4f6lFK;
  SignalVarf sVarf_ZpfaUrnn;
  SignalVarf sVarf_TbSLV8le;
  ControlBinop cBinop_0uHQJeNR;
  ControlBinop cBinop_0Pg7M4bY;
  ControlBinop cBinop_nF0K1NJP;
  ControlBinop cBinop_CSQNvw3r;
  ControlBinop cBinop_9vWyyjSR;
  ControlVar cVar_Lu1ouIoQ;
  ControlBinop cBinop_Y69HdJro;
  ControlBinop cBinop_OIYUdWOC;
  ControlBinop cBinop_WcttvRL9;
  ControlBinop cBinop_QCqPtx8Z;
  ControlSlice cSlice_GTixlW5T;
  ControlBinop cBinop_6i6n3EZx;
  ControlRandom cRandom_YsklFfWR;
  SignalVari sVari_CP17y1Ff;
  SignalVarf sVarf_tsF8wJhQ;
  ControlVar cVar_gpDNMLui;
  ControlBinop cBinop_5cAovgKE;
  SignalVarf sVarf_sREve591;
  ControlBinop cBinop_5me6ba1E;
  ControlBinop cBinop_z1VpNAVy;
  ControlBinop cBinop_T3FVYocL;
  ControlBinop cBinop_OdaNIhqH;
  ControlVar cVar_fjjgkLMH;
  SignalVarf sVarf_lzmSSGTw;
  SignalVarf sVarf_gIl8ddj6;
  ControlBinop cBinop_H58gFTCr;
  ControlBinop cBinop_v6NzAVvT;
  SignalVarf sVarf_oqG04I7i;
  ControlBinop cBinop_OlmmmQ1s;
  ControlBinop cBinop_8vDb2mhR;
  ControlBinop cBinop_uY25VMPn;
  SignalVarf sVarf_flozjRRE;
  ControlBinop cBinop_uYtOSafz;
  ControlBinop cBinop_36vqowBw;
  ControlBinop cBinop_vOltnciC;
  SignalVarf sVarf_lI3M2NO1;
  ControlBinop cBinop_yVO1Csxm;
  ControlBinop cBinop_LcdF0xtJ;
  ControlBinop cBinop_SpXUkYSY;
  ControlVar cVar_Z2EDFxLM;
  ControlVar cVar_kWCiLnPX;
  SignalVarf sVarf_uN0YYn82;
  SignalVarf sVarf_Mn2cED2a;
  ControlBinop cBinop_4eh9LTmO;
  ControlBinop cBinop_cunn6TNE;
  ControlBinop cBinop_Q6borehM;
  ControlVar cVar_nD1Xrz5c;
  ControlBinop cBinop_ao1xhyBs;
  ControlBinop cBinop_Rgx7p5An;
  ControlBinop cBinop_MOWzEINv;
  ControlBinop cBinop_GuWjO0Hk;
  ControlBinop cBinop_uq5oX0ui;
  ControlBinop cBinop_AZxELPr6;
  ControlBinop cBinop_jS1bNsUg;
  ControlBinop cBinop_9ssiM0R9;
  ControlBinop cBinop_amW7EUi7;
  ControlBinop cBinop_9tXk9QEf;
  ControlVar cVar_MCrmJQQx;
  ControlBinop cBinop_b9e6EcsC;
  ControlBinop cBinop_hvS1l7on;
  ControlBinop cBinop_531Hf3Dx;
  ControlBinop cBinop_EOGWIKqv;
  ControlBinop cBinop_BHFN4QbF;
  ControlBinop cBinop_6HQe9kSM;
  ControlBinop cBinop_iNSajlJF;
  ControlBinop cBinop_1tH6hFi6;
  ControlBinop cBinop_trNIpJ8T;
  ControlBinop cBinop_7CygVWUi;
  ControlBinop cBinop_y2YsNqfE;
  ControlBinop cBinop_RsfxifzB;
  ControlBinop cBinop_7xP72zA6;
  ControlBinop cBinop_0u937PZ7;
  ControlBinop cBinop_yoCAUJn1;
  ControlBinop cBinop_BBO8qIZ5;
  ControlBinop cBinop_ASYxM8BX;
  ControlBinop cBinop_WruG5NaA;
  ControlBinop cBinop_VRwDGzso;
  ControlBinop cBinop_qg9GOEDQ;
  ControlBinop cBinop_qcpSn9Jy;
  ControlVar cVar_as4BF1bd;
  ControlVar cVar_gaPl3hvw;
  SignalVarf sVarf_QDNxVffR;
  SignalVarf sVarf_B5snaMF6;
  SignalVarf sVarf_6KTvfFcz;
  ControlVar cVar_trLriyDf;
  SignalVarf sVarf_AuYVX3gQ;
  ControlVar cVar_FhtzxrKg;
  SignalVarf sVarf_8ALmqcTI;
  SignalVarf sVarf_VyxnrcC6;
  SignalVarf sVarf_7T0dA7Pi;
  HvTable hTable_spYlychT;
  ControlBinop cBinop_bgrAfGpA;
  ControlBinop cBinop_45Lj1LG5;
  ControlDelay cDelay_DYGNbFhZ;
  ControlDelay cDelay_FE2y4TcF;
  SignalVarf sVarf_o4Z63GLD;
  ControlVar cVar_TY1fnApG;
  SignalVarf sVarf_EZvCPgDL;
  ControlVar cVar_ctD5UrL4;
  SignalVarf sVarf_CMcZzvnH;
  SignalVarf sVarf_gLSfat2R;
  SignalVarf sVarf_jFz8OqiC;
  SignalVarf sVarf_1NtnWdbS;
  ControlBinop cBinop_khJr0P5b;
  ControlBinop cBinop_ZFZpDsCw;
  SignalVarf sVarf_USHK0SOW;
  ControlVar cVar_92XVRIoK;
};

#endif // _HEAVY_CONTEXT_WINDGEN_HPP_
