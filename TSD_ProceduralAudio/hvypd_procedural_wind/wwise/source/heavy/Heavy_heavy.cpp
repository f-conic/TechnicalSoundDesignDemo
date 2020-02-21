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

#include "Heavy_heavy.hpp"

#define Context(_c) reinterpret_cast<Heavy_heavy *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_heavy_new(double sampleRate) {
    return new Heavy_heavy(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_heavy_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_heavy(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_heavy::Heavy_heavy(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sBiquad_k_init(&sBiquad_k_z4NCoGXm, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sTabhead_init(&sTabhead_4agiJ8Yk, &hTable_KGTu4WzN);
  numBytes += sTabread_init(&sTabread_XY4PXO8b, &hTable_KGTu4WzN, false);
  numBytes += sTabread_init(&sTabread_ISBQqrlg, &hTable_KGTu4WzN, false);
  numBytes += sRPole_init(&sRPole_TODZ2rMA);
  numBytes += sPhasor_init(&sPhasor_Rb49DLpo, sampleRate);
  numBytes += sTabhead_init(&sTabhead_8VD0WAGS, &hTable_KGTu4WzN);
  numBytes += sTabread_init(&sTabread_F9AXNekL, &hTable_KGTu4WzN, false);
  numBytes += sTabread_init(&sTabread_dOXfMPCF, &hTable_KGTu4WzN, false);
  numBytes += sCPole_init(&sCPole_ivZUb5mu);
  numBytes += sTabhead_init(&sTabhead_Dm5IzYNq, &hTable_KGTu4WzN);
  numBytes += sTabread_init(&sTabread_KJifhNk1, &hTable_KGTu4WzN, false);
  numBytes += sTabread_init(&sTabread_zJ3rky0h, &hTable_KGTu4WzN, false);
  numBytes += sRPole_init(&sRPole_0pEocXtF);
  numBytes += sRPole_init(&sRPole_GwjBPccB);
  numBytes += sDel1_init(&sDel1_Xu3cZ4OC);
  numBytes += sRPole_init(&sRPole_pEj3syVR);
  numBytes += sTabhead_init(&sTabhead_Db9QiBSs, &hTable_KGTu4WzN);
  numBytes += sTabread_init(&sTabread_xYoFTp9w, &hTable_KGTu4WzN, false);
  numBytes += sTabread_init(&sTabread_Tjt3Xnjq, &hTable_KGTu4WzN, false);
  numBytes += sCPole_init(&sCPole_JOUb8DQj);
  numBytes += sBiquad_k_init(&sBiquad_k_kpGWg1dE, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sTabhead_init(&sTabhead_gC9hL2NP, &hTable_KGTu4WzN);
  numBytes += sTabread_init(&sTabread_hxB8cHgK, &hTable_KGTu4WzN, false);
  numBytes += sTabread_init(&sTabread_u2SmSnnb, &hTable_KGTu4WzN, false);
  numBytes += sRPole_init(&sRPole_KbqTmRLY);
  numBytes += sPhasor_init(&sPhasor_IKk7vxeY, sampleRate);
  numBytes += sTabhead_init(&sTabhead_syaIlWzx, &hTable_KGTu4WzN);
  numBytes += sTabread_init(&sTabread_L29Q9STU, &hTable_KGTu4WzN, false);
  numBytes += sTabread_init(&sTabread_SP43hs7p, &hTable_KGTu4WzN, false);
  numBytes += sBiquad_k_init(&sBiquad_k_7hmI8N0J, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sDel1_init(&sDel1_v2jljQdV);
  numBytes += sPhasor_k_init(&sPhasor_JEyKC37x, 0.1f, sampleRate);
  numBytes += sRPole_init(&sRPole_HoXj9OZ9);
  numBytes += sRPole_init(&sRPole_l2WaYiBc);
  numBytes += sRPole_init(&sRPole_Bt0D7AKP);
  numBytes += sDel1_init(&sDel1_UGLydjQf);
  numBytes += sRPole_init(&sRPole_K8g7FNzT);
  numBytes += sRPole_init(&sRPole_6NP0xLT7);
  numBytes += sRPole_init(&sRPole_mwjp8yNt);
  numBytes += sDel1_init(&sDel1_QuWRpZD0);
  numBytes += sTabwrite_init(&sTabwrite_gKXP08a6, &hTable_KGTu4WzN);
  numBytes += cVar_init_f(&cVar_7d4Vicc9, 0.0f);
  numBytes += sVarf_init(&sVarf_MH2zLIdv, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1dnnKuKV, 200.0f);
  numBytes += sVarf_init(&sVarf_UbhVo1tn, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_1NdaYn6s, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_04ll5ckY, 0.0f);
  numBytes += sVarf_init(&sVarf_AK8uhkQu, 1000.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_RI62KuWI, "del-a");
  numBytes += sVarf_init(&sVarf_irQa6qsg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ec9DWbeX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QxhETTkF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mgLZOV7g, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_twqs907p, 0.0f);
  numBytes += sVarf_init(&sVarf_Nu2g7ecd, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_2eCBIR5Q, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hb0oakmR, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_PodtCDqF, 3.0f);
  numBytes += sVarf_init(&sVarf_RItQH3cT, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_HGubuC1a, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YMG9qT6Q, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_XhhTQBQO, 3.0f);
  numBytes += cVar_init_f(&cVar_A0tVhjSv, 0.0f);
  numBytes += sVarf_init(&sVarf_ItYNj27C, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_fG7lot5f, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_rpf5kzFp, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_8Ges3EYa, 1626264541);
  numBytes += cSlice_init(&cSlice_QnShJ56y, 1, 1);
  numBytes += sVari_init(&sVari_B8Z401zA, 0, 0, false);
  numBytes += cBinop_init(&cBinop_HbMwmH4j, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ASF6fVkt, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zz3F29Tb, 0.5f);
  numBytes += sVarf_init(&sVarf_uZrkAAcB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6E6kAX9O, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_x1v9EGe7, 0.0f);
  numBytes += cBinop_init(&cBinop_0RQcTA39, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_kYHZHlgD, 0.0f, 0.0f, false);
  numBytes += sVari_init(&sVari_2roTgRYK, 0, 0, false);
  numBytes += cRandom_init(&cRandom_R5YEeEao, -308109112);
  numBytes += cSlice_init(&cSlice_pdZ4zEhg, 1, 1);
  numBytes += sVarf_init(&sVarf_mI7mF7il, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bAv7AxsI, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_nOuCkMsW, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_RnbpeaPW, 0.5f);
  numBytes += cIf_init(&cIf_KXJL8pMt, false);
  numBytes += cVar_init_f(&cVar_17xOVnEM, 1000.0f);
  numBytes += sVarf_init(&sVarf_ej9KianO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3TObpgYJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JbFmwncb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vmGjLSTk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nClOXWwj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Yz18Rhhm, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mPnhvmvm, 0.0f);
  numBytes += sVarf_init(&sVarf_krJrDQk4, 0.8f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uF0AwPf9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eo8DdnE5, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_wuD76zW9, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_mRYmAxQF, 0.07f);
  numBytes += sVarf_init(&sVarf_iFkl7kQI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zqW1feKg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PFnWvsKV, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_TzEZS5tq, "del-a");
  numBytes += cVar_init_f(&cVar_jMROeUo8, 200.0f);
  numBytes += cBinop_init(&cBinop_CEotCy2g, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ilsZtDH4, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Fks9gZQJ, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_XbUBDpg0, 40.0f);
  numBytes += cBinop_init(&cBinop_LfcVo5Qi, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_UGjlu6Pm, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Vd8x85KJ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_z4zpXWIy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OIDFn7Ee, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_bqlfdMNm, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_fd3epV0Q, 0.1f);
  numBytes += sVarf_init(&sVarf_8ymcTcRh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_aJ0GX80b, 1000.0f);
  numBytes += sVarf_init(&sVarf_zt6HJRxo, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_bb2pcLyD, false);
  numBytes += sVarf_init(&sVarf_DrDc8G9L, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_V6xp4imd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AcpglnXA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YMsJpj6B, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_pOuUpFTG, 0.0f);
  numBytes += cBinop_init(&cBinop_EPLRn6Ou, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_J2FBVWk9, 0.5f);
  numBytes += sVarf_init(&sVarf_enkgzMdT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WbkyqBkZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_DB31XlD3, 0.0f);
  numBytes += cVar_init_s(&cVar_FQ7rr4aK, "del-a");
  numBytes += sVarf_init(&sVarf_r5J9ceax, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eNDFXgXn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ei6KeqgK, 2.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iriMCZLE, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_tnQL7RsA, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_axui19BN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4GZwtmHO, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_2gWYYIFx, 40.0f);
  numBytes += cBinop_init(&cBinop_MDJ95UJ1, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_T2D4nX7o, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_dqm8vYuC, 400.0f);
  numBytes += cBinop_init(&cBinop_JZWPFf4t, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_1GONl5DM, 1000.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WCwyMLqi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_X52CoTPK, 2.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eUEfhF0r, 0.2f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fv79EzJ1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bU99KDCB, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Di3kG1J3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_y9u8HYQE, 4000.0f);
  numBytes += sVarf_init(&sVarf_aYQitTgv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mncZzyRd, 1.2f, 0.0f, false);
  numBytes += sVari_init(&sVari_mWWaADai, 0, 0, false);
  numBytes += cRandom_init(&cRandom_0u3YyX9I, 363213797);
  numBytes += cSlice_init(&cSlice_WeXVu3vG, 1, 1);
  numBytes += sVarf_init(&sVarf_qwWGg1lJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ELZLjWv3, 0.0f);
  numBytes += sVarf_init(&sVarf_UFHSGVTE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_HDcOV4H0, 0.0f);
  numBytes += cVar_init_s(&cVar_uPtUGEME, "del-a");
  numBytes += sVarf_init(&sVarf_KKsSxKZj, 2.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lxofoAkF, 0.0f);
  numBytes += sVarf_init(&sVarf_JuKy4oOu, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YhSuwwXD, 0.0f);
  numBytes += cVar_init_s(&cVar_ZAiLgmgq, "del-a");
  numBytes += sVarf_init(&sVarf_VtK8gBp0, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_pRDyaQdJ, "del-a");
  numBytes += sVarf_init(&sVarf_WkF0ucOJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wuzRkQYw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nWO6u8ST, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_cp7wESXz, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qUQNbegd, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_LR40p1B4, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_DrnOZBal, 800.0f);
  numBytes += cBinop_init(&cBinop_6EENltQZ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_aEj7dOWo, 1.0f);
  numBytes += cBinop_init(&cBinop_bWg1XxMf, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_XRUY4NJM, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_tSHl6oB8, 0.0f);
  numBytes += hTable_init(&hTable_KGTu4WzN, 256);
  numBytes += cDelay_init(this, &cDelay_5kxlNLHa, 0.0f);
  numBytes += sVarf_init(&sVarf_3kYwyU4X, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_N8pmBJ91, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UnySrNga, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_heavy::~Heavy_heavy() {
  hTable_free(&hTable_KGTu4WzN);
}

HvTable *Heavy_heavy::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x1839FFA2: return &hTable_KGTu4WzN; // del-a
    default: return nullptr;
  }
}

void Heavy_heavy::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xKL1eylZ_sendMessage);
      break;
    }
    case 0x5C92F556: { // q_branches_whistle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wZPBmPO0_sendMessage);
      break;
    }
    case 0x228BAFC9: { // vol_branches
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bzZ5iKmY_sendMessage);
      break;
    }
    case 0x67C201F5: { // vol_buildings
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iwssNkaj_sendMessage);
      break;
    }
    case 0x18604B87: { // vol_doorways
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sytVBw67_sendMessage);
      break;
    }
    case 0xBDBA399A: { // vol_leaves
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TT5cK8f4_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_heavy::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "vol_buildings";
        info->hash = 0x67C201F5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 3.0f;
        info->defaultVal = 0.7f;
        break;
      }
      case 1: {
        info->name = "q_branches_whistle";
        info->hash = 0x5C92F556;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1500.0f;
        info->defaultVal = 400.0f;
        break;
      }
      case 2: {
        info->name = "vol_branches";
        info->hash = 0x228BAFC9;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 15.0f;
        info->defaultVal = 5.0f;
        break;
      }
      case 3: {
        info->name = "vol_doorways";
        info->hash = 0x18604B87;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 10.0f;
        info->defaultVal = 3.0f;
        break;
      }
      case 4: {
        info->name = "vol_leaves";
        info->hash = 0xBDBA399A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 5.0f;
        info->defaultVal = 1.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 5;
}



