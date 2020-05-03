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

#include "Heavy_windGen.hpp"

#define Context(_c) reinterpret_cast<Heavy_windGen *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_windGen_new(double sampleRate) {
    return new Heavy_windGen(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_windGen_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_windGen(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_windGen::Heavy_windGen(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabhead_init(&sTabhead_FlUfUVok, &hTable_spYlychT);
  numBytes += sTabread_init(&sTabread_GXKoAZll, &hTable_spYlychT, false);
  numBytes += sTabread_init(&sTabread_cRq04gcO, &hTable_spYlychT, false);
  numBytes += sCPole_init(&sCPole_gj4IW0R1);
  numBytes += sTabhead_init(&sTabhead_Twf3b2kK, &hTable_spYlychT);
  numBytes += sTabread_init(&sTabread_eTp7qZXD, &hTable_spYlychT, false);
  numBytes += sTabread_init(&sTabread_4i5dmliu, &hTable_spYlychT, false);
  numBytes += sBiquad_k_init(&sBiquad_k_Dm9GL8hZ, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sDel1_init(&sDel1_PjHHYJ8K);
  numBytes += sTabhead_init(&sTabhead_YdJxrPVT, &hTable_spYlychT);
  numBytes += sTabread_init(&sTabread_kac0wRpQ, &hTable_spYlychT, false);
  numBytes += sTabread_init(&sTabread_Qjb8RhDs, &hTable_spYlychT, false);
  numBytes += sCPole_init(&sCPole_qRsf5CBy);
  numBytes += sTabhead_init(&sTabhead_7FJ2vbLS, &hTable_spYlychT);
  numBytes += sTabread_init(&sTabread_Qx7ONZhV, &hTable_spYlychT, false);
  numBytes += sTabread_init(&sTabread_5yPKNLw3, &hTable_spYlychT, false);
  numBytes += sRPole_init(&sRPole_gu9mcFdm);
  numBytes += sRPole_init(&sRPole_YZ3OiX1T);
  numBytes += sDel1_init(&sDel1_O9rKdXJ1);
  numBytes += sRPole_init(&sRPole_qfq5d57P);
  numBytes += sBiquad_k_init(&sBiquad_k_TWYN0EXQ, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sTabhead_init(&sTabhead_1Wk2pKEK, &hTable_spYlychT);
  numBytes += sTabread_init(&sTabread_3ZqJrYPJ, &hTable_spYlychT, false);
  numBytes += sTabread_init(&sTabread_zCz3PpM2, &hTable_spYlychT, false);
  numBytes += sRPole_init(&sRPole_48d5mzmx);
  numBytes += sPhasor_init(&sPhasor_xgSGQTB1, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_zBjX4SMt, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sTabhead_init(&sTabhead_tb8ZUi97, &hTable_spYlychT);
  numBytes += sTabread_init(&sTabread_hrkAK5x2, &hTable_spYlychT, false);
  numBytes += sTabread_init(&sTabread_gMHroshT, &hTable_spYlychT, false);
  numBytes += sRPole_init(&sRPole_iw5MDSKl);
  numBytes += sPhasor_init(&sPhasor_oLEIN0wU, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_fKP08iwB, 0.1f, sampleRate);
  numBytes += sRPole_init(&sRPole_e0KQ32CS);
  numBytes += sRPole_init(&sRPole_Y0VpjC5s);
  numBytes += sRPole_init(&sRPole_gwaD4Rnz);
  numBytes += sDel1_init(&sDel1_Ik6k3rte);
  numBytes += sRPole_init(&sRPole_EqlYbrMa);
  numBytes += sRPole_init(&sRPole_WpTbkRFR);
  numBytes += sRPole_init(&sRPole_yLnv67vZ);
  numBytes += sDel1_init(&sDel1_QgVcNjvi);
  numBytes += sTabwrite_init(&sTabwrite_FhMXREbk, &hTable_spYlychT);
  numBytes += cVar_init_f(&cVar_cyraW2SN, 0.0f);
  numBytes += sVarf_init(&sVarf_l5hhZHL6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tYbaZYML, 0.45f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_5CpX96HO, "del-a");
  numBytes += sVarf_init(&sVarf_EJDaROSP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3PZ3CDp0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HRE33aGl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cWgkNgOV, 2.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5NZ5AedU, 1000.0f);
  numBytes += sVarf_init(&sVarf_Knqqopca, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Sl5aFLeD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4ufXwHlQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zzyweif8, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_LegADxHi, false);
  numBytes += cBinop_init(&cBinop_cvWRebaz, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_uvBIxlwQ, 0.07f);
  numBytes += sVarf_init(&sVarf_IzSIigD6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5pYbPBTs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2MB6b3aa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vffhrFzo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_cQX4UFcs, 4000.0f);
  numBytes += cBinop_init(&cBinop_DZjxhQWj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_oNJfWks0, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_bhp8tauH, "del-a");
  numBytes += cVar_init_f(&cVar_620riYJ1, 0.0f);
  numBytes += sVarf_init(&sVarf_EF50fPR0, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4476W1eS, 0.0f);
  numBytes += sVarf_init(&sVarf_9v224X5j, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_qwf7bQJS, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XuTGm5oR, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_duTf7qhP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_GLtBa7Ui, 40.0f);
  numBytes += cBinop_init(&cBinop_FFj2Z6tW, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_pdmYwzlX, 200.0f);
  numBytes += cBinop_init(&cBinop_YM1I5VSl, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_dalKFzU3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_m9yBCBY0, 0.0f);
  numBytes += cSlice_init(&cSlice_roH0Knax, 1, 1);
  numBytes += cRandom_init(&cRandom_yM64lNTc, 1742035791);
  numBytes += sVari_init(&sVari_rE9yBWsR, 0, 0, false);
  numBytes += sVarf_init(&sVarf_DzCuV7EE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_WIVIYAcW, 0.1f);
  numBytes += cBinop_init(&cBinop_dA8mFBs4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_O2QXY4CX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bZt6VyJ6, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_3zNtiVCY, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_VoQItGYq, 0.5f);
  numBytes += sVarf_init(&sVarf_uruExZKR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sFlbCBBy, 1.2f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MG9r5lq8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0gE7JUSh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zE4wDVS7, 1000.0f);
  numBytes += sVarf_init(&sVarf_vSveWv11, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_j0g6vvGO, false);
  numBytes += sVarf_init(&sVarf_twRSP1PD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WLMyyxab, 1000.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FzQK82cm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TRrcpirM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Aybj4zjb, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_XuOfFf4k, "del-a");
  numBytes += cVar_init_f(&cVar_fUTV5NvH, 0.0f);
  numBytes += cVar_init_f(&cVar_GzUHNGLP, 0.0f);
  numBytes += sVarf_init(&sVarf_CCTowUa0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dIODxUcP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_XZ93fufm, 0.0f);
  numBytes += sVarf_init(&sVarf_pILr6UfK, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_0FIvRVlB, "del-a");
  numBytes += sVarf_init(&sVarf_Wgkd0q7P, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XAVegxys, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3uQu9dvG, 0.0f);
  numBytes += sVarf_init(&sVarf_PFIhmQXb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZQtUz39Q, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_KqfIycAg, 0.0f); // __div
  numBytes += sVari_init(&sVari_P6UojO3l, 0, 0, false);
  numBytes += cRandom_init(&cRandom_Fygbla1G, 1392811495);
  numBytes += cSlice_init(&cSlice_cre7gKan, 1, 1);
  numBytes += cBinop_init(&cBinop_38Gm5RKg, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_h6kHpfcy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0nX3QOcn, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_szCjaHUn, 0.5f);
  numBytes += sVarf_init(&sVarf_hF5cR2gK, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_29hgXvB7, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_I3b1ici7, 0.5f);
  numBytes += sVarf_init(&sVarf_uXRuv4Hj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wH3pfWdl, 3.0f);
  numBytes += sVarf_init(&sVarf_pJxSOZqn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_L3zLCbS6, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_kxOsLTkR, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZpfaUrnn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TbSLV8le, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Lu1ouIoQ, 0.0f);
  numBytes += cBinop_init(&cBinop_Y69HdJro, 0.0f); // __div
  numBytes += cSlice_init(&cSlice_GTixlW5T, 1, 1);
  numBytes += cRandom_init(&cRandom_YsklFfWR, -1598006462);
  numBytes += sVari_init(&sVari_CP17y1Ff, 0, 0, false);
  numBytes += sVarf_init(&sVarf_tsF8wJhQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_gpDNMLui, 3.0f);
  numBytes += sVarf_init(&sVarf_sREve591, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_T3FVYocL, 0.0f); // __mul
  numBytes += cVar_init_s(&cVar_fjjgkLMH, "del-a");
  numBytes += sVarf_init(&sVarf_lzmSSGTw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gIl8ddj6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oqG04I7i, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_flozjRRE, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_uYtOSafz, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_lI3M2NO1, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Z2EDFxLM, 200.0f);
  numBytes += cVar_init_f(&cVar_kWCiLnPX, 0.0f);
  numBytes += sVarf_init(&sVarf_uN0YYn82, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Mn2cED2a, 2.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_4eh9LTmO, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nD1Xrz5c, 800.0f);
  numBytes += cBinop_init(&cBinop_ao1xhyBs, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Rgx7p5An, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_GuWjO0Hk, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9tXk9QEf, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_MCrmJQQx, 1.0f);
  numBytes += cBinop_init(&cBinop_EOGWIKqv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BHFN4QbF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1tH6hFi6, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_RsfxifzB, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0u937PZ7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ASYxM8BX, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_qcpSn9Jy, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_as4BF1bd, 400.0f);
  numBytes += cVar_init_f(&cVar_gaPl3hvw, 40.0f);
  numBytes += sVarf_init(&sVarf_QDNxVffR, 1000.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_B5snaMF6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6KTvfFcz, 0.8f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_trLriyDf, 0.0f);
  numBytes += sVarf_init(&sVarf_AuYVX3gQ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_FhtzxrKg, 0.0f);
  numBytes += sVarf_init(&sVarf_8ALmqcTI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VyxnrcC6, 0.2f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7T0dA7Pi, 0.45f, 0.0f, false);
  numBytes += hTable_init(&hTable_spYlychT, 256);
  numBytes += cDelay_init(this, &cDelay_DYGNbFhZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FE2y4TcF, 0.0f);
  numBytes += sVarf_init(&sVarf_o4Z63GLD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_TY1fnApG, 0.0f);
  numBytes += sVarf_init(&sVarf_EZvCPgDL, 2.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ctD5UrL4, 0.0f);
  numBytes += sVarf_init(&sVarf_CMcZzvnH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gLSfat2R, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jFz8OqiC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1NtnWdbS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_USHK0SOW, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_92XVRIoK, "del-a");
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_windGen::~Heavy_windGen() {
  hTable_free(&hTable_spYlychT);
}

HvTable *Heavy_windGen::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x1839FFA2: return &hTable_spYlychT; // del-a
    default: return nullptr;
  }
}

void Heavy_windGen::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UsqgB2ZU_sendMessage);
      break;
    }
    case 0x5C92F556: { // q_branches_whistle
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cE5FgxpC_sendMessage);
      break;
    }
    case 0x228BAFC9: { // vol_branches
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OnygtdZE_sendMessage);
      break;
    }
    case 0x67C201F5: { // vol_buildings
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XJCh0AX4_sendMessage);
      break;
    }
    case 0x18604B87: { // vol_doorways
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Khx1jNnI_sendMessage);
      break;
    }
    case 0xBDBA399A: { // vol_leaves
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TEPQLTbK_sendMessage);
      break;
    }
    case 0x60CE831: { // vol_master
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rFhWGTwR_sendMessage);
      break;
    }
    case 0x5F708FA1: { // wind_intensity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_g9YRzMfP_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_windGen::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "vol_master";
        info->hash = 0x60CE831;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.45f;
        info->defaultVal = 0.209f;
        break;
      }
      case 1: {
        info->name = "vol_leaves";
        info->hash = 0xBDBA399A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.6f;
        break;
      }
      case 2: {
        info->name = "vol_branches";
        info->hash = 0x228BAFC9;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 40.0f;
        info->defaultVal = 2.519f;
        break;
      }
      case 3: {
        info->name = "vol_buildings";
        info->hash = 0x67C201F5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.283f;
        break;
      }
      case 4: {
        info->name = "q_branches_whistle";
        info->hash = 0x5C92F556;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1500.0f;
        info->defaultVal = 637.7f;
        break;
      }
      case 5: {
        info->name = "vol_doorways";
        info->hash = 0x18604B87;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 30.0f;
        info->defaultVal = 8.267f;
        break;
      }
      case 6: {
        info->name = "wind_intensity";
        info->hash = 0x5F708FA1;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 2.0f;
        info->defaultVal = 1.165f;
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
  return 7;
}



