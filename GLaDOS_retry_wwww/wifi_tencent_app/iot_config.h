/*
 * Copyright (c) 2022 HiSilicon (Shanghai) Technologies CO., LIMITED.
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

#ifndef IOT_CONFIG_H
#define IOT_CONFIG_H

// <CONFIG THE LOG
/* if you need the iot log for the development , please enable it, else please comment it */
#define CONFIG_LINKLOG_ENABLE   1

// < CONFIG THE WIFI
/* Please modify the ssid and pwd for the own */
#define CONFIG_AP_SSID  "你的wifi账号" // WIFI SSID
#define CONFIG_AP_PWD   "你的wifi密码" // WIFI PWD
/* Tencent iot Cloud user ID , password */
#define CONFIG_USER_ID    "这些不给你们看了"
#define CONFIG_USER_PWD   "这也不能给你们看"
#define CN_CLIENTID     "这个也一样" // Tencent cloud ClientID format: Product ID + device name
static void AppDemoIot(void);
#endif 