/*
 * Send Function Implementations
 */


void Heavy_heavy::cVar_7d4Vicc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ve7jeNDz_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_dDRpOOVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cl6A1E9x_sendMessage);
}

void Heavy_heavy::cSystem_cl6A1E9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1NdaYn6s, HV_BINOP_DIVIDE, 1, m, &cBinop_1NdaYn6s_sendMessage);
}

void Heavy_heavy::cBinop_Pko7zMdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_qiu1tTRe_sendMessage);
}

void Heavy_heavy::cBinop_J70Yr0im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UbhVo1tn, m);
}

void Heavy_heavy::cBinop_aqPCThsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ocuXUPPk_sendMessage);
}

void Heavy_heavy::cBinop_dmWSzqQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_9gqnSemf_sendMessage);
}

void Heavy_heavy::cBinop_9gqnSemf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1NdaYn6s, HV_BINOP_DIVIDE, 0, m, &cBinop_1NdaYn6s_sendMessage);
}

void Heavy_heavy::cBinop_qiu1tTRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MH2zLIdv, m);
}

void Heavy_heavy::cVar_1dnnKuKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dmWSzqQ3_sendMessage);
}

void Heavy_heavy::cBinop_EVTm3h04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Pko7zMdb_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_J70Yr0im_sendMessage);
}

void Heavy_heavy::cBinop_ocuXUPPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EVTm3h04_sendMessage);
}

void Heavy_heavy::cBinop_1NdaYn6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RnJe2iEv_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_RnJe2iEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_aqPCThsX_sendMessage);
}

void Heavy_heavy::cSend_0PCwJV7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bzZ5iKmY_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_04ll5ckY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HgxFtxBT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_aft1Zjki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_17xOVnEM, 0, m, &cVar_17xOVnEM_sendMessage);
}

void Heavy_heavy::cBinop_E58gjcoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_irQa6qsg, m);
}

void Heavy_heavy::cVar_RI62KuWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V6hn6bsP_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_KqqhOG9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QxhETTkF, m);
}

void Heavy_heavy::cSystem_rt2PW6r6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KqqhOG9D_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ec9DWbeX, m);
}

void Heavy_heavy::cMsg_V6hn6bsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rt2PW6r6_sendMessage);
}

void Heavy_heavy::cSystem_VBsuiPx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_E58gjcoA_sendMessage);
}

void Heavy_heavy::cMsg_4fZo9xLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VBsuiPx2_sendMessage);
}

void Heavy_heavy::cVar_twqs907p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0PCwJV7D_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_TL40joUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hb0oakmR, m);
}

void Heavy_heavy::cBinop_JgzpnzaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2eCBIR5Q, HV_BINOP_MULTIPLY, 1, m, &cBinop_2eCBIR5Q_sendMessage);
}

void Heavy_heavy::cBinop_2eCBIR5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DjJ7VBvj_sendMessage);
}