/*
 * Send Function Implementations
 */


void Heavy_windGen::cVar_cyraW2SN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4eryWYSA_sendMessage(_c, 0, m);
}

void Heavy_windGen::cReceive_OnygtdZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cWgkNgOV, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sFlbCBBy, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cWgkNgOV, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sFlbCBBy, m);
}

void Heavy_windGen::cSend_7rQLx3AK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OnygtdZE_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_bYqj64MT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_zE4wDVS7, 0, m, &cVar_zE4wDVS7_sendMessage);
}

void Heavy_windGen::cSystem_LOOaFK9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aWZcN8bR_sendMessage);
}

void Heavy_windGen::cMsg_ThwcwXkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LOOaFK9f_sendMessage);
}

void Heavy_windGen::cSystem_0voFUrtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZO9NaCxB_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HRE33aGl, m);
}

void Heavy_windGen::cBinop_aWZcN8bR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3PZ3CDp0, m);
}

void Heavy_windGen::cVar_5CpX96HO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IqT11wk0_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_IqT11wk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0voFUrtD_sendMessage);
}

void Heavy_windGen::cBinop_ZO9NaCxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EJDaROSP, m);
}

void Heavy_windGen::cMsg_eTDRHdMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zzyweif8, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Knqqopca, m);
}

void Heavy_windGen::cBinop_m9d3K5Px_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Sl5aFLeD, m);
}

void Heavy_windGen::cBinop_o1p5uDHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_keMZVH4q_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_6kgA67KT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_o1p5uDHq_sendMessage);
}

void Heavy_windGen::cBinop_B4kfQ7qR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F29Xp4K5_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_hEq81dsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xKl3FCbJ_sendMessage);
}

void Heavy_windGen::cVar_5NZ5AedU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_16qRMLCZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_LegADxHi, 0, m, &cIf_LegADxHi_sendMessage);
}

void Heavy_windGen::cMsg_F29Xp4K5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_BtkoPqvk_sendMessage);
}

void Heavy_windGen::cBinop_BtkoPqvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4ufXwHlQ, m);
}

void Heavy_windGen::cMsg_qcxSFkzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x2Y3DCI0_sendMessage);
}

void Heavy_windGen::cSystem_x2Y3DCI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rP144bbO_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_keMZVH4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_B4kfQ7qR_sendMessage);
}

void Heavy_windGen::cMsg_rP144bbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_m9d3K5Px_sendMessage);
}

void Heavy_windGen::cBinop_xKl3FCbJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zzyweif8, m);
}

void Heavy_windGen::cIf_LegADxHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_6kgA67KT_sendMessage(_c, 0, m);
      cMsg_eTDRHdMm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_hEq81dsR_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_o1p5uDHq_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_Knqqopca, m);
      break;
    }
    default: return;
  }
}

void Heavy_windGen::cBinop_16qRMLCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LegADxHi, 1, m, &cIf_LegADxHi_sendMessage);
}

void Heavy_windGen::cSend_Nd3iz2Md_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_rFhWGTwR_sendMessage(_c, 0, m);
}

void Heavy_windGen::cReceive_XJCh0AX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VyxnrcC6, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VyxnrcC6, m);
}

