/*
 * Created by Martin Winkelhofer 03/2016
 * W-Dimension / wdim / wdim0 / maarty.w@gmail.com
 *  _      ____   ________       __    _
 * | | /| / / /  / ___/ _ \  ___/ /___(_)  _____ ____
 * | |/ |/ / /__/ /__/ // / / _  / __/ / |/ / -_) __/
 * |__/|__/____/\___/____/  \_,_/_/ /_/|___/\__/_/
 *
 * This file is part of WLCD - W-Dimension's LCD driver (for ESP8266).
 *
 * WLCD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * WLCD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with WLCD. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __WLCD_FONT_FXS_8X15_16_127_H__
#define __WLCD_FONT_FXS_8X15_16_127_H__

/* ============================================================================
 * FONT: "Fxs", 8x15, regular, chars 16..127
 * ============================================================================
 *
 * fonter.c used to create content of CharOffs[], Rects[] arrays. Thanks!
 *
 * uint16_t CharOffs[] - offsets to array Rects[]
 *
 * Example for char with ASCII value 65 - "A":
 * CharOffs[65] = 0x0170
 * CharOffs[66] = 0x0177
 * => for drawing of char "A" we'll use 7 rectangles, first rectangle is here -> Rects[0x0170]
 *
 * uint16_t Rects[] - each 16-bit value describes one rectangle:
 * 0 b 0000 0000 0000 0000
 *       H    W    Y    X
 * note: add 1 to W, H to get real width, height.
 */

#define WLCD_FONT_FXS_8X15_16_127_CHAR_WIDTH      8
#define WLCD_FONT_FXS_8X15_16_127_CHAR_HEIGHT     15
#define WLCD_FONT_FXS_8X15_16_127_FIRST_CHAR_CODE   16
#define WLCD_FONT_FXS_8X15_16_127_LAST_CHAR_CODE    127