void Heavy_heavy::cMsg_rrWQB6Yb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JgzpnzaN_sendMessage);
}

void Heavy_heavy::cSystem_Ao0kmYwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rrWQB6Yb_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_HxM4ppsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ao0kmYwN_sendMessage);
}

void Heavy_heavy::cVar_PodtCDqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2eCBIR5Q, HV_BINOP_MULTIPLY, 0, m, &cBinop_2eCBIR5Q_sendMessage);
}

void Heavy_heavy::cBinop_Nb7YVudK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TL40joUw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Nu2g7ecd, m);
}

void Heavy_heavy::cBinop_DjJ7VBvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Nb7YVudK_sendMessage);
}

void Heavy_heavy::cBinop_BbAvYPho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HGubuC1a, HV_BINOP_MULTIPLY, 1, m, &cBinop_HGubuC1a_sendMessage);
}

void Heavy_heavy::cMsg_ey7tfZ2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BbAvYPho_sendMessage);
}

void Heavy_heavy::cMsg_LR8xzuOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yjxDPF1Q_sendMessage);
}

void Heavy_heavy::cSystem_yjxDPF1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ey7tfZ2s_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_HGubuC1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Fq2pLZYj_sendMessage);
}

void Heavy_heavy::cBinop_ankCPead_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YMG9qT6Q, m);
}

void Heavy_heavy::cVar_XhhTQBQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HGubuC1a, HV_BINOP_MULTIPLY, 0, m, &cBinop_HGubuC1a_sendMessage);
}

void Heavy_heavy::cBinop_pMk23xZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ankCPead_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RItQH3cT, m);
}

void Heavy_heavy::cBinop_Fq2pLZYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_pMk23xZu_sendMessage);
}

void Heavy_heavy::cVar_A0tVhjSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_G9q3ujz4_sendMessage);
}

void Heavy_heavy::cBinop_QFLmspl0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_SGKLCi9D_sendMessage);
}

void Heavy_heavy::cBinop_G9q3ujz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_uswTIKMm_sendMessage);
}

void Heavy_heavy::cBinop_uswTIKMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fG7lot5f, HV_BINOP_DIVIDE, 0, m, &cBinop_fG7lot5f_sendMessage);
}

void Heavy_heavy::cBinop_uRHSqIxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6arS7pkZ_sendMessage);
}

void Heavy_heavy::cBinop_6arS7pkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QFLmspl0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VfsrRsxn_sendMessage);
}

void Heavy_heavy::cMsg_Wyn0edRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_PRZizwbk_sendMessage);
}

void Heavy_heavy::cBinop_SGKLCi9D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ItYNj27C, m);
}

void Heavy_heavy::cBinop_PRZizwbk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_uRHSqIxL_sendMessage);
}

void Heavy_heavy::cMsg_BSUAdk0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mGII6jlO_sendMessage);
}

void Heavy_heavy::cSystem_mGII6jlO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fG7lot5f, HV_BINOP_DIVIDE, 1, m, &cBinop_fG7lot5f_sendMessage);
}

void Heavy_heavy::cBinop_fG7lot5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wyn0edRy_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_VfsrRsxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rpf5kzFp, m);
}

void Heavy_heavy::cSwitchcase_WbcGEev2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QnShJ56y, 0, m, &cSlice_QnShJ56y_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8Ges3EYa, 0, m, &cRandom_8Ges3EYa_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cRandom_8Ges3EYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_kgtUE3WM_sendMessage);
}

void Heavy_heavy::cSlice_QnShJ56y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8Ges3EYa, 1, m, &cRandom_8Ges3EYa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cUnop_Xiamu6bf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dwmAcT8C_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_kgtUE3WM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Xiamu6bf_sendMessage);
}

void Heavy_heavy::cMsg_dwmAcT8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_B8Z401zA, m);
}

void Heavy_heavy::cMsg_awRCFfeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_9GdHlvG2_sendMessage);
}

void Heavy_heavy::cBinop_9GdHlvG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HbMwmH4j, HV_BINOP_MULTIPLY, 1, m, &cBinop_HbMwmH4j_sendMessage);
}

void Heavy_heavy::cMsg_BDOVFbPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yTfLjb8g_sendMessage);
}

void Heavy_heavy::cSystem_yTfLjb8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_awRCFfeM_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_HbMwmH4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_sQB4qhi9_sendMessage);
}

void Heavy_heavy::cBinop_tm4v8FhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uZrkAAcB, m);
}

void Heavy_heavy::cBinop_HpqLFUO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tm4v8FhJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ASF6fVkt, m);
}

void Heavy_heavy::cBinop_sQB4qhi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HpqLFUO2_sendMessage);
}

void Heavy_heavy::cVar_zz3F29Tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HbMwmH4j, HV_BINOP_MULTIPLY, 0, m, &cBinop_HbMwmH4j_sendMessage);
}

void Heavy_heavy::cBinop_cBsw8ERD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0RQcTA39, HV_BINOP_DIVIDE, 0, m, &cBinop_0RQcTA39_sendMessage);
}

void Heavy_heavy::cBinop_lAqiFuH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_I6udBtyu_sendMessage);
}

void Heavy_heavy::cBinop_OBVObo3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_cBsw8ERD_sendMessage);
}

void Heavy_heavy::cBinop_ezSbWyiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_YD2YVjZ9_sendMessage);
}

void Heavy_heavy::cMsg_59QI2z7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FAZhsE0K_sendMessage);
}

void Heavy_heavy::cSystem_FAZhsE0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0RQcTA39, HV_BINOP_DIVIDE, 1, m, &cBinop_0RQcTA39_sendMessage);
}

void Heavy_heavy::cVar_x1v9EGe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_OBVObo3u_sendMessage);
}

void Heavy_heavy::cBinop_0RQcTA39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oSppqm89_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_oSppqm89_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ezSbWyiS_sendMessage);
}

void Heavy_heavy::cBinop_I6udBtyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kYHZHlgD, m);
}

void Heavy_heavy::cBinop_YD2YVjZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_scAL1N9N_sendMessage);
}

void Heavy_heavy::cBinop_scAL1N9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lAqiFuH4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5lcp3vC0_sendMessage);
}

void Heavy_heavy::cBinop_5lcp3vC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6E6kAX9O, m);
}

void Heavy_heavy::cSwitchcase_2A5Ecrqu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pdZ4zEhg, 0, m, &cSlice_pdZ4zEhg_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_R5YEeEao, 0, m, &cRandom_R5YEeEao_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cRandom_R5YEeEao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_AhmVD5nq_sendMessage);
}

void Heavy_heavy::cBinop_AhmVD5nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FG3mAKvr_sendMessage);
}

void Heavy_heavy::cUnop_FG3mAKvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J5kLVjtc_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSlice_pdZ4zEhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_R5YEeEao, 1, m, &cRandom_R5YEeEao_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cMsg_J5kLVjtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_2roTgRYK, m);
}

void Heavy_heavy::cBinop_4wOf5AHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bAv7AxsI, m);
}

void Heavy_heavy::cBinop_r3057LgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BGgzYFr8_sendMessage);
}

void Heavy_heavy::cBinop_BGgzYFr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4wOf5AHQ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mI7mF7il, m);
}

void Heavy_heavy::cMsg_vzgc6pNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0JinhOTH_sendMessage);
}

void Heavy_heavy::cBinop_0JinhOTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOuCkMsW, HV_BINOP_MULTIPLY, 1, m, &cBinop_nOuCkMsW_sendMessage);
}

void Heavy_heavy::cBinop_nOuCkMsW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_r3057LgE_sendMessage);
}

void Heavy_heavy::cSystem_Ll8UVlzP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vzgc6pNm_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_wzRQbWm1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ll8UVlzP_sendMessage);
}