void Heavy_windGen::cBinop_Mkvkdx0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5pYbPBTs, m);
}

void Heavy_windGen::cBinop_M51DJVYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cvWRebaz, HV_BINOP_MULTIPLY, 1, m, &cBinop_cvWRebaz_sendMessage);
}

void Heavy_windGen::cBinop_cvWRebaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5xSrmXd3_sendMessage);
}

void Heavy_windGen::cMsg_yzaiF4qJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_M51DJVYk_sendMessage);
}

void Heavy_windGen::cSystem_TEh3ASgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yzaiF4qJ_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_Vb3h0pvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TEh3ASgo_sendMessage);
}

void Heavy_windGen::cVar_uvBIxlwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cvWRebaz, HV_BINOP_MULTIPLY, 0, m, &cBinop_cvWRebaz_sendMessage);
}

void Heavy_windGen::cBinop_5xSrmXd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rurWDkZQ_sendMessage);
}

void Heavy_windGen::cBinop_rurWDkZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Mkvkdx0Y_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IzSIigD6, m);
}

void Heavy_windGen::cReceive_TEPQLTbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6KTvfFcz, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6KTvfFcz, m);
}

void Heavy_windGen::cVar_cQX4UFcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DZjxhQWj, HV_BINOP_MULTIPLY, 0, m, &cBinop_DZjxhQWj_sendMessage);
}

void Heavy_windGen::cBinop_Vnf5mu7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2MB6b3aa, m);
}

void Heavy_windGen::cBinop_DZjxhQWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KMrrDQ1H_sendMessage);
}

void Heavy_windGen::cMsg_Z4PND2NY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SinbzF1S_sendMessage);
}

void Heavy_windGen::cSystem_BQx000ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z4PND2NY_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_DugDDVHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BQx000ut_sendMessage);
}

void Heavy_windGen::cBinop_SinbzF1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DZjxhQWj, HV_BINOP_MULTIPLY, 1, m, &cBinop_DZjxhQWj_sendMessage);
}

void Heavy_windGen::cBinop_KMrrDQ1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kraisuOr_sendMessage);
}

void Heavy_windGen::cBinop_kraisuOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Vnf5mu7C_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vffhrFzo, m);
}

void Heavy_windGen::cVar_bhp8tauH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xpUiMMjZ_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_TwVGbm8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4476W1eS, 0, m, &cVar_4476W1eS_sendMessage);
}

void Heavy_windGen::cSystem_MyMTVMaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Gbgg9S17_sendMessage);
}

void Heavy_windGen::cMsg_A4rY2AQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MyMTVMaz_sendMessage);
}

void Heavy_windGen::cVar_620riYJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_windGen::cBinop_Gbgg9S17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_620riYJ1, 0, m, &cVar_620riYJ1_sendMessage);
}

void Heavy_windGen::cMsg_xpUiMMjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UQCnvvkD_sendMessage);
}

void Heavy_windGen::cSystem_UQCnvvkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TwVGbm8O_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EF50fPR0, m);
}

void Heavy_windGen::cVar_4476W1eS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_windGen::cBinop_aUZnS1TF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FFj2Z6tW, HV_BINOP_DIVIDE, 0, m, &cBinop_FFj2Z6tW_sendMessage);
}

void Heavy_windGen::cBinop_qwf7bQJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YM1I5VSl, HV_BINOP_MULTIPLY, 1, m, &cBinop_YM1I5VSl_sendMessage);
}

void Heavy_windGen::cBinop_XuTGm5oR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WsSuo66G_sendMessage);
}

void Heavy_windGen::cBinop_duTf7qhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kduWoaTW_sendMessage);
}

void Heavy_windGen::cUnop_dILXJw3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_x2XnNjqn_sendMessage);
}

void Heavy_windGen::cVar_GLtBa7Ui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_bdwq7lvk_sendMessage);
}

void Heavy_windGen::cBinop_x2XnNjqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_duTf7qhP, HV_BINOP_MULTIPLY, 1, m, &cBinop_duTf7qhP_sendMessage);
}

void Heavy_windGen::cBinop_bdwq7lvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XuTGm5oR, HV_BINOP_DIVIDE, 1, m, &cBinop_XuTGm5oR_sendMessage);
}

void Heavy_windGen::cBinop_EYAzKvgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TWYN0EXQ, 5, m);
}

void Heavy_windGen::cBinop_FFj2Z6tW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dalKFzU3, HV_BINOP_MULTIPLY, 1, m, &cBinop_dalKFzU3_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_dILXJw3T_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XuTGm5oR, HV_BINOP_DIVIDE, 0, m, &cBinop_XuTGm5oR_sendMessage);
}

void Heavy_windGen::cCast_KimsK1T4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pdmYwzlX, 0, m, &cVar_pdmYwzlX_sendMessage);
}

void Heavy_windGen::cBinop_9tBhgfuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qhX8GIxS_sendMessage);
}

void Heavy_windGen::cBinop_kduWoaTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TWYN0EXQ, 4, m);
}

void Heavy_windGen::cVar_pdmYwzlX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_aUZnS1TF_sendMessage);
}

void Heavy_windGen::cBinop_3JKTtUn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_9tBhgfuW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_duTf7qhP, HV_BINOP_MULTIPLY, 0, m, &cBinop_duTf7qhP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dalKFzU3, HV_BINOP_MULTIPLY, 0, m, &cBinop_dalKFzU3_sendMessage);
}

void Heavy_windGen::cSystem_Bi9GjGUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FFj2Z6tW, HV_BINOP_DIVIDE, 1, m, &cBinop_FFj2Z6tW_sendMessage);
}

void Heavy_windGen::cMsg_rT5legGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Bi9GjGUo_sendMessage);
}

void Heavy_windGen::cBinop_YM1I5VSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TWYN0EXQ, 1, m);
}

void Heavy_windGen::cBinop_1lAittUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3JKTtUn3_sendMessage);
}

void Heavy_windGen::cBinop_qhX8GIxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EYAzKvgX_sendMessage);
}

void Heavy_windGen::cBinop_dalKFzU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwf7bQJS, HV_BINOP_ADD, 1, m, &cBinop_qwf7bQJS_sendMessage);
}

void Heavy_windGen::cBinop_WsSuo66G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1lAittUi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qwf7bQJS, HV_BINOP_ADD, 0, m, &cBinop_qwf7bQJS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_H8QCMI8g_sendMessage);
}

void Heavy_windGen::cBinop_H8QCMI8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YM1I5VSl, HV_BINOP_MULTIPLY, 0, m, &cBinop_YM1I5VSl_sendMessage);
}

void Heavy_windGen::cReceive_g9YRzMfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XAVegxys, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XAVegxys, m);
}

void Heavy_windGen::cVar_m9yBCBY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Nd3iz2Md_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_4MpoUezF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_DEFuuLf6_sendMessage);
}

void Heavy_windGen::cSlice_roH0Knax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yM64lNTc, 1, m, &cRandom_yM64lNTc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_windGen::cSwitchcase_vKX7Ow7R_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_roH0Knax, 0, m, &cSlice_roH0Knax_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yM64lNTc, 0, m, &cRandom_yM64lNTc_sendMessage);
      break;
    }
  }
}

void Heavy_windGen::cUnop_DEFuuLf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FLLDqNEj_sendMessage(_c, 0, m);
}

void Heavy_windGen::cRandom_yM64lNTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_4MpoUezF_sendMessage);
}

void Heavy_windGen::cMsg_FLLDqNEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_rE9yBWsR, m);
}

void Heavy_windGen::cVar_WIVIYAcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dA8mFBs4, HV_BINOP_MULTIPLY, 0, m, &cBinop_dA8mFBs4_sendMessage);
}

void Heavy_windGen::cSystem_w3QhJixP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ICumoWZ6_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_AgxvTceX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w3QhJixP_sendMessage);
}

void Heavy_windGen::cMsg_ICumoWZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lkXvGg7l_sendMessage);
}

