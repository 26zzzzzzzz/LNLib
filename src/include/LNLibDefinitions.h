/**
 * Author:
 * 2023/06/08 - Yuqing Liang (BIMCoder Liang)
 * bim.frankliang@foxmail.com
 * ΢�Ź��ںţ�BIMCoder����ʦ
 *
 * Use of this source code is governed by a GPL-3.0 license license that can be found in
 * the LICENSE file.
 */

#pragma once

#define DLL_EXPORT __declspec(dllexport)
#define DLL_IMPORT __declspec(dllimport)

#ifdef LNLIB_HOME
#define LNLIB_EXPORT DLL_EXPORT
#else
#define LNLIB_EXPORT DLL_IMPORT
#endif