const uint16_t wlcd_font_fxs_8x15_16_127_Rects[] = {
  0x6240, 0x2460, 0xa020, 0x8130, 0x4350, 0x0670, 0x6244, 0x2162, 0xa026, 0x8035, 0x4053, 0x0170, 0x8133, 0x1342, 0x0591, 0x0551, 
  0x1392, 0x6131, 0x6135, 0x11b1, 0x11b5, 0x9133, 0x9136, 0x2140, 0x0431, 0x0171, 0x0421, 0x04d1, 0x3061, 0x3065, 0x2042, 0x2094, 
  0x2021, 0x0135, 0x0252, 0x1070, 0x1175, 0x1092, 0x10b5, 0x01c0, 0x0030, 0x1054, 0x01a2, 0x01c5, 0x3690, 0x9133, 0x1342, 0x0591, 
  0x05c1, 0x0551, 0x1392, 0x9133, 0x1342, 0x0551, 0x9133, 0x05a1, 0x13a2, 0x0680, 0x4064, 0x2174, 0x0063, 0x00a3, 0x0680, 0x4062, 
  0x2071, 0x0162, 0x01a2, 0x3170, 0x06a0, 0x0780, 0x4062, 0x4065, 0x2071, 0x2175, 0x3481, 0x1262, 0x16a0, 0x0053, 0x3451, 0x5252, 
  0x1650, 0x6053, 0x5133, 0x2342, 0x11a3, 0x2131, 0x2135, 0x8132, 0x8135, 0x0651, 0x0691, 0x2113, 0x21b3, 0x3032, 0x3085, 0x1035, 
  0x1041, 0x1063, 0x1074, 0x1195, 0x01a1, 0x0145, 0x10a2, 0x3021, 0x3023, 0x3094, 0x3096, 0x1030, 0x1133, 0x1046, 0x1055, 0x1064, 
  0x1073, 0x1082, 0x1091, 0x10a3, 0x11a6, 0x0121, 0x0151, 0x0194, 0x01c4, 0x8032, 0x2185, 0x3034, 0x3071, 0x1041, 0x1144, 0x0384, 
  0x02b2, 0x01b6, 0x0132, 0x0162, 0x2133, 0x4162, 0x1143, 0x11b3, 0x0134, 0x01d4, 0x4164, 0x1143, 0x11b3, 0x0132, 0x01d2, 0x2263, 
  0x0671, 0x0152, 0x0155, 0x0192, 0x0195, 0x4153, 0x0571, 0x12a3, 0x21a4, 0x01d3, 0x0571, 0x12a3, 0x1135, 0x1154, 0x1173, 0x1192, 
  0x11b1, 0x6142, 0x6146, 0x0333, 0x03b3, 0x1055, 0x1282, 0x8134, 0x0251, 0x0043, 0x2145, 0x05b1, 0x0332, 0x1141, 0x0174, 0x0183, 
  0x0192, 0x01a1, 0x8035, 0x1141, 0x1191, 0x0232, 0x2145, 0x2185, 0x02b2, 0x0173, 0x6155, 0x4132, 0x0691, 0x0181, 0x4131, 0x0531, 
  0x3075, 0x03b1, 0x0371, 0x1185, 0x00a4, 0x4161, 0x3175, 0x1133, 0x03b2, 0x1152, 0x0461, 0x0233, 0x0531, 0x2192, 0x1154, 0x1173, 
  0x1135, 0x8032, 0x8035, 0x2041, 0x2145, 0x2081, 0x2185, 0x0232, 0x1162, 0x1074, 0x02b2, 0x4145, 0x3141, 0x0332, 0x3084, 0x0182, 
  0x10a3, 0x6035, 0x00b2, 0x1253, 0x12a3, 0x1253, 0x12a3, 0x21a4, 0x01d3, 0x2062, 0x0135, 0x0144, 0x0153, 0x1083, 0x1094, 0x10a5, 
  0x1053, 0x0071, 0x01b5, 0x0561, 0x0581, 0x2065, 0x0131, 0x0142, 0x0153, 0x1084, 0x1093, 0x10a2, 0x1054, 0x0175, 0x00b1, 0x0332, 
  0x1141, 0x1145, 0x1173, 0x11a3, 0x0164, 0x6140, 0x5146, 0x06b1, 0x0531, 0x3064, 0x1073, 0x0164, 0x0194, 0x6151, 0x6155, 0x1133, 
  0x0342, 0x0381, 0x8131, 0x8035, 0x2145, 0x2185, 0x0331, 0x0371, 0x03b1, 0x6141, 0x0332, 0x1145, 0x1195, 0x03b2, 0x8131, 0x4155, 
  0x0331, 0x0144, 0x01a4, 0x03b1, 0x8131, 0x0531, 0x05b1, 0x0471, 0x8131, 0x0531, 0x0471, 0x6141, 0x3185, 0x0332, 0x1145, 0x02b2, 
  0x0084, 0x8131, 0x8135, 0x0371, 0x8133, 0x0332, 0x03b2, 0x7135, 0x1191, 0x03b2, 0x8131, 0x4054, 0x1135, 0x3085, 0x3035, 0x11a5, 
  0x0271, 0x8131, 0x05b1, 0x8131, 0x8136, 0x2064, 0x0251, 0x0055, 0x8131, 0x8136, 0x1251, 0x1064, 0x1075, 0x6141, 0x6145, 0x0332, 
  0x03b2, 0x8131, 0x2145, 0x0431, 0x0471, 0x6141, 0x6145, 0x0332, 0x03b2, 0xa035, 0x10b4, 0x01d5, 0x8131, 0x8035, 0x2145, 0x2195, 
  0x0331, 0x0371, 0x1074, 0x0332, 0x1141, 0x3085, 0x02b2, 0x0145, 0x0162, 0x0173, 0x1195, 0x01a1, 0x1074, 0x8133, 0x0531, 0x7131, 
  0x7135, 0x03b2, 0x6131, 0x6135, 0x03a2, 0x11a3, 0x5131, 0x5136, 0x2192, 0x2195, 0x2064, 0x2191, 0x2195, 0x1131, 0x1135, 0x1163, 
  0x0152, 0x0184, 0x2035, 0x0082, 0x4173, 0x3131, 0x3135, 0x0372, 0x0531, 0x2191, 0x2135, 0x05b1, 0x0164, 0x0173, 0x0182, 0xb132, 
  0x0332, 0x03e2, 0x1131, 0x1152, 0x1173, 0x1194, 0x11b5, 0xb134, 0x0132, 0x01e2, 0x1113, 0x0322, 0x0131, 0x0135, 0x07e0, 0x1113, 
  0x0134, 0x0012, 0x5165, 0x0352, 0x3082, 0x0282, 0x1091, 0x02b2, 0x8131, 0x4165, 0x0451, 0x04b1, 0x4161, 0x0352, 0x03b2, 0x0165, 
  0x01a5, 0x8135, 0x4161, 0x0252, 0x02b2, 0x4161, 0x2165, 0x0352, 0x03b2, 0x0381, 0x7142, 0x0333, 0x0571, 0x8155, 0x4161, 0x04e1, 
  0x0252, 0x02b2, 0x8131, 0x5165, 0x0451, 0x6153, 0x1123, 0x05b1, 0x0151, 0x8154, 0x1124, 0x03e1, 0x0152, 0x8131, 0x1155, 0x11a5, 
  0x2074, 0x2055, 0x0281, 0x0194, 0x8133, 0x05b1, 0x0131, 0x6151, 0x5166, 0x5054, 0x0551, 0x6151, 0x5165, 0x0451, 0x4161, 0x4165, 
  0x0352, 0x03b2, 0x9151, 0x4165, 0x0451, 0x04b1, 0x9155, 0x4161, 0x0252, 0x02b2, 0x6151, 0x1155, 0x0064, 0x0271, 0x0452, 0x04b1, 
  0x1161, 0x0382, 0x1195, 0x7132, 0x0551, 0x03b3, 0x6155, 0x5151, 0x02b2, 0x4151, 0x4155, 0x03a2, 0x11a3, 0x4151, 0x4156, 0x3064, 
  0x11a2, 0x11a5, 0x2173, 0x1151, 0x1155, 0x11a1, 0x11a5, 0x0372, 0x0392, 0x5151, 0x5155, 0x03b2, 0x03e0, 0x11b4, 0x01d3, 0x0551, 
  0x05b1, 0x1155, 0x0174, 0x0183, 0x0192, 0x01a1, 0x2143, 0x21a3, 0x2072, 0x0134, 0x01d4, 0x3043, 0x0081, 0x0192, 0xb133, 0x2143, 
  0x21a3, 0x2075, 0x0132, 0x01d2, 0x3044, 0x0185, 0x0094, 0x0231, 0x0254, 0x1037, 0x0140, 0x0143, 0x1040, 0x0046, 0x8531
};