void Heavy_windGen::cBinop_lkXvGg7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dA8mFBs4, HV_BINOP_MULTIPLY, 1, m, &cBinop_dA8mFBs4_sendMessage);
}

void Heavy_windGen::cBinop_dA8mFBs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pfxujPJh_sendMessage);
}

void Heavy_windGen::cBinop_TQTE9l3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_EusxcNIy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DzCuV7EE, m);
}

void Heavy_windGen::cBinop_pfxujPJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TQTE9l3N_sendMessage);
}

void Heavy_windGen::cBinop_EusxcNIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O2QXY4CX, m);
}

void Heavy_windGen::cBinop_3zNtiVCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9OUTUM6s_sendMessage);
}

void Heavy_windGen::cSystem_eIwIlA70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qCNETVQS_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_DQNtobhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eIwIlA70_sendMessage);
}

void Heavy_windGen::cBinop_l1837p0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3zNtiVCY, HV_BINOP_MULTIPLY, 1, m, &cBinop_3zNtiVCY_sendMessage);
}

void Heavy_windGen::cMsg_qCNETVQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_l1837p0D_sendMessage);
}

void Heavy_windGen::cBinop_L4tcbCfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uruExZKR, m);
}

void Heavy_windGen::cBinop_6crCoCZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_L4tcbCfe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bZt6VyJ6, m);
}

void Heavy_windGen::cBinop_9OUTUM6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6crCoCZH_sendMessage);
}

void Heavy_windGen::cVar_VoQItGYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3zNtiVCY, HV_BINOP_MULTIPLY, 0, m, &cBinop_3zNtiVCY_sendMessage);
}

void Heavy_windGen::cBinop_cvaEibBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_twRSP1PD, m);
}

void Heavy_windGen::cVar_zE4wDVS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_e7rvpb2r_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_j0g6vvGO, 0, m, &cIf_j0g6vvGO_sendMessage);
}

void Heavy_windGen::cBinop_MX83kyuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0gE7JUSh, m);
}

void Heavy_windGen::cMsg_Sqhe2fWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_AJOgJB8G_sendMessage);
}

void Heavy_windGen::cMsg_CCO70IDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_MX83kyuV_sendMessage);
}

void Heavy_windGen::cMsg_QfEUoYUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CgFlkZZi_sendMessage);
}

void Heavy_windGen::cSystem_CgFlkZZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9C7k73ni_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_EU5F4grh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MG9r5lq8, m);
}

void Heavy_windGen::cIf_j0g6vvGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DQsmcR4R_sendMessage(_c, 0, m);
      cMsg_OTRLH1wp_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ksEHdVwI_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_s2PGHc4F_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_vSveWv11, m);
      break;
    }
    default: return;
  }
}

void Heavy_windGen::cBinop_e7rvpb2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j0g6vvGO, 1, m, &cIf_j0g6vvGO_sendMessage);
}

void Heavy_windGen::cBinop_s2PGHc4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Sqhe2fWJ_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_ksEHdVwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cvaEibBu_sendMessage);
}

void Heavy_windGen::cBinop_AJOgJB8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CCO70IDc_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_OTRLH1wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_twRSP1PD, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vSveWv11, m);
}

void Heavy_windGen::cMsg_9C7k73ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_EU5F4grh_sendMessage);
}

void Heavy_windGen::cMsg_DQsmcR4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_s2PGHc4F_sendMessage);
}

void Heavy_windGen::cMsg_3li8Fk9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hfm5wfHu_sendMessage);
}

void Heavy_windGen::cMsg_EVXtL1p4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TimDVE4D_sendMessage);
}

void Heavy_windGen::cSystem_TimDVE4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oePu08MA_sendMessage);
}

void Heavy_windGen::cVar_XuOfFf4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3li8Fk9o_sendMessage(_c, 0, m);
}

void Heavy_windGen::cSystem_hfm5wfHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0i3L2IWw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Aybj4zjb, m);
}

void Heavy_windGen::cBinop_oePu08MA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fUTV5NvH, 0, m, &cVar_fUTV5NvH_sendMessage);
}

void Heavy_windGen::cVar_fUTV5NvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_windGen::cBinop_0i3L2IWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TRrcpirM, m);
}

void Heavy_windGen::cVar_GzUHNGLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_2R7G0ifr_sendMessage(_c, 0, m);
}

void Heavy_windGen::cSend_JyG81Qgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_g9YRzMfP_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_FyekxMAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1m5aqVaM_sendMessage);
}

void Heavy_windGen::cBinop_kypmhv44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Wgkd0q7P, m);
}

void Heavy_windGen::cVar_XZ93fufm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_windGen::cSystem_1m5aqVaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kypmhv44_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pILr6UfK, m);
}

void Heavy_windGen::cVar_0FIvRVlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FyekxMAT_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_OsfC9IyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XZ93fufm, 0, m, &cVar_XZ93fufm_sendMessage);
}

void Heavy_windGen::cMsg_jHKuLwQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pTZ8arrI_sendMessage);
}

void Heavy_windGen::cSystem_pTZ8arrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OsfC9IyX_sendMessage);
}

void Heavy_windGen::cBinop_p9SwEtu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VrWLXlUa_sendMessage);
}

void Heavy_windGen::cBinop_VrWLXlUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_2VFREwWa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gG7vgmP3_sendMessage);
}

void Heavy_windGen::cBinop_oLJg6ZiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_TNNT3h1P_sendMessage);
}

void Heavy_windGen::cMsg_aV8HuuNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_TvGVhuLV_sendMessage);
}

void Heavy_windGen::cBinop_gG7vgmP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PFIhmQXb, m);
}

void Heavy_windGen::cVar_3uQu9dvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_oLJg6ZiV_sendMessage);
}

void Heavy_windGen::cBinop_2VFREwWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_nDRXJuUM_sendMessage);
}

void Heavy_windGen::cSystem_SBXMhD8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqfIycAg, HV_BINOP_DIVIDE, 1, m, &cBinop_KqfIycAg_sendMessage);
}

void Heavy_windGen::cMsg_h51936EA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SBXMhD8H_sendMessage);
}

void Heavy_windGen::cBinop_TvGVhuLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_p9SwEtu7_sendMessage);
}

void Heavy_windGen::cBinop_TNNT3h1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqfIycAg, HV_BINOP_DIVIDE, 0, m, &cBinop_KqfIycAg_sendMessage);
}

void Heavy_windGen::cBinop_KqfIycAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aV8HuuNt_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_nDRXJuUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZQtUz39Q, m);
}

void Heavy_windGen::cMsg_2sEJMDPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_P6UojO3l, m);
}

void Heavy_windGen::cUnop_jTV3ZuHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2sEJMDPJ_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_znbGxeLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jTV3ZuHR_sendMessage);
}

void Heavy_windGen::cRandom_Fygbla1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_znbGxeLM_sendMessage);
}

void Heavy_windGen::cSlice_cre7gKan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Fygbla1G, 1, m, &cRandom_Fygbla1G_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_windGen::cSwitchcase_sqCxsRtg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_cre7gKan, 0, m, &cSlice_cre7gKan_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Fygbla1G, 0, m, &cRandom_Fygbla1G_sendMessage);
      break;
    }
  }
}

void Heavy_windGen::cBinop_cHPCidFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_38Gm5RKg, HV_BINOP_MULTIPLY, 1, m, &cBinop_38Gm5RKg_sendMessage);
}

void Heavy_windGen::cSystem_tf5DEa7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r1nepf4k_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_dm7nbe2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tf5DEa7E_sendMessage);
}

void Heavy_windGen::cBinop_38Gm5RKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WfosrVz4_sendMessage);
}

void Heavy_windGen::cMsg_r1nepf4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cHPCidFr_sendMessage);
}

void Heavy_windGen::cBinop_JF63GE4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WV42BisO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_h6kHpfcy, m);
}

void Heavy_windGen::cBinop_WfosrVz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JF63GE4G_sendMessage);
}

void Heavy_windGen::cVar_szCjaHUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_38Gm5RKg, HV_BINOP_MULTIPLY, 0, m, &cBinop_38Gm5RKg_sendMessage);
}

