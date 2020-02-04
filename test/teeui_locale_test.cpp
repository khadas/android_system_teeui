/*
 *
 * Copyright 2020, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Generated by generate_teeui_render_tests - DO NOT EDIT */

#include <getopt.h>
#include <gtest/gtest.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <teeui/example/teeui.h>
#include <unistd.h>

#include <teeui_locale_test.h>

#define TeeuiLocaleTest_DO_LOG_DEBUG

namespace teeui {

namespace test {

class TeeuiLocaleTest : public ::testing::Test {
  public:
    DeviceInfo device_info;

    static TeeuiLocaleTest* Instance() {
        static TeeuiLocaleTest* instance = new TeeuiLocaleTest;
        return instance;
    }

    void initFromOptions(int argc, char** argv);
    int runTest(const char* language, bool magnified);
    void TestBody() {}
    void createDevice(int widthPx, int heightPx, double dp2px, double mm2px,
                      double powerButtonTopMm, double powerButtonBottomMm, double volUpButtonTopMm,
                      double volUpButtonBottomMm);
};

/*
 * Configures device with test parameters
 * widthPx, heightPx : pixel dimension of devices
 * dp2px : density pixel to pixel
 * mm2px : millimeter to pixel
 * powerButtonTopMm : location of the top of the power button in mm
 * powerButtonBottomMm : location of the bottom of the power button in mm
 * volUpButtonTopMm : location of the top of the up volume button in mm
 * volUpButtonBottomMm : location of the bottom of the up power button in mm
 */

void TeeuiLocaleTest::createDevice(int widthPx, int heightPx, double dp2px, double mm2px,
                                   double powerButtonTopMm, double powerButtonBottomMm,
                                   double volUpButtonTopMm, double volUpButtonBottomMm) {
    DeviceInfo* device_info_ptr = &TeeuiLocaleTest::Instance()->device_info;
    device_info_ptr->width_ = widthPx;
    device_info_ptr->height_ = heightPx;
    device_info_ptr->dp2px_ = dp2px;
    device_info_ptr->mm2px_ = mm2px;
    device_info_ptr->powerButtonTopMm_ = powerButtonTopMm;
    device_info_ptr->powerButtonBottomMm_ = powerButtonBottomMm;
    device_info_ptr->volUpButtonTopMm_ = volUpButtonTopMm;
    device_info_ptr->volUpButtonBottomMm_ = volUpButtonBottomMm;
}

void TeeuiLocaleTest::initFromOptions(int argc, char** argv) {

    uint width = 0, height = 0;
    double dp2px = 0, mm2px = 0;
    double powerBottonTopMm = 0, powerButtonBottomMm = 0;
    double volUpButtonTopMm = 0, volUpButtonBottomMm = 0;

    int option_index = 0;
    static struct option options[] = {{"width", required_argument, 0, 'w'},
                                      {"height", required_argument, 0, 'l'},
                                      {"dp2px", required_argument, 0, 'd'},
                                      {"mm2px", required_argument, 0, 'm'},
                                      {"powerButtonTop", required_argument, 0, 't'},
                                      {"powerButtonBottom", required_argument, 0, 'b'},
                                      {"volUpButtonTop", required_argument, 0, 'u'},
                                      {"volUpButtonBottom", required_argument, 0, 'v'},
                                      {"help", 0, 0, 'h'},
                                      {"?", 0, 0, '?'},
                                      {0, 0, 0, 0}};
    while (true) {
        int c = getopt_long(argc, argv, "w:l:d:m:t:b:u:v:h?", options, &option_index);
        if (c == -1) break;
        double numeric_value = 0;
        switch (c) {
        case 'w':
            width = atoi(optarg);
            break;
        case 'l':
            height = atoi(optarg);
            break;
        case 'd':
            numeric_value = strtod(optarg, NULL);
            dp2px = numeric_value;
            break;
        case 'm':
            numeric_value = strtod(optarg, NULL);
            mm2px = numeric_value;
            break;
        case 't':
            numeric_value = strtod(optarg, NULL);
            powerBottonTopMm = numeric_value;
            break;
        case 'b':
            numeric_value = strtod(optarg, NULL);
            powerButtonBottomMm = numeric_value;
            break;
        case 'u':
            numeric_value = strtod(optarg, NULL);
            volUpButtonTopMm = numeric_value;
            break;
        case 'v':
            numeric_value = strtod(optarg, NULL);
            volUpButtonBottomMm = numeric_value;
            break;
        case '?':
        case 'h':
            std::cout << "Options:" << std::endl;
            std::cout << "--width=<device width in pixels>" << std::endl;
            std::cout << "--height=<device height in pixels>" << std::endl;
            std::cout << "--dp2px=<pixel per density independent pixel (px/dp) ratio of the "
                         "device. Typically <width in pixels>/412 >"
                      << std::endl;
            std::cout << "--mm2px=<pixel per millimeter (px/mm) ratio>" << std::endl;
            std::cout << "--powerButtonTop=<distance from the top of the power button to the top "
                         "of the screen in mm>"
                      << std::endl;
            std::cout << "--powerButtonBottom=<distance from the bottom of the power button to the "
                         "top of the screen in mm>"
                      << std::endl;
            std::cout << "--volUpButtonTop=<distance from the top of the UP volume button to the "
                         "top of the screen in mm>"
                      << std::endl;
            std::cout << "--volUpButtonBottom=<distance from the bottom of the UP power button to "
                         "the top of the screen in mm>"
                      << std::endl;
            exit(0);
        }
    }
    createDevice(width, height, dp2px, mm2px, powerBottonTopMm, powerButtonBottomMm,
                 volUpButtonTopMm, volUpButtonBottomMm);
}

int TeeuiLocaleTest::runTest(const char* language, bool magnified) {
    DeviceInfo* device_info_ptr = &TeeuiLocaleTest::Instance()->device_info;
    selectLanguage(language);
    setDeviceInfo(*device_info_ptr, magnified);
    uint32_t w = device_info_ptr->width_;
    uint32_t h = device_info_ptr->height_;
    uint32_t linestride = w;
    uint32_t buffer_size = h * linestride;
    std::vector<uint32_t> buffer(buffer_size);
    int error = renderUIIntoBuffer(0, 0, w, h, linestride, buffer.data(), buffer_size);
    return error;
}

int runAllTests(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::teeui::test::TeeuiLocaleTest::Instance()->initFromOptions(argc, argv);
    return RUN_ALL_TESTS();
}

TEST_F(TeeuiLocaleTest, Test_en) {
    int error = runTest("en", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_en_M) {
    int error = runTest("en", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AF) {
    int error = runTest("af", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AF_M) {
    int error = runTest("af", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AM) {
    int error = runTest("am", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AM_M) {
    int error = runTest("am", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR) {
    int error = runTest("ar", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_M) {
    int error = runTest("ar", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_EG) {
    int error = runTest("ar-EG", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_EG_M) {
    int error = runTest("ar-EG", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_JO) {
    int error = runTest("ar-JO", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_JO_M) {
    int error = runTest("ar-JO", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_MA) {
    int error = runTest("ar-MA", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_MA_M) {
    int error = runTest("ar-MA", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_SA) {
    int error = runTest("ar-SA", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_SA_M) {
    int error = runTest("ar-SA", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_XB) {
    int error = runTest("ar-XB", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AR_XB_M) {
    int error = runTest("ar-XB", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AS) {
    int error = runTest("as", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AS_M) {
    int error = runTest("as", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AZ) {
    int error = runTest("az", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_AZ_M) {
    int error = runTest("az", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BE) {
    int error = runTest("be", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BE_M) {
    int error = runTest("be", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BG) {
    int error = runTest("bg", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BG_M) {
    int error = runTest("bg", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BN) {
    int error = runTest("bn", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BN_M) {
    int error = runTest("bn", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BS) {
    int error = runTest("bs", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_BS_M) {
    int error = runTest("bs", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_CA) {
    int error = runTest("ca", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_CA_M) {
    int error = runTest("ca", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_CS) {
    int error = runTest("cs", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_CS_M) {
    int error = runTest("cs", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DA) {
    int error = runTest("da", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DA_M) {
    int error = runTest("da", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DE) {
    int error = runTest("de", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DE_M) {
    int error = runTest("de", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DE_AT) {
    int error = runTest("de-AT", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DE_AT_M) {
    int error = runTest("de-AT", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DE_CH) {
    int error = runTest("de-CH", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_DE_CH_M) {
    int error = runTest("de-CH", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EL) {
    int error = runTest("el", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EL_M) {
    int error = runTest("el", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_AU) {
    int error = runTest("en-AU", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_AU_M) {
    int error = runTest("en-AU", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_CA) {
    int error = runTest("en-CA", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_CA_M) {
    int error = runTest("en-CA", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_GB) {
    int error = runTest("en-GB", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_GB_M) {
    int error = runTest("en-GB", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_IE) {
    int error = runTest("en-IE", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_IE_M) {
    int error = runTest("en-IE", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_IN) {
    int error = runTest("en-IN", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_IN_M) {
    int error = runTest("en-IN", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_NZ) {
    int error = runTest("en-NZ", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_NZ_M) {
    int error = runTest("en-NZ", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_SG) {
    int error = runTest("en-SG", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_SG_M) {
    int error = runTest("en-SG", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_XA) {
    int error = runTest("en-XA", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_XA_M) {
    int error = runTest("en-XA", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_XC) {
    int error = runTest("en-XC", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_XC_M) {
    int error = runTest("en-XC", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_ZA) {
    int error = runTest("en-ZA", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EN_ZA_M) {
    int error = runTest("en-ZA", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES) {
    int error = runTest("es", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_M) {
    int error = runTest("es", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_419) {
    int error = runTest("es-419", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_419_M) {
    int error = runTest("es-419", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_AR) {
    int error = runTest("es-AR", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_AR_M) {
    int error = runTest("es-AR", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_BO) {
    int error = runTest("es-BO", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_BO_M) {
    int error = runTest("es-BO", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_CL) {
    int error = runTest("es-CL", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_CL_M) {
    int error = runTest("es-CL", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_CO) {
    int error = runTest("es-CO", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_CO_M) {
    int error = runTest("es-CO", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_CR) {
    int error = runTest("es-CR", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_CR_M) {
    int error = runTest("es-CR", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_DO) {
    int error = runTest("es-DO", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_DO_M) {
    int error = runTest("es-DO", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_EC) {
    int error = runTest("es-EC", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_EC_M) {
    int error = runTest("es-EC", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_GT) {
    int error = runTest("es-GT", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_GT_M) {
    int error = runTest("es-GT", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_HN) {
    int error = runTest("es-HN", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_HN_M) {
    int error = runTest("es-HN", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_MX) {
    int error = runTest("es-MX", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_MX_M) {
    int error = runTest("es-MX", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_NI) {
    int error = runTest("es-NI", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_NI_M) {
    int error = runTest("es-NI", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PA) {
    int error = runTest("es-PA", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PA_M) {
    int error = runTest("es-PA", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PE) {
    int error = runTest("es-PE", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PE_M) {
    int error = runTest("es-PE", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PR) {
    int error = runTest("es-PR", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PR_M) {
    int error = runTest("es-PR", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PY) {
    int error = runTest("es-PY", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_PY_M) {
    int error = runTest("es-PY", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_SV) {
    int error = runTest("es-SV", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_SV_M) {
    int error = runTest("es-SV", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_US) {
    int error = runTest("es-US", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_US_M) {
    int error = runTest("es-US", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_UY) {
    int error = runTest("es-UY", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_UY_M) {
    int error = runTest("es-UY", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_VE) {
    int error = runTest("es-VE", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ES_VE_M) {
    int error = runTest("es-VE", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ET) {
    int error = runTest("et", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ET_M) {
    int error = runTest("et", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EU) {
    int error = runTest("eu", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_EU_M) {
    int error = runTest("eu", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FA) {
    int error = runTest("fa", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FA_M) {
    int error = runTest("fa", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FI) {
    int error = runTest("fi", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FI_M) {
    int error = runTest("fi", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FIL) {
    int error = runTest("fil", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FIL_M) {
    int error = runTest("fil", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FR) {
    int error = runTest("fr", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FR_M) {
    int error = runTest("fr", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FR_CA) {
    int error = runTest("fr-CA", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FR_CA_M) {
    int error = runTest("fr-CA", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FR_CH) {
    int error = runTest("fr-CH", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_FR_CH_M) {
    int error = runTest("fr-CH", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_GL) {
    int error = runTest("gl", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_GL_M) {
    int error = runTest("gl", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_GSW) {
    int error = runTest("gsw", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_GSW_M) {
    int error = runTest("gsw", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_GU) {
    int error = runTest("gu", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_GU_M) {
    int error = runTest("gu", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HE) {
    int error = runTest("he", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HE_M) {
    int error = runTest("he", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HI) {
    int error = runTest("hi", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HI_M) {
    int error = runTest("hi", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HR) {
    int error = runTest("hr", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HR_M) {
    int error = runTest("hr", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HU) {
    int error = runTest("hu", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HU_M) {
    int error = runTest("hu", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HY) {
    int error = runTest("hy", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_HY_M) {
    int error = runTest("hy", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ID) {
    int error = runTest("id", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ID_M) {
    int error = runTest("id", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IN) {
    int error = runTest("in", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IN_M) {
    int error = runTest("in", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IS) {
    int error = runTest("is", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IS_M) {
    int error = runTest("is", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IT) {
    int error = runTest("it", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IT_M) {
    int error = runTest("it", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IW) {
    int error = runTest("iw", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_IW_M) {
    int error = runTest("iw", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_JA) {
    int error = runTest("ja", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_JA_M) {
    int error = runTest("ja", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KA) {
    int error = runTest("ka", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KA_M) {
    int error = runTest("ka", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KK) {
    int error = runTest("kk", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KK_M) {
    int error = runTest("kk", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KM) {
    int error = runTest("km", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KM_M) {
    int error = runTest("km", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KN) {
    int error = runTest("kn", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KN_M) {
    int error = runTest("kn", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KO) {
    int error = runTest("ko", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KO_M) {
    int error = runTest("ko", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KY) {
    int error = runTest("ky", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_KY_M) {
    int error = runTest("ky", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LN) {
    int error = runTest("ln", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LN_M) {
    int error = runTest("ln", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LO) {
    int error = runTest("lo", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LO_M) {
    int error = runTest("lo", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LT) {
    int error = runTest("lt", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LT_M) {
    int error = runTest("lt", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LV) {
    int error = runTest("lv", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_LV_M) {
    int error = runTest("lv", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MK) {
    int error = runTest("mk", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MK_M) {
    int error = runTest("mk", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ML) {
    int error = runTest("ml", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ML_M) {
    int error = runTest("ml", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MN) {
    int error = runTest("mn", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MN_M) {
    int error = runTest("mn", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MO) {
    int error = runTest("mo", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MO_M) {
    int error = runTest("mo", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MR) {
    int error = runTest("mr", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MR_M) {
    int error = runTest("mr", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MS) {
    int error = runTest("ms", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MS_M) {
    int error = runTest("ms", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MY) {
    int error = runTest("my", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_MY_M) {
    int error = runTest("my", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NB) {
    int error = runTest("nb", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NB_M) {
    int error = runTest("nb", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NE) {
    int error = runTest("ne", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NE_M) {
    int error = runTest("ne", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NL) {
    int error = runTest("nl", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NL_M) {
    int error = runTest("nl", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NO) {
    int error = runTest("no", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_NO_M) {
    int error = runTest("no", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_OR) {
    int error = runTest("or", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_OR_M) {
    int error = runTest("or", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PA) {
    int error = runTest("pa", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PA_M) {
    int error = runTest("pa", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PL) {
    int error = runTest("pl", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PL_M) {
    int error = runTest("pl", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PT) {
    int error = runTest("pt", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PT_M) {
    int error = runTest("pt", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PT_BR) {
    int error = runTest("pt-BR", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PT_BR_M) {
    int error = runTest("pt-BR", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PT_PT) {
    int error = runTest("pt-PT", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_PT_PT_M) {
    int error = runTest("pt-PT", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_RO) {
    int error = runTest("ro", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_RO_M) {
    int error = runTest("ro", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_RU) {
    int error = runTest("ru", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_RU_M) {
    int error = runTest("ru", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SI) {
    int error = runTest("si", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SI_M) {
    int error = runTest("si", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SK) {
    int error = runTest("sk", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SK_M) {
    int error = runTest("sk", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SL) {
    int error = runTest("sl", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SL_M) {
    int error = runTest("sl", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SQ) {
    int error = runTest("sq", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SQ_M) {
    int error = runTest("sq", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SR) {
    int error = runTest("sr", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SR_M) {
    int error = runTest("sr", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SR_LATN) {
    int error = runTest("sr-Latn", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SR_LATN_M) {
    int error = runTest("sr-Latn", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SV) {
    int error = runTest("sv", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SV_M) {
    int error = runTest("sv", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SW) {
    int error = runTest("sw", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_SW_M) {
    int error = runTest("sw", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TA) {
    int error = runTest("ta", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TA_M) {
    int error = runTest("ta", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TE) {
    int error = runTest("te", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TE_M) {
    int error = runTest("te", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TH) {
    int error = runTest("th", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TH_M) {
    int error = runTest("th", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TL) {
    int error = runTest("tl", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TL_M) {
    int error = runTest("tl", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TR) {
    int error = runTest("tr", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_TR_M) {
    int error = runTest("tr", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_UK) {
    int error = runTest("uk", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_UK_M) {
    int error = runTest("uk", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_UR) {
    int error = runTest("ur", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_UR_M) {
    int error = runTest("ur", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_UZ) {
    int error = runTest("uz", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_UZ_M) {
    int error = runTest("uz", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_VI) {
    int error = runTest("vi", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_VI_M) {
    int error = runTest("vi", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH) {
    int error = runTest("zh", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH_M) {
    int error = runTest("zh", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH_CN) {
    int error = runTest("zh-CN", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH_CN_M) {
    int error = runTest("zh-CN", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH_HK) {
    int error = runTest("zh-HK", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH_HK_M) {
    int error = runTest("zh-HK", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH_TW) {
    int error = runTest("zh-TW", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZH_TW_M) {
    int error = runTest("zh-TW", true /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZU) {
    int error = runTest("zu", false /* magnified */);
    ASSERT_EQ(error, 0);
}

TEST_F(TeeuiLocaleTest, Test_ZU_M) {
    int error = runTest("zu", true /* magnified */);
    ASSERT_EQ(error, 0);
}

}  // namespace test

}  // namespace teeui