void Heavy_heavy::cVar_RnbpeaPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOuCkMsW, HV_BINOP_MULTIPLY, 0, m, &cBinop_nOuCkMsW_sendMessage);
}

void Heavy_heavy::cSend_ve7jeNDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TT5cK8f4_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_d7vgDrle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LGbtg9wM_sendMessage);
}

void Heavy_heavy::cSystem_LGbtg9wM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CmpvskuT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_bdY6gRkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DuTZxOod_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_CmpvskuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_h94nLTqe_sendMessage);
}

void Heavy_heavy::cBinop_h94nLTqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ej9KianO, m);
}

void Heavy_heavy::cMsg_DuTZxOod_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Os8EKbXG_sendMessage);
}

void Heavy_heavy::cBinop_Os8EKbXG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3TObpgYJ, m);
}

void Heavy_heavy::cMsg_RjQnMDfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bdY6gRkj_sendMessage);
}

void Heavy_heavy::cIf_KXJL8pMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_EhLzSdIl_sendMessage(_c, 0, m);
      cMsg_ne7IhtRj_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_VQHxRivr_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_hf7SlGMM_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_vmGjLSTk, m);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_CZQ5VsvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KXJL8pMt, 1, m, &cIf_KXJL8pMt_sendMessage);
}

void Heavy_heavy::cBinop_hf7SlGMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RjQnMDfY_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_17xOVnEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_CZQ5VsvQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KXJL8pMt, 0, m, &cIf_KXJL8pMt_sendMessage);
}

void Heavy_heavy::cBinop_WDRTLaze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JbFmwncb, m);
}

void Heavy_heavy::cMsg_EhLzSdIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_hf7SlGMM_sendMessage);
}

void Heavy_heavy::cMsg_VQHxRivr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WDRTLaze_sendMessage);
}

void Heavy_heavy::cMsg_ne7IhtRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JbFmwncb, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vmGjLSTk, m);
}

void Heavy_heavy::cVar_mPnhvmvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3kyt0EJv_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_kwmCeG5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hOkU8WyG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eo8DdnE5, m);
}

void Heavy_heavy::cBinop_9rm79Bbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kwmCeG5m_sendMessage);
}

void Heavy_heavy::cMsg_zwX4RZev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_LzJSXRyr_sendMessage);
}

void Heavy_heavy::cBinop_LzJSXRyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wuD76zW9, HV_BINOP_MULTIPLY, 1, m, &cBinop_wuD76zW9_sendMessage);
}

void Heavy_heavy::cSystem_wUEEnnY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zwX4RZev_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_f9E7Jg4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wUEEnnY4_sendMessage);
}

void Heavy_heavy::cBinop_wuD76zW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9rm79Bbc_sendMessage);
}

void Heavy_heavy::cBinop_hOkU8WyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uF0AwPf9, m);
}

void Heavy_heavy::cVar_mRYmAxQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wuD76zW9, HV_BINOP_MULTIPLY, 0, m, &cBinop_wuD76zW9_sendMessage);
}

void Heavy_heavy::cMsg_VdG0JABh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_aJ0GX80b, 0, m, &cVar_aJ0GX80b_sendMessage);
}

void Heavy_heavy::cBinop_KfOu4UMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zqW1feKg, m);
}

void Heavy_heavy::cBinop_nrTiyHLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iFkl7kQI, m);
}

void Heavy_heavy::cSystem_uH1xty4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KfOu4UMT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PFnWvsKV, m);
}

void Heavy_heavy::cSystem_l0LWPtoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nrTiyHLA_sendMessage);
}

void Heavy_heavy::cMsg_UaUKmknn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l0LWPtoK_sendMessage);
}

void Heavy_heavy::cVar_TzEZS5tq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QdpQrAbT_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_QdpQrAbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uH1xty4H_sendMessage);
}

void Heavy_heavy::cReceive_wZPBmPO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1GONl5DM, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_AK8uhkQu, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1GONl5DM, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_AK8uhkQu, m);
}

void Heavy_heavy::cBinop_2jPIGz8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fks9gZQJ, HV_BINOP_DIVIDE, 1, m, &cBinop_Fks9gZQJ_sendMessage);
}

void Heavy_heavy::cVar_jMROeUo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_1a9tVrWI_sendMessage);
}

void Heavy_heavy::cBinop_1a9tVrWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LfcVo5Qi, HV_BINOP_DIVIDE, 0, m, &cBinop_LfcVo5Qi_sendMessage);
}

void Heavy_heavy::cBinop_1TAumj0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mb9rdT6t_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGjlu6Pm, HV_BINOP_ADD, 0, m, &cBinop_UGjlu6Pm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_FbpQl9K6_sendMessage);
}

void Heavy_heavy::cBinop_CEotCy2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nuKLQPph_sendMessage);
}

void Heavy_heavy::cBinop_ilsZtDH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_z4NCoGXm, 1, m);
}

void Heavy_heavy::cBinop_Fks9gZQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1TAumj0M_sendMessage);
}

void Heavy_heavy::cBinop_FbpQl9K6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ilsZtDH4, HV_BINOP_MULTIPLY, 0, m, &cBinop_ilsZtDH4_sendMessage);
}

void Heavy_heavy::cBinop_8yjmDK5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_z4NCoGXm, 5, m);
}

void Heavy_heavy::cBinop_PcHwgKOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GXgOf5f2_sendMessage);
}

void Heavy_heavy::cBinop_mb9rdT6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Shp1KHF3_sendMessage);
}

void Heavy_heavy::cVar_XbUBDpg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_2jPIGz8Y_sendMessage);
}

void Heavy_heavy::cBinop_LfcVo5Qi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vd8x85KJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Vd8x85KJ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_nyBjdReH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Fks9gZQJ, HV_BINOP_DIVIDE, 0, m, &cBinop_Fks9gZQJ_sendMessage);
}

void Heavy_heavy::cBinop_Shp1KHF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_PcHwgKOk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CEotCy2g, HV_BINOP_MULTIPLY, 0, m, &cBinop_CEotCy2g_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vd8x85KJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Vd8x85KJ_sendMessage);
}

void Heavy_heavy::cBinop_UGjlu6Pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ilsZtDH4, HV_BINOP_MULTIPLY, 1, m, &cBinop_ilsZtDH4_sendMessage);
}

void Heavy_heavy::cUnop_nyBjdReH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_NKbP0FFH_sendMessage);
}

void Heavy_heavy::cBinop_Vd8x85KJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGjlu6Pm, HV_BINOP_ADD, 1, m, &cBinop_UGjlu6Pm_sendMessage);
}

void Heavy_heavy::cSystem_6oi7eK1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LfcVo5Qi, HV_BINOP_DIVIDE, 1, m, &cBinop_LfcVo5Qi_sendMessage);
}

void Heavy_heavy::cMsg_HsharESC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6oi7eK1r_sendMessage);
}

void Heavy_heavy::cBinop_NKbP0FFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CEotCy2g, HV_BINOP_MULTIPLY, 1, m, &cBinop_CEotCy2g_sendMessage);
}

void Heavy_heavy::cBinop_GXgOf5f2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8yjmDK5M_sendMessage);
}

void Heavy_heavy::cBinop_nuKLQPph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_z4NCoGXm, 4, m);
}

void Heavy_heavy::cCast_C83CiasE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jMROeUo8, 0, m, &cVar_jMROeUo8_sendMessage);
}

void Heavy_heavy::cBinop_iEYCzkEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OIDFn7Ee, m);
}

void Heavy_heavy::cMsg_k9J9hsMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D3gbJwxx_sendMessage);
}

void Heavy_heavy::cSystem_D3gbJwxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TJaReTuy_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_l76J8PBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bqlfdMNm, HV_BINOP_MULTIPLY, 1, m, &cBinop_bqlfdMNm_sendMessage);
}