void Heavy_windGen::cBinop_WV42BisO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0nX3QOcn, m);
}

void Heavy_windGen::cBinop_8cJ4XXV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_b0t5a16R_sendMessage);
}

void Heavy_windGen::cBinop_b0t5a16R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6uMaJxqA_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uXRuv4Hj, m);
}

void Heavy_windGen::cBinop_6uMaJxqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hF5cR2gK, m);
}

void Heavy_windGen::cBinop_ry47Jses_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_29hgXvB7, HV_BINOP_MULTIPLY, 1, m, &cBinop_29hgXvB7_sendMessage);
}

void Heavy_windGen::cBinop_29hgXvB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8cJ4XXV5_sendMessage);
}

void Heavy_windGen::cMsg_rQESBjX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ry47Jses_sendMessage);
}

void Heavy_windGen::cSystem_yDMAAr8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rQESBjX6_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_NSScRCi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yDMAAr8f_sendMessage);
}

void Heavy_windGen::cVar_I3b1ici7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_29hgXvB7, HV_BINOP_MULTIPLY, 0, m, &cBinop_29hgXvB7_sendMessage);
}

void Heavy_windGen::cVar_wH3pfWdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kxOsLTkR, HV_BINOP_MULTIPLY, 0, m, &cBinop_kxOsLTkR_sendMessage);
}

void Heavy_windGen::cBinop_1nFbYvAW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qYRDOrMc_sendMessage);
}

void Heavy_windGen::cBinop_qYRDOrMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yDviiIyK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_L3zLCbS6, m);
}

void Heavy_windGen::cBinop_yDviiIyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pJxSOZqn, m);
}

void Heavy_windGen::cBinop_kxOsLTkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1nFbYvAW_sendMessage);
}

void Heavy_windGen::cMsg_COoCRwdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rE4f6lFK_sendMessage);
}

void Heavy_windGen::cSystem_4e9zouPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_COoCRwdP_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_WmkPJJtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4e9zouPk_sendMessage);
}

void Heavy_windGen::cBinop_rE4f6lFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kxOsLTkR, HV_BINOP_MULTIPLY, 1, m, &cBinop_kxOsLTkR_sendMessage);
}

void Heavy_windGen::cBinop_0uHQJeNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TbSLV8le, m);
}

void Heavy_windGen::cMsg_Sca5LXlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_9vWyyjSR_sendMessage);
}

void Heavy_windGen::cBinop_0Pg7M4bY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZpfaUrnn, m);
}

void Heavy_windGen::cMsg_nbqtADAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_91bZyfcT_sendMessage);
}

void Heavy_windGen::cSystem_91bZyfcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y69HdJro, HV_BINOP_DIVIDE, 1, m, &cBinop_Y69HdJro_sendMessage);
}

void Heavy_windGen::cBinop_nF0K1NJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_CSQNvw3r_sendMessage);
}

void Heavy_windGen::cBinop_CSQNvw3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y69HdJro, HV_BINOP_DIVIDE, 0, m, &cBinop_Y69HdJro_sendMessage);
}

void Heavy_windGen::cBinop_9vWyyjSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WcttvRL9_sendMessage);
}

void Heavy_windGen::cVar_Lu1ouIoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_nF0K1NJP_sendMessage);
}

void Heavy_windGen::cBinop_Y69HdJro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Sca5LXlY_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_OIYUdWOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_0uHQJeNR_sendMessage);
}

void Heavy_windGen::cBinop_WcttvRL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QCqPtx8Z_sendMessage);
}

void Heavy_windGen::cBinop_QCqPtx8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OIYUdWOC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0Pg7M4bY_sendMessage);
}

void Heavy_windGen::cUnop_K06FdgbJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QYjCXnJO_sendMessage(_c, 0, m);
}

void Heavy_windGen::cSwitchcase_LiACPLTm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GTixlW5T, 0, m, &cSlice_GTixlW5T_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YsklFfWR, 0, m, &cRandom_YsklFfWR_sendMessage);
      break;
    }
  }
}

void Heavy_windGen::cSlice_GTixlW5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YsklFfWR, 1, m, &cRandom_YsklFfWR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_windGen::cBinop_6i6n3EZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_K06FdgbJ_sendMessage);
}

void Heavy_windGen::cRandom_YsklFfWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_6i6n3EZx_sendMessage);
}

void Heavy_windGen::cMsg_QYjCXnJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_CP17y1Ff, m);
}

void Heavy_windGen::cVar_gpDNMLui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T3FVYocL, HV_BINOP_MULTIPLY, 0, m, &cBinop_T3FVYocL_sendMessage);
}

void Heavy_windGen::cBinop_5cAovgKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sREve591, m);
}

void Heavy_windGen::cBinop_5me6ba1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5cAovgKE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tsF8wJhQ, m);
}

void Heavy_windGen::cBinop_z1VpNAVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5me6ba1E_sendMessage);
}

void Heavy_windGen::cMsg_PgW7zCCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OdaNIhqH_sendMessage);
}

void Heavy_windGen::cBinop_T3FVYocL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_z1VpNAVy_sendMessage);
}

void Heavy_windGen::cBinop_OdaNIhqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T3FVYocL, HV_BINOP_MULTIPLY, 1, m, &cBinop_T3FVYocL_sendMessage);
}

void Heavy_windGen::cSystem_x00mMotM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PgW7zCCz_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_AZNUJARV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x00mMotM_sendMessage);
}

void Heavy_windGen::cVar_fjjgkLMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P199jyf4_sendMessage(_c, 0, m);
}

void Heavy_windGen::cSystem_rMD9sFSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_H58gFTCr_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gIl8ddj6, m);
}

void Heavy_windGen::cSystem_mvJpr8iC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_v6NzAVvT_sendMessage);
}

void Heavy_windGen::cMsg_e05B3mn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mvJpr8iC_sendMessage);
}

void Heavy_windGen::cBinop_H58gFTCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lzmSSGTw, m);
}

void Heavy_windGen::cBinop_v6NzAVvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_oqG04I7i, m);
}

void Heavy_windGen::cMsg_P199jyf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rMD9sFSX_sendMessage);
}

void Heavy_windGen::cBinop_OlmmmQ1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8vDb2mhR_sendMessage);
}

void Heavy_windGen::cBinop_8vDb2mhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vOltnciC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_36vqowBw_sendMessage);
}

void Heavy_windGen::cBinop_uY25VMPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_OlmmmQ1s_sendMessage);
}

void Heavy_windGen::cBinop_uYtOSafz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bugupyOT_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_36vqowBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_flozjRRE, m);
}

void Heavy_windGen::cBinop_vOltnciC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_yVO1Csxm_sendMessage);
}

void Heavy_windGen::cBinop_yVO1Csxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lI3M2NO1, m);
}

void Heavy_windGen::cBinop_LcdF0xtJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_SpXUkYSY_sendMessage);
}

void Heavy_windGen::cBinop_SpXUkYSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYtOSafz, HV_BINOP_DIVIDE, 0, m, &cBinop_uYtOSafz_sendMessage);
}

void Heavy_windGen::cVar_Z2EDFxLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_LcdF0xtJ_sendMessage);
}

void Heavy_windGen::cSystem_U8vBFlbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYtOSafz, HV_BINOP_DIVIDE, 1, m, &cBinop_uYtOSafz_sendMessage);
}

void Heavy_windGen::cMsg_r2RdNTRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_U8vBFlbv_sendMessage);
}

void Heavy_windGen::cMsg_bugupyOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_uY25VMPn_sendMessage);
}

void Heavy_windGen::cVar_kWCiLnPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IfUWN2l3_sendMessage(_c, 0, m);
}

void Heavy_windGen::cBinop_4eh9LTmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_AZxELPr6_sendMessage);
}

void Heavy_windGen::cBinop_cunn6TNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EOGWIKqv, HV_BINOP_MULTIPLY, 0, m, &cBinop_EOGWIKqv_sendMessage);
}