const uint16_t wlcd_font_fxs_8x15_16_127_CharOffs[129] = {
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
  0x0000, 0x0006, 0x000c, 0x0011, 0x0015, 0x001a, 0x002c, 0x002d, 0x0033, 0x0036, 0x0039, 0x003e, 0x0043, 0x0045, 0x004a, 0x004e, 
  0x0052, 0x0052, 0x0055, 0x0057, 0x005b, 0x0067, 0x0079, 0x0084, 0x0085, 0x008a, 0x008f, 0x0095, 0x0097, 0x009a, 0x009b, 0x009c, 
  0x00a1, 0x00a7, 0x00aa, 0x00b2, 0x00ba, 0x00be, 0x00c5, 0x00cc, 0x00d1, 0x00db, 0x00e3, 0x00e5, 0x00e9, 0x00f3, 0x00f5, 0x00ff, 
  0x0105, 0x010d, 0x0112, 0x0119, 0x011e, 0x0124, 0x0128, 0x012b, 0x0131, 0x0134, 0x0137, 0x013a, 0x0141, 0x0143, 0x0148, 0x014d, 
  0x0151, 0x0155, 0x015c, 0x0163, 0x016d, 0x016f, 0x0172, 0x0176, 0x017b, 0x0184, 0x0188, 0x018f, 0x0192, 0x0197, 0x019a, 0x019e, 
  0x019f, 0x01a2, 0x01a8, 0x01ac, 0x01b1, 0x01b5, 0x01ba, 0x01bd, 0x01c2, 0x01c5, 0x01c9, 0x01cd, 0x01d4, 0x01d7, 0x01db, 0x01de, 
  0x01e2, 0x01e6, 0x01ea, 0x01ee, 0x01f3, 0x01f6, 0x01f9, 0x01fd, 0x0202, 0x0209, 0x020f, 0x0216, 0x021e, 0x021f, 0x0227, 0x022e, 
  0x022f //last item is not offset to real char, but is here just to be able to count how many rectangles we use for last char
};

#endif 