void Heavy_heavy::cBinop_bqlfdMNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xBY59qB3_sendMessage);
}

void Heavy_heavy::cMsg_TJaReTuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_l76J8PBs_sendMessage);
}

void Heavy_heavy::cBinop_MxZTdgCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iEYCzkEK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8ymcTcRh, m);
}

void Heavy_heavy::cBinop_xBY59qB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MxZTdgCa_sendMessage);
}

void Heavy_heavy::cVar_fd3epV0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bqlfdMNm, HV_BINOP_MULTIPLY, 0, m, &cBinop_bqlfdMNm_sendMessage);
}

void Heavy_heavy::cMsg_MnA8FXoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_V6xp4imd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DrDc8G9L, m);
}

void Heavy_heavy::cVar_aJ0GX80b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_n3gNQPro_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_bb2pcLyD, 0, m, &cIf_bb2pcLyD_sendMessage);
}

void Heavy_heavy::cSystem_aegqVCHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cPkTkfc7_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_KSZqp0JI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aegqVCHO_sendMessage);
}

void Heavy_heavy::cBinop_7GbV5Vk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kHO046jh_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_cPkTkfc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_imUiSh1f_sendMessage);
}

void Heavy_heavy::cBinop_n3gNQPro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bb2pcLyD, 1, m, &cIf_bb2pcLyD_sendMessage);
}

void Heavy_heavy::cIf_bb2pcLyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_1hDCr9bq_sendMessage(_c, 0, m);
      cMsg_MnA8FXoS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_eQwAOiFg_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_lcDL2ugX_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_DrDc8G9L, m);
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cBinop_wd6OOLtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AcpglnXA, m);
}

void Heavy_heavy::cBinop_lcDL2ugX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TqwFzL6T_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Q5rrgqIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_V6xp4imd, m);
}

void Heavy_heavy::cMsg_kHO046jh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_wd6OOLtN_sendMessage);
}

void Heavy_heavy::cBinop_imUiSh1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zt6HJRxo, m);
}

void Heavy_heavy::cMsg_1hDCr9bq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_lcDL2ugX_sendMessage);
}

void Heavy_heavy::cMsg_TqwFzL6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_7GbV5Vk2_sendMessage);
}

void Heavy_heavy::cMsg_eQwAOiFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Q5rrgqIf_sendMessage);
}

void Heavy_heavy::cSend_3kyt0EJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_sytVBw67_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_pOuUpFTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qXfy5YP0_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_ieZr3c9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HN0HnYyZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_enkgzMdT, m);
}

void Heavy_heavy::cBinop_tnL0zRnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ieZr3c9j_sendMessage);
}

void Heavy_heavy::cBinop_HN0HnYyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WbkyqBkZ, m);
}

void Heavy_heavy::cBinop_6qU7RHbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EPLRn6Ou, HV_BINOP_MULTIPLY, 1, m, &cBinop_EPLRn6Ou_sendMessage);
}

void Heavy_heavy::cMsg_ADpDeSjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6qU7RHbB_sendMessage);
}

void Heavy_heavy::cBinop_EPLRn6Ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tnL0zRnI_sendMessage);
}

void Heavy_heavy::cMsg_IgoZRAjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Cegt3wmJ_sendMessage);
}

void Heavy_heavy::cSystem_Cegt3wmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ADpDeSjj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_J2FBVWk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EPLRn6Ou, HV_BINOP_MULTIPLY, 0, m, &cBinop_EPLRn6Ou_sendMessage);
}

void Heavy_heavy::cVar_DB31XlD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_FQ7rr4aK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QOqMpx7p_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_omZHmF4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZMeOdq8v_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eNDFXgXn, m);
}

void Heavy_heavy::cBinop_2IrqY8eP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DB31XlD3, 0, m, &cVar_DB31XlD3_sendMessage);
}

void Heavy_heavy::cSystem_ULsELuo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2IrqY8eP_sendMessage);
}

void Heavy_heavy::cMsg_qyL5bRU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ULsELuo8_sendMessage);
}

void Heavy_heavy::cMsg_QOqMpx7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_omZHmF4U_sendMessage);
}

void Heavy_heavy::cBinop_ZMeOdq8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_r5J9ceax, m);
}

void Heavy_heavy::cReceive_bzZ5iKmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ei6KeqgK, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mncZzyRd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ei6KeqgK, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mncZzyRd, m);
}

void Heavy_heavy::cBinop_OcExrMws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EE0T6EhW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tnQL7RsA, HV_BINOP_ADD, 0, m, &cBinop_tnQL7RsA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Z3Ie7GFS_sendMessage);
}

void Heavy_heavy::cBinop_tnQL7RsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_axui19BN, HV_BINOP_MULTIPLY, 1, m, &cBinop_axui19BN_sendMessage);
}

void Heavy_heavy::cMsg_nAXoQnUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lElczO0f_sendMessage);
}

void Heavy_heavy::cSystem_lElczO0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JZWPFf4t, HV_BINOP_DIVIDE, 1, m, &cBinop_JZWPFf4t_sendMessage);
}

void Heavy_heavy::cBinop_SH2pfmBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MDJ95UJ1, HV_BINOP_DIVIDE, 1, m, &cBinop_MDJ95UJ1_sendMessage);
}

void Heavy_heavy::cBinop_jwxt3dtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GZwtmHO, HV_BINOP_MULTIPLY, 1, m, &cBinop_4GZwtmHO_sendMessage);
}

void Heavy_heavy::cBinop_EE0T6EhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_t5jqnfDe_sendMessage);
}

void Heavy_heavy::cUnop_jXpN1NFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_jwxt3dtX_sendMessage);
}

void Heavy_heavy::cBinop_axui19BN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kpGWg1dE, 1, m);
}

void Heavy_heavy::cBinop_4GZwtmHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0LLHO2nw_sendMessage);
}

void Heavy_heavy::cVar_2gWYYIFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_SH2pfmBm_sendMessage);
}

void Heavy_heavy::cBinop_MDJ95UJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_OcExrMws_sendMessage);
}

void Heavy_heavy::cBinop_T2D4nX7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tnQL7RsA, HV_BINOP_ADD, 1, m, &cBinop_tnQL7RsA_sendMessage);
}

void Heavy_heavy::cBinop_LTUOVojt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_42MQL6vJ_sendMessage);
}

void Heavy_heavy::cVar_dqm8vYuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_5rgs5nkm_sendMessage);
}

void Heavy_heavy::cCast_D3QHxqG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dqm8vYuC, 0, m, &cVar_dqm8vYuC_sendMessage);
}

void Heavy_heavy::cBinop_42MQL6vJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Nj3Lhcna_sendMessage);
}

void Heavy_heavy::cBinop_Z3Ie7GFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_axui19BN, HV_BINOP_MULTIPLY, 0, m, &cBinop_axui19BN_sendMessage);
}

void Heavy_heavy::cBinop_JZWPFf4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T2D4nX7o, HV_BINOP_MULTIPLY, 1, m, &cBinop_T2D4nX7o_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_jXpN1NFK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MDJ95UJ1, HV_BINOP_DIVIDE, 0, m, &cBinop_MDJ95UJ1_sendMessage);
}

void Heavy_heavy::cBinop_0LLHO2nw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kpGWg1dE, 4, m);
}

void Heavy_heavy::cBinop_t5jqnfDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_LTUOVojt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GZwtmHO, HV_BINOP_MULTIPLY, 0, m, &cBinop_4GZwtmHO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_T2D4nX7o, HV_BINOP_MULTIPLY, 0, m, &cBinop_T2D4nX7o_sendMessage);
}