void Heavy_windGen::cCast_f0yc5vc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nD1Xrz5c, 0, m, &cVar_nD1Xrz5c_sendMessage);
}

void Heavy_windGen::cBinop_Q6borehM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4eh9LTmO, HV_BINOP_MULTIPLY, 1, m, &cBinop_4eh9LTmO_sendMessage);
}

void Heavy_windGen::cVar_nD1Xrz5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_MOWzEINv_sendMessage);
}

void Heavy_windGen::cBinop_ao1xhyBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EOGWIKqv, HV_BINOP_MULTIPLY, 1, m, &cBinop_EOGWIKqv_sendMessage);
}

void Heavy_windGen::cBinop_Rgx7p5An_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_b9e6EcsC_sendMessage);
}

void Heavy_windGen::cBinop_MOWzEINv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tXk9QEf, HV_BINOP_DIVIDE, 0, m, &cBinop_9tXk9QEf_sendMessage);
}

void Heavy_windGen::cSystem_ahUlPoHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9tXk9QEf, HV_BINOP_DIVIDE, 1, m, &cBinop_9tXk9QEf_sendMessage);
}

void Heavy_windGen::cMsg_E1y65Kcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ahUlPoHF_sendMessage);
}

void Heavy_windGen::cBinop_GuWjO0Hk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ao1xhyBs, HV_BINOP_ADD, 1, m, &cBinop_ao1xhyBs_sendMessage);
}

void Heavy_windGen::cBinop_uq5oX0ui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rgx7p5An, HV_BINOP_DIVIDE, 1, m, &cBinop_Rgx7p5An_sendMessage);
}

void Heavy_windGen::cBinop_AZxELPr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Dm9GL8hZ, 4, m);
}

void Heavy_windGen::cBinop_jS1bNsUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_amW7EUi7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4eh9LTmO, HV_BINOP_MULTIPLY, 0, m, &cBinop_4eh9LTmO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GuWjO0Hk, HV_BINOP_MULTIPLY, 0, m, &cBinop_GuWjO0Hk_sendMessage);
}

void Heavy_windGen::cBinop_9ssiM0R9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hvS1l7on_sendMessage);
}

void Heavy_windGen::cBinop_amW7EUi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9ssiM0R9_sendMessage);
}

void Heavy_windGen::cBinop_9tXk9QEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GuWjO0Hk, HV_BINOP_MULTIPLY, 1, m, &cBinop_GuWjO0Hk_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_rnCpFcPL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rgx7p5An, HV_BINOP_DIVIDE, 0, m, &cBinop_Rgx7p5An_sendMessage);
}

void Heavy_windGen::cVar_MCrmJQQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_uq5oX0ui_sendMessage);
}

void Heavy_windGen::cBinop_b9e6EcsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_531Hf3Dx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ao1xhyBs, HV_BINOP_ADD, 0, m, &cBinop_ao1xhyBs_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_cunn6TNE_sendMessage);
}

void Heavy_windGen::cBinop_hvS1l7on_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Dm9GL8hZ, 5, m);
}

void Heavy_windGen::cBinop_531Hf3Dx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jS1bNsUg_sendMessage);
}

void Heavy_windGen::cUnop_rnCpFcPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Q6borehM_sendMessage);
}

void Heavy_windGen::cBinop_EOGWIKqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Dm9GL8hZ, 1, m);
}

void Heavy_windGen::cBinop_BHFN4QbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_zBjX4SMt, 1, m);
}

void Heavy_windGen::cBinop_6HQe9kSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_trNIpJ8T_sendMessage);
}

void Heavy_windGen::cBinop_iNSajlJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6HQe9kSM_sendMessage);
}

void Heavy_windGen::cBinop_1tH6hFi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7xP72zA6_sendMessage);
}

void Heavy_windGen::cBinop_trNIpJ8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_zBjX4SMt, 5, m);
}

void Heavy_windGen::cSystem_fH4DPihC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qcpSn9Jy, HV_BINOP_DIVIDE, 1, m, &cBinop_qcpSn9Jy_sendMessage);
}

void Heavy_windGen::cMsg_bClUS8HQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fH4DPihC_sendMessage);
}

void Heavy_windGen::cBinop_7CygVWUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_BBO8qIZ5_sendMessage);
}

void Heavy_windGen::cBinop_y2YsNqfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_zBjX4SMt, 4, m);
}

void Heavy_windGen::cBinop_RsfxifzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ASYxM8BX, HV_BINOP_ADD, 1, m, &cBinop_ASYxM8BX_sendMessage);
}

void Heavy_windGen::cBinop_7xP72zA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7CygVWUi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ASYxM8BX, HV_BINOP_ADD, 0, m, &cBinop_ASYxM8BX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yoCAUJn1_sendMessage);
}

void Heavy_windGen::cBinop_0u937PZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_y2YsNqfE_sendMessage);
}

void Heavy_windGen::cBinop_yoCAUJn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHFN4QbF, HV_BINOP_MULTIPLY, 0, m, &cBinop_BHFN4QbF_sendMessage);
}

void Heavy_windGen::cBinop_BBO8qIZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_iNSajlJF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0u937PZ7, HV_BINOP_MULTIPLY, 0, m, &cBinop_0u937PZ7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RsfxifzB, HV_BINOP_MULTIPLY, 0, m, &cBinop_RsfxifzB_sendMessage);
}

void Heavy_windGen::cBinop_ASYxM8BX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHFN4QbF, HV_BINOP_MULTIPLY, 1, m, &cBinop_BHFN4QbF_sendMessage);
}

void Heavy_windGen::cUnop_TRqQPj2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_qg9GOEDQ_sendMessage);
}

void Heavy_windGen::cBinop_WruG5NaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qcpSn9Jy, HV_BINOP_DIVIDE, 0, m, &cBinop_qcpSn9Jy_sendMessage);
}

void Heavy_windGen::cBinop_VRwDGzso_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1tH6hFi6, HV_BINOP_DIVIDE, 1, m, &cBinop_1tH6hFi6_sendMessage);
}

void Heavy_windGen::cCast_P2aoqt93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_as4BF1bd, 0, m, &cVar_as4BF1bd_sendMessage);
}

void Heavy_windGen::cBinop_qg9GOEDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0u937PZ7, HV_BINOP_MULTIPLY, 1, m, &cBinop_0u937PZ7_sendMessage);
}

void Heavy_windGen::cBinop_qcpSn9Jy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RsfxifzB, HV_BINOP_MULTIPLY, 1, m, &cBinop_RsfxifzB_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_TRqQPj2m_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1tH6hFi6, HV_BINOP_DIVIDE, 0, m, &cBinop_1tH6hFi6_sendMessage);
}

void Heavy_windGen::cVar_as4BF1bd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_WruG5NaA_sendMessage);
}

void Heavy_windGen::cVar_gaPl3hvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_VRwDGzso_sendMessage);
}

void Heavy_windGen::cSend_2R7G0ifr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TEPQLTbK_sendMessage(_c, 0, m);
}

void Heavy_windGen::cVar_trLriyDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Nd3iz2Md_sendMessage(_c, 0, m);
}

void Heavy_windGen::cVar_FhtzxrKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7rQLx3AK_sendMessage(_c, 0, m);
}

void Heavy_windGen::cCast_5mfSennX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_trLriyDf, 0, m, &cVar_trLriyDf_sendMessage);
}

void Heavy_windGen::cReceive_rFhWGTwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7T0dA7Pi, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tYbaZYML, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tYbaZYML, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7T0dA7Pi, m);
}

void Heavy_windGen::cSend_4eryWYSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Khx1jNnI_sendMessage(_c, 0, m);
}

void Heavy_windGen::cReceive_Khx1jNnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EZvCPgDL, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Mn2cED2a, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Mn2cED2a, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EZvCPgDL, m);
}

