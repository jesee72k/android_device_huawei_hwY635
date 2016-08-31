/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    std::ifstream fin;
    std::string buf;
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    fin.open("/proc/app_info");
    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
    fin.close();

    /* Y635-L01 */
    if (buf.find("Y635-L01") != std::string::npos) {
        property_set("ro.product.model", "Y635-L01");
        property_set("ro.product.name", "Y635-L01");
        property_set("ro.product.device", "Y635-L01");
        property_set("ro.build.product", "Y635-L01");
        property_set("ro.telephony.default_network", "9");
    }
    /* Y635-L02 */
    else if (buf.find("Y635-L02") != std::string::npos) {
        property_set("ro.product.model", "Y635-L02");
        property_set("ro.product.name", "Y635-L02");
        property_set("ro.product.device", "Y635-L02");
        property_set("ro.build.product", "Y635-L02");
        property_set("ro.telephony.default_network", "9");
    }
    /* Y635-L03 */
    else if (buf.find("Y635-L03") != std::string::npos) {
        property_set("ro.product.model", "Y635-L03");
        property_set("ro.product.name", "Y635-L03");
        property_set("ro.product.device", "Y635-L03");
        property_set("ro.build.product", "Y635-L03");
        property_set("ro.telephony.default_network", "9");
    }
    /* Y635-L11 */
    else if (buf.find("Y635-L03") != std::string::npos) {
        property_set("ro.product.model", "Y635-L11");
        property_set("ro.product.name", "Y635-L11");
        property_set("ro.product.device", "Y635-L11");
        property_set("ro.build.product", "Y635-L11");
        property_set("ro.telephony.default_network", "9");
    }
    /* Y635-L21 */
    else if (buf.find("Y635-L21") != std::string::npos) {
        property_set("ro.product.model", "Y635-L21");
        property_set("ro.product.name", "Y635-L21");
        property_set("ro.product.device", "Y635-L21");
        property_set("ro.build.product", "Y635-L21");
        property_set("ro.telephony.default_network", "9");
    }
}