void Heavy_heavy::cBinop_5rgs5nkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JZWPFf4t, HV_BINOP_DIVIDE, 0, m, &cBinop_JZWPFf4t_sendMessage);
}

void Heavy_heavy::cBinop_Nj3Lhcna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kpGWg1dE, 5, m);
}

void Heavy_heavy::cSend_qXfy5YP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_iwssNkaj_sendMessage(_c, 0, m);
}

void Heavy_heavy::cReceive_xKL1eylZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WbcGEev2_onMessage(_c, NULL, 0, m, NULL);
  cMsg_BSUAdk0H_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_A0tVhjSv, 0, m, &cVar_A0tVhjSv_sendMessage);
  cMsg_HxM4ppsc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PodtCDqF, 0, m, &cVar_PodtCDqF_sendMessage);
  cMsg_LR8xzuOq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XhhTQBQO, 0, m, &cVar_XhhTQBQO_sendMessage);
  cSwitchcase_2A5Ecrqu_onMessage(_c, NULL, 0, m, NULL);
  cMsg_59QI2z7W_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x1v9EGe7, 0, m, &cVar_x1v9EGe7_sendMessage);
  cMsg_BDOVFbPe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zz3F29Tb, 0, m, &cVar_zz3F29Tb_sendMessage);
  cMsg_wzRQbWm1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RnbpeaPW, 0, m, &cVar_RnbpeaPW_sendMessage);
  cSwitchcase_Aoq0odG3_onMessage(_c, NULL, 0, m, NULL);
  cMsg_CaoeMLCQ_sendMessage(_c, 0, m);
  cMsg_dDRpOOVt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1dnnKuKV, 0, m, &cVar_1dnnKuKV_sendMessage);
  cMsg_WyNemgTB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_y9u8HYQE, 0, m, &cVar_y9u8HYQE_sendMessage);
  cMsg_f9E7Jg4T_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mRYmAxQF, 0, m, &cVar_mRYmAxQF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XbUBDpg0, 0, m, &cVar_XbUBDpg0_sendMessage);
  cMsg_HsharESC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jMROeUo8, 0, m, &cVar_jMROeUo8_sendMessage);
  cMsg_k9J9hsMr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fd3epV0Q, 0, m, &cVar_fd3epV0Q_sendMessage);
  cMsg_IgoZRAjS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_J2FBVWk9, 0, m, &cVar_J2FBVWk9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2gWYYIFx, 0, m, &cVar_2gWYYIFx_sendMessage);
  cMsg_nAXoQnUd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dqm8vYuC, 0, m, &cVar_dqm8vYuC_sendMessage);
  cMsg_KSZqp0JI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aJ0GX80b, 0, m, &cVar_aJ0GX80b_sendMessage);
  cMsg_d7vgDrle_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_17xOVnEM, 0, m, &cVar_17xOVnEM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aEj7dOWo, 0, m, &cVar_aEj7dOWo_sendMessage);
  cMsg_0AwQc0rY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DrnOZBal, 0, m, &cVar_DrnOZBal_sendMessage);
  cMsg_aft1Zjki_sendMessage(_c, 0, m);
  cMsg_VdG0JABh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RI62KuWI, 0, m, &cVar_RI62KuWI_sendMessage);
  cMsg_4fZo9xLR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TzEZS5tq, 0, m, &cVar_TzEZS5tq_sendMessage);
  cMsg_UaUKmknn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FQ7rr4aK, 0, m, &cVar_FQ7rr4aK_sendMessage);
  cMsg_qyL5bRU4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uPtUGEME, 0, m, &cVar_uPtUGEME_sendMessage);
  cMsg_5CYwUbLE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZAiLgmgq, 0, m, &cVar_ZAiLgmgq_sendMessage);
  cMsg_fJ4nMPux_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pRDyaQdJ, 0, m, &cVar_pRDyaQdJ_sendMessage);
  cMsg_1x0qBzS9_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_igpR7hdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fv79EzJ1, m);
}

void Heavy_heavy::cBinop_mjVLRm8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_igpR7hdx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bU99KDCB, m);
}

void Heavy_heavy::cBinop_N5q6wCoR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mjVLRm8I_sendMessage);
}

void Heavy_heavy::cBinop_N0p2VVKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Di3kG1J3, HV_BINOP_MULTIPLY, 1, m, &cBinop_Di3kG1J3_sendMessage);
}

void Heavy_heavy::cMsg_Uhw82vsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_N0p2VVKM_sendMessage);
}

void Heavy_heavy::cMsg_WyNemgTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CiJel7Mq_sendMessage);
}

void Heavy_heavy::cSystem_CiJel7Mq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Uhw82vsc_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_Di3kG1J3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_N5q6wCoR_sendMessage);
}

void Heavy_heavy::cVar_y9u8HYQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Di3kG1J3, HV_BINOP_MULTIPLY, 0, m, &cBinop_Di3kG1J3_sendMessage);
}

void Heavy_heavy::cReceive_iwssNkaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eUEfhF0r, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eUEfhF0r, m);
}

void Heavy_heavy::cMsg_bSGdKmDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_mWWaADai, m);
}

void Heavy_heavy::cBinop_NWcln88W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vDppEDmE_sendMessage);
}

void Heavy_heavy::cRandom_0u3YyX9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_NWcln88W_sendMessage);
}

void Heavy_heavy::cSlice_WeXVu3vG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0u3YyX9I, 1, m, &cRandom_0u3YyX9I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_heavy::cSwitchcase_Aoq0odG3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WeXVu3vG, 0, m, &cSlice_WeXVu3vG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0u3YyX9I, 0, m, &cRandom_0u3YyX9I_sendMessage);
      break;
    }
  }
}

void Heavy_heavy::cUnop_vDppEDmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bSGdKmDW_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_OdAAFAwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0PXdpe5D_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UFHSGVTE, m);
}

void Heavy_heavy::cVar_ELZLjWv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cSystem_X8nzgryL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gASGMris_sendMessage);
}

void Heavy_heavy::cMsg_5CYwUbLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X8nzgryL_sendMessage);
}

void Heavy_heavy::cBinop_gASGMris_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ELZLjWv3, 0, m, &cVar_ELZLjWv3_sendMessage);
}

void Heavy_heavy::cMsg_8DoObS2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OdAAFAwt_sendMessage);
}

void Heavy_heavy::cBinop_0PXdpe5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HDcOV4H0, 0, m, &cVar_HDcOV4H0_sendMessage);
}

void Heavy_heavy::cVar_HDcOV4H0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_uPtUGEME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8DoObS2e_sendMessage(_c, 0, m);
}

void Heavy_heavy::cVar_lxofoAkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cMsg_ooirf6Gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jOaDFosN_sendMessage);
}

void Heavy_heavy::cBinop_DzerwWB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YhSuwwXD, 0, m, &cVar_YhSuwwXD_sendMessage);
}

void Heavy_heavy::cVar_YhSuwwXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_heavy::cVar_ZAiLgmgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ooirf6Gg_sendMessage(_c, 0, m);
}

void Heavy_heavy::cSystem_nLgborKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DMhtBG7z_sendMessage);
}

void Heavy_heavy::cMsg_fJ4nMPux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nLgborKd_sendMessage);
}

void Heavy_heavy::cBinop_DMhtBG7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lxofoAkF, 0, m, &cVar_lxofoAkF_sendMessage);
}

void Heavy_heavy::cSystem_jOaDFosN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DzerwWB8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JuKy4oOu, m);
}

void Heavy_heavy::cMsg_1x0qBzS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OS3A8Let_sendMessage);
}

void Heavy_heavy::cSystem_OS3A8Let_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_koC45kii_sendMessage);
}

void Heavy_heavy::cBinop_LDaw3fng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wuzRkQYw, m);
}