void Heavy_windGen::cReceive_UsqgB2ZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LiACPLTm_onMessage(_c, NULL, 0, m, NULL);
  cMsg_nbqtADAL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Lu1ouIoQ, 0, m, &cVar_Lu1ouIoQ_sendMessage);
  cMsg_AZNUJARV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gpDNMLui, 0, m, &cVar_gpDNMLui_sendMessage);
  cMsg_WmkPJJtR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wH3pfWdl, 0, m, &cVar_wH3pfWdl_sendMessage);
  cSwitchcase_sqCxsRtg_onMessage(_c, NULL, 0, m, NULL);
  cMsg_h51936EA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3uQu9dvG, 0, m, &cVar_3uQu9dvG_sendMessage);
  cMsg_dm7nbe2w_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_szCjaHUn, 0, m, &cVar_szCjaHUn_sendMessage);
  cMsg_NSScRCi7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I3b1ici7, 0, m, &cVar_I3b1ici7_sendMessage);
  cSwitchcase_vKX7Ow7R_onMessage(_c, NULL, 0, m, NULL);
  cMsg_r2RdNTRW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Z2EDFxLM, 0, m, &cVar_Z2EDFxLM_sendMessage);
  cMsg_DugDDVHg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cQX4UFcs, 0, m, &cVar_cQX4UFcs_sendMessage);
  cMsg_Vb3h0pvu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uvBIxlwQ, 0, m, &cVar_uvBIxlwQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GLtBa7Ui, 0, m, &cVar_GLtBa7Ui_sendMessage);
  cMsg_rT5legGK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pdmYwzlX, 0, m, &cVar_pdmYwzlX_sendMessage);
  cMsg_AgxvTceX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_WIVIYAcW, 0, m, &cVar_WIVIYAcW_sendMessage);
  cMsg_DQNtobhZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VoQItGYq, 0, m, &cVar_VoQItGYq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gaPl3hvw, 0, m, &cVar_gaPl3hvw_sendMessage);
  cMsg_bClUS8HQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_as4BF1bd, 0, m, &cVar_as4BF1bd_sendMessage);
  cMsg_QfEUoYUN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zE4wDVS7, 0, m, &cVar_zE4wDVS7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MCrmJQQx, 0, m, &cVar_MCrmJQQx_sendMessage);
  cMsg_E1y65Kcb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nD1Xrz5c, 0, m, &cVar_nD1Xrz5c_sendMessage);
  cMsg_e8CXS7XT_sendMessage(_c, 0, m);
  cMsg_qcxSFkzi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5NZ5AedU, 0, m, &cVar_5NZ5AedU_sendMessage);
  cMsg_duHO93FF_sendMessage(_c, 0, m);
  cMsg_bYqj64MT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5CpX96HO, 0, m, &cVar_5CpX96HO_sendMessage);
  cMsg_ThwcwXkx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bhp8tauH, 0, m, &cVar_bhp8tauH_sendMessage);
  cMsg_A4rY2AQj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XuOfFf4k, 0, m, &cVar_XuOfFf4k_sendMessage);
  cMsg_EVXtL1p4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0FIvRVlB, 0, m, &cVar_0FIvRVlB_sendMessage);
  cMsg_jHKuLwQV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fjjgkLMH, 0, m, &cVar_fjjgkLMH_sendMessage);
  cMsg_e05B3mn1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_92XVRIoK, 0, m, &cVar_92XVRIoK_sendMessage);
  cMsg_2z1qNgK8_sendMessage(_c, 0, m);
}

void Heavy_windGen::hTable_spYlychT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nAafolHP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FE2y4TcF, 2, m, &cDelay_FE2y4TcF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eIsa7pnR_sendMessage);
}

void Heavy_windGen::cMsg_nAafolHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_DYGNbFhZ, 2, m, &cDelay_DYGNbFhZ_sendMessage);
}

void Heavy_windGen::cMsg_2rLHlEgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_spYlychT, 0, m, &hTable_spYlychT_sendMessage);
}

void Heavy_windGen::cCast_eIsa7pnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FE2y4TcF, 0, m, &cDelay_FE2y4TcF_sendMessage);
}

void Heavy_windGen::cBinop_bgrAfGpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_45Lj1LG5_sendMessage);
}

void Heavy_windGen::cBinop_45Lj1LG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WAiOgHTd_sendMessage(_c, 0, m);
}

void Heavy_windGen::cDelay_DYGNbFhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DYGNbFhZ, m);
  cMsg_2rLHlEgg_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_e8CXS7XT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ndgqnsSY_sendMessage);
}

void Heavy_windGen::cSystem_ndgqnsSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bgrAfGpA_sendMessage);
}

void Heavy_windGen::cDelay_FE2y4TcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FE2y4TcF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DYGNbFhZ, 0, m, &cDelay_DYGNbFhZ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FE2y4TcF, 0, m, &cDelay_FE2y4TcF_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FhMXREbk, 1, m, NULL);
}

void Heavy_windGen::cMsg_WAiOgHTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_spYlychT, 0, m, &hTable_spYlychT_sendMessage);
}

void Heavy_windGen::cVar_TY1fnApG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lrVPEIqA_sendMessage(_c, 0, m);
}

void Heavy_windGen::cSend_lrVPEIqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XJCh0AX4_sendMessage(_c, 0, m);
}

void Heavy_windGen::cVar_ctD5UrL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JyG81Qgf_sendMessage(_c, 0, m);
}

void Heavy_windGen::cReceive_cE5FgxpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WLMyyxab, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QDNxVffR, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WLMyyxab, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QDNxVffR, m);
}

void Heavy_windGen::cSend_IfUWN2l3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cE5FgxpC_sendMessage(_c, 0, m);
}

void Heavy_windGen::cMsg_duHO93FF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_5NZ5AedU, 0, m, &cVar_5NZ5AedU_sendMessage);
}

void Heavy_windGen::cSystem_qcAur9To_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZFZpDsCw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jFz8OqiC, m);
}

void Heavy_windGen::cBinop_khJr0P5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1NtnWdbS, m);
}

void Heavy_windGen::cBinop_ZFZpDsCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_USHK0SOW, m);
}

void Heavy_windGen::cMsg_2z1qNgK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M8LpecoS_sendMessage);
}

void Heavy_windGen::cSystem_M8LpecoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_khJr0P5b_sendMessage);
}

void Heavy_windGen::cMsg_o825F25e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qcAur9To_sendMessage);
}

void Heavy_windGen::cVar_92XVRIoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o825F25e_sendMessage(_c, 0, m);
}




/*
 * Context Process Implementation
 */

