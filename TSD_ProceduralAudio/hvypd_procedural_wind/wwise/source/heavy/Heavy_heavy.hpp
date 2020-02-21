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

#ifndef _HEAVY_CONTEXT_HEAVY_HPP_
#define _HEAVY_CONTEXT_HEAVY_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalTabwrite.h"
#include "HvTable.h"
#include "HvControlRandom.h"
#include "HvSignalBiquad.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlUnop.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvControlIf.h"
#include "HvSignalCPole.h"
#include "HvMath.h"
#include "HvSignalRPole.h"
#include "HvSignalTabread.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"

class Heavy_heavy : public HeavyContext {

 public:
  Heavy_heavy(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_heavy();

  const char *getName() override { return "heavy"; }
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
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_7d4Vicc9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dDRpOOVt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_cl6A1E9x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Pko7zMdb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J70Yr0im_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aqPCThsX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dmWSzqQ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9gqnSemf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qiu1tTRe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1dnnKuKV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EVTm3h04_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ocuXUPPk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1NdaYn6s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RnJe2iEv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_0PCwJV7D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_04ll5ckY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aft1Zjki_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_E58gjcoA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RI62KuWI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KqqhOG9D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_rt2PW6r6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_V6hn6bsP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_VBsuiPx2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4fZo9xLR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_twqs907p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TL40joUw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JgzpnzaN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2eCBIR5Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rrWQB6Yb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Ao0kmYwN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HxM4ppsc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PodtCDqF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nb7YVudK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DjJ7VBvj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BbAvYPho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ey7tfZ2s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LR8xzuOq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_yjxDPF1Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HGubuC1a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ankCPead_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XhhTQBQO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pMk23xZu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Fq2pLZYj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_A0tVhjSv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QFLmspl0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G9q3ujz4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uswTIKMm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uRHSqIxL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6arS7pkZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Wyn0edRy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SGKLCi9D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PRZizwbk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BSUAdk0H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_mGII6jlO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fG7lot5f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VfsrRsxn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WbcGEev2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_8Ges3EYa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QnShJ56y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Xiamu6bf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kgtUE3WM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dwmAcT8C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_awRCFfeM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9GdHlvG2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BDOVFbPe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_yTfLjb8g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HbMwmH4j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tm4v8FhJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HpqLFUO2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sQB4qhi9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zz3F29Tb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cBsw8ERD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lAqiFuH4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OBVObo3u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ezSbWyiS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_59QI2z7W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FAZhsE0K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_x1v9EGe7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0RQcTA39_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oSppqm89_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_I6udBtyu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YD2YVjZ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_scAL1N9N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5lcp3vC0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_2A5Ecrqu_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_R5YEeEao_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AhmVD5nq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_FG3mAKvr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pdZ4zEhg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_J5kLVjtc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4wOf5AHQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r3057LgE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BGgzYFr8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vzgc6pNm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0JinhOTH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nOuCkMsW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Ll8UVlzP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wzRQbWm1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RnbpeaPW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_ve7jeNDz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d7vgDrle_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_LGbtg9wM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bdY6gRkj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CmpvskuT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h94nLTqe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DuTZxOod_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Os8EKbXG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RjQnMDfY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_KXJL8pMt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CZQ5VsvQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hf7SlGMM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_17xOVnEM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WDRTLaze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EhLzSdIl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VQHxRivr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ne7IhtRj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mPnhvmvm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kwmCeG5m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9rm79Bbc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zwX4RZev_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LzJSXRyr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_wUEEnnY4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f9E7Jg4T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wuD76zW9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hOkU8WyG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mRYmAxQF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VdG0JABh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KfOu4UMT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nrTiyHLA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_uH1xty4H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_l0LWPtoK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UaUKmknn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TzEZS5tq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QdpQrAbT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wZPBmPO0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2jPIGz8Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jMROeUo8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1a9tVrWI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1TAumj0M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CEotCy2g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ilsZtDH4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Fks9gZQJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FbpQl9K6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8yjmDK5M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PcHwgKOk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mb9rdT6t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XbUBDpg0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LfcVo5Qi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Shp1KHF3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UGjlu6Pm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_nyBjdReH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vd8x85KJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6oi7eK1r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HsharESC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NKbP0FFH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GXgOf5f2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nuKLQPph_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_C83CiasE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iEYCzkEK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_k9J9hsMr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_D3gbJwxx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l76J8PBs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bqlfdMNm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TJaReTuy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MxZTdgCa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xBY59qB3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fd3epV0Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MnA8FXoS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aJ0GX80b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_aegqVCHO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KSZqp0JI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7GbV5Vk2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cPkTkfc7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n3gNQPro_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_bb2pcLyD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wd6OOLtN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lcDL2ugX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q5rrgqIf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kHO046jh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_imUiSh1f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1hDCr9bq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TqwFzL6T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eQwAOiFg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_3kyt0EJv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pOuUpFTG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ieZr3c9j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tnL0zRnI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HN0HnYyZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6qU7RHbB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ADpDeSjj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EPLRn6Ou_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IgoZRAjS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Cegt3wmJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_J2FBVWk9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DB31XlD3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FQ7rr4aK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_omZHmF4U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2IrqY8eP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ULsELuo8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qyL5bRU4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QOqMpx7p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZMeOdq8v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bzZ5iKmY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OcExrMws_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tnQL7RsA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nAXoQnUd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lElczO0f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SH2pfmBm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jwxt3dtX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EE0T6EhW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_jXpN1NFK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_axui19BN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4GZwtmHO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2gWYYIFx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MDJ95UJ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T2D4nX7o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LTUOVojt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dqm8vYuC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_D3QHxqG0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_42MQL6vJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z3Ie7GFS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JZWPFf4t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0LLHO2nw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t5jqnfDe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5rgs5nkm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nj3Lhcna_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_qXfy5YP0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xKL1eylZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_igpR7hdx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mjVLRm8I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N5q6wCoR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N0p2VVKM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Uhw82vsc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WyNemgTB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CiJel7Mq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Di3kG1J3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_y9u8HYQE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_iwssNkaj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bSGdKmDW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NWcln88W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_0u3YyX9I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WeXVu3vG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Aoq0odG3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cUnop_vDppEDmE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_OdAAFAwt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ELZLjWv3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_X8nzgryL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5CYwUbLE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gASGMris_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8DoObS2e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0PXdpe5D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HDcOV4H0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uPtUGEME_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lxofoAkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ooirf6Gg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DzerwWB8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YhSuwwXD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZAiLgmgq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_nLgborKd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fJ4nMPux_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DMhtBG7z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_jOaDFosN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1x0qBzS9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_OS3A8Let_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LDaw3fng_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pRDyaQdJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oVHNuhIo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_koC45kii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_VBpn1QjJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_sytVBw67_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_HgxFtxBT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cp7wESXz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_OVVegqJG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0AwQc0rY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_7CXkcumV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nLsxAWdl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BISHraEC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cROzhMAB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pg2y3K9r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qUQNbegd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k2i5U7M5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LR40p1B4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZTW4880r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DrnOZBal_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6EENltQZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WYMiZCyp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZL3qKza9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aEj7dOWo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ftQBG00c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_54hiQNKc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bWg1XxMf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZD9IzJEE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XRUY4NJM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_71XsB6qr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_tSHl6oB8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SHOjC10I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ID7KUU9e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_p8Rnah9z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_n7au4pzr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CaoeMLCQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_KGTu4WzN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KqusGvmf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HN1Ifwte_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_5kxlNLHa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9o6YO9TT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TT5cK8f4_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_z4NCoGXm;
  SignalTabhead sTabhead_4agiJ8Yk;
  SignalTabread sTabread_XY4PXO8b;
  SignalTabread sTabread_ISBQqrlg;
  SignalRPole sRPole_TODZ2rMA;
  SignalPhasor sPhasor_Rb49DLpo;
  SignalTabhead sTabhead_8VD0WAGS;
  SignalTabread sTabread_F9AXNekL;
  SignalTabread sTabread_dOXfMPCF;
  SignalCPole sCPole_ivZUb5mu;
  SignalTabhead sTabhead_Dm5IzYNq;
  SignalTabread sTabread_KJifhNk1;
  SignalTabread sTabread_zJ3rky0h;
  SignalRPole sRPole_0pEocXtF;
  SignalRPole sRPole_GwjBPccB;
  SignalDel1 sDel1_Xu3cZ4OC;
  SignalRPole sRPole_pEj3syVR;
  SignalTabhead sTabhead_Db9QiBSs;
  SignalTabread sTabread_xYoFTp9w;
  SignalTabread sTabread_Tjt3Xnjq;
  SignalCPole sCPole_JOUb8DQj;
  SignalBiquad_k sBiquad_k_kpGWg1dE;
  SignalTabhead sTabhead_gC9hL2NP;
  SignalTabread sTabread_hxB8cHgK;
  SignalTabread sTabread_u2SmSnnb;
  SignalRPole sRPole_KbqTmRLY;
  SignalPhasor sPhasor_IKk7vxeY;
  SignalTabhead sTabhead_syaIlWzx;
  SignalTabread sTabread_L29Q9STU;
  SignalTabread sTabread_SP43hs7p;
  SignalBiquad_k sBiquad_k_7hmI8N0J;
  SignalDel1 sDel1_v2jljQdV;
  SignalPhasor sPhasor_JEyKC37x;
  SignalRPole sRPole_HoXj9OZ9;
  SignalRPole sRPole_l2WaYiBc;
  SignalRPole sRPole_Bt0D7AKP;
  SignalDel1 sDel1_UGLydjQf;
  SignalRPole sRPole_K8g7FNzT;
  SignalRPole sRPole_6NP0xLT7;
  SignalRPole sRPole_mwjp8yNt;
  SignalDel1 sDel1_QuWRpZD0;
  SignalTabwrite sTabwrite_gKXP08a6;
  ControlVar cVar_7d4Vicc9;
  SignalVarf sVarf_MH2zLIdv;
  ControlBinop cBinop_Pko7zMdb;
  ControlBinop cBinop_J70Yr0im;
  ControlBinop cBinop_aqPCThsX;
  ControlBinop cBinop_dmWSzqQ3;
  ControlBinop cBinop_9gqnSemf;
  ControlBinop cBinop_qiu1tTRe;
  ControlVar cVar_1dnnKuKV;
  ControlBinop cBinop_EVTm3h04;
  ControlBinop cBinop_ocuXUPPk;
  SignalVarf sVarf_UbhVo1tn;
  ControlBinop cBinop_1NdaYn6s;
  ControlVar cVar_04ll5ckY;
  SignalVarf sVarf_AK8uhkQu;
  ControlBinop cBinop_E58gjcoA;
  ControlVar cVar_RI62KuWI;
  ControlBinop cBinop_KqqhOG9D;
  SignalVarf sVarf_irQa6qsg;
  SignalVarf sVarf_Ec9DWbeX;
  SignalVarf sVarf_QxhETTkF;
  SignalVarf sVarf_mgLZOV7g;
  ControlVar cVar_twqs907p;
  ControlBinop cBinop_TL40joUw;
  SignalVarf sVarf_Nu2g7ecd;
  ControlBinop cBinop_JgzpnzaN;
  ControlBinop cBinop_2eCBIR5Q;
  SignalVarf sVarf_hb0oakmR;
  ControlVar cVar_PodtCDqF;
  ControlBinop cBinop_Nb7YVudK;
  ControlBinop cBinop_DjJ7VBvj;
  SignalVarf sVarf_RItQH3cT;
  ControlBinop cBinop_BbAvYPho;
  ControlBinop cBinop_HGubuC1a;
  SignalVarf sVarf_YMG9qT6Q;
  ControlBinop cBinop_ankCPead;
  ControlVar cVar_XhhTQBQO;
  ControlBinop cBinop_pMk23xZu;
  ControlBinop cBinop_Fq2pLZYj;
  ControlVar cVar_A0tVhjSv;
  ControlBinop cBinop_QFLmspl0;
  ControlBinop cBinop_G9q3ujz4;
  ControlBinop cBinop_uswTIKMm;
  ControlBinop cBinop_uRHSqIxL;
  ControlBinop cBinop_6arS7pkZ;
  SignalVarf sVarf_ItYNj27C;
  ControlBinop cBinop_SGKLCi9D;
  ControlBinop cBinop_PRZizwbk;
  ControlBinop cBinop_fG7lot5f;
  ControlBinop cBinop_VfsrRsxn;
  SignalVarf sVarf_rpf5kzFp;
  ControlRandom cRandom_8Ges3EYa;
  ControlSlice cSlice_QnShJ56y;
  ControlBinop cBinop_kgtUE3WM;
  SignalVari sVari_B8Z401zA;
  ControlBinop cBinop_9GdHlvG2;
  ControlBinop cBinop_HbMwmH4j;
  ControlBinop cBinop_tm4v8FhJ;
  SignalVarf sVarf_ASF6fVkt;
  ControlBinop cBinop_HpqLFUO2;
  ControlBinop cBinop_sQB4qhi9;
  ControlVar cVar_zz3F29Tb;
  SignalVarf sVarf_uZrkAAcB;
  ControlBinop cBinop_cBsw8ERD;
  ControlBinop cBinop_lAqiFuH4;
  ControlBinop cBinop_OBVObo3u;
  ControlBinop cBinop_ezSbWyiS;
  SignalVarf sVarf_6E6kAX9O;
  ControlVar cVar_x1v9EGe7;
  ControlBinop cBinop_0RQcTA39;
  SignalVarf sVarf_kYHZHlgD;
  ControlBinop cBinop_I6udBtyu;
  ControlBinop cBinop_YD2YVjZ9;
  ControlBinop cBinop_scAL1N9N;
  ControlBinop cBinop_5lcp3vC0;
  SignalVari sVari_2roTgRYK;
  ControlRandom cRandom_R5YEeEao;
  ControlBinop cBinop_AhmVD5nq;
  ControlSlice cSlice_pdZ4zEhg;
  ControlBinop cBinop_4wOf5AHQ;
  SignalVarf sVarf_mI7mF7il;
  SignalVarf sVarf_bAv7AxsI;
  ControlBinop cBinop_r3057LgE;
  ControlBinop cBinop_BGgzYFr8;
  ControlBinop cBinop_0JinhOTH;
  ControlBinop cBinop_nOuCkMsW;
  ControlVar cVar_RnbpeaPW;
  ControlBinop cBinop_bdY6gRkj;
  ControlBinop cBinop_h94nLTqe;
  ControlBinop cBinop_Os8EKbXG;
  ControlIf cIf_KXJL8pMt;
  ControlBinop cBinop_CZQ5VsvQ;
  ControlBinop cBinop_hf7SlGMM;
  ControlVar cVar_17xOVnEM;
  ControlBinop cBinop_WDRTLaze;
  SignalVarf sVarf_ej9KianO;
  SignalVarf sVarf_3TObpgYJ;
  SignalVarf sVarf_JbFmwncb;
  SignalVarf sVarf_vmGjLSTk;
  SignalVarf sVarf_nClOXWwj;
  SignalVarf sVarf_Yz18Rhhm;
  ControlVar cVar_mPnhvmvm;
  SignalVarf sVarf_krJrDQk4;
  SignalVarf sVarf_uF0AwPf9;
  ControlBinop cBinop_kwmCeG5m;
  ControlBinop cBinop_9rm79Bbc;
  SignalVarf sVarf_eo8DdnE5;
  ControlBinop cBinop_LzJSXRyr;
  ControlBinop cBinop_wuD76zW9;
  ControlBinop cBinop_hOkU8WyG;
  ControlVar cVar_mRYmAxQF;
  ControlBinop cBinop_KfOu4UMT;
  ControlBinop cBinop_nrTiyHLA;
  SignalVarf sVarf_iFkl7kQI;
  SignalVarf sVarf_zqW1feKg;
  SignalVarf sVarf_PFnWvsKV;
  ControlVar cVar_TzEZS5tq;
  ControlBinop cBinop_2jPIGz8Y;
  ControlVar cVar_jMROeUo8;
  ControlBinop cBinop_1a9tVrWI;
  ControlBinop cBinop_1TAumj0M;
  ControlBinop cBinop_CEotCy2g;
  ControlBinop cBinop_ilsZtDH4;
  ControlBinop cBinop_Fks9gZQJ;
  ControlBinop cBinop_FbpQl9K6;
  ControlBinop cBinop_8yjmDK5M;
  ControlBinop cBinop_PcHwgKOk;
  ControlBinop cBinop_mb9rdT6t;
  ControlVar cVar_XbUBDpg0;
  ControlBinop cBinop_LfcVo5Qi;
  ControlBinop cBinop_Shp1KHF3;
  ControlBinop cBinop_UGjlu6Pm;
  ControlBinop cBinop_Vd8x85KJ;
  ControlBinop cBinop_NKbP0FFH;
  ControlBinop cBinop_GXgOf5f2;
  ControlBinop cBinop_nuKLQPph;
  SignalVarf sVarf_z4zpXWIy;
  SignalVarf sVarf_OIDFn7Ee;
  ControlBinop cBinop_iEYCzkEK;
  ControlBinop cBinop_l76J8PBs;
  ControlBinop cBinop_bqlfdMNm;
  ControlBinop cBinop_MxZTdgCa;
  ControlBinop cBinop_xBY59qB3;
  ControlVar cVar_fd3epV0Q;
  SignalVarf sVarf_8ymcTcRh;
  ControlVar cVar_aJ0GX80b;
  SignalVarf sVarf_zt6HJRxo;
  ControlBinop cBinop_7GbV5Vk2;
  ControlBinop cBinop_n3gNQPro;
  ControlIf cIf_bb2pcLyD;
  SignalVarf sVarf_DrDc8G9L;
  ControlBinop cBinop_wd6OOLtN;
  ControlBinop cBinop_lcDL2ugX;
  ControlBinop cBinop_Q5rrgqIf;
  ControlBinop cBinop_imUiSh1f;
  SignalVarf sVarf_V6xp4imd;
  SignalVarf sVarf_AcpglnXA;
  SignalVarf sVarf_YMsJpj6B;
  ControlVar cVar_pOuUpFTG;
  ControlBinop cBinop_ieZr3c9j;
  ControlBinop cBinop_tnL0zRnI;
  ControlBinop cBinop_HN0HnYyZ;
  ControlBinop cBinop_6qU7RHbB;
  ControlBinop cBinop_EPLRn6Ou;
  ControlVar cVar_J2FBVWk9;
  SignalVarf sVarf_enkgzMdT;
  SignalVarf sVarf_WbkyqBkZ;
  ControlVar cVar_DB31XlD3;
  ControlVar cVar_FQ7rr4aK;
  ControlBinop cBinop_2IrqY8eP;
  SignalVarf sVarf_r5J9ceax;
  ControlBinop cBinop_ZMeOdq8v;
  SignalVarf sVarf_eNDFXgXn;
  SignalVarf sVarf_ei6KeqgK;
  SignalVarf sVarf_iriMCZLE;
  ControlBinop cBinop_OcExrMws;
  ControlBinop cBinop_tnQL7RsA;
  ControlBinop cBinop_SH2pfmBm;
  ControlBinop cBinop_jwxt3dtX;
  ControlBinop cBinop_EE0T6EhW;
  ControlBinop cBinop_axui19BN;
  ControlBinop cBinop_4GZwtmHO;
  ControlVar cVar_2gWYYIFx;
  ControlBinop cBinop_MDJ95UJ1;
  ControlBinop cBinop_T2D4nX7o;
  ControlBinop cBinop_LTUOVojt;
  ControlVar cVar_dqm8vYuC;
  ControlBinop cBinop_42MQL6vJ;
  ControlBinop cBinop_Z3Ie7GFS;
  ControlBinop cBinop_JZWPFf4t;
  ControlBinop cBinop_0LLHO2nw;
  ControlBinop cBinop_t5jqnfDe;
  ControlBinop cBinop_5rgs5nkm;
  ControlBinop cBinop_Nj3Lhcna;
  SignalVarf sVarf_1GONl5DM;
  SignalVarf sVarf_WCwyMLqi;
  SignalVarf sVarf_X52CoTPK;
  SignalVarf sVarf_eUEfhF0r;
  SignalVarf sVarf_fv79EzJ1;
  SignalVarf sVarf_bU99KDCB;
  ControlBinop cBinop_igpR7hdx;
  ControlBinop cBinop_mjVLRm8I;
  ControlBinop cBinop_N5q6wCoR;
  ControlBinop cBinop_N0p2VVKM;
  ControlBinop cBinop_Di3kG1J3;
  ControlVar cVar_y9u8HYQE;
  SignalVarf sVarf_aYQitTgv;
  SignalVarf sVarf_mncZzyRd;
  SignalVari sVari_mWWaADai;
  ControlBinop cBinop_NWcln88W;
  ControlRandom cRandom_0u3YyX9I;
  ControlSlice cSlice_WeXVu3vG;
  SignalVarf sVarf_qwWGg1lJ;
  ControlVar cVar_ELZLjWv3;
  SignalVarf sVarf_UFHSGVTE;
  ControlBinop cBinop_gASGMris;
  ControlBinop cBinop_0PXdpe5D;
  ControlVar cVar_HDcOV4H0;
  ControlVar cVar_uPtUGEME;
  SignalVarf sVarf_KKsSxKZj;
  ControlVar cVar_lxofoAkF;
  SignalVarf sVarf_JuKy4oOu;
  ControlBinop cBinop_DzerwWB8;
  ControlVar cVar_YhSuwwXD;
  ControlVar cVar_ZAiLgmgq;
  ControlBinop cBinop_DMhtBG7z;
  SignalVarf sVarf_VtK8gBp0;
  ControlBinop cBinop_LDaw3fng;
  ControlVar cVar_pRDyaQdJ;
  SignalVarf sVarf_WkF0ucOJ;
  ControlBinop cBinop_koC45kii;
  SignalVarf sVarf_wuzRkQYw;
  SignalVarf sVarf_nWO6u8ST;
  ControlBinop cBinop_cp7wESXz;
  ControlBinop cBinop_nLsxAWdl;
  ControlBinop cBinop_BISHraEC;
  ControlBinop cBinop_cROzhMAB;
  ControlBinop cBinop_pg2y3K9r;
  ControlBinop cBinop_qUQNbegd;
  ControlBinop cBinop_k2i5U7M5;
  ControlBinop cBinop_LR40p1B4;
  ControlBinop cBinop_ZTW4880r;
  ControlVar cVar_DrnOZBal;
  ControlBinop cBinop_6EENltQZ;
  ControlBinop cBinop_WYMiZCyp;
  ControlBinop cBinop_ZL3qKza9;
  ControlVar cVar_aEj7dOWo;
  ControlBinop cBinop_ftQBG00c;
  ControlBinop cBinop_54hiQNKc;
  ControlBinop cBinop_bWg1XxMf;
  ControlBinop cBinop_XRUY4NJM;
  ControlBinop cBinop_71XsB6qr;
  ControlDelay cDelay_tSHl6oB8;
  ControlBinop cBinop_SHOjC10I;
  HvTable hTable_KGTu4WzN;
  ControlBinop cBinop_KqusGvmf;
  ControlDelay cDelay_5kxlNLHa;
  SignalVarf sVarf_3kYwyU4X;
  SignalVarf sVarf_N8pmBJ91;
  SignalVarf sVarf_UnySrNga;
};

#endif // _HEAVY_CONTEXT_HEAVY_HPP_