void Heavy_heavy::cVar_pRDyaQdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oVHNuhIo_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_oVHNuhIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VBpn1QjJ_sendMessage);
}

void Heavy_heavy::cBinop_koC45kii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WkF0ucOJ, m);
}

void Heavy_heavy::cSystem_VBpn1QjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_LDaw3fng_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VtK8gBp0, m);
}

void Heavy_heavy::cReceive_sytVBw67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_X52CoTPK, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KKsSxKZj, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KKsSxKZj, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_X52CoTPK, m);
}

void Heavy_heavy::cSend_HgxFtxBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wZPBmPO0_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_cp7wESXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7hmI8N0J, 1, m);
}

void Heavy_heavy::cSystem_OVVegqJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XRUY4NJM, HV_BINOP_DIVIDE, 1, m, &cBinop_XRUY4NJM_sendMessage);
}

void Heavy_heavy::cMsg_0AwQc0rY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OVVegqJG_sendMessage);
}

void Heavy_heavy::cUnop_7CXkcumV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_WYMiZCyp_sendMessage);
}

void Heavy_heavy::cBinop_nLsxAWdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XRUY4NJM, HV_BINOP_DIVIDE, 0, m, &cBinop_XRUY4NJM_sendMessage);
}

void Heavy_heavy::cBinop_BISHraEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_71XsB6qr_sendMessage);
}

void Heavy_heavy::cBinop_cROzhMAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7hmI8N0J, 4, m);
}

void Heavy_heavy::cBinop_pg2y3K9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cp7wESXz, HV_BINOP_MULTIPLY, 0, m, &cBinop_cp7wESXz_sendMessage);
}

void Heavy_heavy::cBinop_qUQNbegd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cp7wESXz, HV_BINOP_MULTIPLY, 1, m, &cBinop_cp7wESXz_sendMessage);
}

void Heavy_heavy::cBinop_k2i5U7M5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZL3qKza9_sendMessage);
}

void Heavy_heavy::cBinop_LR40p1B4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cROzhMAB_sendMessage);
}

void Heavy_heavy::cBinop_ZTW4880r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BISHraEC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qUQNbegd, HV_BINOP_ADD, 0, m, &cBinop_qUQNbegd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_pg2y3K9r_sendMessage);
}

void Heavy_heavy::cVar_DrnOZBal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_nLsxAWdl_sendMessage);
}

void Heavy_heavy::cBinop_6EENltQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qUQNbegd, HV_BINOP_ADD, 1, m, &cBinop_qUQNbegd_sendMessage);
}

void Heavy_heavy::cBinop_WYMiZCyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LR40p1B4, HV_BINOP_MULTIPLY, 1, m, &cBinop_LR40p1B4_sendMessage);
}

void Heavy_heavy::cBinop_ZL3qKza9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7hmI8N0J, 5, m);
}

void Heavy_heavy::cVar_aEj7dOWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_ftQBG00c_sendMessage);
}

void Heavy_heavy::cBinop_ftQBG00c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bWg1XxMf, HV_BINOP_DIVIDE, 1, m, &cBinop_bWg1XxMf_sendMessage);
}

void Heavy_heavy::cBinop_54hiQNKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_k2i5U7M5_sendMessage);
}

void Heavy_heavy::cBinop_bWg1XxMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZTW4880r_sendMessage);
}

void Heavy_heavy::cCast_ZD9IzJEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DrnOZBal, 0, m, &cVar_DrnOZBal_sendMessage);
}

void Heavy_heavy::cBinop_XRUY4NJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6EENltQZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_6EENltQZ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_7CXkcumV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bWg1XxMf, HV_BINOP_DIVIDE, 0, m, &cBinop_bWg1XxMf_sendMessage);
}

void Heavy_heavy::cBinop_71XsB6qr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_54hiQNKc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LR40p1B4, HV_BINOP_MULTIPLY, 0, m, &cBinop_LR40p1B4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6EENltQZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_6EENltQZ_sendMessage);
}

void Heavy_heavy::cDelay_tSHl6oB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tSHl6oB8, m);
  cMsg_HN1Ifwte_sendMessage(_c, 0, m);
}

void Heavy_heavy::cBinop_SHOjC10I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_KqusGvmf_sendMessage);
}

void Heavy_heavy::cMsg_ID7KUU9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_tSHl6oB8, 2, m, &cDelay_tSHl6oB8_sendMessage);
}

void Heavy_heavy::cMsg_p8Rnah9z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_KGTu4WzN, 0, m, &hTable_KGTu4WzN_sendMessage);
}

void Heavy_heavy::cSystem_n7au4pzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SHOjC10I_sendMessage);
}

void Heavy_heavy::cMsg_CaoeMLCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n7au4pzr_sendMessage);
}

void Heavy_heavy::hTable_KGTu4WzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ID7KUU9e_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5kxlNLHa, 2, m, &cDelay_5kxlNLHa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9o6YO9TT_sendMessage);
}

void Heavy_heavy::cBinop_KqusGvmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p8Rnah9z_sendMessage(_c, 0, m);
}

void Heavy_heavy::cMsg_HN1Ifwte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_KGTu4WzN, 0, m, &hTable_KGTu4WzN_sendMessage);
}

void Heavy_heavy::cDelay_5kxlNLHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5kxlNLHa, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tSHl6oB8, 0, m, &cDelay_tSHl6oB8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5kxlNLHa, 0, m, &cDelay_5kxlNLHa_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_gKXP08a6, 1, m, NULL);
}

void Heavy_heavy::cCast_9o6YO9TT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5kxlNLHa, 0, m, &cDelay_5kxlNLHa_sendMessage);
}

void Heavy_heavy::cReceive_TT5cK8f4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_krJrDQk4, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_krJrDQk4, m);
}




/*
 * Context Process Implementation
 */