int Heavy_windGen::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9;
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
    __hv_varread_f(&sVarf_o4Z63GLD, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_FlUfUVok, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf2), VIf(ZERO), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf1));
    __hv_varread_f(&sVarf_EF50fPR0, VOf(Bf3));
    __hv_zero_f(VOf(Bf4));
    __hv_lt_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_GXKoAZll, VIi(Bi1), VOf(Bf4));
    __hv_tabread_if(&sTabread_cRq04gcO, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 400.0f, 400.0f, 400.0f, 400.0f, 400.0f, 400.0f, 400.0f, 400.0f);
    __hv_var_k_f(VOf(Bf4), 600.0f, 600.0f, 600.0f, 600.0f, 600.0f, 600.0f, 600.0f, 600.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Sl5aFLeD, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Knqqopca, VOf(Bf1));
    __hv_min_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_zzyweif8, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_varread_f(&sVarf_4ufXwHlQ, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_cos_f(VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf0));
    __hv_gt_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sqrt_f(VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_cpole_f(&sCPole_gj4IW0R1, VIf(Bf1), VIf(ZERO), VIf(Bf5), VIf(Bf4), VOf(Bf4), VOf(Bf5));
    __hv_var_k_f(VOf(Bf5), 0.12f, 0.12f, 0.12f, 0.12f, 0.12f, 0.12f, 0.12f, 0.12f);
    __hv_add_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_sFlbCBBy, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf5), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf1));
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_f(&sVarf_uN0YYn82, VIf(Bf2));
    __hv_tabhead_f(&sTabhead_Twf3b2kK, VOf(Bf6));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_lzmSSGTw, VOf(Bf6));
    __hv_min_f(VIf(ZERO), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_varread_f(&sVarf_gIl8ddj6, VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_eTp7qZXD, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_4i5dmliu, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_oqG04I7i, VOf(Bf4));
    __hv_var_k_f(VOf(Bf4), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_o4Z63GLD, VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_Dm9GL8hZ, VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f, 0.99f);
    __hv_min_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_del1_f(&sDel1_PjHHYJ8K, VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_VyxnrcC6, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_AuYVX3gQ, VIf(Bf0));
    __hv_varread_f(&sVarf_l5hhZHL6, VOf(Bf7));
    __hv_varread_f(&sVarf_uN0YYn82, VOf(Bf6));
    __hv_varread_f(&sVarf_oNJfWks0, VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_gLSfat2R, VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_CMcZzvnH, VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_8ALmqcTI, VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_7T0dA7Pi, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(O1), VOf(O1));
    __hv_varwrite_f(&sVarf_FzQK82cm, VIf(Bf2));
    __hv_varread_f(&sVarf_o4Z63GLD, VOf(Bf2));
    __hv_varread_f(&sVarf_TRrcpirM, VOf(Bf7));
    __hv_tabhead_f(&sTabhead_YdJxrPVT, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(ZERO), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf6));
    __hv_varread_f(&sVarf_Aybj4zjb, VOf(Bf1));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_kac0wRpQ, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_Qjb8RhDs, VIi(Bi0), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_WLMyyxab, VOf(Bf6));
    __hv_varread_f(&sVarf_QDNxVffR, VOf(Bf5));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_MG9r5lq8, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_vSveWv11, VOf(Bf6));
    __hv_min_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_twRSP1PD, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf2));
    __hv_varread_f(&sVarf_0gE7JUSh, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf7));
    __hv_cos_f(VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf2));
    __hv_gt_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_sqrt_f(VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_qRsf5CBy, VIf(Bf6), VIf(ZERO), VIf(Bf3), VIf(Bf5), VOf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_cWgkNgOV, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf1), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
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
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varwrite_f(&sVarf_l5hhZHL6, VIf(Bf4));
    __hv_varread_f(&sVarf_o4Z63GLD, VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_varread_f(&sVarf_Wgkd0q7P, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_7FJ2vbLS, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(ZERO), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf2));
    __hv_varread_f(&sVarf_pILr6UfK, VOf(Bf6));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Qx7ONZhV, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_5yPKNLw3, VIi(Bi0), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_IzSIigD6, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_5pYbPBTs, VOf(Bf2));
    __hv_rpole_f(&sRPole_gu9mcFdm, VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_max_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_flozjRRE, VOf(Bf7));
    __hv_rpole_f(&sRPole_YZ3OiX1T, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_O9rKdXJ1, VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_lI3M2NO1, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_vffhrFzo, VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_2MB6b3aa, VOf(Bf7));
    __hv_rpole_f(&sRPole_qfq5d57P, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_6KTvfFcz, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf6), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf6));
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
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
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_CCTowUa0, VIf(Bf8));
    __hv_varread_f(&sVarf_o4Z63GLD, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_TWYN0EXQ, VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_1NtnWdbS, VOf(Bf7));
    __hv_varread_f(&sVarf_USHK0SOW, VOf(Bf7));
    __hv_tabhead_f(&sTabhead_1Wk2pKEK, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(ZERO), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf2));
    __hv_varread_f(&sVarf_jFz8OqiC, VOf(Bf3));
    __hv_zero_f(VOf(Bf5));
    __hv_lt_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_cast_fi(VIf(Bf5), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_3ZqJrYPJ, VIi(Bi1), VOf(Bf5));
    __hv_tabread_if(&sTabread_zCz3PpM2, VIi(Bi0), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_min_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_max_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf3), VIf(Bf5), VOf(Bf5));
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
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_DzCuV7EE, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_O2QXY4CX, VOf(Bf6));
    __hv_rpole_f(&sRPole_48d5mzmx, VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf1));
    __hv_varread_f(&sVarf_Mn2cED2a, VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf3), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_fma_f(VIf(Bf6), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_xgSGQTB1, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf2), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf6), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf7), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf3), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_f(&sVarf_dIODxUcP, VIf(Bf9));
    __hv_varwrite_f(&sVarf_B5snaMF6, VIf(Bf4));
    __hv_varwrite_f(&sVarf_8ALmqcTI, VIf(Bf0));
    __hv_varwrite_f(&sVarf_gLSfat2R, VIf(Bf9));
    __hv_varread_f(&sVarf_o4Z63GLD, VOf(Bf9));
    __hv_biquad_k_f(&sBiquad_k_zBjX4SMt, VIf(Bf9), VOf(Bf9));
    __hv_tabhead_f(&sTabhead_tb8ZUi97, VOf(Bf0));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_EJDaROSP, VOf(Bf0));
    __hv_min_f(VIf(ZERO), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf4));
    __hv_varread_f(&sVarf_HRE33aGl, VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_hrkAK5x2, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_gMHroshT, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_3PZ3CDp0, VOf(Bf4));
    __hv_var_k_f(VOf(Bf4), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_min_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f);
    __hv_max_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f, 0.35f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf4), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf0));
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_bZt6VyJ6, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_uruExZKR, VOf(Bf5));
    __hv_rpole_f(&sRPole_iw5MDSKl, VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf9));
    __hv_varread_f(&sVarf_EZvCPgDL, VOf(Bf2));
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 200.0f);
    __hv_var_k_f(VOf(Bf0), 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f);
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_oLEIN0wU, VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf0));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf2), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf0), VOf(Bf5));
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_oNJfWks0, VIf(Bf6));
    __hv_varread_f(&sVarf_FzQK82cm, VOf(Bf4));
    __hv_varread_f(&sVarf_AuYVX3gQ, VOf(Bf9));
    __hv_varread_f(&sVarf_9v224X5j, VOf(Bf1));
    __hv_add_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_dIODxUcP, VOf(Bf9));
    __hv_add_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_B5snaMF6, VOf(Bf1));
    __hv_add_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_CCTowUa0, VOf(Bf9));
    __hv_add_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_tYbaZYML, VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));
    __hv_varread_i(&sVari_rE9yBWsR, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_i(&sVari_rE9yBWsR, VIi(Bi1));
    __hv_varwrite_f(&sVarf_o4Z63GLD, VIf(Bf9));
    __hv_phasor_k_f(&sPhasor_fKP08iwB, VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_i(&sVari_P6UojO3l, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_varwrite_i(&sVari_P6UojO3l, VIi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_uXRuv4Hj, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_hF5cR2gK, VOf(Bf9));
    __hv_rpole_f(&sRPole_e0KQ32CS, VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_h6kHpfcy, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_0nX3QOcn, VOf(Bf9));
    __hv_rpole_f(&sRPole_Y0VpjC5s, VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_PFIhmQXb, VOf(Bf5));
    __hv_rpole_f(&sRPole_gwaD4Rnz, VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Ik6k3rte, VIf(Bf5), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_ZQtUz39Q, VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f, 50.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f, 0.125f);
    __hv_fms_f(VIf(Bf5), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_max_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf9));
    __hv_varread_i(&sVari_CP17y1Ff, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_CP17y1Ff, VIi(Bi1));
    __hv_varread_f(&sVarf_tsF8wJhQ, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_sREve591, VOf(Bf1));
    __hv_rpole_f(&sRPole_EqlYbrMa, VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_L3zLCbS6, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_pJxSOZqn, VOf(Bf1));
    __hv_rpole_f(&sRPole_WpTbkRFR, VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_ZpfaUrnn, VOf(Bf5));
    __hv_rpole_f(&sRPole_yLnv67vZ, VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_QgVcNjvi, VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_TbSLV8le, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_XAVegxys, VOf(Bf4));
    __hv_min_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_FhMXREbk, VIf(Bf1));
    __hv_varwrite_f(&sVarf_9v224X5j, VIf(Bf6));
    __hv_varwrite_f(&sVarf_CMcZzvnH, VIf(Bf8));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_windGen::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_windGen::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