int Heavy_heavy::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_i(&sVari_mWWaADai, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_mWWaADai, VIi(Bi1));
    __hv_varwrite_f(&sVarf_WCwyMLqi, VIf(Bf1));
    __hv_varread_f(&sVarf_WCwyMLqi, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_z4NCoGXm, VIf(Bf1), VOf(Bf1));
    __hv_tabhead_f(&sTabhead_4agiJ8Yk, VOf(Bf0));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf0));
    __hv_varread_f(&sVarf_JuKy4oOu, VOf(Bf3));
    __hv_zero_f(VOf(Bf4));
    __hv_lt_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_XY4PXO8b, VIi(Bi0), VOf(Bf4));
    __hv_tabread_if(&sTabread_ISBQqrlg, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf4), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_min_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_max_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf0), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_8ymcTcRh, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_OIDFn7Ee, VOf(Bf5));
    __hv_rpole_f(&sRPole_TODZ2rMA, VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_varread_f(&sVarf_KKsSxKZj, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf3), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_Rb49DLpo, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_iriMCZLE, VIf(Bf0));
    __hv_varread_f(&sVarf_WCwyMLqi, VOf(Bf6));
    __hv_varread_f(&sVarf_WkF0ucOJ, VOf(Bf1));
    __hv_tabhead_f(&sTabhead_8VD0WAGS, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_wuzRkQYw, VOf(Bf1));
    __hv_min_f(VIf(ZERO), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf2));
    __hv_varread_f(&sVarf_VtK8gBp0, VOf(Bf1));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_F9AXNekL, VIi(Bi0), VOf(Bf5));
    __hv_tabread_if(&sTabread_dOXfMPCF, VIi(Bi1), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 400.0f, 400.0f, 400.0f, 400.0f, 400.0f, 400.0f, 400.0f, 400.0f);
    __hv_var_k_f(VOf(Bf5), 600.0f, 600.0f, 600.0f, 600.0f, 600.0f, 600.0f, 600.0f, 600.0f);
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ej9KianO, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_vmGjLSTk, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_JbFmwncb, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf6));
    __hv_varread_f(&sVarf_3TObpgYJ, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf3));
    __hv_cos_f(VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf6));
    __hv_gt_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sqrt_f(VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_ivZUb5mu, VIf(Bf2), VIf(ZERO), VIf(Bf4), VIf(Bf5), VOf(Bf5), VOf(Bf4));
    __hv_var_k_f(VOf(Bf4), 0.12f, 0.12f, 0.12f, 0.12f, 0.12f, 0.12f, 0.12f, 0.12f);
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_mncZzyRd, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf4), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf2));
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_Yz18Rhhm, VIf(Bf3));
    __hv_varread_f(&sVarf_WCwyMLqi, VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_varread_f(&sVarf_iFkl7kQI, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_Dm5IzYNq, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(ZERO), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf2));
    __hv_varread_f(&sVarf_PFnWvsKV, VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_KJifhNk1, VIi(Bi0), VOf(Bf1));
    __hv_tabread_if(&sTabread_zJ3rky0h, VIi(Bi1), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_zqW1feKg, VOf(Bf2));
    __hv_var_k_f(VOf(Bf2), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_eo8DdnE5, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_uF0AwPf9, VOf(Bf2));
    __hv_rpole_f(&sRPole_0pEocXtF, VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_max_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_UbhVo1tn, VOf(Bf7));
    __hv_rpole_f(&sRPole_GwjBPccB, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Xu3cZ4OC, VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_MH2zLIdv, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_bU99KDCB, VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_fv79EzJ1, VOf(Bf7));
    __hv_rpole_f(&sRPole_pEj3syVR, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_krJrDQk4, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf6), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_aYQitTgv, VIf(Bf1));
    __hv_varread_f(&sVarf_nClOXWwj, VOf(Bf8));
    __hv_varread_f(&sVarf_mgLZOV7g, VOf(Bf7));
    __hv_varread_f(&sVarf_aYQitTgv, VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_3kYwyU4X, VOf(Bf7));
    __hv_add_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_qwWGg1lJ, VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_z4zpXWIy, VOf(Bf7));
    __hv_add_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.45f, 0.45f, 0.45f, 0.45f, 0.45f, 0.45f, 0.45f, 0.45f);
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_WCwyMLqi, VOf(Bf8));
    __hv_tabhead_f(&sTabhead_Db9QiBSs, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf6), VIf(ZERO), VOf(Bf6));
    __hv_floor_f(VIf(Bf6), VOf(Bf7));
    __hv_varread_f(&sVarf_UFHSGVTE, VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_lt_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_xYoFTp9w, VIi(Bi0), VOf(Bf4));
    __hv_tabread_if(&sTabread_Tjt3Xnjq, VIi(Bi1), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_1GONl5DM, VOf(Bf7));
    __hv_varread_f(&sVarf_AK8uhkQu, VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_zt6HJRxo, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_DrDc8G9L, VOf(Bf7));
    __hv_min_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_V6xp4imd, VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_varread_f(&sVarf_AcpglnXA, VOf(Bf7));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf6));
    __hv_cos_f(VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf8));
    __hv_gt_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sqrt_f(VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_cpole_f(&sCPole_JOUb8DQj, VIf(Bf7), VIf(ZERO), VIf(Bf2), VIf(Bf4), VOf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ei6KeqgK, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf5), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf7), VOf(Bf8));
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf8), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_z4zpXWIy, VIf(Bf9));
    __hv_varwrite_f(&sVarf_nWO6u8ST, VIf(Bf1));
    __hv_varread_f(&sVarf_WCwyMLqi, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_kpGWg1dE, VIf(Bf1), VOf(Bf1));
    __hv_tabhead_f(&sTabhead_gC9hL2NP, VOf(Bf6));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_r5J9ceax, VOf(Bf6));
    __hv_min_f(VIf(ZERO), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf4));
    __hv_varread_f(&sVarf_eNDFXgXn, VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_hxB8cHgK, VIi(Bi0), VOf(Bf8));
    __hv_tabread_if(&sTabread_u2SmSnnb, VIi(Bi1), VOf(Bf6));
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf8), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_min_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f);
    __hv_max_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f);
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf4), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf6));
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf6), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_enkgzMdT, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_WbkyqBkZ, VOf(Bf7));
    __hv_rpole_f(&sRPole_KbqTmRLY, VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf1));
    __hv_varread_f(&sVarf_X52CoTPK, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f);
    __hv_var_k_f(VOf(Bf6), 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f);
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_phasor_f(&sPhasor_IKk7vxeY, VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf6), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf2));
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf2));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_YMsJpj6B, VIf(Bf5));
    __hv_varread_f(&sVarf_irQa6qsg, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_syaIlWzx, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf1), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_QxhETTkF, VOf(Bf4));
    __hv_min_f(VIf(ZERO), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf1));
    __hv_varread_f(&sVarf_Ec9DWbeX, VOf(Bf4));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_L29Q9STU, VIi(Bi0), VOf(Bf7));
    __hv_tabread_if(&sTabread_SP43hs7p, VIi(Bi1), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_WCwyMLqi, VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_7hmI8N0J, VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_del1_f(&sDel1_v2jljQdV, VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_eUEfhF0r, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf7), VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_UnySrNga, VIf(Bf6));
    __hv_varwrite_f(&sVarf_nClOXWwj, VIf(Bf5));
    __hv_varwrite_f(&sVarf_3kYwyU4X, VIf(Bf3));
    __hv_varwrite_f(&sVarf_qwWGg1lJ, VIf(Bf6));
    __hv_varwrite_f(&sVarf_N8pmBJ91, VIf(Bf9));
    __hv_varwrite_f(&sVarf_mgLZOV7g, VIf(Bf0));
    __hv_phasor_k_f(&sPhasor_JEyKC37x, VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf0));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_varread_i(&sVari_2roTgRYK, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_varwrite_i(&sVari_2roTgRYK, VIi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_mI7mF7il, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_bAv7AxsI, VOf(Bf0));
    __hv_rpole_f(&sRPole_HoXj9OZ9, VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_ASF6fVkt, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_uZrkAAcB, VOf(Bf0));
    __hv_rpole_f(&sRPole_l2WaYiBc, VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_6E6kAX9O, VOf(Bf3));
    __hv_rpole_f(&sRPole_Bt0D7AKP, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_UGLydjQf, VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_kYHZHlgD, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f);
    __hv_fms_f(VIf(Bf3), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_max_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_varread_i(&sVari_B8Z401zA, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_i(&sVari_B8Z401zA, VIi(Bi1));
    __hv_varread_f(&sVarf_Nu2g7ecd, VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_hb0oakmR, VOf(Bf6));
    __hv_rpole_f(&sRPole_K8g7FNzT, VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_RItQH3cT, VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_YMG9qT6Q, VOf(Bf6));
    __hv_rpole_f(&sRPole_6NP0xLT7, VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_rpf5kzFp, VOf(Bf3));
    __hv_rpole_f(&sRPole_mwjp8yNt, VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_QuWRpZD0, VIf(Bf3), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_ItYNj27C, VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_gKXP08a6, VIf(Bf6));
    __hv_varread_f(&sVarf_iriMCZLE, VOf(Bf6));
    __hv_varread_f(&sVarf_UnySrNga, VOf(Bf9));
    __hv_varread_f(&sVarf_N8pmBJ91, VOf(Bf5));
    __hv_add_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Yz18Rhhm, VOf(Bf9));
    __hv_add_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_nWO6u8ST, VOf(Bf5));
    __hv_add_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_YMsJpj6B, VOf(Bf9));
    __hv_add_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 0.45f, 0.45f, 0.45f, 0.45f, 0.45f, 0.45f, 0.45f, 0.45f);
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_heavy::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_heavy::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
